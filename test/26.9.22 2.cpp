#include<bits/stdc++.h>
using namespace std;

int a,b,c,D=0,x1,x2;

int main(){
	cin>>a>>b>>c;
	D=b*b-4*a*c;
	x1=(-b+sqrt(D))/(2*a);
	x2=(-b-sqrt(D))/(2*a);
	cout<<"x1="<<x1<<' '<<"x2="<<x2<<endl;
	return 0;
}
