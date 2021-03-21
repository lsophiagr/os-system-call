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

- Paso 4: Cambiar de Path para poder descargar el nuevo Kernel.


 Adquirir el nuevo kernel con WGET
            **cd /usr/src**
            **wget https://www.kernel.org/pub/linux/kernel/v4.x/linux-4.17.4.tar.xz**
            Intenta cambiar a un Kernel de una versión superior para que así cuándo reinicies el sistema el Kernel sea actualizado.

- Paso 5: Vamos a extraer el .tar que acabamos de descargar.


 En la misma carpeta donde se encuentra tu nuevo kernel comprimido ejecuta el siguiente comando:
            **tar -xvf linux-4.17.4.tar.xz**
            Luego que el sistema termine de descomprimir los archivos procederemos a ingresar dentro de nuestro nuevo kernel
            **cd linux-4.17.4**

- Paso 6: Definir una nueva system call. 


En este caso estaremos agregando múltiples funciones. Creamos un directorio que contendra estas funciones en un solo archivo.


 **mkdir proyecto**
            **cd proyecto**
            Creamos el archivo **touch my_syscall.c** y lo editamos (Puede usar tu editor favorito nano, vim, gedit u otro) **gedit my_syscall.c**
            Toma de referencia el codigo que encuentras [Aquí](/Systems_Calls_C/C/my_syscall.c)\n
            Creamos el archivo Makefile de la misma manera como my_syscall.c sin extension. Este debe contener obj-y := my_syscall.o

- Paso 7: Agregar la carpeta proyecto a el Makefile de Linux 4.17.4.


**gedit Makefile** Busca por el *core-y += kernel/ mm/ fs/ ipc/ security/ crypto/ block/*
            Al final de esta linea agrega la carpeta de proyecto/ debes dejer un espacio entre *block/* y tu nueva carpeta.

- Paso 8: Agregar tu nueva system call a la tabla, en este ejemplo te mostraremos como hacerlo para 64 bits.


**cd arch/x86/entry/syscalls/**
            **gedit syscall_64.tbl**
            Agrega la system call dentro de 332 en adelante. A continuacion te damos un ejemplo de la imagen como se debe ver la tabla.
![Syscall_Table](https://github.com/lsophiagr/OS-P1/blob/main/src_Images/Screenshot%20(769).png)

- Paso 9: Agrega el system call al archivo de headers.


**cd include/linux/**
            **gedit syscalls.h**
            Agrega la siguiente linea hasta la ultima linea del archivo justo antes del #endif
            **asmlinkage long sys_hello(void);**

- Paso 10: Instalar las siguiente librerias para compilar.


Corre los siguientes comandos para preparte para compilar tu nuevo kernel.
            **sudo apt-get install gcc**
            **sudo apt-get install libncurses5-dev**
            **sudo apt-get install bison**
            **sudo apt-get install flex**
            **sudo apt-get install libssl-dev**
            **sudo apt-get install libelf-dev**
            **sudo apt-get install make**
            **sudo apt-get update**
            **sudo apt-get upgrade**

- Paso 11: Configura tu Kernel.


En el path **linux-4.17.4** crea tu archivo de configuracion antes de compilar. Esto puedes crearlo corriendo el siguiente comando: **sudo make menuconfig**

- Paso 12: Compila tu Kernel


En el path the **linux-4.17.4** tendras que compilar tu Kernel. Esto puedes lograrlo con **make -jn** la *n* hace referencia a cuantos procesadores cuenta tu maquina virtual, esto hace que el proceso sea *n* veces mas rapido.


El resultado se vera así luego de tu compilación.
![Kernel Compiled](https://github.com/lsophiagr/OS-P1/blob/main/src_Images/Screenshot%20(764).png)
- Paso 13: Instala/ Actualiza tu Kernel.


Corre el siguiente comando **sudo make modules_install install**

Luego de correr el último comando podrás verificar que en tu fyle system de linux (El que actualmente corre) podrás ir a */boot/* y veras que existen nuevos archivos de configuración, mapping, vm linux y otros.


![Kernel new files](https://github.com/lsophiagr/OS-P1/blob/main/src_Images/Screenshot%20(765).png)


Reinicia tu sistema para que actualice a tu nuevo Kernel.
**shutdown -r now**


Podras revisar luego del reboot tu kernel actualizado corriendo con **uname -r** en este comando deberías poder ver tu nuevo Kernel operando.


![Kernel new files](https://github.com/lsophiagr/OS-P1/blob/main/src_Images/Screenshot%20(768).png)


#### Test System Call
Ve al directorio home(~) y crea un archivo para probar tu system call.
Puedes tomar una de las siguientes para poder hacer test a tu system call [Aquí](https://github.com/lsophiagr/OS-P1/tree/main/Test_System_Calls_C)


Compila y corre el programa
**gcc [filename]**
**./a.out**


![Kernel ](https://github.com/lsophiagr/OS-P1/blob/main/src_Images/out.jpg)


Puedes revisar el mensaje que provee el kernel con **dmesg** esto dara el output de tu system call al final del output del Kernel.


![Kernel ](https://github.com/lsophiagr/OS-P1/blob/main/src_Images/kernel_out.jpg)


# Conclusiones
Decidimos crear conclusiones para los lectores para que se encuentren preparados para enfrentar un problema como este. Te compartimos nuestras conclusiones así también como recomendaciones para afrontar el proyecto.

- Leer es clave. Busca toda la información que puedas antes de comenzar una linea de código. Necesitas entender temas como que es un system call, como opera un system call y que lo hace diferente.

- Prueba y error es el camino al éxito. No importa si en algún paso te da error, lo mejor que puedes hacer sobre los errores es aprender de ellos, te informas de mejor manera sobre como funciona el sistema operativo y entiendes mejor conceptualmente.

- Verifica tus cambios. Siempre que agregues un cambio a un archivo verifica que el cambio sea aplicado y más importante aún que la syntaxis este bien. 


Esperemos te haya servido nuestra documentación para resolver un system call.