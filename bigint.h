#include<vector>
#include<string>
namespace tiny
{
	class bigint
	{
	public:
		bigint(int x);
		bigint(const std::string& s);
		bigint& operator+=(const bigint& other);
	private:
		std::vector<int> v;
	};
}
