
OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
SEARCH_DIR(.)

/* Memory Spaces Definitions */
MEMORY
{
/*
  sla      (rx)  : ORIGIN = 0x10000000, LENGTH = 0x00000200
  rom      (rx)  : ORIGIN = 0x10000200, LENGTH = 0x0003fe00
  ram      (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00014000
*/
  rom      (rx)  : ORIGIN = 0x10000000, LENGTH = 0x00040000
  ram      (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00014000
}

ENTRY(Reset_Handler)
PROVIDE( _start_SWAP = (((Reset_Handler) >> 24) | (((Reset_Handler) & 0x00FF0000) >> 8) | (((Reset_Handler) & 0x0000FF00) << 8) | ((Reset_Handler) << 24)));
PROVIDE_HIDDEN( _SLA_Size = _endimage - __end_header );
PROVIDE( _SLA_Size_SWAP = (((_SLA_Size) >> 24) | (((_SLA_Size) & 0x00FF0000) >> 8) | (((_SLA_Size) & 0x0000FF00) << 8) | ((_SLA_Size) << 24)));


STACK_SIZE = DEFINED(STACK_SIZE) ? STACK_SIZE : DEFINED(__stack_size__) ? __stack_size__ : 0x00001000;

SECTIONS
{
/*
    .sb_sla_header : ALIGN (4)
    {
        FILL(0xFF)
        KEEP (*(.sb_sla_header))
        __end_header = .;
        . = ALIGN(512);
    } > sla
*/
    .text :
    {
        . = ALIGN(4);
        _sfixed = .;
        _svectors = .;

        KEEP(*(.vectors))
	__evectors = .;
	__end__ = .;

        *(.text)
        *(.glue_7t)
        *(.glue_7)

	*(.init)
	*(.fini)
        *(.rodata)

        . = ALIGN(4);
        _etext = .;
    } > rom

    . = ALIGN(4);
    .data :
    {
        _srelocate = ALIGN(., 4);

        *(.data .data.*);
        *(.flashprog*)

        _erelocate = ALIGN(., 4);
    } > ram AT>rom

    .sb_sla_trailer : 
    {
        KEEP(*(.sb_sla_trailer))
        FILL(0xDEADC0DE);
        LONG(0xDEADC0DE);
        . = ALIGN(16);
    }  > rom
    _endimage = LOADADDR(.sb_sla_trailer)+SIZEOF(.sb_sla_trailer);

    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        _sbss = . ;
        _szero = .;

        *(.bss .bss.*)

        . = ALIGN(4);
        _ebss = . ;
        _ezero = .;
    } > ram

    .stack (NOLOAD):
    {
        . = ALIGN(8);
        _sstack = .;

        . = . + STACK_SIZE;

        . = ALIGN(8);
        _estack = .;
    } > ram

    . = ALIGN(4);
    _end = . ;
}
