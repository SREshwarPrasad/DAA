#include<iostream>
#include<string.h>
#define max 10
using namespace std;

char x[max], y[max], b[max][max];

void printlcs(char b[][max], char x[], int i, int j)
{
	if(i==0 || j==0)
	{
		return; 
	}
	else if(b[i][j]=='d')
	{
		printlcs(b,x,i-1,j-1);
		cout<<x[i-1];
		
	}
	else if(b[i][j]=='l')
	{
		printlcs(b,x,i,j-1);
	}
	else if(b[i][j]=='u')
	{
		printlcs(b,x,i-1,j);
	}
}
void lcs(char x[], char y[])
{
	
	int m,n,i,j;
	int c[max][max];
	m=strlen(x); 
	n=strlen(y);
	cout<<"String length of X: "<<m<<endl;
	cout<<"String length of Y: "<<n<<endl;
	
	for(i=0; i<=m;i++)
	{
		c[i][0]=0;
	}
	for(j=0; j<=n;j++)
	{
		c[0][j]=0;
	}
	for(i=1; i<=m; i++)
	{
		for(j=1; j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='d';
			}
			else if(c[i][j-1]>c[i-1][j])
			{
				c[i][j]=c[i][j-1];
				b[i][j]='l';
			}
			else if(c[i][j-1]<c[i-1][j])
			{
				c[i][j]=c[i-1][j];
				b[i][j]='u';
			}
		}
	}
	
	cout<<"Table Pattern: "<<endl;
	for(i=1; i<=m; i++)
	{
		for(j=1; j<=n; j++)
		{
			cout<<c[i][j]<<b[i][j]<<"\t\t";
		}
		cout<<endl;
	}
	printlcs(b,x,m,n);
	cout<<endl;
}

int main()
{
	cout<<"X: ";
	cin>>x;
	cout<<"Y: ";
	cin>>y;
	lcs(x,y);
	return 0;
	
}
