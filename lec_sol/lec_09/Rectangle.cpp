#include "stdafx.h"
#include "Rectangle.h"


Rectangle::Rectangle() {
	this->log("Rectangle default constructor is called.");
}

Rectangle::Rectangle(const Rectangle & rectangle) {
	this->log("Rectangle copy constructor is called.");
}

Rectangle::~Rectangle() {
	this->log("Rectangle destructor is called.");
}

void Rectangle::setWidth(int width) {
	this->width = width;
}

void Rectangle::setHeight(int height) {
	this->height = height;
}
