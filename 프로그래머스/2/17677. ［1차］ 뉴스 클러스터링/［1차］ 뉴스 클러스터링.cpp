#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype> // 필요한 헤더 추가
using namespace std;

int solution(string str1, string str2) {
    
    map<string, double> A, B;
    set<string> mySet;
    double child = 0.0, parent = 0.0;
    
    // 문자열을 두 글자씩 끊어서 다중 집합을 만듦
    for (int i = 0; i < str1.length() - 1; i++) {
        string temp = "";
        // 대문자로 변환
        if (isalpha(str1[i]) && isalpha(str1[i+1])) {
            temp += toupper(str1[i]);
            temp += toupper(str1[i+1]);
            // A 집합에 추가
            A[temp]++;
            mySet.insert(temp);
        }
    }
    
    for (int i = 0; i < str2.length() - 1; i++) {
        string temp = "";
        if (isalpha(str2[i]) && isalpha(str2[i+1])) {
            temp += toupper(str2[i]);
            temp += toupper(str2[i+1]);
            // B 집합에 추가
            B[temp]++;
            mySet.insert(temp);
        }
    }
    
    // 유사도 계산
    for (const auto& s : mySet) {
        parent += max(A[s], B[s]);
        child += min(A[s], B[s]);
    }
    
    if (parent == 0) return 65536;
    
    return child / parent * 65536;
}
