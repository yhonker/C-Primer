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
Point global;
Point foo_bar(Point arg){
    Point local = arg, *heap = new Point(global);
    *heap = local;
    Point pa[4] = {local, *heap};
    return *heap;
}
```