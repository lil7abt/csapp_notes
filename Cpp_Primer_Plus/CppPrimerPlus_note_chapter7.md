# Chapter 7 Functions: Programming Modules
## Functions for arrays
To keep a function from accidentally altering the contents of
an array argument, you can use the keyword const
    
    void show_array(const int ar[], int n);
It means that, we cannot use `ar` to change the data. E.g: we can read `ar[0]`, but cannot change the `ar[0]`, like `ar[]` is read-only, and this doesn't mean that thte original array needs to be constant.
## Functions for strings
## Functions for structures
To save time and space, we can pass the address(pointers) of a structure instead of passing the entire structure. We need 3 changes
1) when calling the function, pass it the address (&var) rather than the struct itsself (var)
2) Declare the formal parameter to be a pointer-to-type. If the function shouldn't modify the structure, use the const modifier.
3) Because the formal parameter is a pointer, we need to use the indirect membership operator (->) rather than the membership operator(.)
   

## Functions for objects of string class
The program treats string just as it would treat any of the built-in types, such as int.
## Pointers to functions
### Function Pointer Basics
基本use case, 例如你想写一个函数叫estimate()来估算写代码时间，来给不同的程序员用，这个函数的部分代码可以适用给所有，但是不同程序员有自己的估算算法
1. Obtaining the Address of a function   
```c++
    Process(think); // pass the address of think() to process()
```
2. Declare a pointer to a function: the declaration shoud identify the function's return type and the function's signature(its argument list).
   ```c++
   double pam(int);// prototype
   double (*pf)(int); // pf points to a fucntion that returns double
   //double *pf(int);//pf() is a function that returns a pointer-to-double
   pf=pam;// pam() has to match pf in both signature and return type
   ```
   回到本章节最初的问题，写一个estimate()函数:
   ```c++
   void estimate(int lines, double (*pf)(int));//lines to be estimated, and *pf to pass the address of an estimating algorithm --> tricky part
   estimate(50, pam;// function call telling estimate() to use pam()
   ```
3. Use a pointer to a function to invoke the function
```c++
    double pam(int);
    double (*pf)(int);
    pf=pam;
    double x = pam(4);
    double y = (*pf)(5);//
```
## Summary
1. By default, C++ functions pass arguments by value. This means that the formal paramters in the fucntion def are variables that are initialized to the values provided by the function call. Thus, C++ functions protect the intgrity of the origianal data by working with copies
2. C++ treats an array name argument as the address of the first element of the array; Technically, this is still passing by value, because the pointer is a copy of the original address, but function uses the pointer to access the contents of the original array.