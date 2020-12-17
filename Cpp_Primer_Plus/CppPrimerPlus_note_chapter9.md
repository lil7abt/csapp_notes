# Chapter 9 Memory models and Namspaces
## Ch 9.1 Separate Compilation
### Program Division
1. a head file that contains the structure declarations and prototypes for functions that use those structures   
    * function prototypes
    * symbolic constans defined using #define or const
    * structure declarations
    * class declarations
    * template declarations
    * inline functions
2. a source code file that contains the code for the struct-related functions
3. a source code file that contains the code that call the struc-related functions
## Ch 9.2 Storage Duration, Scope and Linkage
### Ch 9.2.1 Storage Duration
1. **Automatic storage duration**: variables delared inside a function definition. They have 2 kinds:   
   
2. **Static storage duration**: variables defined outside a function definition by using the keyword `static`. They persist for the entire time a program is running. They have 3 kinds:
      
3. **Thread storage duration**:Variables declared with the keyword `thread_local` have storage that persists for as long as the containing thread lasts.
   
4. **Dynamic storage duration**: Memory allocated by the `new` operator persists until it is freed with the `delete` operator or until the program ends, whichever comes first. And it is sometimes termed the `free store` and `heap`
   
### Ch 9.2.2 Scope and Linkage
1. **Scope**: describes how widely visible a name is in a file(translation unit).
2. **Linkage**: describes how a name can be shared in different units. A name with external linkage can be shared across files, and a name with internal linkage can be shared by functions within a single file.

## Ch 9.3 Namespaces
Namespaces can be located at the globall level or inside other namespaces, but they cannot be placed in a block.
作为附加信息来区分不同库中相同名称的函数、类、变量等。使用了命名空间即定义了上下文。本质上，命名空间就是定义了一个范围。
1. 定义namespace
   ```c++
    namespace namespace_name
    {
        //代码声明
    }
   ```
2. 调用带有namespace的函数或变量 
   ```c++
    namespace::code; //code可以是函数或者变量
   ```
3. Using 指令   
   使用using namespace，告诉compiler 后续的代码将使用指定的命名空间中的名称
4. namespace的嵌套
   可以在namespace里面定义另外一个namespace
   ```c++
   namespace namespace_name1
   {
       namespace namespace_name2
       {

       }
   }
    //通过::来访问嵌套namespace的成员
   using namespace namespace_name1::namepsace_name2;
   using namespace namespace_name1; 

   ```