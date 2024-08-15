#include<reg51.h>
void delay();
void delay1();

void main(){
	P1=0x00;
	while(1){
		P1=0x00;
		delay();
		P1=0xFF;
		delay1();
	}
}

void delay(){
	TMOD=0x01;
	TH0= 0xFC;
	TL0=0x17;
	TR0=1;
	while(TF0==0){}
		TF0=0;
		TR0=0;
}

void delay1(){
	TMOD=0x01;
	TH0= 0xF8;
	TL0=0x30;
	TR0=1;
	while(TF0==0){}
		TF0=0;
		TR0=0;
}