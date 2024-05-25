/*#include<reg51.h>

void timer0_isr (void) interrupt 1{
	P1= ~P1;
	TH0 = 0XFC;
	TL0 = 0X67;
}

void main(){
	TMOD = 0X01;
	IE = 0X82;
	TH0 = 0XFC;
	TL0 = 0X67;
	TR0 = 1;
	while(1);
}*/

/*#include<reg51.h>

void timer0_isr (void) interrupt 3{
	P1= ~P1;
	TH0 = 0XFC;
	TL0 = 0X67;
}

void main(){
	TMOD = 0X01;
	IE = 0X88;
	TH0 = 0XFC;
	TL0 = 0X67;
	TR0 = 1;
	while(1);
}*/


/*#include<reg51.h>
unsigned int x=0;

void timer0_isr (void) interrupt 1{
	if(x==0){
		P1= 0X00;
		TH0 = 0XFE;
		TL0 = 0XEC;
		x=1;
	}
	else if(x==1){
		P1=0XFF;
		TH0=0XFD;
		TL0=0X7B;
		x=0;
	}
}
void main(){
	TMOD = 0X01;
	IE = 0X82;
	TH0 = 0XFD;
	TL0 = 0X7B;
	TR0 = 1;
	while(1);
}*/

/*#include<reg51.h>
unsigned int i,j;

void Delay(int t){
	for(i=0;i<t;i++){
		for(j=0;j<t;j++){
			;
		}
	}
}

void ex0_isr (void) interrupt 0{
	P1= ~P1;
	Delay(500);
}

void main(){
	IE=0X81;
	while(1);
}*/

#include<reg51.h>
unsigned int i,j;

void Delay(int t){
	for(i=0;i<t;i++){
		for(j=0;j<t;j++){
			;
		}
	}
}

void ex0_isr (void) interrupt 2{
	P1= ~P1;
	Delay(500);
}

void main(){
	IE=0X84;
	while(1);
}