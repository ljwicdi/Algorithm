
/*
5 x 5 크기의 보드가 주어진다. 보드는 1 x 1 크기의 정사각형 격자로 이루어져 있다. 보드의 격자에는 -1, 0, 1중 하나의 숫자가 적혀 있다. 격자의 위치는 (r, c)로 표시한다. r은 행 번호, c는 열 번호를 나타낸다. 행 번호는 맨 위 위치가 0이고 아래 방향으로 1씩 증가한다. 열 번호는 맨 왼쪽 위치가 0이고 오른쪽 방향으로 1씩 증가한다. 즉, 맨 왼쪽 위 위치가 (0, 0), 맨 아래 오른쪽 위치가 (4, 4)이다. -1이 적혀 있는 칸으로는 이동할 수 없고 0, 1이 적혀 있는 칸으로는 이동할 수 있다.

현재 한 명의 학생이 (r, c) 위치에 있고 한 번의 이동으로 상, 하, 좌, 우 방향 중에서 한 방향으로 한 칸 이동할 수 있다. 학생이 현재 위치 (r, c)에서 시작하여 1이 적혀 있는 칸에 도착하기 위한 최소 이동 횟수를 출력하자. 현재 위치 (r, c)에서 시작하여 1이 적혀 있는 칸으로 이동할 수 없는 경우 –1을 출력한다. 보드에는 1이 적혀 있는 격자가 1개 주어진다.    
*/

/*
첫 번째 줄부터 다섯 개의 줄에 걸쳐 보드의 정보가 순서대로 주어진다. i번째 줄의 j번째 숫자는 보드의 (i - 1)번째 행, (j - 1)번째 열의 정보를 나타낸다. 보드의 정보는 -1, 0, 1중 하나이다.

다음 줄에 학생의 현재 위치 r, c가 빈칸을 사이에 두고 순서대로 주어진다.
*/

/*
학생이 현재 위치 (r, c)에서 1이 적혀 있는 칸에 도착하기 위한 최소 이동 횟수를 출력한다. 현재 위치 (r, c)에서 1이 적혀 있는 칸으로 이동할 수 없는 경우 -1을 출력한다.
*/

/*
0 ≤ r, c ≤ 4
학생의 현재 위치 (r, c)에는 0이 적혀 있다.
1이 적혀 있는 격자가 1개 주어진다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int r, c;
struct Student {
    int x;
    int y;
    int count;
};

bool chkEastWall(int x, int y) {
    if (y == 4) {
        return false;
    } else {
        return true;
    }
}

bool chkNorthWall(int x, int y) {
    if (x == 0) {
        return false;
    } else {
        return true;
    }
}

bool chkWestWall(int x, int y) {
    if (y == 0) {
        return false;
    } else {
        return true;
    }
}

bool chkSouthWall(int x, int y) {
    if (x == 4) {
        return false;
    } else {
        return true;
    }
}

Student tossObject(int x, int y, int count) {
    Student student;
    student.x = x;
    student.y = y;
    student.count = count;

    return student;
}
int main(void) {

    int data;
    vector<int> v[5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> data;
            v[i].push_back(data);
        }
    }

    
    cin >> r >> c;
    Student student;
    student.x = r;
    student.y = c;
    student.count = 0;

    queue<Student> q;
    set<pair<int, int>> mySet;
    mySet.insert(make_pair(r, c));
    q.push(student);
    
    int result = -1;
    while (!q.empty()) {
        auto s = q.front();
        
        if (v[s.x][s.y] == 1) {
            result = s.count;
            break;
        }
        q.pop();

        if (chkEastWall(s.x, s.y)) {
            if (v[s.x][s.y + 1] != -1) {
                if (mySet.find(make_pair(s.x, s.y + 1)) == mySet.end()) {
                    mySet.insert(make_pair(s.x, s.y + 1));
                    Student student = tossObject(s.x, s.y + 1, s.count + 1);
                    q.push(student);
                }
            }
        }

        if (chkNorthWall(s.x, s.y)) {
            if (v[s.x - 1][s.y] != -1) {
                if (mySet.find(make_pair(s.x - 1, s.y)) == mySet.end()) {
                    mySet.insert(make_pair(s.x - 1, s.y));
                    Student student = tossObject(s.x - 1, s.y, s.count + 1);
                    q.push(student);
                }
            }
        }

        if (chkWestWall(s.x, s.y)) {
            if (v[s.x][s.y - 1] != -1) {
                if (mySet.find(make_pair(s.x, s.y - 1)) == mySet.end()) {
                    mySet.insert(make_pair(s.x, s.y - 1));
                    Student student = tossObject(s.x, s.y - 1, s.count + 1);
                    q.push(student);
                }
            }
        }

        if (chkSouthWall(s.x, s.y)) {
            if (v[s.x + 1][s.y] != -1) {
                if (mySet.find(make_pair(s.x + 1, s.y)) == mySet.end()) {
                    mySet.insert(make_pair(s.x + 1, s.y));
                    Student student = tossObject(s.x + 1, s.y, s.count + 1);
                    q.push(student);
                }
            }
        }

    }
    
    cout << result;
    return 0;
}