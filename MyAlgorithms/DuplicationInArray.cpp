#include <iostream>
#include <cstdlib>

using namespace std;


//[2,3,1,0,2,5,3] 下标是0，数值是2，两者不相等，将其与数组的第二个数字交换，交换后[1,3,2,0,2,5,3]
//[1,3,2,0,2,5,3] 下标是0，数值是1，两者不相等，将其与数组的第一个数字交换，交换后[3,1,2,0,2,5,3]
//[3,1,2,0,2,5,3] 下标是0，数值是3，两者不相等，将其与数组的第三个数字交换，交换后[0,1,2,3,2,5,3]
//[0,1,2,3,2,5,3] 下标是0，数值是0，继续，一直到下标为4，数值为2，比较其和下标为2的数值，相等，重复了。

bool duplicate(int numbers[], int length, int *duplication)
{
	if (numbers == NULL || length <= 0)
	{
		return false;
	}
	for (int i = 0; i < length;i++)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
		{
			return false;
		}
	}
	for (int i = 0; i < length;i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			//swap numbers[i] and numbers[numbers[i]]
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}