#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

#define LOWER = 0
#define UPPER = 300;

int n;
int a[15]={0};
bool visited[15]={0};

void DFS(int pointer){
	if (pointer > n){
		for (int i=1; i<=n ;i++){
			printf("%5d", a[i]);
		}
		printf("\n");
	}
	
	for (int i=1; i<=n; i++){
		if (visited[i] == 0){
			a[pointer] = i;
			visited[i] = 1;
			DFS(pointer+1);
			visited[i] = 0;
		}
	}
}


int main(){
	scanf("%d",&n);
	DFS(1);
	return 0;
}