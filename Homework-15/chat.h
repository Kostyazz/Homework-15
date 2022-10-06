#pragma once

#include "sha1.h"
#include "HashTable.h"

class Chat {
public:
	Chat();
	void reg(string _login, string _pass);
	bool login(string _login, string _pass);
private:
	HashTable ht;
};