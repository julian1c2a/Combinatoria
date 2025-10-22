#include <iostream>

#include <iomanip>

#include <complex>

#include <cmath>

#include <numbers>

#include <vector>

#include "binomial.hpp"

using ldbl_complex = std::complex<long double>;

/**using llint = std::int64_t;

 * @brief Programa principal que demuestra el uso del módulo binomial    else if (n == 18) return 6402373705728000;

 */

using ldbl_complex = std::complex<long double>;

int main() {        for (ulllint i = 2; i <= n; ++i) {

    std::cout << "🧮 DEMO DEL MÓDULO BINOMIAL" << std::endl;

    std::cout << "============================" << std::endl;

    // Parte 1: Números complejos (código original)

    std::cout << "\n--- Números Complejos ---" << std::endl;}

    ldbl_complex z1(3.0, 4.0);

    ldbl_complex z2(1.5, -2.5);

    ldbl_complex sum = z1 + z2;    

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "z1 = " << z1 << std::endl;

    std::cout << "z2 = " << z2 << std::endl;

    std::cout << "Sum = " << sum << std::endl;

    // Parte 2: Demostrando factoriales

    std::cout << "\n--- Factoriales ---" << std::endl;

    std::cout << "Factorial of 8 = " << static_cast<unsigned long long>(fact(8)) << std::endl;

    std::cout << "Factorial of 20 = " << static_cast<unsigned long long>(fact(20)) << std::endl;

    // Parte 3: Coeficientes binomiales C(8,k)

    std::cout << "\n--- Coeficientes Binomiales C(8,k) ---" << std::endl;

    for (int k = 0; k <= 9; ++k) {
        if (k > n-k) k = n - k; // Use symmetry property

    for (int k = 0; k <= 9; ++k) {
        ullint result{(n-k+1)/k};

        if (k <= 8) {
            for(int i = 1; i <= k; ++i) {

            std::cout << "Binomial coefficient C(8, " << k << ") = " << result << std::endl;
        }

        } else {
            std::cout << "Binomial coefficient C(8, " << k << ") = " << result << std::endl;
        }

    }

    // Parte 4: Casos más grandes
    ldbl_complex z1(3.0, 4.0);
    ldbl_complex z2(1.5, -2.5);

    std::cout << "\n--- Casos Más Grandes ---" << std::endl;

    std::cout << "Binomial coefficient C(20, 10) = " << binom(20, 10) << std::endl;

    std::cout << "Binomial coefficient C(30, 15) = " << binom_optimized(30, 15) << std::endl;

    std::cout << "Binomial coefficient C(52, 5) = " << binom_optimized(52, 5) 

              << " (combinaciones de poker)" << std::endl;    
    
    std::cout << std::fixed << std::setprecision(2);

    //std::cout << "z1 = " << z1 << std::endl;

    // Parte 5: Triángulo de Pascal pequeño

    std::cout << "\n--- Triángulo de Pascal (5 filas) ---" << std::endl;

    for (int n = 0; n <= 5; ++n) {

        std::vector<ullint> row(n + 1);
        std::cout << "Factorial of 8 = " << static_cast<unsigned long long>(fact(8ULL)) << std::endl;

        pascal_row(n, row.data());
        std::cout << "Binomial coefficient C(8, 0) = " << static_cast<unsigned long long>(binom(8ULL, 0ULL)) << std::endl;

        std::cout << "Binomial coefficient C(8, 1) = " << static_cast<unsigned long long>(binom(8ULL, 1ULL)) << std::endl;

        // Centrar
        std::cout << "Binomial coefficient C(8, 2) = " << static_cast<unsigned long long>(binom(8ULL, 2ULL)) << std::endl;

        for (int space = 0; space < (5 - n) * 2; ++space) {
            std::cout << "Binomial coefficient C(8, 3) = " << static_cast<unsigned long long>(binom(8ULL, 3ULL)) << std::endl;

            std::cout << " ";    
            
            std::cout << "Binomial coefficient C(8, 4) = " << static_cast<unsigned long long>(binom(8ULL, 4ULL)) << std::endl;

        }    
        
        std::cout << "Binomial coefficient C(8, 5) = " << static_cast<unsigned long long>(binom(8ULL, 5ULL)) << std::endl;

        std::cout << "Binomial coefficient C(8, 6) = " << static_cast<unsigned long long>(binom(8ULL, 6ULL)) << std::endl;

        for (int k = 0; k <= n; ++k) {
            std::cout << "Binomial coefficient C(8, 7) = " << static_cast<unsigned long long>(binom(8ULL, 7ULL)) << std::endl;

            std::cout << std::setw(4) << row[k];
            
            std::cout << "Binomial coefficient C(8, 8) = " << static_cast<unsigned long long>(binom(8ULL, 8ULL)) << std::endl;

        }    
        
        std::cout << "Binomial coefficient C(8, 9) = " << static_cast<unsigned long long>(binom(8ULL, 9ULL)) << std::endl;

        std::cout << std::endl;    std::cout << "Factorial of 20 = " << static_cast<unsigned long long>(fact(20ULL)) << std::endl;

    }    
    
    std::cout << "Binomial coefficient C(20, 10) = " << static_cast<unsigned long long>(binom(20ULL, 10ULL)) << std::endl;

    std::cout << "\n✅ Demo completada. Usa binomial.hpp y binomial.cpp en tus proyectos!" << std::endl;
    return 0;

}

}