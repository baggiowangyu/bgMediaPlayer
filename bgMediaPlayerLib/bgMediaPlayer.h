#ifndef _bgMediaPlayer_H_
#define _bgMediaPlayer_H_

#include "bgSubScreen.h"

#define MAX_SUBSCREEN_COUNT	128

class bgMediaPlayer
{
public:
	bgMediaPlayer(CWnd *window) 
		:screen_window_(window) {}
	~bgMediaPlayer() { screen_window_ = NULL; }

public:
	int Initialize(int h_count = 1, int v_count = 1);
	void Destroy();

public:
	int Play(const char *url, int screen_index = -1);
	int Stop(int screen_index = -1);
	int Pause(int screen_index = -1);
	int Resume(int screen_index = -1);

	int CaptureScreen(const char *path, int screen_index = -1);

private:
	CWnd *screen_window_;
	bgSubScreen sub_screen_[MAX_SUBSCREEN_COUNT];
};

#endif//_bgMediaPlayer_H_