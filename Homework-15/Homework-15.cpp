#include <iostream>
#include "chat.h"

using namespace std;
int main()
{
	Chat chat;
	chat.reg("Vasya", "123");
	chat.reg("Petya", "1234");
	chat.reg("King", "boss");
	chat.reg("Ayaya", "Oyoyo");
	chat.reg("Vex", "death");
	cout << chat.login("Vasya", "123");
	cout << chat.login("oioi", "123");
}