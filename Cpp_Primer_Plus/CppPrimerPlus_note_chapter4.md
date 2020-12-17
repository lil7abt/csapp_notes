# C++ Compond Types
## Array
1. Declaration: `typeName arrayName[12];`
2. adfa
3. 
## String
A string is a series of characters stored in consecutive bytes of memory
1. Array of char (the last char of every string is the null char): `char dog[2] = {'f','a','\0'};`
2. String Class: 
## Structure
The keyword `struct` indicates that the code defines the layout for a structure.
## Unions
One use for a union is to save space when a data item can use two or more formats but never simultaneously
## Enum
An alternative to const for creating symbolic constants
## Pointers and Free Store
Pointer Golden Rule: Always initialize a pointer to a definite and appropriate address before
you apply the dereferencing operator (*) to it.
## Pointers, Array, and Pointer Arithmetic
In most contexts, C++ interprets the name of an array as the address of its first element
## Array Alternatives
1. Vector template class:  
   In general, the following declaration creates a vector object `vt` that can hold `n_elem` elements of type `typeName`:
   ```
   vector<typeName> vt(n_elem);
   ```
1. array template class:   
   More general, the following declaration creates an array object `arr` with `n_elem` elements of `typeName`:
   ```
   array<typeName, n_elem> arr;
   ```
   Unlike the case for vector, n_elem can’t be a variable.
2. Comparison of the built-in array, template array, template vector 
   1. whether we use a built-in array, a vector object, or an array object, we can use the standard array notation to access individual members.
   2. addresses that array objects use the same region of memory as the built-in array, whereas the vector object is stored in a different region
   3. you can assign an array object to another array object