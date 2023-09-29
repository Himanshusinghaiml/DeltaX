#include <iostream>
#include <string>
using namespace std;
string json(string s)
{
    string copy=""; int inde=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='{' or s[i]=='[')
        {
            copy+='\n';
            for(int i=0;i<inde;i++)
            {
                copy+="**";
            }
            copy+=s[i];
            copy+='\n';
            inde+=1;
            for(int i=0;i<inde;i++)
            {
                copy+="**";
            }

        }
       else if(s[i]==',')
        {
            copy+=s[i];
            copy+='\n';
            for(int i=0;i<inde;i++)
           {
            copy+="**";
           }

        }
        else if (s[i]=='}' or s[i]==']')
        {
           inde-=1;
           copy+='\n';
            
           for(int i=0;i<inde;i++)
           {
            copy+="**";
           }
           copy+=s[i];
        }

        else  copy+=s[i];
    }
    return copy;
}
int main()
    {
        string s;
        getline(cin,s);
        string ans=json(s);
        cout<<ans;
    }
 //input {"name":"john","email":"john.d@gmail.com"} 



/* 
{
**"name":"john",
**"email":"john.d@gmail.com"
}

*/

/*
{"name":"james","friends":["joe","joey"]}
// vs code ouput 
 

*/
 /*   // original ouptut
 {
**"name":"james",
**"freinds":
**[
****"joe",
****"joey"
**]
}
*/





 /* 
{
**"name":"james",
**"friends":
**[
****{
******"id":0,
******"name":"Christi Harmon"
****},
****{
******"id":1,
******"name":"Garrison peck"
****},
****{
******"id":2,
******"name":"jaclyn Kirk"
****}
**]
}   */