#include <iostream>
//#include <clocale>
#include <cstdlib>
using namespace std;
//----- объявление прототипов используемых функций----------------------------------------
void Input(int* M,int n);  // ввод массива
void Print(int* M,int n);   // вывод массива
void RandomFill(int* M,int n);   // заполнение массива случайными числами
//--------------------------------------------------------------------------
int Work(int* M,int n);   // пример обработки массива
//   Сюда добавить протопипы тех функций которые дополнительно напишете
//--------------------------------------------------------------------------
 
//----------  main() -  точка входа в программу консольного приложения 
int main()
{
    //setlocale(LC_ALL,"Rus");
    int n;
    cout<<"Размер вектора?";
    cin>>n;
    int* A=new int[n];
    //Input(A,n);
    RandomFill(A,n);
    Print(A,n); 
    int s=Work(A,n);
    cout<<"Summa = " << s<< endl;
    delete[] A;
    //system("pause");
    return 0;
}
//----   описание функций -----------------------------------------
// ввод массива
void Input(int* M,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"M["<<i<<"]=?";
            cin >> M[i];
    }
}
// заполнение случайными числами
void RandomFill(int* M,int n)
{
    for(int i=0;i<n;i++)
    {
        M[i]=rand()%100;
    }
}
  // вывод массива
void Print(int* M,int n)
{
    for(int i=0;i<n;i++)
    {
        cout << M[i]<< " ";
    }
    cout << endl;
}
// пример обработки - подсчет суммы элементов
int Work(int* M,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=M[i];
    }
    return sum;
}
