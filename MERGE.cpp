//Ex1-(i) MERGE SORT

#include<iostream>
using namespace std;

int a[100]; int n;

void MERGE(int, int, int);
void MERGE_SORT(int p, int r)
{
	if(p<r)
	{
		int q= (p+r)/2;
		MERGE_SORT(p,q);
		MERGE_SORT(q+1,r);
		MERGE(p,q,r);
	}
}

void MERGE(int p, int q, int r)
{
	int n1= q-p+1; 
	int n2=r-q;
	int L[n1+2], R[n2+1];
	for(int i=1; i<=n1; i++)
	{
		L[i]=a[p+i-1];
	}
	L[n1+1]=1000;
	for(int j=1; j<=n2; j++)
	{
		R[j]=a[q+j];
	}
	R[n2+1]=1000;
	int i=1; int j=1;
	for(int k=p; k<=r; k++)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i]; i+=1;
		}
		else
		{
			a[k]=R[j]; j+=1;
		}
	}
}

void get()
{
	cout<<"Enter no of elements: "; 
	cin>>n;
	cout<<"Elements ?";
	for(int i=1; i<=n; i++)
		cin>>a[i];
	MERGE_SORT(1,n);
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
