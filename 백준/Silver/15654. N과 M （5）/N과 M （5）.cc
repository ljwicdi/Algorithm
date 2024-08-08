#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<int> v;
int N, M;
void combination(vector<int> & nums, int currentDepth, int currentIndex, set<int> & mySet) {
    if (currentDepth == M) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (mySet.find(v[i]) != mySet.end()) {
            continue;
        }
        nums.push_back(v[i]);
        mySet.insert(v[i]);
        combination(nums, currentDepth + 1, i, mySet);
        nums.pop_back();
        mySet.erase(v[i]);
    }
}

int main() {

    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    sort(v.begin(), v.end());
    
    vector<int> nums;
    set<int> mySet;
    for (int i = 0; i < N; i++) {
        nums.push_back(v[i]);
        mySet.insert(v[i]);
        combination(nums, 1, i, mySet);
        nums.pop_back();
        mySet.erase(v[i]);
    }

    return 0;
}