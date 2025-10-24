/*
 * sla_header.c
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 

#include <stdio.h>
#include <stdint.h>

extern unsigned int _start_SWAP;
extern unsigned int _SLA_Size_SWAP;

#define ltob(x)				(((x) >> 24) | (((x)&0x00FF0000) >> 8) | (((x)&0x0000FF00) << 8) | (((x)&0x000000FF) << 24))

#define rom_ver_a1			0x01000000
#define magic_h				0x48495357
#define magic_l				0x45444744


typedef struct {
	struct {
		uint32_t high;
		uint32_t low;
	} header_id;
	uint32_t format_version;
	uint32_t application_image_start_address;
	uint32_t application_image_signature_offset;
	uint32_t *executable_start_address;
	uint32_t argument_size;
	uint32_t application_version;
} sla_header;



__attribute__((section(".sb_sla_header"))) __attribute__((__used__))
const sla_header sb_header =
{
	.header_id = {
		.high      = ltob(magic_h),
		.low       = ltob(magic_l),
	},
	.format_version                     = ltob(rom_ver_a1),
	.application_image_start_address    = ltob(0x10000000),
	.application_image_signature_offset = (int)&_SLA_Size_SWAP, // Trick to get constant defined at link time
//	.application_image_signature_offset = ltob(0x00000610),
	.executable_start_address           = (uint32_t *)&_start_SWAP,
//	.executable_start_address           = (uint32_t *)ltob(0x10000554),
	.argument_size                      = 0,
	.application_version                = ltob(0x01000000),
};

