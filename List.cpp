#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
bool _home = false; 
bool _end = false; 
int inner = 1; 
void out(char str[256])
{
	char outstr[256];
	char outbuf[256];
	int p = 256;
	if (strstr(str, "/**") != NULL)
	{
		_home = true;
		_end = false;
	}
	if ((_home == true) && (_end == false))
	{
		if (strstr(str, "\\func") != NULL) 
		{

			for (int j = 0; j < 256; j++)
			{
				outbuf[j] = *(strstr(str, "func") + 5+j);
			}
			p = strcspn(outbuf, ")");
			for (int j = p + 1; j < 256; j++)
			{
				outbuf[j] = 0;
			}
			cout << endl;
			cout << inner << ") " << outbuf << endl;
			inner++;
			cout << endl;
		}
	}
	if (strstr(str, "*/") != NULL)
	{
		_end = true;
	}
}


/*int main()
{
	setlocale(LC_CTYPE, "rus");
	char path[256];
	char buffstr[256];
	fstream fin;
	cin >> path;
	fin.open(path, ios::in);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.getline(buffstr, 256);
			output(buffstr);
		}
	}
	system("pause");
	fin.close();
	return 0;
}*/
