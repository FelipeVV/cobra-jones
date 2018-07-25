# Cobra Jones.
Un juego de adivinar.
## Quienes Somos?
Córdoba C. Johan y Vega V. Felipe.
 Estudiantes de Ciencias de la Computación e Informática en la Universidad de Costa Rica.
 Este juego se crea como proyecto de Programación 2 en C++

## Premisa
El juego está inpirado en las historias y películas de aventura, como Indiana Jones. Es un juego de exploración.

## Objetivos del Proyecto
* Diseñar un juego que emita el sentimiento de exploración.
* El juego tratara sobre una exploradora en un templo antiguo. Se encuentra atrapada en una habitacion del templo con mosaicos en el piso.
* La vista del juego es *top down*, osea, vista desde arriba. Como un pajaro:

![](https://i.imgur.com/iCow8ti.jpg)

* No todos los mosaicos son iguales. Existen tres tipos principales de mosaicos que el jugador puede pisar:
	* Normales: No hacen nada en especial.
	* Trampas: Mosaicos que tienen una apariencia vieja y quebrada. Si el jugador los pisa, cae al abismo.
	* Platos: Este tipo de piso tiene un antiguo y valioso artefacto escondido, pero para excabarlo, el jugador debe taladrear el piso.
* Como es una vista desde arriba, la habitacion parecera una cuadricula llena de mosaicos de diferentes tipos.
* Hoy en dia muchos juegos se disenan de esta forma, por ejemplo los nuevos titulos de Zelda. Nosotros queremos que nuestro juego se vea como uno de estos juegos:

![](https://i.imgur.com/awjBYDo.jpg)

(Notese como el piso tiene un patron de cuadrados. Nosotros queremos lograr ese efecto.)
* Los niveles se cargarán de varios archivos de texto.
* Cada archivo de texto contiene:
	* Las dimennsiones de la habitacion
	* El tipo de mosaicos que contendrá la habitacion(representado con caracteres).
* A continuacion un ejemplo de un archivo de texto:

```
16 16
-----------------
#--#---#-#-------
----------#------
-------O---------
---#-------------
---O-#--O--#-----
---#-------------
#--#----------#-#
--------------#--
-#-----------#---
-----------------
--#--#---#-------
#-------#-----##-
-----------------
--#-------#######
----------#######
```
* El juego es capaz de leer esta matriz, interpretarla y crear un nivel donde cada caracter representa un tipo de piso diferente:
![](https://i.imgur.com/x3pDcdA.png)

(En esta imagen se puede ver al jugador en el medio de la pantalla. Representado por un dibujo de una exploradora)
* El jugador es capaz de moverse al rededor de la cuadricula de mosaicos con un avatar, que sera un personaje en la pantalla.

## Objetivo del juego ##
* El jugador es una exploradora que desea encontrar un artefacto antiguo que le traera buena suerte y fortuna.
* El tesoro se encuentra en el mosaico mas alejado de los mosaicos quebrados(trampas).
* El jugador debe usar la intuicion y calcular donde puede ser el mosaico en el que se esconde el tesoro.
* El jugador se debe basar en los mosaicos quebrados y suponer el lugar mas alejado de los mosaicos quebrados.
* El jugador puede caminar alrededor del nivel y colocarse sobre el mosaico enn que crea que esta el tesoro.
* Una vez parado encima del mosaico, el jugador puede presionar una tecla para taladrar el piso y ver si adivino correctamente.

## Juego ##

![](https://i.imgur.com/eyvOikF.png)

* Al iniciar la aplicacion, el jugador vera un menu de inicio mostrando 3 espacios principales:
1. Nombre: El jugador puede elegir su nombre si desea. Por defecto se llama Selena, como la protagonista.
2. Nuevo juego: Empieza a jugar desde el nivel uno.
3. Seleccionar nivel: El jugador puede irse al nivel que desea.

## Controles ##
* El jugador puede manejar al avatar del juego con las flechas del teclado.

![](https://i.imgur.com/j0VfwaI.jpg)

* Con esto el jugador se puede mover arriba, abajo, izquierda y derecha.
* Taladro: Con espacio el jugador puede ver si abajo de su mosaico se encuentra el artefacto perdido.
* Volver al menu de incio: Presione P.


## Primer Entregable

1. El jugador es capaz de moverse en el mapa

2. programa debe cargar los niveles de forma correcta, añadiendo según el archivo de texto de la entrada las texturas correspondientes a cada elemento.

3. El jugador tiene un boton diseñado para "taladrar" el suelo.

## Segundo Entregable

1. Si acierta una moneda se hace gigante y llena el campo de visión del jugador y se muestra su score.

2. Si falla un rectángulo se hace gigante y de igual forma llena el campo de visión pero esta vez se muestran las opciones de repetir o salir.

3. Hay más de un nivel

4. El jugador es capaz de seleccionar niveles en un tipo de menu