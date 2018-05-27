#include "stdafx.h"
#include "ComObject.h"

int ComObject::LAST_ID = 0; 

ComObject::ComObject() {
	this->id = ++ ComObject::LAST_ID ;
	ZF_LOGW("object id = %04d , constructor" , this->id);
}

ComObject::~ComObject() {
	ZF_LOGW("object id = %04d , destructor" , this->id);
}

#//