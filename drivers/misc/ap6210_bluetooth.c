#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <asm/io.h>
#include <asm/mach/arch.h>
#include <mach/hardware.h>
#include <mach/gpio.h>
#include <linux/gpio_keys.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <mach/hardware.h>
#include <linux/gpio.h>

static void bluetooth_on(void)
{
    gpio_direction_output(45, 0);
    gpio_request_one(104, GPIOF_OUT_INIT_LOW, "gpio104");
    ndelay(80000);
    gpio_direction_output(45, 1);
    gpio_request_one(104, GPIOF_OUT_INIT_HIGH, "gpio104");
    ndelay(80000);
}

/*static void bluetooth_off(void)
{
    gpio_direction_output(45, 0);
    gpio_request_one(104, GPIOF_OUT_INIT_LOW, "gpio104");
}*/

static int bluetooth_init(void)
{
    bluetooth_on();
    printk("power on of bluetooth device!!");

    return 0;
}

/*static void bluetooth_exit(void)
{
    bluetooth_off();
}*/

subsys_initcall(bluetooth_init);
//module_init(bluetooth_init);
//module_exit(bluetooth_exit);

MODULE_LICENSE("Dual BSD/GPL");
