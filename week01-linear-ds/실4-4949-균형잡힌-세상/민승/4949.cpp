#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	while (true)
	{
		stack<char> open;
		string input = "";
		bool isBalanced = true;
		getline(cin, input);

		if (input == ".")
		{
			break;
		}

		for (char a : input)
		{
			if (a == '[' || a == '(')
			{
				open.push(a);
			} 
			else if (a == ']')
			{
				if (!open.empty() && open.top() == '[')
				{
					open.pop();
				}
				else 
				{
					isBalanced = false;
				}
			}
			else if (a == ')')
			{
				if (!open.empty() && open.top() == '(')
				{
					open.pop();
				}
				else
				{
					isBalanced = false;
				}
			}
		}
		if (isBalanced && open.empty())
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}