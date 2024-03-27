#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> mySet;
    vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < elements.size(); j++) {
            v.push_back(elements[j]);
        }
    }
    
    for (int i = 0; i < v.size() - elements.size(); i++) {
        int sum = 0;
        for (int j = i; j < i + elements.size(); j++) {
            sum = sum + v[j];
            mySet.insert(sum);
        }
        
    }
    answer = mySet.size();
    return answer;
}