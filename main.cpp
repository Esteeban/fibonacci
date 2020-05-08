#include <iostream>
#include <chrono>
#include <cstdlib>


using namespace std;

/**
 * Versión recursiva
 * @param numero Número a calcular
 * @return el factorial del número
 */
unsigned long long factorial_recursivo(int numero);

/**
 * Versión recursiva
 * @param numero Número a calcular
 * @return  el factorial del número
 */
unsigned long long factorial_iterativo(int numero);
/**
 * Función que muestra los participantes del grupo
 */

/** 
 * Version recursiva 
 * @param numero Numero a calcular
 * @return la serie de fibonacci del numero
 */
unsigned long long fibonacci(int numero);
 
 /**
 * Version iterativa
 * @param numero Numero a calcular
 * @return la serie de fibonacci del numero
 */
unsigned long long fibonacci_iterativo(int numero);


void participantes();

/**
 * Ejemplo Factorial
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */
int main(int argc, char** argv) {

    int numero;
    std::cout<<"Ingrese numero a trabajar: ";
    std::cin>>numero;

    /**
     * Medición recursiva
     */
    auto inicio_recursivo = chrono::steady_clock::now();
    unsigned long long recursivo = factorial_recursivo(numero);
    auto fin_recursivo = chrono::steady_clock::now();
    auto tiempo_recursivo = chrono::duration_cast<chrono::nanoseconds>(fin_recursivo - inicio_recursivo).count();
    std::cout << std::endl << "Factorial (Recursivo) de " << numero << " es " << recursivo << " demoró (" << tiempo_recursivo << "ns) " << std::endl;

    /**
     * Medición iterativa
     */
    auto inicio_iterativo = chrono::steady_clock::now();
    unsigned long long iterativo = factorial_iterativo(numero);
    auto fin_iterativo = chrono::steady_clock::now();
    auto tiempo_iterativo = chrono::duration_cast<chrono::nanoseconds>(fin_iterativo - inicio_iterativo).count();
    std::cout << std::endl << "Factorial (Iterativo) de " << numero << " es " << iterativo << " demoró (" << tiempo_iterativo << "ns) " << std::endl;

    /** Funcion de Fibonacci recursiva*/
    auto inicio_fibonacci = chrono::steady_clock::now();
    unsigned long long fibonacci_x = fibonacci(numero);
    auto fin_fibonacci = chrono::steady_clock::now();
    auto tiempo_fibonacci = chrono::duration_cast<chrono::nanoseconds>(fin_fibonacci - inicio_fibonacci).count();
    std::cout << std::endl << "La serie de fibonacci(Recursivo) de " << numero << " es " << fibonacci_x << " demoro (" << tiempo_fibonacci << "ns) " << std::endl;


    //funcion de fibonnacci iterada
    auto inicio_fibonacci_i = chrono::steady_clock::now();
    unsigned long long fibonacci = fibonacci_iterativo(numero);
    auto fin_fibonacci_i = chrono::steady_clock::now();
    auto tiempo_fibonacci_i = chrono::duration_cast<chrono::nanoseconds>(fin_fibonacci_i - inicio_fibonacci_i).count();
    std::cout << std::endl << "La serie de fibonacci(Iterativo) de " << numero << " es " << fibonacci << " demoro (" << tiempo_fibonacci_i << "ns) " << std::endl;



    /**
     * Despliegue de participantes
     */
    participantes();
    return EXIT_SUCCESS;
}

void participantes() {
    std::cout << std::endl << "=== Ejemplo de Factorial y Fibonacci ===" << std::endl;
    std::cout << std::endl << "Andres Munoz" << std::endl; 
    std::cout << std::endl << "Esteban Rojas" << std::endl;
    std::cout << std::endl << "Ignacio Valdevenito" << std::endl;
}

unsigned long long factorial_recursivo(int numero) {
    if (numero == 0) {
        return 1;
    } else {
        return (numero * factorial_recursivo(numero - 1));
    }
}

unsigned long long factorial_iterativo(int numero) {
    unsigned long long producto = 1;

    for (int i = 1; i <= numero; i++) {
        producto = producto * i;
    }


    return producto;
}

//fibonacci--> al un numero se le suma el numero anterior y=x+(x-1)+(x-...)+(x-n) hasta que el numero se haga 0 y no sume mas
unsigned long long fibonacci(int numero){
    if (numero==0){
        return numero;
    }
    else{
        return (numero + fibonacci(numero - 1)); //recursividad
    }
}

unsigned long long fibonacci_iterativo(int numero){
    int aux=0;
    if (numero==0){
        return numero;
    }
    else{
        while(numero != 0){
            aux +=numero;
            numero = numero-1;
        }
    }
    return aux;
}