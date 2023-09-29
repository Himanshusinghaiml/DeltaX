#include<bits/stdc++.h>
using namespace std;
unsigned long long powerof2(unsigned long long p)
{
  while((p & (p-1))!=0)
  {
    p &=(p-1);
  }
  return p;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        unsigned long long p;
        cin>>p;
        bool playerA=true;
        while(p>1)
        {
            if((p & (p-1))==0)
            {
                p/=2;
            }
            else{
                unsigned long long temp=powerof2(p);
                p-=temp;
            }
             playerA=!playerA;
        }
        
        if(playerA)
           cout<<"playerB"<<endl;
        else 
           cout<<"playerA"<<endl;

    }
}



 