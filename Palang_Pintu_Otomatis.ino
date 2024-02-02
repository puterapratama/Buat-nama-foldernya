#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <deprecated.h>
#include <require_cpp11.h>

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_G 5
#define LED_R 4
#define BUZZER 2
MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo myServo;

void setup ()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  myServo.attach(3);
  myServo.write(0);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R,OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  Serial.println("program siap");
  Serial.println();

}
void loop()
{

float rfid = 15;
float ifr = 4;
  
float hasil;  
float tbc1	= (25-rfid)/20;
float tbc2 	= 1;
float ttbc1 	= (rfid-5)/20;
float ttbc2 	= 1;
float tdksi1 	= (8-ifr)/5;
float tdksi2	= 1; 
float ttdksi1 	= (ifr-3)/5;
float ttdksi2 	= 1;
float  pre1, pre2, pre3, pre4, rule1,rule2,rule3,rule4;


  //rule 1
  if(rfid <= 5 && ifr <= 3) {
  	rule1 = 180 - (tbc2 * 90);
    pre1 = tbc2;
  } else if ((rfid > 5 && rfid <= 25) && ifr <= 3){
  		 	
          if(tbc1 < tdksi2){
          rule1 = 180 - (tbc1 * 90); //rules 1
          pre1 = tbc1;
        } else if (tbc1 > tdksi2){
          rule1 = 180 - (tdksi2 * 90); //rules 1
          pre1 = tdksi2;
        } else {
          rule1 = 180 - (tbc1 * 90); //rules 1
          pre1 = tbc1;
        }
    
  } else if ((rfid > 5 && rfid <= 25) && (ifr > 3 && ifr <= 8)){
  		 	
          if(tbc1 < tdksi1){
          rule1 = 180 - (tbc1 * 90); //rules 1
          pre1 = tbc1;
        } else if (tbc1 > tdksi1){
          rule1 = 180 - (tdksi1 * 90); //rules 1
          pre1 = tdksi1;
        } else {
          rule1 = 180 - (tdksi1 * 90); //rules 1
          pre1 = tdksi1;
        }
   
  }
  
  //rule2
   if(rfid <= 5 && ifr > 8) {
  	rule2 = 90 + (tbc2 * 90);
    pre2 = tbc2;
  } else if ((rfid > 5 && rfid <= 25) && ifr > 8){
  		 	
          if(tbc1 < ttdksi2){
          rule2 = 90 + (tbc1 * 90); //rules 2
          pre2 = tbc1;
        } else if (tbc1 > ttdksi2){
          rule2 = 90 + (ttdksi2 * 90); //rules 2
          pre2 = ttdksi2;
        } else {
          rule2 = 90 + (tbc1 * 90); //rules 2
          pre2 = tbc1;
        }
    
  } else if ((rfid > 5 && rfid <= 25) && (ifr > 3 && ifr <= 8)){
  		 	
          if(tbc1 < ttdksi1){
          rule2 = 90 + (tbc1 * 90); //rules 2
          pre2 = tbc1;
        } else if (tbc1 > ttdksi1){
          rule2 = 90 + (ttdksi1 * 90); //rules 2
          pre2 = ttdksi1;
        } else {
          rule2 = 90 + (ttdksi1 * 90); //rules 2
          pre2 = ttdksi1;
        }
    
    
  }
             
  
   //rule 3
   
  if(rfid > 25 && ifr <= 3) {
  	rule3 = 180 - (ttbc2 * 90);
    pre3 = ttbc2;
  } else if ((rfid > 5 && rfid <= 25) && ifr <= 3){
  		 	
          if(ttbc1 < tdksi2){
          rule3 = 180 - (ttbc1 * 90); //rules 3
          pre3 = ttbc1;
        } else if (ttbc1 > tdksi2){
          rule3 = 180 - (tdksi2 * 90); //rules 3
          pre3 = tdksi2;
        } else {
          rule3 = 180 - (ttbc1 * 90); //rules 3
          pre3 = ttbc1;
        }
    
  } else if ((rfid > 5 && rfid <= 25) && (ifr > 3 && ifr <= 8)){
  		 	
          if(ttbc1 < tdksi1){
          rule3 = 180 - (ttbc1 * 90); //rules 3
          pre3 = ttbc1;
        } else if (ttbc1 > tdksi1){
          rule3 = 180 - (tdksi1 * 90); //rules 3
          pre3 = tdksi1;
        } else {
          rule3 = 180 - (tdksi1 * 90); //rules 3
          pre3 = tdksi1;
        }
  
  }
       
   
  //rule4
  
   if(rfid > 5 && ifr > 8) {
  	rule4 = 90 + (ttbc2 * 90);
    pre4 = ttbc2;
  } else if ((rfid > 5 && rfid <= 8) && ifr > 8){
  		 	
          if(ttbc1 < ttdksi2){
          rule4 = 90 + (ttbc1 * 90); //rules 4
          pre4 = ttbc1;
        } else if (ttbc1 > ttdksi2){
          rule4 = 90 + (ttdksi2 * 90); //rules 4
          pre4 = ttdksi2;
        } else {
          rule4 = 90 + (ttdksi1 * 90); //rules 4
          pre4 = ttdksi1;
        }
    
  } else if ((rfid > 5 && rfid <= 25) && (ifr > 3 && ifr <= 8)){
  		 	
          if(ttbc1 < ttdksi1){
          rule4 = 90 + (ttbc1 * 90); //rules 4
          pre4 = ttbc1;
        } else if (ttbc1 > ttdksi1){
          rule4 = 90 + (ttdksi1 * 90); //rules 4
          pre4 = ttdksi1;
        } else {
          rule4 = 90 + (ttdksi1 * 90); //rules 4
          pre4 = ttdksi1;
        }

  }          
  
  
  hasil = ((pre1*rule1)+(pre2*rule2)+(pre3*rule3)+(pre4*rule4))/(pre1+pre2+pre3+pre4);
  Serial.print("rfid: "); //menulis "Suhu Ruangan: " pada serial monitor
  Serial.print(rfid); //menulis besarnya nilai (suhu) pada serial monitor
  //menulis " Degree C" pada serial monitor diakhiri dengan pergantian baris
  Serial.print("ifr :"); //menulis "Smoke Detected :" pada serial monitor
  Serial.println(ifr); //menulis bersarnya smokesensorValue pada serial monitor
  Serial.print("hasil: ");
  Serial.println(hasil);
  //lcd.print(hasil);

  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i],HEX));
  }
  Serial.println();
  Serial.println("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "93 BF 3E 96")
  {
  Serial.println("KARTU BERHASIL MASUK");
  Serial.println();
  delay(500);
  digitalWrite(LED_G, HIGH);
  tone(BUZZER, 500);
  delay(300);
  noTone(BUZZER);
  myServo.write(90);
  delay(5000);
  myServo.write(0);
  digitalWrite(LED_G, LOW);
  }
  else  {
  Serial.println("KARTU GAGAL MASUK");
  digitalWrite(LED_R, LOW);
  tone (BUZZER, 300);
  delay(1000);
  digitalWrite(LED_R, LOW);
  noTone(BUZZER);
  }
  delay(1000);
}