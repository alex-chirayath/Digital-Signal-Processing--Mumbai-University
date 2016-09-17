/*
 * circularconv.c
 *

 */

#include <stdio.h>

float x[30],h[30],y[30],x2[30],a[30];
int n,m,i,j,k;

int main()
{
	printf("\n Enter the length of the first sequence: ");
	scanf("%d",&n);
    printf("\n Enter the first sequence: ");
    for(i=0;i<n;i++)
    	scanf("%f",&x[i]);

	printf("\n\n Enter the length of the second sequence: ");
    scanf("%d",&m);
    printf("\n Enter the second sequence: ");
    for(j=0;j<m;j++)
    	scanf("%f",&h[j]);

    if(n-m!=0) /*If length of both sequences are not equal*/
    {
    	if(n>m) /* Pad the smaller sequence with zero*/
    	{
    		for(i=m;i<n;i++)
    			h[i]=0.0;
    		m=n;
    	}
    	for(i=n;i<m;i++)
    		x[i]=0.0;
    	n=m;
    }

    y[0]=0.0;
    a[0]=h[0];
    for(j=1;j<n;j++) /*folding h(n) to h(-n)*/
    	a[j]=h[n-j];

    /*Circular convolution*/
    for(i=0;i<n;i++)
    	y[0]+=x[i]*a[i];
    for(k=1;k<n;k++)
    {
    	y[k]=0.0;

    	//circular shift
    	for(j=1;j<n;j++)
    		x2[j]=a[j-1];
    	x2[0]=a[n-1];
    	for(i=0;i<n;i++)
    	{
    		a[i]=x2[i];
    		y[k]+=x[i]*x2[i];
    	}
    }

    //displaying the result
    printf("\n\nCircular Convolution: \n");
    for(i=0;i<n;i++)
    	printf("\n y[%d] = %.2f",(i),y[i]);
    return 0;
}

/*	OUTPUT :

 Enter the length of the first sequence: 5
 Enter the first sequence: 0 0.6 -1 1.5 2

 Enter the length of the second sequence: 5
 Enter the second sequence: -2 3 0.2 0.7 0.8

Circular Convolution:

 y[0] = 6.08
 y[1] = -0.55
 y[2] = 6.40
 y[3] = -4.28
 y[4] = 0.72
--------------------------------------------------

 Enter the length of the first sequence: 4
 Enter the first sequence: 1 2 -1 1

 Enter the length of the second sequence: 4
 Enter the second sequence: 2 4 6 8

Circular Convolution:

 y[0] = 16.00
 y[1] = 6.00
 y[2] = 20.00
 y[3] = 18.00

*/

