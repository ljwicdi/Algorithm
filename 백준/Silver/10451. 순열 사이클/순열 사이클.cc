
#include <iostream>
#include <set>
using namespace std;

int ids[1001];
int sizes[1001];

int root(int i) {
    while (ids[i] != i) {
        i = ids[i];
    }
    
    return i;
}

bool find(int a, int b) {
    if (root(a) == root(b)) {
        return true;
    } else {
        return false;
    }
}

void uni(int a, int b) {
    if (sizes[root(a)] >= sizes[root(b)]) {
        ids[root(b)] = a;
    } else {
        ids[root(a)] = b;
    }
}

int main()
{
    int testCase, N, data;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        cin >> N;
        set<int> mySet;
        for (int j = 1; j <= N; j++) {
            sizes[j] = 0;
            ids[j] = j;
        }
        
        for (int j = 1; j <= N; j++) {
            
            cin >> data;
            
            if (!find(j ,data)) {
                uni(j, data);
            }
        }
        
        for (int j = 1; j <= N; j++) {
            mySet.insert(root(ids[j]));
        }
        
        cout << mySet.size() << "\n";
        
    }

    return 0;
}
