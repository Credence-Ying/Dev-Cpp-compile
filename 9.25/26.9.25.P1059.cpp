#include<bits/stdc++.h>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[105];
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int k=unique(a+1,a+n+1)-(a+1);
	cout<<k<<endl;
	for(int i=1;i<=k;i++) cout<<a[i]<<' ';
	return 0;
}