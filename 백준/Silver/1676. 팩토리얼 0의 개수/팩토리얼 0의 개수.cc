#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> divideInts(int i) {
    int two = 0, five = 0;
    while (i % 2 == 0) {
        i = i / 2;
        two++;
    }
    
    while (i % 5 == 0) {
        i = i / 5;
        five++;
    }
    
    return make_pair(two, five);
}

int main() {
    
    int N;
    cin >> N;
    
    int twoCount = 0, fiveCount = 0;
    for (int i = 1; i <= N; i++) {
        pair<int, int> result = divideInts(i);
        
        twoCount += result.first;
        fiveCount += result.second;
    }
    
    cout << min(twoCount, fiveCount);
    return 0;
}
