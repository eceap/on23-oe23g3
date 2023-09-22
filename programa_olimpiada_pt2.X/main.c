/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene la función principal
 * 
 * Aquí se encuentra la implementación de la función principal
 */
/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* Para las definiciones de uint8_t por ej.*/
#include "system.h"     /* Funciones/Parametros System, como osc/peripheral config */
#include "user.h"       /* Funciones/Parametros User, como InitApp */
#include "tick.h"       /* Funciones/Parametros Tick */
#include <stdio.h>      /* Archivo de Encabezados StdIO */
#include "adc.h"    

/*==================[definiciones y macros]==================================*/
typedef enum {
    Einicio, Erecuperacion, Etesteo
} estadoMEF_t;
/*==================[definiciones de datos internos]=========================*/
estadoMEF_t estadoActual; // Variable de estado (global)
tick_t tInicio;
uint16_t fallas, valorAD0, valorAD1, valorAD2, valorAD3;
adcMap_t canal; // creo una variable de canal
/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/
void InicializarMEF(void);
void ActualizarMEF(void);
uint16_t resultadoADC;

/*==================[funcion principal]======================================*/
void main(void) {
    appInit(); /* Inicializa I/O y Periféricos de la aplicación */
    InicializarMEF();
    while (1) {
        ActualizarMEF();

    }
}

void InicializarMEF(void) {
    estadoActual = Einicio; // Establece estado inicial 
    tInicio = tickRead(); // También inicia temporizacion    
}

void ActualizarMEF(void) {
    switch (estadoActual) {
        case Einicio:
            PIN_LED_INI = 1;
            if (tickRead() - tInicio > 1000) {
                estadoActual = Etesteo; // pasa al estado de diagnostico
            }

            break;
        case Etesteo:
            if (PIN_F_A == 0) { //testeo el si el fusible esta abierto
                PIN_LED_F_A = 1;
                fallas++;
            }

            resultadoADC = adcRead(AIN2); //mido la salida del regulador interno
            if (resultadoADC < 8900 && resultadoADC > 9300) { //si el valor de salida no está entre los 8,9 y los 9,3 prende los leds
                PIN_LED_REG_INT = 1;
                fallas++;
            }

            if (PIN_Q_CI == 1) { //testeo el funcionamiento del circuito integrado
                tInicio = tickRead(); // También inicia temporizacion
                if (tickRead() - tInicio > 11 && PIN_Q_CI != 0 || (PIN_Q_CI == PIN_Q_CI_NEG))
                    PIN_LED_CI = 1;
                fallas++;
            }

            if (PIN_INI == 1) {
                PIN_LED_TGENE = 1;
            }
            

            estadoActual = Erecuperacion; // pasa al estado de recuperacion
            break;
        case Erecuperacion:


            break;

        default:
            InicializarMEF();
    }
}



/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/