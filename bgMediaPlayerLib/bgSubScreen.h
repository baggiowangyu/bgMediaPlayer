#ifndef _bgSubScreen_H_
#define _bgSubScreen_H_

#include <afxwin.h>


class bgSubScreen
{
public:
	bgSubScreen();
	~bgSubScreen();

public:
	int Initialize(CWnd *window, int h_count, int v_count, int h_index, int v_index, enum _PlayCore_ core);
	void Destroy();

private:
	//CRect GetSubScreenRect();

private:
	int current_index_;
	POINT screen_potin_;
	CStatic *screen_;
	CRect screen_rect_;
	enum _PlayCore_ player_core_;
};

#endif//_bgSubScreen_H_