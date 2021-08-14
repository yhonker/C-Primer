//
// Created by honker on 2021/8/10.
//

#include "Sales_data.h"



Sales_data& Sales_data::combine(const Sales_data& rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const {
    return 0;
}

/*Sales_data::Sales_data(istream &is) {
    read(is, *this);
}


ostream& print(ostream& os, const Sales_data& sd){
    os<<sd.isbn()<<" "<<sd.units_sold<<" "<<sd.revenue<<" "<<sd.avg_price();
    return os;
}

istream& read(istream& is,  Sales_data& sd){
    double price;
    is>>sd.bookNo>>sd.units_sold>>price;
    sd.revenue = price * sd.units_sold;
    return is;
}*/

Sales_data& add(const Sales_data& sda, const Sales_data& sdb){
    Sales_data sdc = sda;//copy
    sdc.combine(sdb);
    return sdc;
}

