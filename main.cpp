#include "Chess.h"
int main()
{
    cout << "���������1������(����)";
    Player p1(BLACK);
    cout << "���������2������";
    Player p2(WHITE);
    p1.player_info();
    p2.player_info();
    ChessBoard CB;
    int win;
    //������ѭ��
    while(true)
    {
        CB.show();
        CB.set_chess();
        win = check_win(CB);
        if(win)
        {
            p1.i_win(win);
            p2.i_win(win);
            p1.player_info();
            p2.player_info();
            break;
        }
        system("cls");
    }
    system("pause");
}