const MILLER_RABIN = require('./MILLER_RABIN');

module.exports = n => {
  let s = 0;
  n = n + 1 - (n % 2);

  while (!MILLER_RABIN(n, s))
    n += 2;

  return n;
}
