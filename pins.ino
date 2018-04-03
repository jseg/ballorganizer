void initializeInputs(){
  pinMode(TRIGGER1, INPUT); 
  pinMode(TRIGGER2, INPUT); 
  pinMode(TRIGGER3, INPUT); 
  pinMode(TRIGGER4, INPUT); 
  pinMode(TRIGGER5, INPUT); 
  pinMode(TRIGGER6, INPUT); 
  pinMode(OFFPIN, INPUT); 
  }

  void initializeOutputs(){  //set pin modes and intial states
  //Sounds
  pinMode(SOL1,OUTPUT);
  pinMode(SOL2,OUTPUT);
  pinMode(SOL3,OUTPUT);
  pinMode(SOL4,OUTPUT);
  pinMode(SOL5,OUTPUT);
  pinMode(SOL6,OUTPUT);
  pinMode(SOL8,OUTPUT);
  pinMode(MOTOR,OUTPUT);
  pinMode(POWER,OUTPUT);
  digitalWrite(SOL1,HIGH);
  digitalWrite(SOL2,HIGH);
  digitalWrite(SOL3,HIGH);
  digitalWrite(SOL4,HIGH);
  digitalWrite(SOL5,HIGH);
  digitalWrite(SOL6,HIGH);
  digitalWrite(SOL8,HIGH);
  digitalWrite(MOTOR,HIGH);
  digitalWrite(POWER,HIGH);
  }
