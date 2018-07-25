#include<bits/stdc++.h>
using namespace std;
int a[5][5]={0},ans=0,r[5]={0},l[5]={0},u[10]={0},d1=0,d2=0;
bool check(int i,int j){
	if(i==3&&l[j]!=15) return 0;
	if(j==3&&r[i]!=15) return 0;
	if(i==3&&j==1&&d2!=15) return 0;
	if(i==3&&j==3&&d1!=15) return 0;
	return 1;
}
void s(int i,int j){
	if(i>3){
		ans++;
	}
	if(j>3){
		s(i+1,1);
	}
	else{
		for(int k=1;k<10;k++){
			if(u[k]==0){
				u[k]=1;
				r[i]=r[i]+k;
				l[j]=l[j]+k;
				if(i==j) d1=d1+k;
				if(i+j==4) d2=d2+k;
				if(check(i,j)){
					s(i,j+1);
				}
				u[k]=0;
				r[i]=r[i]-k;
				l[j]=l[j]-k;
				if(i==j) d1=d1-k;
				if(i+j==4) d2=d2-k;
			}
		}	
	}
}

int main(){
	s(1,1);
	cout<<ans<<endl;
}
