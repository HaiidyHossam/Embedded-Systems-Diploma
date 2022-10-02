#include "STDTYPE.h"
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "avr/delay.h"
#include <stdio.h>

//commands like read clear write
void CLCD_VidSendCommand(u8 Copy_u8Command){
	
	/* set RS pin as low */
	DIO_VidSetPinValue(CLCD_CTRL_PORT ,LOW,CLCD_RS_PIN);
	
	/* set RW pin as low to write*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT ,LOW,CLCD_RW_PIN);
	
	/* send command to data pins D0 to D7 */
	//full port -- the value is the command
	DIO_VidSetPortValue(CLCD_DATA_PORT, Copy_u8Command);
	
	/*set enable pulse */
	DIO_VidSetPinValue(CLCD_CTRL_PORT ,HIGH,CLCD_E_PIN);
	
	/* delay 34an el pulse */
	_delay_ms(3);
	
	/*CLR Enable Pin*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT ,LOW,CLCD_E_PIN);
}

void CLCD_VidSendData(u8 Copy_u8Data){
	/* set RS pin as high */
	DIO_VidSetPinValue(CLCD_CTRL_PORT ,HIGH,CLCD_RS_PIN);
	
	/* set RW pin as low to write*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT ,LOW,CLCD_RW_PIN);
	
	/* send data to data pins D0 to D8 */
	DIO_VidSetPortValue(CLCD_DATA_PORT, Copy_u8Data );
	
	/*set enable pulse */
	DIO_VidSetPinValue(CLCD_CTRL_PORT ,HIGH,CLCD_E_PIN);
	
	/* delay 34an el pulse */ 
	_delay_ms(3);
	
	/*CLR Enable Pin*/
	DIO_VidSetPinValue(CLCD_CTRL_PORT ,LOW,CLCD_E_PIN);
}

void CLCD_VidInit(void)
{
//data sheet set of commands .. because rs is 0 in data sheet
_delay_ms(40);
/*function set*/
//n means when 0 one line and when 1 two lines
//f font size when 1 means 5 *11 and when 0 means 5*8
CLCD_VidSendCommand (0b00111111);
 _delay_ms(40);

/*display on/off*/
//d display enable if 0 disabled
//c cursor enable if 0 disabled
//b blinking -- if 0 off cursor 
CLCD_VidSendCommand (0b00001100);
_delay_ms(40);

/*display clear */
CLCD_VidSendCommand (0b00000001);
_delay_ms(2);
/*entry set mode */
CLCD_VidSendCommand (0b00000110);
_delay_ms(40);
}


/*going to any place  in LCD */

void CLCD_VidGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos){
	u8 Local_u8Address =0;
	
	if(Copy_u8XPos ==0){
		Local_u8Address =Copy_u8YPos;
	}
	else if(Copy_u8XPos ==1){
		//0x40 is written in data --> when we are in second line
		Local_u8Address =0x40+Copy_u8YPos;
	}
	//address of DDram says that rs=0 so when we set it we will send command
	//0b10000000=128 dec
	CLCD_VidSendCommand (128+Local_u8Address);	
	
}
//using clcd custom character generator
void CLCD_VidWriteSpecialCharacter(u8 *Copy_pu8Pattern, u8 Copy_u8PatternNumber,u8 Copy_u8XPOS,u8 Copy_u8YPOS){
	u8 Local_u8Address =0;
	//Copy_u8PatternNumber maybe 0,1,2 -- 7
	//CGram consists of 8 locations so if i wanna get the address:
	Local_u8Address =8 *Copy_u8PatternNumber;
	//go to this address by the key of CGram "its address 64"
	CLCD_VidSendCommand (64+ Local_u8Address);
	//write on this address
	for(u8 i=0; i<8;i++){
		//byte by byte for each location of the 8 ones
		//send data to cgram it won't appear on lcd
		CLCD_VidSendData (Copy_pu8Pattern[i]);
	}
	//3awz a5rog mn CGRAm w aro7 ll DDRam 34an a write on LCD
	CLCD_VidGotoXY(Copy_u8XPOS,Copy_u8YPOS);
	//show data of each pattern on the lcd
	CLCD_VidSendData (Copy_u8PatternNumber);
}


/* Send string to LCD function */


void LCD_String (u8 *str)		
{
	
	for(u8 i=0;str[i]!='\0';i++)		// Send each char of string till the NULL 
	{
		CLCD_VidSendData(str[i]);
	}
}

void LCD_Clear()
{
	CLCD_VidSendCommand (0x01);		// Clear display 
	_delay_ms(2);
	CLCD_VidSendCommand (0x80);		// Cursor at home position so call DDRAm
}


void LCD_printNumber(int num)
{
	u8 str[10];
itoa(num, str, 10);  // here 10 means decimal
	LCD_String(str);
}

