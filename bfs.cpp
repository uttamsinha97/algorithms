#include <iostream>

int a[20][20],b[20][20],q[20],visited[20],f=0,r=-1,i,n,j,v,m=0;
using namespace std;
void bfs(int v) // utility function for bfs
{
    for(i=1;i<=n;i++)
    {
        if(b[v][i] && !visited[i])
        {
            b[i][v]=0;
            b[v][i]=0;
            cout<<"\t"<<v<<"--->"<<i;
        }
    }
      for(i=1;i<=n;i++)
     {
          if(a[v][i] && !visited[i])
          {
                 q[++r]=i;
                 //cout<<"\t"<<v<<"-->"<<i;
          }
     }
     if(f<=r)
     {
         visited[q[f]]=1;
         bfs(q[f++]);
     }
}
int main()
{

      cout<<"enter the no. of vertices\n";
      cin>>n;
      for(i=1;i<=n;i++)
      {
          visited[i]=0;
          q[i]=0;
      }
      cout<<"enter adjacency matrix for the graph\n";
      for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
      cin>>a[i][j];
      cout<<"enter the starting vertex\n";
      cin>>v;
      for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
      b[i][j]=a[i][j];
      cout<<"path:\n";
      bfs(v);
      cout<<"\nnodes reachable from the given starting vertex "<<v<<" is\n";
      for(i=1;i<=n;i++)
      {
            if(visited[i])
            {
                m=1;
                cout<<"\t"<<i;
            }              
      } 
      if(m==0)
          cout<<"\ngraph is not connected\n";
      else if(m==1)
                cout<<"graph is connected\n";
     return 0;
}
