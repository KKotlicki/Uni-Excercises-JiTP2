// Konrad Kotlicki (310958)

#ifndef ZAD1_RANGE_H
#define ZAD1_RANGE_H
#include <iostream>

class range
{
    int low, high;
public:
    range(int low, int high){
        range::low = low;
        this->high = high;
    }

    int get_low() const{
        return low;
    }

    int get_high() const{
        return high;
    }

    virtual bool inrange(int val) const{
        return get_low() < val && val < get_high();
    }

    friend std::ostream& operator<<(std::ostream& os, range& rg){
        return os << '(' << rg.get_low() << ", " << rg.get_high() << ')';
    }

};

class bcrange : public range{

public:
    bcrange(int low, int high) : range(low, high){}

    bool inrange(int val) const override{
        return get_low() <= val && val <= get_high();
    }

    friend std::ostream& operator<<(std::ostream& os, const bcrange& bcrg)
    {
        os << '<' << bcrg.get_low() << ", " << bcrg.get_high() << '>';
        return os;
    }
};

class lcrange : public range{

public:
    lcrange(int low, int high) : range(low, high){}

    bool inrange(int val) const override{
        return get_low() <= val && val < get_high();
    }

    friend std::ostream& operator<<(std::ostream& os, const lcrange& lcrg)
    {
        os << '<' << lcrg.get_low() << ", " << lcrg.get_high() << ')';
        return os;
    }
};

class rcrange : public range{

public:
    rcrange(int low, int high) : range(low, high){}

    bool inrange(int val) const override{
        return get_low() < val && val <= get_high();
    }

    friend std::ostream& operator<<(std::ostream& os, const rcrange& rcrg)
    {
        os << '(' << rcrg.get_low() << ", " << rcrg.get_high() << '>';
        return os;
    }
};

#endif //ZAD1_RANGE_H
