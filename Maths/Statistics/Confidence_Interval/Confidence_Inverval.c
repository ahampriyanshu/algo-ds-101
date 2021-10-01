#include <assert.h>
#include <math.h>
#include <stdlib.h>

/** calculate the normal quantile (which is the inverse normal CDF, here calculated by Acklam's algorithm, according to https://stackedboxes.org/2017/05/01/acklams-normal-quantile-function/)
 *	@param p probability
 *	@return the p-quantile of the standard normal distribution
 */
double normalQuantile(const double p)
{
	assert(0 <= p && p <= 1);

	double result = 0;

	if (p == 0)
		result = -INFINITY;
	else if (p == 1)
		result = INFINITY;
	else
	{
		const double a[] = {
				-3.969683028665376e+01,
				2.209460984245205e+02,
				-2.759285104469687e+02,
				1.383577518672690e+02,
				-3.066479806614716e+01,
				2.506628277459239e+00
		};

		const double b[] = {
				-5.447609879822406e+01,
				1.615858368580409e+02,
				-1.556989798598866e+02,
				6.680131188771972e+01,
				-1.328068155288572e+01
		};

		const double c[] = {
				-7.784894002430293e-03,
				-3.223964580411365e-01,
				-2.400758277161838e+00,
				-2.549732539343734e+00,
				4.374664141464968e+00,
				2.938163982698783e+00
		};

		const double d[] = {
				7.784695709041462e-03,
				3.224671290700398e-01,
				2.445134137142996e+00,
				3.754408661907416e+00
		};

		const double p_low = 0.02425;
		const double p_high = 1 - p_low;

		if (p < p_low) // approximation for lower region
		{
			const double q = sqrt(-2*log(p));
			result = (((((c[0]*q+c[1])*q+c[2])*q+c[3])*q+c[4])*q+c[5]) / ((((d[0]*q+d[1])*q+d[2])*q+d[3])*q+1);
		}
		else if (p_high < p) // approximation for upper region
		{
			const double q = sqrt(-2*log(1-p));
			result = -(((((c[0]*q+c[1])*q+c[2])*q+c[3])*q+c[4])*q+c[5]) / ((((d[0]*q+d[1])*q+d[2])*q+d[3])*q+1);
		}
		else // approximation for central region
		{
			const double q = p - 0.5;
			const double r = q*q;
			result = (((((a[0]*r+a[1])*r+a[2])*r+a[3])*r+a[4])*r+a[5])*q / (((((b[0]*r+b[1])*r+b[2])*r+b[3])*r+b[4])*r+1);
		}
	}

	return result;
}

/** calculate the confidence interval
 *	@param[in] estimator estimator of which the CI should be calculated
 *	@param[in] standardError the estimator's standard error
 *	@param[in] confidenceLevel confidence level of the CI
 *	@param[out] confidenceInterval expected to be an array of 2 doubles, in which the lower and upper bounds of the (confidenceLevel*100)% CI are saved
 */
void confidence_interval(const double estimator, const double standardError, const double confidenceLevel, double confidenceInterval[])
{
	assert(0 < confidenceLevel && confidenceLevel < 1);
	const double errorLevel = 1 - confidenceLevel;

	double lower = 0;
	double upper = 0;

	const double error = normalQuantile(1 - errorLevel/2.0) * standardError;

	lower = estimator - error;
	upper = estimator + error;

	confidenceInterval[0] = lower;
	confidenceInterval[1] = upper;

	return;
}

/* Test section */

#include <stdio.h>

int main(void)
{
	const double confidenceLevel = 0.99;

	double confidenceInterval[2];

	const size_t sampleSize = 10000;
	double sample[sampleSize];

	double sampleMean = 0;
	double sampleVariance = 0;

	// generate random sample of size sampleSize
	srand(0);
	for(size_t i = 0; i < sampleSize; ++i)
	{
		double uniformRandom = rand()/((double)RAND_MAX);
		sample[i] = normalQuantile(uniformRandom);
	}

	// calculate mean
	for (size_t i = 0; i < sampleSize; ++i)
		sampleMean += sample[i];
	sampleMean /= sampleSize;

	// calculate variance
	for (size_t i = 0; i < sampleSize; ++i)
		sampleVariance += (sample[i] - sampleMean)*(sample[i] - sampleMean);
	sampleVariance /= sampleSize-1;

	// our estimator is the sample mean, whose standard deviation is given by
	const double estimatorStandardDeviation = sqrt(sampleVariance/sampleSize);

	confidence_interval(sampleMean, estimatorStandardDeviation, confidenceLevel, confidenceInterval);

	printf("The random sample of %zu standard normal points yields the following estimator for the mean:\n", sampleSize);
	printf("   estimator: %f\n", sampleMean);
	printf("   %2.1f %% confidence interval: (%f, %f)\n", confidenceLevel*100, confidenceInterval[0], confidenceInterval[1]);

	return EXIT_SUCCESS;
}
