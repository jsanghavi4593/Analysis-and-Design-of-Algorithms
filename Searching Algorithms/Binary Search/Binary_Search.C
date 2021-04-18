#include<stdio.h>
#include<conio.h>

void main()
{
	int a[100],i,n,num,first,last,mid;
	clrscr();

	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("Enter the elements in the array: ");

	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}

	printf("Enter the number that you want to search: ");
	scanf("%d", &num);

	first = 0;
	last = n-1;
	mid = (first + last)/2;

	while(first <= last)
	{
		if(a[mid] == num)
		{
			printf("The element %d found at position %d.",num,mid+1);
			break;
		}

		else if(a[mid] > num)
		{
			last = mid-1;
		}

		else
		{
			first=mid+1;
		}

		mid= (first+last)/2;
	}

	if(first>last)
	{
		printf("The element %d does not exist.",num);
	}

	getch();
}