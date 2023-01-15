#include <stdbool.h>
#include <stddef.h>
#include <printf.h>
#include "os_applAPI.h"

#include "main.h"
#include "bme280.h"
#include "log.h"

#define LOG_LEVEL LOG_DEBUG
#define LOG_MODULE_NAME "sensor"
#define CYCLE_PERIOD 2000  // 2s


bool sensor_init(void)
{
    BME280_Reset();
    HAL_Delay(10);
    BME280_SetMode(BME280_MODE_SLEEP);
    HAL_Delay(10);
    BME280_SetStandby(BME280_STBY_20ms);  // not used in forced mode
    BME280_SetFilter(BME280_FILTER_OFF);
    BME280_SetOSRSH(BME280_OSRS_H_x1);
    BME280_SetOSRST(BME280_OSRS_T_x1);
    BME280_SetOSRSP(BME280_OSRS_P_x1);
    BME280_Read_Calibration();

    return true;
}


void sensor_loop(void)
{
    task_open();

    while(true) {
        int32_t ut, up, uh;
        uint32_t t, p, h;

        BME280_SetMode(BME280_MODE_FORCED);
        BME280_Read_UTPH(&ut, &up, &uh);

        t = BME280_CalcT(ut);
        p = BME280_CalcP(up) >> 8;
        h = BME280_CalcH(uh);

#if ENABLE_LOGS
        /* uint8_t td, tf; */
        /* uint16_t pd, pf; */
        /* uint16_t hd, hf; */
        char buffer[80];

        snprintf(
            buffer,
            sizeof(buffer),
            "t=%d.%ddegC, p=%d.%dhPa, h=%d.%d%%RH",
            t / 100, t % 100, p / 100, p % 100, h / 1024, h % 1024
        );
        log_debug(buffer);
#endif

        task_wait(CYCLE_PERIOD);
    }

    task_close();
}
