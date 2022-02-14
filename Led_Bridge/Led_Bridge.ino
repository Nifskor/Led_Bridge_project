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
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
// define NeoPixel Pin and Number of LEDs
#define PIN 6
#define NUM_LEDS 59
// create a NeoPixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
/*   아래 부분 수동변수 파트  */
int count = 0;  // 현재 아직은 사용안함
int resis = A0; // 가변저항
int powerbutton = 2;
int powercheck = 0;    // 전원껏다 켯다용
int powerbutcheck = 0; // 파워 켜짐 여부 확인체크  1이면 꺼진상태 , 2이면 켜져있는 상태  , 5대기
int displaycount =0; // 초기 디스플레이 표시 카운팅 체크 
int select2 =0;
int menustep = 0 ; // 메뉴 선택부분 
/*       ------  헤더 선언 부분 --------------------*/

void setup()
{
// start the strip and blank it out
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  /*  초기 모드 시작 */
  lcd.begin();
  lcd.backlight();
  lcd.print("WELCOME, LED BRI");
 lcd.setCursor(0, 1);
 lcd.print("DGE V2 ING's");
 //--------------------------------------------- display
  strip.begin();
  strip.show();
  strip.setBrightness(255); //초기밝기255
  /* 초기 시리얼 통신 설정  */
  Serial.begin(9600);
  /*   초기 시리얼 통신 설정 끝 */
  /* 초기 부팅후 환영모드 */
  for (int i = 0; i <= NUM_LEDS; i++)
  {
    // strip.setPixelColor(i, 255,139,39); //2700k
    strip.setPixelColor(i, 255, 255, 255); // 2700k
    strip.show();
    delay(40);
  }
  for (int j = 0; j <= NUM_LEDS; j++)
  {
    strip.setPixelColor(j, 0, 0, 0); // 2700k
    strip.show();
    delay(40);
  }
  pinMode(powerbutton, INPUT);
} // 셋업 부분 마지막

/*  void loop 시작 부분 */
void loop()
{
  /* 선택 옵션 넣은후 작동되게 case문 작성 */
  int select = analogRead(resis) / 128; // 나누기로 128해서 1 2 3 4~8 케이스 맞게나오게 설정
  //powera(); // 파워 전원 제어 부분 
  Serial.println(select);
  while(displaycount==0){
  lcd.begin();
 lcd.print("Please Select");
 displaycount=1;
  }
  char *menuitem[] = {"BACK MENU        ","REST MODE       " , "STUDY MODE         " , "FIX MODE        " ,
  "GREEN MODE       ","BLUE MODE         ","Sleepin MODE        ","DJING MODE      "};
  int menuNum = sizeof(menuitem)/sizeof(char *); //arraysize

if(menustep == 0 ){ 
   lcd.begin(); 
lcd.println(menuitem[select]);
}
if(select ==0){
  menustep =0;
  select =0;
}else if (select ==1){
  bookmode();
}
  /*switch (select)
  {
     case '0':
    menustep = 0; //초기화면 
    break;
  case '1':
    bookmode();
    Serial.println("case0");
    break;
  case '2':
    studymode();
    break;
  case '3':
    fixmode();
    break;
  case '4':
    greenmode();
    break;
  case '5':
    bluemode();
    break;
  case '6':
    sleeping();
    break;
  case '7':
    djingmode();
    break;
  }*/
  // ledbright(); // 밝기 제어 부분 
//for(int k =0; k<=59; k++){
//strip.setPixelColor(k, 255,139,39); //2700k
//ledbright();
  }
 
  /* -----------------------------*/

// end loop문
/* 함수 처리 공간 */
// 반복문 처리해서 탈출조건 만들어서 탈출하는형태로 구현 
void bookmode()
{
  do { 
   lcd.setCursor(0,0);
    lcd.println("REST MODE          ");
  ledbright(); // 밝기 제어 부분 
        for(int i = 0 ; i <=59; i++){
         strip.setPixelColor(i, 255,139,39); //2700k
   // strip.setPixelColor(i, 255, 255, 255); // 2700k
    strip.show();
   // delay(40);
        }
        }while(1); //버튼을 누른다던지 이벤트 발생시 
}

void studymode()
{
}
void fixmode()
{
}
void redmode()
{
}
void greenmode()
{
}
void bluemode()
{
}
void sleeping()
{
}
void djingmode()
{
}


void powera()
{
  powercheck = digitalRead(powerbutton); // 파워버튼
                                         //-------------------------------------------------------------------------------------
  if (powercheck == 1)
  { // 버튼 눌린상태 눌린상태에서 전원꺼짐모
    if (powerbutcheck == 2)
    { // 전원이 켜져있는 상태라면? 꺼야겠지
       lcd.begin(); 
        lcd.print("POWER OFF");
        lcd.setCursor(0, 1);
        lcd.print("STAND POWER OFF");
      for (int j = 0; j <= NUM_LEDS; j++)
      {
        strip.setPixelColor(j, 0, 0, 0);
        strip.show();
        delay(40);
      }
      powerbutcheck = 5; // 이건꺼졌을상태임
      Serial.println("전원이 꺼짐 ");
    }
  }
  //-----------------------------------------------------------------------
  if (powercheck == 1)
  { // 버튼이 작동했을때 함수
    if (powerbutcheck == !5)
    { // 5가 아닐때만 동작
      powerbutcheck = 1;
     
    }
    if (powerbutcheck == 5)
    { // 자동 꺼짐 방지용 코드 절대 중요!
      powerbutcheck = 0;
    }
  }
  //----------------------------------------------------------------
  if (powerbutcheck == 1) // 전원이 켜짐
  {
     lcd.begin(); 
        lcd.print("POWER ON");
        lcd.setCursor(0, 1);
        lcd.print("STAND POWER ON");
    for (int i = 0; i <= NUM_LEDS; i++)
    {
       strip.setBrightness(70);
      strip.setPixelColor(i, 255, 255, 255);
      strip.show();
      delay(40);
      powerbutcheck = 2; // 켜진후 꺼짐을 대기하는 함수
     
    }
     
    Serial.println("전원이 켜짐");
  }
  //-------------------------------------------------------------
}
void ledbright()
{
  //lcd.begin();
  /*  LED 밝기 조정용 함수 */
  int val = analogRead(resis) / 4; // 나누기 4로 max값 255로 나오게
  /*if (val == 0)
  {
    strip.setBrightness(0);
    strip.show();
  }*/// 불안정으로 인해 코드 생략 
  delay(10);
  if (val >= 0 && val <= 10)
  {
    strip.setBrightness(10);
    strip.show();
  }
  if (val >= 10 && val <= 20)
  {
    strip.setBrightness(20);
    strip.show();
  }
  if (val >= 20 && val <= 30)
  {
    strip.setBrightness(30);
    strip.show();
  }
  if (val >= 30 && val <= 40)
  {
    strip.setBrightness(40);
    strip.show();
  }
  if (val >= 40 && val <= 50)
  {
    strip.setBrightness(50);
    strip.show();
  }
  if (val >= 50 && val <= 60)
  {
    strip.setBrightness(60);
    strip.show();
  }
  if (val >= 60 && val <= 70)
  {
    strip.setBrightness(70);
    strip.show();
  }
  if (val >= 70 && val <= 80)
  {
    strip.setBrightness(80);
    strip.show();
  }
  if (val >= 80 && val <= 90)
  {
    strip.setBrightness(90);
    strip.show();
  }
  if (val >= 90 && val <= 100)
  {
    strip.setBrightness(100);
    strip.show();
  }
  if (val >= 100 && val <= 110)
  {
    strip.setBrightness(110);
    strip.show();
  }
  if (val >= 110 && val <= 120)
  {
    strip.setBrightness(120);
    strip.show();
  }
  if (val >= 120 && val <= 130)
  {
    strip.setBrightness(130);
    strip.show();
  }
  if (val >= 130 && val <= 140)
  {
    strip.setBrightness(140);
    strip.show();
  }
  if (val >= 140 && val <= 150)
  {
    strip.setBrightness(150);
    strip.show();
  }
  if (val >= 150 && val <= 160)
  {
    strip.setBrightness(160);
    strip.show();
  }
  if (val >= 160 && val <= 170)
  {
    strip.setBrightness(170);
    strip.show();
  }
  if (val >= 170 && val <= 180)
  {
    strip.setBrightness(180);
    strip.show();
  }
  if (val >= 180 && val <= 190)
  {
    strip.setBrightness(190);
    strip.show();
  }
  if (val >= 190 && val <= 200)
  {
    strip.setBrightness(200);
    strip.show();
  }
  if (val >= 200 && val <= 210)
  {
    strip.setBrightness(210);
    strip.show();
  }
  if (val >= 210 && val <= 220)
  {
    strip.setBrightness(220);
    strip.show();
  }
  if (val >= 220 && val <= 230)
  {
    strip.setBrightness(230);
    strip.show();
  }
  if (val >= 230 && val <= 240)
  {
    strip.setBrightness(240);
    strip.show();
  }
  if (val >= 240 && val <= 255)
  {
    strip.setBrightness(255);
    strip.show();
  }
  Serial.println(val);
    //lcd.clear();
    lcd.setCursor(0, 1);
    lcd.blink();
     lcd.print(val);
     if(val  >=98&& val<100)lcd.clear();
   
} // ledbright end
