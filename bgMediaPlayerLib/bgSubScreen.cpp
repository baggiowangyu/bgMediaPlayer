#include "bgSubScreen.h"

int bgSubScreen::Initialize(CWnd *window, int h_count, int v_count, int h_index, int v_index)
{
	// ���Ƶ�ǰ�Ӵ��ڵ����귶Χ
	CRect player_rect;
	window->GetWindowRect(&player_rect);

	int e_width = player_rect.Width() / v_count;
	int e_height = player_rect.Height() / h_count;

	// ���㵱ǰ���ڵ�RECT
	player_rect.left = h_index * v_count;
	player_rect.top = v_index * h_count;

	int errCode = 0;
}