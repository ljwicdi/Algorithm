#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int prev_num = arr[0];
    answer.push_back(prev_num);
    for (int i = 1; i < arr.size(); i++) {
        if (prev_num != arr[i]) {
            answer.push_back(arr[i]);
            prev_num = arr[i];
        }
    }

    return answer;
}