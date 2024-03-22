#include <string>
#include <vector>
#include <set>
using namespace std;

bool solution(vector<string> phone_book) {
    // 접두어 .. 가장 앞
    // 브루트포스는 불가능 (입력의 크기가 너무 크다)
    // n log n 으로 해결 
    set<int> sizeRepo;
    for (int i = 0; i < phone_book.size(); i++) {
        sizeRepo.insert(phone_book[i].length());
    }
    
    set<string> mySet;
    for (int i = 0; i < phone_book.size(); i++) {
        for (auto s : sizeRepo) {
            if (phone_book[i].length() > s) {
                string temp = "";
                for (int k = 0; k < s; k++) {
                    temp += phone_book[i][k];
                }
                mySet.insert(temp);
            }
        }    
    }
    
    bool answer = true;
    for (int i = 0; i < phone_book.size(); i++) {
        if (mySet.find(phone_book[i]) != mySet.end()) {
            answer = false;
        }
    }
    
    return answer;
}