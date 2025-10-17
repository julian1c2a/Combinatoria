
#include <iostream>
#include <cstdint>
#include <string>
#include <algorithm>
#include <cmath>
#include <numbers>

using ulllint_t = __uint128_t;
using lllint_t  = __int128_t;
using ullint_t  = std::uint64_t; // This line is a redefinition, but it's not the source of the error.
using llint_t   = std::int64_t;
using std::size_t;

std::ostream& operator<<(std::ostream& os, lllint_t value) {
    if (value == 0) {
        return os << "0";
    }

    std::string s = "";
    bool negative = false;
    if (value < 0) {
        negative = true;
        value = -value;
    }

    while (value > 0) {
        s += (char)('0' + (value % 10));
        value /= 10;
    }
    if (negative) {
        s += '-';
    }
    std::reverse(s.begin(), s.end());
    os << s;
    return os;
}

std::ostream& operator<<(std::ostream& os, ulllint_t value) {
    if (value == 0) {
        return os << "0";
    }

    std::string s = "";
    while (value > 0) {
        s += (char)('0' + (value % 10));
        value /= 10;
    }
    std::reverse(s.begin(), s.end());
    os << s;
    return os;
}

constexpr ulllint_t factorial(ulllint_t n) noexcept
{
	if (n < 2)
        return 1;
    else if(n == 2)
        return 2;
    else if (n == 3)
		return 6;
	else if (n == 4)
		return 24;
	else if (n == 5)
		return 120;
	else if (n == 6)
		return 720;
	else if (n == 7)
		return 5040;
	else if (n == 8)
		return 40320;
	else if (n == 9)
		return 362880;
	else if (n == 10)
        return 3628800;
    else if (n < 35){
		ulllint_t result = 1;
		for (ulllint_t i = 2; i <= n ; ++i)
			result *= i;
    	return result;
    } else {
        long double approx = 0.0L;
        for(lllint_t k = 1; k <= n; ++k)
            approx += std::log10l(static_cast<long double>(k));
        return static_cast<ulllint_t>(std::roundl(std::expl(approx * std::numbers::ln10)));
	}
}

int main()
{
    for(size_t i = 0; i < 35; ++i)
        std::cout << i << "! = " << factorial(i) << '\n';
    std::cout << std::flush;
    for(size_t i = 35; i < 50; ++i)
        std::cout << i << "! = " << factorial(i) << '\n';
	std::cout << std::flush;
	return 0;
}
