// Led Bridge Project ()
/* 
개발자 : INSU CHOI (Nifskor)

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

void setup() {
  // start the strip and blank it out
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  strip.begin();
  strip.show();
  for(int i =0; i<=NUM_LEDS; i++){
  //strip.setPixelColor(i, 255,139,39); //2700k
  strip.setPixelColor(i, 255,100,100); //2700k
  //https://www.google.com/search?q=2700k++rgb&sxsrf=APq-WBspGEg4joCkWrXunQdkTakaw-iKaA:1644592012750&tbm=isch&source=iu&ictx=1&vet=1&fir=QnYxb3zusyq93M%252CTcttBnMs2MqKKM%252C_%253Bg8_9Bn4j1DnV0M%252CF7OrCUk0_fcJeM%252C_%253BvGLOjm7tu6-mrM%252CF7OrCUk0_fcJeM%252C_%253BR1RuhaJD_RF3gM%252CCQ31vUdaFsusIM%252C_%253BiddY8-ZO5vzQlM%252CCQ31vUdaFsusIM%252C_%253BYGqGJxvvL3XT1M%252CnarVLsOfoZQrjM%252C_%253BIPw7Ybmf9hJVEM%252CSvCYHPOJl-m3jM%252C_%253BRZdIQl8xeZ8qeM%252C5J7YHTGZT-5D9M%252C_%253BrGRDGWfS9yp-hM%252Ci5W1dO8liatZbM%252C_%253BbUKJAGzuV3Le3M%252CV5OHwtspmCuSUM%252C_&usg=AI4_-kTES-3Lb_b-bWYgwgKHaXBymwEDFw&sa=X&ved=2ahUKEwjhr-HV9vf1AhUNDt4KHfxLAPUQ9QF6BAgKEAE#imgrc=QnYxb3zusyq93Mhttps://www.google.com/search?q=2700k++rgb&sxsrf=APq-WBspGEg4joCkWrXunQdkTakaw-iKaA:1644592012750&tbm=isch&source=iu&ictx=1&vet=1&fir=QnYxb3zusyq93M%252CTcttBnMs2MqKKM%252C_%253Bg8_9Bn4j1DnV0M%252CF7OrCUk0_fcJeM%252C_%253BvGLOjm7tu6-mrM%252CF7OrCUk0_fcJeM%252C_%253BR1RuhaJD_RF3gM%252CCQ31vUdaFsusIM%252C_%253BiddY8-ZO5vzQlM%252CCQ31vUdaFsusIM%252C_%253BYGqGJxvvL3XT1M%252CnarVLsOfoZQrjM%252C_%253BIPw7Ybmf9hJVEM%252CSvCYHPOJl-m3jM%252C_%253BRZdIQl8xeZ8qeM%252C5J7YHTGZT-5D9M%252C_%253BrGRDGWfS9yp-hM%252Ci5W1dO8liatZbM%252C_%253BbUKJAGzuV3Le3M%252CV5OHwtspmCuSUM%252C_&usg=AI4_-kTES-3Lb_b-bWYgwgKHaXBymwEDFw&sa=X&ved=2ahUKEwjhr-HV9vf1AhUNDt4KHfxLAPUQ9QF6BAgKEAE#imgrc=QnYxb3zusyq93M
  //color rgb
strip.show();
strip.setBrightness(255);
  }
}

void loop() {
 
  // set pixel to red, delay(1000)
  //for(int i =0; i<=NUM_LEDS; i++){
  //strip.setPixelColor(i, 255, 255, 0);
//strip.show();
  }
  //strip.show();
  //delay(1000);
  // set pixel to off, delay(1000)
  //  for(int j =0; j<=NUM_LEDS; j++){
  //strip.setPixelColor(j, 0, 0, 0);
  //  }
  //strip.show();
  //delay(1000);
