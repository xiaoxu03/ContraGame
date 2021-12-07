// ContraGame.cpp : 定义应用程序的入口点。
//

#include "ContraGame.h"

using namespace std;


#pragma region 全局变量

#define MAX_LOADSTRING			100		

// 全局变量: 
HINSTANCE hInst; // 当前窗体实例
WCHAR szTitle[MAX_LOADSTRING]; // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING]; // 主窗口类名


HBITMAP bmp_UIKey;
HBITMAP bmp_Title;				//标题界面图像资源
HBITMAP bmp_StartButton;		//开始按钮图像资源
HBITMAP bmp_HelpButton;			//帮助按钮资源
HBITMAP bmp_BackButton;			//返回按钮资源
HBITMAP bmp_Unit_Red;			//红方主角图像资源
HBITMAP bmp_Unit_Blue;			//蓝方主角图像资源
HBITMAP bmp_HelpMenu;			//帮助界面图像资源
HBITMAP bmp_ResumeButton;		//继续游戏按钮资源
HBITMAP bmp_MenuButton;			//回到主菜单按钮资源
HBITMAP bmp_Stage1;				//第一关图像资源
HBITMAP bmp_Hero;				//主角图像资源
HBITMAP bmp_Bouns;				//问号砖资源
HBITMAP bmp_Box;				//箱子资源
HBITMAP bmp_Coin;				//金币资源
HBITMAP bmp_Door;				//门资源
HBITMAP bmp_Fish;				//鱼资源
HBITMAP bmp_Flag;				//旗子资源
HBITMAP bmp_Key;				//钥匙资源
HBITMAP bmp_Lazer;				//激光资源
HBITMAP bmp_Spider;				//蜘蛛资源
HBITMAP bmp_Switch;				//开关资源
HBITMAP bmp_Heart;				//心资源
HBITMAP bmp_Key_False;			//钥匙未获得资源
HBITMAP bmp_Key_True;			//钥匙已获得资源
HBITMAP bmp_Numbers;			//数字资源
HBITMAP bmp_X;					//x符号资源
HBITMAP bmp_RestartButton;		//重新开始按钮资源
HBITMAP bmp_GameOver;			//游戏是否结束
HBITMAP bmp_Attack;				//攻击资源
HBITMAP bmp_JumpFruit;			//跳跃果实
int nowStage = STAGE_STARTMENU;	//定义初始化当前场景编号
Stage* currentStage = NULL;		//当前场景状态
vector<Unit*> units;			//单位
vector<Button*> buttons;		//按钮
vector<Plat*> plats;			//平台
vector<Health*> uis;			//血量
vector<Unit*> mobs;				//怪物
vector<Bonus*> bonus;			//奖励物品
vector<Door*> doors;			//门
vector<Bonus_Block*> bonus_blocks;
int mouseX = 0;
int mouseY = 0;
bool mouseDown = false;
bool keyUpDown = false;
bool keyLeftDown = false;
bool keyRightDown = false;
bool keyEscDown = false;
bool keyZDown = false;
bool keyXDown = false;
bool keySpaceDown = false;
bool GameOver = false;
bool Dead = false;
bool Attacking = false;
bool Attacked = false;
bool DoubleJumped = false;
//帧
int FRAMES_HOLD[] = { 0 };
int FRAMES_HOLD_COUNT = 1;
int FRAMES_WALK[] = { 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10 };
int FRAMES_WALK_COUNT = 16;
int FRAMES_JUMP[] = { 7 };
int FRAMES_JUMP_COUNT = 1;
int FRAMES_CLIMB[] = { 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6 };
int FRAMES_CLIMB_COUNT = 16;
int FRAMES_BOUNS_FULL[] = { 0 };
int FRAMES_BOUNS_FULL_COUNT = 1;
int FRAMES_FISH_SIWM[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 };
int FRAMES_FISH_SWIM_COUNT = 16;
int FRAMES_FISH_DEAD[] = { 2 };
int FRAMES_FISH_DEAD_COUNT = 1;
int FRAMES_FLAG_UNTOUCHED[] = { 0, 0, 0, 0, 1, 1, 1, 1 };
int FRAMES_FLAG_UNTOUCHED_COUNT = 8;
int FRAMES_LAZER[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int FRAMES_LAZER_COUNT = 24;
int FRAMES_SPIDER[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2 };
int FRAMES_SPIDER_COUNT = 24;
int FRAMES_SWITCH_ON[] = { 1 };
int FRAMES_SWITCH_ON_COUNT = 1;
int FRAMES_SWITCH_OFF[] = { 1 };
int FRAMES_SWITCH_OFF_COUNT = 1;
int FRAMES_HEART[] = { 0, 1, 2 };
int FRAMES_ATTACK[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2 , 2, 2, 2, 2, 2, 2, 2, 2 , 2, 2, 2, 2 };
int FRAMES_ATTACK_COUNT = 48;
//场景渲染起点
int FRAMES_START_X = 0;
int attack_frame_id = 0;
// TODO: 在此添加其它全局变量


double const PI = acos(double(-1)); //定义PI的大小


#pragma endregion


#pragma region Win32程序框架



// 此代码模块中包含的函数的前向声明: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
//TODO
//UNDERSTAND



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// 初始化全局字符串
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_CONTRAGAME, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CONTRAGAME));

	MSG msg;

	// 主消息循环: 
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_CONTRAGAME);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 将实例句柄存储在全局变量中

	HWND hWnd = CreateWindow(szWindowClass, szTitle,
		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // 设置窗口样式，不可改变大小，不可最大化,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WINDOW_WIDTH,
		WINDOW_HEIGHT + WINDOW_TITLEBARHEIGHT,
		nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		// 初始化游戏窗体
		InitGame(hWnd, wParam, lParam);
		break;
	case WM_KEYDOWN:
		// 键盘按下事件
		KeyDown(hWnd, wParam, lParam);
		break;
	case WM_KEYUP:
		// 键盘松开事件
		KeyUp(hWnd, wParam, lParam);
		break;
	case WM_MOUSEMOVE:
		// 鼠标移动事件
		MouseMove(hWnd, wParam, lParam);
		break;
	case WM_LBUTTONDOWN:
		// 鼠标左键按下事件
		LButtonDown(hWnd, wParam, lParam);
		break;
	case WM_LBUTTONUP:
		// 鼠标左键松开事件
		LButtonUp(hWnd, wParam, lParam);
		break;
	case WM_TIMER:
		// 定时器事件
		if (currentStage != NULL && currentStage->timerOn) TimerUpdate(hWnd, wParam, lParam);
		break;
	case WM_PAINT:
		// 绘图
		Paint(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


#pragma endregion


#pragma region 事件处理函数

// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//加载人物图像资源
	bmp_Spider = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_SPIDER));
	bmp_Fish = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_FISH));
	bmp_Title = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STAGE_TITLE));
	bmp_Unit_Red = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_RED));
	bmp_Hero = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_HERO));
	bmp_Attack = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_ATTACK));
	//加载场景图像资源
	bmp_Title = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STAGE_TITLE));
	bmp_HelpMenu = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STAGE_HELP));
	bmp_Stage1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STAGE_1));
	bmp_Bouns = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BONUS));
	bmp_Box = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BOX));
	bmp_Coin = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_COIN));
	bmp_Door = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_DOOR));
	bmp_Flag = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_FLAG));
	bmp_Key = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_KEY));
	bmp_Lazer = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_LAZER));
	bmp_Switch = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_SWITCH));
	bmp_JumpFruit = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_JUMP));
	//加载UI图像资源
	bmp_Numbers = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_NUMBERS));
	bmp_Heart = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_HEART));
	bmp_UIKey = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_UIKEY));
	bmp_X = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_X));
	bmp_GameOver = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_OVER));
	//加载按钮图像资源
	bmp_RestartButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_RESTART));
	bmp_StartButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_START));
	bmp_HelpButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_HELP));
	bmp_BackButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BACK));
	bmp_ResumeButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_RESUME));
	bmp_MenuButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_MENU));
	//添加按钮
	Button* startButton = CreateButton(BUTTON_STARTGAME, bmp_StartButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT,
		((WINDOW_WIDTH - BUTTON_STARTGAME_WIDTH) / 2), ((WINDOW_WIDTH - BUTTON_STARTGAME_HEIGHT) / 2 -100));
	Button* helpButton = CreateButton(BUTTON_HELP, bmp_HelpButton, BUTTON_HELP_WIDTH, BUTTON_HELP_HEIGHT,
		((WINDOW_WIDTH - BUTTON_HELP_WIDTH) / 2), ((WINDOW_WIDTH - BUTTON_HELP_HEIGHT) / 2));
	Button* backButton = CreateButton(BUTTON_BACK, bmp_BackButton, BUTTON_BACK_WIDTH, BUTTON_BACK_HEIGHT,
		((WINDOW_WIDTH - BUTTON_BACK_WIDTH) / 2), ((WINDOW_WIDTH - BUTTON_BACK_HEIGHT) / 2 + 100));
	Button* menuButton = CreateButton(BUTTON_MENU, bmp_MenuButton, BUTTON_MENU_WIDTH, BUTTON_MENU_HEIGHT,
		((WINDOW_WIDTH - BUTTON_MENU_WIDTH) / 2), ((WINDOW_WIDTH - BUTTON_MENU_HEIGHT) / 2 - 100));
	Button* resumeButton = CreateButton(BUTTON_RESUME, bmp_ResumeButton, BUTTON_RESUME_WIDTH, BUTTON_RESUME_HEIGHT,
		((WINDOW_WIDTH - BUTTON_RESUME_WIDTH) / 2), ((WINDOW_WIDTH - BUTTON_RESUME_HEIGHT) / 2 - 200));
	Button* restartButton = CreateButton(BUTTON_RESTART, bmp_RestartButton, BUTTON_RESTART_WIDTH, BUTTON_RESTART_HEIGHT,
		((WINDOW_WIDTH - BUTTON_RESTART_WIDTH) / 2), ((WINDOW_WIDTH - BUTTON_RESTART_HEIGHT) / 2 ));
	//返回按钮地址
	buttons.push_back(startButton);
	buttons.push_back(helpButton);
	buttons.push_back(backButton);
	buttons.push_back(menuButton);
	buttons.push_back(resumeButton);
	buttons.push_back(restartButton);
	//初始化背景
	//bmp_Title = InitBackGround(hWnd, bmp_Title);


	//初始化开始场景
	InitStage(hWnd, STAGE_STARTMENU);

	//初始化主计时器
	SetTimer(hWnd, TIMER_GAMETIMER, TIMER_GAMETIMER_ELAPSE, NULL);
}

// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_ESCAPE:
		if (nowStage == STAGE_STARTMENU)
			ExitProcess(0);
		else if (nowStage == STAGE_HELP)
		InitStage(hWnd, STAGE_STARTMENU);
		else
		{
			for (int i = 0; i < buttons.size(); i++)
			{
				Button* button = buttons[i];
				if (button->buttonID == BUTTON_RESUME)
				{
					button->visible = true - button->visible;
					currentStage->timerOn = true;
				}
				else if (button->buttonID == BUTTON_MENU)
				{
					button->visible = true - button->visible;
					currentStage->timerOn = true;
				}
				else if (button->buttonID == BUTTON_RESTART)
				{
					button->visible = true - button->visible;
					currentStage->timerOn = true;
				}
				else
				{
					button->visible = false;
				}
			}
		}
		break;
	case VK_UP:
		keyUpDown = true;
		break;
	case VK_LEFT:
		keyLeftDown = true;
		break;
	case VK_RIGHT:
		keyRightDown = true;
		break;
	case VK_Z:
		keyZDown = true;
		break;
	case VK_X:
		keyXDown = true;
		break;
	case VK_SPACE:
		keySpaceDown = true;
		break;
	default:
		break;
	}
}

// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_ESCAPE:
		keyEscDown = false;
		break;
	case VK_UP:
		keyUpDown = false;
		break;
	case VK_LEFT:
		keyLeftDown = false;
		break;
	case VK_RIGHT:
		keyRightDown = false;
		break;
	case VK_Z:
		keyZDown = false;
		break;
	case VK_X:
		keyXDown = false;
		break;
	case VK_SPACE:
		keySpaceDown = false;
		break;
	default:
		break;
	}
}

// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
}

// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = true;

	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			if (button->x <= mouseX
				&& button->x + button->width >= mouseX
				&& button->y <= mouseY
				&& button->y + button->height >= mouseY)
			{
				switch (button->buttonID) {
					//条件判断进入哪个场景
				case BUTTON_STARTGAME:
				{
					InitStage(hWnd, STAGE_1);
					break;
				}
				case BUTTON_HELP:
				{
					InitStage(hWnd, STAGE_HELP);
					break;
				}
				case BUTTON_BACK:
				{
					InitStage(hWnd, STAGE_STARTMENU);
					break;
				}
				case BUTTON_RESUME:
				{
					for (int i = 0; i < buttons.size(); i++)
					{
						Button* button = buttons[i];
						button->visible = false;
					}
					currentStage->timerOn = true;
					break;
				}
				case BUTTON_MENU:
				{
					units.clear();
					plats.clear();
					mobs.clear();
					uis.clear();
					bonus.clear();
					bonus_blocks.clear();
					doors.clear();
					FRAMES_START_X = 0;
					InitStage(hWnd, STAGE_STARTMENU);
					break;
				}
				case BUTTON_RESTART:
				{
					plats.clear();
					units.clear();
					mobs.clear();
					uis.clear();
					bonus.clear();
					bonus_blocks.clear();
					doors.clear();
					FRAMES_START_X = 0;
					InitStage(hWnd, STAGE_1);
				}
				default: {
					break;
				}
				
				}
			}
		}
	}

}

// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = false;
}

// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	UpdateUnits(hWnd);

	//刷新显示
	InvalidateRect(hWnd, NULL, FALSE);
}


#pragma endregion


#pragma region 其它游戏状态处理函数



//TODO: 添加游戏需要的更多函数

// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y)
{
	Button* button = new Button();
	button->buttonID = buttonID;
	button->img = img;
	button->width = width;
	button->height = height;
	button->x = x;
	button->y = y;
	button->visible = false;
	return button;
}
Door* CreateDoor(HBITMAP img, int x, int y) {
	Door* door = new Door();
	door->img = img;
	door->x = x;
	door->y = y;
	door->frame_column = 1;
	return door;
}
Bonus* CreateBonus(HBITMAP img, int x, int y, int type, bool display) {
	Bonus* bonus = new Bonus();
	bonus->img = img;
	bonus->x = x;
	bonus->y = y;
	bonus->type = type;
	bonus->display = display;
	return bonus;
}
Bonus_Block* CreateBlock(HBITMAP img,int x,int y) {
	Bonus_Block* block = new Bonus_Block();
	block->x = x;
	block->y = y;
	block->img = img;
	block->frame_id = 0;
	return block;
}
// 添加实体函数
Unit* CreateUnit(int side, int type, int x, int y, int health, HBITMAP texture)
{
	Unit* unit = new Unit();
	unit->side = side;
	unit->img = texture;

	unit->type = type;
	unit->status = UNIT_STATUS_HOLD;


	unit->frame_row = unit->direction;
	unit->frame_column = 0;

	unit->frame_sequence = FRAMES_HOLD;
	unit->frame_count = FRAMES_HOLD_COUNT;
	unit->frame_id = 0;

	unit->x = x;
	unit->y = y;
	unit->vx = 0;
	unit->vy = 0;
	unit->health = health;
	unit->skill_type = SKILL_NONE;
	return unit;
}
Unit* CreateSpider(int side, int type, int x, int y, int health, HBITMAP texture)
{
	Unit* unit = new Unit();
	unit->side = side;
	unit->img = texture;

	unit->type = type;
	unit->status = UNIT_STATUS_HOLD;


	unit->frame_row = 0;
	unit->frame_column = 0;

	unit->frame_sequence = FRAMES_SPIDER;
	unit->frame_count = FRAMES_SPIDER_COUNT;
	unit->frame_id = 0;

	unit->x = x;
	unit->y = y;
	unit->vx = 0;
	unit->vy = 0;
	unit->health = health;
	unit->display = true;
	unit->death_timer = 0;
	return unit;
}

Plat* CreatePlat(int left, int right, int up, int down,bool is_half) {
	Plat* plat = new Plat();
	plat->left = left;
	plat->right = right;
	plat->up = up;
	plat->down = down;
	plat->is_half = is_half;
	return plat;
}
Health* CreateHealth(HBITMAP img, int x, int y) {
	Health* health = new Health();
	health->x = x;
	health->y = y;
	health->image = img;
	health->frame_column = 0;
	health->frame_row = 0;
	health->frame_id = 0;
	health->frame_sequence = FRAMES_HEART;
	return health;
}
// 初始化游戏场景函数
void InitStage(HWND hWnd, int stageID)
{
	// 初始化场景实例
	if (currentStage != NULL) delete currentStage;
	currentStage = new Stage();
	currentStage->stageID = stageID;
	nowStage = stageID;

	if (stageID == STAGE_STARTMENU) {
		currentStage->bg = bmp_Title;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		//显示开始界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_STARTGAME)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_HELP)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


	}
	else if (stageID == STAGE_HELP)
	{
		//TODO
		currentStage->bg = bmp_HelpMenu;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		//显示帮助界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_BACK)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_1)
	{
		currentStage->bg = bmp_Stage1;
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = true;

		//显示游戏界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (false) 
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


		// 按场景初始化单位及矩形平台
		switch (stageID) {
		case STAGE_1:
			units.push_back(CreateUnit(SIDE_HERO, UNIT_TYPE_PLAYER, 200, GROUND_HEIGHT, 6, bmp_Hero));
			mobs.push_back(CreateSpider(SIDE_MOB, UNIT_TYPE_SPIDER, 1100, GROUND_HEIGHT, 2, bmp_Spider));
			mobs.push_back(CreateSpider(SIDE_MOB, UNIT_TYPE_SPIDER, 2500, GROUND_HEIGHT, 2, bmp_Spider));
			plats.push_back(CreatePlat(1952, 2140, 378, 441, false));
			plats.push_back(CreatePlat(2267, 2582, 252, 315, false));
			plats.push_back(CreatePlat(4095, 4283, 252, 285, true));
			plats.push_back(CreatePlat(4095, 4283, 504, 537, true));
			plats.push_back(CreatePlat(4220, 4360, 378, 410, true));
			plats.push_back(CreatePlat(4420, 4472, 0, 490, false));
			uis.push_back(CreateHealth(bmp_Heart, 0, 0));
			uis.push_back(CreateHealth(bmp_Heart, 63, 0));
			uis.push_back(CreateHealth(bmp_Heart, 126, 0));
			uis.push_back(CreateHealth(bmp_UIKey, 1180, 0));
			bonus_blocks.push_back(CreateBlock(bmp_Bouns, 2016, 378));
			bonus.push_back(CreateBonus(bmp_JumpFruit, 2016, 315, SKILL_JUMP, false));
			bonus.push_back(CreateBonus(bmp_Key, 2400, 188, SKILL_NONE,true));
			doors.push_back(CreateDoor(bmp_Door, 3224 - 189, 441));
			break;
		default:
			break;
		}
	}

	//刷新显示
	InvalidateRect(hWnd, NULL, FALSE);
}

// 刷新单位状态函数
void UpdateUnits(HWND hWnd)
{
	for (int i = 0; i < units.size(); i++) {
		Unit* unit = units[i];
		//根据单位类型选择行为函数
		if(unit != nullptr){
		switch (unit->type) {
		case UNIT_TYPE_PLAYER:
			UnitBehaviour_hero(unit);
			if (units[0]->y > 1260 || Dead) {
				Dead = false;
				currentStage->timerOn = false;
				if (currentStage->stageID == STAGE_1)
				{
					currentStage->bg = bmp_Stage1;
					currentStage->timeCountDown = 10000;
					currentStage->timerOn = false;
					GameOver = true;
					//显示游戏界面的按钮
					for (int i = 0; i < buttons.size(); i++)
					{
						Button* button = buttons[i];
						if (button->buttonID == BUTTON_RESTART)
						{
							button->visible = true;
						}
						else if (button->buttonID == BUTTON_MENU)
						{
							button->visible = true;
						}
						else
						{
							button->visible = false;
						}
					}
				}
			}
			break;
		}
		}
	}
	for (int i = 0; i < mobs.size(); i++) {
		Unit* mob = mobs[i];
		//根据单位类型选择行为函数
		if (mob != nullptr) {
			switch (mob->type) {
			case UNIT_TYPE_FISH:
				break;
			case UNIT_TYPE_SPIDER:
				UnitBehaviour_mob(mob,units[0]);
				break;
			case UNIT_TYPE_SLIME:
				break;
			
		}
		}
	}
}
void Knock(Unit* unit) {
	for (int i = 0; i < bonus_blocks.size(); i++) {
		Bonus_Block* block = bonus_blocks[i];
		if( i == 0 && block->frame_id == 0 && unit->x >= block->x - 23 && unit->x <= block->x + 40 && unit->y - UNIT_SIZE_Y >= block->y + UNIT_SIZE_Y && unit->y - UNIT_SIZE_Y <= block->y + UNIT_SIZE_Y + 20 ) {
			block->frame_id = 1;
			bonus[0]->display = true;
		}
	}
}

//跟随视角判定函数
int Camera(Unit* unit) {
	//判断条件
	if (!((FRAMES_START_X <= 5 && unit->vx < 0) || (FRAMES_START_X >= 5035 && unit->vx > 0)) && (unit->x - FRAMES_START_X > 500 && unit->x - FRAMES_START_X < 1000)) {
		
		FRAMES_START_X += unit->vx;
	}
	return FRAMES_START_X;
}
//二段跳函数
void DoubleJump(Unit* unit) {
	if (unit->status == UNIT_STATUS_JUMP  && unit->skill_type == SKILL_JUMP && keySpaceDown && !DoubleJumped) {
		unit->vy += -8;
		DoubleJumped = true;
	}
}
//开门加血函数
void OpenDoor(Unit* unit) {
	if (unit->x >= doors[0]->x - 15 && keyUpDown && unit->x <= doors[0]->x + 45 && unit->y <= GROUND_HEIGHT && unit->y >= GROUND_HEIGHT - 100 && uis[3]->frame_column == 1) {
		doors[0]->frame_column = 0;
		uis[3]->frame_column = 0;
		unit->health = 6;
	}
}
//攻击函数
void Attack(Unit* unit) {
	if (keyXDown && !Attacking) {
		Attacking = true;
	}
	else if (!keyXDown ) {
		Attacking = false;
		attack_frame_id = 0;
		Attacked = false;
	}
	else if (attack_frame_id == FRAMES_ATTACK_COUNT) {
		Attacked = true;
		Attacking = false;
		attack_frame_id = 0;
	}
	else if (keyXDown && Attacking) {
		attack_frame_id++;
	}
	if (Attacking) {
			for (int i = 0; i < mobs.size(); i++) {
			Unit* mob = mobs[i];
			if ((mob->x - unit->x>= 0 && mob->x - unit->x < 80 && !unit->direction) || (mob->x - unit->x <= 0 && mob->x - unit->x > -80 && unit->direction) && unit->health > 0) {
				mob->health--;
				mob->x += (0.5 - unit->direction) * 120;
				Attacked = true;
			}
		}
	}
}
void Eat(Unit* unit) {
	if (bonus[0]->display && sqrt((unit->x - bonus[0]->x) * (unit->x - bonus[0]->x) + (unit->y - bonus[0]->y) * (unit->y - bonus[0]->y)) <= 40) {
		unit->skill_type = SKILL_JUMP;
		bonus[0]->display = false;
	}else if (bonus[1]->display && sqrt((unit->x - bonus[1]->x) * (unit->x - bonus[1]->x) + (unit->y - bonus[1]->y) * (unit->y - bonus[1]->y)) <= 40) {
		bonus[1]->display = false;
		uis[3]->frame_column = 1;
	}
}
//掉落函数
int fall(Unit* unit, int next_status) {
	if (unit->x >= PIT1_LEFT && unit->x <= PIT1_RIGHT) {
		unit->vy += 0.5;
	}
	else {
		for (int i = 0; i < plats.size(); i++) {
			if (unit->vy == 0 && unit->y == plats[i]->up && unit->x  >= plats[i]->left - UNIT_SIZE_X && unit->x  <= plats[i]->right &&!(unit->x + unit->vx > plats[i]->left  - UNIT_SIZE_X && unit->x + unit->vx < plats[i]->right)) {
				next_status = UNIT_STATUS_JUMP;
			}
		}
	}
	if (unit->y > GROUND_HEIGHT && (unit->x >= 1276 && unit->x <= 1438)) {
		if (unit->x + unit->vx >= 1438 && keyRightDown) {
			unit->x = 1438 ;
			unit->vx = 0;
		}
		else if (unit->x + unit->vx <= 1276 && keyLeftDown) {
			unit->x = 1276;
			unit->vx = 0;
		}
	}
	return next_status;
}
int fall_mob(Unit* unit, int next_status) {
	if (unit->x >= PIT1_LEFT && unit->x <= PIT1_RIGHT) {
		unit->vy += 0.5;
	}
	if (unit->y > GROUND_HEIGHT && (unit->x >= 1276 && unit->x <= 1438)) {
		if (unit->x + unit->vx >= 1438 && keyRightDown) {
			unit->x = 1438;
			unit->vx = 0;
		}
		else if (unit->x + unit->vx <= 1276 && keyLeftDown) {
			unit->x = 1276;
			unit->vx = 0;
		}
	}
	return next_status;
}
int Jump(Unit* unit) {
	int next_status = UNIT_STATUS_JUMP;
	//跳跃以及掉坑
	if (unit->y <= GROUND_HEIGHT && !keyZDown) unit->vy += 1;
	else if (unit->y <= GROUND_HEIGHT && keyZDown)	unit->vy += 0.3;
	else if (unit->y > GROUND_HEIGHT && !(unit->x >= PIT1_LEFT && unit->x <= PIT1_RIGHT - UNIT_SIZE_X)) {
		unit->vy = 0;
		unit->y = GROUND_HEIGHT;
		next_status = UNIT_STATUS_HOLD;
		DoubleJumped = false;
	}
	if (!keyRightDown && !keyLeftDown) {
		unit->vx = 0;
	}
	else if (keyRightDown && !keyLeftDown) {
		unit->frame_column = UNIT_DIRECT_RIGHT;
		unit->vx = 5;
	}
	else if (keyLeftDown && !keyRightDown) {
		unit->frame_column = UNIT_DIRECT_LEFT;
		unit->vx = -5;
	}
	for (int i = 0; i < plats.size(); i++) {
		//顶头函数
		if (!plats[i]->is_half && unit->y >= plats[i]->down + UNIT_SIZE_Y && unit->y + unit->vy - UNIT_SIZE_Y < plats[i]->down && unit->y + unit->vy + UNIT_SIZE_Y> plats[i]->up && unit->x + unit->vx >= plats[i]->left - UNIT_SIZE_X - 5 && unit->x + unit->vx <= plats[i]->right + 5) {
			unit->y = plats[i]->down + UNIT_SIZE_Y;
			unit->vy = -unit->vy;
		}
		//侧碰撞
		else if (unit->y >= plats[i]->up && unit->y - UNIT_SIZE_Y <= plats[i]->down) {
			if (unit->x >= plats[i]->right && unit->x + unit->vx < plats[i]->right) {
				unit->x = plats[i]->right;
				unit->vx = 0;
				keyLeftDown = false;
			}
			if (unit->x + UNIT_SIZE_X <= plats[i]->left && unit->x + unit->vx + UNIT_SIZE_X > plats[i]->left) {
				unit->x = plats[i]->left - UNIT_SIZE_X ;
				unit->vx = 0;
				keyRightDown = false;
			}
		}
		//顶面碰撞
		else if (unit->y < plats[i]->up && unit->y + unit->vy >= plats[i]->up && unit->x + unit->vx > plats[i]->left - UNIT_SIZE_X && unit->x + unit->vx < plats[i]->right ) {
			unit->vy = 0;
			unit->y = plats[i]->up;
			DoubleJumped = false;
			next_status = UNIT_STATUS_HOLD;
		}
	}
	return next_status;
}//跳跃函数


//爬梯子函数
void Climb(Unit* unit) {
	if (!keyUpDown || unit->y <= 180) {
		unit->frame_id--;
		unit->vy = 0;
	}
	if (keyUpDown && keyRightDown)
	{
		unit->vy = -1.4;
		unit->vx = 1.4;
	}
	else if (keyUpDown && keyRightDown)
	{
		unit->vy = -1.4;
		unit->vx = -1.4;
	}
	else if(keyUpDown && unit->y >= 180)
	{
		unit->vy = -2;
	}
	else if (keyRightDown)
	{
		unit->vx = 1;
	}
	
	else if (keyLeftDown)
	{
		unit->vx = -2;
	}
	else
	{
		unit->vx = 0;
		unit->vy = 0;
	}
}
//血量函数
void health_change(Unit* unit) {
	if (unit->health == 6) {
		uis[0]->frame_column = 0;
		uis[1]->frame_column = 0;
		uis[2]->frame_column = 0;
	}
	else if (unit->health == 5) {
		uis[0]->frame_column = 0;
		uis[1]->frame_column = 0;
		uis[2]->frame_column = 1;
	}
	else if (unit->health == 4) {
		uis[0]->frame_column = 0;
		uis[1]->frame_column = 0;
		uis[2]->frame_column = 2;
	}
	else if (unit->health == 3) {
		uis[0]->frame_column = 0;
		uis[1]->frame_column = 1;
		uis[2]->frame_column = 2;
	}
	else if (unit->health == 2) {
		uis[0]->frame_column = 0;
		uis[1]->frame_column = 2;
		uis[2]->frame_column = 2;
	}
	else if (unit->health == 1) {
		uis[0]->frame_column = 1;
		uis[1]->frame_column = 2;
		uis[2]->frame_column = 2;
	}
	else if (unit->health == 0) {
		uis[0]->frame_column = 2;
		uis[1]->frame_column = 2;
		uis[2]->frame_column = 2;
	}
}
void Hurt(Unit* unit) {
	for (int i = 0; i < mobs.size(); i++) {
		if (sqrt((units[0]->x - mobs[i]->x) * (units[0]->x - mobs[i]->x) + (units[0]->y - mobs[i]->y) * (units[0]->y - mobs[i]->y)) < 40 && mobs[i]->health > 0) {
			if (units[0]->x - mobs[i]->x >= 0) unit->x += 80;
			else unit->x -= 80;
			unit->health--;
		}
	}
	if (unit->health <= 0) Dead = true;
}
//玩家行为函数
void UnitBehaviour_hero(Unit* unit) {
	//判断当前状态, 以及判断是否需要状态变化
	
	int next_status = unit->status;
	switch (unit->status) {
	case UNIT_STATUS_HOLD:
		next_status = fall(unit,next_status);
		if (keyRightDown) {
			next_status = UNIT_STATUS_WALK;
			unit->direction = UNIT_DIRECT_RIGHT;
		}
		else if (keyLeftDown) {
			next_status = UNIT_STATUS_WALK;
			unit->direction = UNIT_DIRECT_LEFT;
		}
		else if (keyZDown && unit->y <= GROUND_HEIGHT){
			next_status = UNIT_STATUS_JUMP;
		}
		else if (keyUpDown && unit->x >= 2585 && unit->x <= 2648 && unit->y > 180) {
			next_status = UNIT_STATUS_CLIMB;
		}	
		break;
	case UNIT_STATUS_WALK:
		next_status=fall(unit,next_status);
		if (keyZDown && unit->y <= GROUND_HEIGHT) {
			next_status = UNIT_STATUS_JUMP;
		}
		else if (unit->direction == UNIT_DIRECT_RIGHT && keyRightDown == 0) {
			next_status = UNIT_STATUS_HOLD;
		}
		else if (unit->direction == UNIT_DIRECT_LEFT && keyLeftDown == 0) {
			next_status = UNIT_STATUS_HOLD;
		}
		break;
	case UNIT_STATUS_JUMP:
		next_status = Jump(unit);
		break;
	case UNIT_STATUS_CLIMB:
		Climb(unit);
		if (keyZDown) {
			next_status = UNIT_STATUS_JUMP;
		}
		else if (!(unit->x  >= LADDER1_LEFT && unit->x <= LADDER1_RIGHT) && unit->y <= LADDER1_UP + UNIT_SIZE_Y) {
			next_status = UNIT_STATUS_JUMP;
		}
		break;
	}
	//运动行为变化
	if (next_status != unit->status) {
		//状态变化
		unit->status = next_status;
		unit->frame_id = 0;
		switch (unit->status) {
		case UNIT_STATUS_HOLD:
			if(unit->y <= GROUND_HEIGHT){
			unit->frame_sequence = FRAMES_HOLD;
			unit->frame_count = FRAMES_HOLD_COUNT;

			unit->vx = 0;
			unit->vy = 0;
			}
			break;
		case UNIT_STATUS_WALK:
			unit->frame_sequence = FRAMES_WALK;
			unit->frame_count = FRAMES_WALK_COUNT;
			if (unit->direction == UNIT_DIRECT_RIGHT) {
				unit->vx = 5;
				unit->frame_row = 0;
			}
			else if(unit->direction == UNIT_DIRECT_LEFT){
				unit->vx = -5;
				unit->frame_row = 1;
			}
			break;
		case UNIT_STATUS_CLIMB:
			unit->frame_sequence = FRAMES_CLIMB;
			unit->frame_count = FRAMES_CLIMB_COUNT;
			unit->vx = 0;
			unit->vy = -2;
			break;
		case UNIT_STATUS_JUMP:
			unit->frame_sequence = FRAMES_JUMP;
			unit->frame_count = FRAMES_JUMP_COUNT;
			unit->vy = -10.5;
			break;
		}
	}
	FRAMES_START_X = Camera(unit);
	Knock(unit);
	Eat(unit);
	Attack(unit);
	DoubleJump(unit);
	OpenDoor(unit);
	//血量变化函数
	Hurt(unit);
	health_change(unit);
	//动画运行到下一帧
	unit->x += unit->vx;
	unit->y += unit->vy;

	unit->frame_id++;
	unit->frame_id = unit->frame_id % unit->frame_count;

	int column = unit->frame_sequence[unit->frame_id];
	unit->frame_column = column;
}
//怪物行为函数 
void UnitBehaviour_mob(Unit* unit,Unit* hero) {

	double dirX = hero->x - unit->x;
	double dirY = hero->y - unit->y;
	double distance = sqrt(dirX * dirX + dirY * dirY);


	if (dirX > 0) {
		unit->direction = UNIT_DIRECT_RIGHT;
	}
	else if (dirX < 0){
		unit->direction = UNIT_DIRECT_LEFT;
	}


	//判断当前状态, 以及判断是否需要状态变化
	int next_state = unit->status;
	switch (unit->status) {
	case UNIT_STATUS_HOLD:
		if (abs(dirX) <= 1200) next_state = UNIT_STATUS_WALK;
		break;
	case UNIT_STATUS_WALK:
		next_state = fall(unit, next_state);
		if (abs(dirX) > 1200) next_state = UNIT_STATUS_HOLD;
		if (unit->direction == UNIT_DIRECT_LEFT) unit->vx = -1;
		else if (unit->direction == UNIT_DIRECT_RIGHT) unit->vx = 1;
		else unit->vx = 0;
		break;
	};
	if (next_state != unit->status) {
		//状态变化
		unit->status = next_state;
		unit->frame_id = -1;

		switch (unit->status) {
		case UNIT_STATUS_HOLD:
			unit->frame_sequence = FRAMES_SPIDER;
			unit->frame_id--;
			unit->vx = 0;
			unit->vy = 0;
			break;
		case UNIT_STATUS_WALK:
			unit->frame_sequence = FRAMES_SPIDER;
			unit->frame_count = FRAMES_WALK_COUNT;
			break;
			break;
		};
	}

	//动画运行到下一帧
	

	unit->frame_id++;
	unit->frame_id = unit->frame_id % unit->frame_count;

	int column = unit->frame_sequence[unit->frame_id];
	unit->frame_column = column;
	if (unit->health <= 0) {
		switch (unit->type) {
		case UNIT_TYPE_SPIDER:
			unit->frame_column = 3;
			unit->death_timer++;
			unit->vx = 0;
		}
	}
	unit->x += unit->vx;
	unit->y += unit->vy;
}
#pragma endregion


#pragma region 绘图函数
// 绘图函数
void Paint(HWND hWnd)
{

	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//初始化缓存
	HBITMAP	blankBmp = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, blankBmp);

	// 绘制背景到缓存
	SelectObject(hdc_loadBmp, currentStage->bg);
	//SelectObject(hdc_loadBmp, bmp_BackGround);

	

	// 按场景分类绘制内容到缓存
	if (currentStage->stageID == STAGE_STARTMENU) {
		BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	}
	else if (currentStage->stageID == STAGE_HELP) {
		BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	}
	else if (currentStage->stageID >= STAGE_1 && currentStage->stageID <= STAGE_1) //TODO：添加多个游戏场景
	{
		BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, FRAMES_START_X, 0, SRCCOPY);
		SelectObject(hdc_loadBmp, bmp_Door);
		TransparentBlt(
			hdc_memBuffer, doors[0]->x - FRAMES_START_X, doors[0]->y + 21,
			UNIT_SIZE_X, 105,
			hdc_loadBmp, UNIT_SIZE_X * doors[0]->frame_column, 0, UNIT_SIZE_X, 105 ,
			RGB(255, 255, 255)
		);
		for (int i = 0; i < units.size(); i++) {
			Unit* unit = units[i];
			if(unit != nullptr){
			SelectObject(hdc_loadBmp, unit->img);
			TransparentBlt(
				hdc_memBuffer, unit->x - FRAMES_START_X, unit->y - UNIT_SIZE_Y,
				UNIT_SIZE_X, UNIT_SIZE_Y,
				hdc_loadBmp, UNIT_SIZE_X * unit->frame_column, UNIT_SIZE_Y * unit->frame_row, UNIT_SIZE_X, UNIT_SIZE_Y,
				RGB(255, 255, 255)
			);
			if (Attacking && !Attacked) {
				SelectObject(hdc_loadBmp, bmp_Attack);
				TransparentBlt(
				hdc_memBuffer, unit->x - FRAMES_START_X + 80 * (0.5-unit->direction), unit->y - UNIT_SIZE_Y,
				UNIT_SIZE_X, UNIT_SIZE_Y,
				hdc_loadBmp, UNIT_SIZE_X * attack_frame_id, UNIT_SIZE_Y * unit->direction, UNIT_SIZE_X, UNIT_SIZE_Y,
				RGB(255, 255, 255));
			}
			
		}
		}
		for (int i = 0; i < mobs.size(); i++) {
			Unit* mob = mobs[i];
			if (mob != nullptr && mob->death_timer < 100) {
				SelectObject(hdc_loadBmp, mob->img);
				TransparentBlt(
					hdc_memBuffer, mob->x - FRAMES_START_X, mob->y - UNIT_SIZE_Y,
					UNIT_SIZE_X, UNIT_SIZE_Y,
					hdc_loadBmp, UNIT_SIZE_X * mob->frame_column, UNIT_SIZE_Y * mob->frame_row, UNIT_SIZE_X, UNIT_SIZE_Y,
					RGB(255, 255, 255)
				);
			}
		}
		for (int i = 0; i < bonus_blocks.size(); i++) {
			Bonus_Block* block = bonus_blocks[i];
			SelectObject(hdc_loadBmp, block->img);
			TransparentBlt(
				hdc_memBuffer, block->x - FRAMES_START_X, block->y,
				UNIT_SIZE_X, UNIT_SIZE_Y,
				hdc_loadBmp, UNIT_SIZE_X * block->frame_id, 0, UNIT_SIZE_X, UNIT_SIZE_Y,
				RGB(255, 255, 255));
		}
		for (int i = 0; i < bonus.size(); i++) {
			Bonus* bonu = bonus[i];
			if (bonu->display) {
				SelectObject(hdc_loadBmp, bonu->img);
				TransparentBlt(
					hdc_memBuffer, bonu->x - FRAMES_START_X, bonu->y,
					UNIT_SIZE_X, UNIT_SIZE_Y,
					hdc_loadBmp,0 , 0, UNIT_SIZE_X, UNIT_SIZE_Y,
					RGB(255, 255, 255));
			}
			
		}
		for (int i = 0; i < uis.size(); i++) {
			Health* heart = uis[i];
			if (heart != nullptr) {
				SelectObject(hdc_loadBmp, heart->image);
				TransparentBlt(
					hdc_memBuffer, heart->x, heart->y,
					UNIT_SIZE_X, UNIT_SIZE_Y,
					hdc_loadBmp, UNIT_SIZE_X * heart->frame_column, UNIT_SIZE_Y * heart->frame_row, UNIT_SIZE_X, UNIT_SIZE_Y,
					RGB(255, 255, 255)
				);
			}
		}
		if (GameOver) {
			SelectObject(hdc_loadBmp, bmp_GameOver);
			TransparentBlt(
				hdc_memBuffer, 0, 0,
				1260, 819,
				hdc_loadBmp, 0, 0, 1260, 819,
				RGB(255, 255, 255));
				GameOver = false;
		}
	}


	// 绘制按钮到缓存

	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			SelectObject(hdc_loadBmp, button->img);
			TransparentBlt(
				hdc_memBuffer, button->x, button->y,
				button->width, button->height,
				hdc_loadBmp, 0, 0, button->width, button->height,
				RGB(255, 255, 255)
			);
		}
		if(button->buttonID == BUTTON_RESUME && button->visible == true)
			currentStage->timerOn = false;
	}

	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存（非常重要）
	DeleteObject(blankBmp);
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);
}
#pragma endregion