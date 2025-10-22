#include <iostream>
#include <iomanip>
#include <complex>

using ldbl_complex = std::complex<long double>;

int main() {
    ldbl_complex z1(3.0, 4.0);
    ldbl_complex z2(1.5, -2.5);

    ldbl_complex sum = z1 + z2;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;
    std::cout << "Sum = " << sum << std::endl;

    return 0;
}