// Led Bridge Project ()
/* 
개발자 : ING's - (Nifskor)

개발 기간 : 2022 / 01 / 27 ~ 진행중 
출력물 파트 출처 : https://www.thingiverse.com/thing:1639224
간단한 소개 : 본 프로젝트는 싱기버스에서 LED bridge Lamp  출력물 파츠를 이용해 
RGB LED Strip 을 이용하여 스탠드 등을 만들어 보는 프로젝트 이다. 

제작 이유 : 우리집 스탠드 등이 너무 오래되어서 사기엔 아깝고 나만의 스탠드를 만들어 보기위해 

필요한 기능 요구사항들 : 눈에 피로하지않은 독서 모드  
                   , 공부 모드  (집중모드) . 수리 모드 , 빨강, 초록, 파랑 모드 , 취침 모드
   - 취침 모드 : 눈에 피로하지않은 주광색 으로 표시되어지다가 일정 시간이 지나면 자동으로 종료되는 기능 

*/ 
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
//define NeoPixel Pin and Number of LEDs
#define PIN 6
#define NUM_LEDS 59
//create a NeoPixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
int count =0;
void setup() {
  // start the strip and blank it out
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  strip.begin();
  strip.show();
  strip.setBrightness(255);
  for(int i =0; i<=NUM_LEDS; i++){
  //strip.setPixelColor(i, 255,139,39); //2700k
  strip.setPixelColor(i, 255,100,100); //2700k
strip.show();
delay(50);
  }
  for(int j =0; j<=NUM_LEDS; j++){
   strip.setPixelColor(j, 0,0,0); //2700k
   strip.show();
   delay(50);
}
}

void loop() {
  strip.setBrightness(30);
  while(count==0){
    for(int k =0; k<=59; k++){
     strip.setPixelColor(k, 255,139,39); //2700k
   strip.show();
   delay(50);
   count=2;
    }
  }

  }
  
  
