#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include "binomial.hpp"

/**
 * @brief Programa de prueba para las funciones de coeficientes binomiales
 */

void test_basic_functionality() {
    std::cout << "=== PRUEBAS BÁSICAS DE FUNCIONALIDAD ===" << std::endl;
    
    // Pruebas de factorial
    std::cout << "\n--- Factoriales ---" << std::endl;
    for (int i = 0; i <= 10; ++i) {
        std::cout << i << "! = " << static_cast<unsigned long long>(fact(i)) << std::endl;
    }
    
    // Pruebas de coeficientes binomiales básicos
    std::cout << "\n--- Coeficientes Binomiales C(8,k) ---" << std::endl;
    for (int k = 0; k <= 8; ++k) {
        auto result1 = binom(8, k);
        auto result2 = binom_optimized(8, k);
        std::cout << "C(8," << k << ") = " << result1 
                  << " (optimized: " << result2 << ")" << std::endl;
        
        // Verificar que ambas implementaciones dan el mismo resultado
        if (result1 != result2) {
            std::cout << "❌ ERROR: Las implementaciones no coinciden!" << std::endl;
        }
    }
}

void test_pascal_triangle() {
    std::cout << "\n=== TRIÁNGULO DE PASCAL (usando pascal_row) ===" << std::endl;
    
    const int max_row = 10;
    for (int n = 0; n <= max_row; ++n) {
        std::vector<ullint> row(n + 1);
        pascal_row(n, row.data());
        
        // Centrar la fila
        for (int space = 0; space < (max_row - n); ++space) {
            std::cout << "  ";
        }
        
        // Imprimir los valores de la fila
        for (int k = 0; k <= n; ++k) {
            std::cout << std::setw(4) << row[k];
        }
        std::cout << std::endl;
    }
}

void test_safety_checks() {
    std::cout << "\n=== PRUEBAS DE SEGURIDAD (OVERFLOW) ===" << std::endl;
    
    struct TestCase {
        ullint n, k;
        std::string description;
    };
    
    std::vector<TestCase> cases = {
        {10, 5, "Caso seguro pequeño"},
        {30, 15, "Caso seguro mediano"}, 
        {60, 30, "Caso límite"},
        {100, 50, "Caso probablemente inseguro"},
        {70, 35, "Caso grande"}
    };
    
    for (const auto& test : cases) {
        bool is_safe = binom_safe(test.n, test.k);
        std::cout << "C(" << test.n << "," << test.k << ") - " 
                  << test.description << ": " 
                  << (is_safe ? "✅ SEGURO" : "⚠️  RIESGO DE OVERFLOW") << std::endl;
        
        if (is_safe) {
            auto result = binom_optimized(test.n, test.k);
            std::cout << "  Resultado: " << result << std::endl;
        }
    }
}

void performance_comparison() {
    std::cout << "\n=== COMPARACIÓN DE RENDIMIENTO ===" << std::endl;
    
    const int iterations = 1000000;
    std::vector<std::pair<ullint, ullint>> test_cases = {
        {20, 10}, {30, 15}, {40, 20}
    };
    
    for (const auto& [n, k] : test_cases) {
        // Medir binom_optimized
        auto start = std::chrono::high_resolution_clock::now();
        ullint sum1 = 0;
        for (int i = 0; i < iterations; ++i) {
            sum1 += binom_optimized(n, k);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto time1 = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        // Medir binom (versión original)
        start = std::chrono::high_resolution_clock::now();
        ullint sum2 = 0;
        for (int i = 0; i < iterations; ++i) {
            sum2 += binom(n, k);
        }
        end = std::chrono::high_resolution_clock::now();
        auto time2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        std::cout << "C(" << n << "," << k << "):" << std::endl;
        std::cout << "  binom_optimized: " << time1.count() << " μs" << std::endl;
        std::cout << "  binom original:  " << time2.count() << " μs" << std::endl;
        std::cout << "  Resultado: " << sum1 / iterations << std::endl;
        std::cout << "  Verificación: " << (sum1 == sum2 ? "✅ MATCH" : "❌ MISMATCH") << std::endl;
    }
}

void demonstration_use_cases() {
    std::cout << "\n=== CASOS DE USO DEMOSTRATIVOS ===" << std::endl;
    
    // 1. Probabilidad binomial
    std::cout << "\n--- Probabilidad Binomial ---" << std::endl;
    std::cout << "Probabilidad de obtener exactamente 3 caras en 10 lanzamientos:" << std::endl;
    ullint combinations = binom_optimized(10, 3);
    double probability = static_cast<double>(combinations) / (1 << 10); // 2^10
    std::cout << "C(10,3) = " << combinations << std::endl;
    std::cout << "P(X=3) = " << combinations << "/1024 = " 
              << std::fixed << std::setprecision(4) << probability << std::endl;
    
    // 2. Expansión binomial
    std::cout << "\n--- Coeficientes de (x+y)^6 ---" << std::endl;
    std::cout << "(x+y)^6 = ";
    for (int k = 0; k <= 6; ++k) {
        ullint coeff = binom_optimized(6, k);
        if (k > 0) std::cout << " + ";
        std::cout << coeff;
        
        if (6 - k > 0) {
            std::cout << "x";
            if (6 - k > 1) std::cout << "^" << (6 - k);
        }
        if (k > 0) {
            std::cout << "y";
            if (k > 1) std::cout << "^" << k;
        }
    }
    std::cout << std::endl;
    
    // 3. Combinaciones en un juego
    std::cout << "\n--- Combinaciones de Poker ---" << std::endl;
    std::cout << "Maneras de elegir 5 cartas de 52:" << std::endl;
    ullint poker_combinations = binom_optimized(52, 5);
    std::cout << "C(52,5) = " << poker_combinations << " combinaciones posibles" << std::endl;
}

int main() {
    std::cout << "🧮 PRUEBAS DEL MÓDULO BINOMIAL" << std::endl;
    std::cout << "==============================" << std::endl;
    
    test_basic_functionality();
    test_pascal_triangle();
    test_safety_checks();
    performance_comparison();
    demonstration_use_cases();
    
    std::cout << "\n✅ Todas las pruebas completadas!" << std::endl;
    std::cout << "\n📚 Archivos creados:" << std::endl;
    std::cout << "  • binomial.hpp - Declaraciones de funciones" << std::endl;
    std::cout << "  • binomial.cpp - Implementaciones" << std::endl;
    std::cout << "  • test_binomial.cpp - Este archivo de pruebas" << std::endl;
    
    return 0;
}