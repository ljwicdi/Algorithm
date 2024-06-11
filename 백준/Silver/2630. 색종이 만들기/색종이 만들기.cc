
#include <iostream>
#include <vector>
using namespace std;

vector<int> v[128];
int whiteCnt = 0;
int blueCnt = 0;

bool sameColor(int startX, int endX, int startY, int endY) {
    if (startX == endX && startY == endY) return true;
    
    int criteria = v[startX][startY];
    
    for (int i = startX; i < endX; i++) {
        for (int j = startY; j < endY; j++) {
            if (criteria != v[i][j]) {
                return false;
            }
        }
    }
    
    return true;
}

void colorCount(int startX, int endX, int startY, int endY) {
    if (v[startX][startY] == 1) {
        blueCnt++;
    } else {
        whiteCnt++;
    }
}

void solve(int startX, int endX, int startY, int endY) {
    
    if (sameColor(startX, endX, startY, endY)) {
        colorCount(startX, endX, startY, endY);
        return;
    }
    
    solve(startX, (startX + endX) / 2, startY, (startY + endY) / 2);
    solve(startX, (startX + endX) / 2, (startY + endY) / 2, endY);
    solve((startX + endX) / 2, endX, startY, (startY + endY) / 2);
    solve((startX + endX) / 2, endX, (startY + endY) / 2, endY);
}

int main() {
    
    int N;
    cin >> N;
    int data;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> data;
            v[i].push_back(data);
        }
    }
    
    solve(0, N, 0, N);
    
    cout << whiteCnt << "\n";
    cout << blueCnt;

    return 0;
}
