# OS-P1  👩‍💻🧑🏻‍💻
Proyecto System Call para la clase de Sistemas Operativos

## Problema a desarrollar: 🤖
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

## Entregable 👓
- URL al repositorio donde implementó la función por medio de un system call y el programa que
hace uso de la función

- Documentación con el diagrama conceptual que explique todos los pasos necesarios que el
sistema operativo tiene que realizar para que el proceso de usuario pueda utilizar la system call. 

# Desarrollo del proyecto
A continuación tendremos los pasos detallados para que puedas implementar el proyecto de agregar un system call a tu Linux de Kernel.

#### Introducción
El proyecto System Call consta de desarrollar una función que determine si una expresión aritmética se encuentra correctamente cerrada o no. Esta función debe retornar verdadero si la expresión está correctamente cerrada o falso de lo contrario. Como parte de la clase de sistemas operativos es necesario que esta función se encuentre implementada en un system call con el objetivo de comprender cómo opera este y utilizar los recursos del kernel para resolver el problema del user.

Un system call es un mecanismo que provee una interfaz entre un proceso y el sistema operativo. Es un método programático en donde un programa de computadora solicita un servicio del Kernel del sistema operativo. Un system call ofrece los servicios del sistema operativo para que puedan ser utilizados por el usuario, es importante mencionar que un system call son únicamente el punto de entrada para el Kernel del sistema.
