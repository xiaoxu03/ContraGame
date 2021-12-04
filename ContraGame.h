#pragma once

#pragma region 头文件引用

// Windows 头文件: 
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>

// 资源头文件
#include "resource.h"
#pragma comment(lib, "Msimg32.lib")			//图象处理的函数接口，例如：透明色的位图的绘制TransparentBlt函数


// TODO:  在此处引用程序需要的其他头文件
#include <vector>
#include <math.h>


#pragma endregion


#pragma region 宏定义

#define WINDOW_TITLEBARHEIGHT	32			//标题栏高度
#define WINDOW_WIDTH			1260		//游戏窗口宽度
#define WINDOW_HEIGHT			819			//游戏窗口高度

//按键定义
#define	VK_Z					0x5A		//定义Z键

#define STAGE_STARTMENU			0			//开始画面的ID
#define STAGE_HELP				-1			//帮助画面的ID
#define STAGE_1					1			//第一个游戏场景的ID
#define STAGE_2					2			//第二个游戏场景的ID
#define STAGE_3 				3			//第三个游戏场景的ID
#define STAGE_4					4			//第四个游戏场景的ID



#define UNIT_SIZE_X				63			//单位的宽度
#define UNIT_SIZE_Y				63			//单位的高度
#define UNIT_LAST_FRAME			10			//单位的动画帧最大值

//单位阵营定义
#define SIDE_HERO				10000		//定义玩家阵营
#define SIDE_MOB				10001		//定义敌人阵营

//单位类型定义
#define UNIT_TYPE_PLAYER		0		//定义单位类型：玩家
#define UNIT_TYPE_BEE			1		//定义单位类型：蜜蜂
#define UNIT_TYPE_SLIME			2		//定义单位类型：史莱姆
#define UNIT_TYPE_MOUSE			3		//定义单位类型：老鼠
#define UNIT_TYPE_FISH			4		//定义单位类型：鱼
#define UNIT_TYPE_BOSS			5		//定义单位类型：BOSS
#define UNIT_TYPE_SPIDER		6		//单位类型定义：蜘蛛

//单位状态定义
#define UNIT_STATUS_HOLD		0		//静止
#define UNIT_STATUS_WALK		1		//行走
#define UNIT_STATUS_JUMP		2		//跳跃
#define UNIT_STATUS_CLIMB		3		//攀爬

//单位方向定义
#define UNIT_DIRECT_RIGHT		0		//向右
#define UNIT_DIRECT_LEFT		1		//向左


//背景
/*#define BG_SRC_COUNT			1		//背景资源数量
#define BG_COLUMNS				1		//背景列数
#define BG_ROWS					1		//背景行数
#define BG_ROWS_SKY				0		//背景天空行数
#define BG_ROWS_LAND			1		//背景地面行数
#define BG_CELL_WIDTH			1024	//背景单格宽度
#define BG_CELL_HEIGHT			768		*///背景单格高度

//其它定义
#define BUTTON_STARTGAME			1001	//开始游戏按钮ID
#define BUTTON_HELP					1002	//帮助游戏按钮ID
#define BUTTON_BACK					1003	//返回按钮ID
#define BUTTON_MENU					1004	//菜单按钮ID
#define BUTTON_RESUME				1005	//继续按钮ID
#define BUTTON_RESTART				1006	//重新开始按钮ID
#define BUTTON_STARTGAME_WIDTH		212		//开始游戏按钮宽度
#define BUTTON_STARTGAME_HEIGHT		76		//开始游戏按钮高度
#define BUTTON_RESTART_WIDTH		212		//重新开始游戏按钮宽度
#define BUTTON_RESTART_HEIGHT		76		//重新开始游戏按钮高度
#define BUTTON_HELP_WIDTH			212		//帮助按钮宽度
#define BUTTON_HELP_HEIGHT			76		//帮助按钮高度
#define BUTTON_BACK_WIDTH			212		//返回按钮宽度
#define BUTTON_BACK_HEIGHT			76		//返回按钮高度
#define BUTTON_MENU_WIDTH			212		//菜单按钮宽度
#define BUTTON_MENU_HEIGHT			76		//菜单按钮高度
#define BUTTON_RESUME_WIDTH			212		//继续按钮宽度
#define BUTTON_RESUME_HEIGHT		76		//继续按钮高度
#define GROUND_HEIGHT				567		//地面高度
#define TIMER_GAMETIMER				1		//游戏的默认计时器ID
#define TIMER_GAMETIMER_ELAPSE		15		//默认计时器刷新间隔的毫秒数
#define UNIT_SPEED					4		//单位行走速度	

//场景特殊定义
#define PIT1_LEFT					1259
#define PIT1_RIGHT					1449
#define LADDER1_LEFT				2583
#define LADDER1_RIGHT				2646
#define LADDER1_UP					189
#pragma endregion


#pragma region 结构体声明

// 场景结构体
struct Stage
{
	int stageID;		//场景编号
	HBITMAP bg;			//背景图片
	int timeCountDown;	//游戏时间倒计时
	bool timerOn;		//计时器是否运行（游戏是否被暂停）

};


// 按钮结构体
struct Button
{
	int buttonID;	//按钮编号
	bool visible;	//按钮是否可见
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	int width;		//宽度
	int height;		//高度
};

// 平台结构体
struct Plat {
	int left;
	int right;
	int down;
	int up;
	bool is_half;
};
// 单位结构体
struct Unit
{
	HBITMAP img;	//图片

	int frame_row;			//当前显示的是图像的第几行
	int frame_column;		//当前显示的是图像的第几列

	int* frame_sequence;		//当前的帧序列
	int frame_count;		//帧序列的长度
	int frame_id;			//当前显示的是帧序列的第几个


	int side;		//单位阵营
	int type;		//单位类型
	int status;		//单位状态
	int direction;	//单位方向

	int x;			//坐标x
	int y;			//坐标y
	double vx;		//速度x
	double vy;		//速度y
	double ax;		//加速度x
	double ay;		//加速度y
	int health;		//生命值
};




//TODO: 添加游戏需要的更多种数据（地物、砖块等）


#pragma endregion


#pragma region 事件处理函数声明


// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

#pragma endregion


#pragma region 其它游戏状态处理函数声明

// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);

// 添加单位函数
Unit* CreateUnit(int side, int type, int x, int y, int health);
//添加平台函数
Plat* CreatePlat(int left, int right, int up, int down);
// 初始化场景函数
void InitStage(HWND hWnd, int stageID);

// 刷新单位状态函数
void UpdateUnits(HWND hWnd);

//单位行为函数
void UnitBehaviour_hero(Unit* unit);
//void UnitBehaviour_mob(Unit* unit);
//视角跟随函数
int Camera(Unit* unit);			//移动视角函数
int Jump(Unit* unit);			//跳跃函数
int fall(Unit* unit,int next_status);			//跌落函数
//TODO: 添加游戏需要的更多函数


#pragma endregion 


#pragma region 绘图函数声明

// 绘图函数
void Paint(HWND hWnd);

#pragma endregion