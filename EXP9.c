/*#include<reg51.h>

void timer_delay(void);

void main(){
	P1=0x00;
	while(1){
		P1=0xff;
		timer_delay();
		P1=0x00;
		timer_delay();
	}
}

void timer_delay(void){
	TMOD=0x01;
	TH0=0xfc;
	TL0=0x67;
	TR0=1;
	while(TF0==0){
		;
	}
	TF0=0;
	TR0=0;
}*/

/*#include<reg51.h>
void delay(void);
sbit led = P1^1;
void main()
{
	while(1)
	{
		led=1;
		delay();
		led=0;
		delay();
	}
}
void delay(void)
{
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x67;
	TR0=1;
	while(TF0 == 0);
	TF0=0;
	TR0=0;
}*/
/*#include<reg51.h>
void delay(void);
sbit led = P1^1;
sbit toggle = P2^0;
void main()
{
	while(1)
	{
		if (toggle == 1)
		{
			led=1;
			delay();
			led=0;
			delay();
		}
	}
}
void delay(void)
{
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x67;
	TR0=1;
	while(TF0 == 0);
	TF0=0;
	TR0=0;
}*/

#include<reg51.h>
void t_on(int, int);
void t_off(int, int);
sbit sw1 = P2^0;
sbit sw2 = P2^1;
sbit sw3 = P2^2;
sbit sw4 = P2^3;
sbit led1 = P1^0;
sbit led2 = P1^1;
sbit led3 = P1^2;
sbit led4 = P1^3;
void main()
{
	while(1)
		{
			if (sw1==1)
			{
				led1=1;
				t_on(0XFF,0X76);
				led1=0;
				t_off(0XFE,0XBD);
			}
			else if (sw2==1)
			{
				led2=1;
				t_on(0XFD,0X7B);
				led2=0;
				t_off(0XFE,0XEB);
			}
			else if (sw3==1)
			{
				led3=1;
				t_on(0XFD,0XD7);
				led3=0;
				t_off(0XFA,0XF6);
			}
			else if (sw4==1)
			{
				led4=1;
				t_on(0XFC,0XC2);
				led4=0;
				t_off(0XFF,0XA4);
			}
		}
	}
void t_on(int th_on, int tl_on)
{
	TMOD=0x10;
	TH1=th_on;
	TL1=tl_on;
	TR1=1;
	while(TF1 == 0);
	TF1=0;
	TR1=0;
}
void t_off(int th_off, int tl_off)
{
	TMOD=0x10;
	TH1=th_off;
	TL1=tl_off;
	TR1=1;
	while(TF1 == 0);
	TF1=0;
	TR1=0;
}




