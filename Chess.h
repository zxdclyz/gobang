#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
#pragma warning(disable:4996)
#define BLACK 1
#define WHITE 2
//�������
class ChessBoard;
class Player;
//player��Ķ���
class Player
{
public:
    Player(int);
    void player_info();
    void i_win(int);
private:
    string name;
    int color;
};
//player�ĺ�������
Player::Player(int c)
{
    color = c;
    cin >> name;
}

void Player::player_info()
{
    cout << "_______________\n" << name << '\t';
    switch (color)
    {
        case BLACK:
            cout << "Black" << endl;
            break;
        case WHITE:
            cout << "White" << endl;
        default:
            break;
    }
    cout << "_______________\n";
}

void Player::i_win(int c)
{
    if(c==color)
        cout << name << "��ʤ��\n";
}

//ChessBoard��Ķ���
class ChessBoard
{
public:
    void show();
    void set_chess();
    friend int check_win(ChessBoard&);
private:
    int current_color = BLACK;
    int Board[15][15] = {0};
    int cursor[2] = {7, 7}; //(x, y)
};

//ChessBoard�ĺ�������
void ChessBoard::show()
{
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            //�ж��Ƿ�Ϊ��겢��ʾ
            if (i==cursor[1]&&j==cursor[0])
            {
                cout << "�� ";
                continue;
            }
            switch (Board[i][j])
            {
                case 0:
                    cout << "��";
                    break;

                case BLACK:
                    cout << "��";
                    break;

                case WHITE:
                    cout << "��";
                    break;

                default:
                    break;
            }
        }
        cout << endl;
    }
}

void ChessBoard::set_chess()
{
    switch (getch())
    {
        //wasd�ƶ�����
        case 'w':
            if(cursor[1]>0)cursor[1]--;
            break;

        case 's':
            if(cursor[1]<14)cursor[1]++;
            break;

        case 'a':
            if(cursor[0]>0)cursor[0]--;
            break;

        case 'd':
            if(cursor[0]<14)cursor[0]++;
            break;

        case ' '://��������
            if(Board[cursor[1]][cursor[0]]==0)//��ֹ�ظ�����
            {
                Board[cursor[1]][cursor[0]] = current_color;
                //��Ч����֮����ɫ
                if(current_color==BLACK)current_color = WHITE;
                else current_color = BLACK;
            }
            break;
        default:
            break;
    }
}

//�����ⶨ��һ���ж���Ӯ�ĺ���
int check_win(ChessBoard& CB)
{
    int (*board)[15] = new int[15][15];
    board = CB.Board;
    int i = 0, j = 0, k = 0;
    //�����м��
    for(i=0; i<15; i++)
    {
        while(j<11)
        {
            if(board[i][j]!=0
            &&board[i][j]==board[i][j+1]
            &&board[i][j]==board[i][j+2]
            &&board[i][j]==board[i][j+3]
            &&board[i][j]==board[i][j+4])
                return board[i][j];
            j++;
        }
        j=0;
    }
    //�м��
    for(j=0; j<15; j++)
    {
        while(i<11)
        {
            if(board[i][j]!=0
            &&board[i][j]==board[i+1][j]
            &&board[i][j]==board[i+2][j]
            &&board[i][j]==board[i+3][j]
            &&board[i][j]==board[i+4][j])
                return board[i][j];
            i++;
        }
        i=0;
    }
    //���·����ж�
    for(j=0; j<11; j++)
    {
        for(k=j,i=0; i<11-j; i++,k++)
        {
            if(board[i][k]!=0
            &&board[i][k]==board[i+1][k+1]
            &&board[i][k]==board[i+2][k+2]
            &&board[i][k]==board[i+3][k+3]
            &&board[i][k]==board[i+4][k+4])
                return board[i][k];
        }
    }
    for(i=0; i<11; i++)
    {
        for(k=i,j=0; j<11-i; j++,k++)
        {
            if(board[k][j]!=0
            &&board[k][j]==board[k+1][j+1]
            &&board[k][j]==board[k+2][j+2]
            &&board[k][j]==board[k+3][j+3]
            &&board[k][j]==board[k+4][j+4])
                return board[k][j];
        }
    }
    //���·����ж�
    for(j=14; j>3; j--)
    {
        for(k=j,i=0; i<j-3; i++,k--)
        {
            if(board[i][k]!=0
            &&board[i][k]==board[i+1][k-1]
            &&board[i][k]==board[i+2][k-2]
            &&board[i][k]==board[i+3][k-3]
            &&board[i][k]==board[i+4][k-4])
                return board[i][k];
        }
    }
    for(i=0; i<11; i++)
    {
        for(k=i,j=14; j>3+i; j--,k++)
        {
            if(board[k][j]!=0
            &&board[k][j]==board[k+1][j-1]
            &&board[k][j]==board[k+2][j-2]
            &&board[k][j]==board[k+3][j-3]
            &&board[k][j]==board[k+4][j-4])
                return board[k][j];
        }
    }
    return 0;
}