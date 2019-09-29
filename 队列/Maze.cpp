#include <iostream>
#include <queue>
using namespace std;
int atr[200][200];
int maze[500][500];

void Init(int r,int c,int ent,int exit)
{
	int row,clom;
	row=2*r+3; //迷宫的行 要多出额外两行 
	clom=2*c+1;//迷宫列 
	//初始化迷宫 1不可走，0可走 
	for(int i=0;i<row;i++)
	{
		maze[i][0]=1; //第一列与最后一列为1 
		maze[i][clom-1]=1;
	}
	
	for(int i=1;i<clom;i++)
	{
		maze[0][i]=0; //第一行与最后一行为0
		maze[row-1][i]=0;
		maze[1][i]=1;//第二行与倒数第二行为1 
		maze[row-2][i]=1;
	}
	maze[1][2*ent-1]=0;//入口 
	maze[row-2][2*exit-1]=0; //出口
	
	//一部分为0，一部分为1，顶点处必为1 
	for(int i=2;i<row-2;i++)
		for(int j=1;j<clom-1;j++)
			{
				if(i%2==0)
					maze[i][j]=0;
				else
					maze[i][j]=1;
			}
	
	//标记围墙部分 
	for(int i=2;i<row-2;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<c-1;i++)
				maze[i][2*j+2]=atr[i-2][j];
		}
		else
		{
			for(int j=0;j<c;j++)
				maze[i][2*j+1]=atr[i-2][j];
		}
	}
}

void Print(int r,int c)
{
	int row=2*r+3;
	int clom = 2*c+1;
	for(int i=0;i<row;i++)
	{
		for(int j=clom;j<clom;j++)
		{
			cout<<maze[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main ()
{
	int r,c,ent,exit;
	int t;
	cin>>r>>c>>ent>>exit;
	t=2*r-1;
	for(int i=0;i<t;i++)
	{
		if(i%2==0)
			for(int j=0;j<c-1;j++)
				cin>>atr[i][j];
		else
			for(int k=0;k<c;k++)
				cin>>atr[i][k];
	}
		
	Init(r,c,ent,exit);
	Print(r,c);
	return 0;
}
