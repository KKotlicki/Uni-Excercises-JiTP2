// Konrad Kotlicki (310958)
#ifndef ZAD3_FIGURE_H
#define ZAD3_FIGURE_H
#include <iostream>
#include <cmath>
#include <vector>
#include <exception>
#include <fstream>
using namespace std;


class FPoint
{
public:
    float x = 0.0f, y = 0.0f;
    FPoint(float cx, float cy) : x(cx), y(cy) {}


    friend ostream& operator<<(ostream& os, const FPoint& fp)
    {return os << '(' << fp.x << ',' << fp.y << ')';}

    friend istream& operator>>(istream& is, FPoint& fp) {
        char l, m, r;
        is >> l >> fp.x >> m >> fp.y >> r;
        if (l != '(' || m != ',' || r != ')')
            throw runtime_error("Invalid point notation.");

        return is;
    }
};


FPoint min(const FPoint& lf, const FPoint& rt)
{
    return {min(lf.x, rt.x), min(lf.y, rt.y)};
}
FPoint max(const FPoint& lf, const FPoint& rt)
{
    return {max(lf.x, rt.x), max(lf.y, rt.y)};
}

vector<FPoint> get_points(istream& is) {
    vector<FPoint> vp;
    char ch;
    FPoint fp(0.0, 0.0);
    is >> ch;
    if (ch != '(') throw runtime_error("Point reading error.");
    do {
        is >> fp;
        vp.push_back(fp);
        is >> ch;
        if (ch == '(') is.unget();
    } while (ch != ')');
    return vp;
}

string get_id(istream& is) {
    string retv;
    char ch;
    while (is >> ch) {
        if (isalpha(ch))
            retv += ch;
        else if (retv.empty())
            throw runtime_error("Identifier not found.");
        else {
            is.unget();
            return retv;
        }
    }
    return retv;
}


class figure
{
    string id;
    vector<FPoint> points;
public:
    friend ostream& operator<<(ostream& os, const figure& fig)
    {
        os << fig.id << '(';
        for (FPoint point : fig.points)
            os << point;
        return os << ')';
    }

    friend istream& operator>>(istream& is, figure& fig)
    {
        fig.id = get_id(is);
        if (fig.id.length() == 0) return is;
        if (fig.id != "Rect" && fig.id != "Circ") throw runtime_error("Invalid figure identifier.");
        fig.points = get_points(is);
        if (fig.points.size() != 2) throw runtime_error("Invalid point count.");
        return is;
    }

    pair<FPoint, FPoint> bbox() const
    {
        FPoint pmin = points[0], pmax = points[0];
        for (int i = 1; i < (int) points.size(); ++i) {
            pmin = min(pmin, points[i]);
            pmax = max(pmax, points[i]);
        }
        if (id == "Circ") {
            FPoint pcen = points[0];
            float radius = sqrt(pow(pmax.x - pmin.x, 2.0f) + pow(pmax.y - pmin.y, 2.0f));
            pmin.x = pcen.x - radius;
            pmin.y = pcen.y - radius;
            pmax.x = pcen.x + radius;
            pmax.y = pcen.y + radius;
        }
        return make_pair(pmin, pmax);
    }
};

#endif //ZAD3_FIGURE_H
