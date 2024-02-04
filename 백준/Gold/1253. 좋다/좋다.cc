#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> v;
    map<int, vector<pair<int, int>>> myMap;
    int data;
    for (int i = 0; i < N; i++) {
        cin >> data;
        v.push_back(data);
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (myMap.find(v[i] + v[j]) == myMap.end()) {
                vector<pair<int, int>> temp;
                temp.push_back(make_pair(i, j));
                myMap[v[i] + v[j]] = temp;
            } else {
                myMap[v[i] + v[j]].push_back(make_pair(i, j));
            }
        }
    }
    
    int result = 0;
    for (int i = 0; i < N; i++) {
        if (myMap.find(v[i]) != myMap.end()) {
            for (auto s : myMap[v[i]]) {
                
                if (s.first != i && s.second != i) {
                    result++;
                    break;
                }
            }
        }
    }
    
    cout << result;
    
    return 0;
}
