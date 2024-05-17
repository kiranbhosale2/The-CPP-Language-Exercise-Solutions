
//∗1) Find the error in Date::add_year() in §16.2.3. Then find two additional errors in the ver-sion in §16.2.10.
#include <unistd.h>
#include <iostream>
using namespace std;

class Date {
    int d, m, y;
    public:
    void init(int dd, int mm, int yy);
    void add_year(int n); // Add n years 
    void add_month(int n); // Add n months
    void add_day(int n); // Add n days
     void print_date(void); 
};

bool is_leap_year( int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void Date::init(int dd, int mm, int yy)
{
   y = yy;
   m = mm;
   d = dd;
}

void Date::add_year(int n)
{
    if ((m == 2 ) && (d == 29) && !is_leap_year(y + n)) {
        // If the current date is February 29 and the resulting year is not a leap year,
        // adjust the date to February 28.
       d = 28;
    }

     y += n;
}

void Date::add_month(int n)
{
    m += n;
}

void Date::add_day(int n)
{
    d += n;
}

void Date::print_date(void)
{
    cout << "date: " << d << " "<<  m << " " << y << endl; 
}


int main() {
    Date x;
    x.init(23, 7, 1988);
    x.add_year(5);
    x.print_date();
}


