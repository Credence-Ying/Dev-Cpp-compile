#include<bits/stdc++.h>
using namespace std;

int a,b,c,x=0;

int main(){
	cin>>a>>b>>c; //a b c分别是除以3 5 7的余数 
	for(int i=10;i<=100;i++){
		if(i%3==a && i%5==b && i%7==c) x=i;
	}
	cout<<x;
	return 0;
}
