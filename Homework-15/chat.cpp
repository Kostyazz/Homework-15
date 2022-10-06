#include "chat.h"
#include "HashTable.h"

Chat::Chat() {
}
void Chat::reg(string _login, string _pass) {
	ht.add(_login, sha1(_pass.c_str(), _pass.length() + 1));
}
bool Chat::login(string _login, string _pass) {
	return ht.find(_login, sha1(_pass.c_str(), _pass.length() + 1));
}