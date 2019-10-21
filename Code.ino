const int LEDPin=13;   
const int Trigger=10;
const int Echo=3;


int score=0;    
int distance;
long duration;

void setup() {
 Serial.begin(9600);                 
 pinMode(LEDPin,OUTPUT);            
 pinMode(Trigger,OUTPUT);            
 pinMode(Echo,INPUT);                
}

void loop() {
  digitalWrite(Trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger,HIGH);       
  delayMicroseconds(10);
  digitalWrite(Trigger,LOW);
  
  
  
  duration=pulseIn(Echo,HIGH);   
  distance=duration*0.017;        
  
 
  
  if(distance<=25)              
{
   score=score+1;                   
   digitalWrite(LEDPin,HIGH);  
   delay(100);
   digitalWrite(LEDPin,LOW);                
   delay(100); 
   if(score>4)
   {
    Serial.println("You are the Winnner");
    delay(1000);
    exit(0);                                     
   }
  }  
  Serial.print("Your Current Score is: ");        
  Serial.println(score);                     
  
 }
