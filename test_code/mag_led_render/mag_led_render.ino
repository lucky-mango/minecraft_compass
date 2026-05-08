#include <QMC5883LCompass.h>
#include <Adafruit_NeoPixel.h>

// ─────────────────────────────────────────
// LED SETUP
// ─────────────────────────────────────────
#define LED_PIN     9
#define LED_COUNT   56
#define BRIGHTNESS  20

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// ─────────────────────────────────────────
// COLOR DEFINITIONS
// ─────────────────────────────────────────
#define RED      strip.Color(255, 0,   0)
// #define DARK_RED strip.Color(201, 24,  40)
#define DARK_RED strip.Color(255, 0,   0)
#define WHITE    strip.Color(255, 255, 255)
#define OFF      0

// ─────────────────────────────────────────
// LED STATE STRUCT
// ─────────────────────────────────────────
struct LEDState {
    int index;
    uint32_t color;
};

// ─────────────────────────────────────────
// PAGE DEFINITIONS
// ─────────────────────────────────────────
LEDState page0[] = {
    {10,  RED},
    {22,  RED},
    {33,  RED},
    {34,  WHITE},
    {32,  WHITE},
    {45,  WHITE}
};

LEDState page1[] = {
    {9,   RED},
    {23,  RED},
    {22,  RED},
    {33,  RED},
    {34,  WHITE},
    {32,  WHITE},
    {45,  WHITE}
};

LEDState page2[] = {
    {8,   RED},
    {9,   RED},
    {22,  RED},
    {23,  RED},
    {33,  RED},
    {34,  WHITE},
    {32,  WHITE},
    {45,  WHITE},
    {44,  WHITE}
};

LEDState page3[] = {
    {33,  RED},
    {32,  DARK_RED},
    {23,  RED},
    {24,  DARK_RED},
    {8,   RED},
    {7,   DARK_RED},
    {34,  WHITE},
    {44,  WHITE}
};

LEDState page4[] = {
    {33,  RED},
    {32,  DARK_RED},
    {25,  DARK_RED},
    {24,  RED},
    {23,  RED},
    {34,  WHITE},
    {44,  WHITE},
    {43,  WHITE}
};

LEDState page5[] = {
    {23,  RED},
    {24,  RED},
    {25,  RED},
    {26,  DARK_RED},
    {33,  RED},
    {32,  DARK_RED},
    {34,  WHITE},
    {43,  WHITE},
    {44,  WHITE}
};

LEDState page6[] = {
    {26,  RED},
    {25,  RED},
    {24,  RED},
    {31,  DARK_RED},
    {32,  RED},
    {33,  RED},
    {22,  WHITE},
    {34,  WHITE},
    {35,  WHITE},
    {45,  WHITE}
};

LEDState page7[] = {
    {29,  RED},
    {30,  RED},
    {31,  RED},
    {32,  RED},
    {33,  RED},
    {22,  WHITE},
    {34,  WHITE},
    {35,  WHITE},
    {45,  WHITE}
};

LEDState page8[] = {
    {33,  RED},
    {32,  RED},
    {47,  RED},
    {48,  RED},
    {46,  DARK_RED},
    {20,  WHITE},
    {21,  WHITE},
    {34,  WHITE}
};

LEDState page9[] = {
    {33,  RED},
    {32,  RED},
    {46,  RED},
    {47,  RED},
    {48,  DARK_RED},
    {21,  WHITE},
    {20,  WHITE},
    {34,  WHITE},
    {22,  WHITE}
};

LEDState page10[] = {
    {33,  RED},
    {32,  RED},
    {47,  RED},
    {46,  DARK_RED},
    {50,  DARK_RED},
    {22,  WHITE},
    {21,  WHITE},
    {34,  WHITE}
};

LEDState page11[] = {
    {33,  RED},
    {46,  RED},
    {50,  RED},
    {45,  DARK_RED},
    {51,  DARK_RED},
    {21,  WHITE},
    {22,  WHITE},
    {34,  WHITE},
    {32,  WHITE}
};

LEDState page12[] = {
    {22,  WHITE},
    {32,  WHITE},
    {34,  WHITE},
    {33,  RED},
    {45,  RED},
    {52,  DARK_RED}
};

LEDState page13[] = {
    {22,  WHITE},
    {32,  WHITE},
    {34,  WHITE},
    {33,  RED},
    {45,  DARK_RED},
    {44,  RED},
    {53,  RED}
};

LEDState page14[] = {
    {33,  RED},
    {34,  RED},
    {43,  RED},
    {44,  DARK_RED},
    {55,  RED},
    {54,  DARK_RED},
    {32,  WHITE},
    {23,  WHITE}
};

LEDState page15[] = {
    {33,  RED},
    {34,  RED},
    {35,  DARK_RED},
    {43,  RED},
    {44,  DARK_RED},
    {42,  RED},
    {55,  DARK_RED},
    {32,  WHITE},
    {23,  WHITE},
    {24,  WHITE}
};

LEDState page16[] = {
    {33,  RED},
    {34,  RED},
    {35,  DARK_RED},
    {43,  RED},
    {44,  DARK_RED},
    {42,  RED},
    {41,  RED},
    {32,  WHITE},
    {23,  WHITE},
    {24,  WHITE}
};

LEDState page17[] = {
    {33,  RED},
    {34,  RED},
    {35,  RED},
    {43,  DARK_RED},
    {42,  RED},
    {41,  RED},
    {22,  WHITE},
    {32,  WHITE},
    {31,  WHITE},
    {45,  WHITE}
};

LEDState page18[] = {
    {33,  RED},
    {34,  RED},
    {35,  RED},
    {36,  RED},
    {37,  RED},
    {38,  DARK_RED},
    {22,  WHITE},
    {32,  WHITE},
    {31,  WHITE},
    {45,  WHITE}
};

LEDState page19[] = {
    {33,  RED},
    {34,  RED},
    {35,  DARK_RED},
    {20,  RED},
    {19,  RED},
    {18,  RED},
    {22,  WHITE},
    {32,  WHITE},
    {31,  WHITE},
    {45,  WHITE}
};

LEDState page20[] = {
    {33,  RED},
    {34,  DARK_RED},
    {21,  RED},
    {20,  RED},
    {19,  RED},
    {18,  RED},
    {32,  WHITE},
    {46,  WHITE},
    {47,  WHITE}
};

LEDState page21[] = {
    {33,  RED},
    {34,  DARK_RED},
    {21,  RED},
    {20,  RED},
    {19,  DARK_RED},
    {13,  RED},
    {32,  WHITE},
    {46,  WHITE},
    {47,  WHITE}
};

LEDState page22[] = {
    {33,  RED},
    {34,  DARK_RED},
    {21,  RED},
    {20,  RED},
    {12,  RED},
    {13,  RED},
    {32,  WHITE},
    {46,  WHITE},
    {47,  WHITE}
};

LEDState page23[] = {
    {12,  RED},
    {11,  RED},
    {21,  RED},
    {22,  RED},
    {33,  RED},
    {32,  WHITE},
    {46,  WHITE},
    {45,  WHITE},
    {34,  WHITE}
};

LEDState page24[] = {
    {11,  RED},
    {21,  RED},
    {22,  RED},
    {33,  RED},
    {32,  WHITE},
    {45,  WHITE},
    {34,  WHITE}
};

// ─────────────────────────────────────────
// PAGE REGISTRY
// ─────────────────────────────────────────
LEDState* pages[] = {
    page0,  page1,  page2,  page3,  page4,
    page5,  page6,  page7,  page8,  page9,
    page10, page11, page12, page13, page14,
    page15, page16, page17, page18, page19,
    page20, page21, page22, page23, page24
};

int pageSizes[] = {
    sizeof(page0)  / sizeof(page0[0]),
    sizeof(page1)  / sizeof(page1[0]),
    sizeof(page2)  / sizeof(page2[0]),
    sizeof(page3)  / sizeof(page3[0]),
    sizeof(page4)  / sizeof(page4[0]),
    sizeof(page5)  / sizeof(page5[0]),
    sizeof(page6)  / sizeof(page6[0]),
    sizeof(page7)  / sizeof(page7[0]),
    sizeof(page8)  / sizeof(page8[0]),
    sizeof(page9)  / sizeof(page9[0]),
    sizeof(page10) / sizeof(page10[0]),
    sizeof(page11) / sizeof(page11[0]),
    sizeof(page12) / sizeof(page12[0]),
    sizeof(page13) / sizeof(page13[0]),
    sizeof(page14) / sizeof(page14[0]),
    sizeof(page15) / sizeof(page15[0]),
    sizeof(page16) / sizeof(page16[0]),
    sizeof(page17) / sizeof(page17[0]),
    sizeof(page18) / sizeof(page18[0]),
    sizeof(page19) / sizeof(page19[0]),
    sizeof(page20) / sizeof(page20[0]),
    sizeof(page21) / sizeof(page21[0]),
    sizeof(page22) / sizeof(page22[0]),
    sizeof(page23) / sizeof(page23[0]),
    sizeof(page24) / sizeof(page24[0]),
};

// ─────────────────────────────────────────
// SHOW PAGE FUNCTION
// ─────────────────────────────────────────
void showPage(int pageIndex) {

    for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, OFF);
    }

    LEDState* page = pages[pageIndex];
    int size = pageSizes[pageIndex];

    for (int i = 0; i < size; i++) {
        strip.setPixelColor(page[i].index, page[i].color);
    }

    strip.show();
}

// ─────────────────────────────────────────
// HEADING TO PAGE
// 360° / 25 pages = 14.4° per page
// Page 0 centered on North (0°)
// ─────────────────────────────────────────
int headingToPage(float heading) {

    // shift by half-page width
    heading += 7.2;

    // wrap around
    if (heading >= 360.0)
        heading -= 360.0;

    int page = (int)(heading / 14.4);

    // safety clamp
    if (page > 24) page = 24;
    if (page < 0)  page = 0;

    return page;
}

// ─────────────────────────────────────────
// COMPASS
// ─────────────────────────────────────────
QMC5883LCompass compass;

int lastPage = -1;
float PAGE_WIDTH = 14.4;
float HYSTERESIS = 0.0; // degrees

// ─────────────────────────────────────────
// SETUP
// ─────────────────────────────────────────
void setup() {

    Serial.begin(115200);

    strip.begin();
    strip.setBrightness(BRIGHTNESS);
    strip.show();

    compass.init();

    compass.setCalibrationOffsets(-279.00, 2503.00, 1727.00);
    compass.setCalibrationScales(1.16, 0.79, 1.14);


    delay(100);

    Serial.println("Compass ready");
}

// ─────────────────────────────────────────
// LOOP
// ─────────────────────────────────────────
void loop() {

    compass.read();

    int x = compass.getX();
    int y = compass.getY();

    float heading = atan2((float)y, (float)x) * 180.0 / PI;

    // reverse direction
    heading = 360.0 - heading;

    if (heading < 0)
        heading += 360.0;

    if (heading >= 360.0)
        heading -= 360.0;

    int page;

    // first run
    if (lastPage == -1) {

        page = headingToPage(heading);

    } else {

        page = lastPage;

        // center of current page
        float center = lastPage * PAGE_WIDTH;

        // compensate for centered north
        center -= 7.2;

        if (center < 0)
            center += 360.0;

        // signed shortest angular difference
        float diff = heading - center;

        if (diff > 180) diff -= 360;
        if (diff < -180) diff += 360;

        // hysteresis thresholds
        if (diff > (PAGE_WIDTH / 2 + HYSTERESIS)) {

            page = (lastPage + 1) % 25;

        } else if (diff < -(PAGE_WIDTH / 2 + HYSTERESIS)) {

            page = (lastPage - 1 + 25) % 25;
        }
    }

    // redraw only if page changed
    if (page != lastPage) {

        showPage(page);

        lastPage = page;

        Serial.print("Heading: ");
        Serial.print((int)heading);
        Serial.print((char)176);

        Serial.print("  Page: ");
        Serial.println(page);
    }

    delay(50);
}