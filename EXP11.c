//sin wave
/*#include<reg51.h>
#include<math.h>
#include<intrins.h>
sbit DAC_WR=P3^0;
unsigned int i=0,x=0,count;
unsigned int dac_cntr;
unsigned int xdata arr[360];
void main()
{
	TMOD=0x01;
	IE=0x82;
	TH0=0xFF;
	TL0=0xCC;
	TR0=1;
	for(i=0;i<360;i++)
	{
		count=(sin(i*3.14/180)*127)+128;
		arr[i]=count;
	}	
	while(1)
	{
		if(x==1)
		{
			x=0;
			DAC_WR=1;
			dac_cntr++;
			P1=arr[dac_cntr];
			DAC_WR=0;
			if(dac_cntr==359)
			{
				dac_cntr=0;
			}
		}
	}
}
void timer0_int() interrupt 1
{
	x=1;
	TH0=0xFF;
	TL0=0xCC;
	return;	
}*/


//stair wave
/*#include<reg51.h>
#include<math.h>
#include<intrins.h>
sbit DAC_WR=P3^0;
unsigned int i=0,x=0,count;
unsigned int dac_cntr;
unsigned int xdata arr[18]={128,160,192,224,255,255,224,192,160,128,96,64,32,1,1,32,64,96};
void main()
{
	TMOD=0x01;
	IE=0x82;
	TH0=0xFC;
	TL0=0x00;
	TR0=1;
	for(i=0;i<15;i++)
	{
		count=((i++)+128);
  	arr[i]=count;
	}		
	while(1)
	{
		if(x==1)
		{
			x=0;
			DAC_WR=1;
			dac_cntr++;
			P1=arr[dac_cntr];
			DAC_WR=0;
			if(dac_cntr==17)
			{
				dac_cntr=-1;
			}
		}
	}
}
void timer0_int() interrupt 1
{
x=1;
TH0=0xFC;
TL0=0x00;
return;	
}*/

//unidirectional triangle
/*#include <reg51.h>
#include <math.h>
sbit DAC_WR=P3^0;
unsigned int i=0,x=0,z=0;
unsigned int dac_cntr = 0;
void main()
{
	TMOD=0X01;
	IE=0X82;
	TH0=0XFF; // Timer value for 39*10^(-6) sec =  [10*10^(-3)/256]
	TL0=0X88;
  TR0=1;		
	while(1)
	{
		if(x==1)
		{   
			x=0;			
			if(z==0)				
			{
				DAC_WR=1;
        P1=dac_cntr;
        dac_cntr++;
        DAC_WR=0;
        if(dac_cntr==255)
	      {
					z=1;
	      }
			}					 
      if(z==1)
	    {
				DAC_WR=1;
				P1=dac_cntr;
				dac_cntr--;
				DAC_WR=0;
				if(dac_cntr==0)
				{
					z=0;
				}
			}
		}
	}
}
void timer0_int() interrupt 1
{
	 x=1;
	TH0=0xFF;
	TL0=0x88;
	 return;
}*/

//bidirectional triangle

#include <reg51.h>
#include <math.h>
sbit DAC_WR=P3^0;
unsigned int i=0,x=0,z=0;
unsigned int dac_cntr;
void main()
{
	TMOD=0X01;
	  IE=0X82;
	  TH0=0XFF;   // Timer value for 39*10^(-6) second [10*10^(-3)/256]
	  TL0=0X88;
                TR0=1;		
	  dac_cntr=127;
		while(1)
		{
		if(x==1)
		  {
			   x=0;
				if(z==0)
{
          DAC_WR=1;
          P1=dac_cntr;	
         dac_cntr++;
         DAC_WR=0;
           if(dac_cntr==255)
	         {
		 z=1;
	         }
 }					 
              if(z==1)
	      {
		DAC_WR=1;
		P1=dac_cntr;
                             dac_cntr--;
	              P1=dac_cntr;
			  if(dac_cntr==0)
				  {
					z=2;
				   }
		}
			              if(z==2)
					{
					        DAC_WR=1;
				                            P1=dac_cntr;
                dac_cntr++;
                  DAC_WR=0;
	    if(dac_cntr==127)
		{
			z=0;
		}
                    }
	  }
	}		
} 

void timer0_int() interrupt 1
{
	 x=1;
	TH0=0xFF;
	TL0=0x88;
	 return;
}




