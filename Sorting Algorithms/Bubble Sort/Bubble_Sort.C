#include<stdio.h>
#include<conio.h>

void main()
{
	int a[100],n,i,j,temp;
	clrscr();

	printf("Enter the number of elements: ");
	scanf("%d",&n);

	printf("Enter the elements: ");

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j] > a[j+1])
			{
				temp   = a[j];
				a[j]   = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	printf("Sorted elements in ascending order: ");
	for(i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}

	getch();
}