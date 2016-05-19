#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void solution(int n);
int nb_digit(int n);

int main(int argc, char const *argv[])
{
    int n(0), caseNo(1);

    while (cin >> n && n != 0)
    {
        cout << "Case " << caseNo++ << ":" << endl;
        solution(n);
    }

    return 0;
}

void solution(int n)
{
    int sum(0), number(0), i(n), a(0), b(0), c(0);
    bool positive(true);
    string line1(""), line2(""), line3("");

    while (i--)
    {
        cin >> number;
        sum += number;
    }

    a = sum / n;
    positive = (sum >= 0);
    a = abs(a);
    sum = abs(sum);

    // if avg is an integer
    if (a == (double)sum / n)
    {
        if (!positive)
            cout << "- ";
        cout << a << endl;
    }
    // if avg is a rational
    else
    {
        b = sum - n * a;
        c = n;

        for (i = 2; i <= b; ++i)
        {
            while (b % i == 0 && c % i == 0)
            {
                c /= i;
                b /= i;
            }
        }

        if (!positive)
        {
            line1 += "  ";
            line2 += "- ";
            line3 += "  ";
        }
        if (a)
        {
            for (i = 0; i < nb_digit(a); ++i)
            {
                line1 += " ";
                line3 += " ";
            }
            line2 += to_string(a);
        }

        for (i = 0; i < nb_digit(c) - nb_digit(b); ++i)
            line1 += " ";
        line1 += to_string(b);
        for (i = 0; i < nb_digit(c); ++i)
            line2 += "-";
        line3 += to_string(c);

        cout << line1 << endl;
        cout << line2 << endl;
        cout << line3 << endl;
    }
}

int nb_digit(int n)
{
    int res(1);
    while (n /= 10)
        res++;
    return res;
}
