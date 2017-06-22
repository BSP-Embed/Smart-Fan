#ifndef _APP_H
#define _APP_H

/* Main settings */


#define EEPROM_DISPLAY				0

/******** MAIN CONFIGURATION ENDS ****************/

/* LCD CONFIGURATION */
#define LCD_DDR           	   		DDRB 
#define LCD_DATA_PORT          		PORTB
#define LCD_ENABLE_PIN        		PB3 
#define LCD_REGISTER_SELECT_PIN     PB2
#ifdef TESTING
	#define DISPLAY_INIT				0
#else
	#define DISPLAY_INIT				1
#endif
#define LCD_NSCRL					3
#define FLOAT_T0_STRING				1
#define DECIMAL_PRECISION			10

/******** LCD CONFIGURATION ENDS ****************/

/* MOTOR CONFIGURATION */

#define MOTOR_DDR				DDRC
#define MOTOR_PORT				PORTC
#define MOT_ANODE_PIN			PC2
#define MOT_CATHODE_PIN			PC3

/******** LCD CONFIGURATION ENDS ****************/


/* BUZZER: CONFIGURATION */
#define	BUZ_DDR						DDRC
#define	BUZ_PORT					PORTC
#define	BUZ_PIN						PC1
#define OFF_TIME					100
/******** BUZZER CONFIGURATION ENDS ****************/

/* LED: CONFIGURATION */

#define	LED_DDR			DDRC
#define	LED_PORT		PORTC
#define	LED_PIN			PC0

#define OFF_TIME		100
/******** LED CONFIGURATION ENDS ****************/

/* GSM: CONFIGURATION */

#define MSG_START					""
#define MSG_END						". Automated SMS By: Life Saving Smart Fan."

/******** ADC CONFIGURATION ENDS ****************/
#define REF_VOL_256

/******** GSM CONFIGURATION ENDS ****************/

/******** EEPROM CONFIGURATION ****************/
#define EEPROM_DISPLAY		0

#endif
