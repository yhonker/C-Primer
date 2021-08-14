#include <iostream>
#include "类/Sales_data.h"
#include "类/Screen.h"
#include "类/Window_mgr.h"

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



    st s1;
    return 0;
}
