//Ex2-(i) QUICK SORT

#include<iostream>
using namespace std;
int a[100]; int n; int q;
int PARTITION(int, int);

void QUICK_SORT(int p, int r)
{
	if(p<r)
	{
		q= PARTITION(p,r);
		QUICK_SORT(p,q-1);
		QUICK_SORT(q+1,r);
	}
}

int PARTITION(int p, int r)
{
	int x=a[r];
	int i=p-1; int j;
	for(j=p; j<r; j++)
	{
		if(a[j]<=x)
		{
			i+=1;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return (i+1);
}

void get()
{
	cout<<"Enter no of elements: "; 
	cin>>n;
	cout<<"Elements ?";
	for(int i=1; i<=n; i++)
		cin>>a[i];
	QUICK_SORT(1,n);
}

void print()
{
	cout<<"Sorted Array: "<<endl;
	for(int i=1; i<=n; i++)
		cout<<a[i]<<"\t";
	cout<<endl;	
}

int main()
{
	get();
	print();
	cout<<endl;	
	return 0;
}
