#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char** argv)
{
    ifstream ifs("1.data");
    string str;
    int count = 0;
    int m,n;
 
    while (ifs >> str)
    {
      //cout << str << endl;
        count++;

        if (count==1)
        {
            stringstream ss;
            ss<<str;
            ss>>m;
        }
        else if (count==2)
        {
            stringstream ss;
            ss<<str;
            ss>>n;
        }
        else if (str == "END")
        {
            break;
        }
        else
        {
            /* code */
        }   
    }
    ifs.close();

    cout<<m<<n;

    return 0;
}
