#include <stdio.h>
#include <stdlib.h>

void interface();
void seetodo();
void createtodo();
void deletetodo();
void adjustcount();



struct ToDo {
	char Data[100];
    struct ToDO * next;
	int count;
};

struct ToDo * start = NULL;

int main()
{
	int choice;
	interface();

	while (1) {


		system("cls");

		printf("1. To see your ToDo list\n");
		printf("2. To create new ToDo\n");
		printf("3. To delete your ToDo\n");
		printf("4. Exit");
		printf("\n\n\nEnter your choice\t:\t");

		scanf("%d", &choice);

		switch (choice) {
		case 1:
			seetodo();
			break;
		case 2:
			createtodo();
			break;
		case 3:
			deletetodo();
			break;
		case 4:
			exit(1);
			break;
		default:
			printf("\nInvalid Choice :-(\n");
			system("pause");
		}
	}
	return 0;
}


void interface()
{
	system("cls");
	printf("------------------------------------------------------------- \n");
	printf("--------------------WELCOME TO TO-DO LIST-------------------- \n");
	printf("------------------------------------------------------------- \n");

	system("pause");
}

// To view all the todos
void seetodo()
{
	system("cls");

	struct ToDo *temp;

	// temp is made to point the start of linked list
	temp = start;

	// Condition for empty linked list
	if (start == NULL)
		printf("\n\nEmpty ToDo \n\n");

	// Traverse until last node
	while (temp != NULL) {

		printf("%d)", temp->count);

		// Print data of the node
		puts(temp->Data);

		// Clear output console
		fflush(stdin);

		// Going to next node
		temp = temp->next;
	}

	printf("\n\n\n");
	system("pause");
}

// Function to insert a node todo
void createtodo()
{
	// Choose choice from user
	char c;

	// Pointers to node
	struct ToDo *add, *temp;
	system("cls");

	while (1) {

		printf("\nWant to add new ToDo ?? Press 'y' for Yes and 'n' for No :-)\n\t\t");
		fflush(stdin);

		// Input from user
		scanf("%c", &c);

		if (c == 'n' || c == 'N')
			break;
		else {

			// If start node is NULL
			if (start == NULL) {

				add = (struct ToDo*)calloc(1, sizeof(struct ToDo));

				// Using add pointer to
				// create linked list
				start = add;
				printf("\nType it: \n");

				// Input from user
				fflush(stdin);
				gets(add->Data);
				add->count = 1;

				start->next = NULL;
			}
			else {
				temp = (struct ToDo*)calloc(1, sizeof(struct ToDo));
				printf("\nType it: \n");
				fflush(stdin);
				gets(temp->Data);

				// Insertion is at last
				// so pointer part is NULL
				temp->next = NULL;

				// add is now pointing
				// newly created node
				add->next = temp;
				add = add->next;
			}

			adjustcount();
		}
	}
}

// Function to delete the todo
void deletetodo()
{
	system("cls");

	int x;

	struct ToDo *del, *temp;
	printf("\nEnter the ToDo's number that you want to remove.\n\t\t");

	if (start == NULL)
		printf("\n\nThere is no ToDo for today :-)\n\n\n");
	else {
		scanf("%d", &x);

		del = start;
		temp = start->next;

		// Running infinite loop so
		// that user can delete and
		// asked again for choice
		while (1) {

			// When the values matches,
			// delete the node
			if (del->count == x) {

				// When the node to be
				// deleted is first node
				start = start->next;

				// Deallocating the memory
				// of the deleted node
				free(del);

				// Adjusting the count when
				// node is deleted
				adjustcount();
				break;
			}

			if (temp->count == x) {
				del->next = temp->next;
				free(temp);
				adjustcount();
				break;
			}
			else {
				del = temp;
				temp = temp->next;
			}
		}
	}
	system("pause");
}

// Function to adjust the numbering
// of the nodes
void adjustcount()
{
	// For traversal, using
	// a node pointer
	struct ToDo * temp;
	int i = 1;
	temp = start;

	// Running loop until last node
	// and numbering it one by one
	while (temp != NULL) {
		temp->count = i;
		i++;
		temp = temp->next;
	}
}
