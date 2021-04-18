#include <stdio.h>
#include <conio.h>

void printArray(int a[], int n)
{
	int i;

	for (i=0;i<n;++i)
	{
		printf("%d ", a[i]);
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int a[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < n && a[left] > a[largest])
	{
		largest = left;
	}

	if(right < n && a[right] > a[largest])
	{
		largest = right;
	}

	if(largest != i)
	{
		printf("\nSwap: %d %d",a[i],a[largest]);

		swap(&a[i], &a[largest]);
		heapify(a, n, largest);
	}
}

void heapSort(int a[], int n)
{
	int i;

	for(i=n/2- 1;i>=0;i--)

	heapify(a, n, i);

	printf("\nHeapify: ");
	printArray(a, n);

	for(i=n-1;i>=0;i--)
	{
		printf("\n\nRoot swap: %d %d",a[0],a[i]);

		swap(&a[0], &a[i]);
		heapify(a, i, 0);

		printf("\nHeapify: ");
		printArray(a, n);

	}
}

void main()
{
	int a[100],i,n;
	clrscr();

	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	heapSort(a, n);
	printf("\n\nSorted elements in ascending order: ");
	printArray(a, n);

	getch();
}