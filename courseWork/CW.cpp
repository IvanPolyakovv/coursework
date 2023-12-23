#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int a;
	cin >> a;
	switch (a)
	{
	case 1:
		system("Lab1.exe");
		break;
	case 2:
		system("Lab2.exe");
		break;
	case 3:
		system("Lab3.exe");
		break;
	case 4:
		system("Lab4.exe");
		break;
	default:
		cout << "Error";
	}
}