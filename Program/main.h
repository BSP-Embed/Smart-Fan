#ifndef MAIN_H
#define MAIN_H

/* comment the below line for release */
//#define TESTING

#include "includes.h"

#ifdef TESTING
	#define PhNum	 "9164442653"
#else
	#define PhNum	 "7204605185"
#endif

const char *MSG = "Person is trying to Hang Over the Fan. Please save him immediately.";

struct  {
	volatile int8u Meas:1;
}AppFlags;

//DEFINE CONSTANT
#define WEIGHT_THESHOLD			2		/* in 100 grams */

//DEFINE MACROS
#define StartTmr()			TCCR0  	|= _BV(CS01)
#define StopTmr()			TCCR0  	&= ~_BV(CS01)


//FUNCTION PROTOTYPES
static void		 init		(void);
static void 	 disptitl 	(void);
static void 	tmr1init	(void);

#endif
