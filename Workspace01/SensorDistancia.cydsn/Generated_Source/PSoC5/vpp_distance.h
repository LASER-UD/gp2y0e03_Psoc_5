/*******************************************************************************
* File Name: vpp_distance.h  
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

#if !defined(CY_PINS_vpp_distance_H) /* Pins vpp_distance_H */
#define CY_PINS_vpp_distance_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "vpp_distance_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 vpp_distance__PORT == 15 && ((vpp_distance__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    vpp_distance_Write(uint8 value);
void    vpp_distance_SetDriveMode(uint8 mode);
uint8   vpp_distance_ReadDataReg(void);
uint8   vpp_distance_Read(void);
void    vpp_distance_SetInterruptMode(uint16 position, uint16 mode);
uint8   vpp_distance_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the vpp_distance_SetDriveMode() function.
     *  @{
     */
        #define vpp_distance_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define vpp_distance_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define vpp_distance_DM_RES_UP          PIN_DM_RES_UP
        #define vpp_distance_DM_RES_DWN         PIN_DM_RES_DWN
        #define vpp_distance_DM_OD_LO           PIN_DM_OD_LO
        #define vpp_distance_DM_OD_HI           PIN_DM_OD_HI
        #define vpp_distance_DM_STRONG          PIN_DM_STRONG
        #define vpp_distance_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define vpp_distance_MASK               vpp_distance__MASK
#define vpp_distance_SHIFT              vpp_distance__SHIFT
#define vpp_distance_WIDTH              1u

/* Interrupt constants */
#if defined(vpp_distance__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in vpp_distance_SetInterruptMode() function.
     *  @{
     */
        #define vpp_distance_INTR_NONE      (uint16)(0x0000u)
        #define vpp_distance_INTR_RISING    (uint16)(0x0001u)
        #define vpp_distance_INTR_FALLING   (uint16)(0x0002u)
        #define vpp_distance_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define vpp_distance_INTR_MASK      (0x01u) 
#endif /* (vpp_distance__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define vpp_distance_PS                     (* (reg8 *) vpp_distance__PS)
/* Data Register */
#define vpp_distance_DR                     (* (reg8 *) vpp_distance__DR)
/* Port Number */
#define vpp_distance_PRT_NUM                (* (reg8 *) vpp_distance__PRT) 
/* Connect to Analog Globals */                                                  
#define vpp_distance_AG                     (* (reg8 *) vpp_distance__AG)                       
/* Analog MUX bux enable */
#define vpp_distance_AMUX                   (* (reg8 *) vpp_distance__AMUX) 
/* Bidirectional Enable */                                                        
#define vpp_distance_BIE                    (* (reg8 *) vpp_distance__BIE)
/* Bit-mask for Aliased Register Access */
#define vpp_distance_BIT_MASK               (* (reg8 *) vpp_distance__BIT_MASK)
/* Bypass Enable */
#define vpp_distance_BYP                    (* (reg8 *) vpp_distance__BYP)
/* Port wide control signals */                                                   
#define vpp_distance_CTL                    (* (reg8 *) vpp_distance__CTL)
/* Drive Modes */
#define vpp_distance_DM0                    (* (reg8 *) vpp_distance__DM0) 
#define vpp_distance_DM1                    (* (reg8 *) vpp_distance__DM1)
#define vpp_distance_DM2                    (* (reg8 *) vpp_distance__DM2) 
/* Input Buffer Disable Override */
#define vpp_distance_INP_DIS                (* (reg8 *) vpp_distance__INP_DIS)
/* LCD Common or Segment Drive */
#define vpp_distance_LCD_COM_SEG            (* (reg8 *) vpp_distance__LCD_COM_SEG)
/* Enable Segment LCD */
#define vpp_distance_LCD_EN                 (* (reg8 *) vpp_distance__LCD_EN)
/* Slew Rate Control */
#define vpp_distance_SLW                    (* (reg8 *) vpp_distance__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define vpp_distance_PRTDSI__CAPS_SEL       (* (reg8 *) vpp_distance__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define vpp_distance_PRTDSI__DBL_SYNC_IN    (* (reg8 *) vpp_distance__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define vpp_distance_PRTDSI__OE_SEL0        (* (reg8 *) vpp_distance__PRTDSI__OE_SEL0) 
#define vpp_distance_PRTDSI__OE_SEL1        (* (reg8 *) vpp_distance__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define vpp_distance_PRTDSI__OUT_SEL0       (* (reg8 *) vpp_distance__PRTDSI__OUT_SEL0) 
#define vpp_distance_PRTDSI__OUT_SEL1       (* (reg8 *) vpp_distance__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define vpp_distance_PRTDSI__SYNC_OUT       (* (reg8 *) vpp_distance__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(vpp_distance__SIO_CFG)
    #define vpp_distance_SIO_HYST_EN        (* (reg8 *) vpp_distance__SIO_HYST_EN)
    #define vpp_distance_SIO_REG_HIFREQ     (* (reg8 *) vpp_distance__SIO_REG_HIFREQ)
    #define vpp_distance_SIO_CFG            (* (reg8 *) vpp_distance__SIO_CFG)
    #define vpp_distance_SIO_DIFF           (* (reg8 *) vpp_distance__SIO_DIFF)
#endif /* (vpp_distance__SIO_CFG) */

/* Interrupt Registers */
#if defined(vpp_distance__INTSTAT)
    #define vpp_distance_INTSTAT            (* (reg8 *) vpp_distance__INTSTAT)
    #define vpp_distance_SNAP               (* (reg8 *) vpp_distance__SNAP)
    
	#define vpp_distance_0_INTTYPE_REG 		(* (reg8 *) vpp_distance__0__INTTYPE)
#endif /* (vpp_distance__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_vpp_distance_H */


/* [] END OF FILE */
