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

Sales_data::Sales_data(const Sales_data &orig):bookNo(orig.bookNo), \
            units_sold(orig.units_sold), revenue(orig.revenue) {

}

Sales_data &Sales_data::operator=(const Sales_data &rhs) {
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    return *this;
}

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