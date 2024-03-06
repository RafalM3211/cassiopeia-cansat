#include "sensirion_common.h"
#include "sgp30.h"


String getCo2(){
      s16 err = 0;
    u16 tvoc_ppb, co2_eq_ppm;
    err = sgp_measure_iaq_blocking_read(&tvoc_ppb, &co2_eq_ppm);
    if (err != STATUS_OK) {
        SerialUSB.println("error reading IAQ values\n");
        return "E";
    }

    return String(co2_eq_ppm);
}

void initCo2Sensor(){
  s16 err;
  u16 scaled_ethanol_signal, scaled_h2_signal;
  while (sgp_probe() != STATUS_OK) {
    SerialUSB.println("SGP failed");
  }

  err = sgp_measure_signals_blocking_read(&scaled_ethanol_signal,
                                            &scaled_h2_signal);
    if (err == STATUS_OK) {
        SerialUSB.println("get ram signal!");
    } else {
        SerialUSB.println("error reading signals");
    }
    err = sgp_iaq_init();
}




