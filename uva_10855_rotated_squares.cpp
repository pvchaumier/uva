#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution(int N, int n);
vector<int> count_presence(vector< vector<char> > big, vector< vector<char> > small);

int main(int argc, char const *argv[])
{
    int N, n;

    while (cin >> N && cin >> n && !(N == 0 && n ==0))
    {
        solution(N, n);
    }

    return 0;
}

void solution(int N, int n)
{
    vector< vector<char> > big(N), small(n);
    string line;
    cin.ignore();
    int i;

    i = N;
    while (i--)
    {
        getline(cin, line);
        for (auto x: line)
            big[N-i-1].push_back(x);
    }

    i = n;
    while (i--)
    {
        getline(cin, line);
        for (auto x: line)
            small[n-i-1].push_back(x);
    }

    vector<int> res(count_presence(big, small));

    cout << res[0] << " ";
    cout << res[1] << " ";
    cout << res[2] << " ";
    cout << res[3] << endl;
}

vector<int> count_presence(vector< vector<char> > big, vector< vector<char> > small)
{
    vector<int> res(4, 0);
    int N(big.size()), n(small.size());
    bool b(true), b90(true), b180(true), b270(true);

    // 
    // ROTATE
    // 
    vector< vector<char> > small_090(small), small_180(small), small_270(small);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            small_090[    j][n-i-1]  = small[i][j];
            small_180[n-i-1][n-j-1]  = small[i][j];
            small_270[n-j-1][    i]  = small[i][j];
        }
    }

    // 
    // COUNT
    // 

    for (int i = 0; i < N-n+1; ++i)
    {
        for (int j = 0; j < N-n+1; ++j)
        {
            b    = true;
            b90  = true;
            b180 = true;
            b270 = true;

            for (int k = 0; k < n; ++k)
            {
                for (int l = 0; l < n; ++l)
                {
                    b    &= (big[i+k][j+l] == small[k][l]);
                    b90  &= (big[i+k][j+l] == small_090[k][l]);
                    b180 &= (big[i+k][j+l] == small_180[k][l]);
                    b270 &= (big[i+k][j+l] == small_270[k][l]);
                }
            }

            if (b)    { res[0]++; }
            if (b90)  { res[1]++; }
            if (b180) { res[2]++; }
            if (b270) { res[3]++; }
        }
    }

    return res;
}
