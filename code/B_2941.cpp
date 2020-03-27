#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>

using namespace std;

int main() {
	char arr[101];

	scanf("%s", arr);

	int count = 0;

	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == 'c')
		{
			if (arr[i + 1] == '=' || arr[i + 1] == '-')
				i = i + 1;
		}
		else if (arr[i] == 'd')
		{
			if (arr[i + 1] == 'z' && arr[i + 2] == '=')
				i = i + 2;
			else if (arr[i + 1] == '-')
				i = i + 1;
		}
		else if (arr[i] == 'l' || arr[i] == 'n')
		{
			if (arr[i + 1] == 'j')
				i = i + 1;
		}
		else if (arr[i] == 's' || arr[i] == 'z')
		{
			if (arr[i + 1] == '=')
				i = i + 1;
		}

		count++;
	}

	cout << count << endl;

}