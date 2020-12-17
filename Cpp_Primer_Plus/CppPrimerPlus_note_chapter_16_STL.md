# 16 The String Class and the STL
C++最大特性就是有多种方法可以达到代码复用。 本章先扩展string类，然后了解smart pointer可以更简单地来管理dynamic memory。之后会了解STL, the STL exemplifies the programming pradigm called generic programming.最后看 `initializer_list` template class
## 16.1 The string class

## 16.2 Smart Pointer Template Class
* 防止heap泄露，即忘记 删除通过new占用的heap。有4个smart pointer templates (`auto_ptr, uniqur_ptr, shared_ptr`,`weak_ptr`). Each defines a pointer-like object intended to be assigned an address obtained by `new`. When the SPT expires, its desctructor uses `delete` to free the memory.所以如果你把通过`new`新建的对象地址分配给SPT，那么你就不用再需要记得最后来释放内存，SPT会在过期之后自动释放内存。相当于这玩意会自动调用自己的destructor,不需要手动来写个delete。
* 使用时，需要include memory header file; SPT属于std namespace
* **`shared_ptr`**:
    * 多个这个智能指针指向相同的对象，使用引用计数，每个shared_ptr的拷贝都指向相同的内存，每使用它一次，内部的引用计数加1，每析构一次，内部引用计数减1，减为0时，自动删除所指向的heap。shared_ptr的内部引用计数是线程安全的，但是对象的读取需要加锁。
    * 初始化: SPT是个class template，可以指定类型，传入指针通过constructor初始化，不能将指针直接赋值给一个SPT，一个是类，一个是指针。注意不要用一个原始指针初始化多个shared_ptr,否则会造成二次释放同一内存。
* **`unique_ptr`**:
    * 同一时刻，只能有一个unique_ptr指向给定对象。
* **`weak_ptr`**:
    * 为了配合shared_ptr而引入的一种智能指针。
## 16.3 STL
* 用于表示以下
    * **Containers**: is a unit, like an array, that can hold several values
    * **Iterators**: are objects that let you move through a *container* much as
pointers let you move through an array; they are generalizations of pointers
    * **Function Objects**: are objects that act like functions; they can be class objects or function pointers (including function names because a function name acts as a pointer)
    * **Algorithms**: recipes for accomplishing particular tasks, such as sorting an array or finding a particular value in a list
### 16.3.1 The `Vector` Template Class
计算机语义下的vector指的是含有一系列的values，而且可以随机地被读取，也就是说，我想读第10个，可以不用读了9个之后来读第10个。You could create a vector object, assign one vector object to another, and use the `[]` operator to access vector elements. To create a vector template object, you use the usual `<type>` notation to indicate the type to be used. 而且vector template object使用动态内存分配，你可以使用initialization argument 来指定想要的vector大小。
```cpp
#include vector
using namespace std;
vector<int> ratings(5);
int n;
cin>>n;
vector<double> scores(n);
```

* Vector的iterator: an iterator behaves like a pointer.
```cpp
/***Iterator 1***/
vector<double>::iterator pd; //a new-created iterator names "pd"
vector<double> scores;       //scores is a vector<double> object
pd = scores.begin();         //have pd point to the first element
/*automatic type deduction*/
//auto pd = scores.begin();
*pd = 22.3;                  //dereference and assign value to 1st element
++pd;//make pd point to the next element

/***Iterator 2***/ //用iterator来遍历vector所有元素    
/*end()实际上指的是vector最后一个元素还后面一个的位置，不含内容。*/                   
for(pd = scores.begin(); pd != scores.end();pd++) 
    cout << *pd << endl;

/**Vector push back funciton**/
vector<double> scores;  // an empty vector is created.
double temp;
while(cin>>temp && temp>=0)
    scores.push_back(temp); //this function adds an elementj to the end of a vector.
cout << "You entered "<< scores.size()<<"scores.\n";

/**Vector erase function**/
/*The erase function takes two iterator arguments that define the range to be removed to remove a given range of a vector.*/#
/*If iterator1 and iterator2 are two iterators, the STL uses the notation [p1, p2)*/
scores.erase(scores.begin(), scores.begin() + 2);

/**Vector insert()* function*/
/*the insert() function complements erase()*/
/*The 1st iterator gives the position ahead of which new elements are to be inserted*/
/*The 2nd and 3rd iterator define the range to be inserted*/
vector<int> old_v;
vector<int> new_v;
old_v.insert(old_v.begin(), new_v.begin()+1, new_v.end());//this inserts all but the 1st element of the new_v vector ahead of the 1st element of the old_v vector
old_v.insert(old_v.end(), new_v.begin()+1, new_v.end());// the new material is inserted ahead of old.end(), meaning it's placed after the last element in the vector
```
* Vector的其他一些函数
```cpp
/**for_each() function**/
vector<Review>::iterator pr:
for(pr=books.begin();pr!=books.end();pr++)
    ShowReview(*pr);
-->
for_each(books.begin(),books.end(), ShowReview);

/**random_shuffle() function**/
/*this function takes two iterators that specify a range and reranges the elements in that range in random order*/
random_shuffle(books.begin(), books.end());

/**sort() function**/
/*如果这个container里面的元素是用户自定义的数据类型，那么就必须要重写个operator<()，来让sort()函数正常使用。*/
bool operator<(const Review & r1, const Review & r2)
{
    if (r1.title<r2.title)
    {
        return true;
    }
    else if (r1.title==r2.title && r1.rating<r2.rating)
    {
        return true;
    }
    else
    {
        return false;
    }   
}
sort(books.begin(), books.end());
//以上代码可以实现按字母顺序排序

/*sort()的第二种形式,有三个argument*/
/*1st 和2nd都是来指示要排序的元素范围*/
/*3rd是一个函数指针，或者说是function object 用于代替operator<(）来进行比较. The return value should be convertible to bool, with false meaning the two arguments are in the wrong order.*/
bool WorseThan(const Review & r1, const Review & r2)
{
    if(r1.rating < r2.rating)
        return true;
    else
        return false;
}
sort(books.begin(), books.end(), WorseThan);
//以上代码可以实现rating大小来排序
```
### 16.3.2 The Range-Based `for` loop(C++11)


## 16.4 Generic Programming 泛型编程
### 16.4.1 Generic
OOP concentrates on the data aspect of programming, whereas generic programming concentrates on algorithms. The main things the two approaches have in common are abstraction and the creation of reusable code, but the philosophies are quite different.   
A goal of generic programming is ***to write code that is independent of data types***. Templates are the C++ tools for creating generic programs.

### 16.4.2 Why Iterators?
Iterators能让algorithms与 container使用的数据类型无关，因此它是STL走向generic的关键。
Iterator is a generic representation of the process of moving through the values in a container.
### 16.4.3 Five kinds of Iterators
1. **input iterator**: a program can use the input iterator to read the values from a container, but it needn't allow a program alter that value. Any algorithm based on an input iterator should be a single-pass algorithm that doesn't rely on iterator values from a previous pass or on earlier iterator values from the same pass. -->*single-pass, read-only algorithms.*
2. **output iterator**: used if an algorithm modifies the contents of a container(Eg. by generating new values to be stored) without reading the contents. --> *single-pass, write-only algorithms.*
3. **forward iterator**: can only go forward through a container one element at a time and can use only the ++ operators
4. **bidirectional iterator**: can tranverse a container in both directions
5. **random access iterator**: can jump directly to an arbitrary element of a container and has all the features of a bidirectional iterator.

They have different capabilities:
* Deferencing read: except output
* Deferencing write: except input
* Fixed and repeatable order: forward, bidirectional, Random-access
* ++i, i++: all
* --i, i--: bidirectional, Random-access
* i[n]: Random-access
* i+n, i-n, i+=n, i-=n: Random-access

All 5 kinds of iterators can be derefenced and can be compared for equality.

每个STL的文档会告诉你此STL用的哪种类型的iterator，然后你才知道你能用这个STL做些什么
- vector, deque: Random-Access
- list, set, multiset, map, multimap: bidirectional
- stack: 不支持iterator，用vector，deque或list对象创建的一个lifo的containier
- queue: 不支持iterator，用deque或者list的对象来创建的一个fifo的container
- priority_queue: 不支持iterator，用vector或deque对象创建的一个排序队列




### 16.4.4 **Iterator header File**
* Some special iterators
    - istream_iterator, ostream_iterator
    - reverese_iterator: rbegin() returns a reverse iterator pointing to past-the-end; rend() returns a reverse iterator pointing to the 1st element. But incrementing a reverse iterator makes it decrement.
    - Insertion Iterators: it adds new elements without overwriting existing data, and it uses automatic memory allocation to ensure that the new information fits. These iterators take the container type as a template argument and the actual container identifier as a constructor argument.:
        ```c++
        //to create a back_insert_iterator for a vector<int> container called dice.
        back_insert_iterator<vector<int>> back_iter(dice);
        //reason: the iterator has to make use of the appropriate container method
        ```
        - *back_insert_iterator*: inserts items at the end of the container; only for the containers that allow rapid insertion at the end
        - *front_insert_iterator*: inserts items at the front; only for the containers that allow constant time insertion at the beginning, Vector is here not possible.
        - *insert_iterator*: inserts items in front ot the location specified as an argument to the insert_iterator constructor. no restriction--> eg
        ```c++
        insert_iterator<vector<int>> insert_iter(dice, dice.begin());
        ```
* Copy() 函数是把一个container的data拷贝到另外一个container;这个函数是基于iterator的.
    * 前两个参数是被拷贝数据的range，必须至少是input iterator
    * 第三个参数是被拷贝的位置, 必须至少是output iterator，且必须有足够大的地方用于放被拷贝近来的的数据
    * Copy函数不能resize目标container的大小，但是可以利用container的自带函数，例如`vector<int>::push_back()`

### 16.4.5 Kinds of Containers
#### 16.4.5.1 Container Concept
* A container is an object that stores other objects, which are all of a single type
* 存在container里面的数据都属于container，即container被删除，里面的所有数据也被删除。当然如果container里面存的时候pointer，被指向数据不会被删除。
#### 16.4.5.2 Sequences
包含如deque, forward_lsit, list, queue, priority_queue, stack 和vector。Its elements are arranged in strict linear order and has a definite order.
* 基本操作: t representing a value of type T. p, q, i, and j, representing iterators
    ```c++
    - X a(n, t): delacares a sequence a of n copies of value t
    - X (n, t) : creates an anonymous sequence of n copies of value t
    - X a(i, j): Declares a sequence a init to the contents of range[i, j)
    - a.insert(p, t)   : return an iterator, inserts a copy of before p.
    - a.insert(p, n, t): return void       , inserts n copies of t before p.
    - a.insert(p, i, j): return void       , inserts copies of elements in the range [i,j) before p
    - a.erase(p)       : return an iterator, erases the element pointed-to by p
    - a.erase(p, q)    : return an iterator, erases the elements in the range [p,q)
    - a.clear()        : return void       , is the same as erase(begin(), end())
    ```
* Optional 操作:
    ```c++
    - a.front()      : 获取第一个元素的reference，vector, list, deque
    - a.back()       : 获取最后一元素的reference, vector, list, deque
    - a.push_front(t): 在首元素前插入，list, deque
    - a.push_back(t) : 在尾元素插入，vector, list, deque
    - a.pop_front(t) : 删除第一个元素， list, deque
    - a.pop_back(t)  : 删除最后一个元素，vector, list, deque
    - a[n]           : 获取某个元素的reference,vector, deque
    - a.at(n)        : 获取某个元素的reference, vector, deque
    ```
* **Vector**:automatic memory management; random-access; Added/Removed from the end in cosntant time; insertion/removal from the beginning and the middle are linear; reversible container; Simplest sequence, should be used as default.
* **Deque**: 和vector类似，但是如果从头开始插入和删除，也是time-constant，所以如果很多操作都是发生在头和尾，就考虑选择Deque这个数据结构。不然还是vector比较好，因为vector的实现比deque简单，所以速度更快
* **list**: declared in the list header file.实现了个双向链表，除了头和尾，每个元素都和自己的前后元素相连。和vector的区别是, 能够实现在list的任何位置做到constant-timeinsertion and removal of elements.也是个reversible的container。不支持[ ]和random-access.和vector不一样，list的iterator所指向的只是个位置，并不是元素本身。
* **forward_list**:单向链表，每个元素只和下一个相连。也不是reversible。和list相比，更简单，更kompakt，特性更少
* **queue**: is an adapter class and allows an underlying class (deque, by default) to exhibit the typical queue interface. 更严格，只能在queue尾添加元素，只能在queue头删除元素，只能看头和尾元素的值，只能检测元素的个数，测试一个queue是否为空。常用方法: empty(), size(), front(), back(), push(const T& x), pop().
* **priority_queue**: is another adapter class and allows the same operations as queue, default underlying class is vector. 和queue区别是，the largest item gets moved to the front of the queue.
* **stack**: is an adapter class,  default underlying class vector. It's more restrictive than vector. NO random-access, No iteration through the stack. You can push a value onto the top, pop an element from the top of stack, view the value of the top element, check the num of the elements and test if the stack is empty.
#### 16.4.5.3 Asscociaive Containers
An associative container associates a value with a key and uses the key to find the value. 强项是能更快搜索到element, 可以插入元素，但是不能设定插入位置。一般是tree结构。一共四种
* **set**: 最简单一种，value类型和key类型一样，key值唯一
* **multiset**: 和set区别是，key可以对应多个value
* **map**: value类型和key类型不一样，且key唯一
* **multimap**: 和map不一样，key可以对应多个value

#### 16.4.5.4 Unordered Asscociaive Containers
无序

## 16.5 Function Objects(AKA. Functors)
中文叫仿函数或者函子。在类里面重载一个()括号运算符的的方法，直接把一个对象函数化。

### 16.5.1 Functor Concepts
1. *Generator*: a functor that can be called with no arguments
2. *Unary function*: is a functor that can be called with one argument, return with bool is a *predict*
3. *Binary function*: is a functor that can be called wih two argument, return with bool is a *binary predict*

### 16.5.2 Predefined Functors
STL provides functor equivalents for all the built-in arithmetic, relational, and logical operators.
- `+:  plus`
- `-:  minus`
- `*:  multiplies`
- `/:  divides`
- `%:  modulus`
- `-:  negate`
- `==: equal_to`
- `!=: not_equal_to`
- `>:  greater`
- `<:  less`
- `>=: greater_equal`
- `<=: less_equal`
- `&&: logical_and`
- `||: logical_or`
- `!:  logical_not`

### 16.5.3 Adaptable Functors and Function Adapters
仿函数和函数适配器，即 有些地方只能用一元函数，但是有必须使用二元函数的时候，通过适配器adapter把二元函数变成一个一元函数。
The predefined functors above are all adaptable.
* bind1st和bind2nd是两个捆绑函数
```c++
// prototype
bind1st(const operation & op, const T & x) --> x op value;
bind2nd(const operation & op, const T & x) --> value op x
//value是被应用在bind的对象

//E.g: f2 is a binary funcion. 
//By using bind1st, val is used as the 1st argument of the f2
//By using bind2nd, val is used as the 2nd argument of the f2
binder1st(f2, val) f1;//Here, the f1 is a funcion object of the class bind1st
f1(x);//-->f2(val, x)
//Ivoking the f1(x) with its single argument
//returns the same value as invoking f2() with val as its 1st argument
//and f1()'s own argument as its 2nd argument.

```
## 16.6 Algorithms
### **算法函数的两个特点**
1. they use templates to provide generic types
2. they use iterators to provide a generic representation for accessing data in a container.       
### **算法函数可以分为以下四类**
* Nonmodifying sequence operations: `<algorithm>`;不改变container的内容，操作其一部分,Eg find(), for_each()
* Mutating sequence operations: `<algorithm>`; 能改变container的内容, Eg transform(), random_shuffle(), copy()
* Sorting and related operations: `<algorithm>`
* Generalized numeric operations: `<numeric>`: 包括计算和，计算内积等
### 函数有不同的version
- in-place algorithm: E.g `sort()`
- copying algorithm: E.g `copy()`
- both: E.g `transform()`
### Function Vs. Container-Methods
一般选用Container member methods, 可以自动调整container的大小，function 不行，需要手动调。
## 16.7 Other Libraries
### The `initializer_list` Template
相当于把整个initializer_list类化以及实例化，可以直接作为参数 用于 对象的创建及初始化。