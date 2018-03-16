#include "bgSubScreen.h"

int bgSubScreen::Initialize(CWnd *window, int h_count, int v_count, int h_index, int v_index)
{
	// 绘制当前子窗口的坐标范围
	CRect player_rect;
	window->GetWindowRect(&player_rect);

	int e_width = player_rect.Width() / v_count;
	int e_height = player_rect.Height() / h_count;

	// 计算当前窗口的RECT

	int errCode = 0;
}