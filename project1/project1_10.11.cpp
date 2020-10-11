#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;

//windows大小
int m;
int n;
int field[m][n] = {0};

//block分類內容
int box[19][4] =
{
    8,9,10,13,  // T1
    5,8,9,13,   //T2
    9,12,13,14, //T3
    4,8,9,12,   //T4
    4,8,12,13,  // L1
    8,9,10,12,  //L2
    4,5,9,13,   //L3
    10,12,13,14,//L4
    5,9,12,13,  // J1
    8,12,13,14, //J2
    4,5,8,12,   //J3
    8,9,10,14,  //J4
    9,10,12,13, //S1
    4,8,9,13,   //S2
    8,9,13,14,  //Z1
    5,8,9,12,   //Z2
    0,4,8,12,   // I1
    12,13,14,15,//I2
    8,9,12,13,  //O
};

//表示該block
struct block
{int x,y;} a[4];

//check著陸/卡到方塊**
bool checktouch()
{
    //著陸
    for (int i=0;i<4;i++)
        //因為從col開始算 多3row
        if (a[i].y==m+3) return 1;
    return 0;

    //卡到底下的方塊**
    int k=m-1;
    for (int i=m-1;i>0;i--)
    {
        int count=0;
        for (int j=0;j<n;j++)
        {
            if (field[i][j]==1) count++;
            field[k][j]=field[i][j];
        }
        if (count<n) k--;

    return 1;
    }
};

//invalid case 判斷(中間撞到方塊或移動超出邊界)**
bool checkinvalid()
{
    //超出左右兩邊邊界
    for (int i=0;i<4;i++)
        if (a[i].x<0 || a[i].x>=n) return 1;
    //中間撞到方塊**


    return 0;
};

//check 是否超過天花板
bool checksky()
{
    for (int i=0;i<4;i++)
        if (a[i].y<=3) return 1;

    return 0;
};

int main(int argc, char** argv)
{
    ifstream ifs("1.data");
    string str;
    int count = 0;
    //matrix的大小
    int m,n;
    //方塊的種類
    string name;
    //col要從第幾個開始
    int colloc;
    //碰到要移動到哪
    int move;

    while (ifs >> str)
    {
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
            //方塊的種類
            if ((count%3)==0)
            {
                name=str;
                //string種類判斷
                if (name == "T1")
                {
                    for (int i=0;i<4;i++)
                    {
                        //a[i].x block表示 最左為0 col
                        //a[i].y block表示 最上為0 row
                        //reference point 為(a[i].x+colloc,a[i].y+4) 也就是(0,4)
                        //map到matrix上時，row不變，天花板下降4
                        a[i].x = box[0][i]%4;
                        a[i].y = box[0][i]/4;
                    }
                }
                else if (name == "T2")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[1][i]%4;
                        a[i].y = box[1][i]/4;
                    }
                }
                else if (name == "T3")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[2][i]%4;
                        a[i].y = box[2][i]/4;
                    }
                }
                else if (name == "T4")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[3][i]%4;
                        a[i].y = box[3][i]/4;
                    }
                }
                else if (name == "L1")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[4][i]%4;
                        a[i].y = box[4][i]/4;
                    }
                }
                else if (name == "L2")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[5][i]%4;
                        a[i].y = box[5][i]/4;
                    }
                }
                else if (name == "L3")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[6][i]%4;
                        a[i].y = box[6][i]/4;
                    }
                }
                else if (name == "L4")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[7][i]%4;
                        a[i].y = box[7][i]/4;
                    }
                }
                else if (name == "J1")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[8][i]%4;
                        a[i].y = box[8][i]/4;
                    }
                }
                else if (name == "J2")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[9][i]%4;
                        a[i].y = box[9][i]/4;
                    }
                }
                else if (name == "J3")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[10][i]%4;
                        a[i].y = box[10][i]/4;
                    }
                }
                else if (name == "J4")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[11][i]%4;
                        a[i].y = box[11][i]/4;
                    }
                }
                else if (name == "S1")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[12][i]%4;
                        a[i].y = box[12][i]/4;
                    }
                }
                else if (name == "S2")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[13][i]%4;
                        a[i].y = box[13][i]/4;
                    }
                }
                else if (name == "Z1")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[14][i]%4;
                        a[i].y = box[14][i]/4;
                    }
                }
                else if (name == "Z2")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[15][i]%4;
                        a[i].y = box[15][i]/4;
                    }
                }
                else if (name == "I1")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[16][i]%4;
                        a[i].y = box[16][i]/4;
                    }
                }
                else if (name == "I2")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[17][i]%4;
                        a[i].y = box[17][i]/4;
                    }
                }
                else if (name == "O")
                {
                    for (int i=0;i<4;i++)
                    {
                        a[i].x = box[18][i]%4;
                        a[i].y = box[18][i]/4;
                    }
                }
            }
            //colloc
            else if ((count%3)==1)
            {
                stringstream ss;
                ss<<str;
                ss>>colloc;
                //選定地方下落
                for (int i=0;i<4;i++) a[i].x+colloc;
                while( !checktouch())
                {
                    //執行下落
                    for (int i=0;i<4;i++) a[i].y+1;
                }

            }
            else if ((count%3)==2)
            {
                stringstream ss;
                ss<<str;
                ss>>move;

                //先判斷有沒有invalid
                if(!checkinvalid()) break;

                //若valid
                else
                {
                    //執行橫移
                    for (int i=0;i<4;i++) a[i].x+=move;
                    //在未碰觸底部下執行下落
                    while( !checktouch())
                    {
                        //執行下落
                        for (int i=0;i<4;i++) a[i].y+1;
                    }

                    //執行消去
                    int k=m-1;
                    for (int i=m-1;i>0;i--)
                    {
                        int count=0;
                        for (int j=0;j<n;j++)
                        {
                            if (field[i][j]) count++;
                            field[k][j]=field[i][j];
                        }
                        if (count<n) k--;
                    }

                    //判定有無超出天花板
                    if (!checksky())
                    {
                        cout<<("over height");
                        break;
                    }
                }
            }
        }   
    }
    ifs.close();

    //windows大小
    int field[m][n] = {0};

    //row往上加四個
    
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            {
                if (field[i][j]==0) continue;
            }

    return 0;
}