
#include <iostream>
#include <string>
using namespace std;
int main() {
    
    int N;
    cin >> N;
    
    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        
        if (str == "P=NP") {
            cout << "skipped\n";
            continue;
        }
        
        int index = 0;
        int sum = 0;
        string a = "";
        while (1) {
            if (str[index] == '+') {
                index++;
                break;
            }
            
            a += str[index++];
        }
        
        sum += stoi(a);
        a = "";
        while (1) {
            if (index >= str.length()) {
                break;
            }
            
            a += str[index++];
        }
        
        sum += stoi(a);
        cout << sum << "\n";
    }
    return 0;
}
