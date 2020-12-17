#ifndef __TABTENN__H__
#define __TABTENN__H__
#include <string>

using std::string;

//Base-Class
class TableTennisPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string &fn = "none",
                      const string &ln = "none",
                      bool  ht         = false);
    // ~TableTennisPlayer();
    void Name() const;
    bool HasTable() const {return hasTable;};
    void ResetTable(bool v) {hasTable=v;};
    
};

//Derived-Class
class RatedPlayer:public TableTennisPlayer
{
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r=0, const string &fn="none", const string &ln="none", bool ht=false);
    RatedPlayer(unsigned int r, const TableTennisPlayer &tp);
    unsigned int Rating() const {return rating;}
    void ResetRating(unsigned int r){rating = r;}
};



#endif  //!__TABTENN__H__