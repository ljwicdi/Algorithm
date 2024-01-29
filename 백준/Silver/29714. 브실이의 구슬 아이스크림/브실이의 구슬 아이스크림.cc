
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int N;  // 구슬 수
    int ball;
    map<int, int> myMap;
   
    
    cin >> N;
    int cnt = N;
    for(int i=0; i<N; i++)  // 구슬 담기
    {
        cin >> ball;
        
        if(myMap.find(ball) == myMap.end())
            myMap[ball] = 1;
        else
            myMap[ball]++;
    }
    
    int Q;
    int order;
    
    cin >> Q;
    
    for(int i=0; i<Q; i++)
    {
        map<int, int> myMap2;
        int flag = 0;
        vector<int> v;
        cin >> order;
        
        for(int j=0; j<order; j++)  // 제거 할 구슬 삽입
        {
            cin >> ball;
            if(myMap2.find(ball) == myMap2.end())
                myMap2[ball] = 1;
            else
                myMap2[ball]++;
        }
        
        for(auto s : myMap2)    // 없는 구슬이 적어도 하나가 있다면
        {
            if(myMap[s.first] < s.second)
            {
                flag = 1;
                break;
            }
        }
        
        if(flag == 0)   // 구슬이 다 존재한다면
        {
            for(auto s : myMap2)    // 먹음
            {
                myMap[s.first] = myMap[s.first] - s.second;
                cnt = cnt - s.second;
            }
        }
        
    
        cin >> order;
        
        for(int j=0; j<order; j++)
        {
            cin >> ball;
            if(flag == 1)   // 구슬이 적어도 하나가 없다면 아무것도 하지않음
                continue;
            
                // 그렇지 않다면 구슬 추가
            if(myMap.find(ball) == myMap.end())
                myMap[ball] = 1;
            else
                myMap[ball]++;
            cnt = cnt + 1;
        }
    }
    
    cout << cnt << "\n";
    
    if(cnt == 0)
        return 0;
        
    for(auto s : myMap)
    {
        for(int i=0; i<s.second; i++)
        {
            cout << s.first << " ";
        }
    }
    return 0;
}
