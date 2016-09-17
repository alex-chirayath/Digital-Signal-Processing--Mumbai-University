/*
 * correlation.c
 *

 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int xo,yo,lb;

int checkeven(int res[], int k)
{
	int j=0;
	while(j<=k)
	{
		if(res[j] != res[k])
			return 0;
		j++;
		k--;
	}
	return 1;
}

int checkodd(int res[], int p, int k)
{
	int i=p,j=0;
	while(j<k)
	{
		if(res[i]!=0 && res[j] != -res[k])
			return 0;
		j++;
		k--;
	}
	return 1;
}

void checksignal(int res[], int n)
{
	int i,k=n-1,f1,f2;
	i=lb;

	f1 = checkeven(res,k);
	f2 = checkodd(res,i,k);

	if(f1)
		printf("\nResultant signal is Even Signal...");
	else if(f2)
		printf("\nResultant signal is Odd Signal...");
	else
		printf("\nResultant signal is Neither Even nor odd Signal...");
}

void calcenergy(int res[], int n)
{
	int i,sum=0;
	for(i=0; i<n; i++)
	{
		sum+= res[i]*res[i];
	}
	printf("\nEnergy of Signal: %d J\n",sum);
}

void convolution(const char * s, int x[], int l, int h[], int m, int n, int conv[])
{
	int i,j,k;
	int mat[20][20];

	for(i=0;i<m;i++)
	{
		for(j=0;j<l;j++)
			mat[i][j]=x[j]*h[i];
	}
/*
 	printf("\n\n By Matrix Multiplication\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<l;j++)
			printf(" %4d",mat[i][j]);
		printf("\n");
	}
*/
	for(k=0;k<n;k++)
	{
		conv[k]=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<l;j++)
			{
				if(i+j==k)
					conv[k]+=mat[i][j];
			}
		}
	}
	printf("%s",s);
	for(i=0;i<n;i++)
		printf("\n  y(%d) = %d",(i-lb),conv[i]);
}

int main()
{
	int l,m,i,x[20],h[20],res[20],x1[20];

	printf("\n Enter the no. of signals for x(n): ");
	scanf("%d",&l);
	printf("\n Enter Signal amplitudes: ");
	for(i=0;i<l;i++)
		scanf("%d",&x[i]);
	printf("\n Enter index which origin of x(n): ");
	scanf("%d",&xo);

	printf("\n\n Enter the no. of signals for h(n): ");
	scanf("%d",&m);
	printf("\n Enter Signal amplitudes: ");
	for(i=m-1;i>=0;i--)
		scanf("%d",&h[i]);
	printf("\n Enter index which origin of h(n): ");
	scanf("%d",&yo);

	lb=xo+yo;

	convolution("\n\nCorrelation of x(n) and h(n) is: ", x, l, h, m, (l+m-1), res);
	checksignal(res, (l+m-1));
	calcenergy(res, (l+m-1));

	//convolution("\n\nAuto Correlation of x(n) is: ", x, l, x, l, (l+l-1), res);
	//checksignal(res, (l+l-1));
	//calcenergy(res, (l+l-1));

	x1[0]=0;
	for(i=0;i<l;i++)
		x1[i+1] = x[i];
	convolution("\n\nCorrelation of x(n-1) and h(n) is: ", x1, l+1, h, m, (l+m), res);
	checksignal(res, (l+m));
	calcenergy(res, (l+m));

	return 0;
}

/* OUTPUT :

 Enter the no. of signals for x(n): 4
 Enter Signal amplitudes: 1 2 3 4
 Enter index which origin of x(n): 1

 Enter the no. of signals for h(n): 3
 Enter Signal amplitudes: 5 0 6
 Enter index which origin of h(n): 1

Correlation of x(n) and h(n) is :
  y(-2) = 6
  y(-1) = 12
  y(0) = 23
  y(1) = 34
  y(2) = 15
  y(3) = 20
Resultant signal is Neither Even nor odd Signal...
Energy of Signal: 2490 J

Correlation of x(n-1) and h(n) is:
  y(-2) = 0
  y(-1) = 6
  y(0) = 12
  y(1) = 23
  y(2) = 34
  y(3) = 15
  y(4) = 20
Resultant signal is Neither Even nor odd Signal...
Energy of Signal: 2490 J
--------------------------------------------------------
**AutoCorrelation:

 Enter the no. of signals for x(n): 3
 Enter Signal amplitudes: 2 3 1
 Enter index which origin of x(n): 0

 Enter the no. of signals for h(n): 3
 Enter Signal amplitudes: 2 3 1
 Enter index which origin of h(n): 0

Correlation of x(n) and h(n) is:
  y(-2) = 2
  y(-1) = 9
  y(0) = 14
  y(1) = 9
  y(2) = 2
Resultant signal is Even Signal...
Energy of Signal: 366 J
*/
