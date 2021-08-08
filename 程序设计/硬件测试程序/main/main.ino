
#include "Arduino.h"
#include <FastLED.h>            // 此示例程序需要使用FastLED库
#define NUM_LEDS 20       // LED灯珠数量
#define LED_DT 5                // Arduino输出控制信号引脚
#define TOUCH 4                 // 触摸引脚
#define LED_TYPE WS2812B         // LED灯带型号
#define COLOR_ORDER GRB         // RGB灯珠中红色、绿色、蓝色LED的排列顺序
uint8_t max_bright = 200;       // LED亮度控制变量，可使用数值为 0 ～ 255， 数值越大则光带亮度越高
CRGB leds[NUM_LEDS];            // 建立光带leds
int mode_ = 0;// 0 关 1 一档 2 二档 3 三档
ICACHE_RAM_ATTR void onChange(){
  mode_++;
  if(mode_ == 4)mode_ = 0;
  switch(mode_){
    case 0:{
      FastLED.setBrightness(50);
      fill_solid(leds,NUM_LEDS,CRGB(0,0,0));
      FastLED.show();
      break;
    }
    case 1:{
      FastLED.setBrightness(50);
      fill_solid(leds,NUM_LEDS,CRGB(255,255,255));
      FastLED.show();
      break;
    }
    case 2:{
      FastLED.setBrightness(150);
      fill_solid(leds,NUM_LEDS,CRGB(255,255,255));
      FastLED.show();
      break;
    }
    case 3:{
      FastLED.setBrightness(200);
      fill_solid(leds,NUM_LEDS,CRGB(255,255,255));
      FastLED.show();
      break;
    }
  }
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);  // 初始化光带
  // put your main code here, to run repeatedly:
  FastLED.setBrightness(max_bright);                            // 设置光带亮度
  attachInterrupt(digitalPinToInterrupt(TOUCH) , onChange, CHANGE);
  
  
}

void loop() {
delay(2000);
}
