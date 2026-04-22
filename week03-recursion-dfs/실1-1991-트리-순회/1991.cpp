#include <iostream>

using namespace std;

struct Node
{
	char data;
	int left;
	int right;

	Node(char nodeData, int leftNode, int rightNode)
	{
		data = nodeData;
		left = leftNode;
		right = rightNode;
	}
};

Node* arr[26];

void preOrder(int n)
{
	if (arr[n] == nullptr) return;
	cout << arr[n]->data;
	preOrder(arr[n]->left);
	preOrder(arr[n]->right);
}

void inOrder(int n)
{
	if (arr[n] == nullptr) return;
	inOrder(arr[n]->left);
	cout << arr[n]->data;
	inOrder(arr[n]->right);
}

void postOrder(int n)
{
	if (arr[n] == nullptr) return;
	postOrder(arr[n]->left);
	postOrder(arr[n]->right);
	cout << arr[n]->data;
}

int main()
{
	int cnt; cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		int left = -1;
		int right = -1;

		char n, l, r; cin >> n >> l >> r;

		if (l != '.') left = l - 'A';
		if (r != '.')right = r - 'A';


		arr[n - 'A'] = new Node(n, left, right);
	}

	preOrder(0);
	cout << "\n";
	inOrder(0);
	cout << "\n";
	postOrder(0);
}