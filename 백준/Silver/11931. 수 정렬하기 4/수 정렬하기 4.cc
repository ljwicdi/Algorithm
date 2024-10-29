#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    //greater<자료형> 내림차순 함수
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; i++)
        cout << a[i] << '\n';
}