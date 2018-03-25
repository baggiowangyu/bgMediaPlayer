#ifndef _bgMediaPlayer_H_
#define _bgMediaPlayer_H_

#include "bgSubScreen.h"

#define MAX_SUBSCREEN_COUNT	1024

enum _PlayCore_
{
	PlayCore_vlc,			// VLC播放核心
	PlayCore_ffmpeg_sdl2,	// ffmpeg + sdl2播放核心
	PlayCore_gxx_gsp,		// 高新兴GSP播放核心
	PlayCore_gxx_rtmp		// 高新兴RTMP播放核心
};

enum _PlayMode_
{
	PlayMode_Normal,		// 普通播放
	PlayMode_Loop			// 轮询播放
};

class bgMediaPlayer
{
public:
	bgMediaPlayer(CWnd *window) 
		: screen_window_(window)
		, play_core_(PlayCore_vlc)
		, play_mode_(PlayMode_Normal) {}
	~bgMediaPlayer() { screen_window_ = NULL; }

public:
	int Initialize(int h_count = 1, int v_count = 1, enum _PlayCore_ core = PlayCore_vlc, enum _PlayMode_ mode = PlayMode_Normal);
	void Destroy();

public:
	int Play(const char *url, int screen_index = -1);
	int Stop(int screen_index = -1);
	int Pause(int screen_index = -1);
	int Resume(int screen_index = -1);

	int CaptureScreen(const char *path, int screen_index = -1);

public:
	int ChangePlayMode();

private:
	CWnd *screen_window_;
	bgSubScreen sub_screen_[MAX_SUBSCREEN_COUNT];

private:
	enum _PlayCore_ play_core_;
	enum _PlayMode_ play_mode_;
};

#endif//_bgMediaPlayer_H_

