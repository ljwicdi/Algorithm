#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> mySet;
    int answer = 0;
    
    // 모든 종류의 개수를 카운트 하기 위해 집합에 넣어줌 
    for (int i = 0; i < nums.size(); i++) {
        mySet.insert(nums[i]);
    }
    
    // 최대 N/2개의 종류를 가지길 원하므로 이보다 많으면 
    // 답은 N/2개
    if (mySet.size() >= nums.size() / 2) {
        answer = nums.size() / 2;
        
    } else {
        // 그보다 작으면 nums에 담긴 포켓몬 종류의 수가 답이다.
        answer = mySet.size();
    }
    
    return answer;
}