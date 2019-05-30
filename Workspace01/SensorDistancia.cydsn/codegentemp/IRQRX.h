/*******************************************************************************
* File Name: IRQRX.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_IRQRX_H)
#define CY_ISR_IRQRX_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void IRQRX_Start(void);
void IRQRX_StartEx(cyisraddress address);
void IRQRX_Stop(void);

CY_ISR_PROTO(IRQRX_Interrupt);

void IRQRX_SetVector(cyisraddress address);
cyisraddress IRQRX_GetVector(void);

void IRQRX_SetPriority(uint8 priority);
uint8 IRQRX_GetPriority(void);

void IRQRX_Enable(void);
uint8 IRQRX_GetState(void);
void IRQRX_Disable(void);

void IRQRX_SetPending(void);
void IRQRX_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the IRQRX ISR. */
#define IRQRX_INTC_VECTOR            ((reg32 *) IRQRX__INTC_VECT)

/* Address of the IRQRX ISR priority. */
#define IRQRX_INTC_PRIOR             ((reg8 *) IRQRX__INTC_PRIOR_REG)

/* Priority of the IRQRX interrupt. */
#define IRQRX_INTC_PRIOR_NUMBER      IRQRX__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable IRQRX interrupt. */
#define IRQRX_INTC_SET_EN            ((reg32 *) IRQRX__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the IRQRX interrupt. */
#define IRQRX_INTC_CLR_EN            ((reg32 *) IRQRX__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the IRQRX interrupt state to pending. */
#define IRQRX_INTC_SET_PD            ((reg32 *) IRQRX__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the IRQRX interrupt. */
#define IRQRX_INTC_CLR_PD            ((reg32 *) IRQRX__INTC_CLR_PD_REG)


#endif /* CY_ISR_IRQRX_H */


/* [] END OF FILE */
