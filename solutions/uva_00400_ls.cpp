#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}

void solution(int N);

int main(int argc, char const *argv[])
{
    int N(0);

    while (cin >> N)
    {
        cin.ignore();
        solution(N);
    }

    return 0;
}

void solution(int N)
{
    vector<string> file_names(N), ls;
    string file_name("");
    int index(N), max_size(0), nb_columns(0), nb_rows(0), nb_spaces(0);

    //
    // Build and sort the vector of file names
    //
    while (index--)
    {
        getline(cin, file_name);
        max_size = max(max_size, file_name.size());
        file_names[N-index-1] = file_name;
    }
    sort(file_names.begin(), file_names.end());

    //
    // Printing
    //
    nb_columns = 62 / (max_size + 2);
    nb_rows = (N % nb_columns == 0) ? N / nb_columns: N / nb_columns + 1;
    cout << "------------------------------------------------------------" << endl;
    for (int i = 0; i < nb_rows; ++i)
    {
        for (int j = 0; j < nb_columns; ++j)
        {
            index = j * nb_rows + i;
            if (index < N)
                cout << left << setw(max_size + 2) << file_names[index];
            else
                break;
        }
        cout << endl;
    }
}
