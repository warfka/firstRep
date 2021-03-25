#include <iostream>
#include <cstring>
using namespace std;
 
class AA
{
private:
    // здесь данные и методы, которые используются только в базовом классе
protected:
    // здесь данные и методы, которые доступны в производном классе
char* str; // для примера строка с динамически выделяемой памятью
public:
    virtual ~AA(){delete[] str;} // деструктор
    AA(){str=new char[1];*str=0;} // конструктор по умолчанию
    AA(char* x)     // конструктор с параметрами
    {
        str=new char[strlen(x)+1];
        strcpy(str,x);
    }
    AA(const AA& a)  // копиконструктор
    {
        str=new char[strlen(a.str)+1];
        strcpy(str,a.str);
    }
    AA& operator=(const AA& a)  // operator= (правило ТРЕХ)
    {
        if(this==&a)  // обязательно проверяем, что нет присвоения типа x=x;
            return *this;
        if(strlen(str)!=strlen(a.str))
        {
            delete[] str;
            str=new char[strlen(a.str)+1];
        }
        strcpy(str,a.str);
        return *this;
    }
    virtual void f(){cout<<" class A\n";} // виртуальная функция
    friend ostream& operator<<(ostream& os,const AA& a); // перегрузка потокового вывода
    friend istream& operator>>(istream& os,AA& a); // перегрузка потокового ввода
};
//-----------------------------------------------------
ostream& operator<<(ostream& os,const AA& a)
{
    os<<a.str<<endl;
    return os;
}
istream& operator>>(istream& is,AA& a)
{
    char tmp[100];
    is.getline(tmp,100);
    delete[] a.str;
    a.str=new char[strlen(tmp)+1];
    strcpy(a.str,tmp);
    return is;
}
//-----------------------------------------------------
 
class BB : public AA
{
private:
    int SIZE; // дополнительные данные
public:
    ~BB(){}
    BB():AA(){SIZE=strlen(str);}
    BB(char* x):AA(x){SIZE=strlen(str);} // обязательно вызываем конструктор базового класса
    BB(BB& a):AA(a){SIZE=strlen(str);} // обязательно вызываем конструктор базового класса
    BB& operator=(const BB& a)  
    {
        if(this==&a)
            return *this;
        if(SIZE!=a.SIZE)
        {
            delete[] str;
            str=new char[SIZE+1];
        }
        strcpy(str,a.str);
        return *this;
    }
    void f(){cout<<" class B\n";}
    friend ostream& operator<<(ostream& os,const BB& a);
    friend istream& operator>>(istream& os,BB& a);
 
};
//-----------------------------------------------------
ostream& operator<<(ostream& os,const BB& a)
{
    os<<a.str<<" Size="<<a.SIZE<<endl;
    return os;
}
istream& operator>>(istream& is,BB& a)
{
 
    char tmp[100];
    is.getline(tmp,100);
    delete[] a.str;
    a.SIZE=strlen(a.str);
    a.str=new char[a.SIZE+1];
    strcpy(a.str,tmp);
    return is;
}
//----------------------------------------------------- 
int main() 
{
    char tst[]="Hello";
    AA a(tst);  // базовый класс
    a.f();      // невиртуальный вызов f() из AA
    AA a2;
    a2=a;  // operator=
    cout<<a2;
    
    BB b(tst);  // производный класс
    b.f();      // невиртуальный вызов f() из BB
    BB b2=b;    // копиконструктор эквивалентно BB b2(b);
    cout<<b;  
 
    AA* pa; 
// Указателю на базовый класс присваиваем адрес ПРОИЗВОДНОГО класса:
    pa=&b;   
    pa->f();// виртуальный вызов f() из B
    pa->AA::f();// невиртуальный вызов f() из AA
 
    //system("pause");
    return 0;
}
