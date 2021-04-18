#include<stdio.h>
#include<conio.h>

void DFS(int);
int G[10][10], visited[10], n;

void main()
{
	int i, j;
	clrscr();

	printf("Enter the no. of vertices: ");
	scanf("%d",&n);

	printf("\nEnter the adjecency matrix of the graph: \n");

	for(i=0;i<n;i++)
		 for(j=0;j<n;j++)
			scanf("%d", &G[i][j]);

	for(i=0;i<n;i++)
		  visited[i]=0;

	printf("\nThe path followed is in order: ");

	DFS(0);

	getch();
}

void DFS(int i)
{
	int j;

	printf("%d ",i);
	visited[i]=1;

	for(j=0;j<n;j++)
		if(!visited[j]&&G[i][j]==1)
			DFS(j);
}
