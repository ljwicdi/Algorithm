
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        int k;
        priority_queue<int> maxPq;
        priority_queue<int, vector<int>, greater<int>> minPq;
        map<int, int> myMap;
        cin >> k;
        
        char order;
        int number;
        for (int j = 0; j < k; j++) {
            cin >> order >> number;
            
            if (order == 'I') {
                maxPq.push(number);
                minPq.push(number);
                myMap[number]++;
            } else if (order == 'D') {
                if (number == -1) {
                    if (minPq.empty()) continue;
                    while (myMap[minPq.top()] <= 0) {
                        minPq.pop();
                        
                        if (minPq.empty()) break;
                    }
                    
                    if (minPq.empty()) continue;
                    myMap[minPq.top()]--;
                    minPq.pop();
                } else if (number == 1) {
                    if (maxPq.empty()) continue;
                    while (myMap[maxPq.top()] <= 0) {
                        maxPq.pop();
                        
                        if (maxPq.empty()) break;
                    }
                    
                    if (maxPq.empty()) continue;
                    myMap[maxPq.top()]--;
                    maxPq.pop();
                }
            }
        }
        
        vector<int> v;
        while (!maxPq.empty()) {
            if (myMap[maxPq.top()] > 0) {
                v.push_back(maxPq.top());
                myMap[maxPq.top()]--;
            }
            
            maxPq.pop();
        }
        
        while (!minPq.empty()) {
            if (myMap[minPq.top()] > 0) {
                v.push_back(minPq.top());
                myMap[minPq.top()]--;
                  
            }
            
            minPq.pop();
            
        }
        
        sort(v.begin(), v.end());
        
        if (v.size() == 0) {
            cout << "EMPTY\n";
        } else if (v.size() == 1) {
            cout << v[0] << " " << v[0] << "\n";
        } else {
            cout << v[v.size() - 1] << " " << v[0] << "\n";
        }
    }

    return 0;
}