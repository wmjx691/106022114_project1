#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

int field[12][5]={0};

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

// //check著陸/卡到方塊**
// bool checktouch(int m,int n)
// {
//     for (int i=0;i<4;i++)
//         //著陸
//         //因為從col開始算 多3row
//         if (a[i].y==m+3) return 0;
//         //卡到底下的方塊**
//         else if (field[(a[i].y)+1][a[i].x]) return 0;
//     return 1;
// };

// //invalid case 判斷(中間撞到方塊或移動超出邊界)**
// bool checkinvalid(int m,int n,int move)
// {
//     for (int i=0;i<4;i++)
//         //超出左右兩邊邊界
//         if (a[i].x<0 || a[i].x>=n) return 0;
//         //中間撞到方塊**
//         else if (move<0)
//         {
//             for (int j=0;j>move;j--)
//                 if(field[a[i].y][a[i].x]==field[a[j].y][a[j].x])
//                 return 0;
//         }
//         else if (move>0)
//         {
//             for (int j=0;j<move;j++)
//                 if(field[a[i].y][a[i].x]==field[a[j].y][a[j].x])
//                 return 0;
//         }       
//     return 1;
// };

// //check 是否超過天花板
// bool checksky()
// {
//     for (int i=0;i<4;i++)
//         if (a[i].y<=3) return 0;

//     return 1;
// };

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
    //儲存matrix現在狀態的東西
    int field[m+4][n] = {0};

    while (ifs >> str)
    {
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
        }
        else if (str == "End")
        {
            break;
        }
        else
        {
            //方塊的種類
            if ((count%3)==0)
            {
                name=str;
                cout<<name<<endl;
            }
            //     //string種類判斷
            //     if (name == "T1")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             //a[i].x block表示 最左為0 col
            //             //a[i].y block表示 最上為0 row
            //             //reference point 為(a[i].x+colloc,a[i].y+4) 也就是(0,4)
            //             //map到matrix上時，row不變，天花板下降4
            //             a[i].x = box[0][i]%4;
            //             a[i].y = box[0][i]/4;
            //         }
            //     }
            //     else if (name == "T2")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[1][i]%4;
            //             a[i].y = box[1][i]/4;
            //         }
            //     }
            //     else if (name == "T3")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[2][i]%4;
            //             a[i].y = box[2][i]/4;
            //         }
            //     }
            //     else if (name == "T4")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[3][i]%4;
            //             a[i].y = box[3][i]/4;
            //         }
            //     }
            //     else if (name == "L1")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[4][i]%4;
            //             a[i].y = box[4][i]/4;
            //         }
            //     }
            //     else if (name == "L2")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[5][i]%4;
            //             a[i].y = box[5][i]/4;
            //         }
            //     }
            //     else if (name == "L3")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[6][i]%4;
            //             a[i].y = box[6][i]/4;
            //         }
            //     }
            //     else if (name == "L4")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[7][i]%4;
            //             a[i].y = box[7][i]/4;
            //         }
            //     }
            //     else if (name == "J1")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[8][i]%4;
            //             a[i].y = box[8][i]/4;
            //         }
            //     }
            //     else if (name == "J2")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[9][i]%4;
            //             a[i].y = box[9][i]/4;
            //             cout<<a[i].x<<" "<<a[i].y<<endl;
            //         }
            //     }
            //     else if (name == "J3")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[10][i]%4;
            //             a[i].y = box[10][i]/4;
            //         }
            //     }
            //     else if (name == "J4")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[11][i]%4;
            //             a[i].y = box[11][i]/4;
            //         }
            //     }
            //     else if (name == "S1")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[12][i]%4;
            //             a[i].y = box[12][i]/4;
            //         }
            //     }
            //     else if (name == "S2")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[13][i]%4;
            //             a[i].y = box[13][i]/4;
            //         }
            //     }
            //     else if (name == "Z1")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[14][i]%4;
            //             a[i].y = box[14][i]/4;
            //         }
            //     }
            //     else if (name == "Z2")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[15][i]%4;
            //             a[i].y = box[15][i]/4;
            //         }
            //     }
            //     else if (name == "I1")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[16][i]%4;
            //             a[i].y = box[16][i]/4;
            //             cout<<a[i].x<<" "<<a[i].y<<endl;
            //         }
            //     }
            //     else if (name == "I2")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[17][i]%4;
            //             a[i].y = box[17][i]/4;
            //         }
            //     }
            //     else if (name == "O")
            //     {
            //         for (int i=0;i<4;i++)
            //         {
            //             a[i].x = box[18][i]%4;
            //             a[i].y = box[18][i]/4;
            //             cout<<a[i].x<<" "<<a[i].y<<endl;
            //         }
            //     }
            // }
            //colloc
            // else if ((count%3)==1)
            // {
            //     stringstream ss;
            //     ss<<str;
            //     ss>>colloc;
            //     //選定地方下落
            //     for (int i=0;i<4;i++)
            //         a[i].x+=colloc;
            //     while( checktouch(m,n))
            //     {
            //         //執行下落
            //         for (int i=0;i<4;i++)
            //             a[i].y+=1;
            //     }

            // }
            // else if ((count%3)==2)
            // {
            //     stringstream ss;
            //     ss<<str;
            //     ss>>move;

            //     //先判斷有沒有invalid
            //     if(!checkinvalid(m,n,move)) continue;

            //     //若valid
            //     else
            //     {
            //         //執行橫移
            //         for (int i=0;i<4;i++)
            //             a[i].x+=move;
            //         //在未碰觸底部下執行下落
            //         while( checktouch(m,n))
            //         {
            //             //執行下落
            //             for (int i=0;i<4;i++)
            //                 a[i].y+=1;
            //         }

            //         // //執行消去**
            //         // int k=m-1;
            //         // for (int i=m-1;i>0;i--)
            //         // {
            //         //     int count=0;
            //         //     for (int j=0;j<n;j++)
            //         //     {
            //         //         if (field[i][j]) count++;
            //         //     }
            //         //     if (count<n) field[k][j]=field[i][j];k--;
            //         // }

            //         //判定有無超出天花板
            //         if (checksky())
            //         {
            //             cout<<("over height");
            //             break;
            //         }

            //         //儲存現在的field上的狀態
            //         for (int i=0;i<4;i++)
            //             field[a[i].x][a[i].y]=1;
            //     }
            // }
        }
    }
    ifs.close();

    // //cout結果
    // for  (int i=4;i<m;i++)
    // {
    //     for (int j=0;j<n;j++)
    //     {
    //         cout<<field[i][j];
    //     }
    //     cout<<endl;
    // }  

    return 0;
}