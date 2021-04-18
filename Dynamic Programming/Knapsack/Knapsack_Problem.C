#include<stdio.h>
#include<conio.h>

int max (int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int Knapsack (int n, int val[], int wt[], int W)
{
	int i, w;
	int knap[100][100];

	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i==0 || w==0)
				knap[i][w] = 0;

			else if (wt[i-1] <= w)
				knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);

			else
				knap[i][w] = knap[i-1][w];
		}
	}

	return knap[n][W];
}

void main()
{
	int i, n, W;
	int wt[100], val[100];
	clrscr();

	printf("\nEnter the no. of objects: ");
	scanf("%d", &n);

	printf("Enter the values & weights of the objects respectively:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &wt[i], &val[i]);
	}

	printf("Enter the capacity of Knapsack: ");
	scanf("%d", &W);

	printf("\nMaximum Profit is : %d.", Knapsack(n, val, wt, W));

	getch();
}