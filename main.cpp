#include <stdio.h>
#include <graphics.h>
#include <math.h>
int flag = 0;
int ChessMap[20][20] = {0};
int jude(int Mapx, int Mapy) {
	int temp = 2 - flag % 2;
	//�ж���
	for (int i = Mapx - 4, j = Mapy;i <= Mapx;i++)
	{
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i + 1][j]
			&& temp == ChessMap[i + 2][j] && temp == ChessMap[i + 3][j]
			&& temp == ChessMap[i + 4][j]) {
			return 1;
		}
	}
	//�ж���
	for (int i = Mapx, j = Mapy - 4;i <= Mapx, j <= Mapy;j++) {
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i][j + 1]
			&& temp == ChessMap[i][j + 2] && temp == ChessMap[i][j + 3]
			&& temp == ChessMap[i][j + 4]) {
			return 1;
		}
	}
	//�ж�����
	for (int i = Mapx - 4, j = Mapy - 4;i <= Mapx, j <= Mapy;j++, i++) {
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i + 1][j + 1]
			&& temp == ChessMap[i + 2][j + 2] && temp == ChessMap[i + 3][j + 3]
			&& temp == ChessMap[i + 4][j + 4]) {
			return 1;
		}
	}
	//�ж�����
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
		line(25, i * 25, 475, i * 25);//����
		line(i * 25, 25, i * 25, 475);//����
	}
	setlinestyle(PS_SOLID, 2);
	line(500, 0, 500, 500);
	setbkmode(100);
	settextcolor(BLACK);
	outtextxy(510, 60, L"���1������");
	outtextxy(510, 100, L"���2������");
}
void playgame() {
	int Chessx = 25, Chessy = 25;
	int Mapx = 0, Mapy = 0;
	MOUSEMSG Msg;
	while (1) {
		Msg = GetMouseMsg();
		//if (Msg.uMsg == WM_LBUTTONDOWN) {//���
		//	printf("X:%d,Y:%d\n", Msg.x, Msg.y);
		//}
		//else if (Msg.uMsg == WM_RBUTTONDOWN) {//�Ҽ�
		//	printf("��\n");
		//}
		for (int i = 1;i < 20;i++) {//��
			for (int j = 1;j < 20;j++) {//��
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
				IMAGE qz;//����ͼƬ
				loadimage(&qz, L"qz.jpg", 12, 12);//�Ȱ�ͼƬ���ڹ�����Ŀ�£�ʹ��L+"����·��"
				putimage(Chessx - 6, Chessy - 6, &qz);
				ChessMap[Mapx][Mapy] = 1;//����Ϊ1
			}
			else {
				setfillcolor(WHITE);//Ĭ�ϰ�ɫ����ϰ���ּ���
				solidcircle(Chessx,Chessy,6);//����뾶Ϊ6
				ChessMap[Mapx][Mapy] = 2;//����Ϊ2
			}
			flag++;
		}
		if(jude(Mapx,Mapy)){
			if (1==flag%2) {
				MessageBox(NULL, L"���1��ʤ", L"gameover", MB_OK);
				return;
			}
			else {
				MessageBox(NULL, L"���2��ʤ", L"gameover", MB_OK);
				return;
			}
		}
	}
}
int main(){
	initializegame();
	playgame();
}