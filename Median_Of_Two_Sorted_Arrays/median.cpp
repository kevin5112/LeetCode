#include <iostream>

double MedianOfTwoArrays(int array1[], int elems1, int array2[], int elems2);

int main()
{
	int array1[]= {2,7,8,9};
	int array2[]= {1,3,4};

	std::cout << "Median is: " << MedianOfTwoArrays(array1, 5, array2, 3) << std::endl;


	return 0;
}

double MedianOfTwoArrays(int array1[], int elems1, int array2[], int elems2)
{
	bool isEven = false;
	int size = elems1 + elems2;
	int val1 = *array1;
	int val2 = *array2;
	double median = 0;
	std::cout << "size: " << size << std::endl;

	if((elems1 + elems2) % 2 == 0)
	{
		isEven = true;
	}

	if(isEven)
	{
		std::cout << "Enter isEven if block\n";
		int i = 0;
		int j = 0;
		while((i + j) < ((size / 2) - 1))
		{
			if(val1 > val2)
			{
				val2 = array2[++j];
			}
			else
			{
				val1 = array1[++i];
			}
		}

		std::cout << "i: " << i << "\nj: " << j << std::endl;
		std::cout << "val1: " << val1 << "\nval2: " << val2 << std::endl;
		median = (val1 + val2) / 2.0;
		return median;
	}
	else
	{
		std::cout << "Enter isOdd if block\n";
		int i = 0;
		int j = 0;
		while((i + j) < (size / 2))
		{
			if(val1 > val2)
			{
				val2 = array2[++j];
			}
			else
			{
				val1 = array1[++i];
			}
		}
		std::cout << "i: " << i << "\nj: " << j << std::endl;
		std::cout << "val1: " << val1 << "\nval2: " << val2 << std::endl;
		if(val1 > val2)
			return (double)val1;
		else 
			return (double)val2;
	}
}