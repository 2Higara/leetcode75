int largestAltitude(int *gain, int gainSize) {
  int max = 0, al = 0;
  for (int i = 0; i < gainSize; i++) {
    al += gain[i];
    if (al > max)
      max = al;
  }
  return max;
}
