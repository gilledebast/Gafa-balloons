/*
 *
 *
 *
 *
 * 
 *
 *
 *
 */

#include <Bridge.h>
#include <HttpClient.h>

const int GetDelay = 30000; //temps entre chaque requete
const int MoveDelay = 1000; //temps de rotation du moteur après une requete
const int ZeroDelay = 5000; //temps pour que le ballon soit à mi-hauteur

const int button_M1_pin = 13;
const int button_M2_pin = 10;
const int button_M3_pin =  9;
const int button_M4_pin =  2;

int button_M1_State = 0;
int button_M2_State = 0;
int button_M3_State = 0;
int button_M4_State = 0;

void setup() {
  setup_pin();
  Bridge.begin();
  Serial.begin(9600);
  //while (!SerialUSB);
  Serial.println("Initialise...");
  setup_motor();
  Serial.println("Ready...");
}

void loop() {  
  HttpClient client;
  client.get("http://one-billion-cat.com/gafa/index.php");

  int char_count = 0;
  while (client.available()) {
    char c = client.read();
    Serial.println(c);
    
    if(char_count == 0){
      if(c == '0'){
        M1_move(0);
      } else if(c == '1'){
        M1_move(1);
      } else if(c == '2'){
        M1_stop();
      } else if(c == 'n'){
        break;
      }
    }

    if(char_count == 1){
      if(c == '0'){
        M2_move(0);
      } else if(c == '1'){
        M2_move(1);
      } else if(c == '2'){
        M2_stop();
      }
    }

    if(char_count == 2){
      if(c == '0'){
        M3_move(0);
      } else if(c == '1'){
        M3_move(1);
      } else if(c == '2'){
        M3_stop();
      }
    }

    if(char_count == 3){
      if(c == '0'){
        M4_move(0);
      } else if(c == '1'){
        M4_move(1);
      } else if(c == '2'){
        M4_stop();
      }
    }
    
    char_count++;
  }
  Serial.flush();
  delay(GetDelay);
  stop_motors();
}

void setup_pin(){
  pinMode(button_M1_pin,INPUT);
  for(int i=3;i<9;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(button_M2_pin,INPUT);
  pinMode(button_M3_pin,INPUT);
  for(int i=11;i<13;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(button_M4_pin,INPUT);
}
