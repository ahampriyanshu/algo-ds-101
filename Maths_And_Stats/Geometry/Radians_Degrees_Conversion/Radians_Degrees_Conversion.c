#include <stdio.h>
#define M_PI 3.14159265358979323846

float convert(float *n, int _case);

int main()
{
    int _case = 0; //to indicate direction of the conversion
    float value;
    printf("What do you want to do?\n");
    while(_case != 1 && _case != 2)
    {
        printf("\n\t1) Convert degrees to radians.\n\t2) Convert radians to degrees.\n");
        scanf("%d", &_case); //get direction of conversion
        switch(_case)
        {
            case 1:
                printf("Enter your value in degrees: ");
                break;
            case 2:
                printf("Enter your value in radians: ");
                break;
            default:
                printf("\nInvalid choice! Please choose one of the options below...");
                break;
        }
    }
    scanf("%f", &value);
    printf("Value of %f ", value);
    printf("%s in %s is:  %f",
    ((_case==1) ? "degrees" : "radians"), 
    ((_case==1) ? "radians" : "degrees"), 
    convert(&value, _case));
    if(_case == 1)
        printf(" rad or %.3fPi rad", value/M_PI); 
    else
        printf(" deg");
    char c;
    scanf("%c", &c); //wait for user input
    return 0;
}

float convert(float *n, int _case)
{
    switch(_case)
    {
        case 1: //convert from degrees to radians
            *n=(*n*M_PI)/180; 
            return(*n);
            break;
        case 2: //convert from radians to degrees
            *n=(*n*180)/M_PI;
            return(*n);
            break;
    }
}
