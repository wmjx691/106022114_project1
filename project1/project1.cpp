#include <iostream>
#include <fstream>
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
        if (a[i].y>=m) return 0;
    return 1;

    //卡到底下的方塊
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

//invalid case 判斷(中間撞到方塊或移動超出邊界)
bool checkinvalid()
{
    //超出左右兩邊邊界
    for (int i=0;i<4;i++)
        if (a[i].x<0 || a[i].x>=n) return 0;
    return 1;
    //中間撞到方塊

};

//check 是否超過天花板
bool checksky()
{
    for (int i=0;i<4;i++)
        if (a[i].y<=3) return 0;
    return 1;
};

//check data結束END沒
bool checkdata()
{
    if (=="END")  return 1;
};

//讀取檔案**
void readtestdata(fstream &in, string filepath, int data[ROW][COLUMN])
{
    in.open("1.data", ios::in);
    if (!in.is_open())
    {
        cout<<"not find test data" <<endl;
    }
    string buff;
	int i = 0;//行數i
	while (getline(in, buff)) {
		vector<double> nums;
		// string->char *
		char *s_input = (char *)buff.c_str();
		const char * split = " ";
		// 以‘ ’為分隔符拆分字串
		char *p = strtok(s_input, split);
		double a;
		while (p != NULL) {
			// char * -> int
			a = atof(p);
			//cout << a << endl;
			nums.push_back(a);
			p = strtok(NULL, split);
		}//end while
		for (int b = 0; b < nums.size(); b++) {
			data[i][b] = nums[b];
		}//end for
		i++;
	}//end while
	in.close();
	cout << "get  data" << endl;
}

int main(){
    //windows大小
    int field[m][n] = {0};
    
    //string種類判斷
    string name; 
    if (name == "T1")
    {
        for (int i=0;i<4;i++)
        {
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

    //a[i].x 最左為0 col
    //a[i].y 最上為0 row
    //reference point 為(a[i].x+colloc,a[i].y+4)
    //map到matrix上時，row不變，天花板下降4
    //選定地方下落
    int colloc;
    for (int i=0;i<4;i++) a[i].x+colloc;
    //row往上加四個
    int move;
    
    //開始輸入檔案if檔案沒到END
    while (!checkdata())
    {
        
        while ()
        {   
            //執行下落
            for (int i=0;i<4;i++) a[i].y+1;

            //著陸或碰到方塊時
            if (!checktouch())
            {
                //先判斷有沒有invalid
                if(!checkinvalid()) break;
                //執行橫移 在持續落下到碰到方塊
                else
                {
                    for (int i=0;i<4;i++) a[i].x+=move;
                    move=0;
                    for (int i=0;i<4;i++) a[i].y+1;
                    if (!checktouch()){
                        //消去
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
                        if (!checktouch())
                        {
                            cout<<("over height");
                            break;
                        }
                    }
                }
            }           
        }        
    }

    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            {
                if (field[i][j]==0) continue;
            }

    return 0;
}