#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> v[N];
    vector<bool> visited(N, false);
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (i == 0 && str[i] == 'W') {
            continue;
        }
        if (i == str.length() - 1 && str[i] == 'E') {
            continue;
        }
        
        if (str[i] == 'E') {
            v[i].push_back(i + 1);
            v[i + 1].push_back(i);
        }
        if (str[i] == 'W') {
            v[i].push_back(i - 1);
            v[i - 1].push_back(i);
        }
    }
    
    queue<int> q;
    q.push(0);
    visited[0] = true;
    
    int result = 0;
    
    int index = 0;
    while (1) {
        while (1) {
            if (visited[index] == false) {
                break;
            }
            index++;
            if (index == N) {
                break;
            }
        }
        if (index == N) {
            break;
        }
        
        queue<int> q;
        q.push(index);
        visited[index] = true;
        result++;
        
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
            
            for (auto k : v[s]) {
                if (visited[k] == false) {
                    visited[k] = true;
                    q.push(k);

                }
            }
        }
    }
    
    cout << result;
    return 0;
}
