//KNAPSACK PROBLEM(31-08-17)

#include<iostream>
using namespace std;
int max(int a,int b)
{
    return(a>b?a:b);
}
void knapsack(int n,int w[],int p[],int m)
{
	int v[10][10],i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
                v[i][j]=0;
            else if(j<w[i])
                v[i][j]=v[i-1][j];
            else
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);

        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
         cout<<v[i][j]<<"\t";
         cout<<"\n";
    }
    cout<<"\n\nThe optimised value is:\n"<<v[n][m]<<"\n";
}
int main()
{
    int w[10],p[10],m,n,i;
    cout<<"\nEnter the number of items:\n";
    cin>>n;
    cout<<"\nEnter the capacity of knapsack:\n";
    cin>>m;
    cout<<"\nEnter the weight of the items:\n";
    for(i=1;i<=n;i++)
        cin>>w[i];
     cout<<"\nEnter the value of the items:\n";
     for(i=1;i<=n;i++)
        cin>>p[i];
      cout<<"THE TABLE IS :\n\n";
      knapsack(n,w,p,m);
      return 0;
}
