#include <stdio.h>

int main()
{
 int a, b, c;
 int ZA[100000], ZB[100000];

 scanf("%d", &a);
 for (b = 0; b < a; ++b)
  scanf("%d%d", &ZA[b], &ZB[b]);
 for (b = 1; b < a; ++b)
  if (ZB[b] > ZB[b - 1])
   ZB[b] = ZB[b - 1];
 c = 0;
 for (b = 0; b < a; ++b)
  c += ZA[b] * ZB[b];
 printf("%d\n", c);

 return 0;
}