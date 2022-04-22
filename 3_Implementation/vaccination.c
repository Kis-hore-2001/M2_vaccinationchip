 #include <string.h>
 #include <ctype.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

char fy=0;

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 7;     // the number of the pushbutton pin

int cnt = 0,fl=0,i;  // variable to store the value coming from the sensor
long duration, inches, cm,distance;
char fl1,fl2,fl3,fl4;
char rfid[20];
int am,amt;
void txs(unsigned char val)
{
int i;
Serial.write(val);
for(i=0;i<1200;i++);
}


 void setup() {
 
   Serial.begin(9600);

    lcd.begin(16, 2);
     lcd.print("RFID                ");
delay(2000);
    lcd.setCursor(0,1);
       lcd.print("                           ");

pinMode(A0,INPUT_PULLUP);
pinMode(A1,INPUT_PULLUP);
pinMode(A2,INPUT_PULLUP);
pinMode(A3,INPUT_PULLUP);
pinMode(A4,INPUT_PULLUP);
pinMode(2,OUTPUT);
digitalWrite(2,0);
 }


int yc,zc;

int bs,kf;

long ll;

 void loop() {
   //digitalWrite(ledPin, HIGH);
  i=0;
delay(1000);

if (Serial.available()) {
   
    rfid[0]=Serial.read();
    rfid[1]=Serial.read();
    rfid[2]=Serial.read();
    rfid[3]=Serial.read();
    rfid[4]=Serial.read();
    rfid[5]=Serial.read();
    rfid[6]=Serial.read();
    rfid[7]=Serial.read();
    rfid[8]=Serial.read();
    rfid[9]=Serial.read();
    rfid[10]=Serial.read();
    rfid[11]=Serial.read();
    rfid[12]=Serial.read();
    rfid[13]=Serial.read();
   
 lcd.setCursor(0, 1);
 lcd.write(rfid[11]);
 lcd.write(rfid[12]);
 lcd.write(rfid[13]);


   if(rfid[11]=='B')
   {
      lcd.setCursor(0,1);
       lcd.print("Card 1         ");

 Serial.print("A");
 delay(2000);
   }

   if(rfid[11]=='2')
   {
         lcd.setCursor(0,1);
       lcd.print("Card 2         ");

 Serial.print("B");
 delay(2000);
   }
   
   if(rfid[11]=='F')
   {
         lcd.setCursor(0,1);
       lcd.print("Card 3         ");

 Serial.print("C");
 delay(2000);
   }
     
}

   

   
 }

