#include <timer.h>

timer t1(1000);
timer t2(100);

int bu_pin = 6;
int rd_pin = 5;
int led_val = HIGH;

void setup()
{
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(bu_pin, OUTPUT);
  pinMode(rd_pin, OUTPUT);
}


void loop(){

  if(digitalRead(10) == HIGH) {
      digitalWrite(bu_pin, HIGH);

      //Wait until t1 his time runs out
      if(t1.get() == true){
        led_val = !led_val;
        digitalWrite(rd_pin, !led_val);

        //Change the timer time depending on the led state 
        if(led_val == HIGH){
          t1.set(2000);
        }else{
          t1.set(100);
        }
      }
  }

  //Synchrone blinking
  if(digitalRead(16) == HIGH) {
      if(t2.get() == true){
        led_val = !led_val;
        digitalWrite(bu_pin, !led_val);
        digitalWrite(rd_pin, led_val);
     }
  }

}

