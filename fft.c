/*
 * fft.c
 *
 * 
 */

#include <stdio.h>
#include <math.h>
#include <complex.h>

void fftoperation(complex buf[], complex out[], int n, int step)
{
	int i;
	if (step < n)
	{
		fftoperation(out, buf, n, step*2);
		fftoperation(out+step, buf+step, n, step*2);

		for (i=0; i<n; i+=2*step)
		{
			complex t = cexp(-I*M_PI*i/n)*out[i+step];
			buf[i/2] = out[i] + t;
			buf[(i+n)/2] = out[i] - t;
		}
	}
}

void fft(complex buf[], int n)
{
	int i;
	complex out[n];
	for (i = 0; i < n; i++)
		out[i] = buf[i];
	fftoperation(buf, out, n, 1);
}


void display(const char * s, complex buf[], int n)
{
	int i;
	printf("%s { ", s);
	for (i = 0; i < n; i++)
	{
		if (!cimag(buf[i]))
			printf("%g ", creal(buf[i]));
		else if(cimag(buf[i])>0)
			printf("(%0.3g+j%0.3g) ", creal(buf[i]), cimag(buf[i]));
		else
			printf("(%0.3g-j%0.3g) ", creal(buf[i]), (cimag(buf[i]))*-1);
		if(i<n-1)
			printf(", ");
		else
			printf("}");
	}
}

int main()
{
	int n,i,x;
	complex buf[30];

	printf("\n Enter length of signal: ");
	scanf("%d", &n);
	printf("\n Enter signal: ");
	for(i=0; i<n; i++)
	{
		scanf("%d",&x);
		creal(buf[i]=x);
	}
	display("\n Data: ", buf, n);
	fft(buf, n);
	display("\n\nFFT : ", buf, n);

	return 0;
}

/* OUTPUT :

 Enter length of signal: 4
 Enter signal: 1 2 3 4
 Data:  { 1 , 2 , 3 , 4 }

FFT :  { 10 , (-2+j2) , -2 , (-2-j2) }
-------------------------------------------

 Enter length of signal: 8
 Enter signal: 1 2 3 4 0 0 0 0
 Data:  { 1 , 2 , 3 , 4 , 0 , 0 , 0 , 0 }

FFT :  { 10 , (-0.414-j7.24) , (-2+j2) , (2.41-j1.24) , -2 ,
		(2.41+j1.24) , (-2-j2) , (-0.414+j7.24) }
-------------------------------------------------------------------

*/
