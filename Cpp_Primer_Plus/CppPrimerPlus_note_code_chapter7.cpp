#include <iostream>
#include <cmath>
#include <string>


// struct polar
// {
//     int distance;
//     int angle;
// };

// struct rect
// {
//     int x;
//     int y;
// };

// void rect_to_polar(const rect* pxy, polar* pda);
// void show_polar(const polar* pda);

// int main()
// {
//     using namespace std;
//     rect rplace;
//     polar pplace;
//     cout << "Enter the x and y values: ";
//     while (cin >> rplace.x >> rplace.y)
//     {
//     rect_to_polar(&rplace, &pplace); // pass addresses
//     show_polar(&pplace); // pass address
//     cout << "Next two numbers (q to quit): ";
//     }
//     cout << "Done.\n";
//     return 0;
// }

// void rect_to_polar(const rect* pxy, polar* pda)
// {
//     using namespace std;
//     pda->distance =sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
//     pda->angle=atan2(pxy->y, pxy->x);
// }
// void show_polar(const polar* pda)
// {
//     using namespace std;
//     const int Rad_to_deg = 57;
//     cout<<"distance is "<<pda->distance;
//     cout<<", angle is "<<pda->angle * Rad_to_deg;
//     cout<<" degrees\n";
// }
// using namespace std;
// const int SIZE =5;
// void display(const string sa[], int n);
// int main()
// {
//     string list[SIZE];
//     cout<<"Enter your "<<SIZE<< "favorite astronomical sights:\n";
//     for(int i=0;i<SIZE;i++)
//     {
//         cout<<i+1<<"; ";
//         getline(cin, list[i]);
//     }
//     cout<<"Your list: \n";
//     display(list, SIZE);
//     return 0;
// }
// void display(const string sa[], int n)
// {
//     for (int i=0; i<n;i++)
//         cout<<i+1<<": "<<sa[i]<<endl;
// }


/***example****/
// double betsy(int);
// double pam(int);
// void estimate (int lines, double (*pf)(int));

// int main()
// {
//     using namespace std;
//     int code;
//     cout << "how many lines do you need to write? ";
//     cin>>code;
//     cout<<"Here's Betsy's estimate:\n";
//     estimate(code, betsy);
//     cout<<"Here's Pam's estimate:\n";
//     estimate(code, pam);
//     return 0;
// }

// double betsy(int lns)
// {
//     return 0.05*lns;
// }
// double pam(int lns)
// {
//     return 0.03*lns+0.0004*lns*lns;
// }
// void estimate(int lines, double (*pf)(int))
// {
//     using namespace std;
//     cout<<lines<<"lines will take ";
//     cout<<(*pf)(lines)<<" hours\n";
// }



/******exececise 3*******/

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
void function_one(box my_box);
void function_two(box *ptr_box);

int main()
{
    box my_box
    {   
        "my_box",
        2,
        2,
        2,
        1
    };
    function_one(my_box);
    function_two(&my_box);
    return 0;
}

void function_one(box my_box)
{
    using namespace std;
    cout<<my_box.maker<<endl;
    cout<<my_box.height<<endl;
    cout<<my_box.width<<endl;
}
void function_two(box *ptr_box)
{
    using namespace std;
    ptr_box->volume=ptr_box->height*ptr_box->length*ptr_box->width;
    cout<<ptr_box->volume;
}