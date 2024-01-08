
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    
    for (int i = 0; i < str.length(); i++) {
        char temp = str[i] - 32;
        cout << temp;
    }

    return 0;
}
