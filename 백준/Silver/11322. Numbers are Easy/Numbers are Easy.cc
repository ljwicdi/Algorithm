#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    
    int N;
    for (int i = 0; i < testCase; i++) {
        cin >> N;
        
        queue<string> q;
        q.push("1");
        
        string result = "";
        while (!q.empty()) {
            auto s = q.front();
            if (stol(s) % N == 0) {
                result = s;
                break;
            }
            q.pop();
            
            q.push(s + "0");
            q.push(s + "1");
        }
        
        cout << result << "\n";
    }

    return 0;
}
