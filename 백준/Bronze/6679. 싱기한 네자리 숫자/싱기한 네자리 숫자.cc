
#include <iostream>
using namespace std;

int isTen(int i) {
    int sum = 0;
    
    while (i != 0) {
        sum = sum + i % 10;
        i = i / 10;
    }
    
    return sum;
}

int isTwelve(int i) {
    int sum = 0;
    
    while (i != 0) {
        sum = sum + i % 12;
        i = i / 12;
    }
    
    return sum;
}

int isSix(int i) {
    int sum = 0;
    
    while (i != 0) {
        sum = sum + i % 16;
        i = i / 16;
    }
    
    return sum;
}

int main() {
    
    for (int i = 1000; i <= 9999; i++) {
        if (isTen(i) == isTwelve(i)) {
            if (isTwelve(i) == isSix(i)) {
                cout << i << "\n";
            }
        } 
    }
    return 0;
}
