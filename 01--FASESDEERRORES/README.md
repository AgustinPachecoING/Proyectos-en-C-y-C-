# TP1 Fases de la traduccion y errores
## Secuencia de Pasos
## 1.a) Escribimos hello2.c
~~~
#include <stdio.h>
int/*medio*/main(void){
int i=42;
 prontf("La respuesta es %d\n");
~~~

## 1.b) Generamos el archivo de preprocesado 
mediante el comando
~~~
gcc -E hello2.c -o hello2.i
~~~
Observamos que en esta etapa del proceso de traduccion,  no se detectan errores de compilacion y se realizan algunas acciones como:
* Se Reemplazan los comentarios por un espacio.
* Se expanden (copia, pega y resuelve) recursivamente los archivos referenciados (#include).
* Nos ahorra el trabajo de declarar las funciones incluidas en la biblioteca estandar( en este caso printf).
* Particularmente para esta implementacion( GCC) agrega algunos logs al preprocesado. Pero esto depende de cada implementacion.

## 1.c) Escribimos hello3.c
~~~
int printf(const char * restrict s, ...);
int main(void){
int i=42;
 prontf("La respuesta es %d\n");
~~~

## 1.d) Semantica de int printf(const char * restrict s, ...);
La primera linea es la declaracion de la funcion printf que retorna un int y que recibe un primer parametro de tipo puntero constante a char y con la palabra clave restrict le decimos al compilador que solo va a poder acceder a esa informacion solamente con el puntero previamente mencionado. Y los puntos suspensivos hace referencia a que la funcion puede tener un numero variable de argumentos , siempre mayores a 1.

## 1.e) Preproceso del archivo de hello3.c 
con el comando
~~~ 
gcc -E hello3.c -o hello2.i
~~~
el cual nos genero el archivo hello3.i. Las diferencias entre hello3.c y el .i son:
* La unica diferencia entre ambos archivos , es que en el hello3.i , nuestra implementacion (GCC) agrega los siguientes logs:
~~~
 0 "hello3.c"
 0 "<built-in>"
 0 "<command-line>"
 1 "hello3.c"
 ~~~
 
## 2.a) Generamos Hello3.s 
con el comando
~~~
gcc -S Hello3.c
~~~
## 2.b) Correccion del error
Para corregir el error tuvimos que sumar '}' para cerrar la función main. Generamos el archivo Hello4.c con dicha corrección y el Hello4.s con el comando
~~~
gcc -S Hello4.c
~~~
## 2.c) El objetivo del lenguaje ensamblador
El objetivo del legunaje ensamblador es proporcionar una representación de bajo nivel de los comandos y las instrucciones de una arquitectura de computadora específica. Se utiliza para programar directamente el hardware, escribiendo instrucciones en lenguaje ensamblador que luego se traducen en código de máquina comprensible por la CPU.
## 2.d) Ensamblamos hello4.s
Con el comando 
~~~
gcc -C Hello4.c -o Hello4.o
~~~ 
ensamblamos hello4.c

## 3.a) Vinculacion
 Con el comando 
 ~~~
 gcc -o Hello4.c
 ~~~
 intentamos vincular el archivo, y obtuvimos un error, ya que no encuentra **prontf** en la biblioteca estandar.
## 3.b) Correccion en hello5.c
 Corregimos la llamada a la función prontf por la llamada a la función printf, que sí esta declarada en la biblioteca estandar. El mismo comando anterior nos generó el archivo ejecutable.
## 3.c) Analisis de la ejecucion de hello5.c
 Al ejecutar Hello5.c nos encontramos con un bug, dado que el resultado no es el esperado (La respuesta es 4200768, cuando tendría que ser 42). Como no se pasó la variable i, a %d se le asignó un valor random del stack del sistema (en este caso fue el número 4200768 pero puede ser cualquier otro), teniendo un comportamiento indefinido.

## 4.a) Se corrige el bug
en el argumento de la función printf se pasa la variable i para que imprima el valor esperado. 

## 5.a) Generamos hello7.c
~~~
int main(void){
 int i=42;
 printf("La respuesta es %d\n", i);
}
~~~

## 5.b) Explicacion
 El programa vinculó y ejecutó correctamente a pesar de no haber declarado la función printf porque es una función built in, forma parte del estandar de C.
* i) En gcc solo arroja warnings indicando que tenemos una declaración implícita de printf. **Aclaración**: en clang, al intentar ejecutar el progama, el compilador nos arroja errores indicando que la ISO 99 o versiones siguientes no tienen soporte para la declaración implícita de funciones. 
* ii) Un prototipo es una declaración de la función que nos indica su nombre, tipo de retornos y tipo de los parámetros que espera recibir (firma de la función). 
* iii) Es una función utilizada en el código que no fue declarada o prototipada.
* iv) Según la especificación de C99 se requiere que las funciones se declaren explícitamente.
* v) Clang como implementación no permite la declaración implícita de funciones mientras que gcc sí las permite.
* vi) Se refiere a las funciones que están disponibles en el lenguaje sin necesidad de incluir bibliotecas externas. Estas funciones forman parte del estándar del lenguaje y están disponibles para su uso inmediato.
* vii) Segun la especificación de C99 se remueven las declaraciones implicitas de funciones, esto no detalla qué hacer con estas declaraciones ni cómo tratarlas por lo tanto gcc no iría en contra del estandar.
La razon es porque sobre GCC se apoya gran parte de la infraestructura de Unix que a su vez es la base de Linux, si se cambian implementaciones de versionados antiguos, probablemente genere errores grandes a la hora de ejecutar el sistema operativo. Basicamente GCC prefiere maximizar la compatibilidad con versiones anteriores. En cambio, por ejemplo Clang dentro de su filosofía es un compilador más independizado el cual no requiere adaptarse a estos cambios manteniendo la compatibilidad, por lo que prefiere tomar las riendas contra el programador y restringirle la compilacion. 

## 6.a) Generamos studio1.c y hello8.c
~~~
void prontf(const char* s, int i){
 printf("La respuesta es %d\n", i);
}
~~~
~~~
int main(void){
int i=42;
 prontf("La respuesta es %d\n", i);
}
~~~

## 6.b) Para generar un ejecutable debemos: 
crear un archivo de encabezado llamado "studio1.h" que contenga el contrato de interfaz de la función "prontf". En este caso, el archivo "studio1.h" debe contener la siguiente línea:
~~~
void prontf(const char* s, int i);
~~~
Compilamos los archivos fuente ("studio1.c" y "hello8.c") con el comando
~~~
gcc -o programa_ejecutable studio1.c hello8.c
~~~
Esto generará un archivo ejecutable llamado "programa_ejecutable" que se basa en las dos unidades de traducción.
## 6.c) Si agregamos argumentos adicionales en la invocación de "prontf", como por ejemplo:
~~~
prontf("La respuesta es %d\n", i, 10);
~~~
Obtendremos un mensaje de advertencia del compilador indicando que hay un exceso de argumentos en la llamada a la función. Sin embargo, el programa se compilará y ejecutará sin errores. La función "prontf" solo utilizará los argumentos proporcionados en su implementación y no tendrá en cuenta los argumentos adicionales.
Por otro lado, si eliminamos argumentos de la invocación de "prontf", como por ejemplo:
~~~
prontf("La respuesta es\n");
~~~
Obtendrás un mensaje de advertencia del compilador indicando que falta un argumento en la llamada a la función. Además, esto causará un comportamiento indefinido durante la ejecución del programa, ya que la función "prontf" espera recibir un argumento entero para imprimirlo correctamente. En este caso, se imprimirá un valor impredecible o potencialmente incorrecto.

## 6.d)
* i) Escribimos el contrato studio.h
~~~
#ifndef _STUDIO_H_INCULDED_
#define _STUDIO_H_INCULDED_

void prontf(const char*, int);
#endif
~~~

* ii) Escribimos hello9.c, un cliente que incluye el contrato
~~~
#include "studio.h" // Interfaz que importa
int main(void){
int i=42;
 prontf("La respuesta es %d\n", i);
}
~~~

* iii) Escribimos studio2.c, proveedor que incluye el contrato
~~~
#include "studio.h" // Interfaz que exporta
#include <stdio.h> // Interfaz que importa
void prontf(const char* s, int i){
 printf("La respuesta es %d\n", i);
}
~~~

* iv) La ventaja es la inclusión de los prototipos, ya que de esta manera el IDE se puede adelantar a errores incluso antes del momento de compilar. Además, se comprueba de que el cliente esta utilizando las funciones de manera correcta y de que el proveedor obedece con los prototipos del contrato.

<br><br><br><br><br> 

# Credito Extra 

## **Bibliotecas**

### ¿Que son?
Las bibliotecas estáticas son archivos que contienen código objeto compilado y funciones que pueden ser utilizadas por programas. Estas bibliotecas se enlazan directamente con el programa en tiempo de compilación, lo que significa que el código de la biblioteca se copia directamente en el ejecutable final del programa.

### ¿Se pueden distribuir? 
Sí, las bibliotecas estáticas se pueden distribuir junto con el programa que las utiliza. Cuando se distribuye un programa que utiliza bibliotecas estáticas, las bibliotecas se incluyen como parte del ejecutable final, lo que permite que el programa se ejecute de manera independiente sin depender de la presencia de las bibliotecas en el sistema del usuario.
### ¿Son portables?
Las bibliotecas estáticas son portables en el sentido de que se pueden utilizar en diferentes sistemas operativos y arquitecturas si se proporcionan las versiones correctas de la biblioteca para cada plataforma objetivo. Ya que cuando se compila una biblioteca estática, el código objeto se genera para esa arquitectura y sistema operativo específico; por lo que para que una biblioteca estática sea portátil, se deben proporcionar diferentes versiones de la biblioteca para cada combinación de arquitectura y sistema operativo objetivo.

### Ventajas y desventajas
#### Ventajas:
* **Independencia**: El programa y las bibliotecas están empaquetados en un único archivo ejecutable, lo que facilita su distribución y uso en diferentes sistemas sin preocuparse por la instalación de bibliotecas adicionales.
* **Rendimiento**: Al enlazarse directamente con el programa, las bibliotecas estáticas pueden ofrecer un rendimiento ligeramente mejor debido a la eliminación de la sobrecarga del enlace dinámico en tiempo de ejecución.
#### Desventajas:
* **Tamaño del ejecutable**: Debido a que el código de la biblioteca se copia directamente en el ejecutable final, puede aumentar el tamaño del archivo ejecutable, especialmente si se utilizan múltiples bibliotecas estáticas.
* **Actualizaciones**: Si se realiza una actualización en la biblioteca estática, es necesario volver a compilar y enlazar el programa para aplicar los cambios, lo que puede ser inconveniente si el programa se distribuye ampliamente
