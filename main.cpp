#include <iostream>
#include "Sales_data.h"
#include "Screen.h"
#include "Window_mgr.h"
int main() {
    Screen sc(50, 50, 's');
    sc.move(2, 2).display(cout).set('h').display(cout);
    cout<<sc.get(2, 2)<<endl;
    Window_mgr wm;


    return 0;
}
