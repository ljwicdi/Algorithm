#include <stdio.h>
 
int max(int a, int b);
 
int main(void){
    int N, K;
    scanf("%d %d", &N, &K);
    
    int value[N+1][K+1];
    int item[N][2];
    
    for(int i=0; i<N; i++){
        scanf("%d %d", &item[i][0], &item[i][1]);
    }
 
    for(int i=0; i<N+1; i++){
        value[i][0] = 0;
    } 
    for(int i=0; i<K+1; i++){
        value[0][i] = 0;
    }
    
    for(int i=1; i<N+1; i++){
        for(int j=1; j<K+1; j++){
            if(item[i-1][0]>j)
                value[i][j] = value[i-1][j];
            else{
                value[i][j] = max(value[i-1][j], value[i-1][j-item[i-1][0]] + item[i-1][1]);
            }
        }
    }
     printf("%d\n", value[N][K]);
}
 
int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}