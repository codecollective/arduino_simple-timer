/*
  Timer.cpp - Library for basic timer usage.
  Created by Wim Rademaker, January 10, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "timer.h"


timer::timer(long t){
	_t = t;
	_timerHelpFlag = 0;
}

//Check if the timer allready run out, it will return `true` if it has run out, else it wil return `false`
int timer::get(){
  long ms = millis() - _timerHelpFlag;

  if(ms >= _t){
    this->reset();
    return true;
  }else{
    return false;
  }
}

//Get te current processed time
long timer::status(){
	long ms = millis() - _timerHelpFlag;
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
    _timerHelpFlag = millis();
}
