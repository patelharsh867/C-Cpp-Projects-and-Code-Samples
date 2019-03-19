#include<stdio.h>
int chain(int index[20][20],int chain_matrix[],int i,int j);
void print_order(int index[20][20],int i,int j);

int main()
{
    int size,i,value;
    int chain_matrix[100];
    int index[20][20];
    printf("Enter the number of matrices: ");
    scanf("%d",&size);

    printf("\nEnter the dimensions of %d matrices...\n",size);
    printf("\n");

    for(i=0;i<size+1;i++)
    {
        printf("Enter the dimensions of the matrix: ");
        scanf("%d",&chain_matrix[i]);
    }


    value=chain(index,chain_matrix,1,size);
    printf("\nNumber of multiplication: %d\n\n",value);
    printf("\nThe Optimal order is:\t");
    print_order(index,1,size);

    return 0;

}


int chain(int index[20][20],int chain_matrix[],int i,int j)
{
  if(i==j)
    return 0;
  int k,count;
  int min=1000000;
  for (k=i;k<j;k++)
  {
    count=chain(index,chain_matrix,i,k)+chain(index,chain_matrix,k+1,j)+chain_matrix[i-1]*chain_matrix[k]*chain_matrix[j];
    if(count<min)
    {
      min=count;
      index[i][j]=k;
    }
  }
  return min;
}
void print_order(int index[20][20],int i,int j)
{
  if(i==j)
   printf("M%d",i);
  else
 {
   printf("(");
   print_order(index,i,index[i][j]);
   print_order(index,index[i][j]+1,j);
   printf(")");
 }
}

