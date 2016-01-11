/*
  Timer.cpp - Library for basic timer usage.
  Created by Wim Rademaker, January 10, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "timer.h"

long timerHelpFlag = 0;

timer::timer(long t)
{
	_t = t;
}

//Check if the timer allready runn out, it will return `true` if it has run out, else it wil return `false`
int timer::get(){
  long ms = millis() - timerHelpFlag;

  if(ms >= _t){
    this->reset();
    return true;
  }else{
    return false;
  }
}

//Get te current procecced time
long timer::status(){
	long ms = millis() - timerHelpFlag;
	return ms;
}

//Set a new timer value
void timer::set(long t){
 	_t = t;
	this->reset();
}

//Start a new timer sequence
void timer::start(){
    this->reset();
}

//Reset the current timer time
void timer::reset(){
    timerHelpFlag = millis();
}
