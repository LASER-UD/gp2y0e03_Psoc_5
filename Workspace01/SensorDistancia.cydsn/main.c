#include "project.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "GP2Y0E03.h"


char buffer[12]={};
volatile char dato;
char distance_cm=0;

CY_ISR(InterrupRx){
    dato=UART_GetChar();//recibe el dato del bluetooth
    switch (dato){
        case '5':{            
            break;
        }
        
        case '6':
        {   
            
            break;
        }
        default:
        {
            break;
        }
    }
}



int main(void)
{
    /*Instancia lo modulos */
    CyGlobalIntEnable; /* Enable global interrupts. */
    /*Inicia los Modulos */
    UART_Start(); 
    I2C_Start();
    VDAC8_Start();
    VDAC8_SetValue(0);
    IRQRX_StartEx(InterrupRx);
    UART_PutString("Iniciando\r\n");
    DS_init();//Inicia sensor de distancia
    sprintf(buffer,"%d\n\r",DS_get_data());//lo codifica en ascci
    UART_PutString(buffer);
    DS_range(0x80);//pone en 128 cm max    
    CyDelay(8000);
    UART_PutString("Iniciando Cambio de Direccion\r\n");
    Ds_change(0x00);//cambia direccion a la 0x10
    UART_PutString("Termino\r\n");
    
    for(;;)
    {
    // velocidad de sensado
        
    }
}

/* [] END OF FILE */
