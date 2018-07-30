#include <iostream>
#include <vector>
using namespace std;

string reverse(string::iterator & it)
{
	char value = *it;
	++it;
	if(value == 'b' || value == 'w')
		return string(1,value);
	
	string upleft = reverse(it);
	string upright = reverse(it);
	string lowleft = reverse(it);
	string lowright = reverse(it);
	
	return string("x")+lowleft+lowright+upleft+upright;
	
	
}

string reverse(string& str)
{
	char value = str[0];
	str = str.substr(1);
	
	if(value == 'b' || value == 'w')
		return string(1,value);
	
	string upleft = reverse(str);
	string upright = reverse(str);
	string lowleft = reverse(str);
	string lowright = reverse(str);
	
	return string("x")+lowleft+lowright+upleft+upright;
	
	
}



int main()
{
	int C;
	cin>>C;
	
	while(C--)
	{
		string str;
		cin>>str;
		std::string::iterator it=str.begin();
		string temp = reverse(str);
		
		cout<<temp<<endl;
	}
	
	
	
	
	return 0;
}

