#ifndef __DFT_PROCESS_H_
#define __DFT_PROCESS_H_

#include <stdint.h>
#include <stdbool.h>

#if 1
#define DEBUG_PRINT(...) printf(__VA_ARGS__)
#else
#define DEBUG_PRINT(...) do {} while (0)
#endif

bool dft_process(int32_t *data,uint32_t time_len,int32_t *real,int32_t *img);

#endif //__DFT_PROCESS_H_
