/*
  Timer.h - Library for basic timer usage.
  Created by Wim Rademaker, January 10, 2016.
  Released into the public domain.
*/
#ifndef timer_h
#define timer_h

#include "Arduino.h"

	class timer
	{
	  public:
		timer(long t);
		void set(long t);
		void reset();
		void start();
		int get();
		long status();
	  private:
		long _t;
		long _timerHelpFlag;
	};

#endif
