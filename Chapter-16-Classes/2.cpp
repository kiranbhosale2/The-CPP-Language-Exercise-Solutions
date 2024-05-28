#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tracer {
    string mess;
    Tracer(const string& s) :mess{s} { clog << mess; }
    ~Tracer() {clog << "~" << mess; }
};
void f(const vector<int>& v)
{
    Tracer tr {"in f()\n"};
    for (auto x : v) {
    Tracer tr {string{"v loop "} +'\n'}; // §25.2.5.1
    // ...
    }
}

int main()
{
    f({1,2,3});
}