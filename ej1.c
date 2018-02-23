#include <16f877.h>  //Librería del microcontrolador
#fuses HS,NOPROTECT,
#device ADC=10   //Convertidor A/D indica resolución de 10 bits
#use delay(clock=20000000) //Frec. de Osc. 20Mhz
//Configuracion del Puerto SERIAL
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7) 
#org 0x1F00, 0x1FFF void loader16F877(void) {}  

void main(){

    //Configuración del Puerto A como analógico 
    setup_port_a(ALL_ANALOG);   
    setup_adc(ADC_CLOCK_INTERNAL); //Relog interno de Conv. A/D
    set_adc_channel(0);    //Selecion del canal 0 

long var; // Variable tipo entero 
float var2;
    while(1){           
        delay_us(200);  
        var=read_adc(); // Se asigna a var la lectura del Canal 0  
        delay_us(200);  
        output_b(var);  // Se muestra  var en el puerto B 
       var2=((float)var)*5/1023; //se realiza la conversion a decimal
       // Se imprime en pantalla  lo que contiene var y su conversion
        printf("%3LX %Ld %f\n",var,var,var2);
       delay_ms(100);          
    }
}





