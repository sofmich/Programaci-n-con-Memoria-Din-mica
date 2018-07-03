#include <stdio.h>
#include <ctype.h>
#include <assert.h>

typedef enum {true, false} boolean;

void outEspace(char *Descomp, char *Comp);
void initStack();
boolean push(char Elem);
int desempilha(char *Elem);
int hasHigherPriority(char Operator);
int Priority(char Exp[], int position);
int InfixtoPostfix(char exp[], char expPost[]);

#define MAX 100
char stack[MAX];
int top;


int main(void) {
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	char Exp[MAX];
	char Exp_outEspace[MAX] = {0};
	char expPost[MAX] = {0};
	int indexicator = 0;

	printf("\nExpression: ");
	fgets(Exp, MAX, stdin);
	outEspace(Exp, Exp_outEspace);

	indexicator = InfixtoPostfix(Exp_outEspace, expPost);
	puts(expPost);
	return indexicator;
}

void outEspace(char *Descomp, char *Comp) {
	int i = 0;
	int j = 0;

	while ( *(Descomp+j) ) {
		if ( !isspace(*(Descomp+j)) ) {
			*(Comp+(i++)) = Descomp[j];
		}
		j++;
	}
}

void initStack() {
	top = -1;
}

boolean push(char Elem) {
	if (top == MAX - 1)         /* Stack is full */
		return false;
	stack[++top] = Elem;
	return true;
}

boolean pop(char *Elem) {
	if (top == -1)              /* stack is empty */
		return false;
	*Elem = stack[top--];
	return true;
}

int hasHigherPriority(char Operator) {
	switch (Operator) {
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '^':
		return 3;
	case '(':
		return 4;
	case ')':
		return 5;
	default:
		return 0;
	}
}

int Priority(char Exp[], int position) {
	if ( hasHigherPriority(Exp[position]) == 1 ) {
		if ( (position == 0) ||
				((hasHigherPriority(Exp[position - 1]) >= 1) &&
						(hasHigherPriority(Exp[position - 1]) <= 3)) ) {
			return 1;
		} else {
			return 2;
		}
	} else if ( (hasHigherPriority(Exp[position]) > 1) &&
			(hasHigherPriority(Exp[position]) <= 3) ) {
		return 2;
	} else {
		return hasHigherPriority(Exp[position]);
	}
}

int InfixtoPostfix(char exp[], char expPost[]) {
	int i = 0, j = 0, index = 0;
	char aux = ' ';
	initStack();
	while ( exp[i] ) {
		if ( Priority(exp, i) == 0 ) {
			expPost[j++] = exp[i];
		} else if ( Priority(exp, i) == 1 ) {
			switch (exp[i]) {
			case '-':
			expPost[j++] = exp[i];
			break;
			case '+':
				aux = expPost[i];
				break;
			default:
				assert(0);
			}
		} else if (Priority(exp, i) == 2) {
			while ( (top != -1) &&
					(hasHigherPriority(stack[top]) >= hasHigherPriority(exp[i])) &&
					stack[top] != '(' ) {
				index = pop(&expPost[j++]);
			}
			index = push(exp[i]);
		} else if ( hasHigherPriority(exp[i]) == 4 ) {
			index = push(exp[i]);
		} else if ( hasHigherPriority(exp[i]) == 5 ) {
			while ( (top != -1) && (stack[top] != '(') ) {
				index = pop(&expPost[j++]);
			}
			if ( (top != - 1) && stack[top] == '(') {
				index = pop(&aux);
			}
		}
		i++;
	}

	while (top != -1) {
		index = pop(&expPost[j++]);
	}

	return index;
}
