#define echo 3
#define trig 2
long dis=0,duration=0;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32,16,2);

void ultrasonic(){
 digitalWrite(trig,0); 
 delayMicroseconds(2);  
 digitalWrite(trig,1); 
 delayMicroseconds(10);
 digitalWrite(trig,0); 
 duration=pulseIn(echo,HIGH);
 dis=0.343*duration/2;
}

void setup()
{
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  for(byte i=5;i<7;i++)
  pinMode(i,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.print("Loading Robot...");
  delay(2000);
  lcd.clear();
  Serial.begin(9600);
}

void loop()
{
  ultrasonic();
  lcd.home();
  lcd.print("dis = "+String(dis)+" mm ");
  //lcd.print(dis);
  //lcd.print(" mm ");
  
  if(dis<500){
  digitalWrite(5,0);
  digitalWrite(6,1);
   lcd.setCursor(5,1);
   lcd.print("Right    "); 
  }
  else{   
    lcd.setCursor(5,1);
    lcd.print("Forward"); 
  dis=map(dis,0,3000,0,255);
  analogWrite(5,dis);
    analogWrite(6,dis);}
}