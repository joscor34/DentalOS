void inicio(){
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("    DentalOS ");
  lcd.setCursor(4,1);
  lcd.print("Version: 1.9.9");
  lcd.setCursor(6,2);
  lcd.print(char(3));
  lcd.print(char(4));
  lcd.print(char(5));
  lcd.print(char(6));
  lcd.print(char(7));
  lcd.print(char(8));
  lcd.print(char(9));
  lcd.setCursor(4,3);
  lcd.print("Iniciando");
  delay(600);
  lcd.setCursor(13,3);
  lcd.print(".");
  delay(300);
  lcd.setCursor(14,3);
  lcd.print(".");
  delay(300);
  lcd.setCursor(15,3);
  lcd.print(".");
  delay(1000);
  
  lcd.clear();
}

void menu1(){
  lcd.setCursor(1,0);
  lcd.print("Blue IVO");
  lcd.setCursor(1,1);
  lcd.print("Smart DENTS");
  lcd.setCursor(1,2);
  lcd.print("TFZ LED");
  lcd.setCursor(1,3); 
  lcd.print("Creditos");

}
  
void seguro_lcd(){
  lcd.setCursor(2,0);
  lcd.print("asegurate que es");
  lcd.setCursor(1,1);
  lcd.print("la lampara correcta");
  seguro = 1;
  lcd.setCursor(7,3);
  lcd.write(10);
  lcd.setCursor(8,3);
  lcd.print("Si");
  lp = 1;
}



void clear_fle(){
 lcd.setCursor(0,0);
 lcd.print(" ");
 lcd.setCursor(0,1);
 lcd.print(" ");
 lcd.setCursor(0,2);
 lcd.print(" ");
 lcd.setCursor(0,3);
 lcd.print(" ");
}

void clear_grados(){
  lcd.setCursor(8,3);
  lcd.print("    ");
}

void cali_ser(){
  //lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("Moviendo");
  lcd.setCursor(6,1);
  lcd.print("El angulo");
  lcd.setCursor(5,2);
  lcd.print("+");
  lcd.setCursor(5,3);
  lcd.print(char(11));
  lcd.setCursor(14,2);
  lcd.print("-");
  lcd.setCursor(14,3);
  lcd.print(char(10)); 
  seguro = 2;
  men_act = 2;
}
//**************************************************************
void calibrar1(){
 digitalWrite(13,LOW);
 x = -6;
 myser.write(30);
 lcd.setCursor(5,0);
 lcd.print("calibrando");
 lcd.setCursor(0,1);
 digitalWrite(dirPin, LOW);
  // Spin the stepper motor 1 revolution slowly:
   while(digitalRead(12)!= 1){
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(600);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(600);
  }
  //**********************************
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 100; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(600);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(600);
  }
  //**********************************
  digitalWrite(13,HIGH);
  delay(300);
  for(int i = 30; i <= 57; i ++){
     myser.write(i);
     delay(20);
  }
  digitalWrite(13,LOW);
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 670; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(600);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(600);
  }
  //*********************************
  digitalWrite(13,1);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.write(10);
//*******************************************
 menu_cali1();
 countG = 57;
 seguro = 6;
 count = 0;
 count2 = 0;
 ser = 0;
 ms = 1;
//*******************************************
 
}

void calibrar2(){
digitalWrite(13,LOW);
 x = -3;
 myser.write(30);
 lcd.setCursor(5,0);
 lcd.print("calibrando");
 lcd.setCursor(0,1);
 digitalWrite(dirPin, LOW);
  // Spin the stepper motor 1 revolution slowly:
   while(digitalRead(12)!= 1){
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(600);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(600);
  }
  //**********************************
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 100; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(600);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(600);
  }
  //**********************************
  digitalWrite(13,HIGH);
  delay(300);
  for(int i = 30; i <= 56; i ++){
     myser.write(i);
     delay(20);
  }
  digitalWrite(13,LOW);
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 1280; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(600);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(600);
  }
  //**********************************
  digitalWrite(13,1);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.write(10);
//*******************************************
 menu_cali2();
 seguro = 7;
 count = 0;
 countG = 56;
 count2 = 0;
 ser = 0;
 ms = 2;
//*******************************************
 
}



void calibrar3(){
digitalWrite(13,LOW);
 x = 41;
 countG = 104;
 myser.write(30);
 lcd.setCursor(5,0);
 lcd.print("calibrando");
 lcd.setCursor(0,1);
 digitalWrite(dirPin, HIGH);
  // Spin the stepper motor 1 revolution slowly:
   while(digitalRead(11)!= 1){
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(600);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(600);
  //**********************************
   }
    //**********************************
   digitalWrite(dirPin, LOW);
    for (int i = 0; i < 1300; i++) {
    // These four lines result in 1 step:
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(600);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(600);
  }
  //**********************************
    digitalWrite(13,HIGH);
    delay(300);
    for(int i = 30; i <= 102; i ++){
      myser.write(i);
      delay(20);
  }
  //**********************************
  digitalWrite(13,1);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.write(10);

//*******************************************
 menu_cali3();
 seguro = 8;
 count = 0;
 count2 = 0;
 ser = 0;
 ms = 3;
//*******************************************
 
}





void mover_motor(){
  lcd.setCursor(0,0);
  lcd.print("Mover en escala de:");
  lcd.setCursor(1,1);
  lcd.print("0.1mm");
  lcd.setCursor(1,2);
  lcd.print("1mm");
  lcd.setCursor(1,3);
  lcd.print("2mm");
  Serial.print("ms: ");
  Serial.println(ms);
  seguro = 4;
}

void creditos(){
  lcd.setCursor(0,0);
  lcd.print("Creador del programa");
  lcd.setCursor(4,1);
  lcd.print("Jose Eduardo");
  lcd.setCursor(3,2);
  lcd.print("Esteva Cordova");
  lcd.setCursor(6,3);
  lcd.print(char(3));
  lcd.print(char(4));
  lcd.print(char(5));
  lcd.print(char(6));
  lcd.print(char(7));
  lcd.print(char(8));
  lcd.print(char(9));
  seguro = 5;
}


void menu_escalas(){
  lcd.setCursor(1,0);
  lcd.print("0.1 mm");
  lcd.setCursor(1,1);
  lcd.print("1 mm");
  lcd.setCursor(1,2);
  lcd.print("2 mm");
  men_act = 3;
}

void menu_cali1(){
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("Blue IVO");
  lcd.setCursor(1,2);
  lcd.print("Cambiar angulo");
  lcd.setCursor(1,3);
  lcd.print("Cambiar altura");
  lp = 1;
}


void menu_cali2(){
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("Smart DENTS");
  lcd.setCursor(1,2);
  lcd.print("Cambiar angulo");
  lcd.setCursor(1,3);
  lcd.print("Cambiar altura");
  lp = 1;
}

void menu_cali3(){
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("TFZ LED");
  lcd.setCursor(1,2);
  lcd.print("Cambiar angulo");
  lcd.setCursor(1,3);
  lcd.print("Cambiar altura");
  lp = 1;
}

void clear_fleS(){
 lcd.setCursor(0,1);
 lcd.print(" ");
 lcd.setCursor(0,2);
 lcd.print(" ");
 lcd.setCursor(0,3);
 lcd.print(" ");
}

void mover_01mm(){
  lcd.setCursor(1,0);
  lcd.print("Moviendo en escala");
  lcd.setCursor(8,1);
  lcd.print("0.1mm");
  lcd.setCursor(5,2);
  lcd.print("-");
  lcd.setCursor(5,3);
  lcd.print(char(11));
  lcd.setCursor(14,2);
  lcd.print("+");
  lcd.setCursor(14,3);
  lcd.print(char(10)); 
  lcd.setCursor(8,3);
  seguro = 9;
  men_act = 1;
}

void mover_1mm(){
  lcd.setCursor(1,0);
  lcd.print("Moviendo en escala");
  lcd.setCursor(8,1);
  lcd.print("1mm");
  lcd.setCursor(5,2);
  lcd.print("-");
  lcd.setCursor(5,3);
  lcd.print(char(11));
  lcd.setCursor(14,2);
  lcd.print("+");
  lcd.setCursor(14,3);
  lcd.print(char(10)); 
  lcd.setCursor(8,3);
  seguro = 10;
  men_act = 1;
}
void mover_2mm(){
  lcd.setCursor(1,0);
  lcd.print("Moviendo en escala");
  lcd.setCursor(8,1);
  lcd.print("2mm");
  lcd.setCursor(5,2);
  lcd.print("-");
  lcd.setCursor(5,3);
  lcd.print(char(11));
  lcd.setCursor(14,2);
  lcd.print("+");
  lcd.setCursor(14,3);
  lcd.print(char(10)); 
  lcd.setCursor(8,3);
  seguro = 11;
  men_act = 1;
}

void clear_pasos(){
  lcd.setCursor(8,3);
  lcd.print("     ");
} 
