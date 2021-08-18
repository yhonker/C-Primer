## 拷贝控制习题解答
### 13.1.1

#### 13.1
```c++
1.如果一个构造函数的第一个参数是自身类类型的引用，且任何额外参数都有默认值，则此构造函数是拷贝构造函数。
2.当我们使用拷贝初始化时会调用拷贝构造函数。
```
#### 13.2
```c++
1.参数类型应该是引用类型。
```
#### 13.3
```c++

```
#### 13.4
```c++
//标记处调用了拷贝构造函数
Point global;
Point foo_bar(Point arg){/* 1 */
    Point local = arg /* 2 */ , *heap = new Point(global)/* 3 */;
    *heap = local;
    Point pa[4] = {local/* 4 */, *heap/* 5 */};
    return *heap;/* 6 */
}
```
#### 13.5
```c++
class HasPtr{
public:
    HasPtr(const std::string &s = std::string()):\
        ps(new std::string(s), i(0)){ }
    HasPtr(const HasPtr &rhs);//新增拷贝构造函数
private:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &rhs):ps(new std::string(*rhs.ps)), i(rhs.i){ }

```

### 13.1.2
#### 13.6
```c++
1.拷贝赋值运算符是一个名为 operator= 的函数。
2.当赋值运算发生时就会用到它。
3.合成拷贝赋值运算符可以用来禁止该类型对象的赋值。
4.如果一个类未定义自己的拷贝赋值运算符，编译器会为它生成一个合成拷贝赋值运算符。
```
#### 13.7
```c++
1.发生浅复制
2.
```
#### 13.8
```c++
HasPtr &HasPtr::operator=(const &rhs){
    string *temp = new string(*rhs.ps);//支持自赋值
    delete ps;
    ps = temp;
    i = rhs.i;
    return *this;
}
```
### 13.1.3
#### 13.9
```c++
1.名字由波浪号接类名构成的成员函数。
2.在一个析构函数中，首先执行函数体，然后销毁成员，成员按逆序销毁。
3.无论何时一个对象被销毁
```