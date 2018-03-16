#include<iostream>
using namespace std;
int main()
{
   int a[20][20],i,j,n,min=0,p[20],mi;
   int count=0,u,v,c,b;
   cout<<"enter the num of nodes:";
   cin>>n;
   cout<<"enter the adjacency matrix:\n";
   cout<<"if there is no edge enter as 999\n";
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         cin>>a[i][j];
         p[i]=i;
      }
   }
   cout<<"EDGE;\n";
   while(count<n)
   {
      mi=999;
      for(i=1;i<=n;i++)
      {
        for(j=1;j<=n;j++)
        {
             if(a[i][j]<=mi&&i!=j)
             {
                 mi=a[i][j];
                 u=c=i;
                 v=b=j;
              }
        }
     }
     while(p[u]!=u)
     u=p[u];
     while(p[v]!=v)
        v=p[v];
        
        if(u!=v)
        {
            cout<<"("<<b<<","<<c<<")"<<"\n";
            p[v]=u;
            min+=mi;
        }
        count++;
        a[c][b]=a[b][c]=999;
     }
     cout<<"\n \n cost="<<min<<"\n";
     return 0;
  }                            
