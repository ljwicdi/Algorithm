
#include <iostream>
using namespace std;
int main() {
    int N;
    string str;
    cin >> N;
    cin >> str;
    for (int i = str.length() - 5; i < str.length(); i++) {
        cout << str[i];
    }
    return 0;
}