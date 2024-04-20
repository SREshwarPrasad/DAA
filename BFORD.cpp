#include<iostream>
#define max 100
#define inf 10000
using  namespace std; 

int i,j; 			//iterating purpose
int u,v; 			//from and to edge
int nv, ne; 			//no of vertices and edges
int f,t, weight; 		//from, to and weight of each edge
int d[max], pi[max];		//d, pi table with relaxation
int w[max][max]; 
int s;				//source vertex


struct edge
{
	int u;
	int v;
	int wt;
}e[max];


int main()
{
	cout<<"BELLMAN FORD: "<<endl<<endl;
	cout<<"No of vertices: "; cin>>nv;
	cout<<"No of edges: "; cin>>ne;
	cout<<"Source vertex? "; cin>>s;
	for(i=1; i<=nv; i++)
	{
		d[i]=inf;
		pi[i]=-1;
	}
	d[s]=0;
	
	for(i=1; i<=ne;i++)
	{
		cout<<"Edge "<<i<<endl;
		cout<<"From: "; cin>>f;
		cout<<"To: "; cin>>t;
		cout<<"Weight: "; cin>>weight;
		cout<<endl;
		
		w[f][t]=weight;
		e[i].u=f;
		e[i].v=t;
		e[i].wt= weight;
	}
	for(i=1; i<=nv;i++)
	{
		for(j=1; j<=ne; j++)
		{
			u=e[j].u; 
			v=e[j].v;
			if(d[v]> d[u] + w[u][v])
			{
				d[v]=d[u]+w[u][v];
				pi[i]=u;
			}
		}
	}
	int cycle=0;
	for(j=1; j<=ne; j++)
	{
		u=e[j].u;
		v=e[j].v;
		if(d[v] > d[u]+w[u][v])
		{
			cycle=1;
			break;
		}
	}
	
	if(!cycle)
	{
		for(i=2; i<=nv; i++)
		{
			cout<<" "<<i<<"\t"<<d[i]<<endl;
		}
	}
	else
	{
		cout<<"Negative";
	}
	
	
	return 0;
}
