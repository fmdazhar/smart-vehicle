#define E1 3  // Enable Pin for motor 1
#define E2 5  // Enable Pin for motor 2
#define LM1 4  // Control pin 1 for motor 1
#define LM2 2  // Control pin 2 for motor 1
#define RM1 8  // Control pin 1 for motor 2
#define RM2 7  // Control pin 2 for motor 2
#define LS 11
#define RS 12
long duration;
int distance;
const int trigPin = A0;
const int echoPin = A1;


void setup() {
  // put your setup code here, to run once:

 
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
    pinMode(LM1, OUTPUT);
    pinMode(LM2, OUTPUT);
    pinMode(RM1, OUTPUT);
    pinMode(RM2, OUTPUT);
    pinMode(LS,INPUT);
    pinMode(RS,INPUT);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600);
}

void loop() 
{ 
   if(ultra()>16)
    {
      line();
    }
   else
    {
    right();
    delay(950);
    forward();
     while(!(digitalRead(LS)) && !(digitalRead(RS)))
       {
       analogWrite(E1,90);
       analogWrite(E2,180);
       }
       analogWrite(E1,100);
       analogWrite(E2,130);
       
      turnright();
      delay(650); 
      back();
      delay(250);+
     }
     
     
}
  
  int ultra()
    {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance= duration*0.034/2;
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
      return distance;
     }
     void left()
     {
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, LOW);
     }
     void right()
     {
      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, LOW);
     }
     void forward()
     {digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, LOW);
     }
     void shut()
     {
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, LOW);
     }
     void turnright()
     {digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
      
     }
     void back()
     {digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
      }
  void line()
  {
    analogWrite(E1,100);
    analogWrite(E2,130);
   
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // Move Forward
  {
    forward();
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     
  { 
    left();
  }
  
  if((digitalRead(LS)) && !(digitalRead(RS)))     
  {
    right();
  }
  
  if((digitalRead(LS)) && (digitalRead(RS)))     // stop
  {
    shut();
  }
    
    
  }


