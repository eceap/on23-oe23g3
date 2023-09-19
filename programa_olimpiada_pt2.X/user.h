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

//SALIDAS
#define TRIS_LED_NORM       TRISCbits.RC0
#define PIN_LED_NORM        PORTAbits.RC0
#define TRIS_LED_INI        TRISCbits.RC1
#define PIN_LED_INI         PORTAbits.RC1
#define TRIS_LED_ERROR      TRISCbits.RC2
#define PIN_LED_ERROR       PORTAbits.RC2
#define TRIS_LED_FA         TRISCbits.RC3
#define PIN_LED_FA          PORTAbits.RC3
#define TRIS_LED_TRANSF     TRISCbits.RC4
#define PIN_LED_TRANSF      PORTAbits.RC4
#define TRIS_LED_CI         TRISCbits.RC5
#define PIN_LED_CI          PORTAbits.RC5
#define TRIS_LED_TGENE      TRISCbits.RC6
#define PIN_LED_TGENE       PORTAbits.RC6
#define TRIS_LED_REG_INT    TRISCbits.RC7
#define PIN_LED_REG_INT     PORTAbits.RC7

//Buzzer
#define	TRIS_SOUNDER        TRISBbits.TRISB7
#define	PIN_SOUNDER         PORTBbits.RB7


/*==================[tipos de datos declarados por el usuario]===============*/

/*==================[declaraciones de datos externos]========================*/
//extern char datoUser; //Ejemplo

/*==================[declaraciones de funciones externas]====================*/
/* TODO: Los prototipos de User level (ej. InitApp) van aquí */
void appInit(void);     /* Inicializa las I/O y los perif�ricos */
/*==================[fin del archivo]========================================*/
#endif// USER_H
