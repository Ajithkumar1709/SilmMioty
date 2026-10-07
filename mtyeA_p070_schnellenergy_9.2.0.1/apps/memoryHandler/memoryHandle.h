#ifndef MEMORY_HANDLE_H
#define MEMORY_HANDLE_H

#include "../common.h"

void memoryHandle_firstBoot(void);
void memoryHandle_readConfigStoreWithBackup(void);
int memoryHandle_writeConfigStoreWithBackup(void);   /* 0 = OK, -1 = flash write failed */
storedDatas_t *memoryHandle_getConfigStore(void);

extern storedDatas_t storedDatas;
#endif // MEMORY_HANDLE_H
