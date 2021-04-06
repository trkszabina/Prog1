#include "std_lib_facilities.h"

using namespace std;

struct Person
{
	private:
	string first_name,last_name;
	int age;

	public:
	Person(){};
	Person(string f, string l, int a)
	{
		first_name=f;
		last_name=l;
		age=a;
	}

	//getters
	string get_first_name() const {return first_name;}
	string get_last_name() const {return last_name;}
	int get_age() const {return age;}

	//setters
	void set_first_name(string n){first_name=n;}
	void set_last_name(string n){last_name=n;}
	void set_age(int a){age=a;}
};

	ostream& operator<< (ostream& os, Person& p)
	{
		os<<"Name: "<<p.get_first_name()<<" "<<p.get_last_name()<<" age: "<<p.get_age();
		return os;
	}

	istream& operator>> (istream& is, Person& p)
	{
		string first,last;
		int a;
		is>>first>>last;

		for(auto letter : first)
		{
			if(!isalpha(letter) && !isdigit(letter))
			{
				cout<<letter<< " letter"<<endl;
				error("Nem megfelelő név");
			}
		}
		p.set_first_name(first);

		for(auto letter : last)
		{
			if(!isalpha(letter))
			{
				cout<<letter<< " letter"<<endl;
				error("Nem megfelelő név, adjon meg vezetéknevet is!");
			}
		}
		p.set_last_name(last);

		is>>a;

		if(0<=a && a<=150)
			{
				p.set_age(a);
			}
		else
		{
			error("Nem megfelelő kor");
		}
		return is;
	}

int main()
{


	Person p2;

	cout<<"Give name and age:"<<endl;
	cin>>p2;
	cout<<p2<<endl;

	cout<<"Give names to the vector:"<<endl;

	vector<Person> people;
	Person temp;
	int numOfPeople=0;
	while(cin>>temp)
	{
		people.push_back(temp);
		cout<<people[numOfPeople]<<endl;
	}


	return 0;
}
