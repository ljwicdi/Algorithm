#include <iostream>
using namespace std;

int sorting(int* arr);

int main() {
    int v[4];
    int i=0, num;
    while(i<4){ 
        cin>>num;
        v[i]=num;
        i++;
    }
    cout<<sorting(v);
}

int sorting(int* arr){ 
    int temp; 
    for(int i=0;i<3;i++){
        for(int j=i+1;j<4;j++){ 
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return arr[0]*arr[2]; 
}