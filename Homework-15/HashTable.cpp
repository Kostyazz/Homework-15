#include "HashTable.h"

HashTable::HashTable(): dataCount(0), dataSize(INIT_SIZE)
{
	data = new AuthData[INIT_SIZE];
}

HashTable::~HashTable()
{
	delete[] data;
}

void HashTable::add(string key, uint * hashValue)
{
	if (dataCount == dataSize) {
		resize();
	}
	for (uint i = 0; i < dataSize; i++) {
		uint index = hash(key, i);
		if (data[index].status != AuthData::used) {
			data[index].login = key;
			data[index].passSha1Hash = hashValue;
			data[index].status = AuthData::used;
			dataCount++;
			break;
		}
	}
}

bool HashTable::find(string key, uint * hashValue)
{
	for (uint i = 0; i < dataSize; i++) {
		uint index = hash(key, i);
		if (data[index].status == AuthData::used && data[index].login == key) {
			return true;
		}
	}
	return false;
}

uint HashTable::hash(string key, uint offset)
{
	uint sum = 0;
	for (char c : key) {
		sum += c;
	}
	//multiplying hash function: f(K) = [M * {K * A}]
	uint fk = floor(dataSize * (sum * A_CONST - floor(sum * A_CONST)));
	//triangle numbers f(i) = (i + i*i) / 2. Should check each number between 0 and M once
	return  (fk + ((offset + 1) * offset) / 2) % dataSize;
}

void HashTable::resize()
{
	AuthData* oldData = data;
	dataSize *= 2;
	dataCount = 0;
	data = new AuthData[dataSize];
	for (uint i = 0; i < dataSize / 2; i++) {
		if (oldData[i].status == AuthData::used) {
			add(oldData[i].login, oldData[i].passSha1Hash);
		}
	}
}
