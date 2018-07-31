const int E1 =  3; ///<Motor1 Speed
const int E2 = 11; ///<Motor2 Speed
const int E3 =  5; ///<Motor3 Speed
const int E4 =  6; ///<Motor4 Speed

const int M1_pin =  4; ///<Motor1 Direction
const int M2_pin = 12; ///<Motor2 Direction
const int M3_pin =  8; ///<Motor3 Direction
const int M4_pin =  7; ///<Motor4 Direction

void M1_move(boolean Direction){
  /*M1(Direction,100);
  delay(MoveDelay);
  M1_stop();*/

  M1(Direction,100);
  int M1_zero = 0;
  int M1_MoveDelay = MoveDelay;
  while (M1_zero < 10){
    delay(10);
    M1_MoveDelay = M1_MoveDelay - 10;
    button_M1_State = digitalRead(button_M1_pin);
    if(button_M1_State == 1){
      M1_zero++;
    } else if(button_M1_State == 0){
      M1_zero = 0;
    }

    if(M1_MoveDelay < 0){
      break;
    } else if(M1_zero == 9){
      M1(0,30);
      delay(ZeroDelay);
      break;
    }
  }
  M1_stop();
}

void M1(boolean Direction, char Speed){
 if(Direction == 0){
  digitalWrite(M1_pin,LOW);
 } else {
  digitalWrite(M1_pin,HIGH);
 }
 analogWrite(E1,Speed);
}

void M1_stop(){
  analogWrite(E1,0);
}

void M2_move(boolean Direction){
  /*M2(Direction,100);
  delay(MoveDelay);
  M2_stop();*/

  M2(Direction,100);
  int M2_zero = 0;
  int M2_MoveDelay = MoveDelay;
  while (M2_zero < 10){
    delay(10);
    M2_MoveDelay = M2_MoveDelay - 10;
    button_M2_State = digitalRead(button_M2_pin);
    if(button_M2_State == 1){
      M2_zero++;
    } else if(button_M2_State == 0){
      M2_zero = 0;
    }

    if(M2_MoveDelay < 0){
      break;
    } else if(M2_zero == 9){
      M2(0,30);
      delay(ZeroDelay);
      break;
    }
  }
  M2_stop();
}

void M2(boolean Direction, char Speed){
 if(Direction == 0){
  digitalWrite(M2_pin,HIGH);
 } else {
  digitalWrite(M2_pin,LOW);
 }
 analogWrite(E2,Speed);
}

void M2_stop(){
  analogWrite(E2,0);
}

void M3_move(boolean Direction){
  /*M3(Direction,100);
  delay(MoveDelay);
  M3_stop();*/

  M3(Direction,100);
  int M3_zero = 0;
  int M3_MoveDelay = MoveDelay;
  while (M3_zero < 10){
    delay(10);
    M3_MoveDelay = M3_MoveDelay - 10;
    button_M3_State = digitalRead(button_M3_pin);
    if(button_M3_State == 1){
      M3_zero++;
    } else if(button_M3_State == 0){
      M3_zero = 0;
    }

    if(M3_MoveDelay < 0){
      break;
    } else if(M3_zero == 9){
      M3(0,30);
      delay(ZeroDelay);
      break;
    }
  }
  M3_stop();
}

void M3(boolean Direction, char Speed){
 if(Direction == 0){
  digitalWrite(M3_pin,LOW);
 } else {
  digitalWrite(M3_pin,HIGH);
 }
 analogWrite(E3,Speed);
}

void M3_stop(){
  analogWrite(E3,0);
}

void M4_move(boolean Direction){
  /*M4(Direction,100);
  delay(MoveDelay);
  M4_stop();*/

  M4(Direction,100);
  int M4_zero = 0;
  int M4_MoveDelay = MoveDelay;
  while (M4_zero < 10){
    delay(10);
    M4_MoveDelay = M4_MoveDelay - 10;
    button_M4_State = digitalRead(button_M4_pin);
    if(button_M4_State == 1){
      M4_zero++;
    } else if(button_M4_State == 0){
      M4_zero = 0;
    }

    if(M4_MoveDelay < 0){
      break;
    } else if(M4_zero == 9){
      M4(0,30);
      delay(ZeroDelay);
      break;
    }
  }
  M4_stop();
}

void M4(boolean Direction, char Speed){
 if(Direction == 0){
  digitalWrite(M4_pin,HIGH);
 } else {
  digitalWrite(M4_pin,LOW);
 }
 analogWrite(E4,Speed);
}

void M4_stop(){
  analogWrite(E4,0);
}

void stop_motors(){
  M1_stop();
  M2_stop();
  M3_stop();
  M4_stop();
}

void setup_motor(){

  int rembobiner = 1;
  int debobiner = 0;
  
  M1(rembobiner,100);
  int M1_zero = 0;
  while (M1_zero < 10){
    delay(10);
    button_M1_State = digitalRead(button_M1_pin);
    if(button_M1_State == 1){
      M1_zero++;
    } else if(button_M1_State == 0){
      M1_zero = 0;
    }
  }
  M1(debobiner,30);
  delay(ZeroDelay);
  M1_stop();

  M2(rembobiner,100);
  int M2_zero = 0;
  while (M2_zero < 10){
    delay(10);
    button_M2_State = digitalRead(button_M2_pin);
    if(button_M2_State == 1){
      M2_zero++;
    } else if(button_M2_State == 0){
      M2_zero = 0;
    }
  }
  M2(debobiner,30);
  delay(ZeroDelay);
  M2_stop();

  M3(rembobiner,100);
  int M3_zero = 0;
  while (M3_zero < 10){
    delay(10);
    button_M3_State = digitalRead(button_M3_pin);
    if(button_M3_State == 1){
      M3_zero++;
    } else if(button_M3_State == 0){
      M3_zero = 0;
    }
  }
  M3(debobiner,30);
  delay(ZeroDelay);
  M3_stop();

  M4(rembobiner,100);
  int M4_zero = 0;
  while (M4_zero < 10){
    delay(10);
    button_M4_State = digitalRead(button_M4_pin);
    if(button_M4_State == 1){
      M4_zero++;
    } else if(button_M4_State == 0){
      M4_zero = 0;
    }
  }
  M4(debobiner,30);
  delay(ZeroDelay);
  M4_stop();
}
