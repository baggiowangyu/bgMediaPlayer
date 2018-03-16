#ifndef _bgSubScreen_H_
#define _bgSubScreen_H_

class bgSubScreen
{
public:
	bgSubScreen();
	~bgSubScreen();

public:
	int Initialize(CWnd *window, int h_count, int v_count, int h_index, int v_index);

private:
	CRect GetSubScreenRect();

private:
	int current_index_;
	CStatic *screen_;
};

#endif//_bgSubScreen_H_