// calculate 95 percentile confidence interval
const hypothesis = Math.random() * 100; // get a random number in range [0, 100)
const data = []
for (let i = 0; i < 1000; i++)
{
  data.push(Math.random() * 200) // sample a dataset in range [0, 200)
}
const mean = data.reduce ((accumulator, currentValue) => {
  return accumulator + currentValue
}, 0) / data.length

const standardDeviation = Math.sqrt (
  data.reduce((accumulator, nextElement) =>
  accumulator + (nextElement - mean)
  , 0) / data.length
)

const percentile = 0.95

function percentile_z(p) {
  if (p > 0.5) return -1

  const a0 = 2.5066282;
  const a1 = -18.6150006;
  const a2 = 41.3911977;
  const a3 = -25.4410605;
  const b1 = -8.4735109;
  const b2 = 23.0833674;
  const b3 = -21.0622410;
  const b4 = 3.1308291;
  const c0 = -2.7871893;
  const c1 = -2.2979648;
  const c2 = 4.8501413;
  const c3 = 2.3212128;
  const d1 = 3.5438892;
  const d2 = 1.6370678
  let r;
  let z;

  if (p > 0.42)
  {
      r = Math.sqrt(-Math.log(0.5-p));
      z = (((c3*r+c2)*r+c1)*r+c0)/((d2*r+d1)*r+1);
  } else
  {
      r = p*p;
      z = p*(((a3*r+a2)*r+a1)*r+a0)/((((b4*r+b3)*r+b2)*r+b1)*r+1);
  }
  return z;
}

const confLo = mean - (percentile_z (percentile) * standardDeviation / Math.sqrt(data.length))
const confHi = mean + (percentile_z (percentile) * standardDeviation / Math.sqrt(data.length))
console.log(confLo, confHi)