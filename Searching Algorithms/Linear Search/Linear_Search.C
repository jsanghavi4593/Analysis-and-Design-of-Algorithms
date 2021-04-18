#include<stdio.h>
#include<conio.h>

void main()
{
	int a[100],i,n,num,found=0;
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

	for(i=0;i<n;i++)
	{
		if(a[i] == num)
		{
			found=1;
			printf("The element %d is found at position %d.", num,i+1);
			break;
		}
	}

	if (found == 0)
	{
		printf("The element %d does not exist.", num);
	}

	getch();
}