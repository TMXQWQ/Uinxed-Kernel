/*
 *
 *      cpu.h
 *      cpu related operation header file
 *
 *      2024/8/21 By MicroFish
 *      Based on GPL-3.0 open source agreement
 *      Copyright © 2020 ViudiraTech, based on the GPLv3 agreement.
 *
 */

#ifndef INCLUDE_CPU_H_
#define INCLUDE_CPU_H_

#include "stdint.h"

/* Vendor information strings from various CPUs */
#define CPUID_VENDOR_AMD           "AuthenticAMD"
#define CPUID_VENDOR_AMD_OLD       "AMDisbetter!"
#define CPUID_VENDOR_INTEL         "GenuineIntel"
#define CPUID_VENDOR_VIA           "VIA VIA VIA "
#define CPUID_VENDOR_TRANSMETA     "GenuineTMx86"
#define CPUID_VENDOR_TRANSMETA_OLD "TransmetaCPU"
#define CPUID_VENDOR_CYRIX         "CyrixInstead"
#define CPUID_VENDOR_CENTAUR       "CentaurHauls"
#define CPUID_VENDOR_NEXGEN        "NexGenDriven"
#define CPUID_VENDOR_UMC           "UMC UMC UMC "
#define CPUID_VENDOR_SIS           "SiS SiS SiS "
#define CPUID_VENDOR_NSC           "Geode by NSC"
#define CPUID_VENDOR_RISE          "RiseRiseRise"
#define CPUID_VENDOR_VORTEX        "Vortex86 SoC"
#define CPUID_VENDOR_AO486         "MiSTer AO486"
#define CPUID_VENDOR_AO486_OLD     "GenuineAO486"
#define CPUID_VENDOR_ZHAOXIN       "  Shanghai  "
#define CPUID_VENDOR_HYGON         "HygonGenuine"
#define CPUID_VENDOR_ELBRUS        "E2K MACHINE "

/* Manufacturer information from various virtual devices */
#define CPUID_VENDOR_QEMU          "TCGTCGTCGTCG"
#define CPUID_VENDOR_KVM           " KVMKVMKVM  "
#define CPUID_VENDOR_VMWARE        "VMwareVMware"
#define CPUID_VENDOR_VIRTUALBOX    "VBoxVBoxVBox"
#define CPUID_VENDOR_XEN           "XenVMMXenVMM"
#define CPUID_VENDOR_HYPERV        "Microsoft Hv"
#define CPUID_VENDOR_PARALLELS     " prl hyperv "
#define CPUID_VENDOR_PARALLELS_ALT " lrpepyh vr "
#define CPUID_VENDOR_BHYVE         "bhyve bhyve "
#define CPUID_VENDOR_QNX           " QNXQVMBSQG "

typedef enum {
    CPUID_FEAT_ECX_SSE3       = 1 << 0,
    CPUID_FEAT_ECX_PCLMUL     = 1 << 1,
    CPUID_FEAT_ECX_DTES64     = 1 << 2,
    CPUID_FEAT_ECX_MONITOR    = 1 << 3,
    CPUID_FEAT_ECX_DS_CPL     = 1 << 4,
    CPUID_FEAT_ECX_VMX        = 1 << 5,
    CPUID_FEAT_ECX_SMX        = 1 << 6,
    CPUID_FEAT_ECX_EST        = 1 << 7,
    CPUID_FEAT_ECX_TM2        = 1 << 8,
    CPUID_FEAT_ECX_SSSE3      = 1 << 9,
    CPUID_FEAT_ECX_CID        = 1 << 10,
    CPUID_FEAT_ECX_SDBG       = 1 << 11,
    CPUID_FEAT_ECX_FMA        = 1 << 12,
    CPUID_FEAT_ECX_CX16       = 1 << 13,
    CPUID_FEAT_ECX_XTPR       = 1 << 14,
    CPUID_FEAT_ECX_PDCM       = 1 << 15,
    CPUID_FEAT_ECX_PCID       = 1 << 17,
    CPUID_FEAT_ECX_DCA        = 1 << 18,
    CPUID_FEAT_ECX_SSE4_1     = 1 << 19,
    CPUID_FEAT_ECX_SSE4_2     = 1 << 20,
    CPUID_FEAT_ECX_X2APIC     = 1 << 21,
    CPUID_FEAT_ECX_MOVBE      = 1 << 22,
    CPUID_FEAT_ECX_POPCNT     = 1 << 23,
    CPUID_FEAT_ECX_TSC        = 1 << 24,
    CPUID_FEAT_ECX_AES        = 1 << 25,
    CPUID_FEAT_ECX_XSAVE      = 1 << 26,
    CPUID_FEAT_ECX_OSXSAVE    = 1 << 27,
    CPUID_FEAT_ECX_AVX        = 1 << 28,
    CPUID_FEAT_ECX_F16C       = 1 << 29,
    CPUID_FEAT_ECX_RDRAND     = 1 << 30,
    CPUID_FEAT_ECX_HYPERVISOR = 1 << 31,

    CPUID_FEAT_EDX_FPU     = 1 << 0,
    CPUID_FEAT_EDX_VME     = 1 << 1,
    CPUID_FEAT_EDX_DE      = 1 << 2,
    CPUID_FEAT_EDX_PSE     = 1 << 3,
    CPUID_FEAT_EDX_TSC     = 1 << 4,
    CPUID_FEAT_EDX_MSR     = 1 << 5,
    CPUID_FEAT_EDX_PAE     = 1 << 6,
    CPUID_FEAT_EDX_MCE     = 1 << 7,
    CPUID_FEAT_EDX_CX8     = 1 << 8,
    CPUID_FEAT_EDX_APIC    = 1 << 9,
    CPUID_FEAT_EDX_SEP     = 1 << 11,
    CPUID_FEAT_EDX_MTRR    = 1 << 12,
    CPUID_FEAT_EDX_PGE     = 1 << 13,
    CPUID_FEAT_EDX_MCA     = 1 << 14,
    CPUID_FEAT_EDX_CMOV    = 1 << 15,
    CPUID_FEAT_EDX_PAT     = 1 << 16,
    CPUID_FEAT_EDX_PSE36   = 1 << 17,
    CPUID_FEAT_EDX_PSN     = 1 << 18,
    CPUID_FEAT_EDX_CLFLUSH = 1 << 19,
    CPUID_FEAT_EDX_DS      = 1 << 21,
    CPUID_FEAT_EDX_ACPI    = 1 << 22,
    CPUID_FEAT_EDX_MMX     = 1 << 23,
    CPUID_FEAT_EDX_FXSR    = 1 << 24,
    CPUID_FEAT_EDX_SSE     = 1 << 25,
    CPUID_FEAT_EDX_SSE2    = 1 << 26,
    CPUID_FEAT_EDX_SS      = 1 << 27,
    CPUID_FEAT_EDX_HTT     = 1 << 28,
    CPUID_FEAT_EDX_TM      = 1 << 29,
    CPUID_FEAT_EDX_IA64    = 1 << 30,
    CPUID_FEAT_EDX_PBE     = 1 << 31
} cpuid_feature_t;

typedef enum {
    CPUID_GETVENDORSTRING = 0,
    CPUID_GETFEATURES     = 1,
    CPUID_GETTLB          = 2,
    CPUID_GETSERIAL       = 3,

    CPUID_INTELEXTENDED        = 0x80000000,
    CPUID_INTELFEATURES        = 0x80000001,
    CPUID_INTELBRANDSTRING     = 0x80000002,
    CPUID_INTELBRANDSTRINGMORE = 0x80000003,
    CPUID_INTELBRANDSTRINGEND  = 0x80000004,
} cpuid_requests_t;

/* Get CPUID */
void cpuid(uint32_t code, uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx);

/* Get CPU manufacturer name */
char *get_vendor_name(void);

/* Get the CPU model name */
char *get_model_name(void);

/* Get the CPU physical address size */
uint32_t get_cpu_phys_bits(void);

/* Get CPU virtual address size */
uint32_t get_cpu_virt_bits(void);

/* Check CPU supports NX/XD */
int cpu_supports_nx(void);

/* Check CPU supports 64bit */
int cpu_support_64bit(void);

/* Check CPU supports MMX */
int cpu_support_mmx(void);

/* Check CPU supports SSE */
int cpu_support_sse(void);

/* Check CPU supports SSE2 */
int cpu_support_sse2(void);

/* Check CPU supports SSE3 */
int cpu_support_sse3(void);

/* Check CPU supports SSSE3 */
int cpu_support_ssse3(void);

/* Check CPU supports SSE4.1 */
int cpu_support_sse41(void);

/* Check CPU supports SSE4.2 */
int cpu_support_sse42(void);

/* Check CPU supports SSE4a (AMD-specific) */
int cpu_support_sse4a(void);

/* Check CPU supports XOP (AMD-specific) */
int cpu_support_xop(void);

/* Check CPU supports FMA4 (AMD-specific) */
int cpu_support_fma4(void);

/* Check CPU supports CVT16 */
int cpu_support_cvt16(void);

/* Check CPU supports AVX */
int cpu_support_avx(void);

/* Check CPU supports AVX2 */
int cpu_support_avx2(void);

/* Get core frequency */
uint32_t get_core_freq(void);

/* Get tsc frequency */
uint32_t get_tsc_freq(void);

/* Get bus frequency */
uint32_t get_bus_freq(void);

#endif // INCLUDE_CPU_H_
