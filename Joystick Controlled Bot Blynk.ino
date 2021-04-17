#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YourAuthToken";
char ssid[] = "Jeevanandan";
char pass[] = "Jeevanandan";


#define SC1 D0 
#define SC2 D1 
#define M1 D5 
#define M2 D6 
#define M3 D7 
#define M4 D8 

int spd=200;

void forward()
{
  analogWrite(SC1, spd); 
  analogWrite(SC2, spd); 
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  delay(50);
  Serial.println("FORWARD");
}

void backward()
{
  analogWrite(SC1, spd);
  analogWrite(SC2, spd);
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  delay(50);
  Serial.println("BACKWARD");
}

void left()
{
  analogWrite(SC1, spd); 
  analogWrite(SC2, spd); 
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  delay(50);
  Serial.println("LEFT");
}

void right()
{
  analogWrite(SC1, spd); 
  analogWrite(SC2, spd); 
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  delay(50);
  Serial.println("RIGHT");
}

void STOP()
{
  analogWrite(SC1, spd);
  analogWrite(SC2, spd);
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
  delay(50);
  Serial.println("STOP");
}

void setup() {
  pinMode(SC1,OUTPUT);
  pinMode(SC2,OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
 
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); 
  spd=pinValue;
 
}

BLYNK_WRITE(V1) {
  int y = param[0].asInt();
  int x = param[1].asInt();

  if(x>700&&y>200&&y<900) 
  {
    forward();
  }
  else if(x<200&&y>200&&y<900) 
  {
    backward();
  }
   else if(y>700&&x>200&&x<900) 
  {
    right();
  }
   else if(y<200&&x>200&&x<900) 
  {
    left();
  }
  else
  {
    STOP();
  }
}

void loop() {
 Blynk.run();
}
