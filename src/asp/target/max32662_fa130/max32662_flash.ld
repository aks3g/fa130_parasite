ENTRY(_kernel__start)

/* Memory Spaces Definitions */
MEMORY
{
  ROM      (rx)  : ORIGIN = 0x10000000, LENGTH = 0x00040000
  RAM      (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00014000
}

OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm","elf32-littlearm")
OUTPUT_ARCH(arm)

PROVIDE(hardware_init_hook = 0);
PROVIDE(software_init_hook = 0);
PROVIDE(software_term_hook = 0);
STARTUP(start.o)

SECTIONS
{
    .text :
    {
        __text = .;

        KEEP(*(.vector))
        KEEP(*(.vectors))
        KEEP(*(.isr_vector))
        KEEP(*(.reset))
        KEEP(*(.reset.*))

        *(.text*)
        *(.glue_7t)
        *(.glue_7)
    } > ROM

    . = ALIGN(4);
    _etext = .;
    PROVIDE(etext = .);

    .rodata :
    {
        *(.rodata*)
    } > ROM

    . = ALIGN(4);
    __idata_start = .;

    .data : AT(__idata_start)
    {
        __data_start = .;
        *(vtable)
        *(.data*)
    } > RAM

    __idata_end = __idata_start + SIZEOF(.data);
    _edata = .;
    PROVIDE(edata = .);

    . = ALIGN(4);

    .bss :
    {
        __bss_start = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
    } > RAM

    . = ALIGN(4);
    _end = .;
    __bss_end = .;
    PROVIDE(end = .);

    .comment 0 : { *(.comment) }

    .debug          0 : { *(.debug) }
    .line           0 : { *(.line) }
    .debug_srcinfo  0 : { *(.debug_srcinfo) }
    .debug_sfnames  0 : { *(.debug_sfnames) }
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    .debug_info     0 : { *(.debug_info) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }
    .debug_weaknames 0 : { *(.debug_weaknames) }
    .debug_funcnames 0 : { *(.debug_funcnames) }
    .debug_typenames 0 : { *(.debug_typenames) }
    .debug_varnames  0 : { *(.debug_varnames) }
}

