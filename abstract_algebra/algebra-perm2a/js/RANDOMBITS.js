const RANDOMINTEGER = require('./RANDOMINTEGER');

module.exports = b => {
  const max = Math.pow(2, b) - 1;
  let n = RANDOMINTEGER(0, max);
  
  const m = Math.pow(2, b - 1) + 1;
  n = n | m;
  
  return n;
}
