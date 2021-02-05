#include <iostream>
#include <fstream>
//#include <iomanip>
#include <vector>
using namespace std;

class liczby622
{
                vector <int> ciag_liczb;
                int min = 0, max = 0;
       			
        public:
                void wprowadz();
                void wypisz();
                int obliczanie();
                int sprawdzenie(int x, int y);
                int zapiszDoPliku(const char *);             
};

void liczby622::wprowadz()
{

		fstream plik;  
        int wprowadzany;
        plik.open("B:\\Programowanie z Panem Fulaa\\Zadanie Mat 62.1&2\\liczby1.txt", ios::in); 
         if(plik.good()) 
            while(!plik.eof()) 
                  {
                	plik >> oct >> wprowadzany;
                	ciag_liczb.push_back(wprowadzany);
                   }
                   plik.close();   
}


void liczby622::wypisz()
{
		for (int i = 0; i < ciag_liczb.size(); i++)
		{
			cout << ciag_liczb[i] << "\n";
		}
}

int liczby622::obliczanie()
{
	min = ciag_liczb[0];
	for (int i = 0; i < ciag_liczb.size(); i++)
		{
			if (ciag_liczb[i] < min)
			{
				min = ciag_liczb[i];
			}
			if (ciag_liczb[i] > max)
			{
				max = ciag_liczb[i];
			}
			
		}
}


int liczby622::zapiszDoPliku(const char *nazwa)
{	
        ofstream plik;
        plik.open(nazwa);
    	plik << "Najmniejsza liczba : " << min;
    	plik << "\nNajwieksza liczba: " << max;
    	plik << "\nNajmniejsza liczba : " << oct  << min;
    	plik << "\nNajwieksza liczba: " << oct << max;
        plik.close();
        
}



int main()
{
	liczby622 x;
    x.wprowadz();
//    x.wypisz();
    x.obliczanie();
    x.zapiszDoPliku("B:\\Programowanie z Panem Fulaa\\Zadanie Mat 62.1&2\\wynik1.txt");
    return 0;
}
