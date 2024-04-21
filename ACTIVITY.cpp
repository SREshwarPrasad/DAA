#include<iostream>
#define max 100
using namespace std;

int n; 
int a[max];
int s[max];
int f[max];

int main()
{
	cout<<"GREEDY SELECTION "<<endl;
	int k=1,m,n;
	cout<<"How many? "; cin>>n;
	for(int i=1; i<=n; i++)
	{
		cout<<"Duration "<<i<<endl;
		cout<<"Enter start: ";
		cin>>s[i];
		cout<<"Enter finish: ";
		cin>>f[i];
		cout<<endl;
	}
	
	int p=1;
	a[p]=1;
	for(m=2; m<=n; m++)
	{
		if(s[m]>=f[k])
		{
			p+=1;
			a[p]=m;
			k=m;
		}
	}

	cout<<"ACTIVITY: "<<endl;
	for(int i=1; i<=p; i++)
	{
		cout<<"a["<<a[i]<<"]"<<"\t";
	}
	cout<<endl;
	return 0;
}
