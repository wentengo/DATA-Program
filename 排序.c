#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

void Swap(int *x, int *y)//Ωªªª∫Ø ˝
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void InsertSort(int *a, int n)//≤Â»Î≈≈–Ú
{
	assert(a);
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0)
		{
			if (a[j + 1] < a[j])
			{
				Swap(&a[j], &a[j + 1]);
				j--;
			}
			else
				break;
		}
	}
}

void ShellSort(int *a, int n)//œ£∂˚≈≈–Ú
{
	assert(a);
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int j = i;
			while (j - gap >= 0)
			{
				if (a[j] < a[j - gap])
					Swap(&a[j], &a[j - gap]);
				j -= gap;
			}
		}
	}
}

void SelectSort(int *a, int n)//—°‘Ò≈≈–Ú
{
	assert(a);
	int min = 0, max = 0, left = 0, right = n-1;
	while (left<=right)
	{
		for (int i = left; i<=right;i++)
		{
			if (a[min] > a[i])
				min = i;
			if (a[max] < a[i])
				max = i;
		}
		Swap(&a[min], &a[left]);
		if (max == left)
			max = min;
		Swap(&a[max], &a[right]);
		left++;
		right--;
	}
}

void Heap(int *a, int root)
{
	assert(a);
	
	for (int parent = (root - 1) / 2; parent >= 0;parent--)
	{
		int child = 2 * parent + 1;
		if (child != root&&a[child] < a[child + 1])
			++child;
		if (a[parent] < a[child])
			Swap(&a[parent], &a[child]);
	}
}

void HeapSort(int *a, int n)//∂—≈≈–Ú
{
	assert(a);
	Heap(a, n);//œÚ…œµ˜∂—
	while (n>1)
	{
		for (int parent = 0; parent <= (n - 1) / 2; parent++)//œÚœ¬µ˜∂—
		{
			int child = parent * 2 + 1;
			if (child < (n - 1) && a[child] < a[child + 1])
				++child;
			if (child < n&&a[parent] < a[child])
				Swap(&a[parent], &a[child]);
		}
		Swap(&a[0], &a[n - 1]);
		n--;
	}
}

void BubbleSort(int *a, int n)//√∞≈›≈≈–Ú
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j + 1 < n - i; j++)
		{
			if (a[j]>a[j + 1])
				Swap(&a[j], &a[j + 1]);
		}
	}
}

int Quick(int *a, int left, int right)
{
	assert(a);
	while (left < right)
	{
		for (; left<right; left++)
		{
			if (a[left] > a[right])
			{
				Swap(&a[left], &a[right]);
				right--;
				break;
			}
		}
		for (; left < right; right--)
		{
			if (a[right] < a[left])
			{
				Swap(&a[left], &a[right]);
				left++;
				break;
			}
		}
	}
	return right;
}

void QuickSort(int *a, int left, int right)//øÏÀŸ≈≈–Ú
{
	assert(a);
	if (left < right)
	{
		int div = Quick(a, left, right);//«¯∑÷◊Û”“«¯º‰
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}

void Merge(int *a, int left, int div, int right)
{
	assert(a);
	int llen = div - left + 1;
	int rlen = right - div;
	int i = 0, j = 0, x = 0;
	int *l, *r;
	l = (int*)malloc(sizeof(int)*llen);
	r = (int*)malloc(sizeof(int)*rlen);
	for (i = 0; i < llen; i++)
		l[i] = a[left + i];
	for (i = 0; i < rlen; i++)
		r[i] = a[div + i + 1];
	i = 0;
	j = 0;
	while (i < llen && j < rlen)
	{
		if (l[i] <= r[j])
			a[left + x++] = l[i++];
		else
			a[left + x++] = r[j++];
	}
	while (i < llen)
		a[left + x++] = l[i++];
	while (j < rlen)
		a[left + x++] = r[j++];
}

void MergeSort(int *a, int left, int right)//πÈ≤¢≈≈–Ú
{
	assert(a);
	int div = left + ((right - left) >> 1);
	if (left < right)
	{
		MergeSort(a, left, div);
		MergeSort(a, div + 1, right);
		Merge(a, left, div, right);
	}
}

int main()
{
	int a[] = { 21, 25, 49, 25, 16, 8 };
	//int a[] = { 9, 17, 65, 23, 45, 78, 87, 53, 31 };
	//InsertSort(a, sizeof(a) / sizeof(a[0]));
	//ShellSort(a, sizeof(a) / sizeof(a[0]));
	//SelectSort(a, sizeof(a) / sizeof(a[0]));
	//HeapSort(a, sizeof(a) / sizeof(a[0]));
	//BubbleSort(a, sizeof(a) / sizeof(a[0]));
	//QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	MergeSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}