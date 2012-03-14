#THIS IS ARDUINO CODE DESIGNED TO RUN ON THE ATMEGA328p

int latchPin = 5;
int clockPin = 6;
int dataPin = 4;
int latchPin1 = 8;
int clockPin1 = 9;
int dataPin1 = 7;
//int dataPin2 = 10;

void setup () {
 
  Serial.begin(9600);
  pinMode (latchPin, OUTPUT);
  pinMode (latchPin1, OUTPUT);
  pinMode (clockPin, OUTPUT);
  pinMode (clockPin1, OUTPUT);
  pinMode (dataPin, OUTPUT);
  pinMode (dataPin1, OUTPUT);
  //pinMode (dataPin2, OUTPUT);

}

void loop () {
  for (unsigned int i = 1; i < 16; i++){
  for (unsigned int j = 0; j < 255; j++) {
    //digitalWrite(latchPin, 1);
    shiftOut (dataPin, clockPin, LSBFIRST, i);
    shiftOut (dataPin1, clockPin1, MSBFIRST, j);
    shiftOut (dataPin1, clockPin1, MSBFIRST, j);
    digitalWrite (latchPin, 1);
    digitalWrite (latchPin1, 1);
    delay (30);
    digitalWrite (latchPin, 0);
    digitalWrite (latchPin1, 0);
    Serial.println(j,DEC);
  }    
}
}
/*
void shiftOut (int  myDataPin, int myClockPin, byte myDataOut) {
  int i=0;
  int pinState;
  pinMode (myClockPin, OUTPUT);
  pinMode (myDataPin, OUTPUT);
  
  digitalWrite (myDataPin, 1);
  digitalWrite (myClockPin, 1);
  
  for (i=7; i>=0; i--) {
    digitalWrite (myClockPin, 1);
    if (myDataOut & (1>>i) ) {
      pinState= 0;
   
    }
      else {
      pinState= 1;
      
    }
  
  digitalWrite(myDataPin, pinState);
  digitalWrite(myClockPin, 0);
  digitalWrite(myDataPin, 1);
  
  }

digitalWrite(myClockPin, 1);

}
*/


