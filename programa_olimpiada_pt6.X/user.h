/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene macros y definiciones de user
 * 
 * Aquí se definen macros, tipos de datos y se declaran las funciones y datos 
 * externos de user
 */
#ifndef USER_H
#define USER_H
/*==================[inclusiones]============================================*/
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

/*==================[macros]=================================================*/
/* User Level #define Macros                                                 */
/* TODO: Los parámetros de user.c pueden ponerse aquí */

//ENTRADA
#define	TRIS_INI            TRISAbits.TRISA7
#define PIN_INI             PORTAbits.RA7
#define TRIS_F_A            TRISAbits.TRISA1
#define PIN_F_A             PORTAbits.RA1
#define	TRIS_R_INT          TRISAbits.TRISA2
#define PIN_R_INT           PORTAbits.RA2
#define	TRIS_ENTRADA_CI     TRISAbits.TRISA3
#define PIN_ENTRADA_CI      PORTAbits.RA3
#define	TRIS_Q_CI           TRISBbits.TRISB2
#define PIN_Q_CI            PORTBbits.RB2
#define	TRIS_Q_CI_NEG       TRISAbits.TRISA5
#define PIN_Q_CI_NEG        PORTAbits.RA5
#define	TRIS_RES_NORM       TRISAbits.TRISA6
#define PIN_RES_NORM        PORTAbits.RA6
#define TRIS_BUTTON         TRISAbits.TRISA4
#define PIN_BUTTON          PORTAbits.RA4
#define TRIS_CI_T1          TRISAbits.TRISA0
#define PIN_CI_T1           PORTAbits.RA0
#define TRIS_CI_T2          TRISBbits.TRISB0
#define PIN_CIT2            PORTBbits.RB0


//SALIDAS
#define TRIS_LED_NORM       TRISCbits.TRISC0
#define PIN_LED_NORM        PORTCbits.RC0
#define TRIS_LED_INI        TRISCbits.TRISC1
#define PIN_LED_INI         PORTCbits.RC1
#define TRIS_LED_ERROR      TRISCbits.TRISC2
#define PIN_LED_ERROR       PORTCbits.RC2
#define TRIS_LED_F_A         TRISCbits.TRISC3
#define PIN_LED_F_A          PORTCbits.RC3
#define TRIS_LED_TRANSF     TRISCbits.TRISC4
#define PIN_LED_TRANSF      PORTCbits.RC4
#define TRIS_LED_CI         TRISCbits.TRISC5
#define PIN_LED_CI          PORTCbits.RC5
#define TRIS_LED_TGENE      TRISCbits.TRISC6
#define PIN_LED_TGENE       PORTCbits.RC6
#define TRIS_LED_REG_INT    TRISCbits.TRISC7
#define PIN_LED_REG_INT     PORTCbits.RC7
#define TRIS_OSC1           TRISBbits.TRISB4
#define PIN_OSC1            PORTBbits.RB4
#define TRIS_OSC2           TRISBbits.TRISB5
#define PIN_OSC2            PORTBbits.RB5

//Buzzer
#define	TRIS_SOUNDER        TRISBbits.TRISB7
#define	PIN_SOUNDER         PORTBbits.RB7


/*==================[tipos de datos declarados por el usuario]===============*/

/*==================[declaraciones de datos externos]========================*/
//extern char datoUser; //Ejemplo

/*==================[declaraciones de funciones externas]====================*/
/* TODO: Los prototipos de User level (ej. InitApp) van aquí */
void appInit(void);     /* Inicializa las I/O y los periféricos */
void delayTMR0mSeg(uint16_t tmsegs); /* Demora una cantidad de mSegs basado en desbordes de TMR0 */
/*==================[fin del archivo]========================================*/
#endif// USER_H
