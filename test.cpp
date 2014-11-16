#include"bigint.h"
#include<everything>
using namespace tiny;
int main()
{
	vector<bigint> v={123456789,-123456789,"1234567891234567890","-12345678901234567890","01234567890","-012345678952"};
	bigint a="123456789";
	bigint b="-123296654";
	bigint c=0;
	cout<<a<<endl<<b<<endl;
	cout<<(a+=b)<<endl;
}
