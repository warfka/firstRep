//first
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char str[1000];
    int i, j;

    cin >> str;
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9')
        {
            do {
                for (j = i; j < len; j++) {
                    str[j] = str[j + 1];
                }
            } while (str[i] >= '0' && str[i] <= '9');
            
            len--;
        }

    }
   str[len + 1] = '\0';
    cout << str << endl<<endl<<endl;
    return 0;
}


