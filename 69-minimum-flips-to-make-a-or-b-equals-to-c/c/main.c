int minFlips(int a, int b, int c) {
  int count = 0;
  int check = (a | b) ^ c;
  while (check) {
    if (check & 1) {
      if (c & 1) {
        count++;
      } else {
        count += ((a & 1) + (b & 1));
      }
    }
    check >>= 1;
    a >>= 1;
    b >>= 1;
    c >>= 1;
  }
  return count;
}
