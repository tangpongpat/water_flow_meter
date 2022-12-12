volatile int NbTopsFan; //measuring the rising edges of the signal

int Calc;

int hallsensor = 2;    //The pin location of the sensor

int Relaypin= 3;


void rpm ()     //This is the function that the interupt calls

{

 NbTopsFan++;  //This function measures the rising and falling edge of the hall effect sensors signal

}

// The setup() method runs once, when the sketch starts

void setup() //

{

 pinMode(Relaypin, OUTPUT); 

 pinMode(hallsensor, INPUT); //initializes digital pin 2 as an input

 Serial.begin(9600); //This is the setup function where the serial port is initialised,

 attachInterrupt(0, rpm, RISING); //and the interrupt is attached

}

// the loop() method runs over and over again,

// as long as the Arduino has power

void loop ()

{

 NbTopsFan = 0;      //Set NbTops to 0 ready for calculations

 sei();            //Enables interrupts

 delay (1000);      //Wait 1 second

 cli();            //Disable interrupts

 Calc = (NbTopsFan * 60 / 7.5); //(Pulse frequency x 60) / 7.5Q, = flow rate in L / hour

 Serial.print (Calc, DEC); //Prints the number calculated above

 Serial.print ("\t\r\n"); //Prints "L/hour" and returns a  new line

if ( Calc > 500 ) {

      digitalWrite(Relaypin,LOW);
       
      delay(1000); 
    }
else {
    digitalWrite(Relaypin,HIGH);
       
      delay(1000);

}


}