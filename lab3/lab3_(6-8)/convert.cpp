#include "sdt.h"
#include "convert.h"
Scale to_scale(char s)
{   switch (s)
      {case 'c':
       case 'C': return Celsius; break;
       case 'F':
       case 'f': return Fahrenheit; break;
       case 'K':
       case 'k': return Kelvin; break;
       default: throw invalid_argument("Incorrect nomination of scale! Try again!\n");
       }
}
double convert(double t, Scale from, Scale to)
 {  double K;

    if (to==from) return t;
    switch (from)
    {
    case Kelvin: K=t; break;
    case Celsius: K=t+273.15; break;
    case Fahrenheit: K=(5*(t-32))/9+273.15; break;
    default: throw invalid_argument("Incorrect nomination of scale! Try again!\n");
    }
    if (K<0) throw logic_error("Too low temperature!\n");

    if (K>=0)
    {  switch (to)
      {
        case Celsius: return (K-273.15); break;
        case Fahrenheit: return ((9*(K-273.15))/5+32); break;
        case Kelvin: return K; break;
        default: throw invalid_argument("Incorrect nomination of scale! Try again!\n");
      }
    }
    throw exception();
}
