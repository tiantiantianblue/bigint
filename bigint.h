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
		friend std::ostream& operator<<(std::ostream& os, const bigint& self);
		friend bool operator==(const bigint&, const bigint&);
		friend bool operator<(const bigint&, const bigint&);
		friend bool operator>(const bigint&, const bigint&);
	private:
		std::vector<int> v;
		bool postive=true;
	};
}
