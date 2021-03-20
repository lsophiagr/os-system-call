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

#### Contenido
Cuándo nosotros queremos utilizar un servicio del kernel necesitamos usar un system call. Como usuarios nosotros no podemos ejecutar un system call debido a que solo se puede ejecutar en modo Kernel como lo muestra la imagen. Como usuarios no nos percatamos de estos system calls debido a que ya se encuentran dentro del sistema para nuestro uso, cuándo leemos o escribimos a un archivo como usuarios el Kernel ejecuta múltiples System calls para que nosotros podamos utilizar estos servicios en las aplicaciones convencionales.
![Sys_Call_Process](https://www.guru99.com/images/1/121119_0451_SystemCalli3.png)

Veamos como agregamos un system call a nuestro Kernel. A continuación estaremos utilizando un [Ubuntu 16.04.7 LTS](https://releases.ubuntu.com/xenial/) de 64 bits que tiene un Kernel 4.15.0 y estaremos actualizando el Kernel a 4.17.4 que este contendrá nuestro system call.

- Paso 1: Descargar software de VirtualBox y la imagen ISO a montar.
[VirtualBox](https://www.virtualbox.org/wiki/Downloads)
[Ubuntu 16.04.7 LTS](https://releases.ubuntu.com/xenial/)

- Paso 2: Montar la imagen ISO a VirtualBox para tener tu sistema Linux corriendo.

- Paso 3: Confirmar nuestra versión de Kernel con **uname -r** e ingresar con **sudo -s**

- Paso 4: Cambiar de Path para poder descargar el nuevo Kernel. Adquirir el nuevo kernel con WGET
            **cd /usr/src**
            **wget https://www.kernel.org/pub/linux/kernel/v4.x/linux-4.17.4.tar.xz**
            Intenta cambiar a un Kernel de una versión superior para que así cuándo reinicies el sistema el Kernel sea actualizado.

- Paso 5: Vamos a extraer el .tar que acabamos de descargar. En la misma carpeta donde se encuentra tu nuevo kernel comprimido ejecuta el siguiente comando:
            **tar -xvf linux-4.17.4.tar.xz**
            Luego que el sistema termine de descomprimir los archivos procederemos a ingresar dentro de nuestro nuevo kernel
            **cd linux-4.17.4**

- Paso 6: Definir una nueva system call. 


En este caso estaremos agregando múltiples funciones. Creamos un directorio que contendra estas funciones en un solo archivo .c
            **mkdir proyecto**
            **cd proyecto**
            Creamos el archivo **touch my_syscall.c** y lo editamos (Puede usar tu editor favorito nano, vim, gedit u otro) **gedit my_syscall.c**
            Toma de referencia el codigo que encuentras [Aquí](/Systems_Calls_C/C/my_syscall.c)\n
            Creamos el archivo Makefile de la misma manera como my_syscall.c sin extension. Este debe contener obj-y := my_syscall.o

- Paso 7: Agregar la carpeta proyecto a el Makefile de Linux 4.17.4\n
            Deb