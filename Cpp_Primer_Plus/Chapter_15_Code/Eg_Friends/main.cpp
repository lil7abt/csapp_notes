#include <iostream>
#include "tv.h"

int main()
{
    using std::cout;

    Tv s42;

    cout<<"Initial setings for 42\" TV:\n";
    s42.settings();

    s42.onoff();
    s42.chanup();
    cout<<"\nAdjusted settings for s42 TV:\n";
    s42.settings();

    Remote grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout<<"s42 settings after using grey remote:\n";
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    std::cout << "s58 settings:" << std::endl;
    s58.settings();

    return 0;
}