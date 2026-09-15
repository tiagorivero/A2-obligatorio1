# Justificación de órdenes — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1
- La letra pedia ALTA y BUSCAR en O(log K) y RANGO en O(log K + R), para el TAD use un unico 
AVL<T> generico, el arbol tiene altura O(log K) por lo que ALTA y BAJA bajan por un solo camino 
siendo O(1) por nivel, luego como RANGO va cortando las ramas fuera del rango, termina 
visitando solo los dos caminos de borde más los R que son escritos por consola.

## Ejercicio 2
- La letra pedía tabla de hash abierta con encadenamiento y registrar/consultar una palabra en 
O(L) promedio, siendo L el largo, obtengo la clave del cajón  contandolas 26 letras de la 
palabra en orden O(L) y luego calculo el hash con esa clave siendo O(1), luego dimensiono la 
tabla con N buckets desde el principio para que el factor de carga se mantenga sano durante 
todo el proceso, dando el factor de carga λ = N/N = 1 en el peor caso (todas las palabras en 
cajones distintos), sin necesidad de hacer rehash porque N es la cantidad maxima de registros 
desde el inicio.
Así la lista de cada bucket tiene el largo esperado O(1) y el costo de memoria no depende de 
cuántas palabras comparten cajón, luego los valores de cajones distintos y tamaño del cajón más 
grande los actualizo en cada registro, así queda en O(1) sin recorrer la tabla.

## Ejercicio 3
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 4
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 5
- Sin restricciones de órdenes. / Justificación: ...

