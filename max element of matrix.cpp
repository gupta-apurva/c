#include<stdio.h>
int main()
{
	int a[10][10],i,j,n,max;
	printf("\n enter the order of matrix");
	scanf("%d",&n);
	printf("\nenter the element of matrix");
	for(i=0;i<n;i++)
	{
			for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("the orignal marix was\n");
	max=a[0][0];
	for(i=0;i<n;i++)
	{
			for(j=0;j<n;j++)
			{
				if(max<a[i][j])
					max=a[i][j];
				printf("%3d",a[i][j]);
		}
			printf("\n");
	}
	printf("\n the max element of matrix is %d",max);
	return(0);
}
