#include <iostream>
#include <string>

using namespace std;

int main() {
    string text = "jack  is     from  america";
    string s = "";
    bool flag=false;
    for(auto c:text)
    {
        if(c!=' ')
        {
            s+=c;
            flag=false;
        }
        else{
            if(!flag)
            {
                s+=c;
                
            }
            flag=true;
        }
    }
    cout<<s;
     
    
    return 0;
}
