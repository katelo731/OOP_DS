// Student : 0513311 Lo Wen-Huei

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <bits/stdc++.h>
#define MAXSIZE 10000
using namespace std;

struct data
{
	string key, gender;
    int height, weight;
	data *next;

	string getGender()
	{
		return gender;
	}

    int getHeight()
    {
    	return height;
	}

    int getWeight()
    {
    	return weight;
	}
};

class HashTable
{
	public:
		HashTable();
		void addItem(string k, string g, int h, int w);
        data &operator[](string k);
		int hash(string k);

	private:
		data *table[MAXSIZE];
};

#endif
