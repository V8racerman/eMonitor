#ifndef   ACD_eMonitor
#define   ACD_eMonitor

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class ACDeMonitor {
    public:
      // Constructor
      ACDeMonitor(int adc_resolution, byte neutral_pin, byte live_pin);
      
      // Methods
      double rms_calc(int samples, double reference_voltage, double calib);

    private:

    int _adc_resol;
    byte _neutralpin;
    byte _livepin; 
      
};


#endif
