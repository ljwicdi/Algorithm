
#include <iostream>

using namespace std;

int main()
{
    int N, M;
    int appleNum;
    cin >> N >> M;
    
    int left, right;
    left = 1, right = M;   // 초반 세팅, 바구니 왼쪽 = 0, 오른쪽 = N-1
    
    cin >> appleNum;
    
    int apple;
    int move = 0;
    for(int i=0; i<appleNum; i++)
    {
        cin >> apple;   // 사과 떨어짐
        
        if(apple >=left && apple <= right)
        {
            continue;   // 바구니 속으로 사과가 들어옴
        }
        else if(apple < left)
        {
            // 바구니 왼쪽으로 떨어진다면
            move = move + (left - apple);
            right = right - (left - apple);
            left = apple;
        }
        else if(apple > right)
        {
            // 바구니 오른쪽으로 떨떨어진다면
            move = move + (apple - right);
            left = left + (apple - right);
            right = apple;
        }
    }
    
    cout << move;
    
    
    

    return 0;
}
