#include "configuration.h"

#if !MESHTASTIC_EXCLUDE_ENVIRONMENTAL_SENSOR

#include "../mesh/generated/meshtastic/telemetry.pb.h"
#include "MS5611Sensor.h"
#include "TelemetrySensor.h"
#include <typeinfo>
MS5611 ms5611(nodeTelemetrySensorsMap[meshtastic_TelemetrySensorType_MS5611].first);
// Konstruktor
MS5611Sensor::MS5611Sensor() : TelemetrySensor(meshtastic_TelemetrySensorType_MS5611, "MS5611") {}

int32_t MS5611Sensor::runOnce()
{
    LOG_INFO("Initing external sensor: %s", sensorName);

    // Inicializálás I2C-n keresztül
    LOG_INFO("MS5611 sensor before begining I2C ADDR: ",nodeTelemetrySensorsMap[meshtastic_TelemetrySensorType_MS5611].first);
    status = ms5611.begin();
    //LOG_INFO("MS5611 sensor found: %s", ms5611.getAddress());
    LOG_INFO("MS5611 sensor begined :)");
    // Tesztmérés hőmérséklettel
    ms5611.read();
    float testTemperature = ms5611.getTemperature();

    if (testTemperature == MS5611_NOT_READ) {
        LOG_ERROR("MS5611 sensor init failure: NOT_READ.");
        initialized = false;
        return DEFAULT_SENSOR_MINIMUM_WAIT_TIME_BETWEEN_READS;
    }

    if (testTemperature == MS5611_ERROR_2) {
        LOG_ERROR("MS5611 sensor init failure: I2C error.");
        initialized = false;
        return DEFAULT_SENSOR_MINIMUM_WAIT_TIME_BETWEEN_READS;
    }

    LOG_INFO("MS5611 sensor init success.");
    initialized = true;

    return initI2CSensor();
}

void MS5611Sensor::setup()
{
    // Az MS5611 speciális beállításokat nem igényel
    LOG_INFO("MS5611 szenzor setup runs.");
}

bool MS5611Sensor::getMetrics(meshtastic_Telemetry *measurement)
{
    LOG_DEBUG("MS5611::getMetrics() indul");
    if (!initialized) {
        LOG_ERROR("MS5611 nincs inicializalva!");
        return false;
    }

    measurement->variant.environment_metrics.has_temperature = true;
    measurement->variant.environment_metrics.has_barometric_pressure = true;
    ms5611.read();
    // Mérési értékek lekérdezése
    float temperature = ms5611.getTemperature();
    float pressure = ms5611.getPressure();

    // Hibaellenőrzés
    if (temperature == MS5611_NOT_READ || pressure == MS5611_NOT_READ) {
        LOG_ERROR("MS5611 measure fail: NOT_READ.");
        return false;
    }

    if (temperature == MS5611_ERROR_2 || pressure == MS5611_ERROR_2) {
        LOG_ERROR("MS5611 measure fail: I2C error.");
        return false;
    }

    // Adatok mentése
    measurement->variant.environment_metrics.temperature = temperature;
    measurement->variant.environment_metrics.barometric_pressure = pressure;
    LOG_DEBUG("MS5611::getMetrics() lefutott");
    return true;
}

#endif // !MESHTASTIC_EXCLUDE_ENVIRONMENTAL_SENSOR
