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
/*       ------  헤더 선언 부분 --------------------*/
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
//define NeoPixel Pin and Number of LEDs
#define PIN 6
#define NUM_LEDS 59
//create a NeoPixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
/*   아래 부분 수동변수 파트  */ 
int count =0;
int resis = A0; // 가변저항 

/*       ------  헤더 선언 부분 --------------------*/

void setup() {
  // start the strip and blank it out
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  /*  초기 모드 시작 */ 
  strip.begin();
  strip.show();
  strip.setBrightness(255); //초기밝기255
  /* 초기 시리얼 통신 설정  */
  Serial.begin(9600);
  /*   초기 시리얼 통신 설정 끝 */  
  /* 초기 부팅후 환영모드 */ 
  for(int i =0; i<=NUM_LEDS; i++){
  //strip.setPixelColor(i, 255,139,39); //2700k
  strip.setPixelColor(i, 255,100,100); //2700k
strip.show();
delay(40);
  }
  for(int j =0; j<=NUM_LEDS; j++){
   strip.setPixelColor(j, 0,0,0); //2700k
   strip.show();
   delay(40);
}
/* attachInterrupt */ 
 // attachInterrupt(digitalPinToInterrupt(resis), sleepingmode,CHANGE);
} // 셋업 부분 마지막 
/*  void loop 시작 부분 */ 
void loop() {
  /* 선택 옵션 넣은후 작동되게 case문 작성 */ 

  /*  아날로그값 리딩 파트 */  // 평균치 잡아서 -> 튀는값오류를 잡아야할듯 
        for(int k =0; k<=59; k++){
      //strip.setPixelColor(k, 255,139,39); //2700k
      strip.setPixelColor(k, 255,255,255); //2700k
      ledbright();
     
     
      
        }

  /* -----------------------------*/
  
  }
  void ledbright(){
     int  val = analogRead(resis)/4; // 나누기 4로 max값 255로 나오게  
    if(val == 0){
       strip.setBrightness(0); 
       strip.show();
     }
    if( val >=0 && val<=10 ) {
         strip.setBrightness(10); 
       strip.show();
      }
       if( val >=10 && val<=20 ) {
         strip.setBrightness(20); 
       strip.show();
      }
      if( val >=20 && val<=30 ) {
         strip.setBrightness(30); 
       strip.show();
      }
       if( val >=30 && val<=40 ) {
         strip.setBrightness(40); 
       strip.show();
      }
      if( val >=40 && val<=50 ) {
         strip.setBrightness(50); 
       strip.show();
      }
       if( val >=50 && val<=60 ) {
         strip.setBrightness(60); 
       strip.show();
      }
       if( val >=60 && val<=70 ) {
         strip.setBrightness(70); 
       strip.show();
      }
        if( val >=70 && val<=80 ) {
         strip.setBrightness(80); 
       strip.show();
      }
       if( val >=80 && val<=90 ) {
         strip.setBrightness(90); 
       strip.show();
      }
      if( val >=90 && val<=100 ) {
         strip.setBrightness(100); 
       strip.show();
      }
      if( val >=100 && val<=110 ) {
         strip.setBrightness(110); 
       strip.show();
      }
       if( val >=110 && val<=120 ) {
         strip.setBrightness(120); 
       strip.show();
      }
       if( val >=120 && val<=130 ) {
         strip.setBrightness(130); 
       strip.show();
      }
       if( val >=130 && val<=140 ) {
         strip.setBrightness(140); 
       strip.show();
      }
      if( val >=140 && val<=150 ) {
         strip.setBrightness(150); 
       strip.show();
      }
      if( val >=150 && val<=160 ) {
         strip.setBrightness(160); 
       strip.show();
      }
      if( val >=160 && val<=170 ) {
         strip.setBrightness(170); 
       strip.show();
      }
       if( val >=170 && val<=180 ) {
         strip.setBrightness(180); 
       strip.show();
      }
        if( val >=180 && val<=190 ) {
         strip.setBrightness(190); 
       strip.show();
      }
       if( val >=190 && val<=200 ) {
         strip.setBrightness(200); 
       strip.show();
      }
        if( val >=200 && val<=210 ) {
         strip.setBrightness(210); 
       strip.show();
      }
         if( val >=210 && val<=220 ) {
         strip.setBrightness(220); 
       strip.show();
      }
        if( val >=220 && val<=230 ) {
         strip.setBrightness(230); 
       strip.show();
      }
      if( val >=230 && val<=240 ) {
         strip.setBrightness(240); 
       strip.show();
      }
      if( val >=240 && val<=255 ) {
         strip.setBrightness(255); 
       strip.show();
      }
       Serial.println(val);
  }//ledbright end 
  
