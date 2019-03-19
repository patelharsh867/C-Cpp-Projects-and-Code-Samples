#include <stdio.h>

int main()
{
   int *array, n, c, d, position, swap;
   array = (int*)malloc(100001*sizeof(int));
   //printf("Enter number of elements\n");
   //scanf("%d", &n);

   //printf("Enter %d integers\n", n);

   for ( c = 100000 ; c > 0 ; c-- )
      array[c]=c;

double clock_t, a,b;
a=clock();
   for ( c = 0 ; c < ( 100000 - 1 ) ; c++ )
   {
      position = c;

      for ( d = c + 1 ; d < 100000 ; d++ )
      {
         if ( array[position] > array[d] )
            position = d;
      }
      if ( position != c )
      {
         swap = array[c];
         array[c] = array[position];
         array[position] = swap;
      }
   }
b=clock();
printf("%lf",(b-a)/1000);

   //printf("Sorted list in ascending order:\n");

  // for ( c = 0 ; c < n ; c++ )
      printf("%d\n", array[c]);
//
   return 0;
}
