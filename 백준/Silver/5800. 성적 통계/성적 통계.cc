
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp (int a, int b) {
    if (a > b) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int K, N, data;
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        cin >> N;
        
        vector<int> v;
        for (int j = 0; j < N; j++) {
            cin >> data;
            v.push_back(data);
        }
        
        sort(v.begin(), v.end(), comp);
        int maxGap = v[0] - v[1];
        
        for (int j = 1; j < v.size()-1; j++) {
            if (maxGap < v[j] - v[j+1]) {
                maxGap = v[j] - v[j+1];
            }
        }
        
        int max = v[0];
        int min = v[v.size()-1];
        
        cout << "Class " << i + 1 << "\n";
        cout << "Max " << max << ", " << "Min " << min << ", " << "Largest gap " << maxGap << "\n";
        
    }
    return 0;
}
