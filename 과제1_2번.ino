const int row[8] = {26, 27, 28, 29, 30, 31, 32, 33 };
const int col[8] = {38, 39, 40, 41, 42, 43, 44, 45 };

int number[10][8][4] = {
  {0, 1, 1, 0,  //0
   1, 0, 0, 1,
   1, 0, 0, 1,
   1, 0, 0, 1,
   1, 0, 0, 1,
   1, 0, 0, 1,
   1, 0, 0, 1,
   0, 1, 1, 0},
  {0, 0, 1, 0,  //1
   0, 1, 1, 0,
   1, 0, 1, 0,
   0, 0, 1, 0,
   0, 0, 1, 0,
   0, 0, 1, 0,
   0, 0, 1, 0,
   1, 1, 1, 1},
  {1, 1, 1, 1,  //2
   0, 0, 0, 1,
   0, 0, 0, 1,
   1, 1, 1, 1,
   1, 0, 0, 0,
   1, 0, 0, 0,
   1, 0, 0, 0,
   1, 1, 1, 1},
  {1, 1, 1, 1,  //3
   0, 0, 0, 1,
   0, 0, 0, 1,
   1, 1, 1, 1,
   0, 0, 0, 1,
   0, 0, 0, 1,
   0, 0, 0, 1,
   1, 1, 1, 1},
  {1, 0, 0, 1,  //4
   1, 0, 0, 1,
   1, 0, 0, 1,
   1, 1, 1, 1,
   0, 0, 0, 1,
   0, 0, 0, 1,
   0, 0, 0, 1,
   0, 0, 0, 1},
  {1, 1, 1, 1,  //5
   1, 0, 0, 0,
   1, 0, 0, 0,
   1, 1, 1, 1,
   0, 0, 0, 1,
   0, 0, 0, 1,
   0, 0, 0, 1,
   1, 1, 1, 1},
  {1, 1, 1, 1,  //6
   1, 0, 0, 1,
   1, 0, 0, 0,
   1, 1, 1, 1,
   1, 0, 0, 1,
   1, 0, 0, 1,
   1, 0, 0, 1,
   1, 1, 1, 1},
  {1, 1, 1, 1,  //7
   1, 0, 0, 1,
   1, 0, 0, 1,
   0, 0, 0, 1,
   0, 0, 0, 1,
   0, 0, 0, 1,
   0, 0, 0, 1,
   0, 0, 0, 1},
  {1, 1, 1, 1,  //8
   1, 0, 0, 1,
   1, 0, 0, 1,
   1, 1, 1, 1,
   1, 0, 0, 1,
   1, 0, 0, 1,
   1, 0, 0, 1,
   1, 1, 1, 1},
  {1, 1, 1, 1,  //9
   1, 0, 0, 1,
   1, 0, 0, 1,
   1, 1, 1, 1,
   0, 0, 0, 1,
   1, 0, 0, 1,
   1, 0, 0, 1,
   1, 1, 1, 1}
};
int PTLight[2][8][8] = {
  {0, 0, 0, 1, 1, 0, 0, 0,  //정지
   0, 0, 0, 1, 1, 0, 0, 0,
   0, 0, 1, 1, 1, 1, 0, 0,
   0, 1, 0, 1, 1, 0, 1, 0,
   0, 1, 0, 1, 1, 0, 1, 0,
   0, 0, 0, 1, 1, 0, 0, 0,
   0, 0, 1, 0, 0, 1, 0, 0,
   0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0,  //출발
   0, 0, 0, 1, 1, 0, 0, 0,
   0, 0, 1, 1, 1, 1, 1, 0,
   0, 0, 1, 1, 1, 0, 0, 1,
   1, 1, 0, 1, 1, 0, 0, 1,
   0, 0, 0, 1, 1, 0, 0, 0,
   0, 0, 1, 0, 0, 1, 0, 0,
   0, 0, 1, 0, 0, 0, 1, 0}
};

#define Right_G 1  	 //우측 신호등
#define Right_Y 2
#define Right_R 3
#define Up_G 4      	//위쪽 신호등
#define Up_Y 5
#define Up_R 6
#define Left_G 7    	//좌측 신호등
#define Left_Y 8
#define Left_R 9
#define Down_G 10     //아래쪽 신호등
#define Down_Y 11
#define Down_R 12
#define Botton_1 20 	//스위치
int interval = 30000;	//시간
int BlinkYellow = 3;  	//노란불 점멸 카운트
volatile bool state1 = true;  //스위치를 누르면 false로 변환

void setup() {
  pinMode(Right_G, OUTPUT);
  pinMode(Right_Y, OUTPUT);
  pinMode(Right_R, OUTPUT);
  pinMode(Up_G, OUTPUT);
  pinMode(Up_Y, OUTPUT);
  pinMode(Up_R, OUTPUT);
  pinMode(Left_G, OUTPUT);
  pinMode(Left_Y, OUTPUT);
  pinMode(Left_R, OUTPUT);
  pinMode(Down_G, OUTPUT);
  pinMode(Down_Y, OUTPUT);
  pinMode(Down_R, OUTPUT);
  pinMode(Botton_1, INPUT_PULLUP);  //input과의 차이는 프로세서 내부에 있는 pull-up 저항을 사용
  attachInterrupt(3, Botton, FALLING);  //인터럽트 지정함수(어느핀으로 인터럽트 처리, 호출함수 이름, 모드(신호가 high에서 low))
  for (int thisPin = 0; thisPin < 8; thisPin++) //도트메트릭스에 연결한 것들
   {
    pinMode(row[thisPin], OUTPUT);
    pinMode(col[thisPin], OUTPUT);
   }
}

void loop() {
  unsigned long CheckTime = millis(); //타이머 함수, deley를 이용하여도 millis()는 흐른다
  digitalWrite(Right_G, HIGH);
  digitalWrite(Up_R, HIGH);
  digitalWrite(Left_G, HIGH);
  digitalWrite(Down_R, HIGH);
 
  CheckTime = millis();//초록불일 때 보행자 신호는 사람 모습 출력
  while(interval > (millis() - CheckTime)) {
    PSignal(0);
  }
  //delay(interval);
  digitalWrite(Right_G, LOW);
  digitalWrite(Left_G, LOW);

  BlinkLED(Right_Y, Left_Y);
  digitalWrite(Right_R, HIGH);
  digitalWrite(Left_R, HIGH);
  
  digitalWrite(Up_R, LOW);
  digitalWrite(Down_R, LOW);
  digitalWrite(Up_G, HIGH);
  digitalWrite(Down_G, HIGH);

  /*
 CheckTime = millis();
  while(interval > (millis() - CheckTime)) {
    PSignal(0);
  }
  digitalWrite(Up_G, LOW);
  digitalWrite(Down_G, LOW);
  BlinkLED(Up_Y, Down_Y);
  digitalWrite(Up_R, HIGH);
  digitalWrite(Down_R, HIGH);
  */

  CheckTime = millis();
  SwitchLoop(Up_G, Up_Y, Up_R, Down_G, Down_Y, Down_R, CheckTime);
  digitalWrite(Left_R, LOW);
  digitalWrite(Right_R, LOW);
  
}

// 인터럽트 발생 시 호출(스위치를 누를 경우 호출)
void Botton() {
  if(digitalRead(Up_G) == HIGH)
  state1 = false;
}

// 노란불 점멸 함수
void BlinkLED(const int YellowLED1, const int YellowLED2) {
  long Time;
   for(int i = 0; i <  BlinkYellow; i++){
    digitalWrite(YellowLED1, HIGH);
    digitalWrite(YellowLED2, HIGH);
    Time = millis();
    while((millis() - Time) <= 500){
      PSignal(0);
    }
    digitalWrite(YellowLED1, LOW);
    digitalWrite(YellowLED2, LOW);
    Time = millis();
    while((millis() - Time) <= 500){
      PSignal(0);
    }
   }
}

// 스위치 함수
void SwitchLoop(int GLight1, int YLight1, int RLight1, int GLight2, int YLight2, int RLight2, long CheckTime) {
  int Time;
  long DTime;	//스위치 누르면 3초 대기
  int FTime;	//시간 앞자리
  int LTime;	//시간 뒷자리
  while(interval > (millis() - CheckTime)) {  //interval 시간 동안 진행
    if(state1 == false) { //위 측 신호등이 녹색등일 동안에 스위치를 누를 경우 진행
      
      DTime = millis();//스위치 누르면 대기
      while(3000 > (millis() - DTime)){ //3초 동안 돌린다는 의미
       PSignal(0);//사람 모습 출력
      }
      digitalWrite(GLight1, LOW);
      digitalWrite(GLight2, LOW);
      BlinkLED(YLight1, YLight2);
      digitalWrite(RLight1, HIGH);
      digitalWrite(RLight2, HIGH);
      state1 = true;
      //CheckTime = millis();
      while(interval > (millis() - CheckTime)){//도트메트릭스 출력하기
      //PSignal(1);
        Time = (interval - (millis() - CheckTime)) / 1000;
        FTime = Time / 10;	//시간 앞자리 구하기
        LTime = Time % 10;	//시간 뒷자리 구하기
        NSignal(FTime, LTime);	//도트 메트릭스에 숫자 출력
      }
      CleanDOT();//다 지우고
    }
    PSignal(0);//사람 모습 출력
  }
  if(digitalRead(GLight1) == HIGH) { //스위치가 눌리지 않았을 경우 진행
    digitalWrite(GLight1, LOW);
    digitalWrite(GLight2, LOW);
    BlinkLED(YLight1, YLight2);
    digitalWrite(RLight1, HIGH);
    digitalWrite(RLight2, HIGH);
  }
} 
//도트 매트릭스 전체를 정리 함수
void CleanDOT(){
  for(int i = 0; i < 8; i++){
     digitalWrite(row[i], LOW);
     digitalWrite(col[i], HIGH);
  }
}
// 남은 시간으로 도트 메트릭스에 숫자 출력하는 함수
void NSignal(int FTime, int LTime){
  for(int i = 0; i < 8; i++){
    //CleanDOT(); //신호등 불빛이 너무 약하면 밑에 CleanDOT지우고 여기다가 쓴다.
    for(int j = 0; j < 4; j++){
      CleanDOT();
      digitalWrite(row[i], HIGH);//가로줄 다 켜놓고
      if(number[FTime][i][j]){//십의 자리 숫자
       digitalWrite(col[j], LOW);//세로줄을 하나씩 켜준다.
       delay(1);//0.001초 동안
      }
      if(number[LTime][i][j]){//일의 자리 숫자씩
        digitalWrite(col[j+4], LOW);//세로줄을 하나씩 켜준다.
        delay(1);//0.001초 동안
      }
    }
  }
}
//사람 모습 출력 함수
void PSignal(int GoStop){
  for(int i = 0; i < 8; i++){
    //CleanDOT(); //신호등 불빛이 너무 약하면 밑에 CleanDOT지우고 여기다가 쓴다.
    for(int j = 0; j < 8; j++){
      CleanDOT();//전체삭제
      digitalWrite(row[i], HIGH);//가로줄 전체 다 켜놓고
      if(PTLight[GoStop][i][j] == 1){
       digitalWrite(col[j], LOW);
        delay(1);
      }
    }
  }
}
