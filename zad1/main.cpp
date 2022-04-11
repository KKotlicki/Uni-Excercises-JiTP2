#include "range.h"
#include <iostream>
using namespace std;


int main() {
    range rg(2, 4);
    if(rg.get_low() != 2)
        cout << "Error in low value.\n";
    if(rg.get_high() != 4)
        cout << "Error in high value.\n";

    if(rg.inrange(2))
        cout << "Error in inrange (should be False)\n";
    if(!rg.inrange(3))
        cout << "Error in inrange (should be True)\n";
    if(rg.inrange(4))
        cout << "Error in inrange (should be False)\n";

    cout << rg << endl;

    cout << "\nbcrange:" << endl;
    bcrange bcrg(4, 8);

    cout << bcrg.inrange(9) << endl;
    cout << bcrg << endl;

    cout << "\nlcrange:" << endl;
    lcrange lcrg(4, 8);

    cout << lcrg.inrange(8) << endl;
    cout << lcrg << endl;

    cout << "\nrcrange:" << endl;
    rcrange rcrg(4, 8);

    cout << rcrg.inrange(5) << endl;
    cout << rcrg << endl;


    cout << "\nEnd of Tests!" << endl;
    return 0;
}
