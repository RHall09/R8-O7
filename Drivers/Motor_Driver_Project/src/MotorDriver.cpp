/** @file MotorDriver.h
 * 
 * 
 * 
 *  @author Rick Hall
 *  @date 2020-4-Nov
 */

#include <Arduino.h>
#include <MotorDriver.h>
#include <RegOperators.h>

MotorDriver::MotorDriver(int Pin_En_A, int Pin_Mot_A1, int Pin_Mot_A2, 
            int Pin_En_B, int Pin_Mot_B1, int Pin_Mot_B2, 
            Mot_Orient mot_or = mA_B,
            Mot_Pinout mot_A_pin = p1_2,
            Mot_Pinout mot_B_pin = p1_2 )
{
    // Set up flag register
    mot_flag = 0;

    // If incorrect input of flag position, exit constructor
    if (mot_or == mTog || mot_A_pin == pTog || mot_B_pin == pTog)
    {
        return;
    }
    else
    {
        // If any flag not default, set it
        if (mot_or = mB_A)
        {
            bit_set(f_MotAB);
        }
        if (mot_A_pin = p2_1)
        {
            bit_set(f_MotAp);
        }
        if (mot_B_pin = p2_1)
        {
            bit_set(f_MotBp);
        }

        // Store pins in pin array
        mot_pins[0] = Pin_En_A;
        mot_pins[1] = Pin_Mot_A1;
        mot_pins[2] = Pin_Mot_A2;
        mot_pins[3] = Pin_En_B;
        mot_pins[4] = Pin_Mot_B1;
        mot_pins[5] = Pin_Mot_B2;    

        // Set pins to output mode & confirm pins set low
        pinMode(PinEnA, OUTPUT);
        digitalWrite(PinEnA, LOW);
        pinMode(PinA1, OUTPUT);
        digitalWrite(PinA1, LOW);
        pinMode(PinA2, OUTPUT);
        digitalWrite(PinA2, LOW);
        pinMode(PinEnB, OUTPUT);
        digitalWrite(PinEnB, LOW);
        pinMode(PinB1, OUTPUT);
        digitalWrite(PinB1, LOW);
        pinMode(PinB2, OUTPUT);
        digitalWrite(PinB2, LOW);
    }

    bit_set(f_MotCreated);
}

//Enable Motors
void MotorDriver::enable(Mot_Select motor)
{
    if ( (motor = mAB) | (motor = mA) )
    {
        digitalWrite(PinEnA, HIGH);
        bit_set(f_EnMotA);
    }

    if ( (motor = mAB) | (motor = mB) )
    {
        digitalWrite(PinEnB, HIGH);
        bit_set(f_EnMotB);
    }
}
//Disable Motors
void MotorDriver::disable(Mot_Select motor)
{
    if ( (motor = mAB) | (motor = mA) )
    {
        digitalWrite(PinEnA, LOW);
        bit_clr(f_EnMotA);
    }

    if ( (motor = mAB) | (motor = mB) )
    {
        digitalWrite(PinEnB, LOW);
        bit_clr(f_EnMotB);
    }
}
//Set both motor behaviors with PWM %s
void MotorDriver::set(int8_t pwmA, int8_t pwmB)
{
    // Find absolute PWM values (pwmA and pwmB can be negative)
    uint8_t AbsPwmA = abs(pwmA);
    uint8_t AbsPwmB = abs(pwmB);

    // Set Motor A:
    if( 0 < pwmA < 100 )
    {
        digitalWrite(PinA2, LOW);
        analogWrite(PinA1, AbsPwmA);
    }
    else if( -100 < pwmA < 0 )
    {
        digitalWrite(PinA1, LOW);
        analogWrite(PinA2, AbsPwmA);
    }
    else
    {
        digitalWrite(PinA1, LOW);
        digitalWrite(PinA2, LOW);
    }

    // Set Motor B:
    if( 0 < pwmB < 100 )
    {
        digitalWrite(PinB2, LOW);
        analogWrite(PinB1, AbsPwmB);
    }
    else if( -100 < pwmB < 0 )
    {
        digitalWrite(PinB1, LOW);
        analogWrite(PinB2, AbsPwmB);
    }
    else
    {
        digitalWrite(PinB1, LOW);
        digitalWrite(PinB2, LOW);
    }


}
//Set individual motor behavior with PWM %s
void MotorDriver::set(Mot_Select motor, int8_t pwm)
{
    uint8_t AbsPwm = abs(pwm);

    // If motor A:
    if ( motor = mA )
    {
        if( 0 < pwm < 100 )
        {
            digitalWrite(PinA2, LOW);
            analogWrite(PinA1, AbsPwm);
        }
        else if( -100 < pwm < 0 )
        {
            digitalWrite(PinA1, LOW);
            analogWrite(PinA2, AbsPwm);
        }
        else
        {
            digitalWrite(PinA1, LOW);
            digitalWrite(PinA2, LOW);
        }
    }

    // If motor B:
    else if ( motor = mB )
    {
        if( 0 < pwm < 100 )
        {
            digitalWrite(PinB2, LOW);
            analogWrite(PinB1, AbsPwm);
        }
        else if( -100 < pwm < 0 )
        {
            digitalWrite(PinB1, LOW);
            analogWrite(PinB2, AbsPwm);
        }
        else
        {
            digitalWrite(PinB1, LOW);
            digitalWrite(PinB2, LOW);
        }
    }

    // If both:
    else
    {
        if( 0 < pwm < 100 )
        {
            digitalWrite(PinA2, LOW);
            digitalWrite(PinB2, LOW);
            analogWrite(PinA1, AbsPwm);
            analogWrite(PinB1, AbsPwm);
        }
        else if( -100 < pwm < 0 )
        {
            digitalWrite(PinA1, LOW);
            digitalWrite(PinB1, LOW);
            analogWrite(PinA2, AbsPwm);
            analogWrite(PinB2, AbsPwm);
        }
        else
        {
            digitalWrite(PinA1, LOW);
            digitalWrite(PinB1, LOW);
            digitalWrite(PinB1, LOW);
            digitalWrite(PinB2, LOW);
        }
    }
}
//Stop motors
void MotorDriver::stop(Mot_Select motor = mAB)
{
    // If motor A:
    if ( motor = mA )
    {
            digitalWrite(PinA1, LOW);
        digitalWrite(PinA2, LOW);
    }

    // If motor B:
    else if ( motor = mB )
    {
        digitalWrite(PinB1, LOW);
        digitalWrite(PinB2, LOW);
    }

    // If both:
    else
    {
        digitalWrite(PinA1, LOW);
        digitalWrite(PinB1, LOW);
        digitalWrite(PinB1, LOW);
        digitalWrite(PinB2, LOW);
    }
}

//Set/toggle motor orientation
void MotorDriver::setOrient(Mot_Orient motor_orient = mTog)
{
    if (motor_orient = mTog)
    {
        bit_tog(f_MotAB);
    }
    else if (motor_orient = mA_B)
    {
        bit_clr(f_MotAB);
    }
    else
    {
        bit_set(f_MotAB);
    }
}
//Set/toggle pin orientation
void MotorDriver::setPinout(Mot_Select motor, Mot_Pinout motor_pin_orient = pTog)
{
    if ( motor = mA )
    {
        if (motor_pin_orient = pTog)
        {
            bit_tog(f_MotAp);
        }
        else if (motor_pin_orient = p1_2)
        {
            bit_clr(f_MotAp);
        }
        else
        {
            bit_set(f_MotAp);
        }
    }
    else if ( motor = mB )
    {
        if (motor_pin_orient = pTog)
        {
            bit_tog(f_MotBp);
        }
        else if (motor_pin_orient = p1_2)
        {
            bit_clr(f_MotBp);
        }
        else
        {
            bit_set(f_MotBp);
        }    
    }
    else
    {
        if (motor_pin_orient = pTog)
        {
            bit_tog(f_MotAp);
            bit_tog(f_MotBp);
        }
        else if (motor_pin_orient = p1_2)
        {
            bit_clr(f_MotAp);
            bit_clr(f_MotBp);
        }
        else
        {
            bit_set(f_MotAp);
            bit_set(f_MotBp);
        }
    }

}



//Set error-overcurrent flag
void MotorDriver::setOvercurrent(Mot_Select motor)
{


}

//Clear error-overcurrent flag
void MotorDriver::clearOvercurrent(Mot_Select motor)
{


}

//Check Flag Register
uint8_t MotorDriver::getMotFlagReg(void)
{
    return mot_flag;
}

//Check Flag Bit
bool MotorDriver::checkMotFlag(Mot_Flags flag)
{



}




