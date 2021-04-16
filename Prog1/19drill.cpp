#include "std_lib_facilities.h"

template <typename T>
struct S{
public:
	explicit S(T v) : val{v} {}; //constructor
	T& get(); //getter const nelkul
	const T& get() const; //getter constal
	S& operator = (const T& new_val); //uj ertek megadas T referenciaval
private: 
	T val; //make val private
};

//uj ertek adasa 
template <typename T> // drill 10. lepese --> 9. set() helyett
S<T>& S<T>::operator= (const T& new_val) //uj ertekhez operator --> erteknek uj erteket megadni es *thissel visszadni
{
    val=new_val;
    return *this; //argument new_val-ra vonatkozik
}

//getter constal
template <typename T>
const T& S<T>:: get() const //get consttal fv T referencere drill 12.
    {
        return val;
    }

//get nem const tagokra
template <typename T>
T& S<T>:: get() //get consttal fv T referencere drill 12.
    {
        return val;
    }    

//ertek beolvaso istream operatorral + read val
template<class T> istream& operator>>(istream& is, S<T>& value)
{
    T v;
    cin >> v;
    if (!is) return is; //istream tesztelese h nem e ures
  	value = v;	//ertekul adasa
    return is;
}

template<class T> void read_val(T& v)
{
    cin >> v;
}

//bonus feladat vector beolvasas + kiiras
template <typename T>
ostream& operator<< (ostream& os, vector<T>& v)
{
    os<<"{";

    for(auto elem : v)
        os<<elem<<(elem==v[v.size()-1] ? "" : ", "); // conditional operator. 
    os<<"}";

    return os;
}

template <typename T>
istream& operator>> (istream& is, vector<T>& v)
{
    char ch;
    is>>ch;
    if(ch!='{')
        is.unget();
    int val;
    while(is>>val)
    {
        v.push_back(val);
        is>>ch;
        if(ch!=',')
            break;
    }

    return is;
}


int main()
{
	S<int> s_integer(123);
	S<char> s_char('*');
	S<double> s_double(12.5826);
	S<string> s_string("mizu");
    S<vector<int>> s_vector {vector<int>{1, 1, 2, 3, 5, 8}};
    	
    /*
	cout << s_string;
	cout << s_double;
	cout << temp_using_int;
	cout << s_char;
	*/

	cout << "s_integer= " << s_integer.get() << '\n' ;
	cout << "s_char= " << s_char.get() << '\n' ;
	cout << "s_string= " << s_string.get() << '\n' ;
	cout << "s_double= " << s_double.get() << '\n' ;


	cout << "enter a string= ";
	string ss;
	read_val(ss);
	cout << "string is = "<< ss << '\n';

	cout << "enter a integer= ";
	int ii;
	read_val(ii);
	cout << "integer is = " << ii << '\n';

	cout << "enter a double= ";
	double dd;
	read_val(dd);
	cout << "double is = " << dd << '\n';

	cout << "enter a char= ";
	char cc;
	read_val(cc);
	cout << "char is = "<< cc <<'\n';

	cout << "enter 1 or more numbers in format {val,val,val}" << '\n';
	vector<int> numbers;
	read_val(numbers);
	cout << "read value - integer " << numbers << '\n';


 
}