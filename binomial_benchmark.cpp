#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <random>
#include <algorithm>

using ullint = std::uint64_t;
using ulllint = std::uint64_t; // Cambiar a uint64_t para compatibilidad con cout

// Copiamos tus funciones optimizadas
constexpr ulllint fact(ulllint n) {
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
        ulllint result{1};
        for (ulllint i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
}

constexpr ulllint binom_optimized(ulllint n, ulllint k) {
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
    else if (k ==10 || k == n -10) return n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5)*(n-6)*(n-7)*(n-8)*(n-9)/3628800;
    else {
        if(k > n-k) k = n - k; // Use symmetry property
        ulllint result = 1;
        for(ulllint i = 0; i < k; ++i) {
            result = result * (n - i) / (i + 1);
        }
        return result;
    }
}

// Implementación simple para comparación
ulllint binom_simple(ulllint n, ulllint k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k; // Usar simetría
    
    ulllint result = 1;
    for (ulllint i = 0; i < k; ++i) {
        result = result * (n - i) / (i + 1);
    }
    return result;
}

// Implementación usando factoriales (más lenta para n grandes)
ulllint binom_factorial(ulllint n, ulllint k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k;
    
    return static_cast<ulllint>(fact(n)) / (static_cast<ulllint>(fact(k)) * static_cast<ulllint>(fact(n - k)));
}

// Función para medir tiempo de ejecución
template<typename Func>
auto measure_time(Func&& func, int iterations = 1000000) {
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < iterations; ++i) {
        func();
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

int main() {
    std::cout << "=== BENCHMARK DE COEFICIENTES BINOMIALES ===" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    
    // Parámetros de prueba
    std::vector<std::pair<ulllint, ulllint>> test_cases = {
        {10, 5}, {20, 10}, {30, 15}, {40, 20}, {50, 25}
    };
    
    const int iterations = 100000;
    
    std::cout << "\n┌─────────┬─────────┬──────────────┬──────────────┬──────────────┬─────────────┐" << std::endl;
    std::cout << "│   n     │    k    │  Optimizada  │    Simple    │  Factorial   │ Resultado   │" << std::endl;
    std::cout << "│         │         │     (μs)     │     (μs)     │     (μs)     │             │" << std::endl;
    std::cout << "├─────────┼─────────┼──────────────┼──────────────┼──────────────┼─────────────┤" << std::endl;
    
    for (const auto& [n, k] : test_cases) {
        // Medir función optimizada
        auto time_optimized = measure_time([n, k]() {
            volatile auto result = binom_optimized(n, k);
        }, iterations);
        
        // Medir función simple
        auto time_simple = measure_time([n, k]() {
            volatile auto result = binom_simple(n, k);
        }, iterations);
        
        // Medir función con factoriales (solo para n pequeños)
        auto time_factorial = std::chrono::microseconds(0);
        if (n <= 20) {
            time_factorial = measure_time([n, k]() {
                volatile auto result = binom_factorial(n, k);
            }, iterations);
        }
        
        auto result = binom_optimized(n, k);
        
        std::cout << "│ " << std::setw(7) << static_cast<unsigned long long>(n)
                  << " │ " << std::setw(7) << static_cast<unsigned long long>(k)
                  << " │ " << std::setw(12) << time_optimized.count()
                  << " │ " << std::setw(12) << time_simple.count()
                  << " │ " << std::setw(12) << (n <= 20 ? std::to_string(time_factorial.count()) : "N/A")
                  << " │ " << std::setw(11) << static_cast<unsigned long long>(result) << " │" << std::endl;
    }
    
    std::cout << "└─────────┴─────────┴──────────────┴──────────────┴──────────────┴─────────────┘" << std::endl;
    
    // Test intensivo con muchos cálculos
    std::cout << "\n=== TEST INTENSIVO ===" << std::endl;
    std::cout << "Calculando 1,000,000 coeficientes binomiales aleatorios..." << std::endl;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> n_dist(10, 50);
    
    const int intensive_iterations = 1000000;
    std::vector<std::pair<int, int>> random_pairs;
    random_pairs.reserve(intensive_iterations);
    
    // Generar pares aleatorios
    for (int i = 0; i < intensive_iterations; ++i) {
        int n = n_dist(gen);
        std::uniform_int_distribution<> k_dist(0, n);
        int k = k_dist(gen);
        random_pairs.emplace_back(n, k);
    }
    
    // Test con función optimizada
    auto start_intensive = std::chrono::high_resolution_clock::now();
    ulllint sum_optimized = 0;
    for (const auto& [n, k] : random_pairs) {
        sum_optimized += binom_optimized(n, k);
    }
    auto end_intensive = std::chrono::high_resolution_clock::now();
    auto time_intensive = std::chrono::duration_cast<std::chrono::milliseconds>(end_intensive - start_intensive);
    
    std::cout << "Tiempo total: " << time_intensive.count() << " ms" << std::endl;
    std::cout << "Promedio por cálculo: " << (time_intensive.count() * 1000.0 / intensive_iterations) << " ns" << std::endl;
    std::cout << "Cálculos por segundo: " << (intensive_iterations * 1000.0 / time_intensive.count()) << std::endl;
    std::cout << "Suma de verificación: " << static_cast<unsigned long long>(sum_optimized) << std::endl;
    
    // Comparación de precisión
    std::cout << "\n=== VERIFICACIÓN DE PRECISIÓN ===" << std::endl;
    std::vector<std::pair<int, int>> precision_tests = {
        {10, 5}, {15, 7}, {20, 10}, {25, 12}
    };
    
    bool all_match = true;
    for (const auto& [n, k] : precision_tests) {
        auto opt = binom_optimized(n, k);
        auto simple = binom_simple(n, k);
        auto factorial = (n <= 20) ? binom_factorial(n, k) : simple;
        
        std::cout << "C(" << n << "," << k << "): ";
        std::cout << "Opt=" << static_cast<unsigned long long>(opt) << " ";
        std::cout << "Simple=" << static_cast<unsigned long long>(simple) << " ";
        if (n <= 20) std::cout << "Fact=" << static_cast<unsigned long long>(factorial) << " ";
        
        if (opt == simple && (n > 20 || opt == factorial)) {
            std::cout << "✓ MATCH" << std::endl;
        } else {
            std::cout << "✗ MISMATCH" << std::endl;
            all_match = false;
        }
    }
    
    std::cout << "\nTodas las implementaciones coinciden: " << (all_match ? "SÍ ✓" : "NO ✗") << std::endl;
    
    return 0;
}