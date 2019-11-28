#include <iostream>
using namespace std;
	
int f1(int val)
{
	int		num = 0;
	int		*ptr = &num;

	cout << &val << endl;

	if (val == 0) {
		int		val;

		val = 5;
		cout << &val << endl;

		ptr = &val;
		
	}

	cout << ptr << endl;

	return(*ptr + 1);
}

int main()
{
	cout << f1(0) << endl;
}
