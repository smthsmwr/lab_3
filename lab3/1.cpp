#include "sdt.h"
double convert(double t, char from, char to)
{   double K;
    if (to==from) return t;
    switch (from)
    {
    case 'K':
    case 'k': K=t;
              break;
    case 'C':
    case 'c': K=t+273.15;
              break;
    case 'F':
    case 'f': K=(5*(t-32))/9+273.15;
              break;
    default: cout <<"Incorrect nomination of scale! Try again! \n";
    }
    if (K<0)
        {cout <<"Too low temperature!\n";
         return 0;
        }
    if (K>=0)
    {  switch (to)
      {
        case 'C':
        case 'c': return (K-273.15);

        case 'F':
        case 'f': return ((9*(K-273.15))/5+32);

        case 'K':
        case 'k': return K;
        default: cout <<"Incorrect nomination of scale! Try again! \n";
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
        //if (!cin) break;
            temp.push_back(convert(t,s,'C'));
            temp.push_back(convert(t,s,'K'));
            temp.push_back(convert(t,s,'F'));
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
