# include<iostream>
using namespace std;
int a,b,u ,v,n,i ,j;
int cost[10][10],mincost=0,m,ne=1,visited[10];

int main()
{
  cout<<"enter the no of nodes\n";
  cin>>n;
  
  cout<<"enter the cost matrix";
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
       cin>>cost[i][j];
       if(cost[i][j]==0)
          cost[i][j]=999;
    }
  for(i=1;i<=n;i++)
     visited[i]=0;
     
     
cout<<"the spanning edges are:\n";
visited[1]=1;

while(ne<n)
{
   for(i=1,m=999;i<=n;i++)
      for(j=1;j<=n;j++)
          if(cost[i][j]<m)
             if(visited[i]==0)continue;
              else
              {
                 m=cost[i][j];
                 a=u=i;
                 b=v=j;
                 
               }
               
               if( (visited[a]==0 || visited[b]==0))
               {
                  
                  cout<<ne<<".edge("<<a<<","<<b<<")="<<cost[a][b]<<"\n";
                  ne++;
                  mincost=mincost+m;
                  visited[b]=1;
                  
               }
               
          cost[a][b]=cost[b][a]=999;
 }
 cout<<"mincost="<<mincost<<"\n";
 return 0;
 }
                                 
  
