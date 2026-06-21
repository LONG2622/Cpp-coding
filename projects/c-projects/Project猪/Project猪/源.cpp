#include<iostream>
using namespace std;
int main()
{ 
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	cout << "A" << endl;
	cin >> num1;
	cout << "B" << endl;
	cin >> num2;
	cout << "C" << endl;
	cin >> num3;
	cout << "Awei" << num1 << endl;
	cout << "Bwei" << num2 << endl;
	cout << "Cwei" << num3 << endl;
	if (num1 > num2)
	{
		if (num1 > num3) {
			cout << "A is the heaviest" << endl;


		}
		else
			system("pause");
		return 0
			;
	}