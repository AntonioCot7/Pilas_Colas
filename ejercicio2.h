#ifndef PILAS_COLAS_ITERADORES_EJERCICIO2_H
#define PILAS_COLAS_ITERADORES_EJERCICIO2_H

#include <iostream>
using namespace std;

template <typename T>
class MyCircularDeque {
private:
    T* dequeArray;
    int front;
    int rear;
    int maxSize;

public:
    MyCircularDeque(int k) {
        maxSize = k + 1;
        dequeArray = new T[maxSize];
        front = 0;
        rear = 0;
    }

    bool insertFront(T value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + maxSize) % maxSize;
        dequeArray[front] = value;
        return true;
    }

    // Insertar un elemento al final de la deque
    bool insertLast(T value) {
        if (isFull()) {
            return false;
        }
        dequeArray[rear] = value;
        rear = (rear + 1) % maxSize;
        return true;
    }

    // Eliminar el elemento del frente de la deque
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % maxSize;
        return true;
    }

    // Eliminar el elemento del final de la deque
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + maxSize) % maxSize;
        return true;
    }

    // Obtener el elemento del frente de la deque
    T getFront() {
        if (isEmpty()) {
            return T();
        }
        return dequeArray[front];
    }

    T getRear() {
        if (isEmpty()) {
            return T();
        }
        return dequeArray[(rear - 1 + maxSize) % maxSize];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % maxSize == front;
    }
};

#endif //PILAS_COLAS_ITERADORES_EJERCICIO2_H
