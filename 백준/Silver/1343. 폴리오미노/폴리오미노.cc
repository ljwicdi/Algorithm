
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    
    int idx = 0;
    string result;
    while(1)
    {
        if(str[idx] == '.')
        {
            result = result + ".";
            idx++;
            if(idx == str.length())
            {
                cout << result;
                return 0;
            }
            continue;
        }
            
        // 처음 X발견
        string temp;
        while(str[idx] != '.')
        {
            temp+=str[idx];
            idx++;
            if(idx == str.length())
            {
                if(temp.length() % 4 == 1 || temp.length() % 4 == 3)
                {
                    cout << "-1";   // 덮을 수 없음
                    return 0;
                }
                else
                {
                    for(int i=0; i<temp.length()/4; i++)
                        result = result + "AAAA";
                    if(temp.length()%4 == 2)
                        result = result + "BB";
                }
                cout << result;
                return 0;
            }
        }
        
        if(temp.length() % 4 == 1 || temp.length() % 4 == 3)
        {
            cout << "-1";   // 덮을 수 없음
            return 0;
        }
        else    // 만들 수 있다면
        {
            for(int i=0; i<temp.length()/4; i++)
                result = result + "AAAA";
            if(temp.length()%4 == 2)
                result = result + "BB";
        }
    }
    
    cout << result;
    return 0;
}
