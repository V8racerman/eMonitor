 
/* ************************************************************ */
/* *** eMonitor FUNCTION DEFINITION *************************** */
/* ************************************************************ */

#include "acd_eMonitor.h"

ACDeMonitor:: ACDeMonitor(int adc_resolution, byte neutral_pin, byte live_pin) {
  _adc_resol = adc_resolution;
  _neutralpin = neutral_pin;
  _livepin = live_pin;
}
 
 double ACDeMonitor::rms_calc(int samples, double v_ref, double calibr) {

  int sensor_1;
  int sensor_2;
  int sensor;
  int counter;
  double total_squared = 0.0;
  double rms, mean;
  double cal;
  double amps;
  
  cal = v_ref*calibr/((double)_adc_resol);
  for (counter = 0; counter < samples; counter++) {
    sensor_1 = analogRead(_neutralpin);
    sensor_2 = analogRead(_livepin);
    sensor = sensor_2 - sensor_1;
    amps = cal*sensor;
    total_squared = total_squared + amps * amps;
   }
  mean = total_squared / samples;
  rms = sqrt(mean);
  return rms;
 }
