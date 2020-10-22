#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

/*
This is the code of NTHU EECS 204002 Data Structure project:Tetris
Author: Wei-Hsiang Yu 游惟翔 106022114 NTHUPHYS
*/

int field[20][41]={0};

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

//check著陸/卡到方塊
bool checktouch(int m,int n)
{
    for (int i=0;i<4;i++)
        //著陸
        //因為從col開始算 多3row
        if (a[i].y==m+3) return 0;
        //卡到底下的方塊
        else if (field[(a[i].y)+1][a[i].x-1]) return 0;
    return 1;
};

//invalid case 判斷(中間撞到方塊或移動超出邊界)
bool checkinvalid(int m,int n,int move)
{
    for (int i=0;i<4;i++)
        if (move<0)
        {
            for (int j=0;j>=move;j--)
            {
                //中間撞到方塊
                if(field[a[i].y][a[i].x-1+j]) return 0;
                //超出左右兩邊邊界
                else if (a[i].x+move<0) return 0;
            }
        }
        else if (move>0)
        {
            for (int j=0;j<=move;j++)
            {
                //中間撞到方塊
                if(field[a[i].y][a[i].x-1+j]) return 0;
                //超出左右兩邊邊界
                else if (a[i].x+move>n) return 0;
            }
        }
        else if (a[i].x>n) return 0;
    return 1;
};

//check 是否超過天花板
bool checksky(int n)
{
    for (int i=0;i<4;i++)
        {
        for (int j=0;j<n;j++)
            if (field[i][j]==1) return 0;
        }
    return 1;
};

int main(int argc, char** argv)
{
    //讀入測資
    ifstream ifs(argv[1]);
    string str;
    //將每個測資依照空格分別讀入，由於格式相同可用位置處理
    int count = 0;
    //matrix的大小
    int m,n;
    //方塊的種類
    string name;
    //col要從第幾個開始
    int colloc=0;
    //碰到要移動到哪
    int move=0;

    while (ifs >> str)
    {
        count++;
        //頭一行第一個為row
        if (count==1)
        {
            stringstream ss;
            ss<<str;
            ss>>m;
        }
        //頭一行第二個為col
        else if (count==2)
        {
            stringstream ss;
            ss<<str;
            ss>>n;
        }
        //判斷是否結束
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

                //依照測資第二格說的欄位選定地方下落
                for (int i=0;i<4;i++) a[i].x+=colloc;    
                
                //判斷是否是invalidcase
                if (! checkinvalid(m,n,move))
                    {
                        cout<<count/3+1<<"row in testcase is the invalidcase!!!"<<endl;
                        cout<<"-->inital column location is out of boundary"<<endl;
                        count++;
                        continue;
                    }

                while(checktouch(m,n))
                {
                    //執行下落
                    for (int i=0;i<4;i++)
                        a[i].y+=1;
                }
            }
            else if ((count%3)==2)
            {
                stringstream ss;
                ss<<str;
                ss>>move;

                //invalid block的判斷
                if (! checkinvalid(m,n,move))
                {
                    move=0;
                    cout<<count/3+1<<"row in testcase is the invalidcase!!!"<<endl;
                    cout<<"-->the motion will hit existing blocks or out of boundary"<<endl;
                    continue;
                }

                //執行橫移
                for (int i=0;i<4;i++)
                    a[i].x+=move;

                //上一列的move會影響colloc的invalidcase判斷
                move=0;
                    
                //在未碰觸底部下執行下落
                while( checktouch(m,n))
                {
                    //執行下落
                    for (int i=0;i<4;i++)
                        a[i].y+=1;
                }

                //儲存現在的field上的狀態
                for (int i=0;i<4;i++)
                    field[a[i].y][a[i].x-1]=1;
                
                int k=m+3;
                //消去變為0
                for (int i=m+3;i>=0;i--)
                {
                    int count=0;
                    for (int j=0;j<n;j++)
                    {
                        //檢查整排是否都有值
                        if (field[i][j]) count++;
                        field[k][j]=field[i][j];
                    }
                    if (count<n) k--;
                }

                //判定有無超出天花板
                if (!checksky(n))
                {
                    cout<<("over height")<<endl;
                    break;
                }
            }
        }   
    }

    ofstream fout("106022114_proj1.final");

    //cout結果
    for  (int i=4;i<m+4;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (j==n-1)
            {
                fout<<field[i][j];
            }
            else
                fout<<field[i][j]<<" ";
        }
        fout<<endl;
    }

    //cout結果
    for  (int i=4;i<m+4;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<field[i][j];
        }
        cout<<endl;
    }

    cout<<"106022114_proj1.final is completed."<<endl;

    fout.close();
    ifs.close();

    return 0;
}
