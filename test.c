#include<stdio.h>
#include<stdlib.h>

int Menu()
{
	printf("***********************\n");
	printf("***** 1:开始游戏  *****\n");
	printf("***** 0:结束游戏  *****\n");
	printf("***********************\n");
	printf("请输入您的选择\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
#define MAX_ROW 3
#define MAX_COL 3
char chess_board[MAX_ROW][MAX_COL];
void Init()
{
	//在棋盘里x表示玩家落子，o表示电脑落子
	//" "表示未落子
	for (int row = 0; row < MAX_ROW; ++row)
	{
		for (int col = 0; col < MAX_COL; ++col)
		{
			chess_board[row][col] = 32;
		}
	}
}
void Print()
{
	for (int row = 0; row < MAX_ROW; ++row)
	{
		printf("| %c | %c | %c |\n", chess_board[row][0],
			chess_board[row][1], chess_board[row][2]);
		printf("|___|___|___|\n");
	}
}
void PlayerMove()
{
	while (1)
	{
		printf("玩家落子\n");
		printf("请输入一组坐标(row,col),row[0-2],col[0-2]\n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if ((row >= MAX_ROW || row < 0) || (col >= MAX_COL || col < 0))
		{

			printf("您的输入非法请重新输入\n");
			continue;
		}
		if (chess_board[row][col] != 32)
		{
			printf("您输入的坐标已被占用请重新输入\n");
			continue;
		}
		chess_board[row][col] = 88;
		break;
	}

}
//如果要是棋盘满了返回1否则返回0
int IsFull()
{
	int sum = 0;
	for (int row = 0; row < MAX_ROW; ++row)
	{
		for (int col = 0; col < MAX_COL; ++col)
		{
			sum += chess_board[row][col];
			if(sum==756)

			//if (chess_board[row][col] != 32 || (chess_board[0][0]!=88 && chess_board[0][0] != 79)|| (chess_board[0][1] != 88 && chess_board[0][1] != 79) || (chess_board[0][2] != 88 && chess_board[0][2] != 79)|| (chess_board[1][0] != 88 && chess_board[1][0] != 79))//第一次遍历的时候0 0要是有值那么返回就是1
				return 1;
		}//return 1;
	}
	return 0;
}
char  CheckGameOver()
{   //返回X
	//返回O
	//返回a和棋
	//返回空格既不和也没胜负继续进行游戏 。
	for (int row = 0; row < MAX_ROW; ++row)
	{
		if (chess_board[row][0] == chess_board[row][1] &&
			chess_board[row][0] == chess_board[row][2])
			return chess_board[row][0];
	}
	for (int col = 0; col < MAX_COL; ++col)
	{
		if (chess_board[0][col] == chess_board[1][col] &&
			chess_board[0][col] == chess_board[2][col])
			return 	chess_board[0][col];
	}
	if (chess_board[0][0] == chess_board[1][1] &&
		chess_board[0][0] == chess_board[2][2])
		return chess_board[0][0];
	if (chess_board[0][2] == chess_board[1][1] &&
		chess_board[0][2] == chess_board[2][0])
		return chess_board[0][2];
	if (IsFull())
	{
		return 'a';
	}
	return ' ';
	/*在这里返回空格很巧妙，假设输入时（0 0）时第二行的检测全为空格，返回空格，如果
那么就可以用空格判断程序跳不跳出循环，具体请看判断条件。
如果赋成其他值的话，直接会跳出循环*/
}
void ComputerMove()
{
	printf("电脑落子\n");
	while (1)
	{
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chess_board[row][col] != 32)
		{
			continue;
		}
		else
		{
			chess_board[row][col] = 79;
			break;
		}
	}
}
void Game()
{
	//1.创建并初始化一个棋盘
	Init();

	while (1)
	{
		//2.打印棋盘
		Print();

		//3.玩家落子
		PlayerMove();
		//break;
		//4.判断
		CheckGameOver();
		//返回X
		//返回O
		//返回a和棋
		//返回b既不和也没胜负。
		char winne = CheckGameOver();
		if (winne != ' ')
		{
			//分出胜负或者和棋
			break;
		}
		//5.电脑落子
		ComputerMove();

		//6.判断
		CheckGameOver();
		winne = CheckGameOver();
		if (winne != ' ')
		{
			//分出胜负或者和棋
			break;
		}
	}
	char winne = CheckGameOver();
	if (winne == 88)
	{
		Print();
		printf("玩家胜利\n");
	}
	else if (winne == 79)
	{
		printf("你太菜了\n");
	}
	else if (winne == 'a')
	{
		Print();
		printf("和电脑五五开\n");
	}
	else
		printf("好像出错了\n");
}
int main()
{
	while (1)
	{
		int choice = Menu();
		if (1 == choice)
		{
			Game();
		}
		else if (0 == choice)
		{
			printf("bye_bye\n");
			break;
		}
		else
		{
			printf("输入有误\n");
		}
	}
	system("pause");
	return 0;
}
