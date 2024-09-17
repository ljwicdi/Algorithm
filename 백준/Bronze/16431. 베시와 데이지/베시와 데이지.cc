#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
//베시와 데이지 중 존에게 거리가 더 적은 소가 이김
int map[1001][1001];
int ck[1001][1001];
int bans[1001][1001];
int dans[1001][1001];
 
int bx[8] = { 0,0,1,-1,-1,-1,1,1 };
int by[8] = { 1,-1,0,0,1,-1,1,-1 };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int br, bc, dr, dc, jr, jc;
int b = 200000000, d = 200000000;
void B_BFS(int x,int y)
{
    memset(ck, 0, sizeof(ck));
    queue <pair<int,int>> q;
    q.push({ x,y });
    ck[x][y] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = x + bx[i];
            int ny = y + by[i];
            if (1 <= nx && nx <= 1000 && 1 <= ny && ny <= 1000)
            {
                if (map[nx][ny] == 0 && ck[nx][ny] == 0 || map[nx][ny]==2)
                {
                    ck[nx][ny] = 1;
                    bans[nx][ny] = bans[x][y] + 1;
                    q.push({ nx,ny });
                    if (map[nx][ny] == 2)
                    {
                        b = min(bans[nx][ny], b);
                    }
                }
            }
        }
    }
}
 
void D_BFS(int x, int y)
{
    memset(ck, 0, sizeof(ck));
    queue <pair<int, int>> q;
    q.push({ x,y });
    ck[x][y] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (1 <= nx && nx <= 1000 && 1 <= ny && ny <= 1000)
            {
                if (map[nx][ny] == 0 && ck[nx][ny] == 0 || map[nx][ny] == 2)
                {
                    ck[nx][ny] = 1;
                    dans[nx][ny] = dans[x][y] + 1;
                    q.push({ nx,ny });
                    if (map[nx][ny] == 2)
                    {
                        d = min(dans[nx][ny], d);
                    }
                }
            }
        }
    }
}
int main() {
    cin >> br >> bc >> dr >> dc >> jr >> jc;
    map[jr][jc] = 2;
    B_BFS(br, bc);
    D_BFS(dr, dc);
    if (b > d)
    {
        cout << "daisy" << '\n';
    }
    else if (b < d)
    {
        cout << "bessie" << '\n';
    }
    else
        cout << "tie" << '\n';
 
}