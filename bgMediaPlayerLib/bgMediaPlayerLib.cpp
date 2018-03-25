#include "bgMediaPlayer.h"

int bgMediaPlayer::Initialize(int h_count /* = 1 */, int v_count /* = 1 */, enum _PlayCore_ core /* = PlayCore_vlc */, enum _PlayMode_ mode /* = PlayMode_Normal */)
{
	int errCode = 0;

	play_core_ = core;
	play_mode_ = mode;

	int index = 0;
	for (int h_index = 0; h_index < h_count; ++h_index)
	{
		for (int v_index = 0; v_index < v_count; ++v_index)
		{
			errCode = sub_screen_[index].Initialize(screen_window_, h_count, v_count, h_index, v_index, core);
			++index;
		}
	}

	return errCode;
}

void bgMediaPlayer::Destroy()
{
	// ���ٵ����е��Ӵ���
	for (int index = 0; index < MAX_SUBSCREEN_COUNT; ++index)
	{
		sub_screen_[index].Stop();
		sub_screen_[index].Destroy();
	}
}

int bgMediaPlayer::Play(const char *url, int screen_index /* = -1 */)
{
	int errCode = 0;

	// Ѱ��һ�����еĴ���
	// �����������ѯ���ţ���˳���ҵ����
	// ���û�п�������������Ӵ�������ΪѰ�ҿ��е�����
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