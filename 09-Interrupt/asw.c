#include "bsw.h"

ISR(ISRPin2)
{
    digitalWrite(13, HIGH);
}


ISR(ISRPin3)
{
    digitalWrite(13, LOW);
}