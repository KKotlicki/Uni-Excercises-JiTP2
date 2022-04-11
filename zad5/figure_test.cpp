#include "figure.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <graph.h>
#include <Simple_window.h>
using namespace std;


int main()
{
    ifstream ifs("mapa_test.txt");
    if (!ifs.good()) // dobrze sprawdzic przed czytaniem
    {
        cout << "Cannot find input file.\n";
        return 1;
    }
    vector<figure*> figs;
    try
    {
        figure *fig;
        while ((fig = get_figure(ifs)) != nullptr)
        {
            figs.push_back(fig);
        }
    }
    catch (...)
    {
        cout << "figure: unexpected exception in >>\n";
    }
    ifs.close();

    Simple_window wnd(Point(100, 100), 600, 400, "Rajmund Kozuszek (121528)");
    for (auto pf : figs)
        wnd.attach(*(pf->get_shape()));
    wnd.wait_for_button();

    return 0;
}
