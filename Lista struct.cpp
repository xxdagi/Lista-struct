// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

struct element
{
	int id{};
	string nazwa{};
	element* nastepny = nullptr;
};
struct lista1k
{
	element* head = nullptr;
	int liczbaElementow{};
	void wyswietl();
	void dodaj();
	void usun();
	void menu();
	void sortuj();
};

void lista1k::wyswietl()
{
	if (head == nullptr)
		cout << "Brak elementow w liscie." << endl;
	else
	{
		element* e = head;
		cout << "Ilosc elementow w liscie:" << " " << liczbaElementow << endl << endl;

		cout << "ID" << "\t" << "NAZWA" << "\t\t"
			<< "ADRES ELEMENTU" << "\t\t" << "ADRES NASTEPNEGO ELEMENTU" << endl;

		while (e != nullptr)
		{
			cout << e->id << "\t" << e->nazwa << "\t\t" << e << "\t" << e->nastepny << endl;
			e = e->nastepny;
		}
	}
}
void lista1k::dodaj()
{
	element* nowy = new element();

	cout << "Podaj ID elementu:" << " "; cin >> nowy->id;
	cout << "Podaj nazwe elementu:" << " "; cin >> nowy->nazwa;

	if (head == nullptr)
	{
		head = nowy;
		++liczbaElementow;
	}
	else
	{
		nowy->nastepny = head;
		head = nowy;
		++liczbaElementow;
	}
	cout << endl;
}

void lista1k::usun()
{
	int idUsuswania;
	cout << endl << "Podaj ID elementu do usuniecia:" << " "; cin >> idUsuswania;

	if (head == nullptr)
	{
		cout << "Lista jest pusta, brak elementow do usuniecia." << endl;
		return;
	}
	else
	{
		element* usun = head;

		if (idUsuswania == head->id)
		{
			head = head->nastepny;
			delete usun;
			--liczbaElementow;
		}
		else
		{
			element* poprzedni = head;
			usun = head->nastepny;

			while (usun->id != idUsuswania)
			{
				if (usun->nastepny == nullptr)
				{
					cout << "Brak elementu o podanym ID do usuniecia";
					return;
				}
				else
				{
					usun = usun->nastepny;
					poprzedni = poprzedni->nastepny;
				}
			}
			--liczbaElementow;
			poprzedni->nastepny = usun->nastepny;
			delete usun;
		}
	}
}

void lista1k::sortuj() 
{
	element* current = head;

	if (head == nullptr)
		return;
	else
	{
		
	}
}

void lista1k::menu()
{
	cout << "DODAJ" << setw(5) << "1" << endl;
	cout << "USUN" << setw(6) << "2" << endl;
	cout << "WYSWIETL" << setw(2) << "3" << endl;
	cout << "SORTUJ" << setw(4) << "4" << endl;
	cout << "ZAKONCZ" << setw(3) << "5" << endl;


	while (true)
	{
		int op;
		cout << "\n->" << " "; cin >> op;

		switch (op)
		{
		case 1: dodaj();
			break;
		case 2: usun();
			break;
		case 3: wyswietl();
			break;
		case 4: sortuj();
		case 5: break;
		}
		false;
	}
}


int main()
{
	lista1k lista;
	lista.menu();

	return 0;
}