#include"bigint.h"
#include<algorithm>
#include<ostream>
#include<iterator>
using namespace std;
namespace tiny
{
	static bool operator<(const vector<int>& left,const vector<int>& right)
	{
		if(left.size()<right.size())
			return true;
		else if(left.size()>right.size())
			return false;
		for(int i=left.size()-1;i>=0;--i)
		{
			if(left[i]<right[i])
				return true;
			else if(left[i]>right[i])
				return false;
		}
		return false;
	}
	static bool operator>(const vector<int>& left, const vector<int>& right)
	{
		return !(left<right)&&!(left==right);
	}
	
	bigint& bigint::turn()
	{
		if(v.size()==1&&v[0]==0)
			return *this;
		postive=!postive;
		return *this;
	}
	bigint::bigint(int x)
	{
		if(x<0)
		{
			postive=false;	
			x=-x;
		}
		v.reserve(11);
		do
		{
			v.push_back(x%10);
			x/=10;
		}while(x);
	}
	bigint::bigint(const string& s)
	{
		if(s.empty())
		{
			v.push_back(0);
			return;
		}
		auto end=s.rend();
		if(s[0]=='-')
		{
			postive=false;
			--end;
		}
		else if(s[0]=='+')
		{
			--end;
		}
		for_each(s.rbegin(),end,[this](int i)
				{
				v.push_back(i-'0');
				});
	}
	bigint::bigint(const char* s):bigint(string(s))
	{
	}
	

	ostream& operator<<(ostream& os,const bigint& self)
	{
		if(!self.postive)
			os<<"-";
		copy(self.v.rbegin(),self.v.rend(),ostream_iterator<int>(os,""));
		return os;
	}
	
	
	//operator <, =, >for bigint
	bool operator==(const bigint& left,const bigint& right)
	{
		return (left.postive==right.postive)&&(left.v==right.v);
	}
	bool operator<(const bigint& left,const bigint& right)
	{
		if(left.postive==false&&right.postive==true)
			return true;
		else if(left.postive==true&right.postive==true)
			return left.v<right.v;
		else if(left.postive==false&&right.postive==false)
			return left.v>right.v;
		else
			return false;
	}

	bool operator>(const bigint& left,const bigint& right)
	{
		return !(left<right)&&!(left==right);
	}
	
	bool operator<=(const bigint& left,const bigint& right)
	{
		return (left<right)||(left==right);
	}

	
	bool operator>=(const bigint& left,const bigint& right)
	{
		return (left>right)||(left==right);
	}
	const bigint operator-(const bigint& one)
	{
		bigint big(one);
		big.turn();
		return big;
	}
	bigint operator+(const bigint& left, const bigint& right)
	{
		bigint one=left;
		one+=right;
		return one;
	}
	bigint operator-(const bigint& left, const bigint& right)
	{
		bigint one=left;
		one-=right;
		return one;
	}
	bigint& bigint::operator+=(const bigint& other)
	{
		if(postive==other.postive)
		{
			v.resize(max(v.size(),other.v.size())+1);
			int min_size=min(v.size(),other.v.size());
			for(int i=0;i!=min_size;++i)
				v[i]+=other.v[i];
			bool flag=0;
			for(int& x:v)
			{
				x+=flag;
				if(x>=10)
				{
					x-=10;
					flag=1;
				}
				else
					flag=0;
			}
			if(0==*(v.end()-1))
				v.pop_back();
		}
		else if(postive==true&&other.postive==false)
			*this-=-other;
		else
			*this=-(other-*this);
		return *this;
	}

	bigint& bigint::operator-=(const bigint& other)
	{
		if(postive!=other.postive)
			*this+=-other;
		else if(postive=true&&other.postive==true)
		{
			if(*this>=other)
			{
				int flag=0;
				for(int i=0;i!=v.size();++i)
				{
					v[i]=v[i]+flag-other.v[i];
					if(v[i]<0)
					{
						v[i]+=10;
						flag=-1;
					}
					else
						flag=0;
				}
			}
			else
			{
				*this=(other-*this).turn();
			}
			//remove the front's zeros
			auto it_not_zero=find_if_not(v.rbegin(),v.rend(),[](int x)
				{
					return x==0;
				});
			for(auto it=v.rbegin();it!=it_not_zero;++it)
			{
				v.pop_back();
			}
		}
		else
		{
			*this=-other-(this->turn());
		}
		if(v.empty())
			v.push_back(0);
		return *this;
	}
}
