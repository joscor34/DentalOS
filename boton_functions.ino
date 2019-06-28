void singleClick(){
  lcd.clear();
  if(ser == 1){
    calibrar1();
    Serial.println("Se esta calibrando la lampara 1");
    ms = 1;
    Serial.print("ms es: ");
    Serial.println(ms);
    }

  else if(ser == 2){
    calibrar2();
    ms = 2;
    Serial.print("ms es: ");
    Serial.println(ms);
    }

  else if(ser == 3){
    calibrar3();
    ms = 3;
    Serial.print("ms es: ");
    Serial.println(ms);
   }

   else if(countP == 1){
    mover_01mm();
   }
   else if(countP == 2){
    mover_1mm();
   }
   else if(countP == 3){
    mover_2mm();
   }
   
 else if(countS1 == 2 || countS2 == 2 || countS3 == 2){
    cali_ser(); 
 }


 else if(countS1 == 3 || countS2 == 3 || countS3 == 3){
    mover_motor(); 
 }
  else if(count == 0 && ser == 0){
    lcd.clear();
    seguro_lcd();
    ser = 1;
    Serial.print(ser);
  }
  else if( count == 1 && ser == 0){
    lcd.clear();
    seguro_lcd();
    ser = 2;
    Serial.print(ser);
  }

  else if( count == 2 && ser == 0){
    lcd.clear();
    seguro_lcd();
    ser = 3;
    Serial.print(ser);
  }
 
 else if(count == 3 && ser == 0){
   creditos();
  }
}

void doubleClick(){
  Serial.println("doble hate");
  Serial.println(ms);
  if(men_act == 1 && ms == 2 || men_act == 2 || men_act == 3){
    lcd.clear();
      lp = 0;
    menu_cali2();
    seguro = 6;
    countS1 = 0;
    ms = 0;
    countP = 0; 
    Serial.println("te odias demasiado2"); 
    men_act = 0;
  }
  else if(men_act == 1 && ms == 1 || men_act == 2 || men_act == 3){
    lcd.clear();
      lp = 0;
    menu_cali1();
    seguro = 6;
    countS1 = 0;
    ms = 0;
    countP = 0; 
    Serial.println("te odias demasiado1"); 
    men_act = 0;
  }

  else if(men_act == 1 && ms == 3 || men_act == 2 || men_act == 3){
    lcd.clear();
      lp = 0;
    menu_cali3();
    seguro = 6;
    countS1 = 0;
    ms = 0;
    countP = 0; 
    Serial.println("te odias demasiado3"); 
    men_act = 0;
  }
  else if(lp == 1){
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(10);
  menu1();
  countS1 = 0;
  countS2 = 0;
  countS3 = 0;
  seguro = 0;
  count = 0;
  countP1 = 0;
  countP2 = 0;
  countP3 = 0;
  count2 = 0;
  ser = 0;
}
}
