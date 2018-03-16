#include<iostream>
using namespace std;
int a[20][20], reach[20], n;

void dfs(int v)
{
    int i;
    reach[v]=1;
    
    for(i=1;i<=n;i++)
    {
        if(a[v][i] && !reach[i])
        {
            cout<<v<<"----->"<<i<<"\n";
            dfs(i);
        }
    }
}
int main()
{
    int i,j,count=0,v;
    cout<<"\n Enter no. of vertices :";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        reach[i]=0;
        for(j=1;j<=n;j++)
        a[i][j]=0;
    }
    cout<<"\n Enter adjacency matrix : ";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
             cin>>a[i][j];
        }
    }
    cout<<"\n Enter starting vertex";
    cin>>v;
    dfs(v);
    for(i=1;i<=n;i++)
    {
        if(reach[i])
        count++;
    }
    cout<<"\n\n\n";
    if(count==n)
    cout<<"\n Graph is connected";
    else
    cout<<"\n Graph is not connected";
    cout<<"\n\n\n";
    return 0;
}
