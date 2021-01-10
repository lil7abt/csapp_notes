/****Item 2 Prefer const, enum, inline to #define*****/
    /*use case 2: 用enum hack来替代class static const variable*/
    class GamePlayer
    {
        enum
        {
            NumTurns = 5
        }; //行为类似class static const variable
        int scores[NumTurns];
    }
    /*use case 3: 用inline函数替代 #define 函数*/
    #define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b));
    //better-->
    template <typename T>
    inline void callWithMax(const T &a, const T &b) //由于不知道T是什么类型,所以使用pass by ref to const --> item 20
    {
        f(a > b ? a : b);
    }

/******* Item 3  Use const whenever possible*************/
    // Example 1
    char greeting[] = "Hello";      //如果const出现在*左边,表示被pointed的是const
    char* p = greeting;             //如果const出现在*右边,表示指针本身是个const
    const char* p = greeting;       //如果const出现在*两边,则指针本身和被指data都是const
    char* const p = greeting;
    const char* const p = greeting; 

    //Example 2: STL iterator
    std::vector<int> vec;
    const std::vector<int>::iterator iter = vec.begin();//iter所指的东西(即所指向的内存地址内存储的数据)可变,但是其本身(即所指向的内存地址)不可变被改变
    std::vector<int>::const_iterator citer = vec.begin();//citer所指的东西(即所指向的内存地址内存储的数据)不可变,但是其本身(即所指向的内存地址)可变
    
    //Example 3: const用在函数上面,避免误操作
    class Rational{ };
    const Rational operator*(const Rational& lhs, const Rational& rhs);
    
    //Example 4: const用在member function 上面-->1) 为了好看 2) 为了实现 pass obj by ref to const
    class TextBlock
    {
    public:
        const char& operator[](std::size_t position) const // operator[ ] for const objects 可读不可写
        {return text[position];}                           // 返回值是一个ref to char
        char& operator[](std::size_t position)             // operator[ ] for non-const objects 可读可写
        {return text[position];}                           // 
    private:
        std::string text;
    };
    TextBlock tb("Hello");         //calls non-const TextBlock::operator[]
    std::cout<<tb[0];
    const TextBlock ctb("World");  //calls const TextBlock::operator[]
    std::cout<<ctb[0];

/********Item 4 确保对象使用前都初始化********/
    //Exapmle 1 对ctor使用member initialization list； 这样速度更高
    class PhoneNumber { ... }; 
    class ABEntry 
    {// ABEntry = “Address Book Entry” 
        public: 
            ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones); 
        private: 
            std::string theName;
            std::string theAddress; 
            std::list<PhoneNumber> thePhones; 
            int numTimesConsulted; 
    };
    ABEntry::ABEntry(const std::string& name, const std::string& adress, const std::list<PhoneNumber>& phones): theName(name),
                                                                                                                theAddress(address),
                                                                                                                thePhones(phones),
                                                                                                                numTimesConsulted(0);
    {}
    //Example 2 将每个non-local static对象放到自己的专属函数中，这些函数返回一个reference指向它所含的对象；因为C++可以保证函数内的local static对象会在该第一次调用此函数时被初始化
                                                                                                                    
