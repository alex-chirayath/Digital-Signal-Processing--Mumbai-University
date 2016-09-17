/*
 * linearconv.c
 *

 */

#include <stdio.h>

int x[15],h[15],y[15];

int main()
{
	int i,j,n,m,xo,yo,lb;
	printf("\n Enter value for n: ");
	scanf("%d",&n);
	printf("\n Origin for x(n): ");
	scanf("%d",&xo);
	printf("\n Enter values for i/p x(n): ");
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);

	printf("\n\n Enter value for m: ");
	scanf("%d",&m);
	printf("\n Origin for h(m): ");
	scanf("%d",&yo);
	printf("\n Enter Values for i/p h(m): ");
	for(i=0;i<m; i++)
		scanf("%d",&h[i]);

	lb = xo + yo;
	//Convolution --->
	for(i=n;i<=n+m-1;i++)
		x[i]=0;
	for(i=m;i<=n+m-1;i++)
		h[i]=0;
	for(i=0;i<n+m-1;i++)
	{
		y[i]=0;
		for(j=0;j<=i;j++)
			y[i]=y[i]+(x[j]*h[i-j]);
	}
	printf("\n\nLinear Convolution:");
	for(i=0;i<n+m-1;i++)
		printf("\n y[%d] = %d",(i-lb),y[i]);
	return 0;
}

/*	OUTPUT:

 Enter value for n: 5
 Origin for x(n): 2
 Enter values for i/p x(n): 1 1 0 1 1

 Enter value for m: 4
 Origin for h(m): 3
 Enter Values for i/p h(m): 1 -2 -3 4

Linear Convolution:
 y[-5] = 1
 y[-4] = -1
 y[-3] = -5
 y[-2] = 2
 y[-1] = 3
 y[0] = -5
 y[1] = 1
 y[2] = 4
------------------------------------------------

 Enter value for n: 4
 Origin for x(n): 0
 Enter values for i/p x(n): 1 2 -1 3

 Enter value for m: 4
 Origin for h(m):0
 Enter Values for i/p h(m): 1 2 -1 3

Linear Convolution:
 y[0] = 1
 y[1] = 4
 y[2] = 2
 y[3] = 2
 y[4] = 13
 y[5] = -6
 y[6] = 9
*/
