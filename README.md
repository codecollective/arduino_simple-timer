#Simple non blocking delay timer for arduino


Here's an example:

```
//Include the lib
#include <timer.h>

//Initialise your timers
timer t1(1000); //time im ms 
timer t2(100); //time in ms

void setup()
{

}

void loop(){
	//use them
	if(t1.get() == true){
		led_val = !led_val;
		digitalWrite(rd_pin, !led_val);

		//Change the timer time depending on the led state 
		if(led_val == HIGH){
		  t1.set(2000); //Change timer settin to 2 seconds
		}else{
		  t1.set(100); //Change timer setting to 0.1 seconds
		}
	}

	if(t2.get() == true){
		Do someting else .......
	}
}

```
