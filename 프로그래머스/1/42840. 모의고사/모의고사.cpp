#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp (pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

struct node {
    vector<int> v;
    int index;
    int answerCnt;
};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    node nd[3];
    nd[0].v = {1, 2, 3, 4, 5};
    nd[1].v = {2, 1, 2, 3, 2, 4, 2, 5};
    nd[2].v = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    for (int i = 0; i < 3; i++) {
        nd[i].index = 0;
        nd[i].answerCnt = 0;
    }
    
    for (int i = 0; i < answers.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if (answers[i] == nd[j].v[nd[j].index]) {
                nd[j].answerCnt++;
            }
            nd[j].index++;
            if (nd[j].index == nd[j].v.size()) {
                nd[j].index = 0;
            }
        }
    }
    
    vector<pair<int, int>> temp;
    for (int i = 0; i < 3; i++) {
        temp.push_back(make_pair(nd[i].answerCnt, i + 1));
    }
    
    sort(temp.begin(), temp.end(), comp);
    int max = temp[0].first;
    answer.push_back(temp[0].second);
    
    for (int i = 1; i < 3; i++) {
        if (max == temp[i].first) {
            answer.push_back(temp[i].second);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}