/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.45
        Device            :  PIC16F15325
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void set_led(uint8_t led){
    if(led){
        //1
        LEDTouch_SetHigh();  //1
        LEDDuty_SetLow();  //0        
    }else{
        //0
        //default led status
        LEDTouch_SetLow();  //1
        LEDDuty_SetHigh();  //0        
    }
}

//25ms
void wait_25ms(void){
    uint16_t i=0;
    while(i<16000){
        i++;
    }
}
void check_time(void){
    uint16_t i=0;
    uint16_t j=0;
    while(i<10000){
        i++;
        j++;
    }
}
void main(void)
{
    uint8_t led=0;
    uint8_t touch_sensor=0;
    uint16_t cnt_25ms=0;
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    //printf("uart1 test1\n\r");
    //printf("uart1 test2\n\r");
    //while(1){
    //    wait_25ms();
    //    LEDDuty_Toggle();
    //}
    //default led status
    led=0;
    set_led(led); 
    
    while (1)
    {
        while(PORTCbits.RC1 == 1); //wait change;
        wait_25ms();
        
        //check 1.6s;
        cnt_25ms = 0;
        while( (PORTCbits.RC1 == 0) && (cnt_25ms < 30)  ){
            wait_25ms();
            cnt_25ms++;
        }
        
        //entry
        if( cnt_25ms >= 30 ){
            //low
            if(led==0){
                led = 1;
            }else{
                led = 0;
            }
            set_led(led);            
        }
        while(PORTCbits.RC1 == 0); //wait change;
        
        //release 0.25s
        //cnt_25ms = 0;
        //while(cnt_25ms < 10){
        //    wait_25ms();
        //    if( PORTCbits.RC1 == 1) cnt_25ms++;
        //}
    }    
#if 0    
    while (1)
    {
        // Add your application code
        while(PORTCbits.RC1 == 1); //wait change;
        
        //low
        if(led==0){
            led = 1;
        }else{
            led = 0;
        }
        set_led(led);
        while(PORTCbits.RC1 == 0); //wait change;
    }
#endif
}
/**
 End of File
*/