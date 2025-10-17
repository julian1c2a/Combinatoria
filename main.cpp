
#include <iostream>
#include <cstdint>
#include <string>
#include <algorithm>
#include <cmath>
#include <numbers>

using ulllint_t = __uint128_t;
using lllint_t  = __int128_t;
using ullint_t  = std::uint64_t;
using llint_t   = std::int64_t;
using std::size_t;

std::ostream& operator<< (std::ostream& os, lllint_t value) {
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
    if      (n  < 2) return 1ULL;
    else if (n == 2) return 2ULL;
    else if (n == 3) return 6ULL;
    else if (n == 4) return 24ULL;
    else if (n == 5) return 120ULL;
    else if (n == 6) return 720ULL;
    else if (n == 7) return 5040ULL;
    else if (n == 8) return 40320ULL;
    else if (n == 9) return 362880ULL;
    else if (n == 10) return 3628800ULL;
    else if (n == 11) return 39916800ULL;
    else if (n == 12) return 479001600ULL;
    else if (n == 13) return 6227020800ULL;
    else if (n == 14) return 87178291200ULL;
    else if (n == 15) return 1307674368000ULL;
    else if (n == 16) return 20922789888000ULL;
    else if (n == 17) return 355687428096000ULL;
    else if (n == 18) return 6402373705728000ULL;
    else if (n == 19) return 121645100408832000ULL;
    else if (n == 20) return 2432902008176640000ULL;
    else if (n < 35) {
        ulllint_t result = 1ULL;
        for (ulllint_t i = 2ULL; i <= n; ++i)
            result *= i;
        return result;
    }
    else return 0ULL; // Placeholder for large n factorial calculation: OVERFLOW
}

int main()
{
    for(size_t i = 0; i < 35; ++i)
        std::cout << i << "! = " << factorial(i) << '\n';
    std::cout << std::flush;
    std::cout << std::endl;
    for(size_t i = 35; i < 50; ++i)
        std::cout << i << "! = " << factorial(i) << '\n';
    std::cout << std::flush;
    std::cout << std::endl;

	return 0;
}
