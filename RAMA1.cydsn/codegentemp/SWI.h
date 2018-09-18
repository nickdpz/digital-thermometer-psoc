/*******************************************************************************
* File Name: SWI.h  
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

#if !defined(CY_PINS_SWI_H) /* Pins SWI_H */
#define CY_PINS_SWI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SWI_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SWI__PORT == 15 && ((SWI__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SWI_Write(uint8 value);
void    SWI_SetDriveMode(uint8 mode);
uint8   SWI_ReadDataReg(void);
uint8   SWI_Read(void);
void    SWI_SetInterruptMode(uint16 position, uint16 mode);
uint8   SWI_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SWI_SetDriveMode() function.
     *  @{
     */
        #define SWI_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SWI_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SWI_DM_RES_UP          PIN_DM_RES_UP
        #define SWI_DM_RES_DWN         PIN_DM_RES_DWN
        #define SWI_DM_OD_LO           PIN_DM_OD_LO
        #define SWI_DM_OD_HI           PIN_DM_OD_HI
        #define SWI_DM_STRONG          PIN_DM_STRONG
        #define SWI_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SWI_MASK               SWI__MASK
#define SWI_SHIFT              SWI__SHIFT
#define SWI_WIDTH              3u

/* Interrupt constants */
#if defined(SWI__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SWI_SetInterruptMode() function.
     *  @{
     */
        #define SWI_INTR_NONE      (uint16)(0x0000u)
        #define SWI_INTR_RISING    (uint16)(0x0001u)
        #define SWI_INTR_FALLING   (uint16)(0x0002u)
        #define SWI_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SWI_INTR_MASK      (0x01u) 
#endif /* (SWI__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SWI_PS                     (* (reg8 *) SWI__PS)
/* Data Register */
#define SWI_DR                     (* (reg8 *) SWI__DR)
/* Port Number */
#define SWI_PRT_NUM                (* (reg8 *) SWI__PRT) 
/* Connect to Analog Globals */                                                  
#define SWI_AG                     (* (reg8 *) SWI__AG)                       
/* Analog MUX bux enable */
#define SWI_AMUX                   (* (reg8 *) SWI__AMUX) 
/* Bidirectional Enable */                                                        
#define SWI_BIE                    (* (reg8 *) SWI__BIE)
/* Bit-mask for Aliased Register Access */
#define SWI_BIT_MASK               (* (reg8 *) SWI__BIT_MASK)
/* Bypass Enable */
#define SWI_BYP                    (* (reg8 *) SWI__BYP)
/* Port wide control signals */                                                   
#define SWI_CTL                    (* (reg8 *) SWI__CTL)
/* Drive Modes */
#define SWI_DM0                    (* (reg8 *) SWI__DM0) 
#define SWI_DM1                    (* (reg8 *) SWI__DM1)
#define SWI_DM2                    (* (reg8 *) SWI__DM2) 
/* Input Buffer Disable Override */
#define SWI_INP_DIS                (* (reg8 *) SWI__INP_DIS)
/* LCD Common or Segment Drive */
#define SWI_LCD_COM_SEG            (* (reg8 *) SWI__LCD_COM_SEG)
/* Enable Segment LCD */
#define SWI_LCD_EN                 (* (reg8 *) SWI__LCD_EN)
/* Slew Rate Control */
#define SWI_SLW                    (* (reg8 *) SWI__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SWI_PRTDSI__CAPS_SEL       (* (reg8 *) SWI__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SWI_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SWI__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SWI_PRTDSI__OE_SEL0        (* (reg8 *) SWI__PRTDSI__OE_SEL0) 
#define SWI_PRTDSI__OE_SEL1        (* (reg8 *) SWI__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SWI_PRTDSI__OUT_SEL0       (* (reg8 *) SWI__PRTDSI__OUT_SEL0) 
#define SWI_PRTDSI__OUT_SEL1       (* (reg8 *) SWI__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SWI_PRTDSI__SYNC_OUT       (* (reg8 *) SWI__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SWI__SIO_CFG)
    #define SWI_SIO_HYST_EN        (* (reg8 *) SWI__SIO_HYST_EN)
    #define SWI_SIO_REG_HIFREQ     (* (reg8 *) SWI__SIO_REG_HIFREQ)
    #define SWI_SIO_CFG            (* (reg8 *) SWI__SIO_CFG)
    #define SWI_SIO_DIFF           (* (reg8 *) SWI__SIO_DIFF)
#endif /* (SWI__SIO_CFG) */

/* Interrupt Registers */
#if defined(SWI__INTSTAT)
    #define SWI_INTSTAT            (* (reg8 *) SWI__INTSTAT)
    #define SWI_SNAP               (* (reg8 *) SWI__SNAP)
    
	#define SWI_0_INTTYPE_REG 		(* (reg8 *) SWI__0__INTTYPE)
	#define SWI_1_INTTYPE_REG 		(* (reg8 *) SWI__1__INTTYPE)
	#define SWI_2_INTTYPE_REG 		(* (reg8 *) SWI__2__INTTYPE)
#endif /* (SWI__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SWI_H */


/* [] END OF FILE */
