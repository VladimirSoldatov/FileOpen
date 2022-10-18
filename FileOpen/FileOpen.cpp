#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <typeinfo>
#include"windows.h"
#include"stdio.h"

using namespace std;



template<typename T>
void insert_text(T massive[], T clone_massive[], int type, int lenth)
{
	FILE* myFile;
	const char file_name[] = "tempary.txt";
	if ((myFile = fopen(file_name, "w")) == NULL)
		cout << "File couldn`t be opened\n";
	else
		cout << "OK. File " << file_name << " is open\n";

	for (int i = 0; i <lenth; i++)
	{

		switch (type)
		{
		case 2:
			fprintf(myFile, "%d ", massive[i]);
			break;
		case 1:
			fprintf(myFile, "%f ", massive[i]);
			break;
		case 3:
			fprintf(myFile, "%s ", massive[i]);
			break;
		default:
			cout << "error\n";
			break;
		}
		
	}
	if (fclose(myFile) == EOF)
		cout << "File " << file_name << " couldn`t be closed\n";
	else
		cout << "File " << file_name << " is closed\n";
	FILE* out;
	out = fopen(file_name, "r");
	int result = 0;
	for (int i = 0; i < lenth; i++)
	{
		switch (type)
		{
		case 2:
			result += fscanf(out, "%d ", &clone_massive[i]);
			break;
		case 1:
			result += fscanf(out, "%f ", &clone_massive[i]);
			break;
		case 3:
			result += fscanf(out, "%s ", &clone_massive[i]);
			break;

		default:
			cout << "error\n";
			break;
		}

	}
	cout << "\n";
	for (int i = 0; i < lenth; i++)
	{
		cout << clone_massive[i] << " ";
	}
	cout << "\n";
}
int main()
{
	
	/*TCHAR buffer[MAX_PATH];
	GetCurrentDirectory(sizeof(buffer), buffer);
    wcout << buffer;
    cout << "Hello World!\n";
	*/
	float massive[] = {1.0f, 2.3f, 3.4f};
	int lenth = sizeof(massive) / sizeof(int);
	float * massive2 = new float [lenth];
	insert_text(massive, massive2, 1, lenth);
	//cout << lenth<<"\n";
	//cout <<strcmp(typeid(string).name(), "class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char> >");
}
