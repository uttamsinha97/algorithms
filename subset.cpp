#include<iostream>
using namespace std;
class set
{
	public: int w[10],d,n,count,x[10],i,c;
        public:set()
                {
                        c=0;
                }
                void sum_of_subsets(int,int,int);
                void check();
};     

void set::sum_of_subsets(int s,int k,int r)
{
        x[k]=1;
        if(s+w[k]==d)
        {
                cout<<"\n Subset "<<"=";
                for(i=0;i<=k;i++)
                {
                     if(x[i])
                
                        {
                                cout<<w[i]<<" ";c=1;
                        }
                                
                }
        }
        else if(s+w[k]+w[k+1]<=d)
           sum_of_subsets(s+w[k],k+1,r-w[k]);
        if((s+r-w[k]>=d) && (s+w[k+1]<=d))
        {
                x[k]=0;
                sum_of_subsets(s,k+1,r-w[k]);
        }
}
void set::check()
{
        if(c==0)
                cout<<"no possible subsets\n";
}
int main()
{
int i,r=0;
set s;
        cout<<"Enter the no. of elements\n";
        cin>>s.n;
        cout<<"Enter the elements\n enter elements in ascending orderSQ";
        for(i=0;i<s.n;i++)       //Enter in ascending order
           cin>>s.w[i];
        cout<<"Enter the sum:\n";
        cin>>s.d;
        for(i=0;i<s.n;i++)
            s.x[i]=0;
        for(i=0;i<s.n;i++)
            r+=s.w[i];
        s.sum_of_subsets(0,0,r);
        s.check();
        
        return(0);
        
}
