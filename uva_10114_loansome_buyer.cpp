#include <iostream>
#include <vector>

using namespace std;

void solution(int months, double down_payment, double left_to_pay, int drops);

int main(int argc, char const *argv[])
{
    int months, drops;
    double left_to_pay, down_payment;

    while (cin >> months && months > 0 &&
           cin >> down_payment &&
           cin >> left_to_pay &&
           cin >> drops)
    {
        solution(months, down_payment, left_to_pay, drops);
    }

    return 0;
}

void solution(int months, double down_payment, double left_to_pay, int drops)
{
    int res(0), i(drops);
    vector< pair<int, double> > rates(drops);
    int m; double d;

    double value(left_to_pay + down_payment);
    double payment(left_to_pay / months);
    double new_value(left_to_pay + down_payment);
    double current_rate(0);
    int current_drop(1);

    bool print(false);

    while (i--)
    {
        cin >> m >> d;
        rates[drops-i-1] = make_pair(m, d);
    }

    if (print)
    {
        cout << "INITIAL SITUATION ------------------------------" << endl;
        cout << "   value       = " << new_value    << endl;
        cout << "   left_to_pay = " << left_to_pay  << endl;
        cout << "   payment     = " << payment      << endl;
    }

    current_rate = rates[0].second;
    new_value *= (1 - current_rate);

    if (print)
    {
        cout << "LEAVING DEALER ---------------------------------" << endl;
        cout << "   value       = " << new_value    << endl;
        cout << "   left_to_pay = " << left_to_pay  << endl;
    }

    while (new_value < left_to_pay)
    {
        res++;
        
        if (current_drop < drops && res == rates[current_drop].first)
        {
            current_rate = rates[current_drop].second;
            current_drop++;
        }

        new_value *= (1 - current_rate);
        left_to_pay -= payment;


        if (print)
        {
            cout << "CURRENT SITUATION ------------------------------" << endl;
            cout << "   value        = " << new_value     << endl;
            cout << "   left_to_pay  = " << left_to_pay   << endl;
            cout << "   current_rate = " << current_rate  << endl;
            cout << "   current_drop = " << current_drop  << endl;
            cout << "   res          = " << res           << endl;
        }
    }

    if (res == 1)
        cout << "1 month" << endl;
    else
        cout << res << " months" << endl;
}
