#ifndef __VMXON_H
#define __VMXON_H

#define VMX_VPID                    0x00000000
#define VMX_PI_NOTIFICATION_VEC     0x00000002
#define VMX_EPTP_INDEX              0x00000004

#define VMX_GUEST_ES_SEL            0x00000800
#define VMX_GUEST_CS_SEL            0x00000802
#define VMX_GUEST_SS_SEL            0x00000804
#define VMX_GUEST_DS_SEL            0x00000806
#define VMX_GUEST_FS_SEL            0x00000808
#define VMX_GUEST_GS_SEL            0x0000080a
#define VMX_GUEST_LDTR_SEL          0x0000080c
#define VMX_GUEST_TR_SEL            0x0000080e
#define VMX_GUEST_INT_STATUS        0x00000810

#define VMX_HOST_ES_SEL             0x00000c00
#define VMX_HOST_CS_SEL             0x00000c02
#define VMX_HOST_SS_SEL             0x00000c04
#define VMX_HOST_DS_SEL             0x00000c06
#define VMX_HOST_FS_SEL             0x00000c08
#define VMX_HOST_GS_SEL             0x00000c0a
#define VMX_HOST_TR_SEL             0x00000c0c

#define VMX_IO_BITMAP_A_FULL        0x00002000
#define VMX_IO_BITMAP_A_HIGH        0x00002001
#define VMX_IO_BITMAP_B_FULL        0x00002002
#define VMX_IO_BITMAP_B_HIGH        0x00002003
#define VMX_MSR_BITMAP_FULL         0x00002004
#define VMX_MSR_BITMAP_HIGH         0x00002005
#define VMX_EXIT_MSR_STORE_ADDR_FULL 0x00002006
#define VMX_EXIT_MSR_STORE_ADDR_HIGH 0x00002007
#define VMX_EXIT_MSR_LOAD_ADDR_FULL 0x00002008
#define VMX_EXIT_MSR_LOAD_ADDR_HIGH 0x00002009
#define VMX_ENTRY_MSR_LOAD_ADDR_FULL 0x0000200a
#define VMX_ENTRY_MSR_LOAD_ADDR_HIGH 0x0000200b
#define VMX_EXECUTIVE_VMCS_PTR_FULL 0x0000200c
#define VMX_EXECUTIVE_VMCS_PTR_HIGH 0x0000200d
#define VMX_TSC_OFFSET_FULL         0x00002010
#define VMX_TSC_OFFSET_HIGH         0x00002011
#define VMX_VIRTUAL_APIC_PAGE_ADDR_FULL 0x00002012
#define VMX_VIRTUAL_APIC_PAGE_ADDR_HIGH 0x00002013
#define VMX_APIC_ACCESS_ADDR_FULL   0x00002014
#define VMX_APIC_ACCESS_ADDR_HIGH   0x00002015
#define VMX_POSTED_INT_DESCR_FULL   0x00002016
#define VMX_POSTED_INT_DESCR_HIGH   0x00002017
#define VMX_VMFUNC_CONTROLS_FULL    0x00002018
#define VMX_VMFUNC_CONTROLS_HIGH    0x00002019
#define VMX_EPT_POINTER_FULL        0x0000201A
#define VMX_EPT_POINTER_HIGH        0x0000201B

#define VMX_EOI_EXIT0_BITMAP_FULL   0x0000201C
#define VMX_EOI_EXIT0_BITMAP_HIGH   0x0000201D
#define VMX_EOI_EXIT1_BITMAP_FULL   0x0000201E
#define VMX_EOI_EXIT1_BITMAP_HIGH   0x0000201F
#define VMX_EOI_EXIT2_BITMAP_FULL   0x00002020
#define VMX_EOI_EXIT2_BITMAP_HIGH   0x00002021
#define VMX_EOI_EXIT3_BITMAP_FULL   0x00002022
#define VMX_EOI_EXIT3_BITMAP_HIGH   0x00002023
#define VMX_EPTP_LIST_FULL          0x00002024
#define VMX_EPTP_LIST_HIGH          0x00002025
#define VMX_VMREAD_BITMAP_FULL      0x00002026
#define VMX_VMREAD_BITMAP_HIGH      0x00002027
#define VMX_VMWRITE_BITMAP_FULL     0x00002028
#define VMX_VMWRITE_BITMAP_HIGH     0x00002029
#define VMX_VIRT_EXC_INFO_ADDR_FULL  0x0000202A
#define VMX_VIRT_EXC_INFO_ADDR_HIGH  0x0000202B
#define VMX_XSS_EXITING_BITMAP_FULL  0x0000202C
#define VMX_XSS_EXITING_BITMAP_HIGH  0x0000202D

#define VMX_VMS_LINK_PTR_FULL       0x00002800
#define VMX_VMS_LINK_PTR_HIGH       0x00002801
#define VMX_GUEST_IA32_DEBUGCTL_FULL 0x00002802
#define VMX_GUEST_IA32_DEBUGCTL_HIGH 0x00002803
#define VMX_GUEST_IA32_PAT_FULL     0x00002804
#define VMX_GUEST_IA32_PAT_HIGH     0x00002805
#define VMX_GUEST_IA32_EFER_FULL    0x00002806
#define VMX_GUEST_IA32_EFER_HIGH    0x00002807
#define VMX_GUEST_IA32_PERF_CTL_FULL 0x00002808
#define VMX_GUEST_IA32_PERF_CTL_HIGH 0x00002809
#define VMX_GUEST_PDPTE0_FULL       0x0000280A
#define VMX_GUEST_PDPTE0_HIGH       0x0000280B
#define VMX_GUEST_PDPTE1_FULL       0x0000280C
#define VMX_GUEST_PDPTE1_HIGH       0x0000280D
#define VMX_GUEST_PDPTE2_FULL       0x0000280E
#define VMX_GUEST_PDPTE2_HIGH       0x0000280F
#define VMX_GUEST_PDPTE3_FULL       0x00002810
#define VMX_GUEST_PDPTE3_HIGH       0x00002811

#define VMX_HOST_IA32_PAT_FULL      0x00002C00
#define VMX_HOST_IA32_PAT_HIGH      0x00002C01
#define VMX_HOST_IA32_EFER_FULL     0x00002C02
#define VMX_HOST_IA32_EFER_HIGH     0x00002C03
#define VMX_HOST_IA32_PERF_CTL_FULL 0x00002C04
#define VMX_HOST_IA32_PERF_CTL_HIGH 0x00002C05

#define VMX_PIN_VM_EXEC_CONTROLS    0x00004000
#define VMX_PROC_VM_EXEC_CONTROLS   0x00004002
#define VMX_EXCEPTION_BITMAP        0x00004004
#define VMX_PF_EC_MASK              0x00004006
#define VMX_PF_EC_MATCH             0x00004008
#define VMX_CR3_TARGET_COUNT        0x0000400a
#define VMX_EXIT_CONTROLS           0x0000400c
#define VMX_EXIT_MSR_STORE_COUNT    0x0000400e
#define VMX_EXIT_MSR_LOAD_COUNT     0x00004010
#define VMX_ENTRY_CONTROLS          0x00004012
#define VMX_ENTRY_MSR_LOAD_COUNT    0x00004014
#define VMX_ENTRY_INT_INFO_FIELD    0x00004016
#define VMX_ENTRY_EXCEPTION_EC      0x00004018
#define VMX_ENTRY_INSTR_LENGTH      0x0000401a
#define VMX_TPR_THRESHOLD           0x0000401c
#define VMX_PROC_VM_EXEC_CONTROLS2  0x0000401E
#define VMX_PLE_GAP                 0x00004020
#define VMX_PLE_WINDOW              0x00004022

#define VMX_INSTR_ERROR             0x00004400
#define VMX_EXIT_REASON             0x00004402
#define VMX_EXIT_INT_INFO           0x00004404
#define VMX_EXIT_INT_EC             0x00004406
#define VMX_IDT_VEC_INFO_FIELD      0x00004408
#define VMX_IDT_VEC_EC              0x0000440a
#define VMX_EXIT_INSTR_LEN          0x0000440c
#define VMX_INSTR_INFO              0x0000440e

#define VMX_GUEST_ES_LIMIT          0x00004800
#define VMX_GUEST_CS_LIMIT          0x00004802
#define VMX_GUEST_SS_LIMIT          0x00004804
#define VMX_GUEST_DS_LIMIT          0x00004806
#define VMX_GUEST_FS_LIMIT          0x00004808
#define VMX_GUEST_GS_LIMIT          0x0000480a
#define VMX_GUEST_LDTR_LIMIT        0x0000480c
#define VMX_GUEST_TR_LIMIT          0x0000480e
#define VMX_GUEST_GDTR_LIMIT        0x00004810
#define VMX_GUEST_IDTR_LIMIT        0x00004812
#define VMX_GUEST_ES_ATTR           0x00004814
#define VMX_GUEST_CS_ATTR           0x00004816
#define VMX_GUEST_SS_ATTR           0x00004818
#define VMX_GUEST_DS_ATTR           0x0000481a
#define VMX_GUEST_FS_ATTR           0x0000481c
#define VMX_GUEST_GS_ATTR           0x0000481e
#define VMX_GUEST_LDTR_ATTR         0x00004820
#define VMX_GUEST_TR_ATTR           0x00004822
#define VMX_GUEST_INTERRUPTIBILITY_INFO 0x00004824
#define VMX_GUEST_ACTIVITY_STATE    0x00004826
#define VMX_GUEST_SMBASE            0x00004828
#define VMX_GUEST_IA32_SYSENTER_CS  0x0000482a
#define VMX_GUEST_TIMER             0x0000482e

#define VMX_HOST_IA32_SYSENTER_CS   0x00004c00

#define VMX_CR0_MASK                0x00006000
#define VMX_CR4_MASK                0x00006002
#define VMX_CR0_READ_SHADOW         0x00006004
#define VMX_CR4_READ_SHADOW         0x00006006
#define VMX_CR3_TARGET_0            0x00006008
#define VMX_CR3_TARGET_1            0x0000600a
#define VMX_CR3_TARGET_2            0x0000600c
#define VMX_CR3_TARGET_3            0x0000600e

#define VMX_EXIT_QUALIFICATION      0x00006400
#define VMX_IO_RCX                  0x00006402
#define VMX_IO_RDI                  0x00006406
#define VMX_GUEST_LINEAR_ADDR       0x0000640a

#define VMX_GUEST_PHYSICAL_ADDR_FULL  0x00002400
#define VMX_GUEST_PHYSICAL_ADDR_HIGH  0x00002401

#define VMX_GUEST_CR0               0x00006800
#define VMX_GUEST_CR3               0x00006802
#define VMX_GUEST_CR4               0x00006804
#define VMX_GUEST_ES_BASE           0x00006806
#define VMX_GUEST_CS_BASE           0x00006808
#define VMX_GUEST_SS_BASE           0x0000680a
#define VMX_GUEST_DS_BASE           0x0000680c
#define VMX_GUEST_FS_BASE           0x0000680e
#define VMX_GUEST_GS_BASE           0x00006810
#define VMX_GUEST_LDTR_BASE         0x00006812
#define VMX_GUEST_TR_BASE           0x00006814
#define VMX_GUEST_GDTR_BASE         0x00006816
#define VMX_GUEST_IDTR_BASE         0x00006818
#define VMX_GUEST_DR7               0x0000681a
#define VMX_GUEST_RSP               0x0000681c
#define VMX_GUEST_RIP               0x0000681e
#define VMX_GUEST_RFLAGS            0x00006820
#define VMX_GUEST_PENDING_DEBUG_EXCEPT 0x00006822
#define VMX_GUEST_IA32_SYSENTER_ESP 0x00006824
#define VMX_GUEST_IA32_SYSENTER_EIP 0x00006826

#define VMX_HOST_CR0                0x00006c00
#define VMX_HOST_CR3                0x00006c02
#define VMX_HOST_CR4                0x00006c04
#define VMX_HOST_FS_BASE            0x00006c06
#define VMX_HOST_GS_BASE            0x00006c08
#define VMX_HOST_TR_BASE            0x00006c0a
#define VMX_HOST_GDTR_BASE          0x00006c0c
#define VMX_HOST_IDTR_BASE          0x00006c0e
#define VMX_HOST_IA32_SYSENTER_ESP  0x00006c10
#define VMX_HOST_IA32_SYSENTER_EIP  0x00006c12
#define VMX_HOST_RSP                0x00006c14
#define VMX_HOST_RIP                0x00006c16

// CR4 bits */
#ifndef	X86_CR4_SMEP
#define	X86_CR4_SMEP		0x00100000	/* SMEP enable */
#endif
#ifndef	X86_CR4_OSXSAVE
#define	X86_CR4_OSXSAVE		0x00040000	/* XSAVE/extended state enable */
#endif
#ifndef	X86_CR4_PCIDE
#define	X86_CR4_PCIDE		0x00020000	/* PCID enable */
#endif
#ifndef	X86_CR4_FSGSBASE
#define	X86_CR4_FSGSBASE	0x00010000	/* FSGSBASE enable */
#endif
#ifndef	X86_CR4_SMXE
#define	X86_CR4_SMXE		0x00004000	/* SMX enable */
#endif
#ifndef	X86_CR4_VMXE
#define	X86_CR4_VMXE		0x00002000	/* VMX enable */
#endif
#ifndef	X86_CR4_OSXMMEXCPT
#define	X86_CR4_OSXMMEXCPT	0x00000400	/* os support for Unmasked SIMD exceptions */
#endif
#ifndef	X86_CR4_OSFXSR
#define	X86_CR4_OSFXSR		0x00000200	/* os support for FXSAVE/FXRSTOR */
#endif
#ifndef	X86_CR4_PCE
#define	X86_CR4_PCE		0x00000100	/* performance monitor counter enable */
#endif
#ifndef	X86_CR4_PGE
#define	X86_CR4_PGE		0x00000080	/* page global enable */
#endif
#ifndef	X86_CR4_MCE
#define	X86_CR4_MCE		0x00000040	/* machine check enable */
#endif
#ifndef	X86_CR4_PAE
#define	X86_CR4_PAE		0x00000020	/* physical address extension */
#endif
#ifndef	X86_CR4_PSE
#define	X86_CR4_PSE		0x00000010	/* page size extensions */
#endif
#ifndef	X86_CR4_DE
#define	X86_CR4_DE		0x00000008	/* debugging extensions */
#endif
#ifndef	X86_CR4_TSD
#define	X86_CR4_TSD		0x00000004	/* timestamp disable */
#endif
#ifndef	X86_CR4_PVI
#define	X86_CR4_PVI		0x00000002	/* protected-mode virtual interrupt */
#endif
#ifndef	X86_CR4_VME
#define	X86_CR4_VME		0x00000001	/* virtual 8086 extensions */
#endif

#define	X86_CR4_ALLBITS (X86_CR4_SMEP | X86_CR4_OSXSAVE | X86_CR4_PCIDE | \
			 X86_CR4_FSGSBASE | X86_CR4_SMXE | X86_CR4_VMXE | \
			 X86_CR4_OSXMMEXCPT | X86_CR4_OSFXSR | X86_CR4_PCE | \
			 X86_CR4_PGE | X86_CR4_MCE | X86_CR4_PAE | \
			 X86_CR4_PSE | X86_CR4_DE | X86_CR4_TSD | \
			 X86_CR4_PVI | X86_CR4_VME)

#ifndef	X86_CR0_PG
#define	X86_CR0_PG		0x80000000	/* paging */
#endif
#ifndef	X86_CR0_CD
#define	X86_CR0_CD		0x40000000	/* cache disable */
#endif
#ifndef	X86_CR0_NW
#define	X86_CR0_NW		0x20000000	/* not write-through */
#endif
#ifndef	X86_CR0_AM
#define	X86_CR0_AM		0x00040000	/* alignment mask */
#endif
#ifndef	X86_CR0_WP
#define	X86_CR0_WP		0x00010000	/* write protect */
#endif
#ifndef	X86_CR0_NE
#define	X86_CR0_NE		0x00000020	/* numeric error */
#endif
#ifndef	X86_CR0_ET
#define	X86_CR0_ET		0x00000010	/* extension type */
#endif
#ifndef	X86_CR0_TS
#define	X86_CR0_TS		0x00000008	/* task switched */
#endif
#ifndef	X86_CR0_EM
#define	X86_CR0_EM		0x00000004	/* emulation */
#endif
#ifndef	X86_CR0_MP
#define	X86_CR0_MP		0x00000002	/* monitor coprocessor */
#endif
#ifndef	X86_CR0_PE
#define	X86_CR0_PE		0x00000001	/* protection enable */
#endif

#define	X86_CR0_ALLBITS (X86_CR0_PG | X86_CR0_CD | X86_CR0_NW | X86_CR0_AM | \
			 X86_CR0_WP | X86_CR0_NE | X86_CR0_ET | X86_CR0_TS | \
  			 X86_CR0_EM | X86_CR0_MP | X86_CR0_PE)

/*
 * VMX Exit Reasons
 */

#define VMEXIT_REASONS_FAILED_VMENTRY 0x80000000

#define VMEXIT_REASON_EXCEPTION_NMI       0
#define VMEXIT_REASON_EXTERNAL_INTERRUPT  1
#define VMEXIT_REASON_TRIPLE_FAULT        2
#define VMEXIT_REASON_INIT                3
#define VMEXIT_REASON_SIPI                4
#define VMEXIT_REASON_IO_SMI              5
#define VMEXIT_REASON_OTHER_SMI           6
#define VMEXIT_REASON_PENDING_INTERRUPT   7
#define VMEXIT_REASON_NMI_WINDOW          8
#define VMEXIT_REASON_TASK_SWITCH         9
#define VMEXIT_REASON_CPUID               10
#define VMEXIT_REASON_GETSEC              11
#define VMEXIT_REASON_HLT                 12
#define VMEXIT_REASON_INVD                13
#define VMEXIT_REASON_INVLPG              14
#define VMEXIT_REASON_RDPMC               15
#define VMEXIT_REASON_RDTSC               16
#define VMEXIT_REASON_RSM                 17
#define VMEXIT_REASON_VMCALL              18
#define VMEXIT_REASON_VMCLEAR             19
#define VMEXIT_REASON_VMLAUNCH            20
#define VMEXIT_REASON_VMPTRLD             21
#define VMEXIT_REASON_VMPTRST             22
#define VMEXIT_REASON_VMREAD              23
#define VMEXIT_REASON_VMRESUME            24
#define VMEXIT_REASON_VMWRITE             25
#define VMEXIT_REASON_VMXOFF              26
#define VMEXIT_REASON_VMXON               27
#define VMEXIT_REASON_CR_ACCESS           28
#define VMEXIT_REASON_DR_ACCESS           29
#define VMEXIT_REASON_IO_INSTRUCTION      30
#define VMEXIT_REASON_MSR_READ            31
#define VMEXIT_REASON_MSR_WRITE           32
#define VMEXIT_REASON_INVALID_GUEST_STATE 33
#define VMEXIT_REASON_MSR_LOADING         34

#define VMEXIT_REASON_MWAIT_INSTRUCTION   36
#define VMEXIT_REASON_MONITOR_TRAP        37

#define VMEXIT_REASON_MONITOR_INSTRUCTION 39
#define VMEXIT_REASON_PAUSE_INSTRUCTION   40
#define VMEXIT_REASON_MACHINE_CHECK       41

#define VMEXIT_REASON_TPR_BELOW_THRESHOLD 43
#define VMEXIT_REASON_APIC_ACCESS         44
#define VMEXIT_REASON_VIRTUALIZED_EOI     45
#define VMEXIT_REASON_ACCESS_GDTR_IDTR    46
#define VMEXIT_REASON_ACCESS_LDTR_TR      47
#define VMEXIT_REASON_EPT_VILOATION       48
#define VMEXIT_REASON_EPT_MISCONFIG       49
#define VMEXIT_REASON_INVEPT              50
#define VMEXIT_REASON_RDTSCP              51
#define VMEXIT_REASON_VMX_PREEMPT_TIMER   52
#define VMEXIT_REASON_INVVPID             53
#define VMEXIT_REASON_WMINVD              54
#define VMEXIT_REASON_XSETBV              55
#define VMEXIT_REASON_APIC_WRITE          56
#define VMEXIT_REASON_RDRAND              57
#define VMEXIT_REASON_INVPCID             58
#define VMEXIT_REASON_VMFUNC              59
#define VMEXIT_REASON_RDSEED              61
#define VMEXIT_REASON_XSAVES              63
#define VMEXIT_REASON_XRSTORES            64


#ifndef MSR_IA32_FEATURE_CONTROL
#define MSR_IA32_FEATURE_CONTROL 0x3A
#endif

/* performance event counters */
#define	MSR_IA32_PMC(n)		(0xc1 + (n))
#define	MSR_IA32_PMC0		MSR_IA32_PMC(0)
#define	MSR_IA32_PMC1		MSR_IA32_PMC(1)
#define	MSR_IA32_PMC2		MSR_IA32_PMC(2)
#define	MSR_IA32_PMC3		MSR_IA32_PMC(3)
#define	MSR_IA32_PMC4		MSR_IA32_PMC(4)
#define	MSR_IA32_PMC5		MSR_IA32_PMC(5)
#define	MSR_IA32_PMC6		MSR_IA32_PMC(6)
#define	MSR_IA32_PMC7		MSR_IA32_PMC(7)

/* performance event counters (full width alias) */
#define	MSR_IA32_A_PMC(n)	(0x4c1 + (n))
#define	MSR_IA32_A_PMC0		MSR_IA32_A_PMC(0)
#define	MSR_IA32_A_PMC1		MSR_IA32_A_PMC(1)
#define	MSR_IA32_A_PMC2		MSR_IA32_A_PMC(2)
#define	MSR_IA32_A_PMC3		MSR_IA32_A_PMC(3)
#define	MSR_IA32_A_PMC4		MSR_IA32_A_PMC(4)
#define	MSR_IA32_A_PMC5		MSR_IA32_A_PMC(5)
#define	MSR_IA32_A_PMC6		MSR_IA32_A_PMC(6)
#define	MSR_IA32_A_PMC7		MSR_IA32_A_PMC(7)
	
#ifndef MSR_IA32_SYSENTER_CS
#define MSR_IA32_SYSENTER_CS     0x174
#endif

#ifndef MSR_IA32_SYSENTER_ESP
#define MSR_IA32_SYSENTER_ESP    0x175
#endif

#ifndef MSR_IA32_SYSENTER_EIP
#define MSR_IA32_SYSENTER_EIP    0x176
#endif

#ifndef MSR_IA32_DEBUGCTL
#define MSR_IA32_DEBUGCTL 0x1d9
#endif

#define MSR_IA32_PERFEVTSEL(n)	(0x186 + n)
#define MSR_IA32_PERFEVTSEL0	MSR_IA32_PERFEVTSEL(0)
#define MSR_IA32_PERFEVTSEL1	MSR_IA32_PERFEVTSEL(1)
#define MSR_IA32_PERFEVTSEL2	MSR_IA32_PERFEVTSEL(2)
#define MSR_IA32_PERFEVTSEL3	MSR_IA32_PERFEVTSEL(3)
#define MSR_IA32_PERFEVTSEL4	MSR_IA32_PERFEVTSEL(4)
#define MSR_IA32_PERFEVTSEL5	MSR_IA32_PERFEVTSEL(5)
#define MSR_IA32_PERFEVTSEL6	MSR_IA32_PERFEVTSEL(6)
#define MSR_IA32_PERFEVTSEL7	MSR_IA32_PERFEVTSEL(7)

#define MSR_IA32_PERF_STATUS	0x198

#ifndef MSR_IA32_PAT
#define MSR_IA32_PAT 0x277
#endif

#define MSR_IA32_PERF_CAPABILITIES	0x345

#define	MSR_IA32_FIXED_CTR(n)		(0x309 + n)
#define	MSR_IA32_FIXED_CTR0		MSR_IA32_FIXED_CTR(0)
#define	MSR_IA32_FIXED_CTR1		MSR_IA32_FIXED_CTR(1)
#define	MSR_IA32_FIXED_CTR2		MSR_IA32_FIXED_CTR(2)

#define	MSR_IA32_FIXED_CTR_CTRL		0x38d

#define	MSR_IA32_PERF_GLOBAL_STATUS	0x38e

#ifndef MSR_IA32_PERF_GLOBAL_CTRL
#define MSR_IA32_PERF_GLOBAL_CTRL	0x38f
#endif

#define	MSR_IA32_PERF_GLOBAL_OVFCTRL	0x390

#ifndef MSR_IA32_VMX_BASIC
#define MSR_IA32_VMX_BASIC       0x480
#endif

#ifndef MSR_IA32_VMX_PINBASED_CTLS
#define MSR_IA32_VMX_PINBASED_CTLS  0x481
#endif
#define	PIN_BASED_EXT_INTR_EXIT		0x01	/* external interrupt exiting */
#define PIN_BASED_NMI_EXITING		0x08	/* NMI exiting */
#define PIN_BASED_VIRTUAL_NMI		0x20	/* virtual NMIs */
#define PIN_BASED_ACTIVATE_PREEMPT_TIMER 0x40	/* activate VMX-preemption timer */
#define PIN_BASED_POSTED_INTRS		0x80	/* process posted interrupts */

#ifndef MSR_IA32_VMX_PROCBASED_CTLS
#define MSR_IA32_VMX_PROCBASED_CTLS 0x482
#endif

#ifndef MSR_IA32_VMX_EXIT_CTLS
#define MSR_IA32_VMX_EXIT_CTLS      0x483
#endif

#ifndef MSR_IA32_VMX_ENTRY_CTLS
#define MSR_IA32_VMX_ENTRY_CTLS     0x484
#endif

#ifndef MSR_IA32_VMX_MISC
#define MSR_IA32_VMX_MISC           0x485
#define	VMX_MISC_MAX_SAVED_MSR(x)   (((x) >> 25) & 0x7)
#define VMX_MISC_CR3_TARGETS(x)	    (((x) >> 16) & 0x1ff)
#endif

#ifndef MSR_IA32_VMX_PROCBASED_CTLS2
#define MSR_IA32_VMX_PROCBASED_CTLS2 0x48b
#endif

#define MSR_IA32_VMX_VMFUNC	0x491
#define VMX_VMFUNC_EPTP_SWITCH	0x1

#ifndef MSR_IA32_EFER
#define MSR_IA32_EFER 0xC0000080
#endif

#ifndef MSR_IA32_STAR
#define MSR_IA32_STAR 0xC0000081
#endif

#ifndef MSR_IA32_LSTAR
#define MSR_IA32_LSTAR 0xC0000082
#endif

#ifndef MSR_IA32_FMASK
#define MSR_IA32_FMASK 0xC0000084
#endif

#ifndef MSR_FS_BASE
#define MSR_FS_BASE   0xC0000100
#endif

#ifndef MSR_GS_BASE
#define MSR_GS_BASE   0xC0000101
#endif

#ifndef MSR_SWAPGS
#define MSR_SWAPGS   0xC0000102
#endif

#define MSR_UNCORE_PERF_GLOBAL_CTRL	0x391
#define MSR_UNCORE_PERF_GLOBAL_STATUS	0x392
#define MSR_UNCORE_PERF_GLOBAL_OVF_CTRL	0x393
#define MSR_UNCORE_PERF_FIXED_CTR0	0x394
#define MSR_UNCORE_PERF_FIXED_CTR_CTRL	0x395
#define MSR_UNCORE_ADDR_OPCODE_MATCH    0x396

#define MSR_UNCORE_PMC0			0x3b0
#define MSR_UNCORE_PMC1			0x3b1
#define MSR_UNCORE_PMC2			0x3b2
#define MSR_UNCORE_PMC3			0x3b3
#define MSR_UNCORE_PMC4			0x3b4
#define MSR_UNCORE_PMC5			0x3b5
#define MSR_UNCORE_PMC6			0x3b6
#define MSR_UNCORE_PMC7			0x3b7

#define MSR_UNCORE_PERFEVTSEL0		0x3c0
#define MSR_UNCORE_PERFEVTSEL1		0x3c1
#define MSR_UNCORE_PERFEVTSEL2		0x3c2
#define MSR_UNCORE_PERFEVTSEL3		0x3c3
#define MSR_UNCORE_PERFEVTSEL4		0x3c4
#define MSR_UNCORE_PERFEVTSEL5		0x3c5
#define MSR_UNCORE_PERFEVTSEL6		0x3c6
#define MSR_UNCORE_PERFEVTSEL7		0x3c7

#define MSR_UNC_CBO_0_PERFEVTSEL0	0x700
#define MSR_UNC_CBO_0_PERFEVTSEL1	0x701
/* sel2-7 aren't actually defined... pass thru anyway */
#define MSR_UNC_CBO_0_PERFEVTSEL2	0x702
#define MSR_UNC_CBO_0_PERFEVTSEL3	0x703
#define MSR_UNC_CBO_0_PERFEVTSEL4	0x704
#define MSR_UNC_CBO_0_PERFEVTSEL5	0x705
#define MSR_UNC_CBO_0_PERFEVTSEL6	0x706
#define MSR_UNC_CBO_0_PERFEVTSEL7	0x707


#define CARRY_FLAG    1
#define PARITY_FLAG   4
#define ADJUST_FLAG   0x10
#define ZERO_FLAG     0x40
#define SIGN_FLAG     0x80

#define CPUID_VMX_BIT 5
#define IA32E_MODE_ACTIVE_BIT 0x400
#define CR0_TASK_SWITCHED_FLAG 8

//Some processor based control bits (MSR IA32_VMX_PROCBASED_CTLS and IA32_VMX_TRUE_PROCBASED_CTLS)
#define CPU_BASED_VIRTUAL_INTR_PENDING  0x00000004
#define CPU_BASED_USE_TSC_OFFSETING     0x00000008
#define CPU_BASED_HLT_EXITING           0x00000080
#define CPU_BASED_INVDPG_EXITING        0x00000200
#define CPU_BASED_MWAIT_EXITING         0x00000400
#define CPU_BASED_RDPMC_EXITING         0x00000800
#define CPU_BASED_RDTSC_EXITING         0x00001000
#define CPU_BASED_CR3_LOAD_EXITING      0x00000000
#define CPU_BASED_CR3_STORE_EXITING     0x00010000
#define CPU_BASED_CR8_LOAD_EXITING      0x00080000
#define CPU_BASED_CR8_STORE_EXITING     0x00100000
#define CPU_BASED_TPR_SHADOW            0x00200000
#define CPU_BASED_NMI_WINDOW_EXITING    0x00400000
#define CPU_BASED_MOV_DR_EXITING        0x00800000
#define CPU_BASED_UNCOND_IO_EXITING     0x01000000
#define CPU_BASED_ACTIVATE_IO_BITMAP    0x02000000
#define CPU_BASED_MONITOR_TRAP_FLAG     0x08000000
#define CPU_BASED_ACTIVATE_MSR_BITMAP   0x10000000
#define CPU_BASED_MONITOR_EXITING       0x20000000
#define CPU_BASED_PAUSE_EXITING         0x40000000
#define CPU_BASED_ACTIVATE_SECONDARY    0x80000000

//Some secondary processor based control bits (MSR IA32_VMX_PROCBASED_CTLS2)
#define CPU2_BASED_VIRTUALIZE_APIC    0x00000001
#define CPU2_BASED_ENABLE_EPT         0x00000002
#define CPU2_BASED_DESCR_TABLE_EXITING 0x00000004
#define CPU2_BASED_ENABLE_RDTSCP      0x00000008
#define CPU2_BASED_VIRTUALIZE_X2APIC  0x00000010
#define CPU2_BASED_ENABLE_VPID        0x00000020
#define CPU2_BASED_WBINVD_EXITING     0x00000040
#define CPU2_BASED_UNRESTRICTED_GUEST 0x00000080
#define CPU2_BASED_APIC_REG_VIRT      0x00000100
#define CPU2_BASED_VIRTUAL_INTR_DELIV 0x00000200
#define CPU2_BASED_PAUSE_LOOP_EXITING 0x00000400
#define CPU2_BASED_RDRAND_EXITING     0x00000800
#define CPU2_BASED_ENABLE_INVPCID     0x00001000
#define CPU2_BASED_ENABLE_VMFUNC      0x00002000
#define CPU2_BASED_VMCS_SHADOW        0x00004000
#define CPU2_BASED_RDSEED_EXITING     0x00010000
#define CPU2_BASED_EPT_VIOLATION      0x00040000
#define CPU2_BASED_ENABLE_XSAVES      0x00100000

//Some vm exit control bits
#define VMEXIT_CONTROL_SAVE_DEBUG       0x00000004
#define VMEXIT_CONTROL_HOST_ADDR_SPACE  0x00000200
#define VMEXIT_CONTROL_LOAD_PERF_GLOBAL 0x00001000
#define VMEXIT_CONTROL_ACK_INTR_ONEXIT  0x00008000
#define VMEXIT_CONTROL_SAVE_IA32_PAT    0x00040000
#define VMEXIT_CONTROL_LOAD_IA32_PAT    0x00080000
#define VMEXIT_CONTROL_SAVE_IA32_EFER   0x00100000
#define VMEXIT_CONTROL_LOAD_IA32_EFER   0x00200000
#define VMEXIT_CONTROL_SAVE_PREEMPT_TIMER 0x00400000

//Some vm exit control bits
#define VMENTRY_CONTROL_LOAD_DEBUG       0x00000004
#define VMENTRY_CONTROL_IA32E_MODE_GUEST 0x00000200
#define VMENTRY_CONTROL_LOAD_PERF_GLOBAL 0x00002000

//Event injections constants
#define INJECT_INTR_TYPE_EXTERNAL_INTR 0
#define INJECT_INTR_TYPE_RESERVED 1
#define INJECT_INTR_TYPE_NMI 2
#define INJECT_INTR_TYPE_HARDWARE_EXC 3
#define INJECT_INTR_TYPE_SOFTWARE_INTR 4
#define INJECT_INTR_TYPE_PRIV_SOFTWARE_EXC 5
#define INJECT_INTR_TYPE_SOFTWARE_EXC 6
#define INJECT_INTR_TYPE_OTHER 7

//X86 interrupt vectors
#define X86_DIVIDE_BY_ZERO 0
#define X86_DEBUG 1
#define X86_NMI 2
#define X86_BREAKPOINT 3
#define X86_OVERFLOW 4
#define X86_BOUND 5
#define X86_INVALID_OPCODE 6
#define X86_DEVICE_NOT_AVAIL 7
#define X86_DOUBLE_FAULT 8
#define X86_COPROC_SEG_OVERRUN 9
#define X86_INVALID_TSS 10
#define X86_SEG_NOT_PRESENT 11
#define X86_STACK_FAULT 12
#define X86_GENERAL_PROTECTION 13
#define X86_PAGE_FAULT 14
#define X86_FLOATING_POINT 16
#define X86_ALIGNMENT_CHECK 17
#define X86_MACHINE_CHECK 18
#define X86_SIMD 19
#define X86_VIRTUALIZATION 20

#define LO32(x) (x & 0xffffffff)
#define SET_LO32(x, y) (x = (x & 0xffffffff00000000LL) | y)

typedef struct _msrstore_entry {
   uint32_t msr;
   uint32_t unused;
   uint64_t value;
} msrstore_entry;

typedef struct _msrloadstore {
   unsigned mls_n;
   msrstore_entry *mls_p;
} msrloadstore;

//allocate this struct at end of host stack space
typedef struct _VmxStruct {
   //all registers except rsp are from guest, rsp is 
   //from HOST_RSP vmcs since these will be populated 
   //by the vm exit handler
   uint64_t r15;
   uint64_t r14;
   uint64_t r13;
   uint64_t r12;
   uint64_t r11;
   uint64_t r10;
   uint64_t r9;
   uint64_t r8;
   uint64_t rdi;
   uint64_t rsi;
   uint64_t rbp;
   uint64_t rsp;
   uint64_t rbx;
   uint64_t rdx;
   uint64_t rcx;
   uint64_t rax;
   //we set HOST_RSP to point to the vmxmon_region pointer below
   //then push all registers as first instruction of vm exit handler
   uint8_t *host_stack;
   uint8_t *vmxon_region;
   uint8_t *vmcs_guest_region;
   uint8_t *io_bitmap_a_region;
   uint8_t *io_bitmap_b_region;
   uint8_t *virtual_apic_page;   
   unsigned max_saved_msrs;
   msrloadstore vmexit_store_msr, vmexit_load_msr, vmentry_load_msr;
   uint32_t procNum;
   uint32_t failed;
   uint64_t cr2;
} VmxStruct;

void vmexitCallback(VmxStruct *vmx);

typedef struct _Segment {
  uint16_t sel;
  uint16_t attr;
  uint32_t limit;
  uint64_t base;
} Segment;

#pragma pack(push, 1)

typedef struct _Descriptor {
  uint16_t limit15;
  uint16_t base15;
  uint8_t base23;
  uint16_t attr;  //also contains 4 limit bits
  uint8_t base31;
} Descriptor;

#define ATTR_TYPE_ACCESSED 1
#define ATTR_SYSTEM 0x10
#define ATTR_PRESENT 0x80
#define ATTR_IA_32E 0x2000
#define ATTR_GRANULARITY 0x8000
#define ATTR_UNUSABLE 0x10000

#pragma pack(pop)

#endif

