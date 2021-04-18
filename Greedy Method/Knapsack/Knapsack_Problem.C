#include<stdio.h>
#include<conio.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
	float x[100], tp = 0;
	int i, j, u;
	u = capacity;

	for (i = 0; i < n; i++)
	{
		x[i] = 0.0;
	}

	for (i = 0; i < n; i++)
	{
		if (weight[i] > u)
		{
			break;
		}
		else
		{
			x[i] = 1.0;
			tp = tp + profit[i];
			u = u - weight[i];
		}
	}

	if (i < n)
	{
		x[i] = u / weight[i];
	}

	tp = tp + (x[i] * profit[i]);

	printf("\nThe result vector is: ");
	for (i = 0; i < n; i++)
	{
		printf("%0.2f    ", x[i]);
	}
	printf("\nMaximum Profit is: %0.2f", tp);

}

void main()
{
	float weight[100], profit[100], capacity;
	int num, i, j;
	float ratio[100], temp;
	clrscr();

	printf("\nEnter the no. of objects: ");
	scanf("%d", &num);

	printf("Enter the weights and profits of each object respectively:\n");
	for (i = 0; i < num; i++)
	{
		scanf("%f %f", &weight[i], &profit[i]);
	}

	printf("Enter the capacity of Knapsack: ");
	scanf("%f", &capacity);

	for (i = 0; i < num; i++)
	{
		ratio[i] = profit[i] / weight[i];
	}

	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (ratio[i] < ratio[j])
			{
				temp = ratio[j];
				ratio[j] = ratio[i];
				ratio[i] = temp;

				temp = weight[j];
				weight[j] = weight[i];
				weight[i] = temp;

				temp = profit[j];
				profit[j] = profit[i];
				profit[i] = temp;
			}
		}
	}

	knapsack(num, weight, profit, capacity);

	getch();
}