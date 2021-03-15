#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class file {
	protected:
		ifstream input;
 		ofstream output;
 		
 		int licznik;
 		int mianownik;
		
		file();
		~file();
		
		virtual void loop()=0;;
};

file::file() {
	input.open("c:\\dane_ulamki.txt");
 	output.open("wyjscie.txt");
 	if (!input.good())
    {
        cerr << "Blad - pliku nie da sie otworzyc!\n";
        exit(1);
    }
}

file::~file() {
	input.close();
 	output.close();
}

class zadanie65_2 :public file{
	private:
		vector<int> results;
		
		virtual void loop();
		
		int nwd(int a, int b);
		 
	public:
		void find();
		void show();
};

void zadanie65_2::loop() {
	input>>licznik;
	input>>mianownik;
}

int zadanie65_2::nwd(int a, int b)
{
   if(a!=b)
     return nwd(a>b?a-b:a,b>a?b-a:b);
   return a;
}

void zadanie65_2::find() {
	while (!input.eof()) {
		this->loop();
		
		if (this->nwd(licznik, mianownik) == 1) {
			results.push_back(licznik);
			results.push_back(mianownik);
		}
	}
}

void zadanie65_2::show() {
	for ( int i = 0; i < results.size() - 1; i+=2) {
		cout<<results[i]<<"/"<<results[i+1]<<endl;
	}
}

int main()
{
    zadanie65_2 l;
    l.find();
    l.show();
    return 0;
}
