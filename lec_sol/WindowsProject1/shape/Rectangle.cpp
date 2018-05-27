#include "stdafx.h"
#include "Rectangle.h"

Rectangle::Rectangle() {
	ZF_LOGW("object id = %04d , constructor" , this->id);
}

Rectangle::Rectangle(const Rectangle & rectangle) {
	ZF_LOGW("object id = %04d , copy constructor" , this->id);
}

Rectangle::~Rectangle() {
	ZF_LOGW("object id = %04d , destructor" , this->id);
}

void Rectangle::setWidth(int width) {
	this->width = width;
}

void Rectangle::setHeight(int height) {
	this->height = height;
}

void Rectangle::draw() {
	ZF_LOGW("Rectangle is drawing.");
}
