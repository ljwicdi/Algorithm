#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
int n, m;
vector<int> vec;
 
vector<int> ans;
int main()
{
    cin >> n >> m;
    // 구구단 삽입
    for (int i = 1; i <= m; i++)
    {
        vec.push_back(i * n);
    }
 
    // 구구단 인자 순회
    for (int ele : vec)
    {
        // 문자열로 변환
        string temp = to_string(ele);
 
        // 문자열 뒤집기
        reverse(temp.begin(), temp.end());
        
        // 숫자로 변환해서 ans에 삽입
        ans.push_back(stoi(temp));
    }
 
    // 오름차순 정렬
    sort(ans.begin(), ans.end());
 
    // 마지막 인자 출력
    cout << ans[ans.size() - 1];
 
    return 0;
}