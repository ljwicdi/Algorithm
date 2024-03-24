#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    map<int, int> myMap;
    for (int i = 0; i < arr.size(); i++) {
        int k = 1;
        while (k <= 2000000) {
            if (myMap.find(arr[i] * k) == myMap.end()) {
                myMap[arr[i] * k] = 1;
            } else {
                myMap[arr[i] * k]++;
            }
            k++;
        }
    }
    
    for (auto s : myMap) {
        if (s.second == arr.size()) {
            answer = s.first;
            break;
        }
    }
    return answer;
}