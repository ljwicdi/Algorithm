
#include <iostream>
using namespace std;
int main()
{
    int order;
    // 북 1, 동 2, 남 3, 서 4
    char currentDirection = 'N';
    for (int i = 0; i < 10; i++) {
        cin >> order;
        
        if (order == 1) {
            if (currentDirection == 'N') {
                currentDirection = 'E';
                continue;
            } else if (currentDirection == 'E') {
                currentDirection = 'S';
                continue;
            } else if (currentDirection == 'S') {
                currentDirection = 'W';
                continue;
            } else {
                currentDirection = 'N';
                continue;
            }
        } else if (order == 2) {
            if (currentDirection == 'N') {
                currentDirection = 'S';
                continue;
            } else if (currentDirection == 'E') {
                currentDirection = 'W';
                continue;
            } else if (currentDirection == 'S') {
                currentDirection = 'N';
                continue;
            } else {
                currentDirection = 'E';
                continue;
            }
        } else {
            if (currentDirection == 'N') {
                currentDirection = 'W';
                continue;
            } else if (currentDirection == 'E') {
                currentDirection = 'N';
                continue;
            } else if (currentDirection == 'S') {
                currentDirection = 'E';
                continue;
            } else {
                currentDirection = 'S';
                continue;
            }
        }
    }
    
    cout << currentDirection;

    return 0;
}
