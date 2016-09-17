/*
 * dft.c
 *
 *
 */

#include <stdio.h>
#include <math.h>

void display(const char * s, float realdisp[], float imagdisp[], int n)
{
	int i;
	printf("%s { ", s);
	for (i = 0; i < n; i++)
	{
		if (imagdisp[i] == 0)
			printf("%0.2f ", realdisp[i]);

		else if(imagdisp[i] > 0)
			printf("(%0.2f+j%0.2f) ", realdisp[i], imagdisp[i]);

		else
			printf("(%0.2f-j%0.2f) ", realdisp[i], (imagdisp[i])*-1.0);

		if(i<n-1)
			printf(", ");
		else
			printf("}");
	}
}

void compute_dft(float realbuf[], float imagbuf[], float realout[], float imagout[], int n)
{
	int k,t;
	for (k = 0; k < n; k++)
	{
		float sumreal = 0;
		float sumimag = 0;
		for (t = 0; t < n; t++)
		{
			double angle = 2 * M_PI * t * k / n;
			sumreal +=  realbuf[t] * cos(angle) + imagbuf[t] * sin(angle);
			sumimag += -realbuf[t] * sin(angle) + imagbuf[t] * cos(angle);
		}

		//printf("\nstep %d--> %0.2f \t %0.2f",k,sumreal,sumimag);
		realout[k]=sumreal;
		imagout[k]=sumimag;
	}
}

int main()
{
	int n,i;
	float x,y;
	float realbuf[20], imagbuf[20],realout[20],imagout[20];

	printf("\n Enter length of signal: ");
	scanf("%d", &n);
	printf("\n Enter signal (x+yj) in x y form:\n");
	for(i=0; i<n; i++)
	{
		scanf("%f %f",&x, &y);
		realbuf[i]=x;
		imagbuf[i]=y;
	}
	display("\n Data: ", realbuf, imagbuf, n);
	compute_dft(realbuf, imagbuf, realout, imagout, n);
	display("\n\nDFT : ", realout, imagout, n);

	return 0;
}

/* OUTPUT:

 Enter length of signal: 4
 Enter signal (x+yj) in x y form:
1 0
2 0
3 0
4 0
 Data:  { 1.00 , 2.00 , 3.00 , 4.00 }

DFT :  { 10.00 , (-2.00+j2.00) , (-2.00-j0.00) , (-2.00-j2.00) }
---------------------------------------------------------------------
 Enter length of signal: 8
 Enter signal (x+yj) in x y form:
1 0
2 0
3 0
4 0
0 0
0 0
0 0
0 0
 Data:  { 1.00 , 2.00 , 3.00 , 4.00 , 0.00 , 0.00 , 0.00 , 0.00 }

DFT :  { 10.00 , (-0.41-j7.24) , (-2.00+j2.00) , (2.41-j1.24) , (-2.00-j0.00) ,
		 (2.41+j1.24) , (-2.00-j2.00) , (-0.41+j7.24) }
------------------------------------------------------------------------------
 Enter length of signal: 12
 Enter signal (x+yj) in x y form:
1 0
2 0
3 0
4 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
 Data:  { 1.00 , 2.00 , 3.00 , 4.00 , 0.00 , 0.00 , 0.00 , 0.00 , 0.00 , 0.00 , 0.00 , 0.00 }

DFT :  { 10.00 , (4.23-j7.60) , (-3.50-j4.33) , (-2.00+j2.00) , (2.50+j0.87) , (0.77-j2.40) ,
(-2.00-j0.00) , (0.77+j2.40) , (2.50-j0.87) , (-2.00-j2.00) , (-3.50+j4.33) , (4.23+j7.60) }
*/
