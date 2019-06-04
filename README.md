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
#include <stdbool.h>
#include "GP2Y0E03.h"
#define GP2Y0Ed          0x40//default

char buffer2[12]={};


int main(void)
{
    /*Instancia lo modulos */
    CyGlobalIntEnable; /* Enable global interrupts. */
    /*Inicia los Modulos */
    UART_Start(); 
    IRQRX_StartEx(InterrupRx);
    UART_PutString("Iniciando\r\n");
    DS_init(GP2Y0Ed);//Inicia sensor de distancia
    
    
    for(;;)
    {
    sprintf(buffer2,"Distancia 1: %d\n\r",DS_get_data(GP2Y0Ed));
	UART_PutString(buffer2);
	CyDelay(1000);
        
    }
}
```

## Cambiar la direccion de esclavo del sensor

```
#include "project.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "GP2Y0E03.h"
#define GP2Y0Ed          0x40//default

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    /*Inicia los Modulos */
    UART_Start(); 
    UART_PutString("Iniciando\r\n");
    DS_init(GP2Y0Ed);//Inicia sensor de distancia
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
#define GP2Y0Ed          0x40//default


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    /*Inicia los Modulos */
    UART_Start(); 
    UART_PutString("Iniciando\r\n");
    DS_init();//Inicia sensor de distancia
    UART_PutString("Iniciando Cambio de Direccion\r\n");
    DS_range(GP2Y0Ed,0x80);//pone en 128 cm y cualquier otro parametro diferente de 0x80 la deja de 64 cm
    UART_PutString("Termino\r\n");    
    for(;;)
    {
    }
}

```
## Usar dos sensores en paralelo

```
#include "project.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "GP2Y0E03.h"
#define GP2Y0Ed          0x40//default

char buffer2[12]={};


int main(void)
{
    /*Instancia lo modulos */
    CyGlobalIntEnable; /* Enable global interrupts. */
    /*Inicia los Modulos */
    UART_Start(); 
    IRQRX_StartEx(InterrupRx);
    UART_PutString("Iniciando\r\n");
    DS_init(GP2Y0Ed);//Inicia sensor de distancia
    DS_init(0x60);
    
    
    for(;;)
    {
    sprintf(buffer2,"Distancia 1: %d\n\r",DS_get_data(GP2Y0Ed));
	UART_PutString(buffer2);
	CyDelay(1000);
    
    sprintf(buffer2,"Distancia 2: %d\n\r",DS_get_data(0x60));
	UART_PutString(buffer2);
    CyDelay(1000);
    // velocidad de sensado
        
    }
}

```
