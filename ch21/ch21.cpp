#include "std_lib_facilities.h"

struct Item
{								 
	Item(string n, int i, double v): nev(n), iid(i), ertek(v) {}
	                  
	string nev;
	int iid;
	double ertek;
};

ostream& operator<<(ostream& os, const Item& i)
{
	os << i.nev << ' ' << i.iid << ' ' << i.ertek;
	return os;
}
	
template<typename Iter> 
void kiir(const Iter& elso, const Iter& utolso)
		
{
	for (auto a = elso; a != utolso; ++a)
		
		cout << *a << endl;
}		

class SameName
{
private:
	string nev;
public:
	SameNev(const string &s): nev{s} {}
	bool operator()(const Item& i) const { return i.nev == nev; }
	
};

class SameId
{
private:
	int id;
public:
	SameId(const int& idd): id(idd) {}
	bool operator()(const Item& i) const { return i.iid == id; }
};

void feladat1()
{
	vector<Item> vi;
	string n;
	int id;
	double val;

	string filename = "ch21adatok1.txt";
	ifstream is {filename};
	if (!is) cout << "Nincs ilyen txt a könyvtárban!" << endl;

	
	while (is >> n >> id >> val) { vi.push_back(Item{n, id, val}); }

	sort(vi.begin(), vi.end(),
		[] (const Item& i1, const Item& i2){ return i1.nev < i2.nev; });
	sort(vi.begin(),vi.end(),
		[] (const Item& i1, const Item& i2){ return i1.iid < i2.iid; });
	sort(vi.begin(),vi.end(),
		[] (const Item& i1, const Item& i2){ return i1.ertek > i2.ertek; });

	cout << "Sorbarendezés után:\n";
	kiir(vi.begin(), vi.end());
	cout << endl;

	vi.insert(vi.end(), Item{"item1", 99, 12.34});
	vi.insert(vi.end(), Item{"item2", 9988, 499.95});
	cout << "\nInsert parancs után:\n";
	kiir(vi.begin(), vi.end());
	cout << endl;

	auto nev_torles = find_if(vi.begin(), vi.end(), SameName("item3"));
	vi.erase(nev_torles);
	auto id_torles = find_if(vi.begin(), vi.end(), SameId(55));
	vi.erase(id_torles);
	cout << "\nErase parancs után:\n";
	kiir(vi.begin(), vi.end());
	cout << endl;
}

bool RendezName(const Item& item1, const Item& item2)
{
	return item1.nev < item2.nev;
}
bool RendezId(const Item& item1, const Item& item2)
{
	return item1.iid < item2.iid;
}
bool RendezErtekCsokk(const Item& item1, const Item& item2)
{
	return item1.ertek > item2.ertek;
}

void feladat2() 
{
	list<Item> li;
	string n;
	int id;
	double val;

	
	string filename = "ch21adatok1.txt";
	ifstream is {filename};
	if (!is) cout << "Nincs ilyen txt a könyvtárban!" << endl;

	while (is >> n >> id >> val) { li.push_back(Item{n, id, val}); }

	
	li.sort(RendezName);

	li.sort(RendezId);

	li.sort(RendezErtekCsokk);

	cout << "Sorbarendezés után:\n";
	kiir(li.begin(), li.end());
	cout << endl;

	li.insert(li.end(), Item{"item1", 99, 12.34});
	li.insert(li.end(), Item{"item2", 9988, 499.95});
	cout << "\nInsert parancs után:\n";
	kiir(li.begin(), li.end());
	cout << endl;

	auto nev_torles = find_if(li.begin(), li.end(), SameNev("item3"));
	li.erase(nev_torles);
	auto id_torles = find_if(li.begin(), li.end(), SameId(55));
	li.erase(id_torles);
	cout << "\nErase parancs után:\n";
	kiir(li.begin(), li.end());
	cout << endl;
}


void map_beolavsas(map<string, int>& m)
{
	string szoveg;
	int szam;
	cin >> szoveg >> szam;
	m.insert({szoveg, szam});
}

template<typename T1, typename T2>
void kiir_map(const map<T1, T2> mapp)
{
	for (const auto& e : mapp) cout << e.first << ' ' << e.second << endl;
}

double map_osszead(const map<string, int>& mapp)
{
	int sum = 0;
	for (const auto& e : mapp) sum += e.second;
	return sum;
}

void feladat3()
{
	map<string, int> msi;
			
	msi.insert({"kocka", 12});
	msi.insert({"telefon", 33});
	msi.insert({"laptop", 83});
	msi.insert({"haromszog", 4});
	msi.insert({"negyszog", 92});
	msi.insert({"otszog", 62});
	msi.insert({"hatszog", 45});
	msi.insert({"asztal", 81});
	msi.insert({"szek", 11});
	msi.insert({"villany", 24});

	cout << "A map (msi) elemei:\n";
	kiir_map(msi);
	cout << endl;

	msi.erase(msi.begin(), msi.end());
}

void feladat4()
{
	string filename = "ch21adatok2.txt";
	ifstream is {filename};
	if (!is) cout << "Nincs ilyen txt a könyvtárban!" << endl;

	vector<double> vd;
	double adatok;
	while (is >> adatok) { vd.push_back(adatok); }

	cout << "Elemei a vd-nek:\n";
	kiir(vd.begin(), vd.end());
	cout << endl;

	vector<int> vi(vd.size());
	copy(vd.begin(), vd.end(), vi.begin());

	cout << "\n  vd\tvi\n";
	for (int i = 0; i < vi.size(); ++i) cout << vd[i] << ' ' << vi[i] << endl;
	cout << endl;

	double vdsum;
	for (int i = 0; i < vd.size(); ++i)
		vdsum=vdsum+vd[i];
	cout << "vd összeadva: " << vdsum << endl;

	double visum;
	for (int i = 0; i < vi.size(); ++i)
		visum=visum+vi[i];

	double kulonbseg = vdsum - visum;
	cout << "A vd és vi közötti különbség:\t" << kulonbseg << endl;

	reverse(vd.begin(), vd.end());
	cout << "Az elemek megfordítva (vd):\n";
	kiir(vd.begin(),vd.end());
	cout << endl;

	double atlag = vdsum/vd.size();
	cout << "A vd átlaga: " << atlag << endl;

	vector<double> vd2;
	for (int i = 0; i < vd.size(); ++i)
		if(vd[i]<atlag) vd2.push_back(vd[i]);
	cout << "\nvd2 elemei ( vd2 elemei < vd átlaga ):\n";
	kiir(vd2.begin(), vd2.end());
	cout << endl;

	sort(vd.begin(), vd.end());
	cout << "A vd elemi sorbarendezve:\n";
	kiir(vd.begin(), vd.end());
}

int main()
try{

	feladat1();
	feladat2();
	feladat3();
	feladat4();
	return 0;

}
