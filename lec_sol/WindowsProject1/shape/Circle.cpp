#include "stdafx.h"
#include "Circle.h"


Circle::Circle() {
	ZF_LOGW("object id = %04d , constructor" , this->id);
}


Circle::~Circle() {
	ZF_LOGW("object id = %04d , destructor" , this->id);
}

void Circle::draw(ID2D1HwndRenderTarget * target) {
	ZF_LOGW("Cricle is drawing.");
	ID2D1SolidColorBrush * brush = NULL ; 
	const D2D1_COLOR_F color = D2D1::ColorF(1.0f, 1.0f, 0);
	HRESULT hr = target->CreateSolidColorBrush(color, &brush);

	D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2F( center.x,  center.y), radius, radius);
	target->FillEllipse(ellipse, brush);	

	if (brush) {
		brush->Release();
	}
}
