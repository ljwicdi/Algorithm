#include <iostream>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int p=0,cnt=0;
    cin >> p;

    for(int i=1;i*i<=p;i++){
        cnt++;
    }
    cout << cnt;

    return 0;
}
