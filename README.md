#C++ Primer 5th 

P253 ~ P276 类

```C++
1.一个 const 成员函数如果以引用的形式返回 *this ,那么它的返回类型将是常量引用。

const Screen& Screen::display() const; 
```
```C++
2.如果成员是 const ,引用，或者属于某种未提供默认构造函数的类类型，
我们必须通过构造函数初始值列表为这些成员提供初值。
```