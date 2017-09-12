#include <time.h>
#include "sdl2game.h"
#include <stdbool.h>
#include <stdlib.h>

// ͼƬ��Դ
Image *UISurface;
Image *NEWGAME;
Image *NEWGAMEdown;
Image *pic0;
Image *pic2;
Image *pic4;
Image *pic8;
Image *pic16;
Image *pic32;
Image *pic64;
Image *pic128;
Image *pic256;
Image *pic512;
Image *pic1024;
Image *pic2048;

//��Ϸ����
int gamemap[4][4];
int score, bestscore, steps, gameover, gamew;
char *score_String[10];
char *best_String[10];
char *steps_String[10];

//ϵͳ״̬
bool initstate = false; // ��ʼ��״̬

bool playstate = false; // �Ƿ�����Ϸ״̬

bool buttonstate = false; // ��ť״̬

bool gamestate = false; // ��Ӯ״̬  false ��  true Ӯ
						// ��ʼ��Ϸ��Ϊ true

//������ճ�ʼ������
int All0init()
{
	int i, j;
	if (initstate != true)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				gamemap[i][j] = 0;
			}
		}
	}
}

//����ͼƬ
int loadpic()
{
	UISurface = loadimage("image/My2048.jpg");
	NEWGAME = loadimage("image/newgame.png");
	NEWGAMEdown = loadimage("image/newgamedown.png");
	pic0 = loadimage("image/0.jpg");
	pic2 = loadimage("image/2.jpg");
	pic4 = loadimage("image/4.jpg");
	pic8 = loadimage("image/8.jpg");
	pic16 = loadimage("image/16.jpg");
	pic32 = loadimage("image/32.jpg");
	pic64 = loadimage("image/64.jpg");
	pic128 = loadimage("image/128.jpg");
	pic256 = loadimage("image/256.jpg");
	pic512 = loadimage("image/512.jpg");
	pic1024 = loadimage("image/1024.jpg");
	pic2048 = loadimage("image/2048.jpg");

	return 0;
}

// ������� 2 �� 4 ����
int appear()
{
	int i, j, ran, t[16], x = 0, a, b;
	srand((int)time(0));	//������ӳ�ʼ��
	for (j = 0; j < 4; j++) //���հ׵���������걣�浽�м�����t��
	{
		for (i = 0; i < 4; i++)
		{
			if (gamemap[j][i] == 0)
			{
				t[x] = j * 10 + i;
				x++;
			}
		}
	}
	if (x == 1) //��t�����ȡһ������
	{
		ran = x - 1;
	}
	else
	{
		ran = rand() % (x - 1);
	}
	a = t[ran] / 10; //ȡ�������ֵ��ʮλ��
	b = t[ran] % 10; //ȡ�������ֵ�ĸ�λ��
	srand((int)time(0));
	if ((rand() % 9) > 2) //�ڴ˿հ����������ֵ2��4
	{
		gamemap[a][b] = 2;
	}
	else
	{
		gamemap[a][b] = 4;
	}
	return 0;
}

// ��ͼ�鿴����Ժ���(DEBUG��)
int showmap()
{
	int i, j;
	if (playstate == true)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				printf("%d ", gamemap[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

// �������ݸ���
int scoreUpdate()
{
	itoa(score, score_String, 10);
	itoa(steps, steps_String, 10);
	textsize(24);
	text(score_String, 68, 134, 0, 0, 0);
	//text(steps_String, 150, 130, 0, 0, 0);
	return 0;
}

// ��߷ּ�¼
int bestscoreRecord()
{
	if (score > bestscore)
	{
		bestscore = score;
		itoa(bestscore, best_String, 10);
	}
	text(best_String, 168, 134, 0, 0, 0);
	return 0;
}

// ���µ�ͼ
int addpic()
{
	//������ͼ�����ͼƬ
	int PicAdd, i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			image(pic0, 25 + 110 * j, 160 + 110 * i);
			if (gamemap[i][j] != 0)
			{
				if (gamemap[i][j] == 2)
				{
					image(pic2, 25 + 110 * j, 160 + 110 * i);
				}
				else if (gamemap[i][j] == 4)
				{
					image(pic4, 25 + 110 * j, 160 + 110 * i);
				}
				else if (gamemap[i][j] == 8)
				{
					image(pic8, 25 + 110 * j, 160 + 110 * i);
				}
				else if (gamemap[i][j] == 16)
				{
					image(pic16, 25 + 110 * j, 160 + 110 * i);
				}
				else if (gamemap[i][j] == 32)
				{
					image(pic32, 25 + 110 * j, 160 + 110 * i);
				}
				else if (gamemap[i][j] == 64)
				{
					image(pic64, 25 + 110 * j, 160 + 110 * i);
				}
				else if (gamemap[i][j] == 128)
				{
					image(pic128, 25 + 110 * j, 160 + 110 * i);
				}
				else if (gamemap[i][j] == 256)
				{
					image(pic256, 25 + 110 * j, 160 + 110 * i);
				}
				else if (gamemap[i][j] == 512)
				{
					image(pic512, 25 + 110 * j, 160 + 110 * i);
				}
				else if (gamemap[i][j] == 1024)
				{
					image(pic1024, 25 + 110 * j, 160 + 110 * i);
				}
				else if (gamemap[i][j] == 2048)
				{
					image(pic2048, 25 + 110 * j, 160 + 110 * i);
				}
			}
		}
	}
	playstate = false;

	return 0;
}

// ��ʼ��Ϸ
void startGame()
{
	initstate = true;
	//playstate = true;
}

// ���¿�ʼ��Ϸ
void restartGame()
{
	initstate = false; // ������ʼ��
	gamestate = true;
	score = 0;
	steps = 0;
}

/* ������Ϸ�߼�
	statecheck();
	add();
	moveround();
*/
// ��Ϸ״̬���
bool statecheck()
{
	int i, j;
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 4; i++)
		{
			if (j < 3)
			{
				if (i < 3) // ����Ƿ��п�λ
				{
					if (gamemap[j][i] == gamemap[j + 1][i] || gamemap[j][i] == gamemap[j][i + 1] || gamemap[j][i] == 0)
					{
						gamestate = true;
						break;
					}
					else
					{
						gamestate = false;
					}
				}
			}
			else
			{
				if (i < 3)
				{
					if (gamemap[j][i] == gamemap[j][i + 1] || gamemap[j][i] == 0 || gamemap[j][i + 1] == 0)
					{
						gamestate = true;
						break;
					}
					else
					{
						gamestate = false;
					}
				}
			}
		}
		if (gamestate == true)
		{
			break;
		}
	}

	return gamestate;
}

// �������
int add(int *p)
{
	int i = 0, b;
	while (i < 3)
	{
		if (*(p + i) != 0)
		{
			for (b = i + 1; b < 4; b++)
			{
				if (*(p + b) != 0)
				{
					if (*(p + i) == *(p + b))
					{
						score = score + (*(p + i)) + (*(p + b));
						*(p + i) = *(p + i) + *(p + b);
						if (*(p + i) == 2048)
						{
							gamestate = true;
						}
						*(p + b) = 0;
						i = b + i;
						break;
					}
					else
					{
						i = b;
						break;
					}
				}
			}
			if (b == 4)
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	return score;
}

// �ƶ�����
int moveround(int direction)
{
	/* direction Ϊ����ֵ
	1: up ����
	2: down ����
	3: left ����
	4�� right ����
	*/
	int i, j, g, e, b[4];
	if (direction == 1 || direction == 2)
	{
		for (j = 0; j < 4; j++)
		{
			for (i = 0; i < 4; i++)
			{
				b[i] = gamemap[i][j]; // ����ͼ�д洢����ʱ����
				gamemap[i][j] = 0;
			}
			add(b);				// ���ΰ������
			if (direction == 1) // ���и��µ�ͼ
			{
				e = 0;
				for (g = 0; g < 4; g++)
				{
					if (b[g] != 0)
					{
						gamemap[e][j] = b[g];
						e++;
					}
				}
			}
			else if (direction == 2)
			{
				e = 3;
				for (g = 3; g >= 0; g--)
				{
					if (b[g] != 0)
					{
						gamemap[e][j] = b[g];
						e--;
					}
				}
			}
		}
		steps++;
	}
	else if (direction == 3 || direction == 4)
	{
		for (j = 0; j < 4; j++)
		{
			for (i = 0; i < 4; i++)
			{
				b[i] = gamemap[j][i];
				gamemap[j][i] = 0;
			}
			add(b);
			if (direction == 3)
			{
				e = 0;
				for (g = 0; g < 4; g++)
				{
					if (b[g] != 0)
					{
						gamemap[j][e] = b[g];
						e++;
					}
				}
			}
			else if (direction == 4)
			{
				e = 3;
				for (g = 3; g >= 0; g--)
				{
					if (b[g] != 0)
					{
						gamemap[j][e] = b[g];
						e--;
					}
				}
			}
		}
		steps++;
	}
}

// ��ʼ��
void setup()
{
	// ���ڳ�ʼ��
	size(480, 600);
	title("2048");
	bgimage("image/My2048.jpg");

	// ��Ϸ״̬��ʼ��
	initstate = false;
	playstate = false;
	gamestate = true;

	score = 0;
	steps = 0;
	bestscore = 0;

	// ����ͼƬ
	loadpic();

	// ��ʼ����ͼ
	All0init();
}

// �����ͼ
void draw(float stateTime)
{
	// ��ʼ����ť
	if (buttonstate == false)
	{
		image(NEWGAME, 256, 18);
	}
	else
	{
		image(NEWGAMEdown, 256, 18);
	}

	if (initstate == false)
	{
		All0init();
		initstate = true;
	}

	if (initstate == true)
	{
		// ���µ�ͼ
		addpic();

		// ���·���
		scoreUpdate();
		bestscoreRecord();

		// ��Ϸ״̬���
		statecheck();
	}

	if (gamestate == false && initstate == true)
	{
		text("���ϧ(�s��t)", 356, 100, 0, 0, 0);
		playstate = false;
	}
}

// ����¼�����
void mousePress()
{
	if (inbound(mouseX, mouseY, 256, 18, 201, 52))
	{
		buttonstate = true;
		restartGame();
	}
}
void mouseMove()
{
}
void mouseRelease()
{
	buttonstate = false;
}

// �����¼�������
void keyDown()
{
	if (playstate == false && gamestate == true)
	{
		// ��Ϸ״̬���
		if (key == KEY_UP || key == KEY_W || key == KEY_RIGHT || key == KEY_D || key == KEY_DOWN || key == KEY_S || key == KEY_LEFT || key == KEY_A)
		{
			playstate = true;
			appear();

			// �������
			if (key == KEY_UP || key == KEY_W)
			{
				moveround(1);
			}
			else if (key == KEY_RIGHT || key == KEY_D)
			{
				moveround(4);
			}
			else if (key == KEY_DOWN || key == KEY_S)
			{
				moveround(2);
			}
			else if (key == KEY_LEFT || key == KEY_A)
			{
				moveround(3);
			}
		}
	}
}
void keyUp()
{
	playstate = false;
}

// �������ʱ������Ϸ��Դ
void close()
{
	unloadimage(pic0);
	unloadimage(pic2);
	unloadimage(pic4);
	unloadimage(pic8);
	unloadimage(pic16);
	unloadimage(pic32);
	unloadimage(pic64);
	unloadimage(pic128);
	unloadimage(pic256);
	unloadimage(pic512);
	unloadimage(pic1024);
	unloadimage(pic2048);
	unloadimage(UISurface);
	unloadimage(NEWGAME);
	unloadimage(NEWGAMEdown);
}
