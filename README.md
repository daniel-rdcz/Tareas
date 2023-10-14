## Instrucciones
Escribe un programa en C++ que reciba el nombre de un archivo de texto, seguido de un entero n, donde n es un entero múltiplo de 4 y  (16 <= n <=64)

La salida es una cadena de longitud n/4 que es una representación hexadecimal que corresponde al hasheo del archivo de texto de entrada de acuerdo con las siguientes reglas:

El entero n determina el número de columnas que contendrá una tabla donde se irán acomodando los caracteres del archivo de texto(incluyendo saltos de líneas) en los renglones que sean necesarios.

Si el numero de caracteres en el archivo de entrada no es múltiplo de n, el último renglón se "rellena" con el valor de n.

En un arreglo a de longitud n se calcula a[i] = (la suma de los ASCII de cada char en la columna) % 256.

La salida se genera concatenando la representación hexadecimal (mayúsculas) a dos dígitos de cada posición en el arreglo. La longitud de la cadena de salida será de n/4.

Tu programa debe ser llamado <TuMatricula>_2.1.cpp.