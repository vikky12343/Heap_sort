#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;


clock_t t;
void generate (int *a,int n)
{
int i;
for(i=0;i<n;i++)
a[i]=rand();
}


void MaxHeapify(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i;

 	while (j <= n)
	{
		if (j < n && a[j+1] > a[j])
		j = j+1;
		if (temp > a[j])
			break;
		else if (temp <= a[j])
		{
			a[j/2] = a[j];
			j = 2*j;
		}
	}
	a[j/2] = temp;
	return;
}
void HeapSort(int a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;

		MaxHeapify(a, 1, i - 1);
	}
}
void Build_MaxHeap(int a[], int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
		MaxHeapify(a, i, n);
}
int main()
{
	int n,a[500000], i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
	generate(a,n);
	for(i = 1; i < n; i++)
        cout<<a[i]<<" ";
    t=clock();

	Build_MaxHeap(a, n-1);
	HeapSort(a, n-1);

	cout<<"\nSorted Data ";

	for (i = 1; i < n; i++)
    {

		cout<<" "<<a[i];

    }
    t=clock()-t;
    cout<<"\nTime is :"<<t;
	return 0;
}
