// Student : 0513311 Lo Wen-Huei

#include "HashTable.h"

HashTable::HashTable()
{
	for(int i=0;i<MAXSIZE;i++)
	{
		data *newdata = new data;

		newdata->key = "";
		newdata->gender = "";
		newdata->height = NULL;
		newdata->weight = NULL;
		newdata->next = NULL;

		table[i] = newdata;
	}
}

int HashTable::hash(string k)
{
    int seed = 131;
	unsigned int index = 0;

	for(int i=0; i<k.size(); i++)
		index = (index * seed) + k[i];

	return (index % MAXSIZE);
}

void HashTable::addItem(string k, string g, int h, int w)
{
	int index = hash(k);

	if(table[index]->key == "")
	{
		table[index]->key = k;
		table[index]->gender = g;
		table[index]->height = h;
		table[index]->weight = w;
	}
	else
	{
		data *new_data = new data;

		new_data->key = k;
		new_data->gender = g;
		new_data->height = h;
		new_data->weight = w;

        // insert from head
		new_data->next = table[index];
		table[index] = new_data;
	}
}

data &HashTable::operator [](string k)
{
	int index = hash(k);
	data *data_ptr = table[index];

	if(data_ptr->key == k)
		return *data_ptr;

	while(data_ptr->next != NULL)
	{
        data_ptr = data_ptr->next;

		if(data_ptr->key == k)
			return *data_ptr;
	}
}
