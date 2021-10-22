#include <stdio.h>
#include <math.h>

int DataSelect(int M, float R[]);
void MasOut (float *a, int Size);

int main()
{
	float a[] = {10000, 9999, 10001, 10001, 9999, 9998, 10002, 10000};
	int K = 8;
	
	K = DataSelect(K, a);
	printf("K=%i\n", K);
	MasOut(a, K);	

	return 0;
}

//R - resistance
float Averange(int M, float R[])
{
	float Sum = 0;
	int i = 0;
		
	for (i = 0; i < M; i++)
		Sum += R[i];

	printf("Averange = %f\n", Sum/M);
	return Sum/M;
}

void DeletEl(float R[], int M)
{
	int i = 0;

	for (i = 1; i < M; i++)
		R[i - 1] = R[i];

	R[M - 1] = 0;
}

int DataSelect(int M, float R[])
{
	int i = 0, K = 0;
	float averange = Averange(M, R);

	for (i = 0; i < M; i++)
		if(fabs((R[i] - averange)/averange) > 0.03)
		{	
			printf("d = %f\n",fabs((R[i] - averange)/averange));

			DeletEl(&(R[i]), M - i - 1);
			K++;
		}	

	return M - K;
}

void MasOut (float *a, int Size)
{
	int i = 0; 

	for(i = 0; i < Size; i++)
		printf("%.1lf  ", a[i]);
	printf("\n");
}
