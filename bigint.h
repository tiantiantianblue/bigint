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
		bigint& operator*=(const bigint& other);
		friend const bigint operator*(const bigint& left, const bigint& right);
		friend bool operator==(const bigint&, const bigint&);
		friend bool operator<(const bigint&, const bigint&);
		friend const bigint operator-(const bigint& one);	
		friend std::ostream& operator<<(std::ostream& os, const bigint& self);
	private:
		std::vector<int> v;
		bool postive=true;
	};

	bool operator!=(const bigint&, const bigint&);
	bool operator>(const bigint&, const bigint&);
	bool operator<=(const bigint&, const bigint&);
	bool operator>=(const bigint&, const bigint&);
	inline const bigint operator+(const bigint& left, const bigint& right);
	inline const bigint operator-(const bigint& left, const bigint& right);

	inline const bigint operator+(const bigint& left, const bigint& right)
	{
		bigint one=left;
		one+=right;
		return one;
	}

	inline const bigint operator-(const bigint& left, const bigint& right)
	{
		bigint one=left;
		one-=right;
		return one;
	}
}
