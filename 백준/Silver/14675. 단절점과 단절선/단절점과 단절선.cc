
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    int N;
    cin >> N;
    vector<int> v[N + 1];
    int a, b;
    vector<pair<int, int>> edge;
    edge.push_back(make_pair(-1, -1));
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        edge.push_back(make_pair(a, b));
    }
    
    int qNum;
    cin >> qNum;
    int t, k;
    for (int i = 0; i < qNum; i++) {
        cin >> t >> k;
        
        if (t == 1) {
            if (v[k].size() == 1) {
                cout << "no\n";
            } else {
                cout << "yes\n";
            }
        } else {
            cout << "yes\n";
        }
    }
    return 0;
}
