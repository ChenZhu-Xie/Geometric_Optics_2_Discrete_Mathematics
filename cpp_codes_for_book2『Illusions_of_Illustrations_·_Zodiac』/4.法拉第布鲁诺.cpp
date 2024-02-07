#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int *m=(int*)malloc(sizeof(int)),nn,count=0;
void get(int n,int leftovers)
{
	if(leftovers==0)
	{
		int i;
		for(i=0;i<n;i++)
			m[i]=0;
		for(i=0;i<nn;i++)
			printf("%d ",m[i]);
		printf("\n");
		count=count+1;
	}
	else if(n>leftovers)
		get(n-1,leftovers);
	else
	{
		if(n==1)
		{
			m[0]=leftovers;
			for(int i=0;i<nn;i++)
				printf("%d ",m[i]);
			printf("\n");
			count=count+1;
		}
		else
		for(int j=(leftovers-leftovers%n)/n;j>=0;j--)
		{
			m[n-1]=j;
			get(n-1,leftovers-n*j);
		}
	}
}
void main()
{
	int n,i;
	printf("请输入n值: ");
	scanf("%d",&n);
	nn=n;
	m=(int*)realloc(m,n*sizeof(int));
	printf("\n");
	for(i=0;i<nn;i++)
		printf("%d ",i+1);
	printf("%d ",nn);
	printf("\n\n");
	get(n,n);
	printf("\n");
	printf("如上所示,共有%d组解\n\n",count);
}