#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
const int maxlen = 100;//размер массива

struct BUY
{
	int row;
	int plase;
};
struct BOOK
{
	int row;
	int plase;
	string name;
};
/*!
	\brief структура
	\author egor
	\version 1.0
	\date 2021
	\warning Данная труктура создана только в учебных целях

*/
struct LISTBUY
{
	BUY elem[maxlen]; // массив элементов списка*   
	int last;  //индекс последнего эл-та списка
};

struct LISTBOOK
{
	BOOK elem[maxlen]; // массив элементов списка*   
	int last;  //индекс последнего эл-та списка
};

bool buyDB();
bool buyB();
bool book();
bool deleteB();
char showbuy();
char showbook();
void free();

LISTBOOK bookTicket;
LISTBUY buyTicket;


int main()
{

	/*fstream F;
	F.open("C:\STR\tickets.txt");
	F>>*/

	int input;
while(1)
{
	cout << "___________MENU___________\n";
	cout << "1. buy a ticket without booking\n";
	cout << "2. buy a ticket by booking\n";
	cout << "3. book a ticket\n";
	cout << "4. delete a reservation\n";
	cout << "5. show booked tickets\n";
	cout << "6. show purchased tickets\n";
	cout << "7. number of available seats\n";
	cout << "8. help\n";
	cout << "9. Exit\n";
	cout << "Selection: ";
	cin >> input;
	switch (input) {
	case 1:
	{
		buyDB();
		break;
	}
	case 2:
	{
		buyB();
		break;
	}
	case 3:
		book();
		break;
	case 4:
		deleteB();
		break;
	case 5:
		showbook();
		break;
	case 6:
		showbuy();
		break;
	case 7:
		free();
		break;
	case 8:
		cout << "help!!!\n";
		break;
	case 9:
		return 0;
	default:
		cout << "Error, bad input, quitting\n";
		break;
	}
}
}

bool buyDB()
{
	int r, p, s=0;
	cout << "row:";
	cin >> r;
	cout << endl << "plase:";
	cin >> p;
	if (bookTicket.last != -1) 
	{
		for (int i = 0; i < bookTicket.last; i++)
		{
			if (r != bookTicket.elem[i].row && p != bookTicket.elem[i].plase)
			{
				buyTicket.last++;
				buyTicket.elem[buyTicket.last].row = r;
				buyTicket.elem[buyTicket.last].plase = p;
				s++;
			}
		}
		if (s >= 1) cout << "error!\n"; //забронирован билет
	}
	else
	{
		buyTicket.last++;
		buyTicket.elem[buyTicket.last].row = r;
		buyTicket.elem[buyTicket.last].plase = p;
	}
		
	return 0;

}

bool buyB()
{
	string name_check;
	int j;
	cout << endl << "name:";
	cin >> name_check;
	for (int i = 0; i < 99; i++)
	{
		if (name_check == bookTicket.elem[i].name)
		{
			buyTicket.last++;
			cout << "+!\n";
			cout << "row:" << bookTicket.elem[i].row << endl;
			cout << "plase:" << bookTicket.elem[i].plase << endl;
			buyTicket.elem[buyTicket.last].row = bookTicket.elem[i].row;
			buyTicket.elem[buyTicket.last].plase = bookTicket.elem[i].plase;
			
		}

	}


	for (j = 0; j < bookTicket.last; j++)
	{

			for (int i = j - 1; i < bookTicket.last; i++)
				//перемещаем на одну позицию вверх
				bookTicket.elem[i] = bookTicket.elem[i + 1];
	}
	bookTicket.last--;
	return 0;
}

bool book()
{
	bookTicket.last++;
	cout << "row:";
	cin >> bookTicket.elem[bookTicket.last].row;
	cout << endl << "plase:";
	cin >> bookTicket.elem[bookTicket.last].plase;
	cout << endl << "name:";
	cin >> bookTicket.elem[bookTicket.last].name;
	return 0;
}

bool deleteB()
{
	int j;
	int s=0;
	string name_check;
	cout << endl << "name:";
	cin >> name_check;

	for (j = 0; j < bookTicket.last; j++)
	{
		if (name_check == bookTicket.elem[j].name)
		{
			for (int i = j - 1; i < bookTicket.last; i++)
				//перемещаем на одну позицию вверх
				bookTicket.elem[i] = bookTicket.elem[i + 1];
			s++;
		}
	}
	if (s<1) cout << "error"<<endl;
	bookTicket.last--;
	return 0;
}




char showbuy()
{
	for (int i = 0; i <= buyTicket.last; i++)
	{
		cout << i+1 << ")"<< " row:" << buyTicket.elem[i].row << " plase:" << buyTicket.elem[i].plase <<endl;
	}
	if(buyTicket.last<0) cout << "no tickets purchased" << endl;
	return 0;
}

char showbook()
{
	for (int i = 0; i <= bookTicket.last; i++)
	{
		cout << i+1 << ")" << " row:" << bookTicket.elem[i].row << " plase:" << bookTicket.elem[i].plase << " name:" << bookTicket.elem[i].name << endl;

	}
	if (bookTicket.last < 0) cout << "no tickets booked" << endl;
	return 0;
}

void free()
{
	cout << "number of tickets booked: " << bookTicket.last+1<<endl;
	cout << "number of tickets purchased: " << buyTicket.last+1 << endl;

}

