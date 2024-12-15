struct Reading {
    // DHT11
    float temperature;    // Temperature in °C
    float humidity;       // Humidity in %

    // BMP280
    float pressure;       // Atmospheric pressure in hPa

    // BH1750
    float light; // Light intensity in lux

    // Air Quality Data: MQ135, MQ4, MQ7, MQ2
    float CO2; // CO2 concentration in ppm (from MQ135)
    float methane; // Methane concentration in ppm (from MQ4)
    float CO;  // CO concentration in ppm (from MQ7)
    float smoke; // Smoke concentration in ppm (from MQ2)
    
    // PM2.5
    float pm25;  // PM2.5 concentration in µg/m³

    // Calculated Data
    float absoluteHumidity;  // Absolute humidity in g/m³
    float dewPoint;          // Dew point temperature in °C
    int airQualityIndex;     // AQI
}