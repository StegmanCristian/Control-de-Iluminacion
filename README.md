# TP MAQUINAS DE ESTADO - INFORMATICA II - 2º15

### Profesores
- Prof. Viard, Gustavo
- JTP. Corbalan, Damian

### Alumno 
- Stegman Cristian

## GENERAL
 
### Diagrama de Estados y Transiciones

![alt text](https://github.com/StegmanCristian/Control-de-Iluminacion/blob/master/recursos/diagrama%20de%20%20estados%20y%20transiciones%20.jpeg)

### Descripcion del funcionamiento
El proyecto consiste en un sistema de iluminacion automatico que adapte la intencidad de luz de acuerdo con la luz ambiente.
El sistema posee:
- Un sensor de luz 
- Un dimmer

##### Funcionamiento
Los principios de funcionamiento del sistema son, en definitiva, los descriptos en el diagrama de estados y transiciones, en el cual se observa claramente las condiciones de cambio de estado.
Se determinar un valor de intensidad (i_set) a partir del cual la luz pasara de estar apagada a estar encendida, con un margen determinado (delta_i) que no permita que pequeñas fluctuaciones captadas por el sensor generen multiples cambios de estado.
 
