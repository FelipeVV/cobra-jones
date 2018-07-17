# cobra-jones
Juego como Indiana Jones que no es Indiana Jones.

## Quienes Somos?
Córdoba C. Johan 

Vega V. Felipe

Estudiantes de Ciencias de la Computación e Informática en la Universidad de Costa Rica.

Este juego se crea como proyecto de Programación 2 en C++

## Premisa
El juego está inpirado en las historias y películas de aventura,  

## Visión
* Diseñar un juego divertido.
* Diseñar un juego que emita el sentimiento de exploración.
* Crear un juego que tome espacio en un grid compuesto de diferentes elementos.
* Crear una aplicación que proyecte una imagen sobre el monitor. 
* Crear un juego con una estética y paleta de color uniforme.

## Mecánicas

## Estética
Por razones de tiempo, el juego se hará en estilo "pixel art". La paleta de color tendrá muchos colores y tonos café y tierra.

![](https://i.imgur.com/ohQxtvh.png)
![](https://i.imgur.com/iXU70Kd.png)

## Jugador
La protagonista del juego se llama Selena "Cobra" Jones. El personaje fue diseñado desde una hoja de diseño escrita hasta ya el dibujo final. El arte final incluye rotaciones y expresiones del personaje.


## Primer Entregable

1. El jugador es capaz de moverse en el mapa

2. programa debe cargar los niveles de forma correcta, añadiendo según el archivo de texto de la entrada las texturas correspondientes a cada elemento.

3. El jugador tiene un boton diseñado para "taladrar" el suelo.
  
## Segundo Entregable

1. Si acierta una moneda se hace gigante y llena el campo de visión del jugador y se muestra su score.

2. Si falla un rectángulo se hace gigante y de igual forma llena el campo de visión pero esta vez se muestran las opciones de repetir o salir. 

3. Hay más de un nivel

4. El jugador es capaz de seleccionar niveles en un tipo de menu


El juego se basa en el problema del primer examen, que trata de un juego de exploración por niveles.

Una matriz contiene dos tipos de caracteres: '-' y '#'

* '#': Las celdas con este caracter representan las casillas ocuras. 

* '-': Este caracter es el "relleno". Los mosaicos sin trampas.

* 'O': Este caracter representa la solucion al nivel, es la celda mas alejada de todas las celdas oscuras.
