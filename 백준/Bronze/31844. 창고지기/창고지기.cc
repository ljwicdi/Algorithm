
#include <iostream>
using namespace std;
int main() {
    int robot, flag, box;
    char c;
    for (int i = 0; i < 10; i++) {
        cin >> c;
        if (c == '!') {
            flag = i;
        } else if (c == '@') {
            robot = i;
        } else if (c == '#') {
            box = i;
        }
    }
    
    if (robot < box && box < flag) {
        cout << (box - robot - 1) + (flag - box);
    } else if (flag < box && box < robot) {
        cout << (robot - box - 1) + (box - flag);
    } else {
        cout << "-1";
    }

    return 0;
}