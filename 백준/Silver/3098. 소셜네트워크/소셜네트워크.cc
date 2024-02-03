#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> friendship(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        friendship[A][B] = true;
        friendship[B][A] = true;
    }

    vector<int> newFriendshipsPerDay;
    int days = 0;

    while (true) {
        vector<vector<bool>> tempFriendship = friendship;
        int newFriendships = 0;

        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                if (!friendship[i][j]) {
                    for (int k = 1; k <= N; ++k) {
                        if (friendship[i][k] && friendship[k][j]) {
                            tempFriendship[i][j] = true;
                            tempFriendship[j][i] = true;
                            newFriendships++;
                            break;
                        }
                    }
                }
            }
        }

        if (newFriendships == 0) {
            break;
        }

        friendship = tempFriendship;
        newFriendshipsPerDay.push_back(newFriendships);
        days++;
    }

    cout << days << "\n";
    for (int i = 0; i < newFriendshipsPerDay.size(); ++i) {
        cout << newFriendshipsPerDay[i] << "\n";
    }

    return 0;
}
