#include "application.h"
#include "neopixel/neopixel.h" // use for Build IDE
// #include "neopixel.h" // use for local build

SYSTEM_MODE(AUTOMATIC);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D3
#define PIXEL_COUNT 100
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// Prototypes for local build, ok to leave in for Build IDE
void rainbow(uint8_t wait);
uint32_t Wheel(byte WheelPos);

bool success = Particle.function("stranger", demogorgon);

void setup()
{
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
void loop()
{
  //demogorgon("");
}
  
  
int demogorgon(String text) {
    Particle.publish("message", text);
  
    dark();
  
    uint32_t red = strip.Color(255,0,0);
    uint32_t orange = strip.Color(255,127,0);
    uint32_t yellow = strip.Color(255,255,0);
    uint32_t green = strip.Color(0,255,0);
    uint32_t skyblue = strip.Color(0,255,255);
    uint32_t blue = strip.Color(0,0,255);
    uint32_t violet = strip.Color(127,0,255);
    uint32_t pink = strip.Color(255,0,127);
    uint32_t softwhite = strip.Color(224,224,224);

    uint32_t pallette[] = {red, orange, yellow, green, skyblue, blue, violet, pink, softwhite};

    int charDelay = 750;

    text = text.toUpperCase();
  
    for (int i = 0; i < text.length(); i++) {
            char myChar = text.charAt(i);
            if (myChar == 32) {
                delay(charDelay * 1.5);
            }
            
            int charPixel = getCharAddress(text.charAt(i));
            if (charPixel == 0) {
                continue;
            }

            strip.setPixelColor(charPixel, pallette[random(0,8)]);
            strip.show();
            delay(charDelay);

            strip.setPixelColor(charPixel,0);
            strip.show();
            delay(charDelay / 2);
        }
  
    dark();
    delay(2000);
    return 200;
}

int getCharAddress(char inputChar) {

    int alphabet[] = {
    //a
    53,
    //b
    55,
    //c
    58,
    //d
    60,
    //e
    63,
    //f
    65,
    //g
    68,
    //h
    71,
    //i
    42,
    //j
    40,
    //k
    38,
    //l
    37,
    //m
    35,
    //n
    33,
    //o
    31,
    //p
    29,
    //q
    27,
    //r
    4,
    //s
    7,
    //t
    9,
    //u
    10,
    //v
    11,
    //w
    13,
    //x
    15,
    //y
    17,
    //z
    19
    };
    if (inputChar < 65 || inputChar > 90) {
        return 0;
    }

    int pixelAddress = alphabet[inputChar - 65];
      
    return pixelAddress;
}
  
  
void dark() {
    for (int j= 0; j < strip.numPixels(); j++) {
    strip.setPixelColor(j, 0, 0, 0);
    }
    strip.show();
}
