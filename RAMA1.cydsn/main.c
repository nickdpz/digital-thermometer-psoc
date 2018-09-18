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
uint16 temp=0;

CY_ISR(Inte){
    switch(SWI_Read()){
    case 0x0D:
        LCD_Position(1,14);
        LCD_PutChar(LCD_CUSTOM_0); // Se ponen los grados
        LCD_PrintString("C");
        de=0;//Actualiza Conversion 
        break;
    case 0x0B:
        LCD_Position(1,14);
        LCD_PutChar(LCD_CUSTOM_0); // Se ponen los grados
        LCD_PrintString("F");
        de=1;//Actualiza Conversion 
        break;
    case 0x7:
        LCD_Position(1,14);
        LCD_PrintString(" K");
        de=2;//Actualiza Conversion 
        break;
     default:
        break;
    }
    SWI_ClearInterrupt();
}

void visual(uint16 numero){
        
    LCD_Position(1,0);
    LCD_PrintNumber(numero);
    if(numero<100){
        LCD_Position(1,1);
        LCD_PrintNumber(numero);
        LCD_Position(1,1);
        LCD_PutChar('.');
    
    }else{
        LCD_Position(1,2);
        LCD_PrintNumber(numero);
        LCD_Position(1,2);
        LCD_PutChar('.');
    }
        return;
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    LCD_Start();//Carga caracteres personalizados
    ADC_Start();//
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
        if(de==0){
            //Condicion para Grados Centigrados
            visual(temp*5);     
            
        }else if(de==1){
            //Condicion para Grados Farenhi
            visual(temp*5);
        }
        else{
            //Condicion para Kelvin
            visual(temp*10+1);
        }
        
        
        CyDelay(500);//Tiempo de Refresco
    }
}

/* [] END OF FILE */
