//
// Created by honker on 2021/8/10.
//

#ifndef CPPTRAIN_SALES_DATA_H
#define CPPTRAIN_SALES_DATA_H
#include <bits/stdc++.h>
using namespace std;

class Sales_data {
public:
    Sales_data() = default;
    explicit Sales_data(const string& s):bookNo(s){}//explicit禁止隐式转换
    Sales_data(const string& s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n){}
    explicit Sales_data(istream& is);

    // const修饰this
    string isbn(/*隐式传入(对象地址)this*/) const{ return bookNo;}//this->bookNo
    Sales_data& combine(const Sales_data& rhs);

    //友元
    friend Sales_data& add(const Sales_data& sda, const Sales_data& sdb);

    //显式定义合成拷贝函数
    /*Sales_data(const Sales_data &orig) = default;*/

    //等价于合成的拷贝构造函数, 不是引用类型会形成循环调用拷贝构造函数
    Sales_data(const Sales_data &orig);

    //等价于合成拷贝赋值运算符
    Sales_data &operator=(const Sales_data &rhs);



private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double avg_price() const;

};


Sales_data& add(const Sales_data& sda, const Sales_data& sdb);

/*ostream &print(ostream&, const Sales_data&);

istream &read(istream&, Sales_data&);*/



#endif //CPPTRAIN_SALES_DATA_H
