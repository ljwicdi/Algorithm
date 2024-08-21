#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void duplicatedCombination(int currentIndex, vector<int> & v, int r, vector<int> & result, set<vector<int>> & duplicateChk) {
   
    if (result.size() == r) {
       
        if (duplicateChk.find(result) == duplicateChk.end()) {
            for (auto s : result) {
                cout << s << " ";
            }
            cout << "\n";
           
            duplicateChk.insert(result);
        }
       
        return;
    }
   
    for (int i = currentIndex; i < v.size(); i++) {
        result.push_back(v[i]);
        duplicatedCombination(i, v, r, result, duplicateChk);
        result.pop_back();
    }
}

int main() {
   
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
   
    sort(v.begin(), v.end());
   
    vector<int> result;
    set<vector<int>> duplicateChk;
    duplicatedCombination(0, v, M, result, duplicateChk);

    return 0;
}