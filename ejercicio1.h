#ifndef PILAS_COLAS_ITERADORES_EJERCICIO1_H
#define PILAS_COLAS_ITERADORES_EJERCICIO1_H

#include "stack.h"
int calcularProfundidadMaxima(string cadena) {
    stack<string> pila;
    init_stack(&pila);
    int max_depth = 0;
    int current_depth = 0;

    for (char c : cadena) {
        if (c == '(') {
            push(&pila, cadena);
            current_depth++;
            if (current_depth > max_depth) {
                max_depth = current_depth;
            }
        } else if (c == ')') {
            if (!isempty(&pila)) {
                pop(&pila);
                current_depth--;
            }
        }
    }

    return max_depth;
}

void ejercicio1() {
    string input;
    cout << "Introduce una cadena con paréntesis: ";
    cin >> input;

    int profundidad = calcularProfundidadMaxima(input);
    cout << "La profundidad máxima de anidamiento es: " << profundidad << endl;

}

#endif //PILAS_COLAS_ITERADORES_EJERCICIO1_H
