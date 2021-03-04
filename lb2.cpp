#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
setlocale (LC_ALL, "RUS");
int i,j,N,M,a[20][20];
cout<<"N="; //ввод количества строк
cin>>N;
cout<<"M="; //ввод количества столбцов1
cin>>M;
cout<<"Input matrix A \n";
//цикл по переменной i, в которой перебираем строки матрицы3
for (i=0; i<N; i++)
//цикл по переменной j, в котором перебираем элементы внутри строки
for (j=0; j<M; j++)
cin>>a[i][j]; //ввод очередного элемента матрицы
cout<<"matrix A \n";
for (i=0; i<N; i++)
{
//цикл по переменной i, в котором перебираем строки матрицы
for (j=0; j<M; j++)
cout<<a[i][j]<<"\t"; //вывод очередного элемента матрицы
cout<<endl; //переход на новую строку после вывода всех элементов строки
}
system("pause");
return 0;
}
