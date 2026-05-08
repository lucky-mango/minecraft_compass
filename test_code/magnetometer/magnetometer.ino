#include <QMC5883LCompass.h>

QMC5883LCompass compass;

void setup() {
    Serial.begin(115200);
    compass.init();
    compass.setCalibrationOffsets(-122.00, -67.00, 119.00);
    compass.setCalibrationScales(0.95, 0.99, 1.06);
    delay(100);
    Serial.println("QMC5883L Heading (0-359)");
    Serial.println("Rotate sensor flat on table");
    Serial.println("─────────────────────────");
}

void loop() {
    compass.read();

    int x = compass.getX();
    int y = compass.getY();

    // calculate heading from X and Y only
    float heading = atan2((float)y, (float)x) * 180.0 / PI;

    // normalize to 0-359
    if (heading < 0)    heading += 360.0;
    if (heading >= 360) heading -= 360.0;

    // cast to int for clean 0-359 output
    int headingInt = (int)heading;

    // cardinal direction
    String direction;
    if      (headingInt < 22)  direction = "N";
    else if (headingInt < 67)  direction = "NE";
    else if (headingInt < 112) direction = "E";
    else if (headingInt < 157) direction = "SE";
    else if (headingInt < 202) direction = "S";
    else if (headingInt < 247) direction = "SW";
    else if (headingInt < 292) direction = "W";
    else if (headingInt < 337) direction = "NW";
    else                       direction = "N";

    Serial.print("Heading: ");
    Serial.print(headingInt);
    Serial.print((char)176);
    Serial.print("  ");
    Serial.println(direction);

    delay(100);
}