#include<iostream>
#include<stdlib.h>
#define MAX 15
#define noedge 999
using namespace std;
class dijkstra
{
   public:
	    int n ,v,cost[MAX][MAX],s[MAX],d[MAX];
   
   public:
            void cosmatrix();
            void print();
            void sspatch();
            int choose();
            
};


void dijkstra::cosmatrix()
{
   cout<<"enter the number of vertices\n";
   cin>>n;
   cout<<"enter the cost adjacency matrix\n";
   cout<<"(enter 999 if there is no edge)\n";
   for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
          cin>>cost[i][j];
}

void dijkstra::sspatch()
{
   int i,u,w;
   cout<<"enter the source vertex\n";
   cin>>v;
   for(i=1;i<=n;i++)
   {
      s[i]=0;
      d[i]=cost[v][i];
   }
   
      s[v]=1;
      d[v]=0;
      i=2;
      while(i<n)
      {
         u=choose();
         s[u]=1;
         i++;
         for(w=1;w<=n;w++)
         {
            if((d[u]+cost[u][w]<d[w]) && !s[w])
               d[w]=d[u]+cost[u][w];
               
         }
      }
 }
 
 int dijkstra::choose()
 {
   int w,j,min;
   min=noedge;
   for(j=1;j<=n;j++)
   {
      if(d[j]<min && !s[j])
      {
            min=d[j];
            w=j;
      }
   }
   return w;         
 }
 
 void dijkstra::print()
 {
     cout<<"the shortest path with the cost is\n";
     for(int i=1;i<=n;i++)
       if(i!=v)
          cout<<"<"<<v<<">----<"<<i<<">----->"<<d[i]<<endl;
 }         
 
 int main()
 {
    dijkstra d;
    d.cosmatrix();
    d.sspatch();
    d.print();
 }            
                                           
