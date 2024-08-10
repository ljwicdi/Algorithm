#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
bool visited[8]; // N의 최대값이 8이므로 방문 체크 배열

void solve(vector<int>& nums, int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
        return;
    }

    int last = -1; // 이전에 선택한 숫자를 저장
    for (int i = 0; i < N; i++) {
        if (!visited[i] && last != v[i]) { // 방문하지 않았고, 이전에 선택한 숫자와 다를 경우에만 선택
            visited[i] = true;
            nums.push_back(v[i]);
            solve(nums, depth + 1);
            nums.pop_back();
            visited[i] = false;
            last = v[i]; // 이전에 선택한 숫자로 업데이트
        }
    }
}

int main() {
    cin >> N >> M;
    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end()); // 중복 수열을 방지하기 위해 정렬

    vector<int> nums;
    solve(nums, 0);

    return 0;
}