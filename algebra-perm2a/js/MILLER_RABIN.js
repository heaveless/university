const ES_COMPUSTO = require('./ES_COMPUESTO');

module.exports = (n, s) => {
  let t = 0;
  let u = n - 1;
  while (u % 2 == 0) {
    u = u / 2;
    t = t + 1;

    for (let j = 1; j < s; j++) {
      const a = Math.Random(2, n - 1);
      if (ES_COMPUSTO(a, n, t, u))
        return false;
    }
  }

  return true;
}


