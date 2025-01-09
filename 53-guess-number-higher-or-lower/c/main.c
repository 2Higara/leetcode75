#include <limits.h>
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

int guessNumber(int n) {
  long long l = 1, r = INT_MAX, rs = n;
  while (1) {
    if (guess(rs) == -1) { // n is larger-> l < pick < n < r
      r = rs;
    } else if (guess(rs) == 1) { // n is smaller -> l < n < pick < r
      l = rs;
    } else { // n == pick
      return rs;
    }
    rs = (l + r) / 2;
    printf("rs = %lld\n", rs);
  }
}
