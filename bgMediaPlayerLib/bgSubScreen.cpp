#include "bgSubScreen.h"


bgSubScreen::bgSubScreen()
: screen_(NULL)
{

}

bgSubScreen::~bgSubScreen()
{

}

/************************************************************************

子窗口坐标计算算法
			│←────────- width  ────────-→│
h_index  → ┌───────┬───────┬───────┐─
			│← e_width → │              │              │↑
			│              │              │              │e_height
			│     0        │       2      │       3      │
			│              │              │              │↓
			├───────┼───────┼───────┤─
			│              │              │              │
			│              │              │              │
			│     4        │       5      │       6      │
			│              │              │              │
			├───────┼───────┼───────┤
			│              │              │              │
			│              │              │              │
			│     7        │       8      │       9      │
			│              │              │              │
			└───────┴───────┴───────┘
            ↑
            v_index

			每个窗口的坐标点：
			top    = h_index * e_height;
			bottom = top + e_height;
			left   = v_index * e_width;
			right  = left + e_width;

************************************************************************/

int bgSubScreen::Initialize(CWnd *window, int h_count, int v_count, int h_index, int v_index, enum _PlayCore_ core)
{
	player_core_ = core;

	// 绘制当前子窗口的坐标范围
	CRect player_rect;
	window->GetWindowRect(&player_rect);

	int e_width = player_rect.Width() / v_count;
	int e_height = player_rect.Height() / h_count;

	// 计算当前窗口的RECT
	player_rect.top    = h_index * e_height;
	player_rect.bottom = player_rect.top + e_height;
	player_rect.left   = v_index * e_width;
	player_rect.right  = player_rect.left + e_width;

	screen_potin_.x = v_index;
	screen_potin_.y = h_index;

	char msg[4096] = {0};
	sprintf_s(msg, 4096, "子窗口(%d, %d) >>> 坐标：left:%d\ttop:%d\tright:%d\tbottom:%d\n",
		h_index, v_index, player_rect.left, player_rect.top, player_rect.right, player_rect.bottom);
	OutputDebugStringA(msg);

	// 创建控件
	if (screen_ == NULL)
	{
		// 如果没有创建过，则创建新的对象
		screen_ = new CStatic();
		screen_->Create(_T(""), WS_CHILD|SS_SUNKEN|SS_NOTIFY, player_rect, window, 0);
	}
	else
	{
		// 创建过的话就重置大小
		screen_->MoveWindow(player_rect);
	}
	
	screen_->SetWindowText(_T("这是播放窗口"));
	screen_->ShowWindow(SW_SHOW);

	return 0;
}

void bgSubScreen::Destroy()
{

}

int bgSubScreen::Play(const char *url)
{
	int errCode = 0;
	return errCode;
}

int bgSubScreen::Stop()
{
	int errCode = 0;
	return errCode;
}

int bgSubScreen::Pause()
{
	int errCode = 0;
	return errCode;
}

int bgSubScreen::Resume()
{
	int errCode = 0;
	return errCode;
}

int bgSubScreen::CaptureScreen(const char *path)
{
	int errCode = 0;
	return errCode;
}