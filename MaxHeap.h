#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

#include <vector>
#include <iostream>
#include <stdexcept>

template <class T>
class MaxHeap
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
    MaxHeap(int capacity);
    ~MaxHeap();
    bool isEmpty();
    int getCapacity();
    void printMaxHeap();
    void push(T key);
    T top();
    void pop();
    int getSize();
};

template <class T>
MaxHeap<T>::MaxHeap(int capacity)
{
    std::cout << "--->Creando un MaxHeap: " << this << std::endl;
    size = 0;
    maxSize = capacity;
    data.resize(maxSize);
}

template <class T>
MaxHeap<T>::~MaxHeap()
{
    std::cout << "--->Liberando memoria del MaxHeap: " << this << std::endl;
    data.clear();
}

template <class T>
bool MaxHeap<T>::isEmpty()
{
    return (size <= 0);
}

template <class T>
int MaxHeap<T>::getCapacity()
{
    return maxSize;
}

template <class T>
void MaxHeap<T>::printMaxHeap()
{
    for (int i = 0; i < size; i++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

template <class T>
int MaxHeap<T>::parent(int i)
{
    return (i - 1) / 2;
}

template <class T>
int MaxHeap<T>::left(int i)
{
    return (2 * i + 1);
}

template <class T>
int MaxHeap<T>::right(int i)
{
    return (2 * i + 2);
}

template <class T>
void MaxHeap<T>::push(T key)
{
    if (size == maxSize)
    {
        throw std::out_of_range("Overflow: no se puede insertar la llave: " + std::to_string(key));
    }
    // Insertamos la nueva llave al final del vector
    int i = size;
    data[i] = key;
    size++;
    // Reparar las propiedades del max heap si son violadas
    while (i != 0 && data[parent(i)] < data[i])
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
T MaxHeap<T>::top()
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
void MaxHeap<T>::pop()
{
    if (this->isEmpty())
    {
        throw std::out_of_range("No hay elementos en la lista");
    }
    else
    {
        // regresamos a su valor default el dato con mayor prioridad
        data[0] = T();
        int i = 0;
        size--;
        std::swap(data[0], data[size]);

        // mientras uno de los valores hijo sea mayor hay que seguir ejecutando el ciclo
        while (data[i] < data[left(i)] || data[i] < data[right(i)])
        {
            // Si el hijo izquierdo es mayor que el derecho se intercambia por el
            if (data[left(i)] > data[right(i)])
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

//Regresa la cantidad de datos que tiene la fila priorizada
//Entrada: Nada
//Salida: Un valor entero que representa la cantidad de datos de la fila priorizada
//Complejidad: O(1) se obtiene en tiempo coonstante ya que solo se accede a un atributo del objeto MaxHeap
template <class T>
int MaxHeap<T>::getSize()
{
    return size;
}
#endif // __MAXHEAP_H_