# Chapter 12 Classes and Dynamic Memory Allocation
## 12.1. Special Member Function
These functions are member functions defined automatically, which are provided by C++:   
1) a **default constructor** if you define no constructors:    
   ```c++
   Class_name::Class_name(){ }//it's provided by compiler, no arguments and do nothing; its value at init is unknown
   ```
2) a default deconstructor if you don't define one:
3) a **copy constructor** if you don't define one: is used to copy a newly created obj. That is, it's used during init, including passing function arguments by value and not during ordinary assignment.    
   A copy constructor for a class normally has its prototype:
   * `Class_name(const Class_name &`: it takes a const reference to a class obj as its argument.
   * When is a copy-constructor is used?
     * when a new obj is created and init to an existing obj of same class.
     * a compiler uses a copy constructor whenever a program generates copies of an obj.(it's used when a function passes an obj by value or when a function returns an obj. Because passing by value means creating a copy of the origiinal variable)
     * a compiler also uses a copy constructor whenever it generates temporary objects.
   * What does a default-copy-constructor?
     * member-by-member copy of the nonstatic members (shallow copy)
     * static members are unaffected
   * Tip: If your class has static data member whose value changes when new obj are created, you should provide an explicit copy constructor that handles the accounting. If a class contains memebers that are pointers init by new, you should define a copy-constructor that copies the pointed-to-data instead of copying the pointers themselves. --> This is termed deep-copying.
4) an **assignment operator** if you don't define one:    
   The operator has following prototype:
   ```c++
    Class_name & Class_name::operator=(const Class_name &);//it takes and returns a reference to an object of the class
   ```
   * When does it used? when assigning one obj to another existing obj.
   * What does it? 
     * Implicite implementation: member-to-member copy. Static data memebrs are unaffected
     * Explicite implementation: providing your own assignment-operator definition to make a deep copy. But some:
       * Because the target object may already refer to previously allocated data, the function should use `delete []` to free former obligations.
       * The function should protect against assigning an obj to itself; otherwise, the freeing of memory described previously could erase the object's contents before they reassigned.
       * the fucntion returns a reference to the invoking object.
5) an address operator if you don't define one:   
-> The compiler generates definitions for the last three items if a program uses objects in such a way as to require them. E.g: if you assign one obj to another, program provides a def for the assignment operator.
6) **move constructor**: --> chapter 18
7) **move assignment operator**: --> chapter 18


## Chapter 12.2 Static Class Member Functions
1. No need to invoked by an object; No this-pointer
2. If declared in public-section, it can be invoked using the class name and the scope-resolution-operator
3. Cause the static-member-function is not associated with a particular object, the only data members it can use are the static data members.(这是和friend函数的区别)

## Chapter 12.3 Things to remember when using new in Constructors
1. 如果要在cosntructor用new来init一个pointer member,那么就需要在destructor用delete
2. new和delete需要成双成对出现，new [] 和 delete []也是
3. 需要定义一个copy-cosntructor来实现deep-copy
4. 需要定义一个assign-operator 来实现deep-copy，以及self-asssigment-check

## Chapter 12.4 函数返回值得总结
1. Returning a reference-to-a-const-object: 
   ```c++
   const Vector & Max(const Vector &v1, const Vector &v2)
   {
     if(v1.magval()>v2.magval())
        return v1;
     else
        return v2;
   }
   ```  
   1) 返回对象会调用此对象的copy-constructor, 但是返回引用则不会，所以效率高
   2) 引用都必须是函数期间 一直存在的对象。
   3) 因为argument的reference都是const，所以返回值也必须是const
2. Returning a reference-to-a-non-const-object
   一般用于 assignment operator overloading.
3. Returning an object
   如果被返回对象是 called function的local object(即在called function里面才新创造的对象),则不应返回reference。因为local object有自己的destructor,如果called function结束，这个local object也会消失，那么就没有reference可以来refer这个对象了。比如 arithmetic operator overloading就属于这一类。但需要不可避免的调用 copy-operator来创造生成的returned object。   
   [PS: 函数后面加const代表是 此函数只能读对象的属性，不能修改，提高可读性]
4. Returning a const object 
如果用const修饰函数返回值，则函数返回值也必须赋值给const修饰的变量。



## Chapter 12.5 Using Pointers to Objects
...TODO

## Chapter 12.6 Techniques Reviewing
...
## Chapter 12.7 A Queue Simulation
### Queue说明
1. FIFO
2. A Queue Class, 其元素为customer(另外一个class)
3. 三分之一的customer取钱要1min
4. 三分之一的customer取钱要2min
5. 三分之一的customer取钱要3min
6. 平均每小时的顾客是几乎const
7. Queue类   
   1) 属性   
      1) 一个装所有customer的容器
      2) 有一个上限 
   2) 方法
      1) 要能创造新空queue
      2) 能检查此queue是否为空
      3) 能检查此queue是否为满
      4) 能加元素到queue队尾
      5) 能删queue队头元素
      6) 能统计queue的总元素个数
### 额外说明
1. Nested Structs and Classes: 指的是声明在类声明中的 stuct, class, enum. 他们有class scope. 这样的声明是不会产生obj的，相反，这回确定一个数据类型，只是在此类中才有效。如果声明是在public区的话，那么这些声明也可在类外部使用，只需要通过scope-resolution-operator即可。
2. const变量可以被init一个值，但是不能再被赋值了. Therefor, if you want to init a const data member, you have to do so when the object is created before execution reaches the body of the constructor.所以可以使用 member initializer list: `variable_name(init_value)`   
      ```c++
      Queue::Queue(int qs): qsize(qs) //init the qsize to qs
      {
        front=rear=NULL;
        items=0;
      }
      ```   
      只有constructor可以可这么写。 当然也可以用在那些 reference member, 也是因为 reference和const变量一样都是只能在初始化的时候被赋值。
3. 一般情况下，凡是用new的类，都需要explicite copy constructor和assignment operator
4. it’s best to provide a copy constructor and an assignment operator,
even though you don’t need them now.