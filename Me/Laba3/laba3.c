#include <stdlib.h>
#include <stdio.h>

#define MAXL 1000

#define  root i+sh
#define  left 2*i+1+sh
#define right 2*i+2+sh

void swap (int *a, int *b) { int t = *a; *a = *b; *b = t; }

int main()
{
  int a[MAXL], n, i, sh = 0, b = 0;
  scanf ("%i", &n);
  for (i = 0; i < n; ++i) a[i] = rand()%100;
  while (1)
  {
    b = 0;
    for (i = 0; i < n; ++i)
    {
      if (right < n)
      {
        if (a[root] > a[left] || a[root] > a[right])
	      {
	        if (a[left] < a[right])
	        {
	          swap (&a[root], &a[left]);
	          b = 1;
	        }
	        else if (a[right] < a[left])
	        {
	          swap (&a[root], &a[right]);
	          b = 1;
	        }
	      }
      }
      else if (left < n)
      {
        if (a[root] > a[left])
	      {
	        swap (&a[root], &a[left]);
	        b = 1;
	      }
      }
    }
    if (!b) sh++;
    if (sh + 2 == n) break;
  }
  
  for (i = n-10; i < n; i++) printf ("%i%c", a[i], (i != n - 1) ? ' ' : '\n');
  
  return 0;
}
