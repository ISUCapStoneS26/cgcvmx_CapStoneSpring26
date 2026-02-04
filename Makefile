# Module Name
KMOD = cgcvmx64

SRCS = cgcvmx64.c vmx64.S

EXPORT_SYMS=YES
DEBUG_FLAGS=-g3

.include <bsd.kmod.mk>
