
#include <iostream>
using namespace std;

void result(int h1, int m1, int s1, int h2, int m2, int s2) {
    int results, resultm, resulth;
    
    if (s2 - s1 < 0) {
        m2--;
        results = 60 - (s1 - s2);
    } else {
        results = s2 - s1;
    }
    
    if (m2 - m1 < 0) {
        h2--;
        resultm = 60 - (m1 - m2);
    } else {
        resultm = m2 - m1;
    }
    
    resulth = h2 - h1;
    
    cout << resulth << " " << resultm << " " << results << "\n";
}

int main()
{
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    
    result(h1, m1, s1, h2, m2, s2);

    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    result(h1, m1, s1, h2, m2, s2);
    
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    result(h1, m1, s1, h2, m2, s2);
    return 0;
}


