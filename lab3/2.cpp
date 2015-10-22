#include "sdt.h"
int convert(double t, char from, char to)
{   double K,t1;
    if (to==from) return t;
    switch (from)
    {
    case 'k': K=t;
              break;
    case 'K': K=t;
              break;
    case 'C': K=t+273.15;
              break;
    case 'c': K=t+273.15;
              break;
    case 'F': K=(5*(t-32))/9+273.15;
              break;
    case 'f': K=(5*(t-32))/9+273.15;
              break;
    default: return 1;
    }
    if (K<0) return 2;

    if (K>=0)
    {  switch (to)
      {
        case 'C': return (K-273.15); break;
        case 'c': return (K-273.15); break;

        case 'F': return ((9*(K-273.15))/5+32); break;
        case 'f': return ((9*(K-273.15))/5+32); break;

        case 'K': return K; break;
        case 'k': return K; break;
        default: return 1;
      }
    }
}

int main()
{
    double t;
    char s;
    vector<double> temp;
    vector<char> name;
    cout << "Input the temperature: 10F-Fahrenheit,10C-Celsius,10K-Kelvin: ";
    while (cin>>t>>s)
    {
        switch (convert(t,s,'K'))
        { case 1: cout <<"Incorrect nomination of scale! Try again! \n";
                  break;
          case 2: cout <<"Too low temperature!\n";
                  break;
          default:
            temp.push_back(convert(t,s,'C'));
            temp.push_back(convert(t,s,'K'));
            temp.push_back(convert(t,s,'F'));
        }
      cout << "Input the temperature: 10F-Fahrenheit,10C-Celsius,10K-Kelvin: ";
    }
    cout <<"C \t" <<"K \t" <<"F \t \n";
    for (int i = 0; i < temp.size(); ++i)
    {
        printf("%4.2f\t", temp[i]);
        if ((i+1)%3==0) cout <<"\n";
    }
    return 0;
}
