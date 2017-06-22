#include "main.h"

extern int8u lcdptr;

int main(void)
{
	int16u adcvalue, RefWeight;
	char tmpstr[10];
	
	init();
	
	RefWeight = adcget(0);

	while (TRUE) {
		
		
		set_sleep_mode(SLEEP_MODE_IDLE);
		sleep_mode();
		
		if (AppFlags.Meas == TRUE) {
			if (adcget(0) >= (RefWeight + WEIGHT_THESHOLD)) {
					buzon();
					GSMsndmsg(PhNum, MSG);
					moton();
					dlyms(5000);
					motoff();
					ledon();
					StopTmr();
					set_sleep_mode(SLEEP_MODE_PWR_DOWN);
					sleep_mode();
			} 
			AppFlags.Meas = FALSE;
		}
	}
	return 0;
}
static void init(void)
{
	buzinit();
	ledinit();
	beep(2,100);
	motorinit();
	lcdinit();
	adcinit();
	uartinit();
	GSMinit();
	tmr1init();
	disptitl();
	sei();
	StartTmr();
	beep(1,100);
}
static void disptitl(void)
{
	lcdclr();
	lcdws("Life Saving SFan");
}
static void tmr1init(void)
{
	TCNT1H   = 0xD3;
	TCNT1L   = 0x00;
	TIMSK   |= _BV(TOIE1);			//ENABLE OVERFLOW INTERRUPT
	TCCR1A   = 0x00;					
	TCCR1B  |= _BV(CS10) | _BV(CS11); /* PRESCALAR BY 16 */
}

/* overflows at every 100msec */
ISR(TIMER1_OVF_vect) 
{ 
	static int8u i,j;

	TCNT1H = 0xD3;
	TCNT1L = 0x00;
	
	if (++i >= 50) 
		 i = 0;
	
	if (AppFlags.Meas == 0 && ++j >= 10) {
		AppFlags.Meas = 1;  /* set flag to Measure every 1 seconds */
		j = 0;
	}
	
	switch(i) {
		case 0: case 2: ledon(); break;
		case 1: case 3: ledoff(); break;
	} 
	/* put in sleep */
	
}


