// Konrad Kotlicki (310958)

#ifndef ZAD2_RANGE_H
#define ZAD2_RANGE_H

class range{
    int low, high;
public:
    range(int l, int h) : low(l), high(h){}

    virtual ~range() = default;

    int get_low() const {return low;}

    int get_high() const {return high;}

    virtual char left_paren() const {return '(';}

    virtual char right_paren() const {return ')';}

    virtual bool inrange(int val) const {return get_low()<val && val<get_high();}

    bool operator() (int val) const {return inrange(val);}
};

class lcrange : public range{

public:
    using range::range;

    char left_paren() const override {return '<';}

    bool inrange(int val) const override {return get_low()<=val && val<get_high();}
};

class rcrange : public range{

public:
    using range::range;

    char right_paren() const override {return '>';}

    bool inrange(int val) const override {return get_low()<val && val<=get_high();}
};

class bcrange : public range{

public:
    using range::range;

    char left_paren() const override {return '<';}

    char right_paren() const override {return '>';}

    bool inrange(int val) const override {return get_low()<=val && val<=get_high();}
};

#endif //ZAD2_RANGE_H
