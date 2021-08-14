//
// Created by honker on 2021/8/14.
//

#ifndef CPPTRAIN_OTHER_H
#define CPPTRAIN_OTHER_H


class Other {

};

class ConstRef{
public:
    ConstRef(int ii);

private:
    int i;
    const int ci;
    int &ri;
};

/*错误:ci和ri必须被初始化
ConstRef::ConstRef(int ii) {
    i = ii;
    ci = ii;
    ri = i;
}
*/

//正确
ConstRef::ConstRef(int ii):i(ii),ci(ii),ri(i){}

class X{
    int i;
    int j;
public:
    //未定义的：i在j之前被初始化
    //X(int val):j(val),i(j){}
    //正确
    X(int val):j(val),i(val){}
};

#endif //CPPTRAIN_OTHER_H
