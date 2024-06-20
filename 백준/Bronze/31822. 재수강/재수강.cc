
#include <iostream>
using namespace std;
int main() {
    
    string str;
    cin >> str;
    string frontFive = "";
    for (int i = 0; i < 5; i++) {
        frontFive += str[i];
    }
    int N;
    cin >> N;
    
    int result = 0;
    for (int i = 0; i < N; i++) {
        string data;
        cin >> data;
        string temp = "";
        for (int j = 0; j < 5; j++) {
            temp += data[j];
        }
        if (frontFive == temp) {
            result++;
        }
    }
    
    cout << result;
    
    return 0;
}