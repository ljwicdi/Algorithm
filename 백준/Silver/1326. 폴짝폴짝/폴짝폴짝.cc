
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main()
{
    int N, data, a, b;
    vector<int> v;
    cin >> N;
    
    v.push_back(0);
    for (int i = 0; i < N; i++) {
        cin >> data;
        
        v.push_back(data);
    }
    
    cin >> a >> b;
    
    queue< pair<int, int> > q;
    q.push(make_pair(a, 0));
    while (!q.empty()) {
        auto s = q.front();
        
        if (s.first == b) {
            cout << s.second;
            return 0;
        }
        
        q.pop();
        
        int i = 1;
        
        while (1) {
            
            if (s.first + i * v[s.first] > N) {
                break;
            }
            
            q.push(make_pair(s.first + i * v[s.first], s.second + 1));
            i++;
        }
        
        i = 1;
        
        while (1) {
            if (s.first - i * v[s.first] < 1) {
                break;
            }
            
            q.push(make_pair(s.first - i * v[s.first], s.second + 1));
            i++;
        }
        
    }
    
    cout << "-1";
    
    return 0;
}
