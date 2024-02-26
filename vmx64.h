
#ifndef __VMX32_H
#define __VMX32_H

#include <sys/types.h>

//Implemented in vmx64.S
uint32_t vm_call(uint64_t funcNum);

uint32_t vm_ptrld(uint64_t vmcsAddr);

uint32_t vm_ptrst(uint64_t vmcsAddr);

uint32_t vm_clear(uint64_t vmcsAddr);

uint64_t vm_read(uint32_t field);

uint32_t vm_write(uint64_t field, uint64_t value);

uint32_t vmx_off(void);

uint32_t vmx_on(uint64_t vmxonAddr);

uint32_t vm_launch(void);

uint32_t vm_resume(void);

void vmexit_handler(void);

typedef struct _CpuIdRegs {
   uint32_t eax;
   uint32_t ebx;
   uint32_t ecx;
   uint32_t edx;
} CpuIdRegs;

void cgc_cpuid(CpuIdRegs *regs);
uint8_t cgc_rdrand(uint64_t *rnd);
uint8_t cgc_rdseed(uint64_t *rnd);

uint16_t RegGetCs(void);
uint16_t RegGetDs(void);
uint16_t RegGetEs(void);
void RegSetEs(uint16_t);
uint16_t RegGetSs(void);
uint16_t RegGetFs(void);
uint16_t RegGetGs(void);
uint64_t RegGetCr0(void);
void RegSetCr0(uint64_t _cr0);
void cgc_clts(void);
void cgc_lmsw(uint32_t lmsw);
uint64_t RegGetCr2(void);
void RegSetCr2(uint64_t);
uint64_t RegGetCr3(void);
void RegSetCr3(uint64_t _cr3);
uint64_t RegGetCr4(void);
void RegSetCr4(uint64_t _cr4);
uint64_t RegGetCr8(void);
uint64_t RegGetRflags(void);
uint64_t RegGetRsp(void);
uint64_t GetIdtBase(void);
uint16_t GetIdtLimit(void);
uint64_t GetGdtBase(void);
uint16_t GetGdtLimit(void);
uint16_t GetLdtr(void);

uint16_t GetTrSelector(void);
uint32_t GetTrLimit(void);
uint32_t GetTrAttr(void);
uint32_t GetLdtAttr(void);
uint32_t GetSegAttr(uint16_t);

void do_sidt(uint8_t *idt);
void do_sgdt(uint8_t *gdt);
uint16_t do_sldt();
uint16_t do_str();

void do_lidt(uint8_t *idt);
void do_lgdt(uint8_t *gdt);
void do_lldt(uint16_t ldt);
void do_ltr(uint16_t tr);

uint64_t RegGetTSC(void);

void cr4_set(uint64_t bits);
void cr4_reset(uint64_t bits);

uint64_t RegSetCr8(uint64_t NewCr8);

uint64_t MsrRead(uint32_t reg);
void MsrWrite(uint32_t reg, uint64_t val);

int init_tramp(uint32_t procNum);

#endif
