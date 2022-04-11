#include "range.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

std::ostream& operator<<(std::ostream& os, const range& rng)
{
    return os << rng.left_paren() << rng.get_low() << ", "
              << rng.get_high() << rng.right_paren();
}

// dla przypomnienia - pierwsza wersja zliczania elementow
// kolekcji coll, znajdujacych sie w przedziale rng
int count_in_range(const vector<int>& coll, const range& rng)
{
    int sum = 0;
    for (int v : coll)
        if (rng.inrange(v))
            ++sum;
    return sum;
}

int main()
{
    // testy zliczania elementow w zakresie
    int lower = -4;
    int upper = 3;
    vector<int> test;
    for (int i = lower - 3; i <= upper + 3; ++i)
        test.push_back(i);

    range rop(lower, upper);
    if (count_if(test.begin(), test.end(), rop) != 6)
        cout << "Error in count_if for open range\n";

    lcrange rlc(lower, upper);
    if (count_if(test.begin(), test.end(), rlc) != 7)
        cout << "Error in count_if for left closed range\n";

    rcrange rrc(lower, upper);
    if (count_if(test.begin(), test.end(), rrc) != 7)
        cout << "Error in count_if for right closed range\n";

    bcrange rbc(lower, upper);
    if (count_if(test.begin(), test.end(), rbc) != 8)
        cout << "Error in count_if for closed range\n";

    {
        stringstream ss;
        ss << rop;
        if (ss.str() != "(-4, 3)")
            cout << "Error in << for open range\n";
    }

    {
        stringstream ss;
        ss << rlc;
        if (ss.str() != "<-4, 3)")
            cout << "Error in << for left closed range\n";
    }

    {
        stringstream ss;
        ss << rrc;
        if (ss.str() != "(-4, 3>")
            cout << "Error in << for right closed range\n";
    }

    {
        stringstream ss;
        ss << rbc;
        if (ss.str() != "<-4, 3>")
            cout << "Error in << for closed range\n";
    }

    cout << "End of tests.\n";

    return 0;
}
