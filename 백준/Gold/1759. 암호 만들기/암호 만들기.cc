
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> mo;
vector<char> ja;

vector<string> moCombi;
vector<string> jaCombi;
void combination(int depth, int next, int r, string str, int n, bool isMo) {
    
    if (depth == r) {
        if (isMo) {
            moCombi.push_back(str);
        } else {
            jaCombi.push_back(str);
        }
        return;
    }
    
    for (int i = next; i < n; i++) {
        string newStr = str;
        if (isMo) {
            newStr += mo[i];    
            combination(depth + 1, i + 1, r, newStr, n, true);   
        } else {
            newStr += ja[i];
            combination(depth + 1, i + 1, r, newStr, n, false);
        }
    }
}

int main() {
    
    int L, C;
    cin >> L >> C;
    
    for (int i = 0; i < C; i++) {
        char alpha;
        cin >> alpha;
        if (alpha == 'a' || alpha == 'e' || alpha == 'i' || alpha == 'o' || alpha == 'u') {
            mo.push_back(alpha);
        } else {
            ja.push_back(alpha);
        }
    }
    
    vector<string> result;
    for (int i = 1; i <= mo.size(); i++) {
        moCombi.clear();
        jaCombi.clear();
        // depth, next, r, str, n
        string str = "";
        
        int moR = i;
        int jaR = L - i;
        
        if (jaR < 2) continue;
        
        combination(0, 0, moR, str, mo.size(), true);
        combination(0, 0, jaR, str, ja.size(), false);
        
        for (int j = 0; j < moCombi.size(); j++) {
            for (int k = 0; k < jaCombi.size(); k++) {
                vector<char> temp;
                string a = moCombi[j];
                string b = jaCombi[k];
                
                for (int l = 0; l < a.length(); l++) {
                    temp.push_back(a[l]);
                }
                for (int l = 0; l < b.length(); l++) {
                    temp.push_back(b[l]);
                }
                
                sort(temp.begin(), temp.end());
                string resultStr = "";
                for (auto s : temp) {
                    resultStr += s;
                }
                
                result.push_back(resultStr);
            }
        }
    }
    
    sort(result.begin(), result.end());
    
    for (auto s : result) {
        cout << s << "\n";
    }
    return 0;
}
