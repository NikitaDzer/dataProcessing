#include <stdio.h>
#include <math.h>

int DataSelect(int M, float R[]);
void MasOut (float *a, int Size);

int main()
{
	float a[] = {0.111782, 0.111622, 0.112505, 0.114052,
			  0.11431, 0.110154, 0.098418, 0.111481};
	int K = 8;
	
	K = DataSelect(K, a);
	printf("K=%i\n", K);
	MasOut(a, K);	

	return 0;
}

<<<<<<< HEAD
void MasOut (float *a, int Size)
{
   if(a == NULL)
      return;
   
   int i = 0;
   
   for(i = 0; i < Size; i++)
      printf("%.5lf  ", a[i]);
   printf("\n");
}

//R - resistance
float Averange(int M, float R[])
{
	if(R == NULL)
		return 0;
	
	float Sum = 0;
	int i = 0;
		
	for (i = 0; i < M; i++)
		Sum += R[i];

	return Sum/M;
}

void DeletEl(float R[], int M)
{
	if(R == NULL)
		return;

	int i = 0;

	for (i = 1; i <= M; i++)
		R[i - 1] = R[i];

	R[M - 1] = 0;
=======
//R - resistance
float Averange(int M, float R[])
{
	if(R == NULL)
		return 0;
	
	float Sum = 0;
	int i = 0;
		
	for (i = 0; i < M; i++)
		Sum += R[i];

	printf("Averange = %f\n", Sum/M);
	return Sum/M;
}

void DeletEl(float R[], int M)
{
	if(R == NULL)
		return;

	printf("DeletMas\n");	
	MasOut(R, M);
	int i = 0;

	for (i = 1; i <= M; i++)
		R[i - 1] = R[i];

	R[M - 1] = 0;
}

int DataSelect(int M, float R[])
{
	if(R == NULL)
		return 0;
	
	int i = 0;
	float averange = Averange(M, R), a = 0;

	//MasOut(R, M);
	for (i = 0; i < M; i++)
		if((a = fabs((R[i] - averange)/averange)) > 0.03)
		{	
			printf("d = %f, ",a);
			printf("R[i] = %f\n", R[i]);
			MasOut(R, M);
			DeletEl(&(R[i]), M - i);
			M--;
		}	
	
	return M;
>>>>>>> bdf1007e9447553f185ad3a9e54dde7b69d05e19
}

int DataSelect(int M, float R[])
{
<<<<<<< HEAD
	if(R == NULL)
		return 0;
	
	int i = 0;
	float averange = Averange(M, R), a = 0;

	//MasOut(R, M);
	for (i = 0; i < M; i++)
		if((a = fabs((R[i] - averange)/averange)) > 0.03)
		{
			DeletEl(&(R[i]), M - i);
			M--;
		}	
	
	return M;
=======
	if(a == NULL)
		return;
	
	int i = 0; 

	for(i = 0; i < Size; i++)
		printf("%.5lf  ", a[i]);
	printf("\n");
>>>>>>> bdf1007e9447553f185ad3a9e54dde7b69d05e19
}
