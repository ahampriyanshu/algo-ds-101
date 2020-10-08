#include<graphics.h>

int main()
{
	int i,j,a[101],gd,gm;
	float s=6.0;
	char text[80];
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setbkcolor(15);
	cleardevice();
	setcolor(0);
	settextstyle(0,0,3);
	line(0,350,1400,350);
	delay(2000);
	a[0]=0; 
	for(i=1;i<=100;i++)
	{		
		j=i;
		if(a[i-1]-i>0)
		{
			for(j=i;j>0;j--)
			{
				if(a[j]==a[i-1]-i)
					break;
			}
		}		
		if(j==0)
			a[i]=a[i-1]-i;
		else
			a[i]=a[i-1]+i;
		sprintf(text,"Recaman(%d) = %d   ",i,a[i]);
		outtextxy(0,0,text);
		if(i%2==1)
			arc((a[i]+a[i-1])/2.0*s,350,0,180,abs(a[i]-a[i-1])/2.0*s);
		else
			arc((a[i]+a[i-1])/2.0*s,350,180,360,abs(a[i]-a[i-1])/2.0*s);		
		Sleep(500);
	}
	getch();
	closegraph();
	return 0;
}
