#include <stdlib.h>
typedef struct {
  int prices[10001];
  int day;
  int dms[10001]; // decreasing monotonic stack
  int top;        // dms top
} StockSpanner;

StockSpanner *stockSpannerCreate() {
  StockSpanner *obj = malloc(sizeof(StockSpanner));
  obj->top = -1;
  obj->day = 0;
  return obj;
}

int stockSpannerNext(StockSpanner *obj, int price) {
  obj->day++;
  obj->prices[obj->day] = price;
  while (obj->top >= 0 && price >= obj->prices[obj->dms[obj->top]]) {
    obj->top--;
  }
  obj->top++;
  obj->dms[obj->top] = obj->day;

  int rs = obj->dms[obj->top];
  if (obj->top > 0)
    rs -= obj->dms[obj->top - 1];
  return rs;
}

void stockSpannerFree(StockSpanner *obj) { free(obj); }
