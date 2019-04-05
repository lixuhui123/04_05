#include<stdio.h>
#include<stdlib.h>

int Menu()
{
	printf("***********************\n");
	printf("***** 1:��ʼ��Ϸ  *****\n");
	printf("***** 0:������Ϸ  *****\n");
	printf("***********************\n");
	printf("����������ѡ��\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
#define MAX_ROW 3
#define MAX_COL 3
char chess_board[MAX_ROW][MAX_COL];
void Init()
{
	//��������x��ʾ������ӣ�o��ʾ��������
	//" "��ʾδ����
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
		printf("�������\n");
		printf("������һ������(row,col),row[0-2],col[0-2]\n");
		int row = 0;
		int col = 0;
		scanf("%d,%d", &row, &col);
		if ((row >= MAX_ROW || row < 0) || (col >= MAX_COL || col < 0))
		{

			printf("��������Ƿ�����������\n");
			continue;
		}
		if (chess_board[row][col] != 32)
		{
			printf("������������ѱ�ռ������������\n");
			continue;
		}
		chess_board[row][col] = 88;
		break;
	}

}
//���Ҫ���������˷���1���򷵻�0
int IsFull()
{
	
	for (int row = 0; row < MAX_ROW; ++row)
	{
		for (int col = 0; col < MAX_COL; ++col)
		{
			if (chess_board[row][col] != 32)
				return 1;
		}
	}
	return 0;
}
char  CheckGameOver()
{//����X
	//����O
	//����a����
	//����b�Ȳ���Ҳûʤ������������Ϸ ��
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
	return 'b';
}
void ComputerMove()
{
	printf("��������\n");
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
	//1.��������ʼ��һ������
	Init();
	
	while (1)
	{
		//2.��ӡ����
		Print();

		//3.�������
		PlayerMove();
		//break;
		//4.�ж�
		//CheckGameOver();
		//����X
	    //����O
	    //����a����
	    //����b�Ȳ���Ҳûʤ����
		char winner = CheckGameOver();
		if (winner != 'b')
		{
			//�ֳ�ʤ�����ߺ���
			break;
		}
		//5.��������
		ComputerMove();

		//6.�ж�
		CheckGameOver();
		winner = CheckGameOver();
		if (winner != 'b')
		{
			//�ֳ�ʤ�����ߺ���
			break;
		}
		
	}
	char winner = CheckGameOver();
	if (winner == 88)
	{
		printf("���ʤ��\n");
	}
	else if (winner == 79)
	{
		printf("��̫����\n");
	}
	else if (winner == 'a')
		printf("�͵������忪\n");
	else if (winner == ' ')
		printf("��������\n");
	else if (winner == 'b')
		printf("���������\n");
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
			printf("��������\n");
		}
	}
	system("pause");
	return 0;
}