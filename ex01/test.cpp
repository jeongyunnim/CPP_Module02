#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>

int main(void)
{
	float	fTest;
	int		iTest;
	int		i;

	i = 0;
	fTest = 1;
	iTest = 1;
	while (i < 150)
	{
		fTest *= pow(2, -1);
		iTest = (int)fTest;
		iTest |= 1;
		memcpy(&iTest, &fTest, sizeof(int));
		std::cout << i << "th\n";
		std::cout << std::setprecision(150) << std::fixed << "fTest: " << fTest << std::endl;
		std::cout << "iTest: " << iTest << std::endl;
		for (int j = 31; j >= 0; j--)
		{
			if (j == 30 || j == 22)
				std::cout << " | ";
			if (iTest >= pow(2, j))
			{
				iTest -= pow(2, j);
				std::cout << 1;
			}
			else
				std::cout << 0;
			if (j % 4 == 0)
				std::cout << ' ';
		}
		std::cout << "\n\n";
		i++;
	}

	iTest = 0b000000000000000000000000000001;
	memcpy(&fTest, &iTest, sizeof(int));
	std::cout << "fTest: " << fTest << std::endl;
	iTest = 0b000000000000000000000000000010;
	memcpy(&fTest, &iTest, sizeof(int));
	std::cout << "fTest: " << fTest << std::endl;
	iTest = 0b000000001000000000000000000001;
	memcpy(&fTest, &iTest, sizeof(int));
	std::cout << "fTest: " << fTest << std::endl;
	iTest = 0b000000001000000000000000000010;
	memcpy(&fTest, &iTest, sizeof(int));
	std::cout << "fTest: " << fTest << std::endl;
	return 0;
}