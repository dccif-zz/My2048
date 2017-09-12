#include <time.h>
#include "sdl2game.h"
#include <stdbool.h>
#include <stdlib.h>

// 图片资源
Image *UISurface; // 界面

// 加载按钮
Image *NEWGAME;
Image *NEWGAMEdown;
Image *but2x2;
Image *but2x2down;
Image *but3x3;
Image *but3x3down;
Image *but4x4;
Image *but4x4down;

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

//游戏配置
int gamemapsize;
int gamemap[4][4];
int score, steps, gameover, gamew;
int bestscore[3] = {0, 0, 0};
char score_String[10];
char best_String[10];
char *steps_String[10];

//系统状态
int buttondown;

bool initstate = false; // 初始化状态

bool playstate = false; // 是否在游戏状态

bool buttonstate = false; // 按钮状态

bool newbuttonstate = false; // 开始新游戏状态

bool gamestate = false; // 输赢状态  false 输  true 赢
						// 开始游戏后为 true

//界面清空初始化函数
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

//加载图片
int loadpic()
{

	UISurface = loadimage("image/My2048.jpg");

	// 加载按钮
	NEWGAME = loadimage("image/newgame.png");
	NEWGAMEdown = loadimage("image/newgamedown.png");

	but2x2 = loadimage("image/2x2.png");
	but2x2down = loadimage("image/2x2down.png");
	but3x3 = loadimage("image/3x3.png");
	but3x3down = loadimage("image/3x3down.png");
	but4x4 = loadimage("image/4x4.png");
	but4x4down = loadimage("image/4x4down.png");

	// 加载地图图片
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

// 初始化按钮
int buttoninit()
{
	image(NEWGAME, 256, 18);
	image(but2x2, 263, 100);
	image(but3x3, 263 + 65, 100);
	image(but4x4, 263 + 65 * 2, 100);

	// 点击状态
	if (buttonstate == true)
	{
<<<<<<< HEAD
		if (newbuttonstate == true)
=======
		if (buttondown == 0)
>>>>>>> master
		{
			image(NEWGAMEdown, 256, 18);
		}
		else if (buttondown == 1)
		{
			image(but2x2down, 263, 100);
		}
		else if (buttondown == 2)
		{
			image(but3x3down, 263 + 65, 100);
		}
		else if (buttondown == 3)
		{
			image(but4x4down, 263 + 65 * 2, 100);
		}
	}

	return 0;
}

// 提示语句
void tips()
{
	if (inbound(mouseX, mouseY, 264, 100, 55, 55))
	{
		text("这么丧心病狂吗？", 356, 100, 0, 0, 0);
	}
	if (inbound(mouseX, mouseY, 264 + 65, 100, 55, 55))
	{
		text("稍稍一些难", 356, 100, 0, 0, 0);
	}
	if (inbound(mouseX, mouseY, 264 + 65 * 2, 100, 55, 55))
	{
		text("还是换回来吧", 356, 100, 0, 0, 0);
	}
}

// 随机生成 2 或 4 函数
int appear()
{
	int i, j, ran, t[16], x = 0, a, b;
	srand((int)time(0));			  //随机种子初始化
	for (j = 0; j < gamemapsize; j++) //将空白的区域的坐标保存到中间数组t中
	{
		for (i = 0; i < gamemapsize; i++)
		{
			if (gamemap[j][i] == 0)
			{
				t[x] = j * 10 + i;
				x++;
			}
		}
	}
	if (x == 1) //在t中随机取一个坐标
	{
		ran = x - 1;
	}
	else
	{
		ran = rand() % (x - 1);
	}
	a = t[ran] / 10; //取出这个数值的十位数
	b = t[ran] % 10; //取出这个数值的个位数
	srand((int)time(0));
	if ((rand() % 9) > 2) //在此空白区域随机赋值2或4
	{
		gamemap[a][b] = 2;
	}
	else
	{
		gamemap[a][b] = 4;
	}
	return 0;
}

// 地图查看与调试函数(DEBUG用)
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

// 界面数据更新
int scoreUpdate()
{
	itoa(score, score_String, 10);
	//itoa(steps, steps_String, 10);
	textsize(24);
	text(score_String, 68, 134, 0, 0, 0);
	//text(steps_String, 150, 130, 0, 0, 0);
	return 0;
}

// 最高分记录
int bestscoreRecord()
{
<<<<<<< HEAD
	if (buttondown == 3 || buttondown == -1)
=======
	if (buttondown == 3 || buttondown == 0)
>>>>>>> master
	{
		itoa(bestscore[0], best_String, 10);
		if (score > bestscore[0])
		{
			bestscore[0] = score;
		}
	}
<<<<<<< HEAD
	else if (buttondown == 1)
=======
	if (buttondown == 1)
>>>>>>> master
	{
		itoa(bestscore[1], best_String, 10);
		if (score > bestscore[1])
		{
			bestscore[1] = score;
		}
	}
<<<<<<< HEAD
	else if (buttondown == 2)
=======
	if (buttondown == 2)
>>>>>>> master
	{
		itoa(bestscore[2], best_String, 10);
		if (score > bestscore[2])
		{
			bestscore[2] = score;
		}
	}
	text(best_String, 168, 134, 0, 0, 0);
<<<<<<< HEAD

=======
	
>>>>>>> master
	return 0;
}

// 更新地图
int addpic()
{
	//遍历地图表添加图片
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

// 开始游戏
void startGame()
{
	initstate = true;
	//playstate = true;
}

// 改变游戏地图大小
void changeMap()
{
	if (buttondown == 1)
	{
		gamemapsize = 2;
	}
	else if (buttondown == 2)
	{
		gamemapsize = 3;
	}
	else if (buttondown == 3)
	{
		gamemapsize = 4;
	}
}

// 重新开始游戏
void restartGame()
{
	initstate = false; // 启动初始化
	gamestate = true;
	score = 0;
	steps = 0;
}

/* 核心游戏逻辑
	statecheck();
	add();
	moveround();
*/
// 游戏状态检查
bool statecheck()
{
	int i, j;
	for (j = 0; j < gamemapsize; j++)
	{
		for (i = 0; i < gamemapsize; i++)
		{
			if (j < gamemapsize - 1)
			{
				if (i < gamemapsize - 1) // 检测是否还有空位
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
				if (i < gamemapsize - 1)
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

// 数字相加
int add(int *p)
{
	int i = 0, b;
	while (i < gamemapsize - 1)
	{
		if (*(p + i) != 0)
		{
			for (b = i + 1; b < gamemapsize; b++)
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
			if (b == gamemapsize)
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

// 移动函数
int moveround(int direction)
{
	/* direction 为方向值
	1: up 向上
	2: down 向下
	3: left 向左
	4： right 向右
	*/
	int i, j, g, e, b[4];
	if (direction == 1 || direction == 2)
	{
		for (j = 0; j < gamemapsize; j++)
		{
			for (i = 0; i < gamemapsize; i++)
			{
				b[i] = gamemap[i][j]; // 将地图列存储到临时数组
				gamemap[i][j] = 0;
			}
			add(b);				// 依次按列相加
			if (direction == 1) // 按列更新地图
			{
				e = 0;
				for (g = 0; g < gamemapsize; g++)
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
				e = gamemapsize - 1;
				for (g = gamemapsize - 1; g >= 0; g--)
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
		for (j = 0; j < gamemapsize; j++)
		{
			for (i = 0; i < gamemapsize; i++)
			{
				b[i] = gamemap[j][i];
				gamemap[j][i] = 0;
			}
			add(b);
			if (direction == 3)
			{
				e = 0;
				for (g = 0; g < gamemapsize; g++)
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
				e = gamemapsize - 1;
				for (g = gamemapsize - 1; g >= 0; g--)
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

// 初始化
void setup()
{
	// 窗口初始化
	size(480, 600);
	title("2048");
	bgimage("image/My2048.jpg");

	// 游戏状态初始化
	initstate = false;
	playstate = false;
	gamestate = true;

<<<<<<< HEAD
	buttondown = -1;
	//buttonbefore = 0;
=======
	buttondown = 0;
>>>>>>> master
	gamemapsize = 4;
	score = 0;
	steps = 0;

	// 加载图片
	loadpic();

	// 初始化地图
	All0init();
}

// 界面绘图
void draw(float stateTime)
{
	tips();

	// 初始化按钮
	buttoninit();

	if (initstate == false)
	{
		All0init();
		initstate = true;
	}

	if (initstate == true)
	{
		// 更新地图
		addpic();

		// 更新分数
		scoreUpdate();
		bestscoreRecord();

		// 游戏状态检测
		statecheck();
	}

	if (gamestate == false && initstate == true)
	{
		text("真可惜(╯︵╰)", 356, 100, 0, 0, 0);
		playstate = false;
	}
}

// 鼠标事件处理
void mousePress()
{
	if (inbound(mouseX, mouseY, 256, 18, 201, 52))
	{
		buttonstate = true;
<<<<<<< HEAD
		//buttonbefore = buttondown;
		//buttondown = 0;
		newbuttonstate = true;
=======
		buttondown = 0;
>>>>>>> master
		restartGame();
	}

	if (inbound(mouseX, mouseY, 263, 100, 55, 55))
	{
		buttonstate = true;
		buttondown = 1;
		changeMap();
		restartGame();
	}

	if (inbound(mouseX, mouseY, 263 + 65, 100, 55, 55))
	{
		buttonstate = true;
		buttondown = 2;
		changeMap();
		restartGame();
	}

	if (inbound(mouseX, mouseY, 263 + 65 * 2, 100, 55, 55))
	{
		buttonstate = true;
		buttondown = 3;
		changeMap();
		restartGame();
	}
}
void mouseMove()
{
}
void mouseRelease()
{
	buttonstate = false;
	newbuttonstate = false;
}

// 键盘事件处理函数
void keyDown()
{
	if (playstate == false && gamestate == true)
	{
		// 游戏状态监测
		if (key == KEY_UP || key == KEY_W || key == KEY_RIGHT || key == KEY_D || key == KEY_DOWN || key == KEY_S || key == KEY_LEFT || key == KEY_A)
		{
			playstate = true;
			appear();

			// 按键监测
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

// 程序结束时回收游戏资源
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
	unloadimage(but2x2);
	unloadimage(but2x2down);
	unloadimage(but3x3);
	unloadimage(but3x3down);
	unloadimage(but4x4);
	unloadimage(but4x4down);
}
