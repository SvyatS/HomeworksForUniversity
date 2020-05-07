#include <stdio.h>
#include <stdlib.h>
#define SIZE 1001

void mergeSort(int *a, int l, int r)
{
  if (l == r) return; 
  int mid = (l + r) / 2; 
  mergeSort(a, l, mid);
  mergeSort(a, mid + 1, r);
  int i = l; 
  int j = mid + 1; 
  int *tmp = (int*)malloc((r-l+1) * sizeof(int)); 
  for (int step = 0; step < r - l + 1; step++) 
  {
    if ((j > r) || ((i <= mid) && (a[i] < a[j]))) 
    {
      tmp[step] = a[i];
      i++;
    }
    else 
    {
      tmp[step] = a[j];
      j++;
    }
  }
  for (int step = 0; step < r - l + 1; step++)
    a[l + step] = tmp[step];

	free(tmp);
}
int main() 
{
  int a[SIZE];
  for (int i = 0; i<SIZE; i++) 
  {
    a[i] = (rand() % 100);
    printf(" %d ", a[i]);
  }
  mergeSort(a, 0, SIZE - 1); 
  printf("\n");
  for (int i = 0; i<SIZE; i++)
    printf(" %d ", a[i]);
  getchar();
  return 0;
}
