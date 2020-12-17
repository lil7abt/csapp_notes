//methods for adjusting and resetting times, displaying, adding two times
#ifndef __MYTIME__H__
#define __MYTIME__H__
class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m);
    void addMin(int m);
    void addHr(int h);
    void reset(int h=0, int m=0);
    // Time sum(const Time &t) const;
    Time operator+(const Time &t) const;
    void show() const;
};

#endif  //!__MYTIME__H__