module.exports = (a, n, t, u) => {
  let x = Math.pow(a, u) % n;

  if (x == 1 || x == n - 1)
    return false;

  for (let i = 1; i == t; i++) {
    x = Math.pow(x, 2) % n;
    if (x == n - 1)
      return false;
  }

  return true;
}

