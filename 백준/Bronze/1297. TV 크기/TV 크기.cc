#define _CRT_SECURE_NO_WARNINGS
#include <iostream>  
#include <cmath>
using namespace std;

int main() {

    int d,h,w;
    scanf("%d %d %d",&d, &h, &w);
   
    double r = sqrt( w * w + h * h);//대각선비
    double width = d * w / r;
    double height = d * h / r;
    printf("%d %d", (int)height, (int)width);

    return 0;
}