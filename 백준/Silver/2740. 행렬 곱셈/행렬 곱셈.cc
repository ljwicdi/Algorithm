#include <bits/stdc++.h>
using namespace std;
int main(){
	int A[101][101]={0,};
	int B[101][101]={0,};
	int result[101][101]={0,};
	int N,M,K;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>A[i][j];
		}
	}
	cin>>M>>K;
	for(int i=0;i<M;i++){
		for(int j=0;j<K;j++){
			cin>>B[i][j];
		}
	}		
	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			for(int v=0;v<M;v++){
				result[i][j]+=A[i][v]*B[v][j];	
			}
			cout<<result[i][j]<<" ";		
		}
		cout<<"\n";
	}
	return 0;
}