#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
 
    int m,n;
    cin>>m>>n;
 
    vector<int> vec;
 
    for(int i=m; i<=n; i++){
        int cnt=0;
        for(int j=1; j<=i; j++){
            if(i%j==0){
                cnt++;
            }
        }
        if(cnt==2){
            vec.push_back(i);
        }
    }
 
    int sum=0;
 
    for(int i=0; i<vec.size(); i++){
        sum+=vec[i];
    }
    if(vec.size()==0){
        cout<<"-1";
    }
    else{
        cout<<sum<<"\n"<<vec[0];
    }
}
