#pragma once

#include "Sha1.h"
#include <string>
typedef unsigned int uint;

using namespace std;
const int INIT_SIZE = 4; // low number for easier testing
const double A_CONST = 0.7;
class HashTable
{
public:
	HashTable();
	~HashTable();
	void add(string key, uint* value);
	bool find(string key, uint* value);

private:
	struct AuthData {
		enum enStatus {
			free,
			used,
			deleted
		};
		AuthData() : login(""), passSha1Hash(nullptr), status(free) {
		}
		~AuthData() {
			if (passSha1Hash != nullptr)
				delete[] passSha1Hash;
		}
		AuthData(string _login, uint* sh1) : login(_login), passSha1Hash(sh1), status(used)
		{
		}
		AuthData& operator = (const AuthData& other) {
			login = other.login;

			if (passSha1Hash != 0)
				delete[] passSha1Hash;
			passSha1Hash = new uint[SHA1HASHLENGTHUINTS];

			memcpy(passSha1Hash, other.passSha1Hash, SHA1HASHLENGTHBYTES);

			return *this;
		}
		string login;
		uint* passSha1Hash;
		enStatus status;
	};
	uint hash(string key, uint offset);
	void resize();

	AuthData* data;
	uint dataCount;
	uint dataSize;
};

