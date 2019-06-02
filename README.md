# GP2Y0E03 en Psoc 5 LP
En este repositorio contiene la libreria para el manejo del sensor de distancia GP2Y0E03, entre sus cualidades se encuentra la alta presición para obtener la distancia a objetos no lisos, tiene la posibilidad de cambiar su rango maximo y dirección de esclavo con el fin de manejar mas de uno. La liberia contiene las rutinas para leer su distancia,cambiar la dirección de esclavo del sensor y cambiar la distancia maxima.

La visualizacion de información se debe realizar con una consola serial, para esto se necesita tener conectado el puerto tx y rx al los pines 12.7 y 12.6 del programador del Psoc, el cual debe estar despegado del su programador.
## Compónentes usados 
* I2C
* Serial, para la visualización de informacion
* DAC, para pin de cambio de direccion a 3.3 V

## Lectura del sensor con direccion predeterminada 
```
#include "project.h"
#include <string.h>
#include <stdio.h>
#include "GP2Y0E03.h"

char buffer[12]={};


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    /*Inicia los Modulos */
    UART_Start(); 
    I2C_Start();
    UART_PutString("Iniciando\r\n");
    DS_init();//Inicia sensor de distancia    
    for(;;)
    {
	sprintf(buffer,"Distancia: %d\n\r",DS_get_data());
	UART_PutString(buffer);
	CyDelay(1000);
    // velocidad de sensado
        
    }
}
```

## Cambiar la direccion de esclavo del sensor

```
#include "project.h"
#include <string.h>
#include <stdio.h>
#include "GP2Y0E03.h"

char buffer[12]={};


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    /*Inicia los Modulos */
    UART_Start(); 
    I2C_Start();
    UART_PutString("Iniciando\r\n");
    DS_init();//Inicia sensor de distancia
    UART_PutString("Iniciando Cambio de Direccion\r\n");
    Ds_change(0x00);//cambia direccion a la 0x10
    UART_PutString("Termino\r\n");    
    for(;;)
    {
    }
}

```
## Cambiar la distancia maxima

```
#include "project.h"
#include <string.h>
#include <stdio.h>
#include "GP2Y0E03.h"

char buffer[12]={};


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    /*Inicia los Modulos */
    UART_Start(); 
    I2C_Start();
    UART_PutString("Iniciando\r\n");
    DS_init();//Inicia sensor de distancia
    UART_PutString("Iniciando Cambio de Direccion\r\n");
    DS_range(0x80);//pone en 128 cm y cualquier otro parametro diferente de 0x80 la deja de 64 cm
    UART_PutString("Termino\r\n");    
    for(;;)
    {
    }
}

```


