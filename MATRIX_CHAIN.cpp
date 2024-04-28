#include<iostream>
using namespace std;
int m[10][10], s[10][10];

void par(int s[][10],int i,int j)
{
	if(i==j)
		cout<<"A"<<i;
	else
	{
		cout<<"(";
		par(s,i,s[i][j]);
		par(s,s[i][j]+1,j);
		cout<<")";
	}
}
int main()
{
	
	int p[10];
	int n;
	int i,j,l,k,q;
	
	cout<<"No of elements: "; cin>>n;
	for(int i=0; i<5; i++)
	{
		cout<<"Element "<<i<<" ";
		cin>>p[i];
	}
	
	for(i=1; i<=n; i++)
	{
		m[i][i]=0;
	}	
	for(l=2; l<=n; l++)
	{
		for(i=1; i<=n-l+1; i++)
		{
			int j=i+l-1;
			m[i][j]=1000;
			for(k=i; k<=j-1; k++)
			{
				q= m[i][k] + m[k+1][j]+(p[i-1]*p[k]*p[j]);
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	cout<<endl;
	for(i=1; i<n; i++)
	{
		for(j=1; j<n; j++)
		{
			cout<<m[i][j]<<"\t";
		}
			
		cout<<endl;
	}
	
	cout<<endl<<"s matrix: "<<endl;
		
	for(i=1; i<n; i++)
	{
		for(j=1; j<n; j++)
		{
			cout<<s[i][j]<<"\t";
		}
		
		cout<<endl;
	}	
	
	cout<<endl;
	
	par(s,1,n);
	
	
	
	cout<<"operations: "<<m[1][n];
	return 0;
}
