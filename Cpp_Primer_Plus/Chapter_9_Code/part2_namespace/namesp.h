//contains some
// items normally found in header files—constants, structure definitions, and function prototypes.
// In this case, the items are placed in two namespaces.The first namespace, pers, contains
// a definition of a Person structure, plus prototypes for a function that fills a structure
// with a person’s name and a function that displays the structure’s contents.The second
// namespace, debts, defines a structure for storing the name of a person and the amount of
// money owed to that person.This structure uses the Person structure, so the debts namespace
// has a using directive to make the names in the pers namespace available in the
// debts namespace.The debts namespace also contains some prototypes.

#include <string>
namespace pers
{
    struct Person
    {
        std::string fname;
        std::string lname;
    };
    void getPerson(Person &);
    void showPerson(const Person &);
}
namespace debts
{
    using namespace pers;
    struct Debt
    {
        Person name;
        double amout;
    };
    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebts(const Debt ar[], int n);
    
}
