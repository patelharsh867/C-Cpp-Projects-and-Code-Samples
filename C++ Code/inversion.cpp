#include <iostream>
#include <cstdlib>
#include<fstream>
#include <vector>

using namespace std;
long long int mSort(long long int arr[], long long int temp[],long long int left, long long int right);
long long int merge(long long int arr[], long long int temp[],long long int left,long long int mid, long long int right);

/*
 * calls mSort
 */
long long int mergeSort(long long int *arr,long long int array_size)
{
    long long int *temp = new long long int [array_size];
    return mSort(arr, temp, 0, array_size - 1);
}

/*
 * sorts the input array and returns the number of inversions in the array.
 */
long long int mSort(long long int arr[], long long int temp[], long long int left, long long int right)
{
    long long int mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;
        inv_count  = mSort(arr, temp, left, mid);
        inv_count += mSort(arr, temp, mid+1, right);
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

/*
 * merges two sorted arrays and returns inversion count in the arrays.
 */
long long int merge(long long int arr[],long long int temp[],long long int left, long long int mid, long long int right)
{
    long long int i, j, k;
    long long int inv_count = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return inv_count;
}

/*
 * Main
 */
int main()
{
    //int array_size = 100000;
    fstream file("Numbers.txt");
	long long int linecount = 0;
	long long int array_size = 100000;
	long long int tempArray[array_size];
	long long int *arr;

	while (!file.eof())
	{
		file >> tempArray[linecount];
		linecount++;
	}
    /*file >> tempArray[linecount];
		linecount++;
		file >> tempArray[linecount];
		linecount++;*/
	cout << "Number of lines: " << linecount;

	arr = new long long int[linecount];
	for (int i = 0; i < 100001; i++)
	{
            arr[i] = tempArray[i];
	}
    cout<<"Number of inversions are "<< mergeSort(arr, 100001)<<endl;
cin.get();
    return 0;
}
