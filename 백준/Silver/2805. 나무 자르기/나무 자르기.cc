

#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    int N, M;
    cin >> N >> M;
    
    
    vector<int> tree(N);
    int mi = 0;
    int ma = 0;
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        
        if (ma < tree[i]) {
            ma = tree[i];
        }
       
    }
    
    if (mi == 1 && ma == 1) {
        cout << "0";
        return 0;
    }
    
    int result;
    while (1) {
        int mid = (mi + ma) / 2;
        
        long long cuttedTree = 0;
        for (int i = 0; i < N; i++) {
            if (tree[i] > mid) {
                cuttedTree += tree[i] - mid;
            }
        }
        
        if (cuttedTree == M || (mi == ma)) {
            result = mid;
            break;
        } else if (cuttedTree < M) {
            // 톱의 높이를 낮게
            if (ma == mid) {
                result = mid;
                break;
            }
                
            ma = mid;
            
        } else if (cuttedTree > M) {
            // 톱의 높이를 높게
            if (mi == mid) {
                result = mid;
                break;
            }
            mi = mid;
        }
    } 
    
    cout << result;
    
    return 0;
}