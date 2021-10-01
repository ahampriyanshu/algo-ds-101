#include <math.h> 
#include <iostream>
#include <iomanip>

using namespace std;
/*======================================================================*/
/*===================== Runge-Kutta Method for ODE =====================*/
/*======================================================================*/



//getting dx/dt 
static double dx_dt(double t, double x)
{
    return tan(x) + 1;
}

//Formula used :
//Yn+1 = Yn  + 1/6 *(k1+2*k2+2*k3+k4) :: let interval = h  
//where k1=dx/dt(Xn,Yn)  ,k2=dx/dt((Xn+ h/2 ,Yn+k1/2 ),k3=dx/dt((Xn+ h/2 ,Yn+k2/2 ) and k4=dx/dt((Xn+ h ,Yn+k3 )

//Instead of dx/dt we can also use other differential function


void calculate_Y(double &initial_X, double final_X,double interval ,double &y ){

    int n = static_cast<int>((final_X - initial_X) /interval);

        for (int i = 0; i < n; i++)
        {
            double k1 = dx_dt(initial_X, y);
            double k2 = dx_dt(initial_X + interval / 2.0, y + interval*k1 / 2.0);
            double k3 = dx_dt(initial_X + interval/ 2.0, y + interval*k2 / 2.0);
            double k4 = dx_dt(initial_X + interval, y + interval*k3);

            y += (k1 + 2 * k2 + 2 * k3 + k4) * interval / 6.0;

            //cout << initial_X << ": " << y << endl;

            initial_X += interval;
        }
}

int main(int argc, const char * argv[])
{
   
    cout<<"Press 1 for giving Your own input and 2 for default example"<<endl;
    int option;
    cin>>option;

    cout << setprecision(16);
    double initial_X = 1.0; 
    double final_X = 1.1;

    double y = 1.0;
    double h = 0.025;
    if(option == 1){
        cout<<" Enter Initial value of X i.e X0 "<<endl;
        cin>>initial_X;
        cout<<" Final Value of X "<<endl;
        cin>>final_X;
        cout<<" Enter Initial value of Y i.e Y0 "<<endl;
        cin>>y;
        cout<<" Enter Interval "<<endl;
        cin>>h;

        calculate_Y(initial_X,final_X,h,y);




    }else if(option ==2){

   
    
    
    cout<<" For the example The values taken are :"<<endl;
    cout<<" X0  :"<<initial_X<<endl;
    cout<<" Xn  :"<<final_X<<endl;
    cout<<" Y0  :"<<y<<endl;
    cout<<" interval i.e h :"<<h<<endl;
    calculate_Y(initial_X,final_X,h,y);
    

    
    }else{
        cout<<"You chose wrong option "<<endl;
    }

   
  
    cout << "----------------------------------------------\n";
    cout<<" By calculating using Runge-Kutta method  "<<endl;
    cout << "Xn =  " << initial_X << ",  Y =  " << y << endl;

    getchar();
}