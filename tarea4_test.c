#include<stdio.h>
#include<stdlib.h>
#define bool int

struct sNode
{
	char data;
	struct sNode *next;
};


void push(struct sNode** top_, int newData);
int pop(struct sNode** top_);

bool matches(char char1, char char2)
{
	if (char1 == '(' && char2 == ')')
		return 1;
	else if (char1 == '{' && char2 == '}')
		return 1;
	else if (char1 == '[' && char2 == ']')
		return 1;
	else
		return 0;
}

bool balancedBrackets(char exp[])
{
	int i = 0;
	struct sNode *stack = NULL;
	while (exp[i])
	{
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			push(&stack, exp[i]);
		if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
		{
			if (stack == NULL)
				return 0;
			else if ( !matches(pop(&stack), exp[i]) )
				return 0;
		}
		i++;
	}
	if (stack == NULL)
		return 1;
	else
		return 0;
}


void push(struct sNode** top_, int newData)
{
	struct sNode* new_node =(struct sNode*) malloc(sizeof(struct sNode));
	if (new_node == NULL) exit(0);
	new_node->data  = newData;
	new_node->next = (*top_);
	(*top_)    = new_node;
}

int pop(struct sNode** top_)
{
	char data;
	struct sNode *top;

	if (*top_ == NULL) exit(0);
	else
	{
		top = *top_;
		data = top->data;
		*top_ = top->next;
		free(top);
		return data;
	}
}
int main()
{
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	char exp[100];
	printf("Expression: ");
	scanf("%s", exp);
	if (balancedBrackets(exp))
		printf("Balanced \n");
	else
		printf("Not Balanced \n");
	return 0;
}
