#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

// Ejemplo usando C++23 features
int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Usando ranges (C++20+) y otras características modernas
    auto even_numbers = numbers 
        | std::views::filter([](int n) { return n % 2 == 0; })
        | std::views::transform([](int n) { return n * n; });
    
    std::cout << "Números pares al cuadrado: ";
    for (auto num : even_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Deducción automática de tipos mejorada (C++17+)
    auto lambda = []<typename T>(T value) {
        std::cout << "Valor: " << value << std::endl;
        return value * 2;
    };
    
    auto result = lambda(42);
    std::cout << "Resultado: " << result << std::endl;
    
    return 0;
}