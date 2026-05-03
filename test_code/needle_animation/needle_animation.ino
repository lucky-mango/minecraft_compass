#include <Adafruit_NeoPixel.h>

#define LED_PIN     9
#define LED_COUNT   56
#define BRIGHTNESS  100

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// ─────────────────────────────────────────
// COLOR DEFINITIONS
// ─────────────────────────────────────────
#define RED     strip.Color(255, 0,   0)
#define DARK_RED strip.Color(201,24,40)
#define GREEN   strip.Color(0,   255, 0)
#define BLUE    strip.Color(0,   0,   255)
#define WHITE   strip.Color(255, 255, 255)
#define YELLOW  strip.Color(255, 255, 0)
#define CYAN    strip.Color(0,   255, 255)
#define PURPLE  strip.Color(255, 0,   255)
#define ORANGE  strip.Color(255, 128, 0)
#define OFF     0

// ─────────────────────────────────────────
// LED STATE STRUCT
// ─────────────────────────────────────────
struct LEDState {
    int index;
    uint32_t color;
};

// ─────────────────────────────────────────
// PAGE DEFINITIONS
// add or remove LEDs freely per page
// ─────────────────────────────────────────
LEDState page1[] = {
  	{3,   RED},
    {10,  RED},
    {22,  RED},
    {33,  RED},
    {34,  WHITE},
    {32,  WHITE},
    {45,  WHITE}
};

LEDState page2[] = {
    {5, RED},
    {9,  RED},
    {23,  RED},
    {22,  RED},
    {33,  RED},
    {34,  WHITE},
    {32,  WHITE},
    {45,  WHITE}

};

LEDState page3[] = {
  	{8,   RED},
    {9,   RED},
    {22,   RED},
    {23,   RED},
    {33,   RED},
    {34,  WHITE},
    {32,  WHITE},
    {45,  WHITE},
    {44, WHITE}
};

LEDState page4[] = {
  {33, RED},
  {32, DARK_RED},
  {23, RED},
  {24, DARK_RED},
  {8, RED},
  {7,DARK_RED},
  {34, WHITE},
  {45, WHITE}
};

LEDState page5[] = {
  
};

LEDState page6[] = {
    {5,  RED},
    {15, GREEN},
    {25, BLUE},
};

LEDState page7[] = {
    {0,  RED},
    {1,  GREEN},
    {2,  BLUE},
    {3,  YELLOW},
};

LEDState page8[] = {
    {10, RED},
    {11, GREEN},
    {12, BLUE},
    {23, YELLOW},
    {35, RED},
    {42, GREEN},
};

LEDState page9[] = {
    {5,  RED},
    {15, GREEN},
    {25, BLUE},
    {35, YELLOW},
    {45, RED},
    {55, GREEN},
    {3,  BLUE},
    {13, YELLOW},
};

LEDState page10[] = {
    {0,  RED},
    {1,  GREEN},
    {2,  BLUE},
    {3,  YELLOW},
    {4,  RED},
};

LEDState page11[] = {
    {10, RED},
    {11, GREEN},
    {12, BLUE},
};

LEDState page12[] = {
    {5,  RED},
    {15, GREEN},
    {25, BLUE},
    {35, YELLOW},
};

LEDState page13[] = {
    {0,  RED},
    {1,  GREEN},
    {2,  BLUE},
    {3,  YELLOW},
    {4,  RED},
    {5,  GREEN},
};

LEDState page14[] = {
    {10, RED},
    {11, GREEN},
    {12, BLUE},
    {23, YELLOW},
    {35, RED},
    {42, GREEN},
    {50, BLUE},
};

LEDState page15[] = {
    {5,  RED},
    {15, GREEN},
    {25, BLUE},
    {35, YELLOW},
    {45, RED},
};

LEDState page16[] = {
    {0,  RED},
    {1,  GREEN},
    {2,  BLUE},
    {3,  YELLOW},
    {4,  RED},
    {5,  GREEN},
    {6,  BLUE},
    {7,  YELLOW},
    {8,  RED},
};

LEDState page17[] = {
    {10, RED},
    {11, GREEN},
};

LEDState page18[] = {
    {5,  RED},
    {15, GREEN},
    {25, BLUE},
    {35, YELLOW},
    {45, RED},
    {55, GREEN},
};

LEDState page19[] = {
    {0,  RED},
    {1,  GREEN},
    {2,  BLUE},
};

LEDState page20[] = {
    {10, RED},
    {11, GREEN},
    {12, BLUE},
    {23, YELLOW},
};

LEDState page21[] = {
    {5,  RED},
    {15, GREEN},
    {25, BLUE},
    {35, YELLOW},
    {45, RED},
    {55, GREEN},
    {3,  BLUE},
    {13, YELLOW},
    {23, RED},
};

LEDState page22[] = {
    {0,  RED},
    {1,  GREEN},
    {2,  BLUE},
    {3,  YELLOW},
    {4,  RED},
    {5,  GREEN},
    {6,  BLUE},
};

LEDState page23[] = {
    {10, RED},
    {11, GREEN},
    {12, BLUE},
    {23, YELLOW},
    {35, RED},
};

LEDState page24[] = {
    {5,  RED},
    {15, GREEN},
    {25, BLUE},
    {35, YELLOW},
    {45, RED},
    {55, GREEN},
    {3,  BLUE},
    {13, YELLOW},
};

LEDState page25[] = {
    {5,  RED},
    {15, GREEN},
    {25, BLUE},
    {35, YELLOW},
};

// ─────────────────────────────────────────
// PAGE REGISTRY
// sizeof auto counts LEDs per page
// ─────────────────────────────────────────
LEDState* pages[] = {
    page1,  page2,  page3,  page4,  page5,
    page6,  page7,  page8,  page9,  page10,
    page11, page12, page13, page14, page15,
    page16, page17, page18, page19, page20,
    page21, page22, page23, page24, page25
};

int pageSizes[] = {
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
    sizeof(page21) / sizeof(page21[0]),
    sizeof(page23) / sizeof(page23[0]),
    sizeof(page24) / sizeof(page24[0]),
    sizeof(page25) / sizeof(page25[0]),
};

// ─────────────────────────────────────────
// SHOW PAGE FUNCTION
// ─────────────────────────────────────────
void showPage(int pageIndex) {
    // clear all LEDs
    for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, OFF);
    }

    // set LEDs for this page
    LEDState* page = pages[pageIndex];
    int size = pageSizes[pageIndex];

    for (int i = 0; i < size; i++) {
        strip.setPixelColor(page[i].index, page[i].color);
    }

    strip.show();
}

// ─────────────────────────────────────────
// SETUP & LOOP
// ─────────────────────────────────────────
void setup() {
    strip.begin();
    strip.setBrightness(BRIGHTNESS);
    strip.show();
}

void loop() {
  for(int i =0;i<5;i++){
    //call any page like this
    showPage(i);   // shows page1
    delay(1000);
    };
    // showPage(4);   
    // etc
}

