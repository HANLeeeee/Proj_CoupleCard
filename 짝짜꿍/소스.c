#include<stdio.h>      //printf, scanf
#include<stdlib.h>      //rand敗呪 戚遂
#include<windows.h>      //system紫遂
#include<conio.h>      //徹左球脊径獣 鉢檎戚 戚疑
#include<time.h>      //srand敗呪戚遂


#define Esc 27
#define Enter 13
#define COL GetStdHandle(STD_OUTPUT_HANDLE)     //事薗走舛
#define 褐事 SetConsoleTextAttribute(COL, 0x0002);
#define 項精噺事 SetConsoleTextAttribute(COL, 0x0007);
#define 噺事 SetConsoleTextAttribute(COL, 0x0008);
#define 尻砧事 SetConsoleTextAttribute(COL, 0x000a);
#define 葛空事 SetConsoleTextAttribute(COL, 0x000e);
#define 避事 SetConsoleTextAttribute(COL, 0x00);

int key;
int score = 0;
int lastscore = 0;
int bestscore = 0;

void firstpage_draw();
void gameover_draw();
void levelup_draw(int(*card_b)[8]);

void firstpage();      //湛凪戚走鉢檎
void gameover();      //惟績魁劾凶
void Q();            //惟績亀掻康澗但
void how();			 //繕拙狛

void gamestart();      //惟績獣拙
void game();         //惟績敗呪

void xpage(int(*card_b)[8]);
void checkpage(int ix1, int iy1, int ix2, int iy2, int nn1, int nn2);
int re = 0;
int lv = 1;      //傾婚
int a, b;      //亜稽人 室稽
int inputx1, inputy1, inputx2, inputy2;   //脊径葵
int n1, n2;      //朝球紗 収切
int timer = 1000;

int card_number[8][8] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main(void)
{
	firstpage();

	return 0;
}

void firstpage()
{
	int select = 0, ch = 0;
	while (1)
	{
		system("cls");

		if (select == 0)
		{
			葛空事 firstpage_draw();
			尻砧事 printf("                                   ∈	GAME START\n");
			項精噺事 printf("                                   	繕拙狛\n");
			項精噺事 printf("	                                蟹亜奄\n\n\n\n       ");
			項精噺事 printf("                       �� : 五敢 朕辞 是稽 戚疑\n\n");
			項精噺事 printf("                              �� : 五敢 朕辞 焼掘稽 戚疑\n\n");
			項精噺事 printf("                                   Enter : 五敢 識澱\n\n\n\n\n");
			葛空事 printf("�蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩�");

		}
		else if (select == 1)
		{
			葛空事 firstpage_draw();
			項精噺事 printf("                                   	GAME START\n");
			尻砧事 printf("                                   ∈	繕拙狛\n");
			項精噺事 printf("	                                蟹亜奄\n\n\n\n       ");
			項精噺事 printf("                       �� : 五敢 朕辞 是稽 戚疑\n\n");
			項精噺事 printf("                              �� : 五敢 朕辞 焼掘稽 戚疑\n\n");
			項精噺事 printf("                                   Enter : 五敢 識澱\n\n\n\n\n");
			葛空事 printf("�蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩�");
		}
		else if (select == 2)
		{
			葛空事 firstpage_draw();
			項精噺事 printf("                                   	GAME START\n");
			項精噺事 printf("		                        繕拙狛\n");
			尻砧事 printf("                                   ∈	蟹亜奄\n\n\n\n      ");
			項精噺事 printf("                        �� : 五敢 朕辞 是稽 戚疑\n\n");
			項精噺事 printf("                              �� : 五敢 朕辞 焼掘稽 戚疑\n\n");
			項精噺事 printf("                                   Enter : 五敢 識澱\n\n\n\n\n");
			葛空事 printf("�蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩�");
		}



		ch = _getch();
		if (ch == 'w')
		{
			if (select == 0) select = 2;
			else select--;
		}
		else if (ch == 's')
		{
			if (select == 2) select = 0;
			else select++;
		}
		else if (ch == Enter && select == 0)
		{
			system("cls");
			gamestart();
		}
		else if (ch == Enter && select == 1)
		{
			how();
		}
		else if (ch == Enter && select == 2)
		{
			exit(0);
		}
	}
}

void firstpage_draw()
{
	葛空事 printf("�蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩�\n\n\n\n");
	printf("     ** ** ** **  ***********  *     ************* *       *************     ** ** ** **\n");
	printf("     ** ** ** **    * * * *    *        * * * *    *             *     *     ** ** ** **\n");
	printf(" **  ** ** ** **   *   **  *   ****    *   **  *   *             *     *     ** ** ** **  **\n");
	printf("  ** ** ** ** **  *    **   *  *      *    **   *  ****   *****************  ** ** ** ** **\n");
	printf("   *************               *     *      *    * *              *          *************\n");
	printf("    ************   *************                   *              *          ************\n");
	printf("    ************               *                   *             ***         ************\n");
	printf("     **********                *                   *            *   *         **********\n");
	printf("      ********                 *                   *             ***           ********\n\n\n\n\n");
}


void gamestart()
{
	int card_back[8][8] = { 88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
		88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
		88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
		88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88 };
	int(*card_b)[8] = card_back;         //朝球急檎壕伸段奄鉢

	int clear;
	int i, j;
	int fail = 0;
	while (1)
	{
		system("cls");
		game();
		Sleep((timer));
		system("cls");
		xpage(card_back);

		項精噺事 printf("\n\n\n < x疎妊研 胡煽脊径廃 板 y疎妊研 脊径馬檎 馬蟹税 朝球 疎妊亜 刃失吉陥壱 馬革推 > \n");

		while (1)
		{

			re = 0;
			while (re == 0)
			{
				項精噺事 printf("\n# 湛腰属 朝球税 疎妊研 脊径馬獣神\n");
				scanf_s("  %d   %d", &inputx1, &inputy1);

				if (card_number[8 - inputy1][inputx1 - 1] != 0)
					re++;
				else
				{
					system("cls");
					xpage(card_back);
					葛空事 printf("\n\n\n 止斥- 業郊稽 左獣惟蟹");
				}

			}
			re = 0;
			while (re == 0)
			{
				項精噺事 printf("\n# 砧腰属 朝球税 疎妊研 脊径馬獣神\n");
				scanf_s("  %d   %d", &inputx2, &inputy2);

				if (card_number[8 - inputy2][inputx2 - 1] != 0)
					re++;
				else
				{
					system("cls");
					xpage(card_back);
					葛空事 printf("\n\n\n 止斥-止戚斥--- 業郊稽 左獣惟蟹");
				}

			}

			inputx1 = inputx1 - 1;
			inputy1 = 8 - inputy1;
			inputx2 = inputx2 - 1;
			inputy2 = 8 - inputy2;
			n1 = card_number[inputy1][inputx1];
			n2 = card_number[inputy2][inputx2];

			system("cls");

			checkpage(inputx1, inputy1, inputx2, inputy2, n1, n2);

			if (n1 == n2)
			{
				Sleep(2000);
				system("cls");
				card_back[inputy1][inputx1] = 79;
				card_back[inputy2][inputx2] = 79;

			}

			else
			{

				fail++;
				if (fail == 5)
				{
					Sleep(2500);
					system("cls");
					gameover();
				}
				else
				{
					Sleep(2500);
					system("cls");
				}
			}
			xpage(card_back);


			clear = 0;
			for (i = 0; i < 8; i++)
			{
				for (j = 0; j < 8; j++)
				{
					if (card_back[i][j] == 79)
					{
						clear++;
						timer += 1000;
					}
				}
			}
			printf("\n\n\t               戚腰 傾婚 側 鯵呪 : %d\n", lv);
			if (clear == (2 * lv))
			{
				Sleep(2000);
				lv++;


				system("cls");
				levelup_draw(card_b);
			}
			else if (clear == 65)
				gameover();
		}
	}
}



void game()
{
	int x, y;

	int done = 0;                                 //収切研 脊径馬澗 朝球鯵呪
	int cardnum = 65;                               //朝球腰硲
	int cardtime = 0;                              //収切亜 2腰 蟹尽澗走

	while (done != (2 * lv))                        //done戚 16戚鞠檎 魁
	{
		while (1)
		{
			srand(time(NULL));
			x = rand() % 8;
			y = rand() % 8;
			if (card_number[y][x] == 0)
			{
				card_number[y][x] = cardnum;
				done++;
				if (cardtime == 1)
				{
					cardtime = 0;
					cardnum++;
				}
				else
					cardtime = 1;
			}
			else break;
			if (done == (2 * lv))
				break;
		}
	}

	int num1 = 8;
	int num2 = 0;

	for (a = 0; a < 8; a++)
	{
		項精噺事 printf("%dΒ\t", num1);
		num1--;
		for (b = 0; b < 8; b++)
		{
			printf("%c\t", card_number[a][b]);
		}
		printf("\n\n\n");
	}
	printf("Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α\n");
	while (num2 <= 8)
	{
		printf("%d\t", num2);
		num2++;
	}
}


void xpage(int(*card_b)[8])         //朝球税 急檎
{
	int num1 = 8;
	int num2 = 0;

	for (a = 0; a < 8; a++)
	{
		printf("%dΒ\t", num1);
		num1--;
		for (b = 0; b < 8; b++)
		{
			if (card_number[a][b] != 0)
				printf("%c\t", *(*(card_b + a) + b));
			else
				printf("\t");
		}
		printf("\n\n\n");
	}
	printf("Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α\n");
	while (num2 <= 8)
	{
		printf("%d\t", num2);
		num2++;
	}
}



void checkpage(int ix1, int iy1, int ix2, int iy2, int nn1, int nn2)
{
	card_number[iy1][ix1] = nn1;
	card_number[iy2][ix2] = nn2;

	int num1 = 8;
	int num2 = 0;

	for (a = 0; a < 8; a++)
	{
		項精噺事 printf("%dΒ\t", num1);
		num1--;
		for (b = 0; b < 8; b++)
		{
			if (card_number[a][b] != 0)
			{
				if ((a == iy1) && (b == ix1))
				{
					尻砧事 printf("%c\t", nn1);
				}
				else if ((a == iy2) && (b == ix2))
				{
					尻砧事 printf("%c\t", nn2);
				}
				else
					printf("%c\t", 88);
			}
			else
				printf("\t");
		}
		printf("\n\n\n");
	}
	項精噺事 printf("Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α Α\n");
	while (num2 <= 8)
	{
		項精噺事 printf("%d\t", num2);
		num2++;
	}
}

void levelup_draw(int(*card_b)[8])
{
	system("cls");
	葛空事 printf("�蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩�\n\n\n\n");
	printf("   *                                            *                 *         *   **********\n");
	printf("   *                                            *                 *         *   *         *\n");
	printf("   *                                            *                 *         *   *         *\n");
	printf("   *            *******  *       *   *******    *                 *         *   **********\n");
	printf("   *           *********  *     *   *********   *                 *         *   *\n");
	printf("   *           *           *   *    *           *                  *       *    *\n");
	printf("   **********   *******      *       *******    *                   *******     *\n\n");
	尻砧事 printf("\n\n                         ずせずせずせ 傾婚穣戚 鞠写柔艦陥 ずせずせずせずせ\n\n\n\n");
	項精噺事 printf("                              殖斗研 刊牽檎 陥製 傾婚稽 角嬢逢艦陥.\n\n");
	printf("                              ESC研 刊牽檎 惟績曽戟但生稽 角嬢逢艦陥.\n\n\n\n");
	葛空事 printf("�蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩�");

	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			card_number[i][j] = 0;
			card_b[i][j] = 88;
		}
	}


	while (1) {
		if (_kbhit())
		{
			key = _getch();
			if (key == Enter)
				gamestart();
			else if (key == Esc)
				Q();
		}
	}


}


void gameover()
{
	int select = 0, ch = 0;

	while (1)
	{
		system("cls");


		if (select == 0)
		{
			gameover_draw();
			尻砧事 printf("                                   ∈	RESTART\n");
			項精噺事 printf("                                   	HOME\n");
			項精噺事 printf("	                                蟹亜奄\n\n\n\n       ");
			項精噺事 printf("                       �� : 五敢 朕辞 是稽 戚疑\n\n");
			項精噺事 printf("                              �� : 五敢 朕辞 焼掘稽 戚疑\n\n");
			項精噺事 printf("                                   Enter : 五敢 識澱\n\n\n\n\n");
			葛空事 printf("�蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩�");
		}


		else if (select == 1)
		{
			gameover_draw();
			項精噺事 printf("                                   	RESTART\n");
			尻砧事 printf("                                   ∈	HOME\n");
			項精噺事 printf("	                                蟹亜奄\n\n\n\n       ");
			項精噺事 printf("                       �� : 五敢 朕辞 是稽 戚疑\n\n");
			項精噺事 printf("                              �� : 五敢 朕辞 焼掘稽 戚疑\n\n");
			項精噺事 printf("                                   Enter : 五敢 識澱\n\n\n\n\n");
			葛空事 printf("�蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩�");
		}

		else if (select == 2)
		{
			gameover_draw();
			項精噺事 printf("                                   	RESTART\n");
			項精噺事 printf("		                        HOME\n");
			尻砧事 printf("                                   ∈	蟹亜奄\n\n\n\n      ");
			項精噺事 printf("                        �� : 五敢 朕辞 是稽 戚疑\n\n");
			項精噺事 printf("                              �� : 五敢 朕辞 焼掘稽 戚疑\n\n");
			項精噺事 printf("                                   Enter : 五敢 識澱\n\n\n\n\n");
			葛空事 printf("�蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩�");
		}


		ch = _getch();
		if (ch == 'w')
		{
			if (select == 0) select = 2;
			else select--;
		}
		else if (ch == 's')
		{
			if (select == 2) select = 0;
			else select++;
		}
		else if (ch == Enter && select == 0)
		{
			gamestart();
		}
		else if (ch == Enter && select == 1)
		{
			firstpage();
		}
		else if (ch == Enter && select == 2)
		{
			exit(0);
		}
	}
}

void gameover_draw()
{
	葛空事 printf("�蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩蕩�\n\n\n\n");
	printf("  ********       *        *        * ********        ********  *           * ******** *******\n");
	printf(" *              * *       * *    * * *              *        *  *         *  *        *      *\n");
	printf(" *             *   *      *  *  *  * *              *        *   *       *   *        *      *\n");
	printf(" *   *****    *     *     *   **   * ********       *        *    *     *    ******** *******\n");
	printf(" *       *   *********    *        * *              *        *     *   *     *        *     *\n");
	printf(" *       *  *         *   *        * *              *        *      * *      *        *      *\n");
	printf(" ********* *           *  *        * ********        ********        *       ******** *       *\n\n\n\n\n\n\n");
}




void how()
{
	system("cls");
	褐事  printf("＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                         ");
	項精噺事 printf("[繕拙狛]");
	褐事 printf("                                           ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                           ");
	項精噺事 printf("1. 旭精 硝督昏晦軒 切軒研 奄常廃陥.");
	褐事 printf("                              ＝\n");
	褐事 printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                           ");
	項精噺事 printf("2. 奄常廃 硝督昏税 疎妊研 脊径廃陥.");
	褐事 printf("                              ＝\n");
	褐事 printf("＝                                                                                            ＝\n");
	printf("＝                            ");
	項精噺事 printf("- (x葵y葵)");
	褐事 printf("                                                      ＝\n");
	printf("＝                            ");
	項精噺事 printf("=> x = 神献楕生稽 朕走澗 葵, y = 是楕生稽 朕走澗 葵             ");
	褐事 printf("＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                           ");
	項精噺事 printf("3. 舛岩戚檎 脊径廃 硝督昏 切軒亜 X => O稽 郊駕陥.                ");
	褐事 printf("＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                             ");
	項精噺事 printf("* Esc研 刊牽檎 坦製 鉢檎生稽 宜焼逢艦陥.");
	褐事 printf("                       ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝                                                                                            ＝\n");
	printf("＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝");
	while (1) {
		if (_kbhit())
		{
			key = _getch();
			if (key == Esc)
			{
				firstpage();
			}
		}
	}
}

void Q()
{
	int select = 0, ech = 0;

	while (1)
	{
		system("cls");

		if (select == 0)
		{
			printf("\n\n\n\n\n\n\n\n");
			褐事 printf("                                ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n");
			printf("                                ＝                                  ＝\n");
			printf("                                ＝                                  ＝\n");
			printf("                                ＝");
			項精噺事 printf("         ∈   CONTINUE");
			褐事 printf("            ＝\n");
			printf("                                ＝                                  ＝\n");
			printf("                                ＝          ");
			項精噺事 printf("    Exit         ");
			褐事 printf("       ＝\n");
			printf("                                ＝                                  ＝\n");
			printf("                                ＝                                  ＝\n");
			printf("                                ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n");
			printf("                                       惟績精 坦製採斗 獣拙桔艦陥.\nn");
		}
		else if (select == 1)
		{
			printf("\n\n\n\n\n\n\n\n");
			褐事 printf("                                ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n");
			printf("                                ＝                                  ＝\n");
			printf("                                ＝                                  ＝\n");
			printf("                                ＝            ");
			項精噺事 printf("  CONTINUE   ");
			褐事 printf("         ＝\n");
			printf("                                ＝                                  ＝\n");
			printf("                                ＝        ");
			項精噺事 printf(" ∈   Exit       ");
			褐事 printf("         ＝\n");
			printf("                                ＝                                  ＝\n");
			printf("                                ＝                                  ＝\n");
			printf("                                ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n");
			printf("                                       惟績精 坦製採斗 獣拙桔艦陥.\n\n");
		}
		ech = _getch();
		if (ech == 'w')
		{
			if (select == 0) select = 1;
			else select--;
		}
		else if (ech == 's')
		{
			if (select == 1) select = 0;
			else select++;
		}
		else if (ech == Enter && select == 0)
		{
			gamestart();
		}
		else if (ech == Enter && select == 1)
		{
			exit(0);
		}
	}
}
