#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <thread>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> GenerateArray(int size)
{
	srand(time(0));
	vector<int> array;
	for (size_t i = 0; i < size; i++)
	{
		array.push_back(1 + rand() % 100);
	}
	return array;
}

void Fight(vector<int>& array1, vector<int>& array2)
{
	srand(time(0));
	int i = 0, j = 0;
	while (array1.size() != 0 && array2.size() != 0)
	{
		i %= array1.size();
		j %= array2.size();
		if (array1[i] > array2[j])
		{
			array2.erase(array2.begin() + j);
			++i;
		}
		else if (array1[i] < array2[j])
		{
			array1.erase(array1.begin() + i);
			++j;
		}
		else if (array1[i] == array2[j])
		{
			if ((rand() % 2) == 0)
			{
				array2.erase(array2.begin() + j);
				++i;
			}
			else
			{
				array1.erase(array1.begin() + i);
				++j;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите пожалуйста количество участников в турнире!(положительное больше нуля!)" << endl;
	vector<int> guanin;
	vector<int> guanyan;
	vector<int> energy;
	string s;
	cin >> s;

	char* end;
	long i = strtol(s.c_str(), &end, 10);
	if (*end == '\0')
	{
		if (i > 0)
		{
			energy = GenerateArray(i);
			for (size_t i = 0; i < energy.size(); i++)
			{
				if ((i % 2) == 0)
				{
					guanin.push_back(energy[i]);
				}
				else
				{
					guanyan.push_back(energy[i]);
				}
			}

			thread th(Fight, ref(guanin), ref(guanyan));
			th.join();

			if (guanin.size() != 0)
			{
				cout << "Победил монастырь Гуань-Инь. Их Путь Кулака более совершенен. Они забирают себе на хранение статую боддисатвы Араватти." << endl;
			}
			else
			{
				cout << "Победил монастырь Гуань-Янь. Их Путь Кулака более совершенен. Они забирают себе на хранение статую боддисатвы Араватти." << endl;
			}
		}
		else
		{
			cout << "К сожалению вы вввели некорректные данные!" << endl;
		}
	}
	else
	{
		cout << "К сожалению вы вввели некорректные данные!" << endl;
	}
}