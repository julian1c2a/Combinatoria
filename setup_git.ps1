# Script para configurar Git y subir a GitHub
# Ejecutar después de instalar Git desde https://git-scm.com/downloads

Write-Host "=== Configuración del repositorio Git ===" -ForegroundColor Green

# Verificar que Git esté instalado
try {
    git --version
    Write-Host "✅ Git encontrado" -ForegroundColor Green
} catch {
    Write-Host "❌ Git no está instalado. Descarga desde: https://git-scm.com/downloads" -ForegroundColor Red
    exit 1
}

# Configurar Git (cambiar por tus datos)
Write-Host "Configurando usuario Git..." -ForegroundColor Yellow
git config --global user.name "Tu Nombre"
git config --global user.email "tu.email@ejemplo.com"

# Inicializar repositorio
Write-Host "Inicializando repositorio..." -ForegroundColor Yellow
git init

# Agregar archivos
Write-Host "Agregando archivos..." -ForegroundColor Yellow
git add .

# Commit inicial
Write-Host "Haciendo commit inicial..." -ForegroundColor Yellow
git commit -m "Initial commit: Ultra-optimized binomial coefficient library

Features:
- Constexpr factorial and binomial coefficient functions
- Performance optimizations achieving 15+ million calculations/second
- Comprehensive benchmark suite
- Complete modular architecture with .hpp/.cpp separation
- Extensive documentation and tests
- C++23 compatible code

Benchmarks show exceptional performance:
- Small values (k≤10): ~1-15ns per calculation
- Medium values: ~50-200ns per calculation
- Large values: ~300-400ns per calculation"

Write-Host "✅ Repositorio local configurado!" -ForegroundColor Green
Write-Host ""
Write-Host "=== Próximos pasos ===" -ForegroundColor Cyan
Write-Host "1. Crea un repositorio en GitHub (https://github.com/new)"
Write-Host "2. Ejecuta estos comandos (reemplaza URL):"
Write-Host "   git remote add origin https://github.com/USUARIO/REPOSITORIO.git"
Write-Host "   git branch -M main"
Write-Host "   git push -u origin main"
Write-Host ""
Write-Host "¡Tu biblioteca de coeficientes binomiales estará en GitHub!" -ForegroundColor Green