#include "project.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "GP2Y0E03.h"
#define GP2Y0Ed          0x40//default

char buffer2[12]={};
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

/* [] END OF FILE */
