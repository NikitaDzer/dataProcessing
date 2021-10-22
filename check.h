int check (int K, float resistance[], float resistance_final)
{
    int i;
    float sum = 0;
    for (i=0; i<K; i++){
        sum += resistance[i];
    }
    int rez;
    rez = (sum - K * resistance_final)/K;
    if (rez == 0){
        return 1;
    }
    if (rez != 0){
        return 0 ;
    }
}
