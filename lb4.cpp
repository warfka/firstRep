#include <iostream>
#include <fstream>
 
int main()
{
    std::ofstream out;          // поток для записи3
    out.open("D:\\hello.txt"); // окрываем файл для записиd
    if (out.is_open())
    {
        out << "Hello World!" << std::endl;
    }
     
    std::cout << "End of program" << std::endl;
    return 0;
}		
