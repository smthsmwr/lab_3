//------------------------------------------------------------------------------
//convert.h
//------------------------------------------------------------------------------
enum Scale
 {
   Kelvin='K',
   Celsius='C',
   Fahrenheit='F'
 };

struct Temperature //�������� ���������
{ Temperature(double value,char scale);
   Temperature();
  double value;
  char scale;
};
Temperature convert(Temperature t,char to);

