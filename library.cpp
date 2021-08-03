#include "library.h"

#include <iostream>
#include "gstring.h"

void hello() {
    std::cout << "Hello, World!" << std::endl;
}
struct Sphere {
    double radius;
    Sphere(){
        radius = 10;
    }

    Sphere(const double r) {
        radius = r;
    }

    bool operator==(const Sphere * s) const {
        if (s->radius == this->radius){
            return true;
        }
        return false;
    }
    Sphere * tenS(){
        auto a = new Sphere();
        std::cout<<a->radius;
        return a;
    }
};

Sphere * errew(){
    auto a1 = new Sphere(11.0);
    auto a2 = new Sphere(12.0);
    auto a3 = new Sphere(13.0);
    auto s_list = new Sphere * [3];
    s_list[0] = a1;
    s_list[1] = a2;
    s_list[2] = a3;
    return s_list[1];
}
void test(Sphere * s) {

    Sphere * q = new Sphere();
    if ((*s) == q){
        std::cout<< s->radius;
    }
}
void test2(Sphere & s) {
    std::cout<<s.radius;
}

int main() {
    Sphere qqqq = Sphere();
    auto qq = nullptr;
    if(qq) {
        std::cout<<"dasdsadas\n";
    }
    Sphere * s = new Sphere();
    test(s);
    test2(*s);
    auto b = s->tenS();
    std::cout<<b->radius;
    char * p = new char [5];
    std::cout<<p[5];
    p[0] = 'a';
    if (p[0]){
        printf("dsadas");
    }
    if (p[8])
    {
        printf("dsada");
    }
    String a = "aaa";
    std::cout << a;
}

