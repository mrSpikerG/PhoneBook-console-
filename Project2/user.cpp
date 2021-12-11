#include "user.h"

user::user(char* name, char* describe, char* homeTel, char* workTel, char* phoneTel) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->describe = new char[strlen(describe) + 1];
	strcpy_s(this->describe, strlen(describe) + 1, describe);

	this->homeTel = new char[strlen(homeTel) + 1];
	strcpy_s(this->homeTel, strlen(homeTel) + 1, homeTel);

	this->workTel = new char[strlen(workTel) + 1];
	strcpy_s(this->workTel, strlen(workTel) + 1, workTel);

	this->phoneTel = new char[strlen(phoneTel) + 1];
	strcpy_s(this->phoneTel, strlen(phoneTel) + 1, phoneTel);
}
user::~user() {
	delete name;
	delete describe;
	delete homeTel;
	delete workTel;
	delete phoneTel;
}