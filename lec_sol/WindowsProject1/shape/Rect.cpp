#include "stdafx.h"
#include "Rect.h"

Rect::Rect() {
	ZF_LOGW("object id = %04d , constructor" , this->id);
}

Rect::Rect(const Rect & rect) {
	ZF_LOGW("object id = %04d , copy constructor" , this->id);
}

Rect::~Rect() {
	ZF_LOGW("object id = %04d , destructor" , this->id);
}

void Rect::draw(ID2D1HwndRenderTarget * target) {
	ZF_LOGW("Rect is drawing.");

	ID2D1SolidColorBrush * brush = NULL ; 
	const D2D1_COLOR_F color = D2D1::ColorF(1.0f, 0.0f, 0);
	HRESULT hr = target->CreateSolidColorBrush(color, &brush);

	D2D1_RECT_F r = D2D1::RectF(center.x - width/2, center.y - height/2, center.x + width/2, center.y + height/2);
	target->FillRectangle(r, brush);

	if (brush) {
		brush->Release();
	}
}

void Rect::draw() {
}
