#include <stdio.h>
#include <math.h>

int DataSelect(int Num, float R[]);
void MasOut (float *a, int Size);

/*int main()
{       
        float a[] = {10000, 9999, 10001, 10001, 9999, 9998, 10002, 10000};
        int K = 8;
        
        K = DataSelect(K, a);
        printf("K=%i\n", K);
        MasOut(a, K);
        
        return 0;
}*/

//R - resistance
float Averange(int Num, float R[])
{       
        if(R == NULL)
                return 0;

        float Sum = 0;
        int i = 0;

        for (i = 0; i < Num; i++)
                Sum += R[i];

        printf("Averange = %f\n", Sum/Num);
        return Sum/Num;
}

void DeletEl(float R[], int Num)
{
        if(R == NULL)
                return 0;

        int i = 0;

        for (i = 1; i < Num; i++)
                R[i - 1] = R[i];

        R[Num - 1] = 0;
}


int DataSelect(int Num, float R[])
{
        if(R == NULL)
                return 0;

        int i = 0, K = 0;
        float averange = Averange(Num, R);

        for (i = 0; i < Num; i++)
                if(fabs((R[i] - averange)/averange) > 0.03)
                {
                        printf("d = %f\n",fabs((R[i] - averange)/averange));

                        DeletEl(&(R[i]), Num - i - 1);
                        K++;
                }

        return Num - K;
}

void MasOut (float *a, int Size)
{
        if(R == NULL)
                return 0;

        int i = 0;

        for(i = 0; i < Size; i++)
                printf("%.1lf  ", a[i]);
        printf("\n");
}
