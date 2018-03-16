#include<iostream>
#include<cstdlib>
using namespace std;

void warsh(int a[10][10],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				a[i][j]=(a[i][j]||a[i][k]&&a[k][j]);
}
int main()
{
	int n,a[10][10],i,j;
	cout<<"enter no of vertices\n";
	cin>>n;
	cout<<"enter the adjacency matrix\n";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	warsh(a,n);
	cout<<"transitive closure of a given graph is:\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<a[i][j];
			cout<<"\t";
		}
		cout<<"\n";
	}
}
