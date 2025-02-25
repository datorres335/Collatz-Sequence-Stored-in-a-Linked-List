#include<iostream>
using namespace std;

struct collatzNode
{
	int item;
	collatzNode* link;
};

int main()
{	
	int userNum;
	cout << "Enter a number less than 100: ";
	cin >> userNum;

	int temp = userNum;
	int largestNum = userNum;
	int counterLargest = 0;
	int counterNow = 0;

	collatzNode* head = new collatzNode;
	head->item = userNum;
	collatzNode* firstNode = head;
	collatzNode* secNode = new collatzNode;
	secNode->link = nullptr;
	head->link = secNode;

	for (int i = userNum; i > 1; i--)
	{
		while (temp != 1)
		{
			if (temp % 2 == 0)
			{
				temp = temp / 2;
			}
			else
			{
				temp = temp * 3 + 1;
			}
			secNode->item = temp;
			if (temp == 1) break;
			firstNode = secNode;
			secNode->link = new collatzNode;
			secNode = secNode->link;
			secNode->link = nullptr;
			counterNow++;
		}
		if (counterNow > counterLargest)
		{
			counterLargest = counterNow;
			largestNum = i;
		}
		else //delete current linked list
		{
			firstNode = head;
			secNode = head;
			head = head->link;
			delete firstNode;
			firstNode = nullptr;
			secNode = nullptr;

			while (head != nullptr)
			{
				collatzNode* deleteNode;
				deleteNode = head;
				head = head->link;
				delete deleteNode;
				deleteNode = nullptr;
			}
			delete head;
			head = nullptr;
		}
	}

	secNode = head;

	while (secNode != nullptr)
	{
		cout << secNode->item;
		if (secNode->item != 1) cout << ", ";
		secNode = secNode->link;
	}

	return 0;
}