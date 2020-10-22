#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
int m, n, map[16][41] = { {2 } }, i = 1;
char tcs[1000][30], fl; //end[3]={'E', 'n', 'd'};
int fln, init, move, tmp;
//int check(int p1,int p2,int pos, int mov);
bool I1 = false;
bool I2=false;
bool O = false;
bool check = false;
bool T3 = false;
bool T1 = false;
bool T2 = false;
bool T4 = false;
bool L1 = false;
bool L2 = false;
bool L3 = false;
bool L4 = false;
bool J1 = false;
bool J2 = false;
bool J3 = false;
bool J4 = false;
bool S1 = false;
bool S2 = false;
bool Z1 = false;
bool Z2 = false;
int main(int argc, char* argv[])
{//get file

	FILE* tc;
	FILE* fn;
	//tc = fopen("3.txt", "rt");
	//tc = fopen( "107022210_proj1.data.txt","rt");
	fn = fopen("107022210_proj1.final", "w");
    tc = fopen(argv[1],"rt"); 
	if (tc == NULL)
	{
		printf("fail_to_open");  
		return 0;
	}
	//scan matrix m n and initialize
	fscanf(tc,"%d %d", &m, &n);
	for (int k = 1; k <= n; k++)map[0][k] = 2;
	//INITIALIZE THE MAP
	for (int i = m; i >= 1; i--)
	{
		for (int j = n; j >= 1; j--)
		{
			map[i][j] = 0;
		}
	}
	//testbarrier
	//map[5][4] = 1;
    //map[7][3] = 1;
	//map[3][1] = 1;
	//map[10][2] = 1;
	//map[8][2] = 1;
	//map[10][4] = 1;
	//map[10][1] = 1;
	//map[9][3] = 1;
	//map[8][5] = 1;
	//eat space
	fgets(tcs[0], 3, tc);
	while (tcs[i-1][0] != 'E')
	{
		fgets(tcs[i], 10, tc);
		
		i++;//i=5		
	}
	//printf("%d", i);
	for (int k = 1; k < i - 1; k++)
	{
		int pos, mov;
		//I
		if (tcs[k][0] == 'I')
		{   //I1
			if (tcs[k][1] - '0' == 1)
			{   //pos two digits
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
					if (mov == 0)
					{//bottom
						for (int i = 1; i <= m; i++)
						{
							
							if (i == m && map[i][pos] ==0)
							{
								map[i][pos] = 1;
								map[i-1][pos] = 1;
								map[i-2][pos] = 1;
								map[i-3][pos] = 1;						
								break;
							}
							//middle
							else if (map[i][pos] == 1)
							{
								map[i-1][pos] = 1;
								map[i - 2][pos] = 1;
								map[i - 3][pos] = 1;
								map[i - 4][pos] = 1;
								
								break;
							}
						}
					}
					// move
					else if (mov != 0)
					{
						
						for (int i = 1; i <= m; i++)
						{
							if (I1 == true)
							{
								//printf("kk");
								I1 = false;
								break;
							}
							//bottom and move
							if (i == m)
							{
								pos += mov;
								map[i][pos] = 1;
								map[i - 1][pos] = 1;
								map[i - 2][pos] = 1;
								map[i - 3][pos] = 1;
								I1 = true;
								break;
							}
							//middle move and go to bottom
							if (map[i][pos] == 1)
							{
								//printf("ll");
								
								pos += mov;
								//int j = i - 1;
								for (int j = i - 1; j <= m; j++)
								{//bottom
									if (j == m&&map[j][pos]==0)
									{
										
										map[j][pos] = 1;
										map[j - 1][pos] = 1;
										map[j - 2][pos] = 1;
										map[j - 3][pos] = 1;
										I1 = true;
										break;
									}
									//MIDDLE AND GO TO middle
									else if (map[j][pos] == 1)
									{
									//	printf("gg");
										map[j-1][pos] = 1;
										map[j - 2][pos] = 1;
										map[j - 3][pos] = 1;
										map[j - 4][pos] = 1;
										I1 = true;
										break;
									}
								}
							}
						}
					}
					I1 = false;				
			}
			//I2
			if (tcs[k][1] - '0' == 2)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (I2 == true)
						{
							I2 = false;
							break;
						}
						for (int j = pos; j < pos + 4; j++)
						{//middle 
							if (map[i][j] == 1)
							{
								tmp = i - 1;
								for (int d = pos; d < pos + 4; d++)
								{
									map[tmp][d] = 1;
								}
								I2 = true;
								break;
							}//bottom
							else if (i == m && j == pos + 3)
							{
								for (int d = pos; d < pos + 4; d++)
								{
									map[m][d] = 1;
								}
								break;
							}
						}
					}
					I2 = false;
				}
				//move
				if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (I2 == true)
						{
							I2 = false;
							break;
						}
						//bottom and move
						if (i == m && map[i][pos] == 0 && map[i][pos + 1] == 0 && map[i][pos + 2] == 0 && map[i][pos + 3] == 0)
						{

							pos += mov;
							map[i][pos] = 1;
							map[i][pos + 1] = 1;
							map[i][pos + 2] = 1;
							map[i][pos + 3] = 1;
							break;

						}
						//middle 
							if (map[i][pos] == 1||map[i][pos+1]==1||map[i][pos+2]==1||map[i][pos+3]==1)
							{
								
								tmp = i - 1;
								pos += mov;
								for (int k = tmp; k <= m; k++)
								{
									if (I2 == true)
									{
										I2 = false;
										break;
									}
									  //middle and middle
										if (map[k][pos] == 1 || map[k][pos + 1] == 1 || map[k][pos + 2] == 1 || map[k][pos + 3] == 1)
										{
											tmp = k - 1;
											map[tmp][pos] = 1;
											map[tmp][pos+1] = 1;
											map[tmp][pos+2] = 1;
											map[tmp][pos+3] = 1;
											I2 = true;
											break;
										}
										//middle and bottom
										if (map[k][pos] == 0&& map[k][pos + 1] == 0&& map[k][pos + 2] == 0&& map[k][pos + 3] == 0&&k == m)
										{
											map[k][pos] = 1;
											map[k][pos + 1] = 1;
											map[k][pos + 2] = 1;
											map[k][pos + 3] = 1;
											I2 = true;
											break;
										}
									
								}
							}
							
						
					
					}



				}
				I2 = false;
			}
		}
		//O
		if (tcs[k][0] == 'O')
		{
			if ((tcs[k][3] - '0') >= 0 && (tcs[k][3] - '0') <= 9)
			{
				pos = (tcs[k][2] - '0') * 10 + tcs[k][3] - '0';
				if (tcs[k][5] == '-')//minus sign
				{
					if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
					{
						mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
					}
					else mov = (tcs[k][6] - '0') * (-1);//one digits
				}
				else if (tcs[k][5] != '-')//positive
				{
					//printf("!=-");
					if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
					{
						//printf("haa");
						mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
						//printf("%d", mov);
					}
					else mov = tcs[k][5] - '0';//one digit
				}
			}
			//pos one degit
			else //if (tcs[k][4] == '\0')
			{
				pos = tcs[k][2] - '0';
				if (tcs[k][4] == '-')//minus sign
				{
					if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
					{
						mov = (-1) * ((tcs[k][5] - '0') * 10 + tcs[k][6] - '0');
					}
					else mov = (tcs[k][5] - '0') * (-1);//one digits
				}
				else if (tcs[k][4] != '-')//positive sign
				{
					//printf("!=-");
					if ((tcs[k][5] - '0') >= 0 && (tcs[k][5] - '0') <= 9)//two digits
					{
						//printf("haha");
						mov = (tcs[k][4] - '0') * 10 + tcs[k][5] - '0';
						//printf("%d", mov);
					}
					else mov = tcs[k][4] - '0';//one digit
				}

			}
			//no move
			if (mov == 0)
			{
				
				for (int i = 1; i <= m; i++)
				{//middle 
					//printf("%d", i);
					if (map[i][pos] || map[i][pos + 1] == 1)
					{
						
						map[i - 1][pos] = 1;
						map[i - 2][pos] = 1;
						map[i - 1][pos + 1] = 1;
						map[i - 2][pos + 1] = 1;
						break;
					}
				
					//bottom
					
					if (i == m&&map[i][pos]==0&&map[i][pos+1]==0)
					{
						
						map[i][pos] = 1;
						map[i][pos+1] = 1;
						map[i - 1][pos] = 1;
						map[i - 1][pos+ 1] = 1;
						break;
					}
			
				}
			}
			//move
			else if (mov != 0)
			{
				for (int i = 1; i <= m; i++)
				{
					if (O == true)
					{
						//printf("*");
						O = false;
						break;
					}//printf("*");
					//bottom and move
					if (i == m && map[i][pos] == 0 && map[i][pos + 1] == 0)
					{
						//printf("/*");
						map[i][pos+mov] = 1;
						map[i][pos+1+mov] = 1;
						map[i-1][pos+mov] = 1;
						map[i-1][pos+1+mov] = 1;
						break;
					}
					//midddle move 
					if (map[i][pos] == 1 || map[i][pos + 1] == 1)
					{
						//printf("middle");
						tmp = i - 1;
						pos += mov;
						for (int j = tmp; j <= m; j++)
						{   //middle
							if (map[j][pos] == 1 || map[j][pos + 1] == 1) 
							{
								map[j - 1][pos] = 1;
								map[j - 1][pos+1] = 1;
								map[j - 2][pos] = 1;
								map[j - 2][pos+1] = 1;
								O = true;
								break;
							}
							//bottom
							else if (j == m)
							{
								map[j][pos] = 1;
								map[j][pos+1] = 1;
								map[j - 1][pos] = 1;
								map[j - 1][pos+1] = 1;
								O = true;
								break;
							}
						}
					}
				}
			}
			O = false;
		}
		//T
		if (tcs[k][0] == 'T')
		{   
			//T1
			if (tcs[k][1] - '0' == 1)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{  
						//bottom
						if (map[i-1][pos] == 0 && map[i][pos + 1] == 0 && map[i-1][pos + 2] == 0 && i == m)
						{
							map[i-1][pos] = 1;
							map[i-1][pos + 1] = 1;
							map[i-1][pos + 2] = 1;
							map[i][pos + 1] = 1;
							break;
						}
						//middle 
						if (map[i-1][pos] == 1 || map[i][pos + 1] == 1 || map[i-1][pos + 2] == 1)
						{
							tmp = i - 2;
							map[tmp][pos] = 1;
							map[tmp][pos + 1] = 1;
							map[tmp][pos + 2] = 1;
							map[tmp+1][pos + 1] = 1;
							
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (T1 == true)
						{
							//printf("kk");
							T1 = false;
							break;
						}
						//bottom and move
						if (map[i-1 ][pos] == 0 && map[i][pos + 1] == 0 && map[i - 1][pos + 2] == 0 && i == m)
						{
							//printf("pp");
							pos += mov;
							map[i - 1][pos] = 1;
							map[i - 1][pos + 1] = 1;
							map[i - 1][pos + 2] = 1;
							map[i][pos + 1] = 1;
							T1 = true;
							break;

						}
						//middle
						if (map[i][pos] == 1 || map[i+1][pos + 1] == 1 || map[i][pos + 2] == 1)
						{
							tmp = i - 1;
							pos += mov;
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j][pos] == 1 || map[j+1][pos + 1] == 1 || map[j][pos + 2] == 1)
								{
									//printf("oo*\n");
									map[j - 1][pos] = 1;
									map[j - 1][pos + 1] = 1;
									map[j - 1][pos + 2] = 1;
									map[j ][pos + 1] = 1;
									T1 = true;
									break;

								}
								//middle and bottom
								if (j == m && map[j][pos] == 0 && map[j][pos + 1] == 0 && map[j][pos + 2] == 0)
								{
									//printf("pp");
									map[j-1][pos] = 1;
									map[j-1][pos + 1] = 1;
									map[j-1][pos + 2] = 1;
									map[j ][pos + 1] = 1;
									T1 = true;
									break;

								}
							}
						}

					}
				}
			}
			//T2	
			if (tcs[k][1] - '0' == 2)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{
						//bottom
						if (map[i][pos+1]==0&&map[i-1][pos]==0&& i == m)
						{
							map[i - 1][pos] = 1;
							map[i -2][pos + 1] = 1;
							map[i - 1][pos + 1] = 1;
							map[i][pos + 1] = 1;
							break;
						}
						//middle 
						if (map[i][pos + 1] == 1 || map[i - 1][pos] == 1)
						{
							tmp = i - 1;
							map[tmp-1][pos] = 1;
							map[tmp][pos + 1] = 1;
							map[tmp-1][pos + 1] = 1;
							map[tmp -2][pos +1] = 1;
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (T2 == true)
						{
							//printf("kk");
							T2 = false;
							break;
						}
						//bottom and move
						if (map[i ][pos+1] == 0 && map[i-1][pos ] == 0 && i == m)
						{
							
							pos += mov;
							map[i - 1][pos] = 1;
							map[i - 2][pos + 1] = 1;
							map[i - 1][pos + 1] = 1;
							map[i][pos + 1] = 1;
							T2 = true;
							break;

						}
						//middle
						if (map[i][pos + 1] == 1 || map[i - 1][pos] == 1)
						{
							tmp = i - 1;
							pos += mov;
							//printf("%d**", pos);
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j][pos + 1] == 1 || map[j - 1][pos] == 1)
								{
									//printf("oo*\n");
									tmp = j - 1;
									map[tmp - 1][pos] = 1;
									map[tmp][pos + 1] = 1;
									map[tmp - 1][pos + 1] = 1;
									map[tmp - 2][pos + 1] = 1;
									T2 = true;
									break;

								}
								//middle and bottom
								if (map[j ][pos+1] == 0 && map[j-1][pos ] == 0 && j == m)
								{
									//printf("pp");
									map[j - 1][pos] = 1;
									map[j - 2][pos + 1] = 1;
									map[j - 1][pos + 1] = 1;
									map[j][pos + 1] = 1;
									T2 = true;
									break;

								}
							}
						}

					}
				}
			}
			//T3
			if(tcs[k][1]-'0'==3)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{//bottom
						if (map[i][pos] == 0 && map[i][pos + 1] == 0 && map[i][pos + 2] == 0 && i == m)
						{
							map[i][pos] = 1;
							map[i][pos+1] = 1;
							map[i][pos+2] = 1;
							map[i-1][pos+1] = 1;
							break;
						}
						//middle 
						if (map[i][pos] == 1 || map[i][pos + 1] == 1 || map[i][pos + 2] == 1)
						{
							tmp = i - 1;
							map[tmp][pos] = 1;
							map[tmp][pos + 1] = 1;
							map[tmp][pos + 2] = 1;
							map[tmp - 1][pos + 1] = 1;
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (T3 == true)
						{
							//printf("kk");
							T3 = false;
							break;
						}
						//bottom 
						if (map[i][pos] == 0 && map[i][pos + 1] == 0 && map[i][pos + 2] == 0 && i == m)
						{
							pos += mov;
							map[i][pos] = 1;
							map[i][pos + 1] = 1;
							map[i][pos + 2] = 1;
							map[i - 1][pos + 1] = 1;
							T3 = true;
							break;

						}
						//middle
						if (map[i][pos] == 1 || map[i][pos + 1] == 1 || map[i][pos + 2] == 1)
						{
							tmp = i - 1;
							pos += mov;
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j][pos] == 1 || map[j][pos + 1] == 1 || map[j][pos + 2] == 1)
								{
									//printf("oo*\n");
									map[j - 1][pos] = 1;
									map[j - 1][pos + 1] = 1;
									map[j - 1][pos + 2] = 1;
									map[j - 2][pos + 1] = 1;
									T3 = true;
									break;
									
								}
								//middle and bottom
								if (j == m && map[j][pos] == 0 && map[j][pos + 1] == 0 && map[j][pos + 2] == 0)
								{
									//printf("pp");
									map[j][pos] = 1;
									map[j][pos + 1] = 1;
									map[j][pos + 2] = 1;
									map[j-1][pos + 1] = 1;
									T3 = true;
									break;
									
								}
							}
						}
					
					}
				}
			}
		    //T4
			if (tcs[k][1] - '0' == 4)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{
						//bottom
						if (map[i][pos ] == 0 && map[i -1][pos+1] == 0 && i == m)
						{
							map[i ][pos] = 1;
							map[i - 1][pos ] = 1;
							map[i - 2][pos ] = 1;
							map[i-1][pos + 1] = 1;
							break;
						}
						
						//middle 
						if (map[i][pos ] == 1 || map[i - 1][pos+1] == 1)
						{
							tmp = i - 1;
							map[tmp ][pos] = 1;
							map[tmp-1][pos ] = 1;
							map[tmp - 2][pos] = 1;
							map[tmp -1][pos + 1] = 1;
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (T4 == true)
						{
							//printf("kk");
							T4 = false;
							break;
						}
						//bottom and move
						if (map[i ][pos] == 0 && map[i-1][pos + 1] == 0 && i == m)
						{

							pos += mov;
							map[i][pos] = 1;
							map[i - 1][pos] = 1;
							map[i - 2][pos] = 1;
							map[i - 1][pos + 1] = 1;
							T4 = true;
							break;

						}
						//middle
						if (map[i][pos ] == 1 || map[i - 1][pos+1] == 1)
						{
							tmp = i - 1;
							pos += mov;
							//printf("%d**", pos);
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j][pos ] == 1 || map[j - 1][pos+1] == 1)
								{
									//printf("oo*\n");
									tmp = j - 1;
									map[tmp][pos] = 1;
									map[tmp - 1][pos] = 1;
									map[tmp - 2][pos] = 1;
									map[tmp - 1][pos + 1] = 1;
									T4 = true;
									break;

								}
								//middle and bottom
								if (map[j ][pos] == 0 && map[j-1][pos + 1] == 0 && j == m)
								{
									//printf("pp");
									map[j][pos] = 1;
									map[j - 1][pos] = 1;
									map[j - 2][pos] = 1;
									map[j - 1][pos + 1] = 1;
									T4 = true;
									break;

								}
							}
						}

					}
				}
			}
			T1 = false;
			T2= false;
			T3 = false;
			T4 = false;
		}
		//L
		if (tcs[k][0] == 'L')
		{
			//L1
			if (tcs[k][1] - '0' == 1)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				if (mov == 0)
				{
					//NO MOVE
					for (int i = 1; i <= m; i++)
					{//middle 
						//printf("%d", i);
						if (map[i][pos] ==1|| map[i][pos + 1] == 1)
						{

							map[i - 1][pos] = 1;
							map[i - 2][pos] = 1;
							map[i - 3][pos] = 1;
							map[i -1 ][pos + 1] = 1;
							break;
						}

						//bottom

						if (i == m && map[i][pos] == 0 && map[i][pos + 1] == 0)
						{

							map[i ][pos] = 1;
							map[i - 1][pos] = 1;
							map[i - 2][pos] = 1;
							map[i ][pos + 1] = 1;
							break;
						}

					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (L1 == true)
						{
							L1 = false;
							break;
						}

						//printf("*");
						//bottom and move
						if (i == m && map[i][pos] == 0 && map[i][pos + 1] == 0)
						{
							//printf("/*");
							pos += mov;
							map[i][pos ] = 1;
							map[i][pos + 1 ] = 1;
							map[i - 1][pos ] = 1;
							map[i - 2][pos ] = 1;
							L1 = true;
							break;
						}
						//midddle move 
						if (map[i][pos] == 1 || map[i][pos + 1] == 1)
						{
							//printf("middle\n");
							tmp = i - 1;
							pos += mov;
							for (int j = tmp; j <= m; j++)
							{   //middle
								if (map[j][pos] == 1 || map[j][pos + 1] == 1)
								{
									map[j - 1][pos] = 1;
									map[j - 1][pos + 1] = 1;
									map[j - 2][pos] = 1;
									map[j - 3][pos ] = 1;
									L1 = true;
									break;
								}
								//bottom
								else if (j == m)
								{
									map[j][pos] = 1;
									map[j][pos + 1] = 1;
									map[j - 1][pos] = 1;
									map[j - 2][pos] = 1;
									L1 = true;
									break;
								}
							}
						}
					}
				}
				L1 = false;
			}
			//L2
			if (tcs[k][1] - '0' == 2)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{
						//bottom
						if (map[i][pos] == 0 && map[i - 1][pos] == 0&&map[i-1][pos+1]==0&&map[i-1][pos+2]==0&& i == m)
						{
							map[i][pos] = 1;
							map[i - 1][pos] = 1;
							map[i -1][pos+1] = 1;
							map[i - 1][pos + 2] = 1;
							break;
						}

						//middle 
						if (map[i][pos] == 1 ||map[i - 1][pos] == 1 || map[i - 1][pos + 1] == 1 || map[i - 1][pos + 2]==1)
						{
							tmp = i - 1;
							map[tmp][pos] = 1;
							map[tmp - 1][pos] = 1;
							map[tmp - 1][pos + 1] = 1;
							map[tmp - 1][pos + 2] = 1;
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (L2== true)
						{
							//printf("kk");
							L2 = false;
							break;
						}
						//bottom and move
						if (map[i][pos] == 0 && map[i - 1][pos] == 0 && map[i - 1][pos + 1] == 0 && map[i - 1][pos + 2] == 0 && i == m)
						{

							pos += mov;
							map[i][pos] = 1;
							map[i - 1][pos] = 1;
							map[i - 1][pos+1] = 1;
							map[i - 1][pos + 2] = 1;	
							L2 = true;
							break;

						}
						//middle
						if (map[i][pos] == 1 || map[i - 1][pos] == 1 || map[i - 1][pos + 1] == 1 || map[i - 1][pos + 2] == 1)
						{
							tmp = i - 1;
							pos += mov;
							//printf("%d**", pos);
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j][pos] == 1 || map[j - 1][pos] == 1 || map[j - 1][pos + 1] == 1 || map[j - 1][pos + 2] == 1)
								{
									//printf("oo*\n");
									tmp = j - 1;
									map[tmp][pos] = 1;
									map[tmp - 1][pos] = 1;
									map[tmp - 1][pos+1] = 1;
									map[tmp - 1][pos + 2] = 1;
									L2 = true;
									break;

								}
								//middle and bottom
								if (map[j][pos] == 0 && map[j - 1][pos] == 0 && map[j - 1][pos + 1] == 0 && map[j - 1][pos + 2] == 0 && j == m)
								{
									//printf("pp");
									map[j][pos] = 1;
									map[j - 1][pos] = 1;
									map[j - 1][pos+1] = 1;
									map[j - 1][pos + 2] = 1;	
									L2 = true;
									break;

								}
							}
						}

					}
				}
			}
			//L3
			if (tcs[k][1] - '0' == 3)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{
						//bottom
						if (map[i][pos + 1] == 0 && map[i - 2][pos] == 0 && i == m)
						{
							map[i - 2][pos] = 1;
							map[i  ][pos + 1] = 1;
							map[i - 1][pos + 1] = 1;
							map[i-2][pos + 1] = 1;
							break;
						}
						//middle 
						if (map[i][pos + 1] == 1 ||map[i - 2][pos] == 1)
						{
							tmp = i - 1;
							map[tmp - 2][pos] = 1;
							map[tmp][pos + 1] = 1;
							map[tmp - 1][pos + 1] = 1;
							map[tmp - 2][pos + 1] = 1;
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (L3== true)
						{
							//printf("kk");
							L3 = false;
							break;
						}
						//bottom and move
						if (map[i][pos + 1] == 0 && map[i - 2][pos] == 0 && i == m)
						{

							pos += mov;
							map[i - 2][pos] = 1;
							map[i][pos + 1] = 1;
							map[i - 1][pos + 1] = 1;
							map[i - 2][pos + 1] = 1;
							L3 = true;
							break;

						}
						//middle
						if (map[i][pos + 1] == 1 || map[i - 2][pos] == 1)
						{
							tmp = i - 1;
							pos += mov;
							//printf("%d**", pos);
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j][pos + 1] == 1 || map[j - 2][pos] == 1)
								{
								    //printf("oo*\n");
									tmp = j - 1;
									map[tmp - 2][pos] = 1;
									map[tmp][pos + 1] = 1;
									map[tmp - 1][pos + 1] = 1;
									map[tmp - 2][pos + 1] = 1;
									L3 = true;
									break;

								}
								//middle and bottom
								if (map[j][pos + 1] == 0 && map[j - 2][pos] == 0 && j == m)
								{
									//printf("pp");
									map[j - 2][pos] = 1;
									map[j][pos + 1] = 1;
									map[j - 1][pos + 1] = 1;
									map[j - 2][pos + 1] = 1;
									L3 = true;
                            		break;

								}
							}
						}

					}
				}
			}
			//L4
			if (tcs[k][1] - '0' == 4)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{//bottom
						if (map[i][pos] == 0 && map[i][pos + 1] == 0 && map[i][pos + 2] == 0 && i == m)
						{
							map[i][pos] = 1;
							map[i][pos + 1] = 1;
							map[i][pos + 2] = 1;
							map[i - 1][pos + 2] = 1;
							break;
						}
						//middle 
						if (map[i][pos] == 1 || map[i][pos + 1] == 1 || map[i][pos + 2] == 1)
						{
							tmp = i - 1;
							map[tmp][pos] = 1;
							map[tmp][pos + 1] = 1;
							map[tmp][pos + 2] = 1;
							map[tmp - 1][pos + 2] = 1;
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (L4 == true)
						{
							//printf("kk");
							L4 = false;
							break;
						}
						//bottom 
						if (map[i][pos] == 0 && map[i][pos + 1] == 0 && map[i][pos + 2] == 0 && i == m)
						{
							pos += mov;
							map[i][pos] = 1;
							map[i][pos + 1] = 1;
							map[i][pos + 2] = 1;
							map[i - 1][pos + 2] = 1;	
							L4 = true;
							break;

						}
						//middle
						if (map[i][pos] == 1 || map[i][pos + 1] == 1 || map[i][pos + 2] == 1)
						{
							tmp = i - 1;
							pos += mov;
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j][pos] == 1 || map[j][pos + 1] == 1 || map[j][pos + 2] == 1)
								{
									//printf("oo*\n");
									map[j - 1][pos] = 1;
									map[j - 1][pos + 1] = 1;
									map[j - 1][pos + 2] = 1;
									map[j - 2][pos + 2] = 1;
									L4 = true;
									break;

								}
								//middle and bottom
								if (j == m && map[j][pos] == 0 && map[j][pos + 1] == 0 && map[j][pos + 2] == 0)
								{
									//printf("pp");
									map[j][pos] = 1;
									map[j][pos + 1] = 1;
									map[j][pos + 2] = 1;
									map[j - 1][pos + 2] = 1;
									L4 = true;
									break;

								}
							}
						}

					}
				}
			}
			L1 = false;
			L2 = false;
			L3 = false;
			L4 = false;
		}
		//J
		if (tcs[k][0] == 'J')
		{
			//J1
			if (tcs[k][1] - '0' == 1)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{
						//bottom
						if (map[i][pos] == 0 && map[i ][pos+1] == 0 && i == m)
						{
							map[i][pos] = 1;
							map[i ][pos+1] = 1;
							map[i - 1][pos + 1] = 1;
							map[i - 2][pos + 1] = 1;
							break;
						}

						//middle 
						if (map[i][pos] == 1 || map[i ][pos+1] == 1  )
						{
							tmp = i - 1;
							map[tmp][pos] = 1;
							map[tmp ][pos+1] = 1;
							map[tmp - 1][pos + 1] = 1;
							map[tmp - 2][pos + 1] = 1;
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (J1 == true)
						{
							//printf("kk");
							J1 = false;
							break;
						}
						//bottom and move
						if (map[i][pos] == 0 && map[i ][pos+1] == 0 && map[i ][pos ] == 0 && i == m)
						{

							pos += mov;
							map[i][pos] = 1;
							map[i ][pos+1] = 1;
							map[i - 1][pos + 1] = 1;
							map[i - 2][pos + 1] = 1;
							J1 = true;
							break;

						}
						//middle
						if (map[i][pos] == 1 || map[i ][pos+1] == 1 )
						{
							tmp = i - 1;
							pos += mov;
							//printf("%d**", pos);
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j][pos] == 1 || map[j ][pos+1] == 1 )
								{
									//printf("oo*\n");
									tmp = j - 1;
									map[tmp][pos] = 1;
									map[tmp ][pos+1] = 1;
									map[tmp - 1][pos + 1] = 1;
									map[tmp - 2][pos + 1] = 1;
								    J1 = true;
									break;

								}
								//middle and bottom
								if (map[j][pos] == 0 && map[j][pos+1] == 0 && j == m)
								{
									//printf("pp");
									map[j][pos] = 1;
									map[j][pos+1] = 1;
									map[j - 1][pos + 1] = 1;
									map[j - 2][pos + 1] = 1;
									J1 = true;
									break;

								}
							}
						}

					}
				}
			}
			//J2
			if (tcs[k][1] - '0' == 2)
			{				
				if ((tcs[k][4]-'0')>=0&&(tcs[k][4]-'0')<=9)//pos two digits
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3]-'0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{//bottom
						if (map[i][pos] == 0 && map[i][pos + 1] == 0 && map[i][pos + 2] == 0 && i == m)
						{
							map[i][pos] = 1;
							map[i][pos + 1] = 1;
							map[i][pos + 2] = 1;
							map[i - 1][pos ] = 1;
							break;
						}
						//middle 
						if (map[i][pos] == 1 || map[i][pos + 1] == 1 || map[i][pos + 2] == 1)
						{
							tmp = i - 1;
							map[tmp][pos] = 1;
							map[tmp][pos + 1] = 1;
							map[tmp][pos + 2] = 1;
							map[tmp - 1][pos] = 1;
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (J2== true)
						{
							//printf("kk");
							J2 = false;
							break;
						}
						//bottom 
						if (map[i][pos] == 0 && map[i][pos + 1] == 0 && map[i][pos + 2] == 0 && i == m)
						{
							//printf("tt ");
							//printf("%d ", mov);
							pos += mov;
							map[i][pos] = 1;
							map[i][pos + 1] = 1;
							map[i][pos + 2] = 1;
							map[i - 1][pos] = 1;
							J2 = true;
							break;

						}
						//middle
						if (map[i][pos] == 1 || map[i][pos + 1] == 1 || map[i][pos + 2] == 1)
						{
							tmp = i - 1;
							pos += mov;
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j][pos] == 1 || map[j][pos + 1] == 1 || map[j][pos + 2] == 1)
								{
									//printf("oo*\n");
									map[j - 1][pos] = 1;
									map[j - 1][pos + 1] = 1;
									map[j - 1][pos + 2] = 1;
									map[j - 2][pos] = 1;
									J2 = true;
									break;

								}
								//middle and bottom
								if (j == m && map[j][pos] == 0 && map[j][pos + 1] == 0 && map[j][pos + 2] == 0)
								{
									//printf("pp");
									map[j][pos] = 1;
									map[j][pos + 1] = 1;
									map[j][pos + 2] = 1;
									map[j - 1][pos ] = 1;
									J2 = true;
									break;

								}
							}
						}

					}
				}
			}
			//J3
			if (tcs[k][1] - '0' == 3)
			{

				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)//pos two digits
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{
						//bottom
						if (map[i][pos] == 0 && map[i - 2][pos+1] == 0  && i == m)
						{
							map[i][pos] = 1;
							map[i-1][pos ] = 1;
							map[i - 2][pos ] = 1;
							map[i - 2][pos + 1] = 1;
							break;
						}

						//middle 
						if (map[i][pos] == 1 || map[i - 2][pos+1] == 1 )
						{
							//printf("%d",pos);
							tmp = i - 1;
							map[tmp][pos] = 1;
							map[tmp-1][pos ] = 1;
							map[tmp - 2][pos ] = 1;
							map[tmp - 2][pos + 1] = 1;
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (J3 == true)
						{
							//printf("kk");
							J3 = false;
							break;
						}
						//bottom and move
						if (map[i][pos] == 0 && map[i - 2][pos+1] == 0  && i == m)
						{

							pos += mov;
							map[i][pos] = 1;
							map[i-1][pos ] = 1;
							map[i - 2][pos ] = 1;
							map[i - 2][pos + 1] = 1;
							J3 = true;
							break;

						}
						//middle
						if (map[i][pos] == 1 || map[i - 2][pos+1] == 1 )
						{
							tmp = i - 1;
							pos += mov;
							//printf("%d**", pos);
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j][pos] == 1 || map[j - 2][pos+1] == 1 )
								{
									//printf("oo*\n");
									tmp = j - 1;
									map[tmp][pos] = 1;
									map[tmp-1][pos ] = 1;
									map[tmp - 2][pos ] = 1;
									map[tmp - 2][pos + 1] = 1;
									J3 = true;
									break;

								}
								//middle and bottom
								if (map[j][pos] == 0 && map[j - 2][pos+1] == 0 && j == m)
								{
									//printf("pp");
									map[j][pos] = 1;
									map[j+1][pos ] = 1;
									map[j - 2][pos ] = 1;
									map[j - 2][pos + 1] = 1;
									J3 = true;
									break;

								}
							}
						}

					}
				}
			}
			//J4
			if (tcs[k][1] - '0' == 4)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{
						//bottom
						if (map[i-1][pos] == 0 && map[i - 1][pos+1] == 0 && map[i - 1][pos + 2] == 0 && map[i ][pos + 2] == 0 && i == m)
						{
							map[i-1][pos] = 1;
							map[i - 1][pos+1] = 1;
							map[i - 1][pos + 2] = 1;
							map[i ][pos + 2] = 1;
							break;
						}

						//middle 
						if (map[i-1][pos] == 1 || map[i - 1][pos+1] == 1 || map[i - 1][pos + 2] == 1 || map[i ][pos + 2] == 1)
						{
							tmp = i - 1;
							map[tmp-1][pos] = 1;
							map[tmp - 1][pos+1] = 1;
							map[tmp - 1][pos + 2] = 1;
							map[tmp ][pos + 2] = 1;
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (J4 == true)
						{
							//printf("kk");
							J4 = false;
							break;
						}
						//bottom and move
						if (map[i - 1][pos] == 0 && map[i - 1][pos + 1] == 0 && map[i - 1][pos + 2] == 0 && map[i][pos + 2] == 0 && i == m)
						{

							pos += mov;
							map[i-1][pos] = 1;
							map[i - 1][pos+1] = 1;
							map[i - 1][pos + 2] = 1;
							map[i ][pos + 2] = 1;
							J4 = true;
							break;

						}
						//middle
						if (map[i - 1][pos] == 1 || map[i - 1][pos + 1] == 1 || map[i - 1][pos + 2] == 1 || map[i][pos + 2] == 1)
						{
							tmp = i - 1;
							pos += mov;
							//printf("%d**", pos);
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j - 1][pos] == 1 || map[j - 1][pos + 1] == 1 || map[j - 1][pos + 2] == 1 || map[j][pos + 2] == 1)
								{
									//printf("oo*\n");
									tmp = j - 1;
									map[tmp-1][pos] = 1;
									map[tmp - 1][pos+1] = 1;
									map[tmp - 1][pos + 2] = 1;
									map[tmp ][pos + 2] = 1;
									J4= true;
									break;

								}
								//middle and bottom
								if (map[j - 1][pos] == 0 && map[j - 1][pos + 1] == 0 && map[j - 1][pos + 2] == 0 && map[j][pos + 2] == 0 && j == m)
								{
									//printf("pp");
									map[j-1][pos] = 1;
									map[j - 1][pos+1] = 1;
									map[j - 1][pos + 2] = 1;
									map[j ][pos + 2] = 1;
									J4 = true;
									break;

								}
							}
						}

					}
				}
			}	
			J1 = false;
			J2 = false;
			J3 = false;
			J4 = false;
		}
		if (tcs[k][0] == 'S')
		{
			//S1
			if (tcs[k][1] - '0' == 1)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{
						//bottom
						if (map[i][pos] == 0 && map[i][pos + 1] == 0 &&map[i-1][pos+2]==0&& i == m)
						{
							map[i][pos] = 1;
							map[i][pos + 1] = 1;
							map[i - 1][pos + 1] = 1;
							map[i - 1][pos + 2] = 1;
							break;
						}

						//middle 
						if (map[i][pos] == 1 || map[i][pos + 1] == 1||map[i-1][pos+2]==1)
						{
							tmp = i - 1;
							map[tmp][pos] = 1;
							map[tmp][pos + 1] = 1;
							map[tmp - 1][pos + 1] = 1;
							map[tmp - 1][pos + 2] = 1;
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (S1 == true)
						{
							//printf("kk");
							S1 = false;
							break;
						}
						//bottom and move
						if (map[i][pos] == 0 && map[i][pos + 1] == 0 && map[i - 1][pos + 2] == 0 && i == m)
						{

							pos += mov;
							map[i][pos] = 1;
							map[i][pos + 1] = 1;
							map[i - 1][pos + 1] = 1;
							map[i - 1][pos + 2] = 1;
							S1 = true;
							break;

						}
						//middle
						if (map[i][pos] == 1 || map[i][pos + 1] == 1 || map[i - 1][pos + 2] == 1)
						{
							tmp = i - 1;
							pos += mov;
							//printf("%d**", pos);
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j][pos] == 1 || map[j][pos + 1] == 1 || map[j - 1][pos + 2] == 1)
								{
									//printf("oo*\n");
									tmp = j - 1;
									map[tmp][pos] = 1;
									map[tmp][pos + 1] = 1;
									map[tmp - 1][pos + 1] = 1;
									map[tmp - 1][pos + 2] = 1;
									S1 = true;
									break;

								}
								//middle and bottom
								if (map[j][pos] == 0 && map[j][pos + 1] == 0 && j == m)
								{
									//printf("pp");
									map[j][pos] = 1;
									map[j][pos + 1] = 1;
									map[j - 1][pos + 1] = 1;
									map[j - 1][pos + 2] = 1;
									S1 = true;
									break;

								}
							}
						}

					}
				}
			}
			//S2
			if (tcs[k][1] - '0' == 2)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{
						//bottom
						if (map[i - 1][pos] == 0 && map[i][pos + 1] == 0 && map[i - 1][pos + 2] == 0 && i == m)
						{
							map[i - 1][pos] = 1;
							map[i - 1][pos + 1] = 1;
							map[i - 2][pos ] = 1;
							map[i][pos + 1] = 1;
							break;
						}
						//middle 
						if (map[i - 1][pos] == 1 || map[i][pos + 1] == 1 || map[i - 1][pos + 2] == 1)
						{
							tmp = i - 2;
							map[tmp][pos] = 1;
							map[tmp][pos + 1] = 1;
							map[tmp-2][pos ] = 1;
							map[tmp + 1][pos + 1] = 1;
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (S2 == true)
						{
							//printf("kk");
						     S2 = false;
							break;
						}
						//bottom and move
						if (map[i - 1][pos] == 0 && map[i][pos + 1] == 0 && map[i - 1][pos + 2] == 0 && i == m)
						{
							//printf("pp");
							pos += mov;
							map[i - 1][pos] = 1;
							map[i - 1][pos + 1] = 1;
							map[i - 2][pos ] = 1;
							map[i][pos + 1] = 1;
							S2 = true;
							break;

						}
						//middle
						if (map[i][pos] == 1 || map[i + 1][pos + 1] == 1 || map[i][pos + 2] == 1)
						{
							tmp = i - 1;
							pos += mov;
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j][pos] == 1 || map[j + 1][pos + 1] == 1 || map[j][pos + 2] == 1)
								{
									//printf("oo*\n");
									map[j - 1][pos] = 1;
									map[j - 1][pos + 1] = 1;
									map[j - 2][pos ] = 1;
									map[j][pos + 1] = 1;
									S2 = true;
									break;

								}
								//middle and bottom
								if (j == m && map[j][pos] == 0 && map[j][pos + 1] == 0 && map[j][pos + 2] == 0)
								{
									//printf("pp");
									map[j - 1][pos] = 1;
									map[j - 1][pos + 1] = 1;
									map[j - 2][pos ] = 1;
									map[j][pos + 1] = 1;
									S2 = true;
									break;

								}
							}
						}

					}
				}
			}
			S1 = false;
			S2 = false;
		}
		if (tcs[k][0] == 'Z')
		{
			//Z1
			if (tcs[k][1] - '0' == 1)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{
						//bottom
						if (map[i - 1][pos] == 0 && map[i][pos + 1] == 0 && map[i][pos + 2] == 0 && i == m)
						{
							map[i - 1][pos] = 1;
							map[i - 1][pos + 1] = 1;
							map[i ][pos + 2] = 1;
							map[i][pos + 1] = 1;
							break;
						}
						//middle 
						if (map[i - 1][pos] == 1 || map[i][pos + 1] == 1 || map[i][pos + 2] == 1)
						{
							tmp = i -1;
							map[tmp-1][pos] = 1;
							map[tmp-1][pos + 1] = 1;
							map[tmp][pos + 2] = 1;
							map[tmp][pos + 1] = 1;
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (Z1 == true)
						{
							//printf("kk");
							Z1 = false;
							break;
						}
						//bottom and move
						if (map[i - 1][pos] == 0 && map[i][pos + 1] == 0 && map[i][pos + 2] == 0 && i == m)
						{
							//printf("pp");
							pos += mov;
							map[i - 1][pos] = 1;
							map[i - 1][pos + 1] = 1;
							map[i][pos + 2] = 1;
							map[i][pos + 1] = 1;
							Z1 = true;
							break;

						}
						//middle
						if (map[i - 1][pos] == 1 || map[i][pos + 1] == 1 || map[i][pos + 2] == 1)
						{
							tmp = i - 1;
							pos += mov;
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j - 1][pos] == 1 || map[j][pos + 1] == 1 || map[j][pos + 2] == 1)
								{
									//printf("oo*\n");
									map[j - 2][pos] = 1;
									map[j - 2][pos + 1] = 1;
									map[j-1][pos + 2] = 1;
									map[j-1][pos + 1] = 1;
									Z1 = true;
									break;

								}
								//middle and bottom
								if (map[j - 1][pos] == 0 && map[j][pos + 1] == 0 && map[j][pos + 2] == 0 && j == m)
								{
									//printf("pp");
									map[j - 1][pos] = 1;
									map[j - 1][pos + 1] = 1;
									map[j ][pos + 2] = 1;
									map[j][pos + 1] = 1;
									Z1 = true;
									break;

								}
							}
						}

					}
				}
			}
			//Z2
			if (tcs[k][1] - '0' == 2)
			{
				if ((tcs[k][4] - '0') >= 0 && (tcs[k][4] - '0') <= 9)
				{
					pos = (tcs[k][3] - '0') * 10 + tcs[k][4] - '0';
					if (tcs[k][6] == '-')//minus sign
					{
						if ((tcs[k][8] - '0') >= 0 && (tcs[k][8] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][7] - '0') * 10 + tcs[k][8] - '0');
						}
						else mov = (tcs[k][7] - '0') * (-1);//one digits
					}
					else if (tcs[k][6] != '-')//positive
					{
						//printf("!=-");
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							//printf("haa");
							mov = (tcs[k][6] - '0') * 10 + tcs[k][7] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][6] - '0';//one digit
					}
				}
				//pos one degit
				else //if (tcs[k][4] == '\0')
				{
					pos = tcs[k][3] - '0';
					if (tcs[k][5] == '-')//minus sign
					{
						if ((tcs[k][7] - '0') >= 0 && (tcs[k][7] - '0') <= 9)//two digits
						{
							mov = (-1) * ((tcs[k][6] - '0') * 10 + tcs[k][7] - '0');
						}
						else mov = (tcs[k][6] - '0') * (-1);//one digits
					}
					else if (tcs[k][5] != '-')//positive sign
					{
						//printf("!=-");
						if ((tcs[k][6] - '0') >= 0 && (tcs[k][6] - '0') <= 9)//two digits
						{
							//printf("haha");
							mov = (tcs[k][5] - '0') * 10 + tcs[k][6] - '0';
							//printf("%d", mov);
						}
						else mov = tcs[k][5] - '0';//one digit
					}

				}
				// no move
				if (mov == 0)
				{
					for (int i = 1; i <= m; i++)
					{
						//bottom
						if (map[i][pos] == 0 && map[i - 1][pos + 1] == 0 && i == m)
						{
							map[i][pos] = 1;
							map[i - 1][pos] = 1;
							map[i - 2][pos+1] = 1;
							map[i - 1][pos + 1] = 1;
							break;
						}

						//middle 
						if (map[i][pos] == 1 || map[i - 1][pos + 1] == 1)
						{
							tmp = i - 1;
							map[tmp][pos] = 1;
							map[tmp - 1][pos] = 1;
							map[tmp - 2][pos+1] = 1;
							map[tmp - 1][pos + 1] = 1;
							break;
						}
					}
				}
				//move
				else if (mov != 0)
				{
					for (int i = 1; i <= m; i++)
					{
						if (Z2 == true)
						{
							//printf("kk");
							Z2= false;
							break;
						}
						//bottom and move
						if (map[i][pos] == 0 && map[i - 1][pos + 1] == 0 && i == m)
						{

							pos += mov;
							map[i][pos] = 1;
							map[i - 1][pos] = 1;
							map[i - 2][pos+1] = 1;
							map[i - 1][pos + 1] = 1;
							Z2 = true;
							break;

						}
						//middle
						if (map[i][pos] == 1 || map[i - 1][pos + 1] == 1)
						{
							tmp = i - 1;
							pos += mov;
							//printf("%d**", pos);
							for (int j = tmp; j <= m; j++)
							{   //middle and middle
								if (map[j][pos] == 1 || map[j - 1][pos + 1] == 1)
								{
									//printf("oo*\n");
									tmp = j - 1;
									map[tmp][pos] = 1;
									map[tmp - 1][pos] = 1;
									map[tmp - 2][pos+1] = 1;
									map[tmp - 1][pos + 1] = 1;
									Z2 = true;
									break;

								}
								//middle and bottom
								if (map[j][pos] == 0 && map[j - 1][pos + 1] == 0 && j == m)
								{
									//printf("pp");
									map[j][pos] = 1;
									map[j - 1][pos] = 1;
									map[j - 2][pos+1] = 1;
									map[j - 1][pos + 1] = 1;
									Z2 = true;
									break;

								}
							}
						}

					}
				}
			}
			Z1 = false;
			Z2 = false;
		}
			
		//to eliminate row		
		for (int i = m; i >= 1; i--)
		{
			if (check == true)
			{
				i = m;
				check = false;
			}

			//printf("%d--", i);
			for (int j = 1; j <= n;j++)
			{//the row has 0 element
				//printf("%d**", j);
				if (map[i][j] == 0)break;
				//the whole row is all 1
				else if (j == n && map[i][j] == 1)
				{//make the whole row 0
					//printf("j:%d", j);
					//printf("one\n");
					check = true;
					for (int k = 1; k <= n; k++)
					{
						map[i][k] = 0;
						tmp = i-1;
					}//whenever there is one move to the next row
					for(int f=tmp;f>=1;f--)
						for (int r = 1; r <= n; r++)
						{
							if (map[f][r] == 1)
							{
								map[f][r] = 0;
								map[f + 1][r] = 1;
							}
						}
				
				}
			}
		}
		//check the border
		for (int i = 1; i <= n; i++)
		{
			
			if (map[0][i] != 2)
			{
				printf("cross the  border");
				break;
			}
		}
		
	}

    //draw map
	for (int i = 1; i <= m; i++)
	{
		//if(i!=1)printf("\n");
		for (int j = 1; j <= n; j++)
		{
			if(j!=n)printf("%d ", map[i][j]);
			else printf("%d\n", map[i][j]);
		}
	}
	//draw into file
	for (int i = 1; i <= m; i++)
	{
		//if(i!=1)printf("\n");
		for (int j = 1; j <= n; j++)
		{
			if (j != n)fprintf(fn,"%d ", map[i][j]);
			else fprintf(fn,"%d\n", map[i][j]);
		}
	}
	
	fclose(tc);
	fclose(fn);
	return 0;
}
//for (int i = 1; i <= m; i++)
		//{
		//	//if(i!=1)printf("\n");
		//	for (int j = 1; j <= n; j++)
		//	{
		//		if (j != n)printf("%d ", map[i][j]);
		//		else printf("%d\n", map[i][j]);
		//	}
		//}
		//printf("\n");