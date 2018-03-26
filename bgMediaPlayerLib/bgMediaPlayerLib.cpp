#include "bgMediaPlayerLib.h"

int bgMediaPlayer::Initialize(int h_count /* = 1 */, int v_count /* = 1 */, enum _PlayCore_ core /* = PlayCore_vlc */, enum _PlayMode_ mode /* = PlayMode_Normal */)
{
	int errCode = 0;

	play_core_ = core;
	play_mode_ = mode;

	CRect player_rect;
	screen_window_->GetWindowRect(&player_rect);

	char msg[4096] = {0};
	sprintf_s(msg, 4096, "播放器框架坐标：left:%d\ttop:%d\tright:%d\tbottom:%d=====================================\n",
		player_rect.left, player_rect.top, player_rect.right, player_rect.bottom);
	OutputDebugStringA(msg);

	int index = 0;
	for (int h_index = 0; h_index < h_count; ++h_index)
	{
		for (int v_index = 0; v_index < v_count; ++v_index)
		{
			errCode = sub_screen_[index].Initialize(screen_window_, h_count, v_count, h_index, v_index, core);
			++index;
		}
	}

	OutputDebugStringA("===========================================================================\n");

	return errCode;
}

void bgMediaPlayer::Destroy()
{
	// 销毁掉所有的子窗口
	for (int index = 0; index < MAX_SUBSCREEN_COUNT; ++index)
	{
		sub_screen_[index].Stop();
		sub_screen_[index].Destroy();
	}
}

int bgMediaPlayer::Play(const char *url, int screen_index /* = -1 */)
{
	int errCode = 0;

	// 寻找一个空闲的窗口
	// 如果开启了轮询播放，则按顺序找到最后
	// 如果没有开启，则以最大子窗口索引为寻找空闲的上限
	switch (play_mode_)
	{
	case PlayMode_Normal:
		break;
	case PlayMode_Loop:
		break;
	default:
		break;
	}

	return errCode;
}

int bgMediaPlayer::Stop(int screen_index /* = -1 */)
{
	int errCode = 0;

	// 找到对应索引的播放器对象，停止它

	return errCode;
}

int bgMediaPlayer::Pause(int screen_index /* = -1 */)
{
	int errCode = 0;

	return errCode;
}

int bgMediaPlayer::Resume(int screen_index /* = -1 */)
{
	int errCode = 0;

	return errCode;
}

int bgMediaPlayer::CaptureScreen(const char *path, int screen_index /* = -1 */)
{
	int errCode = 0;

	return errCode;
}