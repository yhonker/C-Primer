#include <iostream>
#include "Sales_data.h"
#include "Screen.h"
#include "Window_mgr.h"

class NoDefault{
public:
    NoDefault() = default;
    NoDefault(const string&);
};

struct st{

    NoDefault my_mem;
};
int main() {
    Screen sc(50, 50, 's');
    sc.move(2, 2).display(cout).set('h').display(cout);
    cout<<sc.get(2, 2)<<endl;
    Window_mgr wm;


    st s1;
    return 0;
}
