#include <bits/stdc++.h>
using namespace std;
static int seq=0;
struct IFoo
{
    virtual void foo() = 0;
    virtual ~IFoo() {}
};

struct IBar
{
    virtual void bar() = 0;
    virtual ~IBar() {}
};


struct Object : public IFoo, public IBar
{
    void foo() override
    {
        cout << "foo called" << endl;
    }

    void bar() override
    {
        cout << "bar called" << endl;
    }
};

void test(IFoo& fooObj)
{
// : " << std::chrono::high_resolution_clock::now().time_since_epoch().count()%10000000 << endl;
    cout << "Sequence Count: " << ++seq << endl;
    fooObj.foo();
    auto other = dynamic_cast<IBar*>(&fooObj);
    if (other)
    {
// : " << std::chrono::high_resolution_clock::now().time_since_epoch().count()%10000000 << endl;
cout << "Sequence Count: " << ++seq << endl;
        other->bar();   
    }
}

void test(IBar& barObj)
{
// : " << std::chrono::high_resolution_clock::now().time_since_epoch().count()%10000000 << endl;
    cout << "Sequence Count: " << ++seq << endl;
    barObj.bar();
    auto other = dynamic_cast<IFoo*>(&barObj);
    if (other)
    {
// : " << std::chrono::high_resolution_clock::now().time_since_epoch().count()%10000000 << endl;
        cout << "Sequence Count: " << ++seq << endl;
        other->foo();   
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    Object obj;
    
    test(static_cast<IFoo&>(obj));
    test(static_cast<IBar&>(obj));
    return 0;
}
