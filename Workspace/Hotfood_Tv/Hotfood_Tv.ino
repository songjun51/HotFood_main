 #include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);
int relay=10;
boolean toggle=0;
void setup() 
{
  Serial.begin(9600);
  bluetooth.begin(9600);
}
void loop()
{
  if (bluetooth.available()) {  
    Serial.write(bluetooth.read());
  }
  if (Serial.available()) {
    bluetooth.write(Serial.read());
  }

  if(bluetooth.read()=='1'){
  toggle+=1;
  if(toggle==1){
  digitalWrite(relay,LOW);
  delay(1000);
  digitalWrite(relay,HIGH);
  }
  }
  else if(bluetooth.read()=='0'){
  digitalWrite(relay,HIGH);
  toggle=0;
  }
  
  delay(1000);
}
