#include <cassert>
#include <cmath>
#include <array>

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
 *	@param estimator estimator of which the CI should be calculated
 *	@param standardError the estimator's standard error
 *	@param confidenceLevel confidence level of the CI
 *	@return the (confidenceLevel*100)% CI
 */
std::array<double, 2> confidence_interval(const double estimator, const double standardError, const double confidenceLevel)
{
	assert(0 < confidenceLevel && confidenceLevel < 1);
	const double errorLevel = 1 - confidenceLevel;

	double lower = 0;
	double upper = 0;

	const double error = normalQuantile(1 - errorLevel/2.0) * standardError;

	lower = estimator - error;
	upper = estimator + error;

	std::array<double, 2> confidenceInterval{lower, upper};
	return confidenceInterval;
}

// Test section:

#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main()
{
	const double confidenceLevel = 0.99;

	const size_t sampleSize = 10000;
	vector<double> sample(sampleSize);

	double sampleMean = 0;
	double sampleVariance = 0;

	// generate random sample of size sampleSize
	{
		default_random_engine generator;
		normal_distribution<double> distribution(0.0,1.0);

		for(size_t i = 0; i < sampleSize; ++i)
			sample[i] = distribution(generator);
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

	auto confidenceInterval = confidence_interval(sampleMean, estimatorStandardDeviation, confidenceLevel);

	cout << "The random sample of " << sampleSize << " standard normal points yields the following estimator for the mean:" << endl
		 << "   estimator: " << sampleMean << endl
		 << "   " << setprecision(2) << confidenceLevel*100 << "% confidence interval: (" << setprecision(6) << confidenceInterval[0] << ", " << confidenceInterval[1] << ")" << endl;

	return 0;
}
