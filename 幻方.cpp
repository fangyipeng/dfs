#include<iostream>
#include<cstring>
#define max 100
using namespace std;

int r[max],c[max],d1=0,d2=0;//r为行，c为列，d1为主对角线，d2为副对角线 
int vis[max],M[max][max];
int N=3,S=15;
int cnt=0;


bool check(int i,int j)
{
	if(i==N && c[j]!=S) return 0; 
	if(j==N && r[i]!=S) return 0;
	if(i==N && j==N && d1!=S) return 0;
	if(i==N && j==1 && d2!=S) return 0;
	return 1; 	
}

void dfs(int i,int j) //i表示行，j表示列 
{	
	if(i>N) cnt++; 
	else if(j>N) dfs(i+1,1);//本列已经放完,放下一列的第一个 
	else for(M[i][j]=1;M[i][j]<=N*N;M[i][j]++) 
	{	
		if(vis[M[i][j]]==0)//没用过 
		{
			vis[M[i][j]]=1;//用过的数标记一下 
			r[i]=r[i]+M[i][j];
			c[j]=c[j]+M[i][j];
			if(i-j==0) d1=d1+M[i][j];
			if(i+j==N+1) d2=d2+M[i][j];

			if(check(i,j)) dfs(i,j+1);
			
			vis[M[i][j]]=0;
			r[i]=r[i]-M[i][j];
			c[j]=c[j]-M[i][j];
			if(i-j==0) d1=d1-M[i][j];
			if(i+j==N+1) d2=d2-M[i][j];		
		}		
	}
}

int main(){
	memset(r,0,sizeof(r));
	memset(c,0,sizeof(c));
	memset(vis,0,sizeof(vis));
	memset(M,0,sizeof(M));
	
	dfs(1,1);
	cout<<cnt;
	return 0;
}
