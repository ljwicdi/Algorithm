#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) {
        return true;
    } else if (a.second == b.second) {
        if (a.first < b.first) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

int main() {
    
    int N;
    cin >> N;
    int data;
    vector<int> v;
    map<int, int> myMap;
    double sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> data;
        v.push_back(data);
        sum += data;
        myMap[data]++;
    }
    
    sort(v.begin(), v.end());
    // 반올림 
    double first = sum / N;
    if (first > 0) {
        if (first - (int)first >= 0.5) {
            first = (int)(first + 1);
        } 
    } else {
        if (first - (int)first <= -0.5) {
            first = (int)first - 1;
        }
    }
    // 3.5 -> 4
    // -2.5 -> -3 
    // -2.5 - (-2) = -0.5
    cout << (int)first << "\n";
    
    cout << v[N / 2] << "\n";
    
    vector<pair<int, int>> temp(myMap.begin(), myMap.end());
    sort(temp.begin(), temp.end(), comp);
    if (temp[0].second == temp[1].second) {
        cout << temp[1].first << "\n";
    } else {
        cout << temp[0].first << "\n";
    }
    
    cout << v[N - 1] - v[0];
    return 0;
}
