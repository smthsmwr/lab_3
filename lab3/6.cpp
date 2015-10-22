#include "sdt.h"
#include "convert.h"
int main()
{
    double t;
    char s;
    vector<double> temp;
    vector<char> name;
    cout << "Input the temperature: 10F-Fahrenheit,10C-Celsius,10K-Kelvin: ";
    while (cin>>t>>s)
    {   try
        {
          temp.push_back(convert(t,s,'C'));
          temp.push_back(convert(t,s,'F'));
          temp.push_back(convert(t,s,'K'));
        }
     catch (const invalid_argument& e)
			{
				cerr << e.what() << "\n";
			}
     catch (const logic_error& le)
			{
				cerr << le.what() << "\n";
			}
     catch (...)
			{
				cerr << "Unknown error! Try again! \n";
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
