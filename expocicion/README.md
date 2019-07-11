# kruskal
algoritmo de kruskal en php

| grafo        | Resultado           |
| ------------- |-------------|
| ![kruskal](https://user-images.githubusercontent.com/47792684/59984348-bd2b5700-95ee-11e9-8ded-8afd5ee3c3e3.gif) | 2 => 3 = 4<br>0 => 3 = 5<br>0 => 1 = 10 | 

El algoritmo de Kruskal trata cada nodo como un árbol independiente y se conecta uno con otro solo si tiene el costo más bajo en comparación con todas las demás opciones disponibles.

# Pasos:
* Se selecciona, de entre todas las aristas restantes, la de menor peso siempre que no cree ningún ciclo.
* Se repite el paso 1 hasta que se hayan seleccionado |V| - 1 aristas.
<br>V = número de vertices
