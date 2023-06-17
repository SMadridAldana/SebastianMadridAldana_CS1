#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int counter = 0;
	while(head != NULL){
		head = head->next;
		counter ++;
	}
	return counter;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int stringLenght = length(head);
	int counter = 0;
	char *pMyString = (char*) malloc(sizeof(char)*(stringLenght+1));
	char *pTemp = pMyString;

	while(head != NULL){
		pMyString[counter] = head->letter;
		counter ++;
		head = head->next;
	}

	pMyString[counter] = '\0';
	return pTemp;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node *pNewNode = (node *) malloc(sizeof(node));
	if(pNewNode == NULL) printf("Memory Allocation Failed");
	else{
		pNewNode->letter = c;
		pNewNode->next = NULL;
		if( *pHead == NULL) *pHead = pNewNode;
		else{
			node * pTemp = *pHead;
			while(pTemp->next != NULL) pTemp = pTemp->next;
			pTemp->next = pNewNode;
		}

	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node * pTempA = *pHead;
	*pHead = NULL;

	while(pTempA != NULL){
		node * pTempB = pTempA;
		pTempA = pTempB->next;
		free(pTempB);
	}
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}