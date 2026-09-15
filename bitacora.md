# Bitácora — Obligatorio 1

**Integrantes:** Tiago Rivero (336462)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## 2026-09-10 — Tiago Rivero
- Lei la letra del ejercicio 1, al principio no entendia una parte de la letra y si las 
funciones de ALTA,BUSCAR,RANGO, eran parte del TAD o si debian estar en el main, a lo que 
consulte con claude mis dudas de la letra.
- Claude me dijo que en el main debia interpertar el nombre de la operacion y el tipo y asi 
llamar el metodo correspondiente.
- Para el TAD reutilice la base del TAD que hicimos para el AVL en clase, me faltaria adaptarlo 
para este contexto .
- Pendiente: Me quedo pendiente para mañana agregar funcion de rango y pertenece, y probar si 
pasa las pruebas.

## 2026-09-13 — Tiago Rivero
- Arregle el main en el que en un inicio utilizaba un while, pero me parecio inecesario y ya 
con un un for funcionaba y separe la logica de pedir los datos en vez de todos de una pedirle 
segun si estamos en RANGO o en ALTA/BUSCAR.
- Usando de base la implementacion de AVL vista en clase, agrego las funciones de pertenece, 
donde recursivamente voy avanzando en el arbol binario hasta encontrar el dato devolviendo true 
y en caso contrario false si llego a NULL, y agregando tambien rango donde, recorremos 
recursivamente el arbol utilizando inorder, y imprimimos los datos que esten dentro de este 
rango.
- Luego corri las pruebas y arrege problemas simples y los mas complejos los consulte con \
claude acerca de que eran y de donde provenian.

- Lei la letra del ejercicio 2, no me quedo muy claro como debia tratar con los strings por lo 
cual le pedi una corta explicacion de la letra con un ejemplo para luego yo crear una primera 
version del main basada en la que hicimos en clase, para la cual mejore depurando con ayuda de 
claude.
- Claude me dijo que no tomara la palabra cruda como clave, ya que ese caso palabras como amor 
y roma quedarian en diferente bucket, por lo que decidi separarlo segun que letras son 
utilizadas y en que cantidad.
- En esta primera version no habia tenido en cuenta las cantidades, para lo que luego tome el 
valor del primer nodo, para segun el caso sumar y calcular el maximo.
- Luego volvie a depurar mi nuevo codigo con claude para el cual ahora tuve que cambiar el 
manejo de la nueva clave ya que me daba problemas con los valores ASCII, y arreglar problemas 
con punteros.
- Pendiente: Mañana adaptar la implementacion de hashAbierto.

## 2026-09-14 — Tiago Rivero
- Empece adaptando la implementacion de hash cerrado hecha en clase para que sea hash abierto, 
el cual es mucho mas simple, ya que en este caso ya no se itera por intentos hasta encontrar un 
bucket vacio sino que se encadena en las lista enlazada.
- En obtenerIndice ya no era necesario sumar los intentos, en buscar simplemente iteramos en la 
lista enlazada, en el destructor hay que iterar y ir eliminando nodo por nodo, en insertar 
simplemente lo inserto al principio de la lista si no existe, sino solo cambio el valor, y en 
existir recorremos la lista enlazada manteniendo el anterior para poder encadenar.
- Luego depure con claude para verificar que mi implementacion para detectar algunos errores 
simples que tenia y que mi implementacion sea consistente con lo que pide la letra.
- Claude me dijo q mi funcion de hash podia dar numeros negativos para lo cual lo arregle  
sumando la cantidad de buckets si el hash daba negativo.
- Luego de arreglar estos simples problemas, corri las pruebas y por ultimo justifique los 
ordenes y mi decisión sobre el factor de carga.

- Lei la letra del ejercicio 3.
- Pendiente: Mañana empezar el ejercicio 3, hoy solo lo lei.

## 2026-09-15 — Tiago Rivero
- 
