#include <iostream>
#include <ctime>

using namespace std;

void solution(int days, int DD, int MM, int YYYY);

int main(int argc, char const *argv[])
{
    int days(0), DD(0), MM(0), YYYY(0);

    while (cin >> days && cin >> DD && cin >> MM && cin >> YYYY &&
          !(days == 0 && DD == 0 && MM == 0 && YYYY == 0))
        solution(days, DD, MM, YYYY);

    return 0;
}

void solution(int days, int DD, int MM, int YYYY)
{
    struct tm date = {0};
    time_t next;

    date.tm_mday  = DD;
    date.tm_mon   = MM - 1;
    date.tm_year  = YYYY - 1900;

    date.tm_mday += days;
    mktime(&date);

    cout << date.tm_mday            << " " 
         << date.tm_mon + 1         << " " 
         << date.tm_year + 1900     << endl;
}
