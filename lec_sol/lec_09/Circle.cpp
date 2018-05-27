#include "stdafx.h"
#include "Circle.h"


Circle::Circle() {
	ZF_LOGW("object id = %04d , constructor" , this->id);
}


Circle::~Circle() {
	ZF_LOGW("object id = %04d , destructor" , this->id);
}

void Circle::draw() {
	ZF_LOGW("Cricle is drawing.");
}
