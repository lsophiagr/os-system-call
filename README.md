# OS-P1
Proyecto System Call para la clase de Sistemas Operativos

## Problema a desarrollar: 
1. Desarrollar una función que determine si una expresión aritmética se encuentra correctamente
cerrada. La función deberá retornar verdadero si la expresión está correctamente cerrada y falso de lo
contrario. Entiéndase por cerrada al hecho de que cada símbolo de paréntesis y/o corchete abierto debe tener
su correspondiente cierre. Ejemplo (5+5), [(1+1)*(2+2)], (((([1]))))

2. Dicha función debe de estar implementada en un system call que deberá recibir como parámetro un
puntero a la cadena que contiene la expresión

3. El estudiante debe utilizar C++ y el kernel de Linux para agregar el system call

4. Deberá compilar el kernel de sistema operativo para agregar la system call personalizada

5. Deberá de crear un programa que reciba como entrada en línea de comando la cadena a utilizar y
hacer uso de la system call implementada en el sistema operativo. 
