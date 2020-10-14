function sqrt(n) {
  if (!(typeof n === 'number' && n >= 0 && !isNaN(n))) {
    return NaN;
  } else if (n === 0) {
    return 0;
  } else if (n === Infinity) {
    return Infinity;

  }

  var value = n;

  while (true) {
    var last = value;
    value = (value + n / value) * 0.5;
    if (Math.abs(value - last) < 1e-9) {
      break;
    }
  }

  return value;
}