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

int timer::get(){
  long ms = millis() - timerHelpFlag;
  
  if(ms >= _t){
    this->reset();
    return true;
  }else{
    return false;
  }
}

void timer::set(long t){
 	_t = t;
	this->reset();
}

void timer::start(){
    this->reset();
}

void timer::reset(){
    timerHelpFlag = millis();
}
