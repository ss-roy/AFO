#include <Servo.h>

Servo myservo;

int fsrpin1 = A0 , fsrpin2=A1;  
int fsrvalue1 = 0 , fsrvalue2 = 0;  
int status=1,pos;

void setup() {
  
  digitalWrite(8, HIGH);
  digitalWrite(10,HIGH);
  Serial.begin(9600);
  myservo.attach(9);
   for (pos = 180; pos >= 70; pos -= 1) { 
    myservo.write(pos);           
    delay(15);                
  }
  delay(2000);
}

void loop() {
  fsrvalue1 = analogRead(fsrpin1);
  Serial.print(fsrvalue1);
  Serial.print("\t");
  fsrvalue2 = analogRead(fsrpin2);
  Serial.print(fsrvalue2);
  Serial.print("\t");
  Serial.println(status);
  if(fsrvalue1 >= 3 && status!=2)
  {
    status=2;
    for (pos = 70; pos <= 180; pos += 1) {
    myservo.write(pos);  
    delay(15);      
    }
    for (pos = 180; pos >= 70; pos -= 1) { 
    myservo.write(pos);           
    delay(15);                
  }
  }
  if(fsrvalue2 >= 3 && status!=3)
  {
    status=3;
  for (pos = 0; pos <= 70; pos += 1) {
    myservo.write(pos);  
    delay(15);      
    }
  }
}

