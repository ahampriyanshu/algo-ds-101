#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * This function calculates the euclidian (or L2) distance of two points.
 * @param point1 coordinates of first point stored in an array
 * @param point2 coordinates of second point stored in an array
 * @param dimension the number of coordinates each point is expected to have
 *
 * @return The euclidian distance between the points
 */
float n_dimensional_distance(double const *point1, double const * point2, const size_t dimension)
{
	double result = 0;

	for (size_t index = 0; index < dimension; ++index)
	{
		double difference = point1[index] - point2[index];
		result += difference*difference;
	}

	return sqrt(result);
}

int main(void)
{
	const size_t N = 3;
	const double point1[] = {1,1,1};
	const double point2[] = {3,4,7};

	double distance = n_dimensional_distance(point1, point2, N);

	printf("The %zu-dimensional distance between the points point1 and point2 is %f", N, distance);

	return EXIT_SUCCESS;
}
