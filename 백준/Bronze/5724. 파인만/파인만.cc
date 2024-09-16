#include <iostream>
 
int main()
{
    while (1)
    {
        int t;
        std::cin >> t;
    
        if (t == 0) break;
 
        int answer = 0;
        for (int i = t; i > 0; i--)
        {
            answer += (i * i);
        }
        std::cout << answer << "\n";
    }
 
    return 0;
}