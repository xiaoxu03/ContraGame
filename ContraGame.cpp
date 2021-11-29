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


int nowStage = STAGE_STARTMENU;	//定义初始化当前场景编号
Stage* currentStage = NULL;		//当前场景状态
vector<Unit*> units;			//单位
vector<Button*> buttons;		//按钮

int mouseX = 0;
int mouseY = 0;
bool mouseDown = false;
bool keyUpDown = false;
bool keyLeftDown = false;
bool keyRightDown = false;
bool keyEscDown = false;
bool keyZDown = false;
bool keyXDown = false;
bool GameOver = false;
//帧
int FRAMES_HOLD[] = { 0 };
int FRAMES_HOLD_COUNT = 1;
int FRAMES_WALK[] = { 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10 };
int FRAMES_WALK_COUNT = 16;
int FRAMES_JUMP[] = { 7 };
int FRAMES_JUMP_COUNT = 1;
int FRAMES_CLIMB[] = { 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6 };
int FRAMES_CLIMB_COUNT = 16;
int FRAMES_ATTACK[] = { 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
int FRAMES_ATTACK_COUNT = 24;
int FRAMES_BOUNS_FULL[] = { 0 };
int FRAMES_BOUNS_FULL_COUNT = 1;
int FRAMES_DOOR_UP_OPEN[] = { 0 };
int FRAMES_DOOR_UP_OPEN_COUNT = 1;
int FRAMES_DOOR_UP_CLOSE[] = { 0 };
int FRAMES_DOOR_UP_CLOSE_COUNT = 1;
int FRAMES_DOOR_DOWN_OPEN[] = { 1 };
int FRAMES_DOOR_DOWN_OPEN_COUNT = 1;
int FRAMES_DOOR_DOWN_CLOSE[] = { 1 };
int FRAMES_DOOR_DOWN_CLOSE_COUNT = 1;
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
int FRAMES_HEART_FULL[] = { 1 };
int FRAMES_HEART_FULL_COUNT = 1;
int FRAMES_HEART_HALF[] = { 1 };
int FRAMES_HEART_HALF_COUNT = 1;
int FRAMES_HEART_EMPTY[] = { 1 };
int FRAMES_HEART_EMPTY_COUNT = 1;
//场景渲染起点
int FRAMES_START_X = 0;
int X = 0;
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
	//加载UI图像资源
	bmp_Numbers = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_NUMBERS));
	bmp_Heart = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_HEART));
	bmp_X = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_X));
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
		((WINDOW_WIDTH - BUTTON_RESTART_WIDTH) / 2), ((WINDOW_WIDTH - BUTTON_RESTART_HEIGHT) / 2 - 300));
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
					InitStage(hWnd, STAGE_STARTMENU);
					units.clear();
					FRAMES_START_X = 0;
					break;
				}
				case BUTTON_RESTART:
				{
					
					units.clear();
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

// 添加实体函数
Unit* CreateUnit(int side, int type, int x, int y, int health)
{
	Unit* unit = new Unit();
	unit->side = side;
	if (side == SIDE_HERO) {
		unit->img = bmp_Hero;
		unit->direction = UNIT_DIRECT_RIGHT;
	}
	else if (side == UNIT_SIZE_Y) {
		unit->img = bmp_Unit_Blue;
		unit->direction = UNIT_DIRECT_RIGHT;
	}

	unit->type = type;
	unit->status = UNIT_STATUS_HOLD;


	unit->frame_row = unit->direction;
	unit->frame_column = 0;

	unit->frame_sequence = FRAMES_HOLD;
	unit->frame_count = FRAMES_HOLD_COUNT;
	unit->frame_id = 0;

	unit->ax = 0;
	unit->ay = 0;
	unit->x = x;
	unit->y = y;
	unit->vx = 0;
	unit->vy = 0;
	unit->health = health;
	return unit;
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


		// 按场景初始化单位
		switch (stageID) {
		case STAGE_1:
			units.push_back(CreateUnit(SIDE_HERO, UNIT_TYPE_PLAYER, 200, 538, 10));
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
			break;
		case UNIT_TYPE_FISH:
			break;
		case UNIT_TYPE_SPIDER:
			break;
		case UNIT_TYPE_SLIME:
			break;
		}
		}



	}


}
//跟随视角判定函数
int Camera(Unit* unit) {
	//判断条件
	if (!((FRAMES_START_X <= 4 && unit->vx < 0) || (FRAMES_START_X >= 5035 && unit->vx > 0)) && (unit->x > 400 && unit->x < 1000)) {
		unit->x -= unit->vx;
		FRAMES_START_X += unit->vx;
	}
	return FRAMES_START_X;
}
//跳跃函数
int Jump(Unit* unit) {
	int next_status = UNIT_STATUS_JUMP;
	if (unit->y <= GROUND_HEIGHT && !keyZDown) unit->vy += 1;
	else if (unit->y <= GROUND_HEIGHT && keyZDown)	unit->vy += 0.3;
	else if (unit->y > GROUND_HEIGHT && !(unit->x + FRAMES_START_X >= 1276 && unit->x + FRAMES_START_X <= 1438)) {
		unit->vy = 0;
		unit->y = GROUND_HEIGHT;
		next_status = UNIT_STATUS_HOLD;
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
	if (unit->y > GROUND_HEIGHT && (unit->x + FRAMES_START_X >= 1276 && unit->x + FRAMES_START_X <= 1438)) {
		if (unit->x + unit->vx + FRAMES_START_X >= 1438 && keyRightDown) {
			unit->x = 1438 - FRAMES_START_X;
			unit->vx = 0;
		}
		else if (unit->x + unit->vx + FRAMES_START_X <= 1276 && keyLeftDown) {
			unit->x = 1276 - FRAMES_START_X;
			unit->vx = 0;
		}
	}
	return next_status;
}
void fall(Unit* unit) {
	if (unit->x + FRAMES_START_X >= 1276 && unit->x + FRAMES_START_X <= 1438) {
		unit->vy += 0.5;
	}
	if (unit->y > GROUND_HEIGHT && (unit->x + FRAMES_START_X >= 1276 && unit->x + FRAMES_START_X <= 1438)) {
		if (unit->x + unit->vx + FRAMES_START_X >= 1438 && keyRightDown) {
			unit->x = 1438 - FRAMES_START_X;
			unit->vx = 0;
		}
		else if (unit->x + unit->vx + FRAMES_START_X <= 1276 && keyLeftDown) {
			unit->x = 1276 - FRAMES_START_X;
			unit->vx = 0;
		}
	}
}
void Climb(Unit* unit) {
	if (!keyZDown) {
		unit->vy = 0;

	}
}
//玩家行为函数
void UnitBehaviour_hero(Unit* unit) {
	//判断当前状态, 以及判断是否需要状态变化
	
	int next_status = unit->status;
	switch (unit->status) {
	case UNIT_STATUS_HOLD:
		fall(unit);
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
		else if (keyUpDown && unit->x + FRAMES_START_X >= 1800 && unit->x + FRAMES_START_X <= 2000 && unit->y > 200) {
			next_status = UNIT_STATUS_CLIMB;
			Climb(unit);
		}	
		break;
	case UNIT_STATUS_WALK:
		fall(unit);
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
		if (keyZDown) {
			next_status = UNIT_STATUS_JUMP;
		}
		else if (/*TODO:判断横向范围以及是否离开梯子变成跳跃状态*/false) {
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
			unit->vy = UNIT_SPEED;
			break;
		case UNIT_STATUS_JUMP:
			unit->frame_sequence = FRAMES_JUMP;
			unit->frame_count = FRAMES_JUMP_COUNT;
			unit->vy = -10;
			break;
		}
	}
	FRAMES_START_X = Camera(unit);
	X = unit->x + FRAMES_START_X;
	//动画运行到下一帧
	unit->x += unit->vx;
	unit->y += unit->vy;

	unit->frame_id++;
	unit->frame_id = unit->frame_id % unit->frame_count;

	int column = unit->frame_sequence[unit->frame_id];
	unit->frame_column = column;


}
//怪物行为函数 
/*void UnitBehaviour_mob(Unit* unit) {

	double dirX = mouseX - unit->x;
	double dirY = mouseY - unit->y;
	double dirLen = sqrt(dirX * dirX + dirY * dirY) + 0.0001;


	if (dirX > 0) {
		unit->direction = UNIT_DIRECT_RIGHT;
	}
	else {
		unit->direction = UNIT_DIRECT_LEFT;
	}


	//判断当前状态, 以及判断是否需要状态变化
	int next_state = unit->status;
	switch (unit->status) {
	case UNIT_STATUS_HOLD:
		next_state = UNIT_STATUS_WALK;
		break;
	case UNIT_STATUS_WALK:
		//TODO
		break;
	};

	if (next_state != unit->status) {
		//状态变化
		unit->status = next_state;
		unit->frame_id = -1;

		switch (unit->status) {
		case UNIT_STATE_HOLD:
			unit->frame_sequence = FRAMES_HOLD;
			unit->frame_count = FRAMES_HOLD_COUNT;
			unit->vx = 0;
			unit->vy = 0;
			break;
		case UNIT_STATUS_WALK:
			unit->frame_sequence = FRAMES_WALK;
			unit->frame_count = FRAMES_WALK_COUNT;
			unit->vx = dirX / dirLen * UNIT_SPEED;
			unit->vy = dirY / dirLen * UNIT_SPEED;
			break;
		case UNIT_STATE_ATTACK:
			unit->frame_sequence = FRAMES_ATTACK;
			unit->frame_count = FRAMES_ATTACK_COUNT;
			unit->vx = 0;
			unit->vy = 0;
			break;
		};
	}

	//动画运行到下一帧
	unit->x += unit->vx;
	unit->y += unit->vy;

	unit->frame_id++;
	unit->frame_id = unit->frame_id % unit->frame_count;

	int column = unit->frame_sequence[unit->frame_id];
	unit->frame_column = column + unit->direction * (UNIT_LAST_FRAME - 2 * column);


}*/



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
		for (int i = 0; i < units.size(); i++) {
			Unit* unit = units[i];
			if(unit != nullptr){
			SelectObject(hdc_loadBmp, unit->img);
			TransparentBlt(
				hdc_memBuffer, unit->x - 0.5 * UNIT_SIZE_X, unit->y - 0.5 * UNIT_SIZE_Y,
				UNIT_SIZE_X, UNIT_SIZE_Y,
				hdc_loadBmp, UNIT_SIZE_X * unit->frame_column, UNIT_SIZE_Y * unit->frame_row, UNIT_SIZE_X, UNIT_SIZE_Y,
				RGB(255, 255, 255)
			);
			}
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



// 初始化背景函数
/*HBITMAP InitBackGround(HWND hWnd, HBITMAP bmp_src) {

	srand(time(NULL));
	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//初始化缓存
	HBITMAP	bmp_output = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, bmp_output);

	//加载资源
	SelectObject(hdc_loadBmp, bmp_src);


	for (int i = 0; i < BG_ROWS; i++) {

		int src_row = 1;
		if (i >= BG_ROWS_SKY)
			src_row = 0;

		for (int j = 0; j < BG_COLUMNS; j++) {
			int src_column = rand() % BG_SRC_COUNT;

			TransparentBlt(
				hdc_memBuffer, j*BG_CELL_WIDTH, i*BG_CELL_HEIGHT,
				BG_CELL_WIDTH, BG_CELL_HEIGHT,
				hdc_loadBmp, src_column * BG_CELL_WIDTH, src_row * BG_CELL_HEIGHT,
				BG_CELL_WIDTH, BG_CELL_HEIGHT,
				RGB(255, 255, 255)
			);

		}
	}
	
	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);
	
	// 回收资源所占的内存（非常重要）
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);

	return bmp_output;
}*/

#pragma endregion