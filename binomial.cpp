#include "binomial.hpp"
#include <limits>
#include <algorithm>
#include <cmath>

// Calcular una fila completa del triángulo de Pascal
void pascal_row(ullint n, ullint* results) {
    if (results == nullptr) return;
    
    // El primer y último elemento siempre son 1
    results[0] = 1;
    if (n > 0) results[n] = 1;
    
    // Calcular la primera mitad usando la fórmula optimizada
    for (ullint k = 1; k <= n/2; ++k) {
        results[k] = binom_optimized(n, k);
    }
    
    // Usar simetría para la segunda mitad
    for (ullint k = n/2 + 1; k < n; ++k) {
        results[k] = results[n - k];
    }
}

// Funciones de utilidad adicionales

/**
 * @brief Calcula el coeficiente binomial usando logaritmos para evitar overflow
 * @param n El número total de elementos
 * @param k El número de elementos a seleccionar
 * @return Aproximación en double del coeficiente binomial
 * @note Útil para valores muy grandes donde el resultado exacto causaría overflow
 */
double binom_log_approx(ullint n, ullint k) {
    if (k > n) return 0.0;
    if (k == 0 || k == n) return 1.0;
    if (k > n - k) k = n - k; // Simetría
    
    double result = 0.0;
    for (ullint i = 0; i < k; ++i) {
        result += std::log(static_cast<double>(n - i)) - std::log(static_cast<double>(i + 1));
    }
    return std::exp(result);
}

/**
 * @brief Versión iterativa simple del coeficiente binomial
 * @param n El número total de elementos  
 * @param k El número de elementos a seleccionar
 * @return El coeficiente binomial C(n,k)
 * @note Versión básica sin optimizaciones, útil para comparación
 */
ullint binom_simple(ullint n, ullint k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k; // Usar simetría
    
    ullint result = 1;
    for (ullint i = 0; i < k; ++i) {
        result = result * (n - i) / (i + 1);
    }
    return result;
}