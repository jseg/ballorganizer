/////////////////////////////////
//Libraries
/////////////////////////////////
#include <Automaton.h>
#include "pins.h"
#include "settings.h"

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
Atm_led indicator;

Atm_bit revolution;
Atm_controller shutOff;


/////////////////////////////////
//Globals
/////////////////////////////////


void setup() {
  trigger1.begin(TRIGGER1, DEBOUNCE, true)
          .onChange(LOW,[] ( int idx, int v, int up ) { 
            sol1.trigger(sol1.EVT_START);
            sol8.trigger(sol8.EVT_START);
            });
  trigger2.begin(TRIGGER2, DEBOUNCE, true)
          .onChange(LOW,[] ( int idx, int v, int up ) { 
            sol2.trigger(sol2.EVT_START);
            });
  trigger3.begin(TRIGGER3, DEBOUNCE, true)
          .onChange(LOW,[] ( int idx, int v, int up ) { 
            sol3.trigger(sol3.EVT_START);
            });
  trigger4.begin(TRIGGER4, DEBOUNCE, true)
          .onChange(LOW,[] ( int idx, int v, int up ) { 
            sol4.trigger(sol4.EVT_START);
            });
  trigger5.begin(TRIGGER5, DEBOUNCE, true)
          .onChange(LOW,[] ( int idx, int v, int up ) { 
            sol5.trigger(sol5.EVT_START);
            sol8.trigger(sol8.EVT_START);
            });
  trigger6.begin(TRIGGER6, DEBOUNCE, true)
          .onChange(LOW,[] ( int idx, int v, int up ) { 
            sol6.trigger(sol6.EVT_START);
            });
  
  sol1.begin(SOL1,true)
      .blink(SOLPULSE,1,1);
  sol2.begin(SOL2,true)
      .blink(SOLPULSE,1,1);
  sol3.begin(SOL3,true)
      .blink(SOLPULSE,1,1);
  sol4.begin(SOL4,true)
      .blink(SOLPULSE,1,1);
  sol5.begin(SOL5,true)
      .blink(SOLPULSE,1,1);
  sol6.begin(SOL6,true)
      .blink(SOLPULSE,1,1);
  sol8.begin(SOL8,true)
      .blink(SHAKE_ON,SHAKE_OFF,SHAKES);

  

  revolution.begin()   //bit to keep track of drum rotation
            .led(13);
  powerOff.begin(OFFPIN, DEBOUNCE)  //digital input to initiate shutdown
          .onChange(HIGH,[] ( int idx, int v, int up ) { 
            motor.trigger(motor.EVT_ON);
            //trigger1.onChange(LOW, revolution, revolution.EVT_TOGGLE);
            revolution.trigger(revolution.EVT_TOGGLE);
            trigger2.sleep(1);
            trigger3.sleep(1);
            trigger4.sleep(1);
            trigger5.sleep(1);
            trigger6.sleep(1);
            });
  motor.begin(MOTOR)          //output to run motor
       .blink(TIMEOUT,1,1)
       .onFinish(power,power.EVT_ON);
  power.begin(POWER);   //output to kill power
  shutOff.begin()             //logical condition to catch 2nd trigger1 and shutdown
         .IF(trigger1,'=',1).AND(revolution)
         .onChange(power,power.EVT_ON); //cuts the power
}

void loop() {
 automaton.run();

}
