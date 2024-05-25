#include<reg51.h>

/*void delay(int);

void main()
{
	P1=0x00;
	while(1)
	{
		P1=0xff;
		delay(500);
		P1=0x00;
		delay(500);
	}
}
void delay(int t){
	unsigned int i,j;
	for(i=0;i<t;i++){
		for(j=0;j<t;j++){
			;
		}
	}
}*/

/*void delay(int);

void main()
{
	P1=0x00;
	while(1)
	{
		P1=0xaa;
		delay(500);
		P1=0x55;
		delay(500);
	}
}
void delay(int t){
	unsigned int i,j;
	for(i=0;i<t;i++){
		for(j=0;j<t;j++){
			;
		}
	}
}*/

/*void delay(int);

void main()
{
	P1=0x01;
	while(1)
	{
		if(P1==0x00){
			P1=0x01;
		}
		delay(500);
		P1=P1<<1;
	}
}

void delay(int t){
	unsigned int i,j;
	for(i=0;i<t;i++){
		for(j=0;j<t;j++){
			;
		}
	}
}*/

/*void delay(int);
unsigned int x;
void main()
{
	P1=0x80;
	x=P1;
	while(1)
	{
		delay(500);
		if(P1==0xff){
			P1=0x80;
		}
		else{
			P1=x|P1>>1;
		}
		x=P1;
	}
}

void delay(int t){
	unsigned int i,j;
	for(i=0;i<t;i++){
		for(j=0;j<t;j++){
			;
		}
	}
}*/

void delay(int);
unsigned int x;
void main()
{
	P1=0x01;
	x=P1;
	while(1)
	{
		delay(500);
		if(P1==0xff){
			P1=0x01;
		}
		else{
			P1=x|P1<<1;
		}
		x=P1;
	}
}

void delay(int t){
	unsigned int i,j;
	for(i=0;i<t;i++){
		for(j=0;j<t;j++){
			;
		}
	}
}