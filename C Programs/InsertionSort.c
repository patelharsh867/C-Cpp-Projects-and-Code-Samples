#include<stdio.h>
int main()
{
	int *data,n,temp,i,j;
	data = (int*)malloc(100001*sizeof(int));
	//printf("Enter elements: ");
	for(i=100000;i>0;i--)
	data[i]=i;

	double clock_t, a,b;
a=clock();
	for(i=100000;i>0;i--)
	{
		temp = data[i];
		j=i-1;
		while(temp<data[j] && j>=0)
/*To sort elements in descending order, change temp<data[j] to temp>data[j] in above line.*/
		{
			data[j+1] = data[j];
			--j;
		}
		data[j+1]=temp;
	}
b=clock();
printf("%lf",(b-a)/1000);

//	printf("In ascending order: ");
//	for(i=0; i<n; i++)
		//printf("%d\t",data[i]);
    return 0;
}
