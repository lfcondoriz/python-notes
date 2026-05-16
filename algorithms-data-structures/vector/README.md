# TDA Vector
El vector es una estructura de datos que almacena elementos de forma contigua en memoria. Es similar a un arreglo, pero con la capacidad de redimensionarse dinámicamente.

Ejecuta el siguiente código para ver cómo funciona el TDA Vector:

```cpp
g++ algorithms-data-structures/vector/main.cpp algorithms-data-structures/vector/vector.cpp -o main -std=c++11 -Wall -Wextra -pedantic
./main
```
Se puede agregar flags:
- `-g` para incluir información de depuración.
- `-O2` para optimizar el código.
- `-Wall` para mostrar todas las advertencias.
- `-Wextra` para mostrar advertencias adicionales.
- `-pedantic` para cumplir con el estándar C++.


Con valgrind:

```bash
valgrind ./main
```

## Funciones del TDA Vector
- `at(size_t index)`: Accede al elemento en la posición `index` con verificación de límites. Es seguro, con excepción.
- `operator[](size_t index)`: Accede al elemento en la posición `index` sin verificación de límites. Es rápido pero sin chequeo
- `front()`: Devuelve una referencia al primer elemento del vector. Es rápido y sin chequeo.

## Conceptos clave
## STL (Standard Template Library) 
Es una biblioteca de C++ que proporciona estructuras de datos y algoritmos genéricos. El `std::vector` es una implementación de un vector dinámico en la STL.

- STL está construido alrededor de: iteradores. No de índices.
    Entonces muchas funciones son equivalentes a operaciones de iteradores
    ```cpp
    front()  -> *begin()
    back()   -> *(end()-1)
    ```

### ¿Por qué no liberar memoria automáticamente en `pop_back()`?

Porque pop_back() solo destruye el último elemento lógico. NO cambia la capacidad reservada.

Porque STL asume esto:

> tal vez vas a volver a insertar elementos. Porque prioriza: performance estable, sobre liberar memoria agresivamente.

Entonces conservar memoria evita reallocaciones costosas.

Si reducís en cada pop constantemente:
- sería lentísimo
- fragmentaría memoria,
- destruiría performance.

Existen métodos como `shrink_to_fit()` (Opcionalmente reduce capacity) para liberar memoria no usada, pero no se llama automáticamente en `pop_back()`. NO está garantizado. Es solo una “request”.