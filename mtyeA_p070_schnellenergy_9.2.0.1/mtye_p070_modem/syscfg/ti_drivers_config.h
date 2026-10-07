/*
 *  ======== ti_drivers_config.h ========
 *  Configured TI-Drivers module declarations
 *
 *  The macros defines herein are intended for use by applications which
 *  directly include this header. These macros should NOT be hard coded or
 *  copied into library source code.
 *
 *  Symbols declared as const are intended for use with libraries.
 *  Library source code must extern the correct symbol--which is resolved
 *  when the application is linked.
 *
 *  DO NOT EDIT - This file is generated for the CC1352R1_LAUNCHXL
 *  by the SysConfig tool.
 */
#ifndef ti_drivers_config_h
#define ti_drivers_config_h

#define CONFIG_SYSCONFIG_PREVIEW

#define CONFIG_CC1352R1_LAUNCHXL
#ifndef DeviceFamily_CC13X2
#define DeviceFamily_CC13X2
#endif

#include <ti/devices/DeviceFamily.h>

#include <stdint.h>

/* support C++ sources */
#ifdef __cplusplus
extern "C" {
#endif


/*
 *  ======== CCFG ========
 */


/*
 *  ======== ADC ========
 */

/* DIO23 */
extern const uint_least8_t              currentAdcDIO23_CONST;
#define currentAdcDIO23                 0
/* DIO24 */
extern const uint_least8_t              volatgeAdcDIO24_CONST;
#define volatgeAdcDIO24                 1
/* DIO28 */
extern const uint_least8_t              panelVolageAdcDIO28_CONST;
#define panelVolageAdcDIO28             2
/* DIO29 */
extern const uint_least8_t              batterySenseAdcDIO29_CONST;
#define batterySenseAdcDIO29            3
#define CONFIG_TI_DRIVERS_ADC_COUNT     4


/*
 *  ======== AESECB ========
 */

extern const uint_least8_t                  CONFIG_AESECB_0_CONST;
#define CONFIG_AESECB_0                     0
#define CONFIG_TI_DRIVERS_AESECB_COUNT      1


/*
 *  ======== GPIO ========
 */
/* Owned by currentAdcDIO23 as  */
extern const uint_least8_t CONFIG_GPIO_currentAdcDIO23_AIN_CONST;
#define CONFIG_GPIO_currentAdcDIO23_AIN 23

/* Owned by volatgeAdcDIO24 as  */
extern const uint_least8_t CONFIG_GPIO_volatgeAdcDIO24_AIN_CONST;
#define CONFIG_GPIO_volatgeAdcDIO24_AIN 24

/* Owned by panelVolageAdcDIO28 as  */
extern const uint_least8_t CONFIG_GPIO_panelVolageAdcDIO28_AIN_CONST;
#define CONFIG_GPIO_panelVolageAdcDIO28_AIN 28

/* Owned by batterySenseAdcDIO29 as  */
extern const uint_least8_t CONFIG_GPIO_batterySenseAdcDIO29_AIN_CONST;
#define CONFIG_GPIO_batterySenseAdcDIO29_AIN 29

extern const uint_least8_t CONFIG_CC1190_PA_EN_DIO3_CONST;
#define CONFIG_CC1190_PA_EN_DIO3 3

extern const uint_least8_t CONFIG_CC1190_LNA_EN_DIO4_CONST;
#define CONFIG_CC1190_LNA_EN_DIO4 4

extern const uint_least8_t CONFIG_CC1190_HGM_DIO5_CONST;
#define CONFIG_CC1190_HGM_DIO5 5

extern const uint_least8_t checkingDIO17_CONST;
#define checkingDIO17 17

/* Owned by CONFIG_SPI_0 as  */
extern const uint_least8_t CONFIG_GPIO_SPI_0_SCLK_CONST;
#define CONFIG_GPIO_SPI_0_SCLK 20

/* Owned by CONFIG_SPI_0 as  */
extern const uint_least8_t CONFIG_GPIO_SPI_0_MISO_CONST;
#define CONFIG_GPIO_SPI_0_MISO 21

/* Owned by CONFIG_SPI_0 as  */
extern const uint_least8_t CONFIG_GPIO_SPI_0_MOSI_CONST;
#define CONFIG_GPIO_SPI_0_MOSI 19

/* Owned by CONFIG_UART_0 as  */
extern const uint_least8_t CONFIG_PIN_2_CONST;
#define CONFIG_PIN_2 13

/* Owned by CONFIG_UART_0 as  */
extern const uint_least8_t CONFIG_PIN_3_CONST;
#define CONFIG_PIN_3 12

/* Owned by CONFIG_NVS_SPI_0 as  */
extern const uint_least8_t CONFIG_GPIO_0_CONST;
#define CONFIG_GPIO_0 22

/* The range of pins available on this device */
extern const uint_least8_t GPIO_pinLowerBound;
extern const uint_least8_t GPIO_pinUpperBound;

/* LEDs are active high */
#define CONFIG_GPIO_LED_ON  (1)
#define CONFIG_GPIO_LED_OFF (0)

#define CONFIG_LED_ON  (CONFIG_GPIO_LED_ON)
#define CONFIG_LED_OFF (CONFIG_GPIO_LED_OFF)


/*
 *  ======== NVS ========
 */

/*
 *  MOSI: DIO19
 *  MISO: DIO21
 *  SCLK: DIO20
 *  SS: undefined
 */
extern const uint_least8_t              CONFIG_NVSEXTERNAL_CONST;
#define CONFIG_NVSEXTERNAL              0
#define CONFIG_TI_DRIVERS_NVS_COUNT     1




/*
 *  ======== SPI ========
 */

/*
 *  MOSI: DIO19
 *  MISO: DIO21
 *  SCLK: DIO20
 */
extern const uint_least8_t              CONFIG_SPI_0_CONST;
#define CONFIG_SPI_0                    0
#define CONFIG_TI_DRIVERS_SPI_COUNT     1


/*
 *  ======== UART ========
 */

/*
 *  TX: DIO13
 *  RX: DIO12
 *  XDS110 UART
 */
extern const uint_least8_t              CONFIG_UART_0_CONST;
#define CONFIG_UART_0                   0
#define CONFIG_TI_DRIVERS_UART_COUNT    1


/*
 *  ======== Board_init ========
 *  Perform all required TI-Drivers initialization
 *
 *  This function should be called once at a point before any use of
 *  TI-Drivers.
 */
extern void Board_init(void);

/*
 *  ======== Board_initGeneral ========
 *  (deprecated)
 *
 *  Board_initGeneral() is defined purely for backward compatibility.
 *
 *  All new code should use Board_init() to do any required TI-Drivers
 *  initialization _and_ use <Driver>_init() for only where specific drivers
 *  are explicitly referenced by the application.  <Driver>_init() functions
 *  are idempotent.
 */
#define Board_initGeneral Board_init

#ifdef __cplusplus
}
#endif

#endif /* include guard */
