#include"bigint.h"
#include<string>
#include<iostream>
using namespace std;
using namespace tiny;
int main()
{
	int i;
	cin>>i;
	string a,b;
	while(cin>>a>>b)
	{
		cout<<bigint(a)+b<<endl;
		cout<<b+bigint(a)<<endl;
		cout<<bigint(a)-b<<endl;
		cout<<b-bigint(a)<<endl;
		cout<<bigint(a)*b<<endl;
		cout<<b*bigint(a)<<endl;
		cout<<bigint(a)/b<<endl;
		cout<<b/bigint(a)<<endl;
		cout<<bigint(a)%b<<endl;
		cout<<b%bigint(a)<<endl;
	}
}
