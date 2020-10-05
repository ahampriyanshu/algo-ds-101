#include <iostream>

bool IsUglyNumber(int num)
{
	auto MaxDivide = [=](int& left, const int& right) {
		while (left % right == 0) left = left / right;
		return left;
	};

	num = MaxDivide(num, 2);
	num = MaxDivide(num, 3);
	num = MaxDivide(num, 5);

	return num == 1;
}

int main()
{
	for (int i = 1; i < 50; ++i)
	{
		printf("%d is ugly? %d\n", i, IsUglyNumber(i));
	}

	return EXIT_SUCCESS;
}
