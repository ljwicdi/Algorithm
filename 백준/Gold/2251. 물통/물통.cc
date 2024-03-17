#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

struct node {
    int A;
    int B;
    int C;
    
};
int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    set<int> k;
   
    set<int> result;
    result.insert(C);
    // 초기상태
    node nd;
    nd.A = 0;
    nd.B = 0;
    nd.C = C;
    queue<node> q;
    q.push(nd);
    while (!q.empty()) {
        // c가 0인 경우가 왜 생길까 ? 
        auto s = q.front();
        
        if (k.find(100000 * s.A + 1000 * s.B + 1 * s.C) != k.end()) {
            q.pop();
            continue;
        }
        if (s.A == 0) {
            
            result.insert(s.C);
        }
            
        k.insert(100000 * s.A + 1000 * s.B + 1 * s.C);
        q.pop();
        
        // 6가지 경우 다 고려 ?
        // A -> C
        node nd;
        // 현재 채울 수 있는 양 
        int able = C - s.C;
        if (able < s.A) {
            nd.C = C;   // 가득 채우고
            nd.A = s.A - able;
        } else {
            nd.C = s.C + s.A;
            nd.A = 0;
        }
        nd.B = s.B;
        q.push(nd);
        
        // A -> B
        able = B - s.B;
        if (able < s.A) {
            nd.B = B;   // 가득 채우고
            nd.A = s.A - able;
        } else {
            nd.B = s.B + s.A;
            nd.A = 0;
        }
        nd.C = s.C;
        q.push(nd);
        
        // B -> C
        able = C - s.C;
        if (able < s.B) {
            nd.C = C;   // 가득 채우고
            nd.B = s.B - able;
        } else {
            nd.C = s.C + s.B;
            nd.B = 0;
        }
        nd.A = s.A;
        q.push(nd);
        
        // B -> A 
        able = A - s.A;
        if (able < s.B) {
            nd.A = A;   // 가득 채우고
            nd.B = s.B - able;
        } else {
            nd.A = s.A + s.B;
            nd.B = 0;
        }
        nd.C = s.C;
        q.push(nd);
        
        // C -> A
        able = A - s.A;
        if (able < s.C) {
            nd.A = A;   // 가득 채우고
            nd.C = s.C - able;
        } else {
            nd.A = s.A + s.C;
            nd.C = 0;
        }
        nd.B = s.B;
        q.push(nd);
        
        // C -> B
        able = B - s.B;
        if (able < s.C) {
            nd.B = B;   // 가득 채우고
            nd.C = s.C - able;
        } else {
            nd.B = s.B + s.C;
            nd.C = 0;
        }
        nd.A = s.A;
        q.push(nd);
        
    }
    
    for (auto s : result) {
        cout << s << " ";
    }
    return 0;
}
