#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class file {
	protected:
		ifstream input;
 		ofstream output;
 		
 		double licznik;
 		double minaownik;
		
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

class zadanie65_1 :public file{
	private:
		vector<double> result; 
	public:
		virtual void loop();
		void findMin();
};

void zadanie65_1::loop() {
	input>>licznik;
	input>>minaownik;
}

void zadanie65_1::findMin() {
	result.push_back(1);
	
	while (!input.eof()) {
		this->loop();

		if (licznik / minaownik < result[0]) {
			result.clear();
			
			result.push_back(licznik / minaownik);
			result.push_back(licznik);
			result.push_back(minaownik);
		}		
	};
	cout<<result[0];
}

int main(int argc, char** argv) {
	zadanie65_1 l;
	l.findMin();
	return 0;
}
