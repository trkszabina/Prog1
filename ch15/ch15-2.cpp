#include "std_lib_facilities.h"

using namespace std;

struct Person
{
	Person() {}
	Person(string ff, string ll, int aa);

	string first_name() const { return f; }
	string last_name() const { return l; }
	int age() const { return a; }

private:
	string f;
	string l;
	int a;
};

Person::Person(string ff, string ll, int aa)
	: f{ff}, l{ll}, a{aa}
{
	if (aa < 0 || aa > 150) error("Invalid age");
	string name = ff + ll;
	for ( char c : name ){
		switch(c){
			case ';': case ':': case '"': case '\'': case '[': case ']': case '*': 
			case '&': case '^': case '%': case '$': case '#': case '@': case '!':
			error("Invalid character(s)");
		}

	}
}
ostream& operator<<(ostream& os, Person& p)
{
	return os << p.first_name() << ' ' << p.last_name() << ' ' << p.age();
}

istream& operator>>(istream& is, Person& p)
{
	string f;
	string l;
	int a;
	is >> f >> l >> a;

	if(!is) error("input error...");

	return is;
}




int main()
{


    vector<Person> persons;
    Person p4;

    cout << "Please enter the name and age(First name, Second name, Age): " << endl;

    while (cin>>p4)
    {
       persons.push_back(p4);
    }
    for (int i = 0; i<persons.size(); ++i)
    {
      cout << persons[i] << endl;
    }       
    
    keep_window_open();
}
