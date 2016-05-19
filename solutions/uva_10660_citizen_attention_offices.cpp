#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

void solution()
{
    // input parsing
    int n_areas(0), x(0), y(0), population(0);
    // map of the city
    vvi city(5, vi(5));
    // position of the offices
    int x1(0), y1(0), x2(0), y2(0), x3(0), y3(0), x4(0), y4(0), x5(0), y5(0);
    // final position of the offices
    int i1_res(0), i2_res(0), i3_res(0), i4_res(0), i5_res(0);
    int min_dist(0);
    int current_min(0);
    int real_min(3000000);

    cin >> n_areas;
    while (n_areas--)
    {
        cin >> x >> y >> population;
        city[x][y] = population;
    }

    // loop on all possible position for the offices
    for (int i1 =    0; i1 <= 20; ++i1) { x1 = i1 / 5; y1 = i1 - (i1 / 5) * 5;
    for (int i2 = i1+1; i2 <= 21; ++i2) { x2 = i2 / 5; y2 = i2 - (i2 / 5) * 5;
    for (int i3 = i2+1; i3 <= 22; ++i3) { x3 = i3 / 5; y3 = i3 - (i3 / 5) * 5;
    for (int i4 = i3+1; i4 <= 23; ++i4) { x4 = i4 / 5; y4 = i4 - (i4 / 5) * 5;
    for (int i5 = i4+1; i5 <= 24; ++i5) { x5 = i5 / 5; y5 = i5 - (i5 / 5) * 5;
        current_min = 0;
        // loop on the areas
        for (int x = 0; x <= 4; ++x) {
        for (int y = 0; y <= 4; ++y) {
            min_dist = min(abs(x - x1) + abs(y - y1),
                       min(abs(x - x2) + abs(y - y2),
                       min(abs(x - x3) + abs(y - y3),
                       min(abs(x - x4) + abs(y - y4),
                           abs(x - x5) + abs(y - y5)
                       ))));
            current_min += min_dist * city[x][y];
        }}
        if (current_min < real_min)
        {
            real_min = current_min;
            i1_res = i1;
            i2_res = i2;
            i3_res = i3;
            i4_res = i4;
            i5_res = i5;
        }
    }}}}}

    cout << i1_res << " "
         << i2_res << " "
         << i3_res << " "
         << i4_res << " "
         << i5_res << endl;
}

int main(int argc, char const *argv[])
{
    int T(0); cin >> T;

    while (T--)
        solution();

    return 0;
}
