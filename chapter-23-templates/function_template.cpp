#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

template<typename T>
void sort(vector<T>& v) 
{
    const size_t n = v.size();
    for (int gap=n/2; 0<gap; gap/=2)
    {
        for (int i = gap; i < n; i++)
        {
            for (int j=i-gap; 0<=j; j-=gap)
            {
                if (v[j+gap]<v[j]) { // swap v[j] and v[j+gap]
                    T temp = v[j];
                    v[j] = v[j+gap];
                    v[j+gap] = temp;
                }
            }
        }
    }
}

template<typename T, typename S>
void print_sorted(vector<T>& v, S sort, ostream& os)
{
    sort(v);
    for (const T& x : v)
    os << x << '\n';
}

int main() {
    vector<int> vi{1, 4, 5 ,8, 3, 5, 9};
    vector<string> vs{"kiran", "bhosale", "at", "post", "madaj"};
    print_sorted(vi, sort<int>, std::cout);
    print_sorted(vs, sort<string>, std::cout);
}