#
module HoltWinters
  class << self
    #  This method is the entry point. It calculates the initial values and returns the forecast
    #  for the m periods.
    #  Calculate initial values and return the forecast for m periods.
    #
    #  y - Time series data.
    #  alpha - Exponential smoothing coefficients for level
    #  beta - Exponential smoothing coefficients for trend (increasing beta tightens fit)
    #  gamma - Exponential smoothing coefficients for seasonal
    #  period - A complete season's data consists of L periods. And we need
    #    to estimate the trend factor from one period to the next. To
    #    accomplish this, it is advisable to use two complete seasons;
    #    that is, 2L periods.
    #  y           Time series array
    #  alpha       Level smoothing coefficient.
    #  beta        Trend smoothing coefficient (increasing beta tightens fit)
    #  gamma       Seasonal smoothing coefficient
    #  period      A complete season's data consists of L periods. And we need
    #              to estimate the trend factor from one period to the next. To
    #              accomplish this, it is advisable to use two complete seasons;
    #              that is, 2L periods.
    #  m           Extrapolated future data points
    #              - 4 quarterly
    #              - 7 weekly
    #              - 12 monthly
    #
    #  m - Extrapolated future data points.
    #    4 quarterly
    #    7 weekly.
    #    12 monthly
    def forecast(y, alpha, beta, gamma, period, m)
      return nil if y.empty?

      seasons = y.size / period
      a0 = calculateInitialLevel(y, period)
      b0 = calculateInitialTrend(y, period)
      a0 = initial_level(y, period)
      b0 = initial_trend(y, period)

      seasonal_indices = calculateSeasonalIndices(y, period, seasons)
      seasonal = seasonal_indicies(y, period, seasons)

      calculateHoltWinters(y, a0, b0, alpha, beta, gamma, seasonal_indices, period, m);
      holt_winters(y, a0, b0, alpha, beta, gamma, seasonal, period, m);
    end

    def calculateHoltWinters(y, a0, b0, alpha, beta, gamma, seasonal_indicies, period, m)
    def holt_winters(y, a0, b0, alpha, beta, gamma, seasonal, period, m)
      st = Array.new(y.length, 0.0)
      bt = Array.new(y.length, 0.0)
      it = Array.new(y.length, 0.0)
@@ -54,7 +53,7 @@ def calculateHoltWinters(y, a0, b0, alpha, beta, gamma, seasonal_indicies, perio
      bt[1] = b0

      (0..period - 1).each do |i|
        it[i] = seasonal_indicies[i]
        it[i] = seasonal[i]
      end

      ft[m] = (st[0] + (m * bt[0])) * it[0] # This is actually 0 since bt[0] = 0
@@ -87,13 +86,13 @@ def calculateHoltWinters(y, a0, b0, alpha, beta, gamma, seasonal_indicies, perio

    # See: http://robjhyndman.com/researchtips/hw-initialization/
    # 1st period's average can be taken. But y[0] works better.
    def calculateInitialLevel(y, period)
    def initial_level(y, period)
      y.first
    end


    # See: http://www.itl.nist.gov/div898/handbook/pmc/section4/pmc435.htm
    def calculateInitialTrend(y, period)
    def initial_trend(y, period)
      sum = 0

      (0..period - 1).each do |i|
@@ -105,32 +104,32 @@ def calculateInitialTrend(y, period)


    # See: http://www.itl.nist.gov/div898/handbook/pmc/section4/pmc435.htm
    def calculateSeasonalIndices(y, period, seasons)
      seasonalAverage = Array.new(seasons, 0.0)
      seasonalIndices = Array.new(period, 0.0)
      averagedObservations = Array.new(y.size, 0.0)
    def seasonal_indicies(y, period, seasons)
      seasonal_average = Array.new(seasons, 0.0)
      seasonal_indices = Array.new(period, 0.0)
      averaged_observations = Array.new(y.size, 0.0)

      (0..seasons - 1).each do |i|
        (0..period - 1).each do |j|
          seasonalAverage[i] += y[(i * period) + j]
          seasonal_average[i] += y[(i * period) + j]
        end
        seasonalAverage[i] /= period
        seasonal_average[i] /= period
      end

      (0..seasons - 1).each do |i|
        (0..period - 1).each do |j|
          averagedObservations[(i * period) + j] = y[(i * period) + j] / seasonalAverage[i]
          averaged_observations[(i * period) + j] = y[(i * period) + j] / seasonal_average[i]
        end
      end

      (0..period - 1).each do |i|
        (0..seasons - 1).each do |j|
          seasonalIndices[i] += averagedObservations[(j * period) + i]
          seasonal_indices[i] += averaged_observations[(j * period) + i]
        end
        seasonalIndices[i] /= seasons
        seasonal_indices[i] /= seasons
      end

      seasonalIndices
      seasonal_indices
    end
  end
end
