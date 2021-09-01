#include "library.h"

#include <iostream>
#include "gstring.h"
#include "gset.h"
#include "random"

void hello() {
    std::cout << "Hello, World!" << std::endl;
}
struct Sphere {
    long radius{};
    Sphere() {
        radius = random();
    }

    explicit Sphere(const long r) {
        radius = r;
    }

    bool operator==(const Sphere & s) const {
        if (s.radius == this->radius){
            return true;
        }
        return false;
    }
};

long long helper(long long n1, long long n2) {
    long long out = 1;
    for (int i=0; i<n1; i++) {
        out = out * 2 % (1000000007);
    }
    for (int j=0; j<n2; j++) {
        out = out * 3 % (1000000007);
    }
    return out;
}

int main() {
    const long long MOD = 10e9 + 7;
    long long out = 1;
    out = out * 4 % MOD;
    for (int i=0; i<22; i++) {
        out = out * 3 % MOD;
    }

    std::cout<<helper(2, 22)<<"\n";
    std::cout<<pow(3, 3333)<<"\n";

    int a = 200000000;
    int b = a*10;
    auto tt = 11^11;
    std::cout<< tt <<"\n";

    std::cout<<'b' - 'a';
    int * we = new int [3];
    char aa [3] = {'a', 'b', 'c'};
    char bb [3] = {'a', 'd', 'e'};
    int ee[3] = {1,2,3};

    Sphere qqq[5];
    for(auto & i : qqq){
        i = *new Sphere();
    }
    auto p = Set<Sphere>(qqq, 5);
    auto s = Set<char>(aa, 3);
    auto cc = Set<char>(bb, 3);
    auto dd = Set<int>(ee, 3);
    s = s*cc;
    s.print();
}

