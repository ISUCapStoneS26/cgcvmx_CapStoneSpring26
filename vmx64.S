
/*
 * This version is modified to use AT&T syntax
 */

.code64

.extern vmexitCallback
.extern real_cgcvmx_on

.macro ENTRY x
	.text
	.globl \x
	.type \x,@function
	.align 16, 0x90
\x:
.endm

.macro END x
	.size \x, .-\x
.endm

/*
uint32_t vm_ptrld(uint64_t addr)
*/
ENTRY vm_ptrld
	push %rdi
	vmptrld (%rsp)
	pop %rdi
	pushfq
	pop %rax
	and $0x41, %eax /* CF | ZF */
	ret
END vm_ptrld

/*
uint32_t vm_ptrst(uint64_t addr)
*/
ENTRY vm_ptrst
	push %rdi
	vmptrst (%rsp)
	pop %rdi
	pushfq
	pop %rax
	and $0x41, %eax /* CF | ZF */
	ret
END vm_ptrst

/*
uint32_t vm_clear(uint64_t addr)
*/
ENTRY vm_clear
	push %rdi
	vmclear (%rsp)
	pop %rdi
	pushfq
	pop %rax
	and $0x41, %eax /* CF | ZF */
	ret
END vm_clear

/*
uint64_t vm_read(uint64_t field)
*/
ENTRY vm_read
	vmread %rdi, %rax
	ret
END vm_read

/*
uint32_t vm_write(uint64_t field, uint64_t value)
*/
ENTRY vm_write
	vmwrite %rsi, %rdi
	pushfq
	pop %rax
	and $0x41, %eax /* CF | ZF */
	ret
END vm_write

/*
uint32_t vmx_off(void)
*/
ENTRY vmx_off
	vmxoff
	pushfq
	pop %rax
	and $0x41, %rax		/* CF | ZF */
	ret
END vmx_off

/*
uint32_t vmx_on(uint64_t addr)
*/
ENTRY vmx_on
	push %rdi
	vmxon (%rsp)
	pop %rdi
	pushfq
	pop %rax
	and $0x41, %eax		/* CF | ZF */
	ret
END vmx_on

/*
uint32_t vm_call(uint64_t func)
*/
ENTRY vm_call
	vmcall
	pushfq
	pop %rax
	and $0x41, %eax		/* CF | ZF */
	ret
END vm_call

/*
uint64_t get_cr4(void)
*/
ENTRY get_cr4
	mov %cr4, %rax
	ret
END get_cr4

/*
void cr4_set(uint64_t bits)
*/
ENTRY cr4_set
	mov %cr4, %rcx
	or %rdi, %rcx
	mov %rcx, %cr4
	ret
END cr4_set

/*
void cr4_reset(uint64_t bits)
*/
ENTRY cr4_reset
	not %rdi
	mov %cr4, %rcx
	and %rdi, %rcx
	mov %rcx, %cr4
	ret
END cr4_reset

ENTRY vm_launch
	vmlaunch
	pushfq
	pop %rax
	and $0x41, %eax		/* CF | ZF */
	ret
END vm_launch

ENTRY vm_resume
	vmresume
	pushfq
	pop %rax
	and $0x41, %eax		/* CF | ZF */
	ret
END vm_resume

/*
   vmexit_handler is specified as HOST_RIP in the VMCS. This is where all VMexits 
   resume execution in the host. Here we do a pusha equivalent to complete the construction
   of the VmxStruct (see vmxon64.h) which was begun when the host stack was allocated
   and HOST_RSP set (see setup of host stack in real_cgcvmx_on() in cgcvmx64.c)
   ultimately invokes vmexitCallback(VmxStruct *vmx) to handle the VMexit
*/
/*
   on VM exit, gp regs still reflect guest values w/ exception of esp
   HOST_RSP points at beginning of CPU struct from VmxInitialize
*/
ENTRY vmexit_handler
	push %rax
	push %rcx
	push %rdx
	push %rbx
	sub $8, %rsp
	push %rbp
	push %rsi
	push %rdi
	push %r8
	push %r9 
	push %r10
	push %r11
	push %r12
	push %r13
	push %r14
	push %r15

	mov %rsp, %rdi		/* VmxStruct* */
	call  vmexitCallback

	pop %r15
	pop %r14
	pop %r13
	pop %r12
	pop %r11
	pop %r10
	pop %r9
	pop %r8
	pop %rdi
	pop %rsi
	pop %rbp
	add $8, %rsp
	pop %rbx
	pop %rdx
	pop %rcx
	pop %rax
	vmresume
	ret
END vmexit_handler

/*
cgc_cpuid(CpuIdRegs *regs)
*/
ENTRY cgc_cpuid
	push %rbx
	mov 0(%rdi),%eax	/* regs->eax */
	mov 8(%rdi),%ecx	/* regs->ecx */

	cpuid

	mov %eax, 0x0(%rdi)
	mov %ebx, 0x4(%rdi)
	mov %ecx, 0x8(%rdi)
	mov %edx, 0xc(%rdi)

	pop %rbx
	ret
END cgc_cpuid

/*
uint8_t cgc_rdrand(uint64_t *rnd);
*/
ENTRY cgc_rdrand
	rdrand %rax
	mov %rax,(%rdi)
	setb %al
	movzbl %al,%eax
	ret
END cgc_rdrand

/*
uint8_t cgc_rdseed(uint64_t *rnd);
*/
ENTRY cgc_rdseed
	rdseed %rax
	mov %rax,(%rdi)
	setb %al
	movzbl %al,%eax
	ret
END cgc_rdseed

ENTRY RegGetTSC
	rdtsc
	shlq $32, %rdx
	orq %rdx, %rax
	ret
END RegGetTSC

ENTRY RegGetCs
	movw %cs, %ax
	movzwq %ax, %rax
	ret
END RegGetCs

ENTRY RegGetDs
	movw %ds, %ax
	movzwq %ax, %rax
	ret
END RegGetDs

ENTRY RegGetEs
	movw %es, %ax
	movzwq %ax, %rax
	ret
END RegGetEs

ENTRY RegSetEs
	movw %di, %es
	ret
END RegSetEs

ENTRY RegGetSs
	movw %ss, %ax
	movzwq %ax, %rax
	ret
END RegGetSs

ENTRY RegGetFs
	movw %fs, %ax
	movzwq %ax, %rax
	ret
END RegGetFs

ENTRY RegGetGs
	movw %gs, %ax
	movzwq %ax, %rax
	ret
END RegGetGs

ENTRY RegGetCr0
	mov %cr0, %rax
	ret
END RegGetCr0

/*
void RegSetCr0(uint64_t _cr0)
*/
ENTRY RegSetCr0
	mov %rdi, %cr0
	ret
END RegSetCr0

/*
void cgc_clts();
*/
ENTRY cgc_clts
	clts
	ret
END cgc_clts
   
/*
void cgc_lmsw(uint64_t lmsw);
*/
ENTRY cgc_lmsw
	lmsw %di
	ret
END cgc_lmsw

ENTRY RegGetCr2
	mov %cr2, %rax
	ret
END RegGetCr2

ENTRY RegSetCr2
	mov %rdi, %cr2
	ret
END RegSetCr2

ENTRY RegGetCr3
	mov %cr3, %rax
	ret
END RegGetCr3

/*
void RegSetCr3(uint64_t _cr3)
*/
ENTRY RegSetCr3
	mov %rdi, %cr3
	ret
END RegSetCr3

ENTRY RegGetCr4
   	mov %cr4, %rax
	ret
END RegGetCr4

/*
void RegSetCr4(uint64_t _cr4)
*/
ENTRY RegSetCr4
	mov %rdi, %cr4
	ret
END RegSetCr4

ENTRY RegGetRflags
	pushfq
	pop %rax
	ret
END RegGetRflags

ENTRY RegGetRsp
	lea 0x8(%rsp),%rax
	ret
END RegGetRsp


/*
void do_sidt(uint8_t *idt)
*/
ENTRY do_sidt
	sidt	(%rdi)
	ret
END do_sidt

/*
void do_lidt(uint8_t *idt)
*/
ENTRY do_lidt
	lidt (%rdi)
	ret
END do_lidt

/*
void do_sgdt(uint8_t *gdt)
*/
ENTRY do_sgdt
	sgdt (%rdi)
	ret
END do_sgdt

/*
void do_lgdt(uint8_t *gdt)
*/
ENTRY do_lgdt
	lgdt (%rdi)
	ret
END do_lgdt

ENTRY GetIdtBase
	subq $16, %rsp
   	sidt (%rsp)
	mov 0x2(%rsp), %rax
	addq $16, %rsp
	ret
END GetIdtBase

ENTRY GetIdtLimit
	subq $0x10, %rsp
	sidt (%rsp)
	movzwq (%rsp), %rax
	addq $16, %rsp
	ret
END GetIdtLimit

ENTRY GetGdtBase
	subq $0x10, %rsp
	sgdt (%rsp)
	movq 0x2(%rsp),%rax
	addq $16, %rsp
	ret
END GetGdtBase

ENTRY GetGdtLimit
	subq $0x10, %rsp
	sgdt (%rsp)
	movzwq (%rsp), %rax
	addq $16, %rsp
	ret
END GetGdtLimit

/*
uint16_t do_sldt()
*/
ENTRY do_sldt
ENTRY GetLdtr
	sldt %ax
	movzwq %ax, %rax
	ret
END do_sldt
END GetLdtr

/*
void do_lldt(uint16_t ldt)
*/
ENTRY do_lldt
	lldt %di
	ret
END do_lldt

/*
uint16_t do_str()
*/
ENTRY do_str
ENTRY GetTrSelector
	str %ax
	movzwq %ax, %rax
   	ret
END do_str
END GetTrSelector

/*
void do_ltr(uint16_t tr)
*/
ENTRY do_ltr
	ltr %di
	ret
END do_ltr

ENTRY GetTrLimit
	str %ax
	movzwq %ax, %rax
	lsl %eax, %rax
	ret
END GetTrLimit
 
ENTRY GetTrAttr
	str   %ax
	movzwq %ax, %rax
	lar %eax, %rax
	ret
END GetTrAttr

ENTRY GetLdtAttr
	sldt %ax
	movzwq %ax, %rax
	lar %eax, %rax
	ret
END GetLdtAttr

ENTRY GetSegAttr
	lar   %eax, %rax
	ret
END GetSegAttr

/*
uint64_t MsrRead(uint32_t reg);
*/
ENTRY MsrRead
	mov  %rdi, %rcx
	/* per ref manual, rdmsr clears high order bits of rdx and rax here */
	rdmsr    /* MSR[rcx] --> edx:eax */
	/* combine into single 64 bit result */
	shlq  $32, %rdx
	orq   %rdx, %rax
	ret
END MsrRead

/*
void MsrWrite(uint32_t reg, uint64_t val);
*/
ENTRY MsrWrite
	movl %edi, %ecx
	/* split rsi across edx:eax */
   	movq %rsi, %rdx
	shrq  $32, %rdx
	movl %esi, %eax
	wrmsr		/* MSR[ecx] <- edx:eax */
	ret
END MsrWrite


/*
   init_tramp computes the correct values for GUEST_RIP and GUEST_RSP
   to be specified in the VMCS prior to issuing vmlaunch. The virtualized
   guest will end up reentering at guest_rip below
*/
ENTRY init_tramp
	push %rax
	push %rcx
	push %rdx
	push %rbx
/*   push rsp */
	push %rbp
	push %rsi
	push %rdi
	push %r8
	push %r9 
	push %r10
	push %r11
	push %r12
	push %r13
	push %r14
	push %r15
   
	movl  %edi, %edx	/* cpu number */
	movq %rsp, %rsi		/* guest rsp, positioned to ret from here */   
	lea  guest_rip, %rdi
   
	call real_cgcvmx_on

	/*** only get here if init failed ***/
fail_rip:
	pop %r15
	pop %r14
	pop %r13
	pop %r12
	pop %r11
	pop %r10
	pop %r9
	pop %r8
	pop %rdi
	pop %rsi
	pop %rbp
/*   pop rsp  */
	pop %rbx
	pop %rdx
	pop %rcx
	pop %rax
	mov $0xffff,%ax
	movswq %ax,%rax
	ret
   
guest_rip:
	/*if we get here, guest vmlaunch was successful*/

	pop %r15
	pop %r14
	pop %r13
	pop %r12
	pop %r11
	pop %r10
	pop %r9
	pop %r8
	pop %rdi
	pop %rsi
	pop %rbp
/*   pop rsp  */
	pop %rbx
	pop %rdx
	pop %rcx
	pop %rax
	xorq %rax, %rax
	ret
END init_tramp
