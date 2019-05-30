/*******************************************************************************
* File Name: PIN_E.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PIN_E_H) /* Pins PIN_E_H */
#define CY_PINS_PIN_E_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PIN_E_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PIN_E__PORT == 15 && ((PIN_E__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PIN_E_Write(uint8 value);
void    PIN_E_SetDriveMode(uint8 mode);
uint8   PIN_E_ReadDataReg(void);
uint8   PIN_E_Read(void);
void    PIN_E_SetInterruptMode(uint16 position, uint16 mode);
uint8   PIN_E_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PIN_E_SetDriveMode() function.
     *  @{
     */
        #define PIN_E_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PIN_E_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PIN_E_DM_RES_UP          PIN_DM_RES_UP
        #define PIN_E_DM_RES_DWN         PIN_DM_RES_DWN
        #define PIN_E_DM_OD_LO           PIN_DM_OD_LO
        #define PIN_E_DM_OD_HI           PIN_DM_OD_HI
        #define PIN_E_DM_STRONG          PIN_DM_STRONG
        #define PIN_E_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PIN_E_MASK               PIN_E__MASK
#define PIN_E_SHIFT              PIN_E__SHIFT
#define PIN_E_WIDTH              1u

/* Interrupt constants */
#if defined(PIN_E__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PIN_E_SetInterruptMode() function.
     *  @{
     */
        #define PIN_E_INTR_NONE      (uint16)(0x0000u)
        #define PIN_E_INTR_RISING    (uint16)(0x0001u)
        #define PIN_E_INTR_FALLING   (uint16)(0x0002u)
        #define PIN_E_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PIN_E_INTR_MASK      (0x01u) 
#endif /* (PIN_E__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PIN_E_PS                     (* (reg8 *) PIN_E__PS)
/* Data Register */
#define PIN_E_DR                     (* (reg8 *) PIN_E__DR)
/* Port Number */
#define PIN_E_PRT_NUM                (* (reg8 *) PIN_E__PRT) 
/* Connect to Analog Globals */                                                  
#define PIN_E_AG                     (* (reg8 *) PIN_E__AG)                       
/* Analog MUX bux enable */
#define PIN_E_AMUX                   (* (reg8 *) PIN_E__AMUX) 
/* Bidirectional Enable */                                                        
#define PIN_E_BIE                    (* (reg8 *) PIN_E__BIE)
/* Bit-mask for Aliased Register Access */
#define PIN_E_BIT_MASK               (* (reg8 *) PIN_E__BIT_MASK)
/* Bypass Enable */
#define PIN_E_BYP                    (* (reg8 *) PIN_E__BYP)
/* Port wide control signals */                                                   
#define PIN_E_CTL                    (* (reg8 *) PIN_E__CTL)
/* Drive Modes */
#define PIN_E_DM0                    (* (reg8 *) PIN_E__DM0) 
#define PIN_E_DM1                    (* (reg8 *) PIN_E__DM1)
#define PIN_E_DM2                    (* (reg8 *) PIN_E__DM2) 
/* Input Buffer Disable Override */
#define PIN_E_INP_DIS                (* (reg8 *) PIN_E__INP_DIS)
/* LCD Common or Segment Drive */
#define PIN_E_LCD_COM_SEG            (* (reg8 *) PIN_E__LCD_COM_SEG)
/* Enable Segment LCD */
#define PIN_E_LCD_EN                 (* (reg8 *) PIN_E__LCD_EN)
/* Slew Rate Control */
#define PIN_E_SLW                    (* (reg8 *) PIN_E__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PIN_E_PRTDSI__CAPS_SEL       (* (reg8 *) PIN_E__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PIN_E_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PIN_E__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PIN_E_PRTDSI__OE_SEL0        (* (reg8 *) PIN_E__PRTDSI__OE_SEL0) 
#define PIN_E_PRTDSI__OE_SEL1        (* (reg8 *) PIN_E__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PIN_E_PRTDSI__OUT_SEL0       (* (reg8 *) PIN_E__PRTDSI__OUT_SEL0) 
#define PIN_E_PRTDSI__OUT_SEL1       (* (reg8 *) PIN_E__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PIN_E_PRTDSI__SYNC_OUT       (* (reg8 *) PIN_E__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PIN_E__SIO_CFG)
    #define PIN_E_SIO_HYST_EN        (* (reg8 *) PIN_E__SIO_HYST_EN)
    #define PIN_E_SIO_REG_HIFREQ     (* (reg8 *) PIN_E__SIO_REG_HIFREQ)
    #define PIN_E_SIO_CFG            (* (reg8 *) PIN_E__SIO_CFG)
    #define PIN_E_SIO_DIFF           (* (reg8 *) PIN_E__SIO_DIFF)
#endif /* (PIN_E__SIO_CFG) */

/* Interrupt Registers */
#if defined(PIN_E__INTSTAT)
    #define PIN_E_INTSTAT            (* (reg8 *) PIN_E__INTSTAT)
    #define PIN_E_SNAP               (* (reg8 *) PIN_E__SNAP)
    
	#define PIN_E_0_INTTYPE_REG 		(* (reg8 *) PIN_E__0__INTTYPE)
#endif /* (PIN_E__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PIN_E_H */


/* [] END OF FILE */
