#include "sdt.h"
#include "convert.h"
int main()
{ vector<Temperature> temp;
  Temperature input;
  input=Temperature();
  cout << "Input the temperature: 10F-Fahrenheit,10C-Celsius,10K-Kelvin: ";
    while (cin >>input.value >>input.scale)
    {   if (!cin) break;
        cout << "Input the temperature: 10F-Fahrenheit,10C-Celsius,10K-Kelvin: ";
        try
        {
          temp.push_back(convert(input,'C'));
          temp.push_back(convert(input,'K'));
          temp.push_back(convert(input,'F'));
        }
     catch (const invalid_argument& e)
			{
				cerr << e.what() << "\n";
			}
     catch (const logic_error& le)
			{
				cerr << le.what() << "\n";
			}
    catch (const invalid_argument& le)
			{
				cerr << le.what() << "\n";
			}
     catch (...)
			{
				cerr << "Unknown error! Try again! \n";
			}
        }


    cout <<"C \t" <<"K \t" <<"F \t \n";
    for (int i = 0; i < (temp.size()); ++i)
    {
        printf("%4.2f\t", temp[i]);
        if ((i+1)%3==0) cout <<"\n";
    }
}
