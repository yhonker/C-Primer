## 重载运算与类型转换习题解答

### 14.1

#### 14.1
```c++
当一个重载的运算符是成员函数时，this 绑定到左侧运算对象。成员运算符函数的（显式）参数数量比运算对象的数量少一个.
```
#### 14.2
```c++
    //重载运算符与类型转换
    //重载+
    friend Sales_data operator+(const Sales_data& a, const Sales_data& b);
    //重载<<
    friend ostream& operator<<(ostream& out, const Sales_data& a);
    //重载>>
    friend istream& operator>>(istream& in, Sales_data& a);

    Sales_data operator+(const Sales_data& a, const Sales_data& b);

    ostream& operator<<(ostream& out, const Sales_data& a);

    istream& operator>>(istream& in, Sales_data& a);
    
    Sales_data operator+(const Sales_data& a, const Sales_data& b){
        Sales_data sum;
        sum = a;
        sum.units_sold += b.units_sold;
        sum.revenue += b.revenue;
        return sum;
    }
    
    ostream& operator<<(ostream& out, const Sales_data& a){
        out<<a.bookNo<<" "<<a.units_sold<<" "<<a.revenue<<endl;
        return out;
    }

    istream& operator>>(istream& in, Sales_data& a){
        cout<<"bookNo：";
        in>>a.bookNo;
        return in;
    }
```
#### 14.3
```c++
1.没有重载的 == 2.string的 == 3.vector的 == 4.string的 ==
```
#### 14.4
```c++
1.非成员 2.成员 3.成员 4.成员 5.非成员 6.非成员 7.非成员 8.成员
```
#### 14.5
```c++
略...
```
