

#include <iostream>

using namespace std;


int main()
{
    string name, result;
    int age, kg;
    while (1) {
        cin >> name >> age >> kg;
        if (name == "#" && age == 0 && kg == 0) {
            break;
        }
        if (age > 17 || kg >= 80) {
            result = "Senior";
        } else {
            result = "Junior";
        }
        
        cout << name << " " << result << "\n";
    }
    return 0;
}
