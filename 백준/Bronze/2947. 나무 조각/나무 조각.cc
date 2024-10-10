#include <stdio.h>
const int SIZE = 5;
int arr[SIZE];
bool flag = true;
inline void swap(int &A, int &B) {
       int temp = A; A = B; B = temp;
}

void printArr() {
       for (int i = 0; i < SIZE; ++i) {
              printf("%d ", arr[i]);
       }
       printf("\n");
}

int main() {
       // freopen("input.txt", "r", stdin);
       
       // 5개 숫자 입력 받기
       for (int i = 0; i < 5; ++i)
       {
              scanf("%d", arr + i);
       }
       // 정렬이 완성될 때까지 수행
       while (flag)
       {
              flag = false;
              for (int i = 0; i < SIZE - 1; ++i) {
                     // 한번이라도 교환 발생한 경우
                     if (arr[i] > arr[i + 1]) {
                           flag = true;
                           swap(arr[i], arr[i + 1]);
                           // 교환될 때마다 상태 출력
                           printArr();
                     }
              }
       }
}