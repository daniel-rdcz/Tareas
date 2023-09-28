# Actividad 1.2 Implementación de la técnica de programación "Programación dinámica" y "algoritmos avaros"

### Instrucciones

Utilizando las técnicas de programación de "programación dinámica", y la de "algoritmos avaros", escribe en C++ un programa que resuelva el problema del cambio de monedas.

El programa recibe un numero entero N, seguido de N valores enteros (uno en cada línea) por la entrada estándar (teclado), que representan las diferentes denominaciones disponibles de las monedas. 

Seguido de esto, el programa recibe dos números enteros: P y Q, (uno en cada línea) por la entrada estándar, que representan P: el precio de un producto dado y Q: es el billete o moneda con el que se paga dicho producto. Obviamente, el valor a convertir es el cambio, es decir, el valor Q - P.

La salida del programa es una impresión de N valores correspondientes al número de monedas de cada denominación, de mayor a menor, una en cada línea, que se tienen que dar para dar el cambio por el producto pagado, primero utilizando programación dinámica, y luego utilizando un algoritmo avaro.

El programa deberá tener 3 funciones obligatorias:

minNumMonGR(int n): recibe un entero que es la cantidad a ser cambiada a monedas y regresa una lista con el números de monedas de cada tipo que se usaron para formar la cantidad, usando el algoritmo Greedy.

minNumMonDP(int n): recibe un entero que es la cantidad a ser cambiada a monedas y regresa una lista con el números de monedas de cada tipo que se usaron para formar la cantidad, usando el algoritmo de Programación Dinámica.

escribeRespuesta(int n): recibe un entero que es la cantidad a ser cambiada a monedas e imprime, a la salida estándar (la pantalla) las soluciones obtenidas por Greedy y por Programación Dinámica. La impresión se realiza de la forma descrita arriba.

La función main deberá pedir, usando letreros, los valores a ser usados, de acuerdo a lo descrito anteriormente (exactamente en el orden indicado anteriormente) y debe llamar a la función escribeRespuesta(Q-P), la cual deberá llamar a su vez las dos funciones de los dos diferentes algoritmos (minNumMonGR(n) y minNumMonDP(n)) e imprimir la respuesta con un letrero que indique a qué algoritmo se refiere.

Por ejemplo, si en un país tenemos monedas de 50, 25, 20, 10, 5 y 1 centavos, el precio P del producto es 20 centavos y se paga con 60 centavos (es sólo para que de 40 que fue el ejercicio que hicimos en clase), el programa deberá imprimir:

Usando Greedy:

1 moneda de 25

1 moneda de 10

1 moneda de 5

Usando Programación Dinámica:

2 monedas de 20

Sube un archivo ZIP que se llame <tu_matricula>_Act1.2.ZIP. Es posible tener más archivos dentro de la carpeta.