#include <iostream>
#include <string>

using namespace std;
int main()
{
	string input;
	getline(std::cin, input);

	int dot_pos = -1;
	int start_pos = -1;
	int end_pos = -1;

	int temp_start_pos = -1;
	int state = 0;

	for(int i = 0; i < input.length(); i++)
	{
		char c = input[i];

		switch(state) 
		{
			case 0: 
				if ('+' == c || '-' == c)
				{
					state = 1;
					temp_start_pos = i;
				}
				else if (c >= '0' && c <= '9')
				{
					state = 2;
					temp_start_pos = i;
				}
				break;

			case 1:
				if ('+' == c || '-' == c)
				{
					state = 1;
					temp_start_pos = i;
				}
				else 
				{
					if (c >= '0' && c <= '9') 
					{
						state = 2;
					}
					else 
					{
						state = 0;
					}
				}

				break;

			case 2: 
				if (c >= '0' && c <= '9')
					break;
				else 
				{
					if ( '.' == c )
					{
						state = 3;
						dot_pos = i;
					}
					else 
					{
						if ('+' == c || '-' == c)
						{
							state = 1;
							temp_start_pos = i;
						}
						else {
							state = 0;
						}
					}
				}

				break;

			case 3:
				if (c >= '0' && c <= '9')
				{
					state = 4;
				}
				else
				{
					if ('+' == c || '-' == c)
					{
						state = 1;
						temp_start_pos = i;
					}
					else {
						state = 0;
					}
				}
				break;
			case 4:
				if (c >= '0' && c <= '9')
				{
					break;
				}
				else {
					if ('+' == c || '-' == c)
					{
						state = 1;
						temp_start_pos = i;
					}
					else if ('.' == c) 
					{
						temp_start_pos = dot_pos  + 1;
						dot_pos = i;
						state = 3;
					}
					else
					{
						state = 0;
					}
				}
				break;
		}

		if (state == 4 || state == 2)
		{
			if (i + 1 - temp_start_pos >= end_pos - start_pos)
			{
				start_pos = temp_start_pos;
				end_pos = i + 1;
			}
		}
	}


    if (end_pos > start_pos)
	{
		printf("%s\n", input.substr(start_pos, end_pos - start_pos).c_str());
	}
	else
	{
		printf("\n");
	}
}

