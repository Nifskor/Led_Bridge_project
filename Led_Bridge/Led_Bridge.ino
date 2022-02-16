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
int powerbutton = 2; // 파워용 버튼 
int okbutton = 3; // 확인용 버튼 
int okbuttontemp =0; //버튼 감지용 함
int powercheck = 0;    // 전원껏다 켯다용
int powerbutcheck = 0; // 파워 켜짐 여부 확인체크  1이면 꺼진상태 , 2이면 켜져있는 상태  , 5대기
int displaycount =0; // 초기 디스플레이 표시 카운팅 체크 
int select2 =0;
int menustep = 0 ; // 메뉴 선택부분 
int workingokcheck = 0;
char *menuitem[] = {"REST MODE(2300K)          ","STUDY MODE       " , "FIX MODE         " , "GREEN MODE        " ,
  "BLUE MODE       ","Sleepin MODE         ","DJING MODE        ","MIDDLE MODE      "};
  int menuNum = sizeof(menuitem)/sizeof(char *); //arraysize
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
    strip.setPixelColor(i, 255,139,39);//2700k 
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
  pinMode(okbutton,INPUT);
  lcd.clear();
  
} // 셋업 부분 마지막

/*  void loop 시작 부분 */
void loop()
{
  /* 선택 옵션 넣은후 작동되게 case문 작성 */
  firstpage();
 
}
  /* -----------------------------*/

// end loop문
/* 함수 처리 공간 */
// 반복문 처리해서 탈출조건 만들어서 탈출하는형태로 구현 
// 아래에서 부턴 LED 조명 제어부분임 색상에따른 서칭이 필요 
void restmode()
{
  do { 
   
    okbuttoncheck(); // 확인버튼 감지용 
   lcd.setCursor(0,0);
    lcd.println("REST MODE(2300K)          ");
  ledbright(); // 밝기 제어 부분 
        for(int i = 0 ; i <=59; i++){
         strip.setPixelColor(i, 255,115,23); //2300k 색상 
         //strip.setPixelColor(i, 255,139,39);//2700k 색상 
        strip.show();
        } 
        if(okbuttontemp==1){
          workingokcheck++;
          if(workingokcheck >=2) break;
        }
        
        }while(true); //버튼을 누른다던지 이벤트 발생시 
        workingokcheck =0;
}

void studymode()
{
   do { 
    //---------------------------------
    okbuttoncheck(); // 확인버튼 감지용 
    int val = analogRead(resis) / 256; // 나누기 256로 max값 4로 나오게 4 가지 옵션 
    //-------------------------------------
   lcd.setCursor(0,0);
    lcd.println("STUDY MODE          ");
  //ledbright(); // 밝기 제어 부분 
       lcd.setCursor(0,1);
       lcd.println("Choose OPtion");
       //---------------------------------------- 아래 부터 스터디 모드 아래 모드 시작 default 1번모드임 
       if(val == 0) {
        lcd.setCursor(0,1);
       lcd.println("Language mode .    ");
       //-------------------------------------------여기서 부터 언어용 불빛 
       if(okbuttontemp==1){
        do { 
    okbuttoncheck(); // 확인버튼 감지용 
   lcd.setCursor(0,0);
    lcd.println("Language mode         ");
  ledbright(); // 밝기 제어 부분 
        for(int i = 0 ; i <=59; i++){
         strip.setPixelColor(i, 255,219,186); //4500k
        strip.show();
        }
        if(okbuttontemp==1){
          workingokcheck++;
          if(workingokcheck >=2) break;
        }
        
        }while(true); //버튼을 누른다던지 이벤트 발생시 
        workingokcheck =0; 
       }// if oktemp 끝 
       }// if val 끝 
       //------------------------------------------- 끝 아래는 수학모드 
       if (val ==1) {
        lcd.setCursor(0,1);
       lcd.println("Math SC MODE .    ");
        if(okbuttontemp==1){
        do { 
    okbuttoncheck(); // 확인버튼 감지용 
   lcd.setCursor(0,0);
    lcd.println("Math SC MODE         ");
  ledbright(); // 밝기 제어 부분 
        for(int i = 0 ; i <=59; i++){
         strip.setPixelColor(i, 255,243,239); //6000k
        strip.show();
        }
        if(okbuttontemp==1){
          workingokcheck++;
          if(workingokcheck >=2) break;
        }
        
        }while(true); //버튼을 누른다던지 이벤트 발생시 
        workingokcheck =0; 
       }// if oktemp 끝  
       } 
       //--------------------------------------------- 아래 음악 모드 
       if(val == 2) {
        lcd.setCursor(0,1);
       lcd.println("MUSIC MODE .      ");
        if(okbuttontemp==1){
        do { 
    okbuttoncheck(); // 확인버튼 감지용 
   lcd.setCursor(0,0);
    lcd.println("MUSIC MODE         ");
  ledbright(); // 밝기 제어 부분 
        for(int i = 0 ; i <=59; i++){
         strip.setPixelColor(i, 255,180,107); //3000k
        strip.show();
        }
        if(okbuttontemp==1){
          workingokcheck++;
          if(workingokcheck >=2) break;
        }
        
        }while(true); //버튼을 누른다던지 이벤트 발생시 
        workingokcheck =0; 
       }// if oktemp 끝   
       }
       //-------------------------------------------- 아래 탈출 모드 
        if (val ==3 ) {
        lcd.setCursor(0,1);
       lcd.println("EXIT               ");
       }
        if(okbuttontemp==1){
          workingokcheck++;
          if(workingokcheck >=2) break;
        }
        }while(true); //버튼을 누른다던지 이벤트 발생시 
        workingokcheck =0; 
}
void fixmode()
{do { 
  
    okbuttoncheck(); // 확인버튼 감지용 
   lcd.setCursor(0,0);
    lcd.println("FIX  MODE          ");
  ledbright(); // 밝기 제어 부분 
        for(int i = 0 ; i <=59; i++){
       strip.setPixelColor(i, 255,249,253); //6500k
        strip.show();
        }
        if(okbuttontemp==1){
          workingokcheck++;
          if(workingokcheck >=2) break;
        }
        
        }while(true); //버튼을 누른다던지 이벤트 발생시 
        workingokcheck =0; 
 
}
void greenmode()
{ 
  do { 
  
    okbuttoncheck(); // 확인버튼 감지용 
   lcd.setCursor(0,0);
    lcd.println("GREEN MODE          ");
  ledbright(); // 밝기 제어 부분 
        for(int i = 0 ; i <=59; i++){
         strip.setPixelColor(i, 0,255,0); //2700k
        strip.show();
        }
        if(okbuttontemp==1){
          workingokcheck++;
          if(workingokcheck >=2) break;
        }
        
        }while(true); //버튼을 누른다던지 이벤트 발생시 
        workingokcheck =0; 
}
void bluemode()
{
  do { 
   
    okbuttoncheck(); // 확인버튼 감지용 
   lcd.setCursor(0,0);
    lcd.println("BLUE MODE          ");
  ledbright(); // 밝기 제어 부분 
        for(int i = 0 ; i <=59; i++){
         strip.setPixelColor(i, 0,0,255); //2700k
        strip.show();
        }
        if(okbuttontemp==1){
          workingokcheck++;
          if(workingokcheck >=2) break;
        }
        
        }while(true); //버튼을 누른다던지 이벤트 발생시 
        workingokcheck =0; 
}
void sleeping()
{
  
}
void djingmode()// 디제잉 모드 
{
  do { 
   
    okbuttoncheck(); // 확인버튼 감지용 
   lcd.setCursor(0,0);
    lcd.println("DJING MODE          ");
  lcd.setCursor(0,1);
  lcd.println("AllloopEnd->OUT.");
  djingstart();
  //colorWipe(strip.Color(255,   0,   0), 50); // Red
  //colorWipe(strip.Color(  0, 255,   0), 50); // Green
  colorWipe(strip.Color(  0,   0, 0), 50); // Dark
delay(10000);
  // This is middle parts 
  theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
  theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
  theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
  theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
  theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
  theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
  theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
  colorWipe(strip.Color(  0,   0, 0), 50); // Dark
  //rainbow(8);             // Flowing rainbow cycle along the whole strip
  //theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant
        if(okbuttontemp==1){
          workingokcheck++;
          if(workingokcheck >=2) break;
        }
        
        }while(true); //버튼을 누른다던지 이벤트 발생시 
        workingokcheck =0; 
  
}
void middlemode(){
  
}
//--------------------------------------------------------------------- djing mode 함수 
void djingstart(){
  for(int i=0; i<strip.numPixels(); i++){
   strip.setPixelColor(i, 255,255,255); //2700k         //  Set pixel's color (in RAM)
    strip.show();     }                     //  Update strip to match
    delay(10000);     
             for(int j=0; j<strip.numPixels(); j++){
   strip.setPixelColor(j, 255,255,255); //2700k         //  Set pixel's color (in RAM)
    strip.show();     }                     //  Update strip to match
    delay(1000);          
  
}
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
void theaterChase(uint32_t color, int wait) {
  for(int a=0; a<10; a++) {  // Repeat 10 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    strip.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}
void theaterChaseRainbow(int wait) {
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<30; a++) {  // Repeat 30 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for(int c=b; c<strip.numPixels(); c += 3) {
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show();                // Update strip with new contents
      delay(wait);                 // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
}
//------------------------------------------------------------------------------
void okbuttoncheck(){/// 확인버튼 감지코드 
  okbuttontemp = digitalRead(okbutton); // 파워버튼
  Serial.println(okbuttontemp);
}
//-------------------------------------------------------------------------------
void firstpage(){ // 시작후 초기 실행및 구현 화면 
   int select = analogRead(resis) / 128; // 나누기로 128해서 1 2 3 4~8 케이스 맞게나오게 설정
  Serial.println(select);
  okbuttoncheck(); // 확인버튼 감지용 
   /* 메인 메뉴 셋팅 초기화면 구현 부 */ 
  if(powerbutcheck==!2){ //전원이 켜진 상태가 아닐때 
    lcd.setCursor(0, 0);
    lcd.println("LED BRIDGE V2   ");
    lcd.setCursor(0, 1); 
    lcd.println("PLEASE POWER ON "); // 전원을 반드시 킨후 사용이 가능하도록 
    powera(); // 파워 전원 제어 부분 
  }else{
     powera(); // 파워 전원 제어 부분 
  while(displaycount==0){
    lcd.setCursor(0, 0);
    lcd.setCursor(0, 1);
  lcd.clear();
 lcd.print("Please Select MODE");
 displaycount=1;
  }
// -------------------------------메뉴 화면 부분 
int firsttemp=0;
//if(firsttemp==0)lcd.clear(); firsttemp=1;
 lcd.setCursor(0, 0);
 lcd.println("Select MODE :   ");
 lcd.setCursor(0, 1);
lcd.println(menuitem[select]); // 배열 부분 상단으로 올림 
//---------------------------------- 초기 옵션 부분 
 if (select ==0){
  if(okbuttontemp ==1 ) {
  restmode();
  }
}else if(select ==1){
   if(okbuttontemp ==1 ) {
  studymode();
   }
}
else if( select ==2){
   if(okbuttontemp ==1 ) {
  fixmode();
   }
}else if(select ==3){
   if(okbuttontemp ==1 ) {
  greenmode();
   }
}else if(select ==4){
   if(okbuttontemp ==1 ) {
  bluemode();
   }
}else if(select ==5){
   if(okbuttontemp ==1 ) {
  sleeping();
   }
}else if(select ==6){
   if(okbuttontemp ==1 ) {
  djingmode();
   }
}else if(select ==7){
   if(okbuttontemp ==1 ) {
  middlemode();
   }
}
  }
}
//------------------------------------------------------------------------------
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
      strip.setPixelColor(i, 255,139,39);//2700k 색상 
      strip.show();
      delay(40);
      powerbutcheck = 2; // 켜진후 꺼짐을 대기하는 함수
     
    }
     
    Serial.println("전원이 켜짐");
  }
  //-------------------------------------------------------------
}
//----------------------------------------------------------------
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
  Serial.println(val);// 변할때만 작동하게 해야할듯 
    //lcd.clear();
    lcd.setCursor(0, 1);
    lcd.blink();
     lcd.print(val);
     if(val  >=98&& val<=102)lcd.clear();
     if(val  >=0&& val<=0)lcd.clear(); // 0 이면 디스플레이 클리
   
} // ledbright end
