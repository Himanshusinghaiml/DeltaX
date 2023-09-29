#include<bits/stdc++.h>
using namespace std;
int find1(string s)
{
    int flag=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='X' && s[i]!='M' && s[i]!='L' && s[i]!='V' && s[i]!='I' && s[i]!='C')
        {
            return 0;
        }
    }
     
    unordered_map<char,int>M;
        M['I']=1;
        M['V']=5;
        M['X']=10;
        M['L']=50;
        M['C']=100;
        M['D']=500;
        M['M']=1000;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(M[s[i]]<M[s[i+1]])
            {
                ans-=M[s[i]];
            }
            else
            {
                 ans+=M[s[i]];
            }
            
        }
        return ans;


}
int main()
{
     string s;
     cin>>s;
     int ans = find1(s);
     if(ans==0)cout<<"invalid"<<endl;
     else cout<<ans<<endl;

}