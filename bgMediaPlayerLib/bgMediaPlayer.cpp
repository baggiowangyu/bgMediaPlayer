#include "bgMediaPlayer.h"

int bgMediaPlayer::Initialize(int h_count /* = 1 */, int v_count /* = 1 */)
{
	int errCode = 0;

	int index = 0;
	for (int h_index = 0; h_index < h_count; ++h_index)
	{
		for (int v_index = 0; v_index < v_count; ++v_index)
		{
			errCode = sub_screen_[index].Initialize(screen_window_, h_index, v_index);
			++index;
		}
	}

	return errCode;
}