#include<iostream>
#pragma once
class user {
private:
	char* name;
	char* describe;
	char* homeTel; //чтобы номера которые начинаются с '0' и '+' показывались
	char* workTel;
	char* phoneTel;
public:

	user(char*, char*, char*, char*, char*);

	inline char* getName() const {
		return this->name;
	}
	inline char* getDescribe() const {
		return this->describe;
	}
	inline char* getHomeTel() const {
		return this->homeTel;
	}
	inline char* getWorkTel() const {
		return this->workTel;
	}
	inline char* getPhoneTel() const {
		return this->phoneTel;
	}

	~user();
};