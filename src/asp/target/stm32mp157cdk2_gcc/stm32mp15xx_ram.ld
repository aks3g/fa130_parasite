MEMORY
{
    VROM (rx) : ORIGIN = 0x00000000, LENGTH = 664
    RMON (rx) : ORIGIN = 0x10000000, LENGTH = 32K
    ROM  (rx) : ORIGIN = 0x10008000, LENGTH = 96K
    RAM  (rwx) : ORIGIN = 0x10020000, LENGTH = 128K
    m_ipc_shm (rwx)  : ORIGIN = 0x10040000, LENGTH = 32K
}

OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm","elf32-littlearm") 
OUTPUT_ARCH(arm)

 /* Symbols needed for OpenAMP to enable rpmsg */
__OPENAMP_region_start__  = ORIGIN(m_ipc_shm);
__OPENAMP_region_length__ = LENGTH(m_ipc_shm);
__OPENAMP_region_end__    = ORIGIN(m_ipc_shm)+LENGTH(m_ipc_shm);

PROVIDE(hardware_init_hook = 0);
PROVIDE(software_init_hook = 0);
PROVIDE(software_term_hook = 0);
STARTUP(start.o)
ENTRY(_kernel__start)

SECTIONS
{
    .text : {
        . = ALIGN(4);
        __text = . ; 
        KEEP(*(.vector))
        *(.text*)
        *(.glue_7)
        *(.glue_7t)
        *(.eh_frame)

        KEEP (*(.init))
        KEEP (*(.fini))

       . = ALIGN(4);
       _etext = .	;

    } > ROM

    .rodata : { 
        . = ALIGN(4);
        *(.rodata*) 
        . = ALIGN(4);
    } > ROM

    .ARM.extab   : { 
    	. = ALIGN(4);
    	*(.ARM.extab* .gnu.linkonce.armextab.*)
        . = ALIGN(4);
    } > ROM

    .ARM : {
      . = ALIGN(4);
      __exidx_start = .;
       *(.ARM.exidx*)
      __exidx_end = .;
      . = ALIGN(4);
    } > ROM

    .preinit_array  : {
      . = ALIGN(4);
      PROVIDE_HIDDEN (__preinit_array_start = .);
      KEEP (*(.preinit_array*))
      PROVIDE_HIDDEN (__preinit_array_end = .);
      . = ALIGN(4);
    } > ROM

    .init_array : {
      . = ALIGN(4);
      PROVIDE_HIDDEN (__init_array_start = .);
      KEEP (*(SORT(.init_array.*)))
      KEEP (*(.init_array*))
      PROVIDE_HIDDEN (__init_array_end = .);
      . = ALIGN(4);
    } > ROM

    .fini_array : {
      . = ALIGN(4);
      PROVIDE_HIDDEN (__fini_array_start = .);
      KEEP (*(SORT(.fini_array.*)))
      KEEP (*(.fini_array*))
      PROVIDE_HIDDEN (__fini_array_end = .);
      . = ALIGN(4);
    } > ROM

    /* Used by the startup to initialize data */
    . = ALIGN(4);
    __idata_start = . ;
    .data   :  AT(__idata_start) 
    {
        __data_start = . ;
        _sdata = .;
        *(vtable)
        *(.data)
        *(.data*)
    } > RAM
    __idata_end = __idata_start + SIZEOF(.data);
    _edata  =  . ;
    PROVIDE (edata = .);
    text_end = ORIGIN(m_text) + LENGTH(m_text);
    . = ALIGN(4);

    .resource_table :
    {
        . = ALIGN(4);
        KEEP (*(.resource_table*))
        . = ALIGN(4);
    } > RAM

    .bss       :
    {
        __bss_start = .	;
        *(.bss*)
        *(COMMON)
      . = ALIGN(32 / 8);
    } > RAM

    ._user_heap_stack :
    {
        . = ALIGN(8);
    } > RAM

    . = ALIGN(32 / 8);
    _end = .		;
    __bss_end = .;
    PROVIDE (end = .)	;

    .comment 0 : { *(.comment) }

    /* Remove information from the compiler libraries */
    /DISCARD/ :
    {
        libc.a ( * )
        libm.a ( * )
        libgcc.a ( * )
    }

  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to 
     the beginning of the section so we begin them at 0.  */

  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }

  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }

  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }

  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }

  /* SGI/MIPS DWARF 2 extensions */
  .debug_weaknames 0 : { *(.debug_weaknames) }
  .debug_funcnames 0 : { *(.debug_funcnames) }
  .debug_typenames 0 : { *(.debug_typenames) }
  .debug_varnames  0 : { *(.debug_varnames) }
}
