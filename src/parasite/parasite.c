#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "parasite.h"

#include "uart.h"
#include "gpio.h"
#include "timer.h"
#include "motor_driver.h"

#include "app/env.h"
#include "app/console.h"
#include "app/ad_collector.h"
#include "app/sensor.h"
#include "app/app_manager.h"

#include "fs/fs.h"
#include "driver/iam20680ht.h"
#include "driver/i2c.h"

typedef void (*test_func)(void);

void app_hw_init(intptr_t exinf)
{
	driver_gpio_init();
	driver_timer_init();
}

void main_task(intptr_t exinf)
{
	if (driver_gpio_get_boot_strap() == 0) {
//	if(0) {
		console_init();
	}
	else {
		driver_gpio_setup_led();
	}

	driver_gpio_led_on();

	console_puts("\n\nStart Parasite AI mini4wd\n");

	analog_collector_init();
	console_puts("Activated: Analog Frontend\n");

	driver_md_init();
	console_puts("Activated: Motor Driver\n");

	act_tsk(CONSLE_TASK);

	act_tsk(FS_TASK);

	driver_i2c_init();
	act_tsk(SENSOR_TASK);

	while(1) {
		dly_tsk(5);
	}
}


void fs_task(intptr_t exinf)
{
	int ret = fs_init();
	console_printf("Activated: File System. %08x\n", ret);

	env_init();

	while(1) {
		dly_tsk(100);
	}
}

void sensor_task(intptr_t exinf)
{
	SensorValue val;
	int ret = appManager_init();
	console_printf("Activated: App Manager. %d\n", ret);
	if (ret) while(1);

	ret = sensor_probe();
	console_printf("Activated: Sensors. %d\n", ret);
	if (ret) while(1);

	App app = appManagerGetCurrentApp();
	if (app) app();

	// if no application, exit this task;
	return;
}

void signal_proc_task(intptr_t exinf)
{
	while(1) {
		dly_tsk(100);
	}
}



/*
 *  CPU Exception handler
 */
volatile uint32_t * p=NULL;
void cpuexc_handler(void *p_excinf)
{
	ID		tskid;

	p = (uint32_t *)p_excinf;

	if (sns_ctx() != true) {
	}
	if (sns_dpn() != true) {
	}
	if (xsns_xpn(p_excinf)) {
		ext_ker();
		assert(0);
	}

	iget_tid(&tskid);
	iras_tex(tskid, 0x8000U);
}

