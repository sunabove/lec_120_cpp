#pragma once
public class VisionInterface
{
public: 
	enum class UiMode : int { PREVIEW = 0 , CANNY = 1 , MATCH = 2 };

	enum class PlayMode { CAM_DISABLED = -1, STOP = 0, PLAY = 1, PAUSE = 2 };

	enum class RecordMode { NO_RECORD = 0, RECORD = 1 };

	enum class VideoSrc { DEVICE = 0 , FILE = 1 } ;

	enum class MouseEvent { LEAVE = -1, ENTER = 0, DOWN = 1, DRAG = 2 , MOVE = 3, UP = 4, CLICK = 5 , DBL_CLICK = 6 };
};

