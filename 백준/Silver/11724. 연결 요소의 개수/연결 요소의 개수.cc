
#include <iostream>
#include <set>
using namespace std;

int ids[1001]; // 1~1000;
int sizes[1001];



int root(int a) {
    while (a != ids[a]) {
        a = ids[a];
    }
    
    return a;
}

void uni(int a, int b) {
    if(sizes[root(a)] > sizes[root(b)]) {
        ids[root(b)] = root(a);
        sizes[root(b)] = sizes[root(b)] + sizes[root(a)];
    } else {
        ids[root(a)] = root(b);
        sizes[root(a)] = sizes[root(a)] + sizes[root(b)];
    }
}

bool find(int a, int b) {
    if (root(a) == root(b)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    

    for (int i = 1; i < 1001; i++) {
        ids[i] = i;
        sizes[i] = 0;
    }
    
    // union - find (방향성 없는 그래프, 연결요소)
    
    int N, M;
    int a, b;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        
        if (!find(a, b)) {
            uni(a, b);
        }  
    }
    
    
    
    set<int> mySet;
    for (int i = 1; i <= N; i++) {
        mySet.insert(root(ids[i]));
    }
    
    cout << mySet.size();
    return 0;
}
