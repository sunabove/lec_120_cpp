#include "stdafx.h"
#include "Point.h"

Point::Point() {
	ZF_LOGW("object id = %04d , constructor" , this->id);
}


Point::~Point() {
	ZF_LOGW("object id = %04d , destructor" , this->id);
}

void Point::draw(ID2D1HwndRenderTarget * target) {
	ZF_LOGW("Point is drawing.");
}
