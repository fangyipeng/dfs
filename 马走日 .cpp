#include<iostream>
using namespace std;
const int dx[8]= {1,1,-1,-1,2,2,-2,-2};
const int dy[8]= {2,-2,2,-2,1,-1,1,-1};
bool a[5][4];

bool check(int x,int y)
{
	if(a[x][y]==1)return false;
	if(x>4||y>3)return false;
	if(x<0||y<0)return false;
	return true;
}

int ans=0;
void dfs(int x,int y,int temp)
{
	int x1,y1;
	if(temp==20)ans++;
	else
	{
		for(int i=0; i<8; i++)
		{
			x1=x+dx[i];
			y1=y+dy[i];
			if(check(x1,y1))
			{
				a[x1][y1]=1;
				dfs(x1,y1,temp+1);
				a[x1][y1]=0;
			}

		}

	}
}
int main()
{

	a[0][0]=1;
	dfs(0,0,1);
	cout<<ans;
	return 0;
}

