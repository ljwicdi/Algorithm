#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) {
        return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<int> result(N, 0);
    // <데이터, 인덱스>
    vector<pair<int, int>> v;
    int data;
    for (int i = 0; i < N; i++) {
        cin >> data;
        v.push_back(make_pair(data, i));
    }
    
    sort(v.begin(), v.end(), comp);
    
    set<int> mySet;
    for (int i = 0; i < v.size(); i++) {
        mySet.insert(v[i].first);
        result[v[i].second] = mySet.size() - 1;
    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
