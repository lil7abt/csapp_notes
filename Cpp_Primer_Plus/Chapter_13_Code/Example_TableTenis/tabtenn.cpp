#include <iostream>
#include "tabtenn.h"

//user constructor with initializer-list
TableTennisPlayer::TableTennisPlayer(const string &fn , const string &ln , bool ht) : firstname(fn), lastname(ln), hasTable(ht)
{}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << "," << firstname;
}

//use initializer list to init the TableTennisPlayer obj for the constructor of the class RatedPlayer
RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht): TableTennisPlayer(ln, fn, ht)
{
    rating=r;
}
// 2nd constructor by passing the base-class-obj. This will invoke the base-class-copy-constructor
RatedPlayer::RatedPlayer(unsigned int  r, const TableTennisPlayer &tp): TableTennisPlayer(tp), rating(r)
{

}