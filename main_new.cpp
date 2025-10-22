#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include "binomial.hpp"

using ldbl_complex = std::complex<long double>;

int main() {
    std::cout << "Demo del modulo binomial" << std::endl;
    
    // Numeros complejos
    ldbl_complex z1(3.0, 4.0);
    ldbl_complex z2(1.5, -2.5);
    ldbl_complex sum = z1 + z2;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;
    std::cout << "Sum = " << sum << std::endl;

    // Factoriales
    std::cout << "Factorial of 8 = " << static_cast<unsigned long long>(fact(8)) << std::endl;
    std::cout << "Factorial of 20 = " << static_cast<unsigned long long>(fact(20)) << std::endl;

    // Coeficientes binomiales
    for (int k = 0; k <= 8; ++k) {
        std::cout << "C(8, " << k << ") = " << binom(8, k) << std::endl;
    }

    // Casos grandes
    std::cout << "C(20, 10) = " << binom(20, 10) << std::endl;
    std::cout << "C(52, 5) = " << binom_optimized(52, 5) << std::endl;

    return 0;
}