#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

#define TCA_ADDR 0x70
#define VL53_ADDR 0x29

Adafruit_VL53L0X sensor = Adafruit_VL53L0X();

void tcaSelect(uint8_t channel) {
    if (channel > 7) return;
    Wire.beginTransmission(TCA_ADDR);
    Wire.write(1 << channel);
    Wire.endTransmission();
    delay(100);
}

bool initSensor(uint8_t channel) {
    tcaSelect(channel);
    delay(100);
    return sensor.begin(VL53_ADDR);
}

int readSensor(uint8_t channel) {
    VL53L0X_RangingMeasurementData_t measure;
    tcaSelect(channel);
    sensor.rangingTest(&measure, false);
    if (measure.RangeStatus != 4) {
        return measure.RangeMilliMeter;
    }
    return -1;
}

void setup() {
    Wire.begin();
    Serial.begin(9600);
    lcd.begin(20, 2);
    lcd.clear();
    lcd.print("Init Sensoren...");

    bool s1_ok = initSensor(0);
    bool s2_ok = initSensor(1);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("S1: ");
    lcd.print(s1_ok ? "OK   " : "FEHLT");
    lcd.setCursor(0, 1);
    lcd.print("S2: ");
    lcd.print(s2_ok ? "OK   " : "FEHLT");

    delay(2000);
    lcd.clear();
}

void loop() {
    int d1 = readSensor(0);
    int d2 = readSensor(1);

    Serial.print("S1: ");
    Serial.print(d1);
    Serial.print(" mm | S2: ");
    Serial.print(d2);
    Serial.println(" mm");

    lcd.setCursor(0, 0);
    lcd.print("S1: ");
    if (d1 >= 0) lcd.print(d1);
    else lcd.print("---");
    lcd.print(" mm     ");

    lcd.setCursor(0, 1);
    lcd.print("S2: ");
    if (d2 >= 0) lcd.print(d2);
    else lcd.print("---");
    lcd.print(" mm     ");

    delay(500);
}