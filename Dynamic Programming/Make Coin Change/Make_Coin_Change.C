#include<stdio.h>
#include<conio.h>

int make_change (int a[], int n, int k)
{
	int i, j, M[1000];
	M[0] = 0;

	for(j=1;j<=n;j++)
	{
		int min = 5000;

		for(i=0; i<=k; i++)
		{
			if(j >= a[i])
			{
				if(min <= (1+M[j-a[i]]))
					min = min;
				else
					min = 1+M[j-a[i]];
			}
		}

		M[j] = min;
		printf("%d\t", M[j]);
	}

	return M[n];
}

void main()
{
	int i, n, c, a[10];
	clrscr();

	printf("\nEnter the no. of coins available: ");
	scanf("%d",&n);

	printf("Enter the value of the coins: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	printf("\nEnter the amount whose change is needed: ");
	scanf("%d", &c);

	printf("\n\nTotal no of coins needed: %d.",make_change(a,c,n));

	getch();
}