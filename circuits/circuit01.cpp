// model circuit with two voltage sources 

#include <iostream>

using namespace std;

float currentIx(float,float,float,float,float); //retruns flowing in Ix
float currentIy(float,float,float,float,float); //retruns flowing in Iy

int main (void)
{
  //resistor,current,voltage
  float R1,R2,R3,Ry,Rz,V1,V2;
  float Rx, D, Ix, Iy, Iz, Vz;

  cout << "Resistor in ohms";

  cout << "\nR1: ";
  cin >> R1;
  cout << "\nR2: ";
  cin >> R2;
  cout << "\nR3: ";
  cin >> R3;
  cout << "\nRy: ";
  cin >> Ry;
  cout << "\nRz: ";
  cin >> Rz;

  cout << "Tension in volts";

  cout << "\nV1: ";
  cin >> V1;
  cout << "\nV2: ";
  cin >> V2;

  Rx = R1 + ((R2 * R3) / (R2 + R3)); //resultant resistance
  cout << "Rx is " << Rx << "ohm\n" <<endl; //resistance
  D = ((Rx + Rz)*(Ry + Rz)) - (Rz*Rz); //determinant

  Ix = currentIx(Rz,Ry,V1,V2,D);
  Iy = currentIy(Rx,Rz,V1,V2,D);
  Iz = Ix + Iy;
  Vz = Rz * Iz;

  //display 

  cout << "Current Ix = " << Ix << "A"<<endl;
    cout << "Current Iy = " << Iy << "A"<<endl;
    cout << "Current Iz = " << Iz << "A" <<endl;
    cout << "Output voltage Vz = " << Vz << "V"<<endl;
    
    return 0;
}

//function to calculate current in Ix

float currentIx(float a, float b, float c, float d, float e)
{
  float Dx;
  Dx = ((c *(a+b)) - (d * a)) / e;
  return Dx;
}

//function to calculate current in Iy 

float currentIy(float a, float b, float c, float d, float e)
{
  float Dy;
  Dy = (((a + b) * d) - (c * b)) / e;
  return Dy;
}
