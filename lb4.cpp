#include <iostream>
#include <fstream>
 
int main()
{
    std::ofstream out;          // поток для записи
    out.open("D:\\hello.txt"); // окрываем файл для записи
    if (out.is_open())
    {
        out << "Hello World!" << std::endl;
    }
     
    std::cout << "End of program" << std::endl;
    return 0;
}		
