#include<iostream>
#include<atlstr.h>
#include<graphics.h>
#include<conio.h>


using namespace std;
typedef struct player Player;
typedef struct monster Monster;
struct player
{
	char name[10];
	int layer;
	int x;
	int y;
	int max_hp;
	int cur_hp;
	int atk;
	int def;
	int key;
	int win;
	int score;
};
struct monster
{
	char name[20];
	int hp;
	int hpmax;
	int atk;
	int def;
	int score;
	int spec;
}Shrem = { "Shrem",10,10,5,5,5,0 }, Skeleton = { "Skeleton",16,16,8,8,8,0 }, Abyssapostle{ "Abyss apostle",100,100,15,15,25,2 }, demonking{ "demon king",100,100,25,15,100,0 }, bat{ "vampire bat", 25,25,15,0,10,1 };
int Title();
void squareprint(int position[2], const IMAGE square[17], int No);
void mapprint(const int layer[10][10], const IMAGE square[17]);
void statusprint(const IMAGE* pstatus, const Player* pbraver);
void generalload(IMAGE square[17]);
Player initialplayer();
void initialmap(int layer[10][10], int originlayer[10][10]);
void move(Player* pbraver, int layer[10][10], int nextposition[2], int* ptemp);
void battletitle();
void battle1(Player* pbraver, Monster monster);
void battle2(Player* pbraver, Monster monster);
void battle3(Player* pbraver, Monster monster);
void battle4(Player* pbraver, Monster monster);
void openjourna(int layer[10][10]);
void openjourna1(int x, int y, int num);
void openjourna2(int x, int y, int num);
void openjourna3(int x, int y, int num);
void openjourna4(int x, int y, int num);
void openjourna5(int x, int y, int num);
void producer();
void victoryinterface(const Player* pbraver);
void failureinterface(const Player* pbraver);
int main()
{
	int option;
	int originlayer1[10][10] = { {1,1,1,1,1,1,1,1,1,1},{1,0,11,3,1,1,20,0,10,1},{1,0,0,11,1,1,0,0,11,1},{1,2,1,1,1,1,1,1,2,1},{1,0,33,0,1,1,0,30,0,1},{1,31,10,31,1,1,30,10,30,1},{1,0,31,0,1,1,0,30,0,1},{1,30,13,30,1,1,31,10,30,1},{1,11,30,12,2,2,12,30,11,1},{1,1,1,1,1,1,1,1,1,1} };
	int originlayer2[10][10] = { {1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1},{1,1,0,0,0,0,0,12,1,1},{1,1,12,1,1,1,1,0,1,1},{1,1,31,1,0,4,1,33,1,1},{1,1,11,1,14,0,1,0,1,1},{1,1,5,1,1,32,1,0,1,1},{1,1,5,5,0,0,1,34,1,1},{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1} };
	int layer1[10][10];
	int layer2[10][10];
	int nextposition[2];
	char key;
	int temp = 0, * ptemp = NULL;
	IMAGE square[17], status;
	Player braver = { "braver",1,6,1,50,50,20,5,1,0,0 };
	generalload(square);
	loadimage(&status, _T("Status.png"), 200, 600);
	initgraph(1100, 600);
	setbkcolor(RGB(255, 255, 255));
	cleardevice();
	do
	{
		option = Title();
		switch (option)
		{
		case 0:
			braver = initialplayer();
			initialmap(layer1, originlayer1);
			initialmap(layer2, originlayer2);
			temp = 0;
			ptemp = &temp;
			while (braver.cur_hp > 0 && braver.win == 0)
			{
				cleardevice();
				battletitle();
				BeginBatchDraw();
				statusprint(&status, &braver);
				if (braver.layer == 1)
				{
					mapprint(layer1, square);
					EndBatchDraw();
					key = _getch();
					switch (key)
					{
					case'X':
					case'x':
						openjourna(layer1);
						break;
					case 72:
					case 'W':
					case 'w':
						nextposition[0] = braver.y - 1;
						nextposition[1] = braver.x;
						move(&braver, layer1, nextposition, ptemp);
						break;
					case 80:
					case 'S':
					case 's':
						nextposition[0] = braver.y + 1;
						nextposition[1] = braver.x;
						move(&braver, layer1, nextposition, ptemp);
						break;
					case  75:
					case 'A':
					case 'a':
						nextposition[0] = braver.y;
						nextposition[1] = braver.x - 1;
						move(&braver, layer1, nextposition, ptemp);
						break;
					case 77:
					case 'D':
					case 'd':
						nextposition[0] = braver.y;
						nextposition[1] = braver.x + 1;
						move(&braver, layer1, nextposition, ptemp);
						break;
					}
					if (braver.layer == 2)layer2[braver.y][braver.x] = 20;
				}
				else if (braver.layer == 2)
				{
					mapprint(layer2, square);
					EndBatchDraw();
					key = _getch();
					switch (key)
					{
					case'X':
					case'x':
						openjourna(layer2);
						break;
					case 72:
					case 'W':
					case 'w':
						nextposition[0] = braver.y - 1;
						nextposition[1] = braver.x;
						move(&braver, layer2, nextposition, ptemp);
						break;
					case 80:
					case 'S':
					case 's':
						nextposition[0] = braver.y + 1;
						nextposition[1] = braver.x;
						move(&braver, layer2, nextposition, ptemp);
						break;
					case  75:
					case 'A':
					case 'a':
						nextposition[0] = braver.y;
						nextposition[1] = braver.x - 1;
						move(&braver, layer2, nextposition, ptemp);
						break;
					case 77:
					case 'D':
					case 'd':
						nextposition[0] = braver.y;
						nextposition[1] = braver.x + 1;
						move(&braver, layer2, nextposition, ptemp);
						break;
					}
					if (braver.layer == 1)layer1[braver.y][braver.x] = 20;
				}
			}
			cleardevice();
			if (braver.cur_hp <= 0)
			{
				failureinterface(&braver);
				cleardevice();
			}
			else if (braver.win == 1)
			{
				victoryinterface(&braver);
				cleardevice();
			}
			break;
		case 1:
			producer();
			break;
		case 2:
			printf("EXIT THE GAME.\n");
			printf("Welcome to play again next time.\n");
			break;
		}
	} while (option != 2);
	return 0;
}
int Title()
{
	IMAGE titlegraph, title, arrow, tip;
	int option = 0;
	char key;
	const int startb[2] = { 200,280 };
	const int producerb[2] = { 200,400 };
	const int exitb[2] = { 200,510 };
	loadimage(&titlegraph, _T("title.png"), 750, 600);
	putimage(75, 0, &titlegraph);
	loadimage(&arrow, _T("arrow1.png"));
	putimage(startb[0], startb[1], &arrow);
	loadimage(&tip, _T("tip.png"));
	putimage(175, 200, &tip);
	while (1)
	{
		key = _getch();
		switch (key)
		{
		case 80:
		case'S':
		case's':
			if (option < 2)option++;
			break;
		case 72:
		case 'w':
		case'W':
			if (option > 0)option--;
			break;
		case  13:
			if (option == 0)return 0;
			else if (option == 1)return 1;
			else if (option == 2)return 2;
		}
		cleardevice();
		putimage(75, 0, &titlegraph);
		putimage(175, 200, &tip);
		if (option == 0)putimage(startb[0], startb[1], &arrow);
		else if (option == 1)putimage(producerb[0], producerb[1], &arrow);
		else if (option == 2)putimage(exitb[0], exitb[1], &arrow);
	}
}
void squareprint(int position[2], const IMAGE square[17], int No)
{
	switch (No)
	{
	case 0:
		putimage(position[0], position[1], &square[1]);
		break;
	case 1:
		putimage(position[0], position[1], &square[2]);
		break;
	case 2:
		putimage(position[0], position[1], &square[3]);
		break;
	case 3:
		putimage(position[0], position[1], &square[4]);
		break;
	case 4:
		putimage(position[0], position[1], &square[5]);
		break;
	case 5:
		putimage(position[0], position[1], &square[6]);
		break;
	case 10:
		putimage(position[0], position[1], &square[7]);
		break;
	case 11:
		putimage(position[0], position[1], &square[8]);
		break;
	case 12:
		putimage(position[0], position[1], &square[9]);
		break;
	case 13:
		putimage(position[0], position[1], &square[10]);
		break;
	case 14:
		putimage(position[0], position[1], &square[11]);
		break;
	case 20:
		putimage(position[0], position[1], &square[0]);
		break;
	case 30:
		putimage(position[0], position[1], &square[12]);
		break;
	case 31:
		putimage(position[0], position[1], &square[13]);
		break;
	case 32:
		putimage(position[0], position[1], &square[16]);
		break;
	case 33:
		putimage(position[0], position[1], &square[14]);
		break;
	case 34:
		putimage(position[0], position[1], &square[15]);
		break;
	}
}
void mapprint(const int layer[10][10], const IMAGE square[17])
{
	int position0[2] = { 225,0 }, position[2], i, j;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			position[0] = position0[0] + 60 * j;
			position[1] = position0[1] + 60 * i;
			squareprint(position, square, layer[i][j]);
		}
}
void statusprint(const IMAGE* pstatus, const Player* pbraver)
{
	putimage(25, 0, pstatus);
	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 255, 255));
	settextstyle(25, 10, _T("微软雅黑"));
	CString strlayer, strcurhp, strmaxhp, stratk, strdef, strscore, strkey;
	strlayer.Format(_T("%d"), pbraver->layer);
	strcurhp.Format(_T("%d"), pbraver->cur_hp);
	strmaxhp.Format(_T("%d"), pbraver->max_hp);
	stratk.Format(_T("%d"), pbraver->atk);
	strdef.Format(_T("%d"), pbraver->def);
	strscore.Format(_T("%d"), pbraver->score);
	strkey.Format(_T("%d"), pbraver->key);
	LPCTSTR lstrlayer = strlayer.AllocSysString(), lstrcurhp = strcurhp.AllocSysString(), lstrmaxhp = strmaxhp.AllocSysString(), lstratk = stratk.AllocSysString(), lstrdef = strdef.AllocSysString(), lstrscore = strscore.AllocSysString(), lstrkey = strkey.AllocSysString();
	outtextxy(100, 25, lstrlayer);
	outtextxy(100, 85, lstrcurhp);
	outtextxy(130, 85, _T('/'));
	outtextxy(140, 85, lstrmaxhp);
	outtextxy(100, 145, lstratk);
	outtextxy(100, 205, lstrdef);
	outtextxy(100, 265, lstrscore);
	settextcolor(YELLOW);
	outtextxy(100, 325, lstrkey);
}
void generalload(IMAGE square[17])
{
	loadimage(&square[0], _T("./the braver.png"), 60, 60);
	loadimage(&square[1], _T("./vacancy.png"), 60, 60);
	loadimage(&square[2], _T("./wall.png"), 60, 60);
	loadimage(&square[3], _T("./door.png"), 60, 60);
	loadimage(&square[4], _T("./up staircase.png"), 60, 60);
	loadimage(&square[5], _T("./down staircase.png"), 60, 60);
	loadimage(&square[6], _T("./magma.png"), 60, 60);
	loadimage(&square[7], _T("./key.png"), 60, 60);
	loadimage(&square[8], _T("./red potion.png"), 60, 60);
	loadimage(&square[9], _T("./blue potion.png"), 60, 60);
	loadimage(&square[10], _T("./sword.png"), 60, 60);
	loadimage(&square[11], _T("./armour.png"), 60, 60);
	loadimage(&square[12], _T("./shrem.png"), 60, 60);
	loadimage(&square[13], _T("./skeleton.png"), 60, 60);
	loadimage(&square[14], _T("./abyss apostle.png"), 60, 60);
	loadimage(&square[15], _T("./demon king.png"), 60, 60);
	loadimage(&square[16], _T("./vampire bat.png"), 60, 60);
}
Player initialplayer()
{
	Player braver = { "braver" };
	braver.layer = 1;
	braver.x = 6;
	braver.y = 1;
	braver.max_hp = 50;
	braver.cur_hp = 50;
	braver.atk = 20;
	braver.def = 5;
	braver.key = 1;
	braver.win = 0;
	braver.score = 0;
	return braver;
}
void initialmap(int layer[10][10], int originlayer[10][10])
{
	int i, j;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			layer[i][j] = originlayer[i][j];
		}
}
void move(Player* pbraver, int layer[10][10], int nextposition[2], int* ptemp)
{
	if (layer[nextposition[0]][nextposition[1]] == 1)return;
	else if (layer[nextposition[0]][nextposition[1]] == 2 && pbraver->key == 0)return;
	else
	{
		layer[pbraver->y][pbraver->x] = *ptemp;
		pbraver->x = nextposition[1];
		pbraver->y = nextposition[0];
		switch (layer[nextposition[0]][nextposition[1]])
		{
		case 0:
			*ptemp = 0;
			break;
		case 2:
			*ptemp = 0;
			pbraver->key--;
			break;
		case 3:
			pbraver->layer++;
			*ptemp = 4;
			pbraver->x = 5;
			pbraver->y = 4;
			break;
		case 4:
			pbraver->layer--;
			*ptemp = 3;
			pbraver->x = 3;
			pbraver->y = 1;
			break;
		case 5:
			*ptemp = 5;
			pbraver->cur_hp -= 5;
			break;
		case 10:
			*ptemp = 0;
			pbraver->key++;
			break;
		case 11:
			*ptemp = 0;
			pbraver->cur_hp += 10;
			if (pbraver->cur_hp > pbraver->max_hp)pbraver->cur_hp = pbraver->max_hp;
			break;
		case 12:
			*ptemp = 0;
			pbraver->cur_hp += 25;
			if (pbraver->cur_hp > pbraver->max_hp)pbraver->cur_hp = pbraver->max_hp;
			break;
		case 13:
			*ptemp = 0;
			pbraver->atk += 20;
			break;
		case 14:
			*ptemp = 0;
			pbraver->def += 10;
			break;
		case 30:
			*ptemp = 0;
			battle1(pbraver, Shrem);
			break;
		case 31:
			*ptemp = 0;
			battle1(pbraver, Skeleton);
			break;
		case 32:
			battle2(pbraver, bat);
			break;
		case 33:
			*ptemp = 0;
			battle3(pbraver, Abyssapostle);
			break;
		case 34:
			*ptemp = 0;
			battle4(pbraver, demonking);
			break;
		}
		layer[nextposition[0]][nextposition[1]] = 20;
	}
}
void openjourna(int layer[10][10])
{
	cleardevice();
	settextcolor(BLACK);
	int i = 0;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	int n5 = 0;
	char key = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			switch (layer[i][j])
			{
			case 30:
				n1++;
				break;
			case 31:
				n2++;
				break;
			case 32:
				n3++;
				break;
			case 33:
				n4++;
				break;
			case 34:
				n5++;
				break;
			}
		}
	}
	if (n1 != 0)
	{
		openjourna1(0, 0, n1);
		i++;
	}
	if (n2 != 0)
	{
		openjourna2(0, 140 * i, n2);
		i++;
	}
	if (n3 != 0)
	{
		openjourna3(0, 140 * i, n3);
		i++;
	}
	if (n4 != 0)
	{
		openjourna4(0, 140 * i, n4);
		i++;
	}
	if (n5 != 0)
	{
		openjourna5(0, 140 * i, n5);
		i++;
	}
	while (key != 'z' && key != 'Z')
	{
		key = _getch();
	}
}
void openjourna1(int x, int y, int num)
{
	CString strnum;
	strnum.Format(_T("%d"), num);
	LPCTSTR lstrnum = strnum.AllocSysString();
	outtextxy(x + 100, y + 120, lstrnum);
	outtextxy(x, y, _T("名字：史莱姆酱"));
	outtextxy(x, y + 20, _T("血量：10"));
	outtextxy(x, y + 40, _T("攻击：5"));
	outtextxy(x, y + 60, _T("防御：5"));
	outtextxy(x, y + 80, _T("分数：5"));
	outtextxy(x, y + 100, _T("特殊属性：无"));
	outtextxy(x, y + 120, _T("剩余数量："));
}
void openjourna2(int x, int y, int num)
{
	CString strnum;
	strnum.Format(_T("%d"), num);
	LPCTSTR lstrnum = strnum.AllocSysString();
	outtextxy(x + 100, y + 120, lstrnum);
	outtextxy(x, y, _T("名字：骷髅"));
	outtextxy(x, y + 20, _T("血量：16"));
	outtextxy(x, y + 40, _T("攻击：8"));
	outtextxy(x, y + 60, _T("防御：8"));
	outtextxy(x, y + 80, _T("分数：8"));
	outtextxy(x, y + 100, _T("特殊属性：无"));
	outtextxy(x, y + 120, _T("剩余数量："));
}
void openjourna3(int x, int y, int num)
{
	CString strnum;
	strnum.Format(_T("%d"), num);
	LPCTSTR lstrnum = strnum.AllocSysString();
	outtextxy(x + 100, y + 120, lstrnum);
	outtextxy(x, y, _T("名字：吸血蝙蝠"));
	outtextxy(x, y + 20, _T("血量：25"));
	outtextxy(x, y + 40, _T("攻击：15"));
	outtextxy(x, y + 60, _T("防御：0"));
	outtextxy(x, y + 80, _T("分数：10"));
	outtextxy(x, y + 100, _T("特殊属性：吸血"));
	outtextxy(x, y + 120, _T("剩余数量："));
}
void openjourna4(int x, int y, int num)
{
	CString strnum;
	strnum.Format(_T("%d"), num);
	LPCTSTR lstrnum = strnum.AllocSysString();
	outtextxy(x + 100, y + 120, lstrnum);
	outtextxy(x, y, _T("名字：深渊使徒"));
	outtextxy(x, y + 20, _T("血量：50"));
	outtextxy(x, y + 40, _T("攻击：30"));
	outtextxy(x, y + 60, _T("防御：15"));
	outtextxy(x, y + 80, _T("分数：25"));
	outtextxy(x, y + 100, _T("特殊属性：精神污染"));
	outtextxy(x, y + 120, _T("剩余数量："));
}
void openjourna5(int x, int y, int num)
{
	CString strnum;
	strnum.Format(_T("%d"), num);
	LPCTSTR lstrnum = strnum.AllocSysString();
	outtextxy(x + 100, y + 120, lstrnum);
	outtextxy(x, y, _T("名字：魔王"));
	outtextxy(x, y + 20, _T("血量：100"));
	outtextxy(x, y + 40, _T("攻击：25"));
	outtextxy(x, y + 60, _T("防御：15"));
	outtextxy(x, y + 80, _T("分数：100"));
	outtextxy(x, y + 100, _T("特殊属性：无"));
	outtextxy(x, y + 120, _T("剩余数量："));
}
void producer()
{
	cleardevice();
	settextcolor(BLACK);
	settextstyle(40, 15, _T("TIMESNEWROMAN"));
	int x = 160;
	int y = 60;
	char key = 0;
	outtextxy(x, y, _T("Developer name : Ye Teng"));
	outtextxy(x, y + 100, _T("Developer name : Junhui Sun"));
	outtextxy(x + 100, y + 200, _T("School : N J U"));
	outtextxy(x - 50, y + 300, _T("Enter 'z' to return to the main page."));
	while (key != 'z' && key != 'Z')
	{
		key = _getch();
	}
}
void victoryinterface(const Player* pbraver)
{
	CString strscore;
	strscore.Format(_T("%d"), pbraver->score);
	LPCTSTR lstrscore = strscore.AllocSysString();
	cleardevice();
	settextstyle(40, 15, _T("TIMESNEWROMAN"));
	settextcolor(RED);
	outtextxy(160, 70, _T("Congratulations! You have won the game."));
	outtextxy(160, 130, _T(" Your final score is "));
	outtextxy(500, 130, lstrscore);
	settextcolor(BLACK);
	int x = 160;
	int y = 250;
	char key = 0;
	outtextxy(x, y, _T("Developer name : Ye Teng"));
	outtextxy(x, y + 100, _T("Developer name : Junhui Sun"));
	outtextxy(x + 100, y + 200, _T("School : N J U"));
	outtextxy(x - 50, y + 300, _T("Enter Z to return to the main page."));
	while (key != 'z' && key != 'Z')
	{
		key = _getch();
	}
}
void failureinterface(const Player* pbraver)
{
	CString strscore;
	strscore.Format(_T("%d"), pbraver->score);
	LPCTSTR lstrscore = strscore.AllocSysString();
	cleardevice();
	settextstyle(40, 15, _T("TIMESNEWROMAN"));
	settextcolor(RED);
	outtextxy(160, 70, _T("Sorry. You failed the game and you can try it again."));
	outtextxy(160, 130, _T(" Your final score is "));
	outtextxy(500, 130, lstrscore);
	settextcolor(BLACK);
	int x = 160;
	int y = 250;
	char key = 0;
	outtextxy(x, y, _T("Developer name : Ye Teng"));
	outtextxy(x, y + 100, _T("Developer name : Junhui Sun"));
	outtextxy(x + 100, y + 200, _T("School : N J U"));
	outtextxy(x - 50, y + 300, _T("Enter Z to return to the main page."));
	while (key != 'z' && key != 'Z')
	{
		key = _getch();
	}
}
void battletitle()
{
	settextcolor(BLACK);
	settextstyle(30, 10, _T("TIMESNEWROMAN"));
	int x = 900;
	int y = 20;
	outtextxy(x, y, _T("Battle log"));
}
void battle1(Player* pbraver, Monster monster)
{
	settextcolor(BLACK);
	settextstyle(12, 8, _T("TIMESNEWROMAN"));
	char key = 0;
	int num = 0;
	int x = 900;
	int y = 60;
	while (1)
	{
		if (num == 0)
		{
			CString strnum, strcurhp1, strcurhp2;
			strnum.Format(_T("%d"), num);
			strcurhp1.Format(_T("%d"), pbraver->cur_hp);
			strcurhp2.Format(_T("%d"), monster.hp);
			LPCTSTR lstrnum = strnum.AllocSysString();
			LPCTSTR lstrcurhp1 = strcurhp1.AllocSysString();
			LPCTSTR lstrcurhp2 = strcurhp2.AllocSysString();
			outtextxy(x, y, _T("ROUND"));
			outtextxy(x + 100, y, lstrnum);
			outtextxy(x, y + 25, _T("Player HP"));
			outtextxy(x + 100, y + 25, lstrcurhp1);
			outtextxy(x, y + 50, _T("Monster HP"));
			outtextxy(x + 100, y + 50, lstrcurhp2);
			num++;
		}
		else if (num > 0)
		{
			CString strnum, strcurhp1, strcurhp2;
			strnum.Format(_T("%d"), num);
			LPCTSTR lstrnum = strnum.AllocSysString();
			outtextxy(x, y + 75 * num, _T("ROUND"));
			outtextxy(x + 100, y + 75 * num, lstrnum);
			if (pbraver->atk > monster.def)
			{
				monster.hp = monster.hp + monster.def - pbraver->atk;
				strcurhp2.Format(_T("%d"), monster.hp);
				LPCTSTR lstrcurhp2 = strcurhp2.AllocSysString();
			}
			else
			{
				monster.hp = monster.hp;
				strcurhp2.Format(_T("%d"), monster.hp);
				LPCTSTR lstrcurhp2 = strcurhp2.AllocSysString();
			}
			outtextxy(x, y + 50 + 75 * num, _T("Monster HP"));
			outtextxy(x + 100, y + 50 + 75 * num, strcurhp2);
			if (monster.hp <= 0)
			{
				pbraver->cur_hp = pbraver->cur_hp;
				strcurhp1.Format(_T("%d"), pbraver->cur_hp);
				LPCTSTR lstrcurhp1 = strcurhp1.AllocSysString();
			}
			else
			{
				if (monster.atk > pbraver->def)
				{
					pbraver->cur_hp = pbraver->cur_hp + pbraver->def - monster.atk;
				}
				else
				{
					pbraver->cur_hp = pbraver->cur_hp;
				}
				strcurhp1.Format(_T("%d"), pbraver->cur_hp);
				LPCTSTR lstrcurhp1 = strcurhp1.AllocSysString();
			}
			outtextxy(x, y + 25 + 75 * num, _T("Player HP"));
			outtextxy(x + 100, y + 25 + 75 * num, strcurhp1);
			if (pbraver->cur_hp <= 0 || monster.hp <= 0)
			{
				break;
			}
			num++;
		}
	}
	if (pbraver->cur_hp > 0)
	{
		CString strscore;
		strscore.Format(_T("%d"), monster.score);
		LPCTSTR lstrscore = strscore.AllocSysString();
		outtextxy(x, y + 75 + 75 * num, _T("You got score "));
		outtextxy(x + 120, y + 75 + 75 * num, lstrscore);
		outtextxy(x, y + 100 + 75 * num, _T("按'z'继续"));
		pbraver->score = pbraver->score + monster.score;
	}
	else
	{
		outtextxy(x, y + 75 + 75 * num, _T("Game over"));
		outtextxy(x, y + 100 + 75 * num, _T("按'z'继续"));
	}
	Sleep(2000);
	while (key != 'z' && key != 'Z')
	{
		key = _getch();
	}
}
void battle2(Player* pbraver, Monster monster)
{
	settextcolor(BLACK);
	settextstyle(12, 8, _T("TIMESNEWROMAN"));
	char key = 0;
	int num = 0;
	int x = 900;
	int y = 60;
	while (1)
	{
		if (num == 0)
		{
			CString strnum, strcurhp1, strcurhp2;
			strnum.Format(_T("%d"), num);
			strcurhp1.Format(_T("%d"), pbraver->cur_hp);
			strcurhp2.Format(_T("%d"), monster.hp);
			LPCTSTR lstrnum = strnum.AllocSysString();
			LPCTSTR lstrcurhp1 = strcurhp1.AllocSysString();
			LPCTSTR lstrcurhp2 = strcurhp2.AllocSysString();
			outtextxy(x, y, _T("ROUND"));
			outtextxy(x + 100, y, lstrnum);
			outtextxy(x, y + 25, _T("Player HP"));
			outtextxy(x + 100, y + 25, lstrcurhp1);
			outtextxy(x, y + 50, _T("Monster HP"));
			outtextxy(x + 100, y + 50, lstrcurhp2);
			num++;
		}
		else if (num > 0)
		{
			CString strnum, strcurhp1, strcurhp2;
			strnum.Format(_T("%d"), num);
			LPCTSTR lstrnum = strnum.AllocSysString();
			outtextxy(x, y + 75 * num, _T("ROUND"));
			outtextxy(x + 100, y + 75 * num, lstrnum);
			if (pbraver->atk > monster.def)
			{
				if (pbraver->atk >= monster.def + monster.hp)
				{
					monster.hp = monster.hp + monster.def - pbraver->atk;
				}
				else
				{
					if (monster.atk > pbraver->def)
					{
						int a = monster.hp + monster.def - pbraver->atk + monster.atk - pbraver->def;
						if (a > monster.hpmax)
						{
							monster.hp = monster.hpmax;
						}
						else
						{
							monster.hp = a;
						}
					}
					else
					{
						monster.hp = monster.hp + monster.def - pbraver->atk;
					}
				}
				strcurhp2.Format(_T("%d"), monster.hp);
				LPCTSTR lstrcurhp2 = strcurhp2.AllocSysString();
			}
			else
			{
				monster.hp = monster.hp;
				strcurhp2.Format(_T("%d"), monster.hp);
				LPCTSTR lstrcurhp2 = strcurhp2.AllocSysString();
			}
			outtextxy(x, y + 50 + 75 * num, _T("Monster HP"));
			outtextxy(x + 100, y + 50 + 75 * num, strcurhp2);
			if (monster.hp <= 0)
			{
				pbraver->cur_hp = pbraver->cur_hp;
				strcurhp1.Format(_T("%d"), pbraver->cur_hp);
				LPCTSTR lstrcurhp1 = strcurhp1.AllocSysString();
			}
			else
			{
				if (monster.atk > pbraver->def)
				{
					pbraver->cur_hp = pbraver->cur_hp + pbraver->def - monster.atk;
				}
				else
				{
					pbraver->cur_hp = pbraver->cur_hp;
				}
				strcurhp1.Format(_T("%d"), pbraver->cur_hp);
				LPCTSTR lstrcurhp1 = strcurhp1.AllocSysString();
			}
			outtextxy(x, y + 25 + 75 * num, _T("Player HP"));
			outtextxy(x + 100, y + 25 + 75 * num, strcurhp1);
			if (pbraver->cur_hp <= 0 || monster.hp <= 0)
			{
				break;
			}
			num++;
		}
	}
	if (pbraver->cur_hp > 0)
	{
		CString strscore;
		strscore.Format(_T("%d"), monster.score);
		LPCTSTR lstrscore = strscore.AllocSysString();
		outtextxy(x, y + 75 + 75 * num, _T("You got score "));
		outtextxy(x + 120, y + 75 + 75 * num, lstrscore);
		outtextxy(x, y + 100 + 75 * num, _T("按'z'继续"));
		pbraver->score = pbraver->score + monster.score;
	}
	else
	{
		outtextxy(x, y + 75 + 75 * num, _T("Game over"));
		outtextxy(x, y + 100 + 75 * num, _T("按'z'继续"));
	}
	Sleep(2000);
	while (key != 'z' && key != 'Z')
	{
		key = _getch();
	}
}
void battle3(Player* pbraver, Monster monster)
{
	settextcolor(BLACK);
	settextstyle(12, 8, _T("TIMESNEWROMAN"));
	char key = 0;
	int num = 0;
	int x = 900;
	int y = 60;
	while (1)
	{
		if (num == 0)
		{
			CString strnum, strcurhp1, strcurhp2;
			strnum.Format(_T("%d"), num);
			strcurhp1.Format(_T("%d"), pbraver->cur_hp);
			strcurhp2.Format(_T("%d"), monster.hp);
			LPCTSTR lstrnum = strnum.AllocSysString();
			LPCTSTR lstrcurhp1 = strcurhp1.AllocSysString();
			LPCTSTR lstrcurhp2 = strcurhp2.AllocSysString();
			outtextxy(x, y, _T("ROUND"));
			outtextxy(x + 100, y, lstrnum);
			outtextxy(x, y + 25, _T("Player HP"));
			outtextxy(x + 100, y + 25, lstrcurhp1);
			outtextxy(x, y + 50, _T("Monster HP"));
			outtextxy(x + 100, y + 50, lstrcurhp2);
			num++;
		}
		else if (num > 0 && num % 4 != 0)
		{
			CString strnum, strcurhp1, strcurhp2;
			strnum.Format(_T("%d"), num);
			LPCTSTR lstrnum = strnum.AllocSysString();
			outtextxy(x, y + 75 * num, _T("ROUND"));
			outtextxy(x + 100, y + 75 * num, lstrnum);
			if (pbraver->atk > monster.def)
			{
				monster.hp = monster.hp + monster.def - pbraver->atk;
				strcurhp2.Format(_T("%d"), monster.hp);
				LPCTSTR lstrcurhp2 = strcurhp2.AllocSysString();
			}
			else
			{
				monster.hp = monster.hp;
				strcurhp2.Format(_T("%d"), monster.hp);
				LPCTSTR lstrcurhp2 = strcurhp2.AllocSysString();
			}
			outtextxy(x, y + 50 + 75 * num, _T("Monster HP"));
			outtextxy(x + 100, y + 50 + 75 * num, strcurhp2);
			if (monster.hp <= 0)
			{
				pbraver->cur_hp = pbraver->cur_hp;
				strcurhp1.Format(_T("%d"), pbraver->cur_hp);
				LPCTSTR lstrcurhp1 = strcurhp1.AllocSysString();
			}
			else
			{
				if (monster.atk > pbraver->def)
				{
					pbraver->cur_hp = pbraver->cur_hp + pbraver->def - monster.atk;
				}
				else
				{
					pbraver->cur_hp = pbraver->cur_hp;
				}
				strcurhp1.Format(_T("%d"), pbraver->cur_hp);
				LPCTSTR lstrcurhp1 = strcurhp1.AllocSysString();
			}
			outtextxy(x, y + 25 + 75 * num, _T("Player HP"));
			outtextxy(x + 100, y + 25 + 75 * num, strcurhp1);
			if (pbraver->cur_hp <= 0 || monster.hp <= 0)
			{
				break;
			}
			num++;
		}
		else
		{
			CString strnum, strcurhp1, strcurhp2;
			strnum.Format(_T("%d"), num);
			LPCTSTR lstrnum = strnum.AllocSysString();
			outtextxy(x, y + 75 * num, _T("ROUND"));
			outtextxy(x + 100, y + 75 * num, lstrnum);
			monster.hp = monster.hp;
			strcurhp2.Format(_T("%d"), monster.hp);
			LPCTSTR lstrcurhp2 = strcurhp2.AllocSysString();
			outtextxy(x, y + 50 + 75 * num, _T("Monster HP"));
			outtextxy(x + 100, y + 50 + 75 * num, strcurhp2);
			if (monster.atk > pbraver->def)
			{
				pbraver->cur_hp = pbraver->cur_hp + pbraver->def - monster.atk;
			}
			else
			{
				pbraver->cur_hp = pbraver->cur_hp;
			}
			strcurhp1.Format(_T("%d"), pbraver->cur_hp);
			LPCTSTR lstrcurhp1 = strcurhp1.AllocSysString();
			outtextxy(x, y + 25 + 75 * num, _T("Player HP"));
			outtextxy(x + 100, y + 25 + 75 * num, strcurhp1);
			outtextxy(x + 150, y + 25 + 75 * num, _T("(Stop)"));
			if (pbraver->cur_hp <= 0 || monster.hp <= 0)
			{
				break;
			}
			num++;
		}
	}
	if (pbraver->cur_hp > 0)
	{
		CString strscore;
		strscore.Format(_T("%d"), monster.score);
		LPCTSTR lstrscore = strscore.AllocSysString();
		outtextxy(x, y + 75 + 75 * num, _T("You got score "));
		outtextxy(x + 120, y + 75 + 75 * num, lstrscore);
		outtextxy(x, y + 100 + 75 * num, _T("按'z'继续"));
		pbraver->score = pbraver->score + monster.score;
	}
	else
	{
		outtextxy(x, y + 75 + 75 * num, _T("Game over"));
		outtextxy(x, y + 100 + 75 * num, _T("按'z'继续"));
	}
	Sleep(2000);
	while (key != 'z' && key != 'Z')
	{
		key = _getch();
	}
}
void battle4(Player* pbraver, Monster monster)
{
	settextcolor(BLACK);
	settextstyle(12, 8, _T("TIMESNEWROMAN"));
	char key = 0;
	int num = 0;
	int x = 900;
	int y = 60;
	while (1)
	{
		if (num == 0)
		{
			CString strnum, strcurhp1, strcurhp2;
			strnum.Format(_T("%d"), num);
			strcurhp1.Format(_T("%d"), pbraver->cur_hp);
			strcurhp2.Format(_T("%d"), monster.hp);
			LPCTSTR lstrnum = strnum.AllocSysString();
			LPCTSTR lstrcurhp1 = strcurhp1.AllocSysString();
			LPCTSTR lstrcurhp2 = strcurhp2.AllocSysString();
			outtextxy(x, y, _T("ROUND"));
			outtextxy(x + 100, y, lstrnum);
			outtextxy(x, y + 25, _T("Player HP"));
			outtextxy(x + 100, y + 25, lstrcurhp1);
			outtextxy(x, y + 50, _T("Monster HP"));
			outtextxy(x + 100, y + 50, lstrcurhp2);
			num++;
		}
		else if (num > 0)
		{
			CString strnum, strcurhp1, strcurhp2;
			strnum.Format(_T("%d"), num);
			LPCTSTR lstrnum = strnum.AllocSysString();
			outtextxy(x, y + 75 * num, _T("ROUND"));
			outtextxy(x + 100, y + 75 * num, lstrnum);
			if (pbraver->atk > monster.def)
			{
				monster.hp = monster.hp + monster.def - pbraver->atk;
				strcurhp2.Format(_T("%d"), monster.hp);
				LPCTSTR lstrcurhp2 = strcurhp2.AllocSysString();
			}
			else
			{
				monster.hp = monster.hp;
				strcurhp2.Format(_T("%d"), monster.hp);
				LPCTSTR lstrcurhp2 = strcurhp2.AllocSysString();
			}
			outtextxy(x, y + 50 + 75 * num, _T("Monster HP"));
			outtextxy(x + 100, y + 50 + 75 * num, strcurhp2);
			if (monster.hp <= 0)
			{
				pbraver->cur_hp = pbraver->cur_hp;
				strcurhp1.Format(_T("%d"), pbraver->cur_hp);
				LPCTSTR lstrcurhp1 = strcurhp1.AllocSysString();
			}
			else
			{
				if (monster.atk > pbraver->def)
				{
					pbraver->cur_hp = pbraver->cur_hp + pbraver->def - monster.atk;
				}
				else
				{
					pbraver->cur_hp = pbraver->cur_hp;
				}
				strcurhp1.Format(_T("%d"), pbraver->cur_hp);
				LPCTSTR lstrcurhp1 = strcurhp1.AllocSysString();
			}
			outtextxy(x, y + 25 + 75 * num, _T("Player HP"));
			outtextxy(x + 100, y + 25 + 75 * num, strcurhp1);
			if (pbraver->cur_hp <= 0 || monster.hp <= 0)
			{
				break;
			}
			num++;
		}
	}
	if (pbraver->cur_hp > 0)
	{
		CString strscore;
		strscore.Format(_T("%d"), monster.score);
		LPCTSTR lstrscore = strscore.AllocSysString();
		outtextxy(x, y + 75 + 75 * num, _T("You got score "));
		outtextxy(x + 120, y + 75 + 75 * num, lstrscore);
		outtextxy(x, y + 100 + 75 * num, _T("按'z'继续"));
		pbraver->score = pbraver->score + monster.score;
		pbraver->win = 1;
	}
	else
	{
		outtextxy(x, y + 75 + 75 * num, _T("Game over"));
		outtextxy(x, y + 100 + 75 * num, _T("按'z'继续"));
	}
	Sleep(2000);
	while (key != 'z' && key != 'Z')
	{
		key = _getch();
	}
}