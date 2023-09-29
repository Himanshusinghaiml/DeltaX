#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {   
        int store = v[i]*(n-i);
        ans=max(ans,store);
    }
    cout<<ans;
}