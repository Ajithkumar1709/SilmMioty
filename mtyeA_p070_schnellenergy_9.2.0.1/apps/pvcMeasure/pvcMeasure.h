#ifndef PVC_MEASURE_H
#define PVC_MEASURE_H
#include "stdint.h"
typedef struct __attribute__((packed)){
  float voltage;
  float current;
  float power;
  uint16_t batVolt;
  uint16_t panelVolt;   /* panel (solar) voltage (mV), ADC1 with pin 21 HIGH */
  float pf;             /* power factor 0..100 = power / (voltage * current) * 100 */
}pvc_t;

/* elapsedMs = time since the previous pvc_measure() call; added to
 * storedDatas.lampBurnTime when the lamp is ON (power > Minpower). */
extern pvc_t pvc_measure(uint32_t elapsedMs);
/* Battery voltage only (mV), no AC sampling. Used in low-battery mode. */
extern uint16_t pvc_readBatVolt(void);
extern void delay_us(unsigned int us);

#endif
