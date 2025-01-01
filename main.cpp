#include <stdio.h>
#include <graphics.h>
#include <math.h>
int flag = 0;
int ChessMap[20][20] = {0};
int jude(int Mapx, int Mapy) {
	int temp = 2 - flag % 2;
	//判断竖
	for (int i = Mapx - 4, j = Mapy;i <= Mapx;i++)
	{
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i + 1][j]
			&& temp == ChessMap[i + 2][j] && temp == ChessMap[i + 3][j]
			&& temp == ChessMap[i + 4][j]) {
			return 1;
		}
	}
	//判定横
	for (int i = Mapx, j = Mapy - 4;i <= Mapx, j <= Mapy;j++) {
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i][j + 1]
			&& temp == ChessMap[i][j + 2] && temp == ChessMap[i][j + 3]
			&& temp == ChessMap[i][j + 4]) {
			return 1;
		}
	}
	//判定东北
	for (int i = Mapx - 4, j = Mapy - 4;i <= Mapx, j <= Mapy;j++, i++) {
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i + 1][j + 1]
			&& temp == ChessMap[i + 2][j + 2] && temp == ChessMap[i + 3][j + 3]
			&& temp == ChessMap[i + 4][j + 4]) {
			return 1;
		}
	}
	//判定西北
	for (int i = Mapx - 4, j = Mapy + 4;i <= Mapx, j >= Mapy;i++, j--) {
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i + 1][j - 1]
			&& temp == ChessMap[i + 2][j - 2] && temp == ChessMap[i + 3][j - 3]
			&& temp == ChessMap[i + 4][j - 4]) {
			return 1;
		}
	}
	return 0;
}
void initializegame() {
	initgraph(600, 500,SHOWCONSOLE);
	loadimage(NULL, L"bk.jpg");
	setlinecolor(BLACK);
	for (int i = 0;i < 20;i++) {
		line(25, i * 25, 475, i * 25);//横线
		line(i * 25, 25, i * 25, 475);//竖线
	}
	setlinestyle(PS_SOLID, 2);
	line(500, 0, 500, 500);
	setbkmode(100);
	settextcolor(BLACK);
	outtextxy(510, 60, L"玩家1：黑棋");
	outtextxy(510, 100, L"玩家2：白棋");
}
void playgame() {
	int Chessx = 25, Chessy = 25;
	int Mapx = 0, Mapy = 0;
	MOUSEMSG Msg;
	while (1) {
		Msg = GetMouseMsg();
		//if (Msg.uMsg == WM_LBUTTONDOWN) {//左键
		//	printf("X:%d,Y:%d\n", Msg.x, Msg.y);
		//}
		//else if (Msg.uMsg == WM_RBUTTONDOWN) {//右键
		//	printf("右\n");
		//}
		for (int i = 1;i < 20;i++) {//行
			for (int j = 1;j < 20;j++) {//列
				if ((abs(Msg.x - j * 25) < 12) && (abs(Msg.y - i * 25) < 12)) {
					Chessx = j * 25;
					Chessy = i * 25;
					Mapx = i;
					Mapy = j;
				}
			}
		}
		printf("x:%d,y:%d\n", Chessx, Chessy);
		if (Msg.uMsg == WM_LBUTTONDOWN) {
			if (ChessMap[Mapx][Mapy]!=0) {

			}
			if (flag % 2 == 0) {
				IMAGE qz;//黑棋图片
				loadimage(&qz, L"qz.jpg", 12, 12);//先把图片放在工程项目下，使用L+"绝对路径"
				putimage(Chessx - 6, Chessy - 6, &qz);
				ChessMap[Mapx][Mapy] = 1;//黑棋为1
			}
			else {
				setfillcolor(WHITE);//默认白色，练习多种技巧
				solidcircle(Chessx,Chessy,6);//白棋半径为6
				ChessMap[Mapx][Mapy] = 2;//白棋为2
			}
			flag++;
		}
		if(jude(Mapx,Mapy)){
			if (1==flag%2) {
				MessageBox(NULL, L"玩家1获胜", L"gameover", MB_OK);
				return;
			}
			else {
				MessageBox(NULL, L"玩家2获胜", L"gameover", MB_OK);
				return;
			}
		}
	}
}
int main(){
	initializegame();
	playgame();
}