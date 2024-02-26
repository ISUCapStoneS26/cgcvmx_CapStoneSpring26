.intel_syntax noprefix

/*
   IMPORTANT NOTE
   The default version of binutils installed in FreeBSD 10 is OLD
   binutils needs to be installed from ports to get a version of
   gas that fixes bugs in the intel_syntax parser/generator
*/

/*
   NOTE: this version has been modified to be compatible with
   clang
*/

.code64

.global cgc_rdrand
.global cgc_rdseed
.global cgc_cpuid
.global cr4_set
.global cr4_reset
.global vm_call
.global vm_clear
.global vm_ptrld
.global vm_ptrst
.global vmx_on
.global vmx_off
.global vm_write
.global vm_read
.global vm_launch
.global vm_resume
.global vmexit_handler
.global RegGetTSC
.global RegGetCs
.global RegGetDs
.global RegGetEs
.global RegSetEs
.global RegGetFs
.global RegGetGs
.global RegGetSs
.global cgc_clts
.global cgc_lmsw
.global RegGetCr0
.global RegSetCr0
.global RegGetCr2
.global RegSetCr2
.global RegGetCr3
.global RegSetCr3
.global RegGetCr4
.global RegSetCr4
.global RegGetRflags
.global RegGetRsp
.global GetIdtBase
.global GetIdtLimit
.global GetGdtBase
.global GetGdtLimit
.global GetLdtr
.global GetSegAttr
.global GetTrAttr
.global GetTrLimit
.global GetLdtAttr
.global GetTrSelector
.global MsrRead
.global MsrWrite
.global init_tramp

.global do_sldt
.global do_sgdt
.global do_sidt
.global do_str

.global do_lgdt
.global do_lidt
.global guest_rip
.global fail_rip
.text

.extern vmexitCallback
.extern real_cgcvmx_on
.extern printf

/*
uint32_t vm_ptrld(uint64_t addr)
*/
vm_ptrld:
   push rdi
   vmptrld [rsp]
   pop rdi
   pushfq
   pop rax
   and eax, 0x41   /* CF | ZF */
   ret

/*
uint32_t vm_ptrst(uint64_t addr)
*/
vm_ptrst:
   push rdi
   vmptrst [rsp]
   pop rdi
   pushfq
   pop rax
   and eax, 0x41   /* CF | ZF */
   ret

/*
uint32_t vm_clear(uint64_t addr)
*/
vm_clear:
   push rdi
   vmclear [rsp]
   pop rdi
   pushfq
   pop rax
   and eax, 0x41   /* CF | ZF */
   ret

/*
uint64_t vm_read(uint64_t field)
*/
vm_read:
   vmread rax, rdi
   ret

/*
uint32_t vm_write(uint64_t field, uint64_t value)
*/
vm_write:
   vmwrite rdi, rsi
   pushfq
   pop rax
   and eax, 0x41   /* CF | ZF */
   ret

/*
uint32_t vmx_off(void)
*/
vmx_off:
   vmxoff
   pushfq
   pop rax
   and rax, 0x41   /* CF | ZF */
   ret

/*
uint32_t vmx_on(uint64_t addr)
*/
vmx_on:
   push rdi
   vmxon [rsp]
   pop rdi
   pushfq
   pop rax
   and eax, 0x41   /* CF | ZF */
   ret

/*
uint32_t vm_call(uint64_t func)
*/
vm_call:
   vmcall
   pushfq
   pop rax
   and eax, 0x41   /* CF | ZF */
   ret

/*
uint64_t get_cr4(void)
*/
get_cr4:
   mov rax, cr4
   ret

/*
void cr4_set(uint64_t bits)
*/
cr4_set:
   mov rcx, cr4
   or  rcx, rdi
   mov cr4, rcx
   ret

/*
void cr4_reset(uint64_t bits)
*/
cr4_reset:
   not rdi
   mov rcx, cr4
   and rcx, rdi
   mov cr4, rcx
   ret

vm_launch:
   vmlaunch
   pushfq
   pop rax
   and eax, 0x41   /* CF | ZF */
   ret

vm_resume:
   vmresume
   pushfq
   pop rax
   and eax, 0x41   /* CF | ZF */
   ret

/*
   vmexit_handler is specified as HOST_RIP in the VMCS. This is where all VMexits 
   resume execution in the host. Here we do a pusha equivalent to complete the construction
   of the VmxStruct (see vmxon64.h) which was begun when the host stack was allocated
   and HOST_RSP set (see setup of host stack in real_cgcvmx_on() in cgcvmx64.c)
   ultimately invokes vmexitCallback(VmxStruct *vmx) to handle the VMexit
*/
vmexit_handler:
/*
   on VM exit, gp regs still reflect guest values w/ exception of esp
   HOST_RSP points at beginning of CPU struct from VmxInitialize
*/
   push rax
   push rcx
   push rdx
   push rbx
   sub  rsp, 8
   push rbp
   push rsi
   push rdi
   push r8
   push r9 
   push r10
   push r11
   push r12
   push r13
   push r14
   push r15

   mov rdi, rsp   /* VmxStruct* */
   call  vmexitCallback

   pop r15
   pop r14
   pop r13
   pop r12
   pop r11
   pop r10
   pop r9
   pop r8
   pop rdi
   pop rsi
   pop rbp
   add rsp, 8
   pop rbx
   pop rdx
   pop rcx
   pop rax
   vmresume
   ret

/*
cgc_cpuid(CpuIdRegs *regs)
*/
cgc_cpuid:
    push rbx
    
    mov eax, [rdi]       /* regs->eax */
    mov ecx, [rdi + 8]   /* regs->ecx */

    cpuid

    mov [rdi], eax
    mov [rdi + 4], ebx    
    mov [rdi + 8], ecx
    mov [rdi + 12], edx
    
    pop rbx
    ret
/*
uint8_t cgc_rdrand(uint64_t *rnd);
*/
cgc_rdrand:
   rdrand rax
   mov [rdi], rax
   setc al
   movzx eax, al
   ret

/*
uint8_t cgc_rdrand(uint64_t *rnd);
*/
cgc_rdseed:
   rdseed rax
/*   .byte 0x48, 0x0f, 0xc7, 0xf8    rdseed rax */
   mov [rdi], rax
   setc al
   movzx eax, al
   ret

RegGetTSC:
   rdtsc
   shl rdx, 32
   or rax, rdx
   ret

RegGetCs:
   mov ax, cs
   movzx rax, ax
   ret

RegGetDs:
   mov ax, ds
   movzx rax, ax
   ret

RegGetEs:
   mov ax, es
   movzx rax, ax
   ret

RegSetEs:
   mov es, di
   ret

RegGetSs:
   mov ax, ss
   movzx rax, ax
   ret

RegGetFs:
   mov ax, fs
   movzx rax, ax
   ret

RegGetGs:
   mov ax, gs
   movzx rax, ax
   ret

RegGetCr0:
   mov  rax, cr0
   ret

/*
void RegSetCr0(uint64_t _cr0)
*/
RegSetCr0:
   mov  cr0, rdi
   ret

/*
void cgc_clts();
*/
cgc_clts:
   clts
   ret
   
/*
void cgc_lmsw(uint64_t lmsw);
*/
cgc_lmsw:
   lmsw di
   ret

RegGetCr2:
   mov  rax, cr2
   ret

RegSetCr2:
   mov  cr2, rdi
   ret

RegGetCr3:
   mov  rax, cr3
   ret

/*
void RegSetCr3(uint64_t _cr3)
*/
RegSetCr3:
   mov  cr3, rdi
   ret

RegGetCr4:
   mov  rax, cr4
   ret

/*
void RegSetCr4(uint64_t _cr4)
*/
RegSetCr4:
   mov  cr4, rdi
   ret

RegGetRflags:
   pushfq
   pop  rax
   ret

RegGetRsp:
   lea  rax, [rsp + 8]
   ret

/*
void do_sidt(uint8_t *idt)
*/
do_sidt:
   sidt [rdi]
   ret

/*
void do_lidt(uint8_t *idt)
*/
do_lidt:
   lidt [rdi]
   ret

/*
void do_sgdt(uint8_t *gdt)
*/
do_sgdt:
   sgdt [rdi]
   ret

/*
void do_lgdt(uint8_t *gdt)
*/
do_lgdt:
   lgdt [rdi]
   ret

GetIdtBase:
   sub  rsp, 16
   sidt [rsp]
   mov  rax, [rsp + 2]
   add  rsp, 16
   ret

GetIdtLimit:
   sub  rsp, 16   
   sidt [rsp]
   /* movzx  rax, word [rsp] */
   .byte 0x48, 0x0f, 0xb7, 0x04, 0x24
   add  rsp, 16
   ret

GetGdtBase:
   sub  rsp, 16
   sgdt [rsp]
   mov  rax, [rsp + 2]
   add  rsp, 16
   ret

GetGdtLimit:
   sub  rsp, 16
   sgdt [rsp]
   /* movzx  rax, word [rsp] */
   .byte 0x48, 0x0f, 0xb7, 0x04, 0x24
   add  rsp, 16
   ret

/*
uint16_t do_sldt()
*/
do_sldt:
GetLdtr:
   sldt  ax
   movzx rax, ax
   ret

/*
void do_lldt(uint16_t ldt)
*/
do_lldt:
   lldt  di
   ret

/*
uint16_t do_str()
*/
do_str:
GetTrSelector:
   str   ax
   movzx rax, ax
   ret

/*
void do_ltr(uint16_t tr)
*/
do_ltr:
   ltr di
   ret

GetTrLimit:
   str   ax
   movzx rax, ax
   /* lsl   rax, eax */
   .byte 0x48, 0x0f, 0x03, 0xc0   
   ret

GetTrAttr:
   str   ax
   movzx rax, ax
   lar   rax, eax
   ret

GetLdtAttr:
   sldt  ax
   movzx rax, ax
   lar   rax, eax
   ret

GetSegAttr:
   lar   rax, eax
   ret

/*
uint64_t MsrRead(uint32_t reg);
*/
MsrRead:
   mov  rcx, rdi
   /* per ref manual, rdmsr clears high order bits of rdx and rax here */
   rdmsr    /* MSR[rcx] --> edx:eax */
   /* combine into single 64 bit result */
   shl  rdx, 32
   or   rax, rdx
   ret

/*
void MsrWrite(uint32_t reg, uint64_t val);
*/
MsrWrite:
   mov  ecx, edi
   /* split rsi across edx:eax */
   mov  rdx, rsi
   shr  rdx, 32
   mov  eax, esi
   wrmsr    /* MSR[ecx] <- edx:eax */
   ret

/*
   init_tramp computes the correct values for GUEST_RIP and GUEST_RSP
   to be specified in the VMCS prior to issuing vmlaunch. The virtualized
   guest will end up reentering at guest_rip below
*/
init_tramp:
   push rax
   push rcx
   push rdx
   push rbx
/*   push rsp */
   push rbp
   push rsi
   push rdi
   push r8
   push r9 
   push r10
   push r11
   push r12
   push r13
   push r14
   push r15
   
   mov  edx, edi           /* cpu number */
   mov  rsi, rsp           /* guest rsp, positioned to ret from here */   
   lea  rdi, [guest_rip]
   
   call real_cgcvmx_on

	/*** only get here if init failed ***/
fail_rip:	
   pop r15
   pop r14
   pop r13
   pop r12
   pop r11
   pop r10
   pop r9
   pop r8
   pop rdi
   pop rsi
   pop rbp
/*   pop rsp  */
   pop rbx
   pop rdx
   pop rcx
   pop rax
   mov ax, 0xffff
   movsx rax, ax
   ret
   
guest_rip:
/*if we get here, guest vmlaunch was successful*/

   pop r15
   pop r14
   pop r13
   pop r12
   pop r11
   pop r10
   pop r9
   pop r8
   pop rdi
   pop rsi
   pop rbp
/*   pop rsp  */
   pop rbx
   pop rdx
   pop rcx
   pop rax
   xor rax, rax
   ret

.att_syntax

