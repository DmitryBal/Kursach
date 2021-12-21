#include <iostream>
#define HASHFUNC(a,b) (a % b)

using namespace std;

struct Current;

struct HashInfo
{
	int code;
	Current * current;
	union
	{
		int i;
		Current* H;
	};
};

template<int T>
struct HashTable
{
	HashInfo data[T + 3];
	int code;
	int count;
	HashTable();

	void Clear() { code++; count = 0; }
	
	HashInfo* Find(Current* a);
	void Add(Current* a, int d);
};

template<int T>
HashTable<T>::HashTable() : code(1), count(0)
{
	for (int i; i < sizeof(data);i++)
		data[i] = 0;
}

template<int T>
HashInfo* HashTable<T>::Find(Current* a)
{
	for (int i = HASHFUNC(a, T); data[i].code == code;i++)
		if (data[i].current == a)
			return &(data[i]);
	return 0;
}

template<int T>
void HashTable<T>::Add(Current* a, int d)
{
	for (int i = HASHFUNC(a, T); data[i].code == code;i++)
	{
		if (i >= T + 2)
			std::cout << "Хеш-Таблица переполнена";
		data[i].current = a;
		data.code = code;
		data[i].i = d;
		count++;
		if (count * 2 > T)
			std::cout << "Размер Хеш-Таблицы слишком мал";
	}
}

int main()
{
	setlocale(LC_CTYPE, "rus");
}