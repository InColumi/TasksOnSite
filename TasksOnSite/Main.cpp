#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ToUpper(string line)
{
	int sizeLine = line.size();
	int number;
	for(int i = 0; i < sizeLine; i++)
	{
		number = line[i];
		if(number >= 97)
		{
			number -= 32;
		}
		line[i] = number;
	}
	return line;
}

bool Compea(string line, string name)
{
	int size = line.size();
	
	int count = 0;
	int numberLine;
	int numberName;
	for(int i = 0; i < size; i++)
	{
		numberLine = line[i];
		numberName = name[i];
		if(numberLine == numberName ||
		   numberLine + 32 == numberName ||
		   numberLine == numberName + 32)
		{
			++count;
		}
		else
		{
			count = 0;
			break;
		}
		
	}
	return (count == size) ? true : false;
}

int main()
{
	int countRows;
	int sizeLine = 3;
	cin >> countRows;
	string** lines = new string*[countRows];
	for(int i = 0; i < countRows; i++)
	{
		lines[i] = new string[sizeLine];
	}
	string temp;

	for(int i = 0; i < countRows; i++)
	{
		for(int j = 0; j < sizeLine; j++)
		{
			cin >> temp;
			lines[i][j] = temp;
		}
	}

	string location;
	cin >> location;
	location = ToUpper(location);

	bool isFind = false;
	for(unsigned int i = 0; i < countRows; i++)
	{
		if(Compea(lines[i][1], location))
		{
			isFind = true;
			int index = 0;
			if(lines[i][0][0] == '0')
			{
				index = 1;
			}
			for(int j = index; j < lines[i][0].size(); j++)
			{
				cout << lines[i][0][j];
			}
			cout << '_' << location << '_' << lines[i][2];
			break;
		}
	}
	if(isFind == false)
	{
		cout << "Impossible";
	}
	return 0;
}