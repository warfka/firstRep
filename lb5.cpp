#include <iostream>
#include <cstring>
 
int main ()
{
  char str[20];
  std::cout << "IN:" << std::endl;
  std::cin >> str;
  std::cout << "OUT:" << std::endl;
  char* p = strtok (str,"1234567890");
 
  while (p != NULL)        
  {
      std::cout << p  << " ";      
      p = strtok (NULL, "1234567890");
  }
  return 0;
}

