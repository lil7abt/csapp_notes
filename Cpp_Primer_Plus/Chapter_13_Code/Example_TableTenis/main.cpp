#include <iostream>
#include "tabtenn.h"

int main()
{
    using std::cout;
    TableTennisPlayer player1("Li", "Li", true);
    RatedPlayer rplayer1(1140, "Hanjie", "Li", false);
    player1.Name();
    if (player1.HasTable())
    {
        cout<<": has a table.\n";
    }
    else
    {
        cout << ": hasn't a table.\n";
    }

    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << "\n";
    RatedPlayer rplayer2(1212, player1);
    cout<<"Name: ";
    rplayer2.Name();
    cout<<"; Rating: "<<rplayer2.Rating()<<"\n";


    system("pause");
    return 0;
}
