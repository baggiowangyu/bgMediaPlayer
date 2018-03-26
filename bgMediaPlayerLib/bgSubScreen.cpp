#include "bgSubScreen.h"


bgSubScreen::bgSubScreen()
: screen_(NULL)
{

}

bgSubScreen::~bgSubScreen()
{

}

/************************************************************************

�Ӵ�����������㷨
			��������������������- width  ����������������-����
h_index  �� �����������������Щ��������������Щ�����������������
			���� e_width �� ��              ��              ����
			��              ��              ��              ��e_height
			��     0        ��       2      ��       3      ��
			��              ��              ��              ����
			�����������������੤�������������੤�������������ȩ�
			��              ��              ��              ��
			��              ��              ��              ��
			��     4        ��       5      ��       6      ��
			��              ��              ��              ��
			�����������������੤�������������੤��������������
			��              ��              ��              ��
			��              ��              ��              ��
			��     7        ��       8      ��       9      ��
			��              ��              ��              ��
			�����������������ة��������������ة���������������
            ��
            v_index

			ÿ�����ڵ�����㣺
			top    = h_index * e_height;
			bottom = top + e_height;
			left   = v_index * e_width;
			right  = left + e_width;

************************************************************************/

int bgSubScreen::Initialize(CWnd *window, int h_count, int v_count, int h_index, int v_index, enum _PlayCore_ core)
{
	player_core_ = core;

	// ���Ƶ�ǰ�Ӵ��ڵ����귶Χ
	CRect player_rect;
	window->GetWindowRect(&player_rect);

	int e_width = player_rect.Width() / v_count;
	int e_height = player_rect.Height() / h_count;

	// ���㵱ǰ���ڵ�RECT
	player_rect.top    = h_index * e_height;
	player_rect.bottom = player_rect.top + e_height;
	player_rect.left   = v_index * e_width;
	player_rect.right  = player_rect.left + e_width;

	screen_potin_.x = v_index;
	screen_potin_.y = h_index;

	char msg[4096] = {0};
	sprintf_s(msg, 4096, "�Ӵ���(%d, %d) >>> ���꣺left:%d\ttop:%d\tright:%d\tbottom:%d\n",
		h_index, v_index, player_rect.left, player_rect.top, player_rect.right, player_rect.bottom);
	OutputDebugStringA(msg);

	// �����ؼ�
	if (screen_ == NULL)
	{
		// ���û�д��������򴴽��µĶ���
		screen_ = new CStatic();
		screen_->Create(_T(""), WS_CHILD|SS_SUNKEN|SS_NOTIFY, player_rect, window, 0);
	}
	else
	{
		// �������Ļ������ô�С
		screen_->MoveWindow(player_rect);
	}
	
	screen_->SetWindowText(_T("���ǲ��Ŵ���"));
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