# P9-Patrones
##### Fecha:19/01/23
##### Autor: Ana Martínez Albendea
##### Objetivo: El objetivo de este fichero es dar a conocer la información básica a cerca del ejercicio que compone la práctica 9 de la asignatura de Diseño Software.
##### Particularidades: El diagrama de calses diseñado inicialmente antes de coenzar a implementar el sistema, se ha ido modificando según se iba desarrollando el sistema a corde a las necesidades del código. Al tratar de implementar el código de la p4 utilizando set del stl, se tuvo que adaptar el código y sobrecargar el < debido a que el set realiza la comparación así en lugar de con ==. Además, para poder insertar o borrar objetos del set se ha de hacer fuera del bucle que lo recorre para que no se rompa el programa debido a un error de segmentación. Para implementar alguna excepción se tuvo que adaptar el código en su momento sólo para poder utilizarla. Para poder tener usuarios inicialmente, se añadieron, con las partes de código que ahora estan comentadas, la creación del fichero y los usuarios predefinidos del set. Además, el código de lectura estaba comentado para esta primera situación.

## 0.Introducción

El objetivo de esta última práctica es implementar alguno de los patrones de diseño que conocemos en nuestra interfaz en función de lo que necesitemos.

## 1.Resumen del ejercicio

Los códigos caracterśiticos de esta prácticas serían los correspondientes a el patrón de diseño elegido. En mi caso he empleado un patrón __singleton__ para la clase Dashboard, ya que solo quiero que se cree una vez y que por lo tanto solo haya una instancia de esta. Además también evita que se clone o asigne consiguiendo lo anterior, asi como utilizando directamente el constructor o __new__ para crear otra instancia.

Fragmentos de código correspondientes al patrón __singleton__:

* Dashboard.h:
```C++
	public:
  static Dashboard* getDashboard();	//creates a Dashboard object in case no instance of it exists yet
	
	// singletons shoul not be cloneable or assignable:
	Dashboard (Dashboard &otherDashboard) = delete;
  void operator= (const Dashboard&) = delete;

	protected:
  Dashboard();// it will be called by getDashboard()

	private:
	static Dashboard* singleDashboard; // pointer to the single instance
```

* Dashboard.cpp:
```C++
	Dashboard* Dashboard::singleDashboard = nullptr;

	Dashboard* Dashboard::getDashboard(){
		if(singleDashboard == nullptr){
		  singleDashboard = new Dashboard();
		}else{
		  cout << "Error: trying to get another instance of a Ball singleton class!\n";
		}
  
  	return singleDashboard;
	}
```

* main.cpp:
```C++
    Dashboard* Ds = Dashboard::getDashboard();
```

## Descripción final del sistema
A lo largo de la asignatura hemos ido implementando diferentes métodos o requisitos a nuestro sistema para hacerlo lo más realista y funcioanl posible. Por ello, si vemos el código final veremos como se ha echo uso de las siguientes cosas y su por qué:

* **Herencia y polimorfismo**: ambos téminos van ligados y son básicos para una programación base del sistema. La herencia nos premite reutilizar el software ya que se crean clases nuevas que heredan datos y comportamientos de una clase padre; además de poder añadir los suyos propios o modificar sobre estos. El polimorfismo permite programar en general en lugar de específicamente y, procesar obj. de clases que formen parte de una jerarquía como si todos fueran objetos de la clase base de dicha jerarquía. 

	Esto se ve principalmente en la creación de los sensores o las cámaras. Las diferentes clases hijas que hay, según el tipo, heredan de las calses 	  padre y modifican algún método de estos, adaptándolos individualmente sin tener que crealos específicamente para cada uno. Esto en un 		futuro ayuda a reutilizar el código sin necesidad de cambiarlo demasiado.

* **Sobrecarga de operadores y/o flujo**: La sobrecarga nos ayuda a lograr un código más claro que con llamadas a funciones y en algunos casos como es este, debemos utilizarla también ya que la colección __set__ para almacenar los datos del sistema lo requiere con el operador <. El __set__, emplea este operador para comparar y verificar que no haya duplicados en la colección. Por lo tanto se ha de sobrecargar dicho operador, dándole otro uso distinto al común como es el de "menor que".

* **Uso de ficheros**: Los ficheros se emplean para almacenar la información necesaria del sistema de manera permanente en el disco en lugar de en la RAM. Con esto se evita que los datos sean temporales y que si se modifican se mantega el cambio después de cerrar nuestro sistema y al volver a iniciarlo. En este caso, lo empleo para almacenar los datos de los usuarios del sistema.

* **Manejo de excepxiones**: Una excepxión indica un problema dado durante la ejecución del sistema el cual ocurre con poca frecuencia. Estas nos permiten crear rutinas para resolverlo o continuar con la ejecución del sistema si se quiere. Además, al indicarnos el problema sabríamos en cierto modo como solucionarlo o por donde buscarlo.

* **Depuración con GDB**: Nos ayuda a encontrar los errores lógicos de nuestro sistema o __bugs__. Además, con el uso de diveros comandos podemos seguir el flujo de nuestro sistema paso a paso y analizarlo detenidamente para así dar con el problema y tenerlo localizado en nuestro código. Esto es algo que ha sido muy útil a la hora de correr el sistema y ver que no realizaba lo que queríamos o se modificaban cosas en ciertos puntos sin darnos cuenta haciendo que no funcionara adecuadamente.

* **Documentación Doxygen y UML**: Esto nos ayuda a tener todo lo relativo a nuestro programa documentado. El Doxygen genera de manera automática la documentación a partir de los códigos del programa y crea un pdf con LATEX y una dirección html a la documentación. El UML es el diagrama de clases del sistema en el que se puedem ver tanto las herencias como el uso de clases entre si, además de todos sus atributos y métodos sin desarrollar.

![DiagramaDeClases_JulioVeganosEHijos](https://user-images.githubusercontent.com/92941166/213264232-7c7ce2de-e87d-40a6-b40a-b96380773aa0.jpg)

### Uso del sistema

### Compilación del sistema
Para compilar el sistema antes de poder utilizarlo, debemos irnos en el terminal a la carpeta donde se encuntra el sistema (en este caso ../p9-patrones-ana-martinezal2021). Una vez aquí debemos introducir el siguiente comando: __$make && ./build/main__ . De esta manera se compilará el programa y se ejecutará. En caso de querer solo compilarlo, __$make__, y si es solo ejecutarlo, __$./build/main/__ .

### Funcionamineto
Como se explicó en un principio este sistema simula una interfaz para una empresa que desea poder controlar todos los sensores y cámaras y tener recogidos los datos de los empleados además de poderlos añadir o eliminar. Por lo tanto su funcionamiento es el siguiente:

Al iniciar el programa se mostrará en pantalla la "ventana" de login para iniciar sesión en el sistema. Nos va a pedir un usuario y una contraseña, ambos estrictamente numéricos, para poder entrar. El número de usuario y la contraseña se verificarán con los datos de los usuarios del sistema q están en nuestro fichero binario y en caso de ser corrector, pasará al menu principal del sistema.

Una vez hemos entrado, se nos muestra un menú principal con las diferentes opciones a realizar. Dependiendo de si el uaurio está guardado en la base de datos como administrador o empleado se mostrarán unas opciones u otras. En caso de ser empleado se mostraran las opciones para cada sensor (Temperatura, Humedad, Nivel de luz y Condición del aire), las cámaras (RGB y Térmica), Micrófono (para dar ordenes), cerrar sesión (vuelve a la ventana de login) y salir del programa. En caso de ser un administrador se le añadirá la opción de gestionar los usuarios del sistema. 

Para entrar en estas opciones se ha de introducir por teclado el número de la opción deseada. Cuando introducimos el número se nos abre el menú personalizado de esa opción donde veremos las diferentes opciones de nuevo pero para la opción elegida. De nuevo introduciendo el núemro de la opción se mostrará por pantalla lo indicado y tendremos la opción de volver al menú principal.

Las opciones según la opción principal elegida son:

* **Sensores**: Encender, apagar y ver la temperatura actual (generada de manera aleatoria).
* **Cámaras**: Encender, apagar y ver la imagen actual (simulación).
* **Micrófono**: Encender, apagar y dar un comando por voz (simulación).

En caso de ser administrador:

* **Gestión de usuarios**: Añadir usuario, eliminar usuario y ver lista de usuarios.

Cuando entramos en el sistema como administrador y elegimos la opción de gestionar los usuarios, dependiendo de la opción elegida nos pedirá lo siguiente:
* **Añadir usuario**: deberemos introducir un número de usuario (0-5 dígitos), contraseña (8 dígitos), nombre de usuario (sin números) y el tipo de usuario(empleado(0) y administrador(1)). De esta manera se añade un nuevo usuario a la base de datos con estas características.
* **Borrar usuario**: deberemos introducir el número del usuario que queremos eliminar. Como es lógico, debe ser el núemro de un usuario que se encuentre dentro de la base de datos. De esta manera estaremos eliminando el usuario de la base de datos definitivamente.
* **Ver la lista de usuarios**: esta opción de nos pedirá nada, sino que nos mostrará los usuarios con su número, nombre y tipo.

Por último, al escoger la opción de salir del sistema en el menú principal, todos los datos del set compuestos por los usuarios se guardarán automáticamente en el archivo binario mencionado al incio. Esto nos permite conservar los cambios de usuarios, en caso de haberlos, de manera permanente para la próxima vez que se utilice el sistema. 

### Datos de los usuarios
Los datos de los usuarios que se encuentran actualmente en el archivo y que son necearios para poder entrar inicialmente son:

**Nº**/	**Nombre**/	**Tipo**/ 			**Contraseña**

  1   /  Ana	   /     Admin	   /       13172409

  2   /  Paula   /    Employee    /    13172408
 
  3	  /  Carlos   /   Employee    /    12345678

  4   /  Pablo    /   Employee    /    11223344

## Documentación
Para poder visualizar la documentación del sistema, tenemos el UML en la carpeta __../doc/uml__, donde se encuntra la imagen JPG del diagrama de clases y el archivo .uxf para abrirlo en UMLet. Por otro lado dentro de la carpeta __../doc__ están las carpetas __../doc/doxygen-doc/hmtl__ y __../doc/doxygen-doc/latex/__ . Si queremos ver la documentación en la página de firefox debemos meternos en la carpeta de html e introducir el siguiente comando: __$firefox index.html__ .
Para ver el pdf de LATEX debemos meterlos en la carpeta de latex e introducir el siguiente comando: __$make && evince refman.pdf__ .

