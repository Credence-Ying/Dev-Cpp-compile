#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main(){
	int N,sum1=0;
	cin>>N;
	int a[1005];
	for(int i=1;i<=N;i++) cin>>a[i];
	
	for(int i=1;i<=N-1;i++){
		for(int j=1;j<=N-i;j++)
		{
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				sum1++;
			}
		}
	}
	//快排就是每次会把最大或最小的移到最边上去，下一轮操作就可以少执行一轮，因此用j <= N - i
	cout<<sum1;
	return 0;
}
