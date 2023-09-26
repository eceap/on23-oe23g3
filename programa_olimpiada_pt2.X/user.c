/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene las definiciones de user
 * 
 * Aquí se encuentra la implementación de users, los defines, macros, 
 * datos internos y externos, declaraciones y definiciones de funciones
 * internas y definiciones de funciones externas.
 */

/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/
#include "adc.h"
#include "system.h"     /* Funciones/Parametros System, como conf de osc/perif */
#include "user.h"       /* Funciones/Parametros User, como InitApp */
#include "tick.h"

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/
//char datoUser; //Ejemplo

/*==================[declaraciones de funciones internas]====================*/
//static void funcUser(void); //Ejemplo

/*==================[definiciones de funciones internas]=====================*/
//static void funcUser(void){ //Ejemplo
//}; 

/*==================[definiciones de funciones externas]=====================*/

/**
 * @brief	Inicializa Ports, Periféricos e Interrupciones
 * @return	Nada
 */
void appInit(void) {
    /* Configura funciones analógicas y dirección de los Ports de I/O */
    ANSEL = 0;
    ANSELH = 1;
    ANS1 = 0;
    ANS2 = 0;

    TRIS_INI = 1;
    TRIS_F_A = 1;
    TRIS_R_INT = 1;
    TRIS_ENTRADA_CI = 1;
    TRIS_Q_CI = 1;
    TRIS_Q_CI_NEG = 1;
    TRIS_RES_NORM = 1;
    TRIS_BUTTON = 1;
    TRIS_CI_T1 = 1;
    TRIS_CI_T2 = 1;
    TRIS_LED_NORM = 0;
    TRIS_LED_INI = 0;
    TRIS_LED_ERROR = 0;
    TRIS_LED_F_A = 0;
    TRIS_LED_TRANSF = 0;
    TRIS_LED_CI = 0;
    TRIS_LED_TGENE = 0;
    TRIS_LED_REG_INT = 0;
    TRIS_SOUNDER = 0;
    adcInit();
    tickInit();
    __delay_ms(100); //Espera que se estabilice la fuente

    /* TODO: Habilita Interrupciones si es necesario*/
    TMR0IE = 1;     //Habilita interrupcion para tick
    //PEIE = 1;
    GIE = 1;
} 


/*==================[fin del archivo]========================================*/