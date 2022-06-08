#ifndef __MINHEAP_H_
#define __MINHEAP_H_

#include <vector>
#include <iostream>
#include <stdexcept>

template <class T>
class MinHeap
{
private:
    // contiene los elementos del heap
    std::vector<T> data;
    // capacidad maxima del heap
    int maxSize;
    // tamaño actual del heap
    int size;
    int parent(int i);
    int left(int i);
    int right(int i);

public:
    MinHeap(int capacity);
    ~MinHeap();
    bool isEmpty();
    int getCapacity();
    void printMinHeap();
    void push(T key);
    T top();
    void pop();
    int getSize();
    bool isInMinHeap(int node);
    void updateMinDistance(int node, int distance);
    int getMinDistance(int node);
};

template <class T>
MinHeap<T>::MinHeap(int capacity)
{
    size = 0;
    maxSize = capacity;
    data.resize(maxSize);
}

template <class T>
MinHeap<T>::~MinHeap()
{
    data.clear();
}

template <class T>
bool MinHeap<T>::isEmpty()
{
    return (size <= 0);
}

template <class T>
int MinHeap<T>::getCapacity()
{
    return maxSize;
}

template <class T>
void MinHeap<T>::printMinHeap()
{
    for (int i = 0; i < size; i++)
    std::cout << std::endl;
}

template <class T>
int MinHeap<T>::parent(int i)
{
    return (i - 1) / 2;
}

template <class T>
int MinHeap<T>::left(int i)
{
    if (2 * i + 1 > size - 1)
    {
        return size;
    }
    else
    {
        return (2 * i + 1);
    }
}

template <class T>
int MinHeap<T>::right(int i)
{
    if (2 * i + 2 > size - 1)
    {
        return size;
    }
    else
    {
        return (2 * i + 2);
    }
}

template <class T>
void MinHeap<T>::push(T key)
{
    if (size == maxSize)
    {
        throw std::out_of_range("Overflow: no se puede insertar la llave: ");
    }
    // Insertamos la nueva llave al final del vector
    int i = size;
    data[i] = key;
    size++;
    // Reparar las propiedades del max heap si son violadas
    while (i != 0 && data[parent(i)].getMinDistance() > data[i].getMinDistance())
    {
        std::swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

// Regresa el valor del dato que está con mayor prioridad en la fila priorizada.
// Entrada: Ninguna
// Salida: el dato con mayor prioridad en el heap
// Complejidad: O(1), siempre tarda un tiempo constante en acceder al primer elemento del heap
template <class T>
T MinHeap<T>::top()
{
    if (this->isEmpty())
    {
        throw std::out_of_range("No hay elementos en la lista");
    }
    else
    {
        return data[0];
    }
}

// Saca de la fila priorizada el dato que tiene mayor prioridad
// Entrada y Salida: Ninguna
// Complejidad: O(log N) dado que solo hace una comparacion por "nivel del arbol"
template <class T>
void MinHeap<T>::pop()
{
    if (this->isEmpty())
    {
        throw std::out_of_range("No hay elementos en la lista");
    }
    else
    {
        // regresamos a su valor default el dato con mayor prioridad
        data[0].setMinDistance(std::numeric_limits<int>::max());
        int i = 0;
        size--;
        std::swap(data[0], data[size]);

        // mientras uno de los valores hijo sea mayor hay que seguir ejecutando el ciclo
        while (data[i].getMinDistance() > data[left(i)].getMinDistance() || data[i].getMinDistance() > data[right(i)].getMinDistance())
        {
            // Si el hijo izquierdo es menor que el derecho se intercambia por el
            if (data[left(i)].getMinDistance() < data[right(i)].getMinDistance())
            {
                std::swap(data[i], data[left(i)]);
                i = left(i);
            }
            else
            {
                std::swap(data[i], data[right(i)]);
                i = right(i);
            }
        }
    }
}

// Regresa la cantidad de datos que tiene la fila priorizada
// Entrada: Nada
// Salida: Un valor entero que representa la cantidad de datos de la fila priorizada
// Complejidad: O(1) se obtiene en tiempo coonstante ya que solo se accede a un atributo del objeto MinHeap
template <class T>
int MinHeap<T>::getSize()
{
    return size;
}

template <class T>
bool MinHeap<T>::isInMinHeap(int node)
{

    for (int i = 0; i < size; i++)
    {
        if (data[i].getNumberNode() == node)
        {
            return true;
        }
    }
    return false;
}

// O(N) complexity
template <class T>
void MinHeap<T>::updateMinDistance(int node, int distance)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i].getNumberNode() == node)
        {
            data[i].setMinDistance(distance);
        }
    }
}

template <class T>
int MinHeap<T>::getMinDistance(int node)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i].getNumberNode() == node)
        {
            return data[i].getMinDistance();
        }
    }
    return -1;
}

#endif // __MinHeap_H_