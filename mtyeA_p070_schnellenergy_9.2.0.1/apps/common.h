#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stdbool.h>

/* ---------------- Config store (external W25Q16 flash, 4 KB pages) ---------------- */
#define CONFIG_STORE_PAGE              1     /* 0x1000 */
#define CONFIG_STORE_BACKUP_PAGE       5     /* 0x5000 */
#define CONFIG_STORE_FIRST_BOOT_MAGIC  0x55

/* ---------------- Config defaults ---------------- */
#define MIN_VOLT                       100u  /* V */
#define MIN_POWER                      10u   /* W */
#define PERIODIC_DURATION              900   /* seconds */
#define MAX_PAYLOAD_PER_DAY            100

typedef struct __attribute__((packed)){
uint32_t Minvoltage;
uint32_t Minpower;
uint32_t periodicTime;
uint32_t maxPayload;
uint32_t maxPayloadCounter;
uint32_t currentDay;
uint32_t lampBurnTime;     /* lifetime lamp ON seconds (rbt) */
uint32_t lastFaultStatus;  /* FAULT_* bitmask, bit7/bit11 */
uint8_t firstBoot;
uint8_t checksum;          /* crc8 of the whole struct with checksum = 0 */
uint32_t energyWh;         /* lifetime energy in Wh (wh) */
uint32_t batTh;            /* low-battery threshold mV (shared attribute batTh) */
}storedDatas_t;

#endif // COMMON_H
