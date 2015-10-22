//------------------------------------------------------------------------------
//convert.h
//------------------------------------------------------------------------------
enum Scale
 {
   Kelvin,
   Celsius,
   Fahrenheit
 };
double convert(double t, Scale from, Scale to);
Scale to_scale(char s); //функция, конвертирующая введённое значение в шкалу Scale
