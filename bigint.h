#include<vector>
#include<string>
#include<iosfwd>
namespace tiny
{
	class bigint
	{
	public:
		bigint(int x);
		bigint(const std::string& s);
		bigint(const char* s);
		bigint& operator+=(const bigint& other);
		bigint& operator-=(const bigint& other);
		friend std::ostream& operator<<(std::ostream& os, const bigint& self);
		friend bool operator==(const bigint&, const bigint&);
		friend bool operator<(const bigint&, const bigint&);
		bigint& turn();
	private:
		std::vector<int> v;
		bool postive=true;
	};
	bool operator>(const bigint&, const bigint&);
	bool operator<=(const bigint&, const bigint&);
	bool operator>=(const bigint&, const bigint&);
	bigint operator+(const bigint& left, const bigint& right);
	bigint operator-(const bigint& left, const bigint& right);
	const bigint operator-(const bigint& one);	
}
