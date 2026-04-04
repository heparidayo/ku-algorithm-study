#include <iostream>

int main()
{
	char input_string[101] = { 0 };
	int alphabet[26] = { 0 };

	std::cin >> input_string;

	int count = 0;

	while (input_string[count] != '\0')
	{
		alphabet[(int)input_string[count] - 'a']++;
		count++;
	}

	for (int i = 0; i < 26; i++)
	{
		std::cout << alphabet[i] << " ";
	}
};
