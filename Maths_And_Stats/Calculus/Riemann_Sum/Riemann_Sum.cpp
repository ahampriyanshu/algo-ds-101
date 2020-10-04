#include<stdio.h>
#include<math.h>

double F1(double x,double a){
    double f1=0.0;
    f1=(sqrt(a-pow(x,2)));
    return f1;
}

int main(){
    double a=0.0,p=0.0,q=0.0,h=0.0,x=0.0,err=0;
    int func=3,n=2;
    double power=0.0,T=0.0;
    double sum=0.0,last=0.0,difference=1.0;

    scanf("%d",&func);

    while(func!=0){
        n=2;
        scanf("%lf%lf%lf%lf",&a,&p,&q,&err);
        power=pow(10.0,-err);
        h=(q-p)/n;

        if(func==1){
            difference=1.0;
            while(difference>=power){
                h=(q-p)/n;
                sum=0.0;
                for(x=p+h;x<=q-h;x++){
                    sum+=(2*F1(x,a));
                }
                T=(h/2)*(F1(p,a)+F1(q,a)+sum);
                if(difference==1.0){
                    difference=T;
                }else{
                    difference=last-T;
                }
                last=T;
                n++;
                }
        }
    printf("%.5lf\n",T);
    scanf("%d",&func);
    }
return 0;
}
