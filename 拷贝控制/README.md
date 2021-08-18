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
#### 13.6
```c++

```