#include "figure.h"
using namespace std;


int main()
{
    try
    {
// testowanie
        ifstream ifs("good.txt");
        if (!ifs.good())// dobrze sprawdzić przed czytaniem
            throw runtime_error("Cannot find input file.");
        figure fig;
//        while (ifs >> fig)
//        {
//            cout << fig << endl;
//            pair<FPoint, FPoint> bb = fig.bbox();
//            cout << '\t' << bb.first << bb.second << endl;
//        }
        ifs.close();
    }
    catch (exception& ex)
    {
        cout << "exception: " << ex.what() << endl;
    }
    catch (...)
    {
        cout << "Unidentified exception.\n";
    }
    cout << "End of Tests!" << endl;
}
