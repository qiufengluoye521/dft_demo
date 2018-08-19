//
// Created by 72989 on 2018/8/18.
//

#include "dft_process.h"
#include <math.h>

#define PI      3.1415926f

int16_t const sin_table[100] = { 0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,63,67,71,75,79,83,86,90,94,98,101,105,109,112,116,119,123,126,130,133,137,140,143,147,150,153,156,159,163,166,169,172,175,177,180,183,186,189,191,194,196,199,201,204,206,209,211,213,215,217,219,222,223,225,227,229,231,232,234,236,237,239,240,241,243,244,245,246,247,248,249,250,250,251,252,252,253,253,254,254,254,255,255,255 };

bool dft_process(int32_t *data,uint32_t time_len,int32_t *real,int32_t *img)
{
    uint16_t i,j;
    //float w = 0.0f;
    uint8_t     delta           = 0;
    int32_t     temp_real       = 0;
    int32_t     temp_img        = 0;
    uint16_t    phase           = 0;
    uint16_t    phase_sin_1q    = 0;
    uint16_t    phase_cos_1q    = 0;
    int16_t     sin_c           = 0;
    int16_t     cos_c           = 0;

    /*
     *  sample rate: 4HZ                2*PI                400
     *  resolution : 0.01HZ             0.01*PI/2           1
     *
     * */    
    //w = 0.01*PI/2;
    delta = 1;
    
    for(i = 0;i < 37;i++)
    {
        temp_real   = 0;
        temp_img    = 0;
        for(j = 0;j < time_len;j++)
        {
            phase           = delta*i*j % 400;
            // phase 0~99
            if(phase < 100)
            {
                phase_sin_1q    = (phase % 100);
                sin_c           = sin_table[phase_sin_1q];
                phase_cos_1q    = (99 - phase) % 100;
                cos_c           = sin_table[phase_cos_1q];
                
            } else if (phase < 200)                     // phase 100~199
            {
                phase_sin_1q    = (199 - phase) % 100;
                sin_c           = sin_table[phase_sin_1q];
                phase_cos_1q    = (phase - 100) % 100;
                cos_c           = -sin_table[phase_cos_1q];
            } else if (phase < 300)                     // phase 200~299
            {
                phase_sin_1q    = phase - 200;
                sin_c           = -sin_table[phase_sin_1q];
                phase_cos_1q    = (299 - phase) % 100;
                cos_c           = -sin_table[phase_cos_1q];
            } else                                      // phase 300~399
            {
                phase_sin_1q    = 399 - phase;
                sin_c           = -sin_table[phase_sin_1q];
                phase_cos_1q    = (phase - 300) % 100;
                cos_c           = sin_table[phase_cos_1q];
            }

            temp_real   = temp_real + data[j]*(int32_t)(cos_c);
            temp_img    = temp_img  + data[j]*(int32_t)(sin_c);
        }
        //DEBUG_PRINT("%d\t%d\r\n",temp_real_1,temp_img_1);
        DEBUG_PRINT("%d\t%d\r\n",temp_real,temp_img);
    }
    
 

}
