#include <iostream>

long long N;
long long sum = 0;
int main(int argc, char** argv){
  scanf("%lld", &N);

  for(long long i=1; i<N; i++){ 
    sum += i*N + i;
  }

  printf("%lld\n", sum);

  return 0;
}