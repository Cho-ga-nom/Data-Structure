#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {                  
	long long key;                          
	struct Node* link;
} List;

int totalNode(List* node)
{
	int count = 0;

	while (node->link != NULL)
	{
		count++;
		node = node->link;
	}

	return count;
}

int sameNumber(long long num, List* head)
{
	List* temp = head;

	if (temp->link == NULL)
	{
		if (temp->key == num)
			return 1;
		else
			return 2;
	}

	while (temp->link != NULL)
	{
		if (temp->key == num)
			return 1;

		temp = temp->link;
	}

	return 2;
}

int main()
{
	List* head = malloc(sizeof(List*));
	head->link = NULL;
	List* temp = head;

	FILE * fp = NULL;
	fp = fopen("input.txt", "r");
	long long num;
	int samenum;
	int overnum = 0;

	while (!feof(fp))
	{
		fscanf(fp,"%lld", &num);
		if (num > 5000)
			overnum++;

		if (head->link == NULL)
		{
			List* node = (List*)malloc(sizeof(List*));
			node->key = num;
			node->link = NULL;
			head->link = node;
		}
		else
		{
			samenum = sameNumber(num, head->link);

			if (samenum == 1)
				continue;
			else if (samenum == 2)
			{
				while (temp->link != NULL)
				{
					temp = temp->link;
				}

				List* node = (List*)malloc(sizeof(List*));
				node->key = num;
				node->link = NULL;
				temp->link = node;
			}
		}  
	}

	fclose(fp);
	printf("The total number of nodes: %d\n", totalNode(head->link));
	printf("More than 5000 values: %d\n", overnum);

	return 0;
}