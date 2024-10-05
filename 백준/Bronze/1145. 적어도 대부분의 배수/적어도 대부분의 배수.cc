#include <iostream>

int a[5] = {0}; 
int num = 1;
int main(int argc, char** argv){
  for(int i = 0; i < 5; i++){
    scanf("%d", &a[i]);
  }

  while(1){
    int cnt = 0;
    for(int i = 0; i < 5; i++){
      if(num % a[i] == 0){
        cnt++;
      }
    }
    if(cnt >= 3){
      printf("%d", num);
      break;
    }
    num++;
  }

  return 0;
}