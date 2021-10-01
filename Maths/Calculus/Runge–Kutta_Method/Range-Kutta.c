#include<math.h>
int compare_float(float x, float y)
{
	float val=0.0001f;
   if(fabs(x - y) < val)
      return 1; //they are same
      return 0; //they are not same
}
// for the equation 2xy +e^x/x^2+x*e^x
float equation(float x,float y)
{
	float val=0;
	val=(2*x*y+pow(2.71828,x))/(pow(x,2)+x*pow(2.71828,x));
	return(val);
}
float next(float x,float y,float h)
{
	float k[4];
	k[0]=h*equation(x,y);
	k[1]=h*equation(x+0.5*h,y+0.5*k[0]);
	k[2]=h*equation(x+0.5*h,y+0.5*k[1]);
	k[3]=h*equation(x+h,y+k[2]);
	k[0]=(k[0]+2*k[1]+2*k[2]+k[3])/6;
	y=y+k[0];
	return(y);
}
int main()
{
	float xg,yg,yf,xgf,h;
	printf("Enter the given X value: ");
	scanf("%f",&xg);
	printf("Enter corresponding Y value: ");
	scanf("%f",&yg);
	printf("Enter the X value which value have to be find: ");
	scanf("%f",&xgf);
	printf("Enter the h value : ");
	scanf("%f",&h);
	while(1)
	{
		yg=next(xg,yg,h);
		xg=xg+h;
		if(compare_float(xg,xgf))
		{
			break;
		}
	}
	printf("The value of y(%f) is : %f",xgf,yg);
}
