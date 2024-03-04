#include<iostream>
#define max 10
using namespace std;
int a[max];
int n;
struct node 
{
	int low;
	int high;
	int sum;
};

void get()
{
	cout<<"Enter no. of elements: "; cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	
	cout<<endl;
}

struct node cross(int a[], int l, int m, int h)
{
	struct node temp;
	int ls= -1000;
	int sum=0;
	int rs=-1000;
	int ml,mr,i,j;
	for( i=m; i>=l; i--)
	{
		sum+=a[i];
		if(ls<sum)
		{
			ls=sum; ml=i;
		}
	}
	sum=0;
	for(j=m+1; j<=h; j++)
	{
		sum+=a[j];
		if(rs<sum)
		{
			rs=sum;
			mr=j;
		}
	}
	temp.low=ml; 
	temp.high=mr;
	temp.sum=ls+rs;
	return temp;
};

struct node fmsa(int a[], int l, int h)
{
	struct node temp, leftnode,rightnode, crossnode;
	if(l==h)
	{
		temp.low=l;
		temp.high=h;
		temp.sum=a[l];
		return temp;
	}
	int mid=(l+h)/2;
	leftnode= fmsa(a,l,mid);
	rightnode=fmsa(a,mid+1,h);
	crossnode=cross(a,l,mid,h);
	if((leftnode.sum>=rightnode.sum) && (leftnode.sum>=crossnode.sum))
	{
		return leftnode;
	}
	
	if((rightnode.sum>=leftnode.sum) && (rightnode.sum>=crossnode.sum))
	{
		return rightnode;
	}
	
	return crossnode;
}

void print()
{
	struct node t;
	
	t=fmsa(a,0,n-1);
	cout<<t.low<<"\t"<<t.high<<"\t"<<"SUM: "<<t.sum<<endl;
	cout<<"MAX SUB ARRAY"<<endl;
	cout<<"[";
	for(int i=t.low; i<=t.high; i++)
	{
		cout<<a[i];
		if(i!=t.high)
			cout<<","<<" ";
	}
	cout<<"]";
	cout<<endl;
}

int main()
{
	get();
	cout<<endl<<"SUBARRAY: "<<endl;
	print();
	return 0;
}
