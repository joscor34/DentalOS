#include <Wire.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Encoder.h>
#include <OneButton.h>
#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 200
LiquidCrystal_I2C lcd(0x3B, 20, 4);
Encoder myEnc(5, 6);
Servo myser;
OneButton button0(8, true);

MPU6050 sensor;

byte flecha[] = {
  B00000,
  B00000,
  B00100,
  B00110,
  B11111,
  B00110,
  B00100,
  B00000
};

byte flechaR[] = {
  B00000,
  B00000,
  B00100,
  B01100,
  B11111,
  B01100,
  B00100,
  B00000
};

byte flechaL[] = {
  B00000,
  B00000,
  B00100,
  B01100,
  B11111,
  B01100,
  B00100,
  B00000
};
//******************************************************
byte f[] = {
  B00001,
  B11110,
  B01001,
  B00100,
  B00010,
  B11100,
  B01100,
  B11110
};
byte a[] = {
  B00000,
  B00000,
  B10000,
  B11000,
  B10100,
  B10010,
  B10001,
  B11111
};


byte c[] = {
  B00111,
  B00010,
  B01110,
  B11011,
  B11010,
  B11000,
  B11001,
  B01110
};
byte t[] = {
  B00000,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};
byte o[] = {
  B00000,
  B00000,
  B00000,
  B01010,
  B10101,
  B01010,
  B10101,
  B01010
};
byte r[] = {
  B00000,
  B11100,
  B10010,
  B10010,
  B11100,
  B10100,
  B10010,
  B10010
};
byte s[] = {
  B00001,
  B00010,
  B00110,
  B01100,
  B11111,
  B00110,
  B01100,
  B10000
};
//******************************************************















#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 200


int gx, gy, gz;

//Variables usadas por el filtro pasa bajos
byte np;
long f_ax,f_ay, f_az;
int p_ax, p_ay, p_az;
long f_gx,f_gy, f_gz;
int p_gx, p_gy, p_gz;
int counter=0;
byte ms;
int lp;
int men_act;
int countS1;
int countS2;
int countS3;
int ver = 0;
int countAnt = 0;
int count = 0;
int countS;
int lamp1 = 0;
int lamp2 = 0;
int lamp3 = 0;
byte countG = 0;
byte countGA = 0;
int ser = 0;
int count2 = 0;
byte countP = 0;
byte countPA;
byte directions;
int ax, ay, az;
//Valor de los offsets
int ax_o,ay_o,az_o;
int gx_o,gy_o,gz_o;

int seguro = 0;
int accel_ang_x;

int x;
int g;
float countP1;
float countP2;
float countP3;

void setup() {
  pinMode(12,INPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  myser.attach(9);
  myser.write(30);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  button0.attachClick(singleClick);
  button0.attachDoubleClick(doubleClick);
  lcd.begin();
  Serial.begin(9600);
  lcd.createChar(10,flecha);
  lcd.createChar(flechaR,flechaR);

  lcd.createChar(3,f);
  lcd.createChar(4,a);
  lcd.createChar(5,c);
  lcd.createChar(6,t);
  lcd.createChar(7,o);
  lcd.createChar(8,r);
  lcd.createChar(9,s);
    
  Serial.println("Basic Encoder Test:");
  inicio();
  menu1();
  Wire.begin();           //Iniciando I2C  
  sensor.initialize();    //Iniciando el sensor
  if (sensor.testConnection()) Serial.println("Sensor iniciado correctamente");
  else Serial.println("Error al iniciar el sensor");
}

long oldPosition  = -999;
void loop() {
  digitalWrite(13,HIGH);
 // Serial.println(digitalRead(12));
  button0.tick();
if(seguro == 0){
  long newPosition = myEnc.read()/4;
  if (newPosition != oldPosition) {
    
    if(newPosition > oldPosition){
        count += 1;        
     }
    else if(newPosition < oldPosition){
        count -= 1;        
     }
    oldPosition = newPosition;
    if(count < 0){
      count = 0;
    }
    else if(count > 3){
      count = 3;
    }
    clear_fle();
    lcd.setCursor(0,count);
    lcd.print(char(10));
    Serial.println(count);

    
  }
}

else if(seguro == 2){
  long newPosition = myEnc.read()/4;
  sensor.getAcceleration(&ax, &ay, &az);
  accel_ang_x=atan(ax/sqrt(pow(ay,2) + pow(az,2)))*(180.0/3.14159265358979);
  accel_ang_x = accel_ang_x + x;
  if (newPosition != oldPosition) {
    if(newPosition < oldPosition){
      countG --;
    }
    else if(newPosition > oldPosition){
      countG ++;
    }
    oldPosition = newPosition;
    if(countG < 0){
      countG = 0;
    }
    else if(countG > 180){
      countG = 180;
    }
    clear_grados();
    Serial.println(countG);
    lcd.setCursor(9,3);
    lcd.print(accel_ang_x); 
    myser.write(countG);
    Serial.println(countG);   
     }
   }


else if(seguro == 4){
  long newPosition = myEnc.read()/4;
  if (newPosition != oldPosition) {
    if(newPosition < oldPosition){
      countP --; 
    }    
    else if(newPosition > oldPosition){
     countP ++;
    }
    oldPosition = newPosition;
    if(countP < 1){
      countP = 1;
    }
    else if(countP > 3){
      countP = 3;
    }
    clear_fleS();
    Serial.println(countP);
    lcd.setCursor(0,countP);
    lcd.write(10);   
     }
  }



else if(seguro == 6){
    long newPosition = myEnc.read()/4;
  if (newPosition != oldPosition) {
    if(newPosition < oldPosition){
      countS1 --; 
    }    
    else if(newPosition > oldPosition){
     countS1 ++;
    }
    oldPosition = newPosition;
    if(countS1 < 2){
      countS1 = 2;
    }
    else if(countS1 > 3){
      countS1 = 3;
    }
    clear_fle();
    Serial.println(countS1);
    lcd.setCursor(0,countS1);
    lcd.write(10);   
     }
}

else if(seguro == 7){
    long newPosition = myEnc.read()/4;
  if (newPosition != oldPosition) {
    if(newPosition < oldPosition){
      countS2 --; 
    }    
    else if(newPosition > oldPosition){
     countS2 ++;
    }
    oldPosition = newPosition;
    if(countS2 < 2){
      countS2 = 2;
    }
    else if(countS2 > 3){
      countS2 = 3;
    }
    clear_fle();
    Serial.println(countS2);
    lcd.setCursor(0,countS2);
    lcd.write(10);   
     }
}

else if(seguro == 8){
    long newPosition = myEnc.read()/4;
  if (newPosition != oldPosition) {
    if(newPosition < oldPosition){
      countS3 --; 
    }    
    else if(newPosition > oldPosition){
     countS3 ++;
    }
    oldPosition = newPosition;
    if(countS3 < 2){
      countS3 = 2;
    }
    else if(countS3 > 3){
      countS3 = 3;
    }
    clear_fle();
    Serial.println(countS3);
    lcd.setCursor(0,countS3);
    lcd.write(10);   
     }
}

else if(seguro == 9){
  long newPosition = myEnc.read()/4;
  if (newPosition != oldPosition) {
    if(newPosition < oldPosition){
      countP1 -= 0.1; 
    }    
    else if(newPosition > oldPosition){
     countP1 += 0.1;
    }
    oldPosition = newPosition;
    if(countP1 < -10){
      countP1 = -10;
    }
    else if(countP1 > 10){
      countP1 = 10;
      }
      clear_pasos();
      lcd.setCursor(7,3);
      lcd.print(countP1);
     }
    }



else if(seguro == 10){
  long newPosition = myEnc.read()/4;
  if (newPosition != oldPosition) {
    if(newPosition < oldPosition){
      countP2 -= 1; 
    }    
    else if(newPosition > oldPosition){
     countP2 += 1;
    }
    oldPosition = newPosition;
    if(countP2 > 10){
      countP2 = 10;
      }
    else if(countP2 < -10){
      countP2 = -10;
    }
      clear_pasos();
      Serial.println(countP2);
      lcd.setCursor(7,3);
      lcd.print(countP2);
     }
    }


else if(seguro == 11){
  long newPosition = myEnc.read()/4;
  if (newPosition != oldPosition) {
    if(newPosition < oldPosition){
      countP3 -= 2; 
    }    
    else if(newPosition > oldPosition){
     countP3 += 2;
    }
    oldPosition = newPosition;
    if(countP3 < -10){
      countP3 = -10;
    }
    else if(countP3 > 10){
      countP3 = 10;
      }
      clear_pasos();
      Serial.println(countP3);
      lcd.setCursor(7,3);
      lcd.print(countP3);
     }
    }

    
  }
