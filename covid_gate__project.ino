#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define trigger    A1 //attech pin A1 for on the thermal senser 
#define MTRA 6   // attech pin D6 Motor terminal 1 for hand sanitizer
#define MTRC 5  // attech pin D5 Motor terminal 1 for DOOR
#define MTRD 4      //attech pin D4 Motor terminal 2 for DOOR
#define IRPIN 7      //attech pin D7 IR SENSOR FOR RETURN VISITER
#define green   A0 //attech pin A0 for sense green light 
//int  LIM2  = A2 ; //attech pin A2 LIMIT SWITCH 2
//int LIM1 = A3; // attech pin A3 LIMIT SWITCH 1
int LIMIT1 =1 ;  // variable for  LIMIT SWITCH 1
int LIMIT2 =1  ;  // variable LIMIT SWITCH 2
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int G =1;// variable for green color screen
int DOOR =0;// variable for door indication
int val=0;// variable for.................
int DOOR_UP =900;// variable for door up time
int DOOR_DOWN =900;// variable for door down time
int DOOR_STAY =5000;// variable for door stay
void setup() {
  Serial.begin(9600);
  pinMode(MTRA,OUTPUT);// Moter terminal 1 for hand sanitizer
  pinMode(MTRC,OUTPUT);// Moter terminal 1 for DOOR
  pinMode(MTRD,OUTPUT);// Moter terminal 2 for DOOR
  pinMode(trigger,OUTPUT);//give low signal for on thermal sensor
  pinMode(A3,INPUT_PULLUP);// attech pin A2 LIMIT SWITCH 1
  pinMode(A2,INPUT_PULLUP);// attech pin A1 LIMIT SWITCH 2
  pinMode(green,INPUT_PULLUP);//set the pin green light for under thermal condition
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  digitalWrite(trigger, HIGH);//initially trigger pin is high
  digitalWrite(MTRA, LOW);
  digitalWrite(MTRC,LOW);
  digitalWrite(MTRD, LOW);
}

void loop() {
  
  analogRead(A3);
  analogRead(A2);
 delay(200);
    Serial.print(distance);
  //.....................Ultrasonic Sensor .............
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);         // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);  // Calculating the distance
  distance = duration * 0.034 / 2;    // Speed of sound wave divided by 2 (go and back)
  Serial.print("Distance: ");         // Displays the distance on the Serial Monitor
  Serial.print(distance);
  Serial.println(" cm");
  //..................................
 

if (distance<8)                        //when hand is sense by ultra sonic 
{ 
   digitalWrite(trigger, LOW);          //thermal senser is on
   delay(1000);
    digitalWrite(trigger,HIGH);
   Serial.println(G);
          DOOR=0;
           G=digitalRead(green);
        if(G<1){
                   Serial.println(G);
                   Serial.println("Temperature is normal ");
                   DOOR = 1;
                   Serial.println(DOOR);
                      }
                   Serial.println(DOOR); 
     Serial.println("sanitizer on ");
     digitalWrite(MTRA, HIGH);
    delay(3000);
    digitalWrite(MTRA, LOW);
    Serial.println("sanitizer off");
    if (DOOR == 1){
    //..............Condition For Door Is Open ..........
    
  while(1){
    Serial.print("   Limit Switch 1     ");
     Serial.println(analogRead(A3));  
    Serial.print("   Limit Switch 2    ");
    Serial.print(analogRead(A2));             
    digitalWrite(MTRC,LOW);
    digitalWrite(MTRD, HIGH);
  if(analogRead(A3)<30){
    Serial.print("   Limit Switch 1     ");
     Serial.println(analogRead(A3));  
    Serial.print("   Limit Switch 2    ");
    Serial.print(analogRead(A2));  
   digitalWrite(MTRC,LOW);
   digitalWrite(MTRD,LOW);
   break;
   }
   }        
    delay(DOOR_STAY);// TIME WHICH DOOR IS OPEN 
//..................Condition For Door Is Close............
                            
 while(1){
      Serial.print("   Limit Switch 1     ");
     Serial.println(analogRead(A3));  
    Serial.print("   Limit Switch 2    ");
    Serial.print(analogRead(A2));  
    digitalWrite(MTRC,HIGH);
    digitalWrite(MTRD,LOW);
if (analogRead(A2)<30){ 
  Serial.print("   Limit Switch 1     ");
     Serial.println(analogRead(A3));  
    Serial.print("   Limit Switch 2    ");
    Serial.print(analogRead(A2));  
    digitalWrite(MTRC, LOW);
    digitalWrite(MTRD, LOW);
    break;
   
   }
   }     
}
delay(1000);
    distance=20;
     delay(1000);
}
int RETURN = digitalRead(IRPIN);
  if (RETURN==0){
  while(1){
    Serial.print("   Limit Switch 1     ");
     Serial.println(analogRead(A3));  
    Serial.print("   Limit Switch 2    ");
    Serial.print(analogRead(A2));             
    digitalWrite(MTRC,LOW);
    digitalWrite(MTRD, HIGH);
  if(analogRead(A3)<30){
    Serial.print("   Limit Switch 1     ");
     Serial.println(analogRead(A3));  
    Serial.print("   Limit Switch 2    ");
    Serial.print(analogRead(A2));  
   digitalWrite(MTRC,LOW);
   digitalWrite(MTRD,LOW);
   break;
   }
   }        
    delay(DOOR_STAY);// TIME WHICH DOOR IS OPEN 
//..................Condition For Door Is Close............
                            
 while(1){
      Serial.print("   Limit Switch 1     ");
     Serial.println(analogRead(A3));  
    Serial.print("   Limit Switch 2    ");
    Serial.print(analogRead(A2));  
    digitalWrite(MTRC,HIGH);
    digitalWrite(MTRD,LOW);
if (analogRead(A2)<30){ 
  Serial.print("   Limit Switch 1     ");
     Serial.println(analogRead(A3));  
    Serial.print("   Limit Switch 2    ");
    Serial.print(analogRead(A2));  
    digitalWrite(MTRC, LOW);
    digitalWrite(MTRD, LOW);
    break;
   
   }
   }
   }
}
