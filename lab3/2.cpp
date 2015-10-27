#include "sdt.h"
enum Error {     //перечисление для ошибок
	NoError,    //Нет ошибок
	ErrTemp,   //Ошибка в значении температуры (<0K)
	ErrScale  //Неизвестная шкала from или to
};
Error convert(double t, char from, char to, double& result)
{   double K;
    if (to==from) result=t;
    switch (from)
    {
    case 'k':
    case 'K': K=t;
              break;
    case 'C':
    case 'c': K=t+273.15;
              break;
    case 'F':
    case 'f': K=(5*(t-32))/9+273.15;
              break;
    default: return ErrScale;
    }
    if (K<0) return ErrTemp;
    else if (K>=0)
    {  switch (to)
      {
        case 'C':
        case 'c': result=(K-273.15); return NoError; break;

        case 'F':
        case 'f': result=((9*(K-273.15))/5+32); return NoError; break;

        case 'K':
        case 'k': result=K; return NoError; break;
        default:  return ErrScale;
      }
    }
}

int main()
{
    double t,K,C,F;
    char s;
    vector<double> temp;
    vector<char> name;
    cout << "Input the temperature: 10F-Fahrenheit,10C-Celsius,10K-Kelvin: ";
    while (cin>>t>>s)
    {
        switch (convert(t,s,'K',K))
        { case ErrScale: cout <<"Incorrect nomination of scale! Try again! \n";
                  break;
          case ErrTemp: cout <<"Too low temperature!\n";
                  break;
          case NoError:
            convert(t,s,'C',C);
            temp.push_back(C);
            temp.push_back(K);
            convert(t,s,'F',F);
            temp.push_back(F);
            break;

        }
      cout << "Input the temperature: 10F-Fahrenheit,10C-Celsius,10K-Kelvin: ";
    }
    cout <<"C \t" <<"K \t" <<"F \t \n";
    for (int i = 0; i < temp.size(); ++i)
    {
        printf("%4.2f\t", temp[i]);
        if ((i+1)%3==0) cout <<"\n";
    }
}
