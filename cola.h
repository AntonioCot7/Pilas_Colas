#ifndef PILAS_COLAS_ITERADORES_COLA_H
#define PILAS_COLAS_ITERADORES_COLA_H

#include <iostream>
#define MAX_QUEUE_SIZE 100
using namespace std;

template <typename T>
struct elemento {
    T key;
};

template <typename T>
struct queue {
    elemento<T> list[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

template <typename T>
void init_queue(queue<T>* q) {
    q->front = 0;
    q->rear = 0;
}


template <typename T>
int isfull(queue<T>* q) {
    return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

// Función para verificar si la cola está vacía
template <typename T>
int isempty(queue<T>* q) {
    return q->front == q->rear;
}

// Operación para agregar un elemento a la cola (enqueue)
template <typename T>
void enqueue(queue<T>* q, T key) {
    if (isfull(q)) {
        cout << "La cola está llena. No se puede agregar más elementos." << endl;
    } else {
        q->list[q->rear].key = key;  // Insertamos el elemento de tipo T
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // Movimiento circular
    }
}

// Operación para eliminar un elemento de la cola (dequeue)
template <typename T>
void dequeue(queue<T>* q) {
    if (isempty(q)) {
        cout << "La cola está vacía. No hay elementos para eliminar." << endl;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE; // Movimiento circular
    }
}

// Obtener el elemento al frente de la cola
template <typename T>
T front(queue<T>* q) {
    if (isempty(q)) {
        cout << "La cola está vacía." << endl;
        return T();  // Retornamos un valor por defecto de tipo T
    } else {
        return q->list[q->front].key;
    }
}

// Obtener el elemento en la parte posterior de la cola
template <typename T>
T back(queue<T>* q) {
    if (isempty(q)) {
        cout << "La cola está vacía." << endl;
        return T();  // Retornamos un valor por defecto de tipo T
    } else {
        return q->list[(q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE].key;
    }
}

// Ejemplo de uso con templates
void learn_cola() {
    queue<int> cola;  // Creamos una cola de enteros
    init_queue(&cola);
    enqueue(&cola, 10);
    enqueue(&cola, 20);
    enqueue(&cola, 30);
    cout << "Elemento en el frente de la cola: " << front(&cola) << endl;
    cout << "Elemento en la parte posterior de la cola: " << back(&cola) << endl;
    dequeue(&cola);
    cout << "Elemento en el frente después de hacer dequeue: " << front(&cola) << endl;

    // Usar cola con otro tipo de datos (por ejemplo, double)
    queue<double> cola_d;  // Creamos una cola de doubles
    init_queue(&cola_d);
    enqueue(&cola_d, 1.5);
    enqueue(&cola_d, 2.75);
    cout << "Elemento en el frente de la cola double: " << front(&cola_d) << endl;
}

#endif // PILAS_COLAS_ITERADORES_COLA_H
