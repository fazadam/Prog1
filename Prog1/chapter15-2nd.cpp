/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "std_lib_facilities.h"

struct Person {
    Person() {}
    Person(string f_name, string l_name, int aa); //constructor

    string first_name() const { return first; } //adat get
    string last_name() const { return last; }
    int age() const { return a; }


private:
    string first;
    string last;
    int a;
};

Person::Person(string f_name, string l_name, int aa) //adatellenorzes
    : first{f_name}, last{l_name}, a{aa}
{
    if (aa < 0 || 150 < aa) error("nem letezo ev");
    
    string nevegyutt = f_name + l_name;       
    for (char c : nevegyutt) {
        switch(c) {
            case ';': case ':': case '"': case '[': case ']': case '*':
            case '&': case '^': case '%': case '$': case '#': case '@':
            case '!':
                error("nem ervenyes nev");
                break;
            default:
                break;
        }
    }
}


istream& operator >>(istream& is, Person& p)
{
	string keresztnev;
	string vezeteknev;
	int a;

	is >> keresztnev >> vezeteknev >> a;
	p = Person(keresztnev,vezeteknev,a); //behivni a person mem funt ami ellenorzi h nem e hibas az adat
	return is;
}

ostream& operator<<(ostream& os,Person& p)
{
	return os << p.first_name() << ' ' << p.last_name() << '\n' << p.age();
}



int main() {

	// Person example_person;
	// example_person.first_name = "Goofy";
	// example_person.age = 63;
	// cout << example_person.name << ", age: " << example_person.age << endl;


	cout << "Enter name and age" << endl;
	Person p;
	cin >> p;
	cout << p << endl;


	cout << "Enter names for testing the vector" << endl;
	vector<Person> testpeople;
	Person p3;

	for (Person p; cin >> p;) //betolteni a vectorba az inputot
	{
		if(p.first_name() == "end") break;
		testpeople.push_back(p);
	}

	for(Person p : testpeople) //kiirni a vectorba betoltott inputokat a screenre
		cout << p << endl; //abban az esetben all le, ha rossz inputot kapott
}