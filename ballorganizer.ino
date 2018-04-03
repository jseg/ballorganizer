/////////////////////////////////
//Libraries
/////////////////////////////////
#include <Automaton.h>
/////////////////////////////////
//Objects
/////////////////////////////////
Atm_digital trigger1;
Atm_digital trigger2;
Atm_digital trigger3;
Atm_digital trigger4;
Atm_digital trigger5;
Atm_digital trigger6;
Atm_digital powerOff;

Atm_led sol1;
Atm_led sol2;
Atm_led sol3;
Atm_led sol4;
Atm_led sol5;
Atm_led sol6;
Atm_led sol8;
Atm_led motor;
Atm_led power;



/////////////////////////////////
//Globals
/////////////////////////////////


void setup() {
  trigger1.begin(TRIGGER1, DEBOUNCE, true)
          .onChange(LOW,[] ( int idx, int v, int up ) { 
            sol1.trigger(sol1.EVT_START);
            sol8.trigger(sol8.EVT_START);
            }
  trigger2.begin(TRIGGER2, DEBOUNCE, true)
          .onChange(LOW,[] ( int idx, int v, int up ) { 
            sol2.trigger(sol2.EVT_START);
            }
  trigger3.begin(TRIGGER3, DEBOUNCE, true)
          .onChange(LOW,[] ( int idx, int v, int up ) { 
            sol3.trigger(sol3.EVT_START);
            }
  trigger4.begin(TRIGGER4, DEBOUNCE, true)
          .onChange(LOW,[] ( int idx, int v, int up ) { 
            sol4.trigger(sol4.EVT_START);
            }
  trigger5.begin(TRIGGER5, DEBOUNCE, true)
          .onChange(LOW,[] ( int idx, int v, int up ) { 
            sol5.trigger(sol5.EVT_START);
            sol8.trigger(sol8.EVT_START);
            }
  trigger6.begin(TRIGGER6, DEBOUNCE, true)
          .onChange(LOW,[] ( int idx, int v, int up ) { 
            sol1.trigger(sol1.EVT_START);
            }
  powerOff.begin(OFFPIN, DEBOUNCE, true)
          .onChange(LOW,[] ( int idx, int v, int up ) { 
            motor.trigger(motor.EVT_START);
            }
  sol1.begin(SOL1,true)
      .blink(SOLPULSE);
  sol2.begin(SOL2,true)
      .blink(SOLPULSE);
  sol3.begin(SOL3,true)
      .blink(SOLPULSE);
  sol4.begin(SOL4,true)
      .blink(SOLPULSE);
  sol5.begin(SOL5,true)
      .blink(SOLPULSE);
  sol6.begin(SOL6,true)
      .blink(SOLPULSE);
  sol8.begin(SOL8,true)
      .blink(SHAKE_ON,SHAKE_OFF,SHAKES);
  motor.begin(MOTOR)
       .blink(BALLEJECT)
       .onFinish(power,power.EVT_ON);
  power.begin(POWER)
         

void loop() {
 automoton.run();

}
