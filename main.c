#include <stdio.h>
#include "dft_process.h"

int32_t test_data_after_iir[] = {
        0,1330,2408,3036,3112,2651,1783,722,-281,-993,-1250,-993,-281,722,1783,2651,3112,3036,2408,1330,0,-1331,-2409,-3037,-3113,-2652,-1784,-723,280,992,1249,992,280,-723,-1784,-2652,-3113,-3037,-2409,-1331,-1,1330,2408,3036,3112,2651,1783,722,-281,-993,-1250,-993,-281,722,1783,2651,3112,3036,2408,1330,0,-1331,-2409,-3037,-3113,-2652,-1784,-723,280,992,1249,992,280,-723,-1784,-2652,-3113,-3037,-2409,-1331,-1,1330,2408,3036,3112,2651,1783,722,-281,-993,-1250,-993,-281,722,1783,2651,3112,3036,2408,1330,0,-1331,-2409,-3037,-3113,-2652,-1784,-723,280,992,1249,992,280,-723,-1784,-2652,-3113,-3037,-2409,-1331,
};
int32_t dft_out_real[37] = {0};
int32_t dft_out_imag[37] = {0};

int main()
{
    uint32_t i = 0;
    uint32_t data_len = 0;
    //printf("start dft process!\n");
    //fft_data_init();

    data_len = sizeof(test_data_after_iir) / sizeof(test_data_after_iir[0]);
    for(i = 0;i< data_len;i++) {
        if(i == data_len - 1) {
            dft_process(test_data_after_iir,data_len,dft_out_real,dft_out_imag);
            //fft_square_bw_v2(test_data_after_iir[i],true,true);
        } else {
            //fft_square_bw_v2(test_data_after_iir[i],false,false);
        }

    }

    return 0;
}