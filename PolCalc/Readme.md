# Calculadora Polaca — Léxico

## Punto 6. Preguntas y Respuestas
## a. ¿Es necesario modificar StackModule.h? ¿Por qué?
Si se desea cambiar el tipo de dato para StackItem, se debe modificar el StackOfDoublesModule.h; para que tanto Calculator.c(cliente) como el StackOfDouble.c(proveedor) se enteren del cambio.
## b. ¿Es necesario recompilar la implementación de Stack? ¿Por qué?
 Solo es necesario si se cambio la interfaz (.h) o la implementacion del modulo Stack. Ya que recompilar la solucion daria el mismo archivo objeto.
## c. ¿Es necesario que Calculator muestre el lexema que originó el error léxico? Justifique su decisión.
No es necesario, solo si se desea saber cual de todos los lexemas leidos fue el que origino el error léxico
## i. Si decide hacerlo, ¿de qué forma debería exponerse el lexema?
### Algunas opciones:
- Tercer componente lexeme en Token¿De qué tipo de dato es
aplicable?
- Cambiar el tipo de val para que sea un union que pueda
representar el valor para Number y valor LexError.

Si decidimos mostrar el lexema que origino el error lexico y nos basamos en la primera opcion, una de las maneras de exponer el lexema es guardarlo en una variable que podemos definir dentro del struct Token, la misma podria ser de tipo char o int. Luego, en la implementacion si el caracter no es un digito ni ninguno de los operandos definidos entonces nos guardamos ese lexema en la variable 'lexeme' para luego imprimirla desde el main.


# BNF Para Notacion Polaca Inversa(NPI)

- ::=  -->  'is defined as'
- |    -->  'or'
- <>   -->  category names

#### < expresion> ::= < numeros> < operadores> | < expresion> < numeros> < operadores>
#### < numeros> ::= < flotante> | < entero>
#### < operadores> ::= < operador>+
#### < operador> ::= '+' | '-' | '*' | '/'
#### < flotante> ::= < digito>+ '.' < digito>+
#### < entero> ::= < digito>+
#### < digito> ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

