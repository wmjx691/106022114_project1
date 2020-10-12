#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    ifstream ifs("1.data");
    string str;
    int count = 0;
    //matrix的大小
    int m,n;
    //方塊的種類
    string type;
    //col要從第幾個開始
    int colloc;
    //碰到要移動到哪
    int move;

    while (ifs >> str)
    {
      //cout << str << endl;
        count++;

        if (count==1)
        {
            stringstream ss;
            ss<<str;
            ss>>m;
            cout<<m<<endl;
        }
        else if (count==2)
        {
            stringstream ss;
            ss<<str;
            ss>>n;
            cout<<n<<endl;
        }
        else if (str == "END")
        {
            break;
        }
        else
        {
            //方塊的種類
            if ((count%3)==0)
            {
                type=str;
                cout<<type<<endl;
            }
            //colloc
            else if ((count%3)==1)
            {
                stringstream ss;
                ss<<str;
                ss>>colloc;
                cout<<colloc<<endl;
            }
            else if ((count%3)==2)
            {
                stringstream ss;
                ss<<str;
                ss>>move;
                cout<<move<<endl;
            }
        }   
    }
    ifs.close();

    return 0;
}
