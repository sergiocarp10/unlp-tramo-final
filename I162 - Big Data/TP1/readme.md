# Práctica 1

## Ej 1
### Inciso a
* Se ejecuta map() unas 16 veces
* Se ejecuta reduce() unas 4 veces
* Se ejecutan 4 mappers
* Se ejecuta 1 reducer
* El reducer recibe la lista de values
* La salida del job es (1,16) [CHEQUEADO]

### Inciso b
* Se ejecuta map() unas 16 veces
* Se ejecuta reduce() unas 4 veces
* Se ejecutan 4 mappers
* Se ejecuta 1 reducer
* El reducer recibe la lista de values
* La salida del job es (1, 565) [CHEQUEADO]

### Inciso c
* Se ejecuta map() unas 16 veces
* Se ejecuta reduce() unas 8 veces
* Se ejecutan 4 mappers
* Se ejecutan 2 reducers
* Cada reducer recibe una lista de keys
* Las salidas del job son (1,36) y (2,32) [CHEQUEADO]

### Inciso d
* Se ejecuta map() unas 16 veces
* Se ejecuta reduce() unas 15 veces (unique keys)
* Se ejecutan 4 mappers
* Se ejecutan 14 reducers (unique keys)
* Cada reducer recibe el value unas value veces
* Las salidas del job son (key, suma de values) [CHEQUEADO]

### Inciso e
* Se ejecuta map() unas 16 veces
* Se ejecuta reduce() unas 16 veces
* Se ejecutan 4 mappers
* Se ejecutan 13 reducers (unique values)
* Las salidas del job son (key, numero entre 1 y veces que aparece su value) [CHEQUEADO]


## Ej 3
¿Cómo  haría  para obtener el  top  20  de  las palabras  más usadas?
* La función reduce no conoce resultados anteriores y posteriores, y además cada palabra puede aparecer en diferentes lineas, asi que no puedo pasar las apariciones de una palabra en cada linea procesada (map) como clave, entonces no me queda otra que mostrar las apariciones totales de cada palabra en la salida de manera desordenada, y luego aplicar un procesamiento posterior (ejemplo Excel)

## Ej 5
Indique si utilizando el dataset Libros es posible resolver los siguientes problemas:
1) Obtener los títulos de todos los libros
2) Obtener  la cantidad de palabras promedio por párrafo
3) Obtener  la cantidad de párrafos promedio por libro
4) Obtener  la cantidad de caracteres del párrafo más extenso
5) Cantidad total de párrafos con diálogos (se entiende por párrafo con diálogo aquel que empieza con un guión)
6) El diálogo más largo (se entiende por diálogo a una secuencia de párrafos con diálogo que aparecen de manera consecutiva)
7) El top 20 de las palabras más usadas por cada libro

Respuestas:

1) Si, ya que el offset del titulo es 0 en todos los archivos.
2) Si, la función map pasa la cantidad de palabras del párrafo que procesó, y la reduce calcula el promedio sumando las cantidades de palabras pasadas, y la cantidad de párrafos se obtiene a partir de la cantidad de VALORES recibidos.
3) No, porque la clave no contiene info del archivo origen?
4) Se puede obtener la cantidad de caracteres de cada párrafo (ordenado de menor a mayor ya que el valor es único por dato/linea), el máximo estará al final de alguna salida...
5) Si, ya que siguen un mismo "prefijo" y se pueden contabilizar todos bajo una única clave, de modo de obtener un solo resultado
6) No, porque no se conoce información del dato anterior.
7) No, desconozco el archivo origen

## Ej 6
Una  empresa  proveedora de  internet  realizó  una  encuesta  para  conocer  el  grado  de satisfacción  de  sus  clientes, en un  formulario  web  los  clientes debían  completar  un campo con los textos "Muy   satisfecho", "Algo satisfecho", "Poco satisfecho", “Disconforme” o "Muy disconforme". Utilice  el  dataset <b>Encuesta</b>  para  saber  cuántos clientes están en cada una de las cinco categorías.

* La función map enviará los datos de una misma opción bajo una misma clave, asi luego la función reduce las contabiliza.

* Vemos que el formato no siempre se respeta...

## Ej 7
El dataset <b>Inversionistas</b>  posee  los nombres, dni, fecha de nacimiento (día, mes y año como  campos  separados) e importe invertido por  diferentes personas en la apertura de un nuevo negocio en la ciudad. Se desea saber:
1) El nombre del inversionista más joven
2) El total del importe invertido por todos los inversionistas
3) El promedio de edad

Implemente una solución en MapReduce. ¿Se puede resolver los tres problemas en un único job?

* Columnas separadas por tabulación!
* Las columnas 1-3 (contando desde 0) son DD, MM y YYYY

## Ej 8
- Producir en los mappers unas tuplas con clave "POSITIVO" + random(33)
- Esto permite forzar la paralelización