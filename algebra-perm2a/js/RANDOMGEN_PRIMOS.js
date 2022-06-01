const RANDOMBITS = require('./RANDOMBITS');
const MILLER_RABIN = require('./MILLER_RABIN');

module.exports = b => {
  let s = 0;
  let n = RANDOMBITS(b);

  while (!MILLER_RABIN(n, s))
    n += 2
  
  return n;
}
