//made by ali
#ifndef MS5611_SENSOR_H
#define MS5611_SENSOR_H

#include "TelemetrySensor.h"
#include <MS5611.h>

class MS5611Sensor : public TelemetrySensor {
public:
    MS5611Sensor();
    int32_t runOnce() override;
    void setup() override;
    bool getMetrics(meshtastic_Telemetry *measurement) override;
   // MS5611 MS5611(0x77);
private:
    
    bool initialized;
};

#endif // MS5611_SENSOR_H
