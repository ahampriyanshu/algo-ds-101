// C program to implement Runge Kutta method
#include<stdio.h>

// A sample differential equation "dy/dx = (x - y)/2"
float dydx(float x, float y)
{
	return((x - y)/2);
}

// Finds value of y for a given x using step size h
// and initial value y0 at x0.
float rungeKutta(float x0, float y0, float x, float h)
{
	// Count number of iterations using step size or
	// step height h
	int n = (int)((x - x0) / h);

	float k1, k2, k3, k4, k5;

	// Iterate for number of iterations
	float y = y0;
	for (int i=1; i<=n; i++)
	{
		// Apply Runge Kutta Formulas to find
		// next value of y
		k1 = h*dydx(x0, y);
		k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1);
		k3 = h*dydx(x0 + 0.5*h, y + 0.5*k2);
		k4 = h*dydx(x0 + h, y + k3);

		// Update next value of y
		y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);;

		// Update next value of x
		x0 = x0 + h;
	}

	return y;
}

// Driver method
int main()
{
	float x0 = 0, y = 1, x = 2, h = 0.2;
	printf("\nThe value of y at x is : %f",
			rungeKutta(x0, y, x, h));
	return 0;
}

