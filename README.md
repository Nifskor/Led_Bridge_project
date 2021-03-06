# <div align=center> Led_Bridge_project </div>
#### <div align=center> 본 프로젝트는 개인 토이 프로젝트로 싱기버스에서 Led bridge Lamp 출력물 파츠를 이용해 <br>RGB LED Strip 을 이용하여 스탠드등을 만들어보는 프로젝트입니다. </div></br>                                              

* 제작 과정및 상세내용은 네이버 블로그에서 확인 하실수있습니다!
 <a href="https://blog.naver.com/nifskr/222656021598"> <img src="https://user-images.githubusercontent.com/92977647/151411167-b7a060a3-2830-4e4a-abaa-7b8e7bdc2a64.png" ></a>
***
### 제작 이유 
> * 우리집에 있는 스탠드 등이 너무 오래되어서  사기엔 아깝고 나만의 스탠드 등을 만들어보기 위해서 
> * 디제잉 할때 파티룸 느낌이 나는 스탠드르 만들어 보고 싶어서 

### 1. 싱기버스 출력물 및 참고 링크 
> *  https://www.thingiverse.com/thing:1639224

### 2. 개발 기간 

## 소프트웨어 V1 개발 완료 
>* 2022 / 02/ 23 - ( 세부 버그는 사용하면서 개선 예정)
### :dizzy: 개발 진행 완료 2022 / 01 / 09 ~ 2022 / 2 / 23 일까지 수행 완료 ( 버그 대부분 수정 완료 및 디제잉 모드 구현 완료)
### 총 수행기간 : 46일 
> * 3D 프린터 출력 기간 : 2022 /01 / 09 ~ 2022 /01 /17 ( E 시리즈 6개부품 출력 및 조립 완료)
> * 출력물 불량으로 S 부품 7개 다시 재출력 : 2022 / 01 / 29 ~ 2022/ 02 / 10
> * 눈부심을 막아주는 쉐이더 출력기간 : 2022/ 02 / 13 ~ 2022 / 02 / 22 (프린터 고장으로 인해 출력 지연)
> * 아두이노를 이용한 개발 기간 : 2022/ 02 / 12 ~ 2022 / 02 / 21 (전기능 구현완료)
> * 전자 회로작업 (납땜, 회로기판 작업등) : 2022 / 02 / 11 ~ 2022 / 02 / 21  작업완료 (약 5일정도 정밀 진행) + 신규 기능 아날로그 사운드 센서 추가

### 3. 기능 요구사항 (목표)
> * 개발시 필수로 반드시 들어가야하는 조건 
> * 1. 휴식 모드 ✅
> * 2. 학습 모드 - ( 언어 모드 , 수리 모드 , 음악 (창의) 모드)✅
> * 3. 수리 모드 ✅
> * 4. 초록 (단색모드)✅
> * 5. 파랑 모드 (단색모드)✅
> * 6. 취침 모드 (눈에 피로하지 않은 주광색으로 표시되어지다가 일정 시간이 지나면 자동을 종료되는 기능 구현) - 60분후 자동으로 종료 기능 구현 ✅
> * -> 4분후 자동으로 lcd 화면 꺼짐 , 56분 ( 종료 4분전에 ) 자동으로 화면이 켜짐 기능 추가 
> * 7. 클럽 및 디제잉 파티모드 ( EDM의 노래의 3개의 샘플을 들은후 그노래의 패턴에 맞춰 작동하는모드 )- ✅ (아날로그 사운드 센서 사용 구현)
> * 8. 가변저항으로 밝기 조정 가능해야함 ✅
> * 9. 리셋을 버튼을 가능하게 해야함✅
> * 10. 버튼으로 옵션을 선택할수있어야함✅
> * 11. 색상 모드 변경이 가능해야함 ✅
> * 12. LED반반 제어모드르 설정해야함 ✅
> * 13. 기기를 사용하지 않을때 1분 경과후 자동으로 lcd 백라이트가 꺼짐 ✅
> * 14. 다시 사용했을때 확인 버튼을 클릭하면 다시 lcd 백라이트가 켜짐 ✅

### 3-1. 기능 요구사항 테스트 결과 
### 기능 구현율 100% 완료 
![스크린샷 2022-02-25 17 44 25](https://user-images.githubusercontent.com/92977647/155683797-0e31044b-ae6e-47e6-8ad0-aa758f999d8d.png)

![스크린샷 2022-02-25 17 45 02](https://user-images.githubusercontent.com/92977647/155683891-5e6424ae-cc5b-4943-ac6f-5bdc5c302c57.png)

### 4. 개발 언어 및 환경 
> * ![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white) - 아두이노 나노 사용 
> * ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) - 아두이노 IDE 개발 환경 C 언어 사용 

### 4-1. 회로도 
<img src = "https://user-images.githubusercontent.com/92977647/156000794-a0b0d721-42a9-40f5-8a3a-fba1baf2c9ef.png" width="480" height="264"/>

### 5. 3D 프린터 출력 이미지 (제작 과정 진행중..) 
<table>
  <tr>
<td> <img alt="" src = "https://user-images.githubusercontent.com/92977647/151405882-868e048f-3da1-43c8-b910-628e1545a484.gif" width="480" height="264/"/></td>

<td> <img alt="" src="https://user-images.githubusercontent.com/92977647/151407074-f02b3c15-74e0-4a43-86bf-eca1ac3caa72.png" width="480"></td>
   </table>

### 6. 완성후 예상 결과물 
<img src = "https://user-images.githubusercontent.com/92977647/151407579-443d4673-a5aa-4c58-9bc1-738e3418344e.png" width="480" height="264"/>
출처 : https://www.thingiverse.com/thing:1639224

### 6-1. 완성후 결과물 
> * 제작과정 및 좀더 자세한 이야기는 네이버블로그에서 확인하실수 있습니다 
<table>
  <tr>
<td> <img alt="" src = "https://user-images.githubusercontent.com/92977647/155687701-97f2cec2-3657-4ea9-8fb6-6f208c5ed3ad.gif" width="480" height="264/"/></td>
   <td> <img alt="" src = "https://user-images.githubusercontent.com/92977647/155687741-4364abba-8756-4bab-9045-87abcbefecc3.gif" width="480" height="264/"/></td>
    </table>
    
### 7. 추후 추진 계획 
> * Led_Bridge와 컴퓨터 (Mac)이랑 연동가능한 프로그램을 개발하여 컴퓨터에서도 전등을 제어할수있게 만들기 
> * PIR센서를 이용해 자리에 착석하면 자동으로 전등이 켜지도록 기능 구현해보기 

### 7-1. 저작권 라이센스 (License)
> * Led Bridge parts Stl 설계 파일은 원저작자 : <b>Janis Jakaitis </b>님에게 있습니다.
> * 아두이노 프로그래밍 및 회로 기판 관련 라이선스 :

> * Copyright @2022 ING's TEC (Nifskor) and Creative Commons ![스크린샷 2022-02-23 21 10 25](https://user-images.githubusercontent.com/92977647/155316914-dff67ba7-9236-44d7-8d93-66aae4ec8d77.png)
> * 개인적 용도로 출처를 남긴 후 동일 조건 변경은 허용되지만  상업적 용도는 허용하지 않습니다 - 문의 : (nifskr@naver.com)
