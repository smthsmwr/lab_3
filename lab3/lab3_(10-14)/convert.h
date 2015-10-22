//------------------------------------------------------------------------------
//convert.h
// ������������ ���� � ������������.
//------------------------------------------------------------------------------
#include "sdt.h"
enum Scale //�������� ������������
 {
   Kelvin='K',
   Celsius='C',
   Fahrenheit='F'
 };

struct Temperature //�������� ���������
{  Temperature(double value,Scale scale);
   Temperature();
   const Temperature& operator+(const Temperature& scale1) const;
   const Temperature& operator/(int d) const;
   bool operator<(const Temperature &scale1) const;
   Temperature& operator+=(const Temperature& scale1);
   Temperature& operator/=(int d);
   double value;
   Scale scale;
};
Temperature convert(Temperature t,Scale to); //���������� ������� �����������

istream& operator>>(istream& in, Temperature& t);//���������� ������� �����.�����
ostream& operator<<(ostream& out, const Temperature& t); //���������� ������� �����.������

istream& operator>>(istream& in, Scale& s);
ostream& operator<<(ostream& out, const Scale& s);

Temperature max_temp(vector<Temperature> temp);
Temperature mid_temp(vector<Temperature> temp);




