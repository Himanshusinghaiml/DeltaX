#include<bits/stdc++.h>
using namespace std;

bool isChar(char c)
{
	return ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z'));
}

bool isDigit(const char c)
{
	return (c >= '0' && c <= '9');
}

bool is_valid(string email)
{
	if (!isChar(email[0])) {
		return 0;
	}
	int At = -1, Dot = -1;
	for (int i = 0; i < email.length(); i++) {
		if (email[i] == '@') {

			At = i;
		}
		else if (email[i] == '.') {

			Dot = i;
		}
	}
	if (At == -1 || Dot == -1)
		return 0;
	if (At > Dot)
		return 0;
	return !(Dot >= (email.length() - 1));
	// if('.'==email.length()-1)return 0;
}
int main()
{   
	vector<string>s;
    int n;cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        string p;
        getline(cin,p);
        s.push_back(p);
    }
	for(int i=0;i<n;i++)
	{
		bool ans = is_valid(s[i]);
		if(ans)cout<<"true"<<endl;else cout<<"false"<<endl;
	}
	 
	return 0;
}

 