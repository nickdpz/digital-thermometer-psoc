/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"



extern uint8 const CYCODE LCD_customFonts[]; //Se carga los caracteres especiales
volatile uint8 de=0;
uint8 temp=0;
uint16 d,u,f,k;

CY_ISR(Inte){
    CyDelay(1);
    switch(SWI_Read()){
    case 0b00000110:
        LCD_Position(1,14);
        LCD_PutChar(LCD_CUSTOM_0); // Se ponen los grados
        LCD_PrintString("C");
        de=0;//Actualiza Conversion 
        break;
    case 0b00000101:
        LCD_Position(1,14);
        LCD_PutChar(LCD_CUSTOM_0); // Se ponen los grados
        LCD_PrintString("F");
        de=1;//Actualiza Conversion 
        break;
    case 0b00000011:
        LCD_Position(1,14);
        LCD_PrintString(" K");
        de=2;//Actualiza Conversion 
        break;
     default:
        break;
    }
    SWI_ClearInterrupt();
}

void visual(uint16 numero, uint16 numero2){
        LCD_Position(1,0);
        LCD_PrintString("       ");
        LCD_Position(1,0);
        LCD_PrintDecUint16(numero);
        LCD_Position(1,2);
        LCD_PrintString(".");
        LCD_PrintDecUint16(numero2);
        LCD_Position(1,4);
        LCD_PrintString(" ");
        
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    IRQ_SW_StartEx(Inte);
    LCD_Start();//Carga caracteres personalizados
    ADC_Start();//Se Carga ADC
    LCD_Position(0,0);
    LCD_PrintString("Temperatura : ");
    LCD_Position(1,14);
    LCD_PutChar(LCD_CUSTOM_0); // Se ponen los grados
    LCD_PrintString("C"); 
    for(;;)
    {   
        
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        temp=ADC_GetResult16();
        //temp=ADC_CountsTo_mVolts(temp);
        if(de==0){
            //Condicion para Grados Centigrados
            u=(uint16)(temp*39+39)/100;
            d=(uint16)(temp*39+39)%100;
            visual(u,d);     
        }else if(de==1){
            //Condicion para Grados Farenhi
            temp=ADC_GetResult16();
            temp=ADC_CountsTo_mVolts(temp);
            LCD_Position(1,0);
            LCD_PrintNumber(temp);
        }
        else{
            //Condicion para Kelvin
            visual(temp,1);
        }
        
        
        CyDelay(500);//Tiempo de Refresco
    }
}

/* [] END OF FILE */
