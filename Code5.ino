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

void heightconvert(int height, int push)
{
    if (height == 1)
    {
       M5.dis.drawpix(24-push,0x000080); 
    }
    else if (height == 2)
    {
       M5.dis.drawpix(19-push,0x000080);
       M5.dis.drawpix(24-push,0x000080); 
    }
    else if (height == 3)
    {
       M5.dis.drawpix(14-push,0x000080);
       M5.dis.drawpix(19-push,0x000080);
       M5.dis.drawpix(24-push,0x000080);  
    }
    else if (height == 4)
    {
       M5.dis.drawpix(9-push,0x000080);
       M5.dis.drawpix(14-push,0x000080);
       M5.dis.drawpix(19-push,0x000080);
       M5.dis.drawpix(24-push,0x000080); 
    }
    else if (height == 5)
    {
       M5.dis.drawpix(4-push,0x000080);
       M5.dis.drawpix(9-push,0x000080);
       M5.dis.drawpix(14-push,0x000080);
       M5.dis.drawpix(19-push,0x000080);
       M5.dis.drawpix(24-push,0x000080);  
    }
    else {}
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
            
            case 3:
            {
            
            Serial.printf("case 3 execution\n" );
            M5.dis.clear ();
            dis3();
            M5.update();

            if (M5.Btn.wasPressed()) 
            {
                bool pressed = true;
                M5.dis.clear ();
                delay(50);
                M5.update();
                    
                while(pressed)
                {   
                    M5.update();  
                    M5.IMU.getTempData(&tempC); 
                    Serial.printf("\n Temp : %.2f C \r\n", tempC);

                    M5.dis.drawpix(0, 0x000080); //Blue
                    M5.dis.drawpix(5, 0x008000); //Red
                    M5.dis.drawpix(10,0xFFA500); //Orange
                    M5.dis.drawpix(15,0xFFFF00); //Yellow
                    M5.dis.drawpix(20,0xFF0000); //Green
                    
                    unsigned long CurrentTime=millis();
                    if(CurrentTime - PreviousTime >= TimeInterval)
                    {   
                        Serial.print("\n not always xxxxxxx");
                        PreviousTime = CurrentTime;

                    if (tempC<35)
                    {
                    M5.dis.drawpix(1,0xFF0000);
                    M5.dis.drawpix(2,0xFF0000);
                    M5.dis.drawpix(3,0xFF0000);
                    M5.dis.drawpix(4,0xFF0000);
                    M5.dis.drawpix(6,0xFF0000);
                    M5.dis.drawpix(7,0xFF0000);
                    M5.dis.drawpix(8,0xFF0000);
                    M5.dis.drawpix(9,0xFF0000);
                    M5.dis.drawpix(11,0xFF0000);
                    M5.dis.drawpix(12,0xFF0000);
                    M5.dis.drawpix(13,0xFF0000);
                    M5.dis.drawpix(14,0xFF0000);
                    M5.dis.drawpix(16,0xFF0000);
                    M5.dis.drawpix(17,0xFF0000);
                    M5.dis.drawpix(18,0xFF0000);
                    M5.dis.drawpix(19,0xFF0000);
                    M5.dis.drawpix(21,0xFF0000);
                    M5.dis.drawpix(22,0xFF0000);
                    M5.dis.drawpix(23,0xFF0000);
                    M5.dis.drawpix(24,0xFF0000);
                    }

                    if (tempC>=35 && tempC<36)
                    {
                    M5.dis.drawpix(1,0xFFFF00);
                    M5.dis.drawpix(2,0xFFFF00);
                    M5.dis.drawpix(3,0xFFFF00);
                    M5.dis.drawpix(4,0xFFFF00);
                    M5.dis.drawpix(6,0xFFFF00);
                    M5.dis.drawpix(7,0xFFFF00);
                    M5.dis.drawpix(8,0xFFFF00);
                    M5.dis.drawpix(9,0xFFFF00);
                    M5.dis.drawpix(11,0xFFFF00);
                    M5.dis.drawpix(12,0xFFFF00);
                    M5.dis.drawpix(13,0xFFFF00);
                    M5.dis.drawpix(14,0xFFFF00);
                    M5.dis.drawpix(16,0xFFFF00);
                    M5.dis.drawpix(17,0xFFFF00);
                    M5.dis.drawpix(18,0xFFFF00);
                    M5.dis.drawpix(19,0xFFFF00);
                    M5.dis.drawpix(21,0xFFFF00);
                    M5.dis.drawpix(22,0xFFFF00);
                    M5.dis.drawpix(23,0xFFFF00);
                    M5.dis.drawpix(24,0xFFFF00);
                    }


                    if (tempC>=36 && tempC<37)
                    {
                    M5.dis.drawpix(1,0xFFA500);
                    M5.dis.drawpix(2,0xFFA500);
                    M5.dis.drawpix(3,0xFFA500);
                    M5.dis.drawpix(4,0xFFA500);
                    M5.dis.drawpix(6,0xFFA500);
                    M5.dis.drawpix(7,0xFFA500);
                    M5.dis.drawpix(8,0xFFA500);
                    M5.dis.drawpix(9,0xFFA500);
                    M5.dis.drawpix(11,0xFFA500);
                    M5.dis.drawpix(12,0xFFA500);
                    M5.dis.drawpix(13,0xFFA500);
                    M5.dis.drawpix(14,0xFFA500);
                    M5.dis.drawpix(16,0xFFA500);
                    M5.dis.drawpix(17,0xFFA500);
                    M5.dis.drawpix(18,0xFFA500);
                    M5.dis.drawpix(19,0xFFA500);
                    M5.dis.drawpix(21,0xFFA500);
                    M5.dis.drawpix(22,0xFFA500);
                    M5.dis.drawpix(23,0xFFA500);
                    M5.dis.drawpix(24,0xFFA500);
                    }

                    if (tempC>=37 && tempC<38)
                    {
                    M5.dis.drawpix(1,0x008000);
                    M5.dis.drawpix(2,0x008000);
                    M5.dis.drawpix(3,0x008000);
                    M5.dis.drawpix(4,0x008000);
                    M5.dis.drawpix(6,0x008000);
                    M5.dis.drawpix(7,0x008000);
                    M5.dis.drawpix(8,0x008000);
                    M5.dis.drawpix(9,0x008000);
                    M5.dis.drawpix(11,0x008000);
                    M5.dis.drawpix(12,0x008000);
                    M5.dis.drawpix(13,0x008000);
                    M5.dis.drawpix(14,0x008000);
                    M5.dis.drawpix(16,0x008000);
                    M5.dis.drawpix(17,0x008000);
                    M5.dis.drawpix(18,0x008000);
                    M5.dis.drawpix(19,0x008000);
                    M5.dis.drawpix(21,0x008000);
                    M5.dis.drawpix(22,0x008000);
                    M5.dis.drawpix(23,0x008000);
                    M5.dis.drawpix(24,0x008000);
                    }


                    
                    if (tempC>=38)
                    {
                    M5.dis.drawpix(1,0x000080);
                    M5.dis.drawpix(2,0x000080);
                    M5.dis.drawpix(3,0x000080);
                    M5.dis.drawpix(4,0x000080);
                    M5.dis.drawpix(6,0x000080);
                    M5.dis.drawpix(7,0x000080);
                    M5.dis.drawpix(8,0x000080);
                    M5.dis.drawpix(9,0x000080);
                    M5.dis.drawpix(11,0x000080);
                    M5.dis.drawpix(12,0x000080);
                    M5.dis.drawpix(13,0x000080);
                    M5.dis.drawpix(14,0x000080);
                    M5.dis.drawpix(16,0x000080);
                    M5.dis.drawpix(17,0x000080);
                    M5.dis.drawpix(18,0x000080);
                    M5.dis.drawpix(19,0x000080);
                    M5.dis.drawpix(21,0x000080);
                    M5.dis.drawpix(22,0x000080);
                    M5.dis.drawpix(23,0x000080);
                    M5.dis.drawpix(24,0x000080);
                    }

                    }

                Serial.print(" button test\n ");
                if (M5.Btn.wasPressed())
                {pressed = false;}
                }
                M5.update();
            
            }
            break;
        }    

            
            case 4:
            {
            Serial.printf("case 4 execution\n" );
            M5.dis.clear ();
            dis4();

            
             M5.update();
            if (M5.Btn.wasPressed()) 
            {
                bool pressed = true;
                M5.dis.clear ();
                delay(50);
                M5.update();

                int tempdat[5] = {3,3,3,3,3};
                int push = 0;
                float initemp = tempC;
                float change;
                int shift = 0;
                    
                while(pressed)
                {     
                    //M5.dis.clear ();  
                    M5.update();  
                    M5.IMU.getTempData(&tempC); 
                    //Serial.printf("\n Temp : %.2f C \r\n", tempC);
                    
                    change = initemp - tempC;
                    
                    unsigned long CurrentTime=millis();
                    if(CurrentTime - PreviousTime >= 700)
                    {   
                        M5.dis.clear();
                        Serial.print(shift);

                        //Serial.print(change);
                        Serial.print("\n");

                        for(int i = 0; i<5; i++)
                        {
                        Serial.print(tempdat[i]);
                        }
                        Serial.print("\n");

                        PreviousTime = CurrentTime;
                        initemp = tempC;

                        for(int i = 4; i>=0; --i)
                        {
                            heightconvert(tempdat[i], 4-i); 
                            //Serial.print(push);
                        }  
                                                    Serial.print("\n");
                        M5.update();

                        if (change < 0.01)
                            shift = 0;
                        else if (change >= 0.01 && change < 0.03)
                            shift = -1;
                        else if (change >= 0.03 && change < 0.05)
                            shift = -2;
                        else if (change >= 0.05)
                            shift = -3;
                        if (change <= -0.01 && change > -0.03)
                            shift = 1;
                        else if (change <= -0.03 && change > -0.05)
                            shift = 2;
                        else if (change <= -0.05)
                            shift = 3;

                        
                            for(int i = 0; i<4; i++)
                            {
                                tempdat[i] = tempdat[i+1];
                            }
                            for(int i = 0; i<4; i++)
                            {
                                tempdat[i] += shift;
                                
                                if (tempdat[i] < 0)
                                    tempdat[i] = 0;
                                else if (tempdat[i] > 5)
                                    tempdat[i] = 5;
                            }
                            tempdat[4] = 3;

                        //delay(300);
                        //M5.update();
                    }

                     //Serial.print(shift);
                        // Serial.print("\n not always xxxxxxx");
                        // Serial.print("\n not always xxxxxxx");
                        // Serial.print("\n not always xxxxxxx");
                        // Serial.print("\n not always xxxxxxx");
                                    
                    
                    //Serial.print(" button test\n ");   
                    if (M5.Btn.wasPressed())
                    {
                        pressed = false;   
                        M5.update();
                    }          
                }
            
            }
            //delay(1000);
             
            break;
            }

           
            case 5:
            {
            Serial.printf("case 5 execution\n" );
            M5.dis.clear ();
            dis5();

           M5.update();
            if (M5.Btn.wasPressed()) 
            {
                bool pressed = true;
                M5.dis.clear ();
                delay(50);
                M5.update();

                
                while(pressed)
                {     

                    M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);
                    delay(200);

                    if ((gyroY ) > minSens && (gyroY) < maxSens) 
                    {
                        ++turn;
                        turn = turn%2;  // Turn switches between modes 0 and 1 (C and F)
                        Serial.printf("GYRO %.2f, \r\n ", gyroY, ModeCounter );
                    M5.dis.clear ();    
                    }

                    if (turn == 0)  //For C
                    {
                       
                        disC();
                         M5.update(); 
                        if (M5.Btn.wasPressed())
                        {
                            pressed = false;
                            unit = 'c';
                            M5.update();
                            break;   
                        }          
                    }
                    if (turn == 1)
                    {
                        disF();
                        M5.update(); 
                        if (M5.Btn.wasPressed())
                        {
                            pressed = false;
                            unit = 'f';
                            M5.update();
                            break;
                        } 
                    }                   
                    
                    Serial.print(" button test\n ");   
                    }
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
