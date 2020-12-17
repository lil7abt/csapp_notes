# 13 类的继承
OOP的一个最大目的就是为了重用代码。This method, called **class inheritance**, lets you derive new classes from old ones, with the derived class inheriting the properties, including the methods, of the old class, called a **base class**.   
用遗传可以做以下几件事情:   
1) 你可以给以存在的类添加功能
2) 你可以给已存在的类添加 data member
3) 你可以改变某个类方法的行为

## 13.1 Beginning with a Simple Base Class
* When one class inherits from another, the original class is called a base class, and the inheriting class is called a derived class.
* With public derivation, the public members of the base class become public members of the derived class.The private portions of a base class become part of the derived class, but they can be accessed only through public and protected methods of the base class.
* 遗传keyword
  * Public-Derivation: 基类的public和private都成为派生类的一部分。但是private部分只能通过基类的public或protected方法来access
  * Protected-Derivation:
  * Private-Derivation:
* 遗传的额外工作
  * 派生类需要自己的constructor
  * 派生类需要自己的data member and member functions
* 创造派生类的对象的具体步骤
  * the base-class obj is constructed first
  * the derived-class constructor should pass the base-class information to a base-class constructor via a member initializer list
  * the derived-class cosntructor shoudl initialize the data memebrs that were added to the derived class
* 派生类和基类特殊关系
  * 派生类对象可以用基类方法
  * 基类指针 可以直接指到 派生类对象; 基类引用 也可以直接 refer一个 派生对象; 但是，指向或引用派生类对象 的 基类指针或引用都 只能调用 基类方法;
  * 但是 派生类指针或引用 就不能 指向或引用 一个基类对象


## 13.2 Inheritance: An Is-a Relationship
Inheritance can add properties to a base class; it doesn’t remove
properties from a base class
## 13.3 Polymorphic Public Inheritance
You want a method to behave differently for the derived class than it does for the base class.   
* 两个关键机制
  * Redefining base-class methods in a derived class重定义基类方法
  * Using virtual methods 使用虚方法
    * 如果一个类函数被定义成虚函数，那么如果一个指针或者引用会根据当前指向的类来调用这个虚函数，而不是调用这个指针或引用在被声明时所用的类的同名函数
    * 所以一般经验 就是， 把所有有可能会被派生类重载的 函数都 定义成 virtual; 而且基类也需要一个virtual destructor for the base-class.
  * 使用Virtual Destructors:是为了 保证 一个指向派生类对象的基类指针 在调用派生类的destructor的时候可以 搞出正确执行顺序: 先执行派生类的destructor,再执行基类的destructor
## 13.4 Static and Dynamic Binding 静态和动态绑定
 * Static compilation: Binding taking place during compilation, is called
*  Dynamic compilation: for the virtual functions, the compiler doesn't konow which kind of object the user is going to choose to make. The compiler has to generate code that allows the correct virutal method to be selected as the program runs.
*  Upcasting(converting the derived-class-reference or -pointer to a base-class-reference or -pointer) is always allowed for public inheritance
*  Downcasting(converting the a base-class-pointer or -reference to a derived-class-pointer or -reference) is not allowed without an explicite type case.
*  Constructors can't be virutal
*  Destructors shoudl be virtual unless a class isn't to be used as a base-class
*  Friends can't be virtual functions because friends are not class members.(only class members can be virtual functions)
## 13.5 Access Control: protected
base类中加了protected的属性，其派生类可以 不需要通过public方法来access这个属性。 So you should prefer private to protected access-control for class data members, and you should use base-class methods to provide derived classes access to base-class data.
## 13.6 Abstract Base Classes 抽象基类
面向对象的系统可能会使用一个抽象基类为所有的外部应用程序提供一个适当的、通用的、标准化的接口。然后，派生类通过继承抽象基类，就把所有类似的操作都继承下来。外部应用程序提供的功能（即公有函数）在抽象基类中是以纯虚函数的形式存在的。这些纯虚函数在相应的派生类中被实现。这个架构也使得新的应用程序可以很容易地被添加到系统中，即使是在系统被定义之后依然可以如此。

C++接口是使用抽象类来实现，如果类中至少一个函数声明为纯虚函数， 那么这个类就是抽象类，纯虚函数是通过声明中"=0"来指定的。设计抽象类的目的是为了给其他类提供一个可以继承的适当的基类。它不能实例化，只能作为接口使用。因此如果一个ABC的子类需要被实例化，则必须实现每个虚函数，所以如果没有在派生类厘米重写纯虚函数，就尝试实例化该类的对象，会导致编译错误。
```c++
    void Move (int x, y)=0;
```
## 13.7 Inheritance and Dynamic Memory Allocation
* 动态内存:   
* Stack: 在函数内部声明的所有变量都将占用stack内存
* Heap: 程序中未使用的内存，在程序运行时可以用于动态分配内存， 用new来分配heap内存，如不再需要，可用delete清空之前的内存
* 如果ptr代表一个用new申请的内存返回的内存空间地址，即指针
    * `delete ptr`: 代表释放内存，且只用来释放ptr所指向的内存
    * `delete [] ptr`: 用来释放ptr所指向的内存，还逐一调用数组中每个对象的的destructor(因为有的对象在生成的时候会用new来占用内存，所以其的structor要有delete语句来在删除对象时候，也清空内存)

* Case 1 Derived Class Doesn't use new
* Case 2 Derived Class Does use new

## 13.8 Class Design Review
需要考虑到以下几点
1. 关于Compiler会自动生成的一些public member functions(special member functions)   
    a. Default Constructors   
        如果你自己不写一个constructor, compiler自动生成一个。   
    b. Copy Constructors     
        Is a constructor that takes an object of the class as its argument. Tpyically, the declared parameter is a constant reference to the class type.    这个东西一般运用在以下几个场景
        * when a new obj is initialized to an object of the same class   
        * When an obj is passed to a function by value   
        * When a function returns an obj by value    
        * When the compiler generates a temp obj    
        一般最好能提供一个能memberwise initialization的copy constructor.    
    c. Assignment Operators   
2. 关于其他的类方法   
    a. Constructor    
        Constructor是用来创建新对象，但是其它类方法都是被已有的对象调用   
    b. Destructor    
        You need to remember to define an explicit destructor that deletes any memory allocated by new in the class contructors and takes care of any other special bookkeeping that destroying a class object requires. If the class is to be used as a base class, you should provide a virtual destructor even if the class doesn't require a desctructor.  
    c. Conversion    
    d. Passing an Obj by value Vs. Passing a Reference   
        因为传递value的话，需要调用一个copy constructor，花时间，所以直接传递reference比较好，另外，如果函数不编辑此对象的话，需要加上const    
    e. Returning an Obj Vs. Returning a Reference    
        如果非必要，也是最好返回一个reference。因为直接返回一个对象的话，也是需要一个temp copy，又会花时间在创建copy和删除copy。当然，如果函数内部创建的obj的reference是不可以被返回的，因为函数结束时，这个reference也就消失了。   
    f. Using `Const`   
        参数里加const可以确保此函数不会改变参数。函数尾部加const，可以确保此函数不会改变调用此函数的对象。
3. 关于遗传   
    a. **Is-a Relationship**: a base class pointer can
point to a derived-class object and that a base-class reference can refer to a derived-class object without an explicit type cast. Also remember that the reverse is not true;   
    b. **What's not inherited**: Constructors, Destructors, Assignment operators   
    c. Assignment Operator   
    d. **Private Vs.Protected**: it’s better to use private
data members    
    e. Virtual Method 
    f. Destructor
    g. Friend
    h. Using Base-Class Methods


