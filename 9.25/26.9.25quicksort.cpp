#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

struct Stu{
	string name;
	int score;
};
Stu a[105];
//定义结构体

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].name>>a[i].score;
	}
	
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n-i;j++){
			if(a[j].score<a[j+1].score || (a[j].score==a[j+1].score && a[j].name>a[j+1].name)){
				Stu temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		cout<<a[i].name<<' '<<a[i].score<<endl;
	}
	return 0;
}
