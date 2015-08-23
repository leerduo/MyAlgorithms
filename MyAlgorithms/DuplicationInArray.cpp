#include <iostream>
#include <cstdlib>

using namespace std;


//[2,3,1,0,2,5,3] �±���0����ֵ��2�����߲���ȣ�����������ĵڶ������ֽ�����������[1,3,2,0,2,5,3]
//[1,3,2,0,2,5,3] �±���0����ֵ��1�����߲���ȣ�����������ĵ�һ�����ֽ�����������[3,1,2,0,2,5,3]
//[3,1,2,0,2,5,3] �±���0����ֵ��3�����߲���ȣ�����������ĵ��������ֽ�����������[0,1,2,3,2,5,3]
//[0,1,2,3,2,5,3] �±���0����ֵ��0��������һֱ���±�Ϊ4����ֵΪ2���Ƚ�����±�Ϊ2����ֵ����ȣ��ظ��ˡ�

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