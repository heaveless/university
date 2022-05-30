import MILLER_RABIN from './MILLER_RABIN';

export default n => {
  let n = 0;
  n = n + 1 - (n % 2);

  while (!MILLER_RABIN(n, s))
    n += 2;

  return n;
}
