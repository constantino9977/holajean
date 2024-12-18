// Libraries
#include <PIDController.h>
const float Sensibilidad=0.066;


const int salidaControl=5;
const int sensorI=A0;


int i;

float sumaI=0.0;
float I2=0.0;

float tiempo=0.0;

float voltajeSensor=0;
float I=0;


float setPoint=0.0;
// Objects
PIDController pid; // Create an instance of the PID controller class, called "pid"


void setup () {
  Serial.begin(9600);   // Some methods require the Serial.begin() method to be called first
  pinMode(salidaControl,OUTPUT);

  pid.begin();          // initialize the PID instance
  pid.tune(5, 5, 100);    // Tune the PID, arguments: kP, kI, kD
  pid.limit(0, 255);    // Limit the PID output between 0 and 255, this is important to get rid of integral windup!
  setPoint=1;
  pid.setpoint(setPoint);    // The "goal" the PID controller tries to "reach"
  delay(2000);
}

void loop () {
  
  //sumaI=0.0;
  //for (i= 0; i <100; i++) {
  //  voltajeSensor= analogRead(A1)*(5.0 / 1023.0); //lectura del sensor   
  //  I=-(voltajeSensor-2.5)/Sensibilidad; //Ecuación  para obtener la corriente
  //  sumaI+=I;
    
  //}
  voltajeSensor= analogRead(A0)*(5.0 / 1023.0); //lectura del sensor   
  I=(voltajeSensor-2.5)/Sensibilidad; //Ecuación  para obtener la corriente
 
  //I2=-sumaI/100;

 
 int output = pid.compute(I);    // Let the PID compute the value, returns the optimal output
 analogWrite(salidaControl, 255-output);           // Write the output to the output pin
      
  
 // Serial.print("Corriente: ");
  Serial.print(I);
  
  
  

  Serial.print(",");
  Serial.print(0);
  Serial.print(",");
  Serial.println(5);
  //Serial.println(" minutos ");
  //delay(3);           
 
}
 

