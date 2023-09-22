/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene las definiciones de ADC
 * 
 * Aquí se encuentra la implementación de ADC, los defines, macros, 
 * datos internos y externos, declaraciones y definiciones de funciones
 * internas y definiciones de funciones externas.
 */

/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/
#include "system.h"
#include "adc.h"        /* Funciones/Parametros ADC */

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/

/**
 * @brief	Inicializa el ADC
 * @return	Nada
 */
void adcInit(void) {
    FVREN = 1; //habilita vref
    ADFM = 1; //justifica a derecha
    VCFG1 = 0; //referencia interna
    VCFG0 = 0;
    ADCS0 = 1; //clock interno
    ADCS1 = 1;
    ANS0 = 1; //entrada analogica        
    ADON = 1; //prendo  conversor  

}

/**
 * @brief	Realiza una conversión AD
 * @param[in]   analogInput Selecciona la entrada analógica deseada
 * @return  resultado de la conversión
 */
uint16_t adcRead(adcMap_t analogInput){  
    uint16_t adcRES;
    ADCON0bits.CHS = analogInput;
    __delay_us(50);
    GO_nDONE = 1; // INICIO LA CONVERSION 
    while (GO_nDONE == 1){} // MIENTRAS QUE SE HAGA LA CONVERSION, ESPERO 
    adcRES = ADRESL; // GUARDO EL RESULTADO 
    adcRES = adcRES | (ADRESH << 8);
    return adcRES;
}

/**
 * @brief	Realiza una conversión AD en mV
 * @param[in]   analogInput Selecciona la entrada analógica deseada
 * @note    Si recibe como parámetro 255 ( o la etiqueta `VDD_CALC` ) determina la tensión de alimentación VDD o tensión de referencia actual 
 * @return  resultado de la conversión en mV
 * @note    Antes de poder medir cualquier canal se debe medir por lo menos una vez la tensión de alimentación o referencia
 */
uint16_t adcRead_mV(adcMap_t analogInput) {
    static uint16_t nAdcRef = 0;
    if (analogInput == VDD_CALC) {
        nAdcRef = adcRead(AIN_FIXREF);
        return (1023UL * 600U) / nAdcRef;
    }
    else{
        return((600UL*adcRead(analogInput)) / nAdcRef);
}
}
/*==================[fin del archivo]========================================*/
