#include <iostream>
using namespace std;
int a_count, b_count, c_count = 0;
int a=300, b=60, c=10;
int greedy(int t){

    while(t!=0){
        if (t >= a){
            a_count += t/a;
            t = t%a;
        }else if (t >= b){
            b_count += t/b;
            t = t%b;
        }else if (t >= c){
            c_count += t/c;
            t = t%c;
        }else{
            return -1;
        }
    }
    return 0;
}

int main(){

    int t;
    cin >> t;

    int result = greedy(t);

    if (result == 0){
        cout << a_count << " " << b_count << " " << c_count << endl;
    }
   
    else{
        cout << -1 << endl;
    }
}