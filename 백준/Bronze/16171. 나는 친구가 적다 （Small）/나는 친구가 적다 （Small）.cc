#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string str;
  cin>>str;
  string s;
  cin>>s;
  string temp = "";
  for(int i=0; i<str.size(); i++){
    if(str[i]>='0' && str[i]<='9') continue;
    else{
      temp+=str[i];
    }
  }
  if(temp.find(s)==string::npos){
    cout<<0<<"\n";
  }else{
    cout<<1<<"\n";
  }
 
}