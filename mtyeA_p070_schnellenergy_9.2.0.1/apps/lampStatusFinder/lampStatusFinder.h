/* ---------------- lamp_monitor.h ---------------- */
#ifndef LAMP_MONITOR_H
#define LAMP_MONITOR_H

#include <stdint.h>
#include <stdbool.h>

/* ---------------- Feature enable/disable (compile-time only) ---------------- */
#define FEATURE_BATVOLT_MONITOR   1   /* set to 0 to disable batVolt logic */
#define FEATURE_FAULT_MONITOR     1   /* set to 0 to disable fault logic */
#define DEBOUNCE_LAMPSTATE     1


/* Lamp-fault debounce: number of consecutive occurrences to set / clear */
#define LAMP_FAULT_DEBOUNCE_COUNT   3u




#define BATVOLT_LOW_THRESHOLD   3000u   /* default batTh (mV); runtime value = storedDatas.batTh */
#define BATVOLT_LOW_HYSTERESIS   100u


/* Lamp states (also the "lmp" telemetry value) */
#define LAMP_OFF      0
#define LAMP_ON       1
#define LAMP_FAULT    2
#define LAMP_UNKNOWN  3

/* Packet types = "pkt" telemetry value sent to the server.
 * PKT_NONE (no packet this cycle) is never sent; it's not 0 because live is 0. */
#define PKT_LIVE        0
#define PKT_LAMP_ON     1
#define PKT_LAMP_OFF    2
#define PKT_FAULT_SET   4
#define PKT_FAULT_CLEAR 5
#define PKT_BOOTON      7   /* event_power_return */
#define PKT_NONE        0xFF

/* rpcHandler jsonextract() return codes */
#define ON_DEMAND    4
#define SEND_CONFIG_ATTRIBUTES 5
#define OTA_UPDATE   6

/* fault bitmask ("fc" / "fd" telemetry values) */
#define FAULT_NONE      0x00000000u
#define FAULT_LAMP_BIT  0x00000080u   /* bit7  = noLoadFault -> 128  */
#define FAULT_BAT_BIT   0x00000800u   /* bit11 = low battery -> 2048 */




typedef struct __attribute__((packed)) {
    uint8_t  pktType;       /* internal PKT_* */
    uint8_t  lmpState;      /* lmp */
    uint32_t voltage;       /* rv (V) */
    uint32_t current;       /* ri (mA) */
    uint32_t power;         /* rw (W) */
    uint16_t batVolt;       /* batVolt (mV) */
    uint32_t faultChanged;  /* fc: bits set (PKT_FAULT_SET) or cleared (PKT_FAULT_CLEAR) */
    uint32_t faultStatus;   /* fd: currently active faults */
    uint32_t utc;           /* ts */
    uint16_t panelVolt;     /* panelVolt (mV) */
    uint32_t burnTime;      /* rbt: lifetime lamp ON seconds */
    uint8_t  pf;            /* pf: power factor 0..100 */
    uint32_t energyWh;      /* wh: lifetime energy in Wh */
    /* sig is not stored: publish.c reads the current signal at send time */
} serveTransmitPkt_t;


void lampMonitor_init(void);
void lampMonitor_requestBootOnPkt(void);
/* True while a lamp fault set/clear is being debounced (use a short sleep) */
bool lampMonitor_isFaultDebouncing(void);

uint8_t lampMonitor_evaluateState(uint32_t voltage, uint32_t power, uint32_t minV, uint32_t minW);
serveTransmitPkt_t lampMonitor_isPacketSendRequired(uint32_t voltage,
                                                     uint32_t power,
                                                     uint32_t batVolt,
                                                     bool periodicStatus,
                                                     uint32_t minW,
                                                     uint32_t minV,
                                                     uint32_t batTh);

#endif /* LAMP_MONITOR_H */


