#include <stdio.h>
#include <time.h>
int main()
{
  int *array, n, c, d, swap;
 array = (int*)malloc(100001*sizeof(int));




  for (c = 100000; c >0 ; c--)
    array[c] = c;
double clock_t, a,b;
a=clock();
  for (c = 0 ; c < ( 100000 - 1 ); c++)
  {
    for (d = 0 ; d < 100000 - c - 1; d++)
    {
      if (array[d] > array[d+1]) /* For decreasing order use < */
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }
b=clock();
printf("%lf",(b-a)/1000);

  //printf("Sorted list in ascending order:\n");

  //for ( c = 0 ; c < n ; c++ )
    // printf("%d\n", array[c]);

  return 0;
}
