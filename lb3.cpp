#include <iostream>
#include <fstream>
#include <string>
 
int main()
{
    std::string line;
 
    std::ifstream in("D:\\hello.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();     // закрываем файл
     
    std::cout << "End of program" << std::endl;
    return 0;
}
