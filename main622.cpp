#include <iostream>
#include <fstream>
//#include <iomanip>
#include <vector>
using namespace std;

class liczby622
{
                vector <int> ciag_liczb;
                int max = 0, max_liczba = 0;
       			
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
        plik.open("B:\\Programowanie z Panem Fulaa\\Zadanie Mat 62.1&2\\liczby2.txt", ios::in); 
         if(plik.good()) 
            while(!plik.eof()) 
                  {
                	plik >> wprowadzany;
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
	int liczba = 0;
	int ciag = 0;
	
	for (int i = 0; i < ciag_liczb.size(); i++)
	{
		
		if(ciag_liczb[i] <= ciag_liczb[i + 1])
		{
			ciag++;
			if (ciag == max)
			{
				max_liczba = ciag_liczb[i - max + 1];
			}
			if(ciag > max)
			{
				max = ciag + 1;
			}
		}
		else
		{
			ciag = 0;
		}
	}
	cout << max << endl;
	cout << max_liczba;
}


int liczby622::zapiszDoPliku(const char *nazwa)
{	
        ofstream plik;
        plik.open(nazwa);
    	plik << "Pierwsza liczba ci¹gu: " << max_liczba;
    	plik << "\nD³ugoœæ ci¹gu: " << max;
        plik.close();
        
}



int main()
{
	liczby622 x;
    x.wprowadz();
//    x.wypisz();
    x.obliczanie();
    x.zapiszDoPliku("B:\\Programowanie z Panem Fulaa\\Zadanie Mat 62.1&2\\wynik.txt");
    return 0;
}
