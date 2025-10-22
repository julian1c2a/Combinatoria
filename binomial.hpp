#ifndef BINOMIAL_HPP
#define BINOMIAL_HPP

#include <cstdint>

/**
 * @file binomial.hpp
 * @brief Funciones optimizadas para cálculo de factoriales y coeficientes binomiales
 * @author Tu nombre
 * @date October 16, 2025
 */

// Alias de tipos para mayor claridad
using ullint = std::uint64_t;
using ulllint = __uint128_t;

/**
 * @brief Calcula el factorial de un número usando valores precalculados para optimización
 * @param n El número del cual calcular el factorial
 * @return El factorial de n (n!)
 * @note Usa valores precalculados hasta 20! para máxima velocidad
 * @note Para n > 20, usa un bucle iterativo
 */
constexpr ulllint fact(ulllint n) {
    // Valores precalculados para máxima velocidad
    if (n == 0 || n == 1) return 1;
    else if (n ==  2) return 2;
    else if (n ==  3) return 6;
    else if (n ==  4) return 24;
    else if (n ==  5) return 120;
    else if (n ==  6) return 720;
    else if (n ==  7) return 5040;
    else if (n ==  8) return 40320;
    else if (n ==  9) return 362880;
    else if (n == 10) return 3628800;
    else if (n == 11) return 39916800;
    else if (n == 12) return 479001600;
    else if (n == 13) return 6227020800;
    else if (n == 14) return 87178291200;
    else if (n == 15) return 1307674368000;
    else if (n == 16) return 20922789888000;
    else if (n == 17) return 355687428096000;
    else if (n == 18) return 6402373705728000;
    else if (n == 19) return 121645100408832000;
    else if (n == 20) return 2432902008176640000;
    else {
        // Para n > 20, calcular iterativamente
        ulllint result = 2432902008176640000ULL; // 20!
        for (ulllint i = 21; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
}

/**
 * @brief Calcula el coeficiente binomial C(n,k) de forma optimizada
 * @param n El número total de elementos
 * @param k El número de elementos a seleccionar
 * @return El coeficiente binomial C(n,k) = n! / (k! * (n-k)!)
 * @note Usa múltiples optimizaciones:
 *       - Valores precalculados para k <= 10
 *       - Propiedad de simetría C(n,k) = C(n,n-k)
 *       - Algoritmo iterativo sin factoriales para casos generales
 */
constexpr ullint binom(ullint n, ullint k) {
    if (k > n) return 0;
    else if ((k == n) || (k == 0)) return 1;
    else if (k == 1 || k == n - 1) return n;
    else if (k == 2 || k == n - 2) return n * (n - 1) / 2;
    else if (k == 3 || k == n - 3) return n * (n - 1) * (n - 2) / 6;
    else if (k == 4 || k == n - 4) return n * (n - 1) * (n - 2) * (n - 3) / 24;
    else if (k == 5 || k == n - 5) return n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120;
    else if (k == 6 || k == n - 6) return n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) / 720;
    else if (k == 7 || k == n - 7) return n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) * (n - 6) / 5040;
    else if (k == 8 || k == n - 8) return n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) * (n - 6) * (n - 7) / 40320;
    else if (k == 9 || k == n - 9) return n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) * (n - 6) * (n - 7) * (n - 8) / 362880;
    else if (k == 10 || k == n - 10) return n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) * (n - 6) * (n - 7) * (n - 8) * (n - 9) / 3628800;
    else {
        // Usar propiedad de simetría para minimizar cálculos
        if (k > n - k) k = n - k;
        
        // Algoritmo iterativo optimizado para evitar overflow
        ullint result = 1;
        for (ullint i = 0; i < k; ++i) {
            result = result * (n - i) / (i + 1);
        }
        return result;
    }
}

/**
 * @brief Versión alternativa de coeficiente binomial usando solo uint64_t
 * @param n El número total de elementos
 * @param k El número de elementos a seleccionar
 * @return El coeficiente binomial C(n,k)
 * @note Versión más portable que no usa __uint128_t
 */
constexpr ullint binom_optimized(ullint n, ullint k) {
    if (k > n) return 0;
    else if ((k == n) || (k == 0)) return 1;
    else if (k == 1 || k == n - 1) return n;
    else if (k == 2 || k == n - 2) return n * (n - 1) / 2;
    else if (k == 3 || k == n - 3) return n * (n - 1) * (n - 2) / 6;
    else if (k == 4 || k == n - 4) return n * (n - 1) * (n - 2) * (n - 3) / 24;
    else if (k == 5 || k == n - 5) return n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120;
    else if (k == 6 || k == n - 6) return n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) / 720;
    else if (k == 7 || k == n - 7) return n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) * (n - 6) / 5040;
    else if (k == 8 || k == n - 8) return n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) * (n - 6) * (n - 7) / 40320;
    else if (k == 9 || k == n - 9) return n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) * (n - 6) * (n - 7) * (n - 8) / 362880;
    else if (k == 10 || k == n - 10) return n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) * (n - 6) * (n - 7) * (n - 8) * (n - 9) / 3628800;
    else {
        // Usar propiedad de simetría
        if (k > n - k) k = n - k;
        
        // Algoritmo iterativo sin factoriales para evitar overflow
        ullint result = 1;
        for (ullint i = 0; i < k; ++i) {
            result = result * (n - i) / (i + 1);
        }
        return result;
    }
}

/**
 * @brief Verifica si un cálculo binomial causará overflow en uint64_t
 * @param n El número total de elementos
 * @param k El número de elementos a seleccionar
 * @return true si el resultado cabe en uint64_t, false si habría overflow
 */
constexpr bool binom_safe(ullint n, ullint k) {
    // Casos triviales que nunca causan overflow
    if (k > n || k == 0 || k == n || k == 1 || k == n - 1) {
        return true;
    }
    
    // Usar simetría
    if (k > n - k) k = n - k;
    
    // Verificación aproximada: si n es muy grande y k no es muy pequeño,
    // probablemente habrá overflow
    if (n > 60 && k > 2) return false;
    if (n > 30 && k > n/3) return false;
    
    // Para casos más pequeños, asumir que es seguro
    // (una implementación más robusta calcularía exactamente)
    return true;
}

// Funciones no-constexpr que van en el .cpp
void pascal_row(ullint n, ullint* results);
double binom_log_approx(ullint n, ullint k);
ullint binom_simple(ullint n, ullint k);

#endif // BINOMIAL_HPP