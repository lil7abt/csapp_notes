#include <iostream>
#include <cmath>
#include "coordin.h"

using namespace std;
int main()
{
    rect rplace;
    polar pplace;
    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
    rect_to_polar(&rplace, &pplace); // pass addresses
    show_polar(&pplace); // pass address
    cout << "Next two numbers (q to quit): ";
    }
    cout << "Done.\n";
    return 0;
}
    