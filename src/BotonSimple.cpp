#include "botonSimple.h"

BotonSimple::BotonSimple(unsigned char _pin, unsigned long _tiempoRebote) {
  pin = _pin;
  tiempoRebote = _tiempoRebote;
  pinMode(pin, INPUT_PULLUP);
  valor=HIGH; anterior=HIGH; estado=SUELTO;
}

void BotonSimple::actualizar() {
  if ( valor==digitalRead(pin) ){
    temporizador=0;
  }
  else
  if ( temporizador==0 ) {
    temporizador = millis();
  }
  else
  if ( millis()-temporizador >= tiempoRebote ) {
    valor = !valor;
  }
  if ( anterior==LOW  && valor==LOW  ) estado = APRETADO;
  if ( anterior==LOW  && valor==HIGH ) estado = SOLTANDOLO;
  if ( anterior==HIGH && valor==LOW  ) estado = APRETANDOLO;
  if ( anterior==HIGH && valor==HIGH ) estado = SUELTO;
  anterior = valor;
}

int BotonSimple::leer() { 
  return estado;
}
 
