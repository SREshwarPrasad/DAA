
//Ex1-(ii): Heapsort 

#include<iostream>
#define max 100
using namespace std;

int n,hs;
int a[max];

void HEAP_SORT(int []);
void print();

void MAX_HEAPIFY(int p[], int i)
{
	int l,r;
	int largest=i; 
	l=2*i;
	r=(2*i)+1;
	if(l<=hs && p[l]>p[i])
		largest=l;
	else
		largest=i;
	if(r<=hs && p[r]>p[largest])
		largest=r;
	if(largest!=i)
	{
		swap(p[i],p[largest]);
		MAX_HEAPIFY(p,largest);
	}
	
}

void BUILD_MAX_HEAP(int p[])
{
	int i;
	hs=n;
	for(i=(n/2); i>=1; i--)
	{
		MAX_HEAPIFY(p,i);
	}
}

void HEAP_SORT()
{
	int i;
	BUILD_MAX_HEAP(a);
	for(i=n; i>=2; i--)
	{
		swap(a[1],a[i]);
		hs=hs-1;
		MAX_HEAPIFY(a,1);
	}
}

void get()
{
	cout<<"Enter no of elements: "; 
	cin>>n;
	cout<<"Elements ?";
	for(int i=1; i<=n; i++)
		cin>>a[i];
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
	HEAP_SORT();
	print();
	cout<<endl;
	
return 0;
}
