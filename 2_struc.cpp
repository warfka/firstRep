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
//char showbook();

LISTBOOK bookTicket;
LISTBUY buyTicket;


int main()
{

	/*fstream F;
	F.open("C:\STR\tickets.txt");
	F>>*/

	int input;
	start:
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
		//deleteB();
		break;
	case 5:
		showbuy();
		break;
	case 6:
		//showbook();
		break;
	case 7:
		cout << "thank you for using it\n";
		break;
	case 8:
		cout << "thank you for using it\n";
		break;
	case 9:
		return 0;
	default:
		cout << "Error, bad input, quitting\n";
		break;
	}
	cin.get();
	goto start;
}

bool buyDB()
{
	cout << "row:";
	cin >> buyTicket.elem[buyTicket.last].row;
	cout << endl << "plase:";
	cin >> buyTicket.elem[buyTicket.last].plase;
	buyTicket.last++;
	return 0;

}

bool buyB()
{
	string name_check;
	cout << endl << "name:";
	cin >> name_check;
	for (int i = 0; i < 99; i++)
	{
		if (name_check == bookTicket.elem[i].name)
		{
			cout << "+!\n";
			cout << "row:" << bookTicket.elem[i].row << endl;
			cout << "plase:" << bookTicket.elem[i].plase << endl;
		}
		
	}

	return 0;
}

bool book()
{
	cout << "row:";
	cin >> bookTicket.elem[0].row;
	cout << endl << "plase:";
	cin >> bookTicket.elem[0].plase;
	cout << endl << "name:";
	cin >> bookTicket.elem[0].name;
	bookTicket.last++;
	return 0;
}
/*
bool deleteB()
{
	string name_check;
	cout << endl << "name:";
	cin >> name_check;
	for (int i = 0; i < 99; i++)
	{
		if (name_check == bookTicket.elem[i].name)
		{
			cout << "+!\n";
			bookTicket.elem[i].name = NULL;
			bookTicket.elem[i].row = NULL;
			bookTicket.elem[i].plase = NULL;
		}
	}

	return 0;
}*/

bool Delete(int pos, LISTBOOK* L)
{
	if (pos > L->last + 1 || pos < 1)
		return false;
	else if (pos < L->last + 1) // не последний элемент
	{
		for (int i = pos - 1; i < L->last; i++)
			//перемещаем на одну позицию вверх
			bookTicket.elem[i] = bookTicket.elem[i + 1];
	}
	L->last--;
	return true;
}


char showbuy()
{
	struct list* p;
	for (int i = 0; i <= buyTicket.last; i++)
	{
		printf("%d ", bookTicket.elem[i]); 
	}
	return 0;
}



/*
int main()
{
	LIST number_list;
	for (int i = 0; i < 5; i++) // список из 5 чисел
	{
		numberList.elem[i] = i + 1;
		cout << number_list.elem[i] << endl;
	}
	number_list.last = 4;
	// ...
	return 0;
}*/

