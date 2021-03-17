#include <iostream>

using namespace std;

/*class Purevirtual{
public:
	virtual void pvf() = 0;
};
*/
struct B1 
{
    virtual void vf() { cout << "B1::vf\n"; }
    void f() { cout << "B1::f\n"; }
    virtual void pvf() { cout << " B1::pvf\n"; }
};

struct D1 : B1 
{
    void vf() override { cout << "D1::vf\n"; }
    void f() { cout << "D1::f\n"; }
};


struct D2 : D1 
{
	void pvf() override { cout << "D2::pvf\n"; }
};

struct B2
{
	virtual void pvf() = 0;
};

struct D21 : B2
{
	string s = "itt valamiert mukodik a pure virtual function 0-val, B1-nel nem";
	void pvf() override { cout << s << '\n'; }
};

struct D22 : B2
{
	int i = 548;
	void pvf() override { cout << i << '\n'; }
};

void f(B2& b2ref){
	b2ref.pvf();
}

int main()
{
	
	B1 b;
    b.vf();
    b.f();

    D1 d;
    d.vf();
    d.f();

    B1& ref {d};
    ref.vf();
    ref.f();
	

    D2 dd;
    dd.vf();
    dd.f();
    dd.pvf();

    D21 d21_string;
    D22 d22_int;

    f(d21_string);
    f(d22_int);

}