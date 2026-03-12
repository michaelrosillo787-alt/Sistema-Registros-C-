# Sistema de Gestión de Empleados

## Descripción

Este proyecto consiste en un sistema de gestión de empleados desarrollado en lenguaje C++. El programa permite administrar información de empleados mediante un menú interactivo en consola.

El sistema permite registrar nuevos empleados, mostrar los registros existentes, buscar empleados por diferentes criterios, modificar información, eliminar registros y generar un reporte general.

El objetivo principal es aplicar conceptos de programación como clases, encapsulamiento y uso de vectores para almacenar información.

## Funcionalidades del sistema

El programa incluye las siguientes opciones:

1. Registrar empleado
2. Mostrar empleados
3. Buscar empleado
4. Modificar empleado
5. Eliminar empleado
6. Generar reporte final
7. Salir del sistema

## Estructura del programa

### Clase Empleado

Esta clase contiene los datos de cada empleado y los métodos necesarios para acceder y modificar la información.

Atributos principales:

* ID
* Nombre
* Departamento
* Cargo
* Salario
* Años de experiencia
* Estado

También incluye métodos para mostrar los datos y modificar la información del empleado.

### Clase GestionEmpleados

Esta clase se encarga de administrar el conjunto de empleados utilizando un vector.
Entre sus funciones principales se encuentran:

* Agregar empleados
* Mostrar la lista de empleados
* Buscar empleados
* Modificar información
* Eliminar registros
* Generar reportes estadísticos

## Tecnologías utilizadas

* Lenguaje de programación: C++
* Programación orientada a objetos
* Uso de vectores de la biblioteca estándar (STL)

Librerías utilizadas en el programa:

* iostream
* vector
* string
* iomanip

## Ejecución del programa

Para compilar el programa se puede utilizar el siguiente comando:

g++ main.cpp -o empleados

Luego se ejecuta con:

./empleados

En sistemas Windows también se puede ejecutar el archivo empleados.exe.

## Conclusión

El desarrollo de este programa permitió aplicar conceptos básicos de programación en C++, como el uso de clases, métodos, vectores y estructuras de control. El sistema cumple con las funciones solicitadas para registrar, consultar, modificar y eliminar información de empleados, además de generar un reporte con estadísticas generales.
