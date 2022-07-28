#include "M5Atom.h"
#include <cmath>
#include <iostream>
#include <string>

using std::string;

#define PIN 27


unsigned long PreviousTime = 0;
const long TimeInterval= 2000;
int ctr=0;
float AverageTemp=0;
float Temp=0;

int tmpnum = 0;
double avgtmp = 0; 
int ModeCounter=0;
bool DeviceOff=true;
float gyroX = 0;
float gyroY = 0;
float gyroZ = 0;
int temp = 0;
float tempF=0;
char unit = 'c';
int turn = 0;

int minSens = 250;
int maxSens = 650;

float tempC = 0;
bool IMU6886Flag = false;
bool menu=true;
float accX = 0, accY = 0, accZ = 0;

void dis1()
{
        M5.dis.drawpix(2, 0xf00000);
        M5.dis.drawpix(6, 0xf00000);
        M5.dis.drawpix(7, 0xf00000);
        M5.dis.drawpix(12, 0xf00000);
        M5.dis.drawpix(17, 0xf00000);
        M5.dis.drawpix(21, 0xf00000);
        M5.dis.drawpix(22, 0xf00000);
        M5.dis.drawpix(23, 0xf00000);
}

void dis2()
{
        M5.dis.drawpix(1, 0xf00000);
        M5.dis.drawpix(2, 0xf00000);
        M5.dis.drawpix(3, 0xf00000);
        M5.dis.drawpix(8, 0xf00000);
        M5.dis.drawpix(12, 0xf00000);
        M5.dis.drawpix(16, 0xf00000);
        M5.dis.drawpix(21, 0xf00000);
        M5.dis.drawpix(22, 0xf00000);
        M5.dis.drawpix(23, 0xf00000);
}

void dis3()
{
          M5.dis.drawpix(1, 0xf00000);
          M5.dis.drawpix(2, 0xf00000);
          M5.dis.drawpix(3, 0xf00000);
          M5.dis.drawpix(8, 0xf00000);
          M5.dis.drawpix(11, 0xf00000);
          M5.dis.drawpix(12, 0xf00000);
          M5.dis.drawpix(18, 0xf00000);
          M5.dis.drawpix(21, 0xf00000);
          M5.dis.drawpix(22, 0xf00000);
          M5.dis.drawpix(23, 0xf00000);
}

void dis4()
{        
         M5.dis.drawpix(1, 0xf00000);
         M5.dis.drawpix(3, 0xf00000);
         M5.dis.drawpix(6, 0xf00000);
         M5.dis.drawpix(8, 0xf00000);
         M5.dis.drawpix(11, 0xf00000);
         M5.dis.drawpix(12, 0xf00000);
         M5.dis.drawpix(13, 0xf00000);
         M5.dis.drawpix(18, 0xf00000);
         M5.dis.drawpix(23, 0xf00000);
}


void dis5()
{
           M5.dis.drawpix(1, 0xf00000);
           M5.dis.drawpix(2, 0xf00000);
           M5.dis.drawpix(3, 0xf00000);
           M5.dis.drawpix(6, 0xf00000);
           M5.dis.drawpix(11, 0xf00000);
           M5.dis.drawpix(12, 0xf00000);
           M5.dis.drawpix(13, 0xf00000);
           M5.dis.drawpix(18, 0xf00000);
           M5.dis.drawpix(21, 0xf00000);
           M5.dis.drawpix(22, 0xf00000);
           M5.dis.drawpix(23, 0xf00000);
}

void dis6()
{
           M5.dis.drawpix(1, 0xf00000);
           M5.dis.drawpix(2, 0xf00000);
           M5.dis.drawpix(3, 0xf00000);
           M5.dis.drawpix(6, 0xf00000);
           M5.dis.drawpix(11, 0xf00000);
           M5.dis.drawpix(12, 0xf00000);
           M5.dis.drawpix(13, 0xf00000);
           M5.dis.drawpix(16, 0xf00000);
           M5.dis.drawpix(18, 0xf00000);
           M5.dis.drawpix(21, 0xf00000);
           M5.dis.drawpix(22, 0xf00000);
           M5.dis.drawpix(23, 0xf00000);
}

void dis7()
{
           M5.dis.drawpix(1, 0xf00000);
           M5.dis.drawpix(2, 0xf00000);
           M5.dis.drawpix(3, 0xf00000);
           M5.dis.drawpix(8, 0xf00000);
           M5.dis.drawpix(12, 0xf00000);
           M5.dis.drawpix(13, 0xf00000);
           M5.dis.drawpix(18, 0xf00000);
           M5.dis.drawpix(23, 0xf00000);
}

void dis8()
{
  M5.dis.drawpix(1, 0xf00000);
           M5.dis.drawpix(1, 0xf00000);
           M5.dis.drawpix(2, 0xf00000);
           M5.dis.drawpix(3, 0xf00000);
           M5.dis.drawpix(6, 0xf00000);
           M5.dis.drawpix(8, 0xf00000);
           M5.dis.drawpix(11, 0xf00000);
           M5.dis.drawpix(12, 0xf00000);
           M5.dis.drawpix(13, 0xf00000);
           M5.dis.drawpix(16, 0xf00000);
           M5.dis.drawpix(18, 0xf00000);
           M5.dis.drawpix(21, 0xf00000);
           M5.dis.drawpix(22, 0xf00000);
           M5.dis.drawpix(23, 0xf00000);
}

void dis9()
{
           M5.dis.drawpix(1, 0xf00000);
           M5.dis.drawpix(2, 0xf00000);
           M5.dis.drawpix(3, 0xf00000);
           M5.dis.drawpix(6, 0xf00000);
           M5.dis.drawpix(8, 0xf00000);
           M5.dis.drawpix(11, 0xf00000);
           M5.dis.drawpix(12, 0xf00000);           
           M5.dis.drawpix(13, 0xf00000);
           M5.dis.drawpix(18, 0xf00000);
           M5.dis.drawpix(23, 0xf00000);          
}

void dis0()
{
           M5.dis.drawpix(1, 0xf00000);
           M5.dis.drawpix(2, 0xf00000);
           M5.dis.drawpix(3, 0xf00000);
           M5.dis.drawpix(6, 0xf00000);
           M5.dis.drawpix(8, 0xf00000);
           M5.dis.drawpix(11, 0xf00000);
           M5.dis.drawpix(13, 0xf00000);
           M5.dis.drawpix(16, 0xf00000);
           M5.dis.drawpix(18, 0xf00000);
           M5.dis.drawpix(21, 0xf00000);
           M5.dis.drawpix(22, 0xf00000);
           M5.dis.drawpix(23, 0xf00000);
      
}

void disF()
{
           M5.dis.drawpix(0, 0xf00000);    
           M5.dis.drawpix(2, 0xf00000);
           M5.dis.drawpix(3, 0xf00000);
           M5.dis.drawpix(4, 0xf00000);
           M5.dis.drawpix(7, 0xf00000);
           M5.dis.drawpix(12, 0xf00000);
           M5.dis.drawpix(13, 0xf00000);
           M5.dis.drawpix(14, 0xf00000);           
           M5.dis.drawpix(17, 0xf00000);
           M5.dis.drawpix(22, 0xf00000);     
}


void disC()
{
           M5.dis.drawpix(0, 0xf00000);
           M5.dis.drawpix(2, 0xf00000);
           M5.dis.drawpix(3, 0xf00000);
           M5.dis.drawpix(4, 0xf00000);
           M5.dis.drawpix(7, 0xf00000);
           M5.dis.drawpix(12, 0xf00000);
           M5.dis.drawpix(17, 0xf00000);           
           M5.dis.drawpix(22, 0xf00000);
           M5.dis.drawpix(23, 0xf00000);
           M5.dis.drawpix(24, 0xf00000);
}
 
void setup() 
{
   M5.begin(true, false, true);
   delay(20);



    if(!IMU6886Flag)
    IMU6886Flag = M5.IMU.Init() == 0;

    {
        Serial.println("Error initializing the IMU! :(");
    }
            M5.IMU.getTempData(&tempC);
            AverageTemp=tempC;

}



void calldisp(int opt)
{
  if (opt == 1)
    dis1();
  else if (opt == 2)
    dis2();
  else if (opt == 3)
    dis3();
  else if (opt == 4)
    dis4();
  else if(opt == 5)
    dis5();
  else if (opt == 6)
    dis6();
  else if (opt == 7)
    dis7();
  else if (opt == 8)
    dis8();
  else if (opt == 9)
    dis9();
  else if (opt == 0)
    dis0();
}


void dispunit(char u)
{
    if (u=='c')
        disC();
    else if (u=='f')
        disF();
}



void loop() 
{

    unsigned long CurrentTime=millis();
    if(IMU6886Flag)
    {
//c. In normal operation, the device is measuring temperature and recording it at a predetermined interval, and the
//screen displays nothing.
        //delay(500);
    if(CurrentTime - PreviousTime >= TimeInterval)
        {
        PreviousTime = CurrentTime;
        M5.IMU.getTempData(&tempC);
        Serial.printf(" Temp in C: %.2f C \r\n", tempC);
        tempF = tempC * 9 / 5 + 32;
        Serial.printf(" Temp in F : %.2f F \r\n", tempF);
        AverageTemp=(AverageTemp+tempC)/2;
        Serial.printf(" Average Temp : %.2f C \r\n", AverageTemp);  
        }
    }
  

//d. When holding the device in the hand with the screen facing relatively upwards, tapping the screen OR pressing the
//screen button activates the screen.

  if(M5.Btn.wasPressed()&& DeviceOff==true)
  {
   DeviceOff=false;
   M5.dis.fillpix(CRGB::Green);
   delay(1000);
   M5.dis.clear();
  


while(1)
{ ++tmpnum;
    unsigned long CurrentTime=millis();
    if(CurrentTime - PreviousTime >= 200)
    {
        PreviousTime = CurrentTime;
        Serial.printf("Gyro : %.2f, %.2f, %.2f \r\n", gyroX, gyroY, gyroZ);
        Serial.print(ModeCounter);
        M5.IMU.getTempData(&tempC);
        Serial.printf("\n Temp : %.2f C \r\n", tempC);
        avgtmp = (avgtmp+tempC)/tmpnum;
        tempF = tempC * 9 / 5 + 32;
        Serial.printf(" Temp : %.2f F \r\n", tempF);

    }
        M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);
        delay(200);
        
    if(menu==true)
    {
        if ((gyroY ) > minSens && (gyroY) < maxSens) 
        {
            ModeCounter++;
            Serial.printf("GYRO %.2f, \r\n ", gyroY, ModeCounter );
            delay(100);
        }
    
        switch (ModeCounter)
    {
        case 1: 
        {
        Serial.printf("case 1 execution\n" );
        M5.dis.clear ();
        dis1();
        M5.update();

        if (M5.Btn.wasPressed()) 
        {
        M5.update();
        bool pressed = true;
        M5.dis.clear ();

        if (unit=='c')
            temp = tempC;
        else if (unit == 'f')
            temp = tempF;

        int digits = int(log10(temp)+1); 
        int multiplier = pow(10,digits);
            
        while(pressed)
        {     
        multiplier = pow(10,digits);
        for(int i=0; i < digits; i++)
        {     
            Serial.print(i);

            multiplier /= 10;
            int num = ( temp / multiplier)%10;

            Serial.print("\n");
            Serial.print(digits );
            Serial.print("\n");
            Serial.print(temp );
            Serial.print("\n");
            Serial.print(num );
            Serial.print("\n");

            M5.dis.clear ();
            delay(100);
            calldisp(num);
            delay(1500);
        }

        M5.dis.clear ();
        dispunit(unit);
        delay(1500);

    //for while the button was pressed 
    
        //M5.update();
        M5.dis.clear();

        Serial.print("exit for");
        break;
        }
    //        
        if (M5.Btn.wasPressed())
        {pressed = false;}
        
        break;
        }
        break;

            }
            case 2:
            {
            Serial.printf("case 2 execution\n" );
            M5.dis.clear ();
            
            dis2();
            //delay(1000);
            M5.update();
            if (M5.Btn.wasPressed()) 
            {
            M5.update();
            bool pressed = true;
            M5.dis.clear ();
            delay(50);
            M5.update();

            temp = AverageTemp;

            if (unit == 'f')
                temp = tempF * 9 / 5 + 32;
            int digitsA = int(log10(temp)+1); 
            int multiplierA = pow(10,digitsA);
                
            while(pressed)
            {     
            multiplierA = pow(10,digitsA);
            for(int i=0; i < digitsA; i++)
            {     
                    Serial.print(i);

                    multiplierA /= 10;
                    int num = ( temp / multiplierA)%10;

                    Serial.print("\n");
                    Serial.print(digitsA );
                    Serial.print("\n");
                    Serial.print(temp );
                    Serial.print("\n");
                    Serial.print(num );
                    Serial.print("\n");

                    
                    M5.dis.clear ();
                    delay(100);
                    calldisp(num);
                    delay(1500);
            }
            M5.dis.clear ();
            dispunit(unit);
            delay(1500);

            break;
            }
    
            break;
            
            if (M5.Btn.wasPressed())
            {pressed = false;}
            }
            break;
            }
            
            break; 
            
            }

            if(ModeCounter>5 || ModeCounter <0)
                ModeCounter=1;
            
        }
    }          
      
  }
  
  M5.update();
}
