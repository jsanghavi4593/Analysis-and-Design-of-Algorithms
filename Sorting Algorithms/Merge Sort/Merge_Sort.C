#include<stdio.h>
#include<conio.h>
#define size 100
void merge(int a[], int, int, int);
void merge_sort(int a[],int, int);

void main()
{
	int a[size],i,n;
	clrscr();

	printf("Enter the number of elements: ");
	scanf("%d",&n);

	printf("Enter the elements of the array: ");

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	merge_sort(a,0,n-1);

	printf("Sorted array in ascending order: ");

	for(i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}

	getch();
}

void merge(int a[], int l, int m, int r)
{
	int i=l,j=m+1,index=l,temp[size],k;

	while((i<=m) && (j<=r))
	{
		if(a[i] < a[j])
		{
			temp[index] = a[i];
			i++;
		}
		else
		{
			temp[index] = a[j];
			j++;
		}
		index++;
	}

	if(i>m)
	{
		while(j<=r)
		{
			temp[index] = a[j];
			j++;
			index++;
		}
	}
	else
	{
		while(i<=m)
		{
			temp[index] = a[i];
			i++;
			index++;
		}
	}

	for(k=l;k<index;k++)
	{
		a[k] = temp[k];
	}
}

void merge_sort(int a[],int l,int r)
{
	int m;
	if(l < r)
	{
		m = (l+r)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,r);
		merge(a,l,m,r);
	}
}