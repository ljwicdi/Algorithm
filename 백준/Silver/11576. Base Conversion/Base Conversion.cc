#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int num_10 = 0;
vector<int> remain;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int A, B;
    cin >> A >> B;

    int N; cin >> N;

    vector<int> Anum(N);
    for (int i = N - 1; i >= 0; i--) {
        cin >> Anum[i]; //거꾸로 넣기(10진수로 계산할때 index 편리하도록)
    }

    //A를 10진수로 바꾸기
    for (int i = 0; i < N; i++) {
        num_10 += Anum[i] * pow(A, i);
    }

    //10진수를 B로 바꾸기
    while (num_10 >= B) {
        remain.push_back(num_10 % B);
        num_10 = num_10 / B;
        if (num_10 < B) {
            remain.push_back(num_10);
        }
    }

    for (int i = remain.size() - 1; i >= 0; i--) {
        cout << remain[i] << " ";
    }

    return 0;
}