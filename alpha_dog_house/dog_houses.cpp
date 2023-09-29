#include<iostream>
using namespace std;
int main()
{
     int n,house;
     cin>>n>>house;
     int arr[n];
     house-=1; 
     int sum=0;
     for(int i=0;i<n;i++)
     {
        cin>>arr[i];
     }
     for(int i=0;i< house;i++)
     {
        arr[i+1]+=arr[i];
        sum+=arr[i];
     }
     int last=n-1;
     for(int i=last;i> house;i--)
     {
        arr[i-1]+=arr[i];
        sum+=arr[i];
     }
     cout<<sum;
}