#include<iostream>
#define max 100
using namespace std;

int a[max],b[max],c[max];
int n;

int bubblesort() //retrieve largest element, bubble sort in ascending order. last element is largest (can do even by max method)
{
	for(int i=0; i<=n;i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			if(a[i]>a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}
	return a[n];
}

void countingsort(int k)
{
	for(int i=1; i<=k; i++)
	{
		c[i]=0;
	}
	for(int j=1; j<=n; j++)
	{
		c[a[j]]+=1;
	}
	for(int i=1; i<=k; i++)
	{
		c[i]+=c[i-1];
	}
	for(int j=n; j>=1; j--)
	{
		b[c[a[j]]]=a[j];
		c[a[j]]-=1;
	}
}
int main()
{
	cout<<"Enter elements: "; cin>>n;
	for(int i=1; i<=n; i++) //give single digit (0-9) as input 
	{
		cin>>a[i];
	}
	int g= bubblesort();
	cout<<"Largest element is "<<g<<endl;
	countingsort(bubblesort());
	
	for(int i=1; i<=n; i++)
	{
		cout<<b[i]<<"\t";
	}
	return 0;
}
