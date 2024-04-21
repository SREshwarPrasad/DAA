#include<iostream>
#define max 100
#define inf 1000
using namespace std;

int ne,nv;
int d[max][max], pi[max][max];
int f,t, weight;

void init()
{
  	for(int i=1; i<=nv;i++)
  	{
    		for(int j=1; j<=nv; j++)
    		{
      			if(d[i][j] == inf  || i==j)
      			{
      				  pi[i][j]=-1;
      			}
      			else
      			{
      				  pi[i][j]=i;
      			}
    		}
  	}
}

void floyd()
{
  	for(int k=1; k<=nv; k++)
  	{
    		for(int i=1; i<=nv; i++)
    		{
    			for(int j=1; j<=nv; j++)
    			{
      				if(d[i][j] > d[i][k] + d[k][j])
      				{
        					d[i][j] = d[i][k] + d[k][j];
        					pi[i][j] = pi[k][j];
      				}
      			}
    		}
  	}
}


void print()
{
  	cout<<"distance matrix "<<endl;
  	for(int i=1; i<=nv; i++)
  	{
  		for(int j=1; j<=nv; j++)
    		{
    			  cout<<d[i][j]<<"\t";
    		}
    		cout<<endl;
    	}
  
    	cout<<endl;
    	cout<<"pi matrix "<<endl;
  
    	for(int i=1; i<=nv; i++)
    	{
      		for(int j=1; j<=nv; j++)
      		{
      			  cout<<pi[i][j]<<"\t";
      		}
      		cout<<endl;
  	}
}

void printpath(int i, int j)
{
  	if(i==j)
  	{
    		cout<<i<<" ";
    		return;
  	}
  	else
  	{
    		if(pi[i][j]==-1)
    		{
    			  cout<<"No path from "<<i<<"to "<<j;
    		}
    		else
    		{
      			printpath(i, pi[i][j]);
      			cout<<j<<" ";
    		}
  	}
}

int main()
{
  	int f,t;
  	
  	cout<<"No of Vertices: ";
  	cin>>nv;
  	cout<<"No. of Edges: ";
  	cin>>ne;
  	
  	for(int i=1; i<=nv; i++)
  	{
    		for(int j=1; j<=nv; j++)
    		{	
      			if(i==j)
      			{
      			  	d[i][j]=0; // diagonal to be 0
      			}
      			else
      			{
      			  	d[i][j]=inf; //initially initialising everything to be infinity
      			}
    		}
  	}
  	
  	for(int i=1; i<=ne; i++)
  	{
    		cout<<"Edge "<<i<<endl;
    		cout<<"from: "; cin>>f;
    		cout<<"to: "; cin>>t;
    		cout<<"weight: "; cin>>weight;
    		cout<<endl;
    		d[f][t]=weight;
  	}
  	
  	init();
  	floyd();
  	print();
  	int f1, t1;
  	cout<<"what path you want? from,to ";
  	cin>>f1>>t1; 
  	printpath(f1,t1);
  	return 0;
}
