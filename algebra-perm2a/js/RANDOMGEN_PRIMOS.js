import RANDOMBITS from './RANDOMBITS';
import MILLER_RABIN from './MILLER_RABIN';

export default b => {
  let n = RANDOMBITS(b);

  while (!MILLER_RABIN(n, s))
    n += 2
  
  return n;
}
