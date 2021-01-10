# Ch2 Ctor/Dtor/AssignmentOperator

## 5 知道C++在暗暗的 write和call的东西
## 6 显示的禁止所有compiler默默为你生成的的函数
## 7 在多态的base类中，把dtor声明为virtual
## 8 在离开dtor时，要阻止exceptions
## 9 永远不要在ctor/dtor的时候调用virtual的函数
## 10 assign operator 的最后都要使用return *this
## 11 在assign operator 里面使用自我赋值
## 12 copy 对象的时候,记得copy里面每个attribute