#include "stdafx.h"
#include "Shape.h"

Shape::Shape() {
	ZF_LOGW("object id = %04d , constructor" , this->id);
}


Shape::~Shape() {
	ZF_LOGW("object id = %04d , desctructor" , this->id);
}

void Shape::draw() {
	ZF_LOGW("Shape is drawing.");
}
