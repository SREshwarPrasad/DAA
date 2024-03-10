//Ex3-(iii) BUCKET SORT 
//VECTOR METHOD

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void bucketSort(float arr[], int n)
{
	vector<float> b[n];
	for (int i=0; i<n; i++) 
	{	
		int bi=n*arr[i];
		b[bi].push_back(arr[i]);
	}
	for (int i=0; i<n; i++)
	{
		for (auto it=b[i].begin(); it!=b[i].end(); it++) 
		{        
			auto const ip = upper_bound(b[i].begin(),it,*it);	
			rotate(ip, it, it+1);         
		} 
	}
	int in = 0;
	for (int i=0;i<n; i++)
		for (int j=0; j<b[i].size();j++)
			arr[in++]=b[i][j];
}


int main()
{
	float arr[]={ 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<n;
	bucketSort(arr, n);
	cout << "Sorted array is \n";
	for (int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	return 0;
}
