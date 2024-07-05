
#include <iostream>
#include <map>
using namespace std;
int main() {
    map<int, int> myMap;
    for (int i = 0; i < 5; i++) {
        int data;
        cin >> data;
        myMap[data]++;
    }
    
    for (pair<int, int> s : myMap) {
        if (s.second % 2 == 1) {
            cout << s.first;
        }
    }

    return 0;
}