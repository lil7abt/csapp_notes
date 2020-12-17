#include <iostream>
#include "stock00.h"
int main()
{
    // stock fluffy_the_cat = stock("LILI.Co", 12, 12.5);
    stock fluffy_the_cat;
    fluffy_the_cat.show();
    fluffy_the_cat.acquire("NanoSmart", 20, 12.5);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();
}