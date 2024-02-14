#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n;
int arr[200020], ans[200020];
set<int>s;
 
int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
 
    ans[arr[0]] = -1;
    s.insert(arr[0]);
    for (int i = 1; i < n; i++) {
        if (s.count(arr[i])) continue;
        ans[arr[i]] = arr[i - 1];
        s.insert(arr[i]);
    }
    printf("%ld\n", s.size());
    for (int i = 0; i < s.size(); i++) printf("%d ", ans[i]); puts("");
}