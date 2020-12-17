# Ch 10 Objects and Classes
## Ch 10.1 Basics
Any function wiht a definition in the class declaration automatically becomes an inline function.   
   
**The client/server model:**   
The client is a program that uses the class. The class declaration, including the class methods, constitute the server, which is a resource that is available to the programs that need it.

**Class Constructors and Deconstructors:**   
This aims to make using class objects similar to usign standard types
1. Constructors: --> public
   - constructor with arguments
   - constructor withou arguments to initialize the object, default constructor, only one is allowed
2. Creat a new object: 
   ```c++
    stock food = stock("Word",250, 12.4);
    stock food("Word",250, 12.4);
    stock food = stock("Word",250, 12.4);
    stock *ptr_food = new stock("Word",250, 12.4);// an object is created wihout a name, but a pointer
   ```
3. Destructors   
   The compiler handles this decision; normally your code shouldn’t explicitly call a destructor.   
  - **Static storage class object**: its destructor is called automatically when the program terminates
  - **Automatic storage class object**: its destructor is called automatically when the program exits the block of code in which the object is defined.
  - **Object created by using new**: it resides in heap memory, or the free store, and its destructor is called automatically when you use delete to free the memory.   
  - Because a destructor is called automatically when a class object expires, there ought to be a destructor. If you don’t provide one, the compiler implicitly declares a default constructor and, if it detects code that  eads to the destruction of an object, it provides a definition for the destructor.    


## Ch 10.2 Abstract Data Types

