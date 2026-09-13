# Bitácora — Obligatorio 1

**Integrantes:** Tiago Rivero (336462)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## 2026-09-10 — Tiago Rivero
- Lei la letra del ejercicio 1, al principio no entendia una parte de la letra y si las funciones de ALTA,BUSCAR,RANGO, eran parte del TAD o si debian estar en el main, a lo que consulte con claude mis dudas de la letra.
- Claude me dijo que en el main debia interpertar el nombre de la operacion y el tipo y asi llamar el metodo correspondiente.
- Para el TAD reutilice la base del TAD que hicimos para el AVL en clase, me faltaria adaptarlo para este contexto .
- Pendiente: Me quedo pendiente para mañana agregar funcion de rango y pertenece, y probar si pasa las pruebas.

## 2026-09-13 — Tiago Rivero
- Arregle el main en el que en un inicio utilizaba un while, pero me parecio inecesario y ya con un un for funcionaba y separe la logica de pedir los datos en vez de todos de una pedirle segun si estamos en RANGO o en ALTA/BUSCAR.
- Usando de base la implementacion de AVL vista en clase, agrego las funciones de pertenece, donde recursivamente voy avanzando en el arbol binario hasta encontrar el dato devolviendo true y en caso contrario false si llego a NULL, y agregando tambien rango donde, recorremos recursivamente el arbol utilizando inorder, y imprimimos los datos que esten dentro de este rango.
- Luego corri las pruebas y arrege problemas simples y los mas complejos los consulte con claude acerca de que eran y de donde provenian,
- Lei la letra del ejercicio 2,


