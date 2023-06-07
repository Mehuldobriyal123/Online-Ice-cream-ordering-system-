#include <stdio.h>
#include <string.h>
#define MAX_FLAVORS 10
typedef struct flavor {
char name[20];
int stock;
} Flavor;
Flavor flavors[MAX_FLAVORS];
int num_flavors = 0;
void add_flavor(char* name, int stock) {
if (num_flavors == MAX_FLAVORS) {
	printf("Maximum number of flavors reached.\n");
return;
}
for (int i = 0; i < num_flavors; i++) {
if (strcmp(flavors[i].name, name) == 0) {
printf("Flavor already exists.\n");
return;
}
}
Flavor new_flavor;
strcpy(new_flavor.name, name);
new_flavor.stock = stock;
flavors[num_flavors] = new_flavor;
num_flavors++;
printf("Flavor added successfully.\n");
}
void remove_flavor(char* name) {
for (int i = 0; i < num_flavors; i++) {
if (strcmp(flavors[i].name, name) == 0) {
for (int j = i; j < num_flavors - 1; j++) {
flavors[j] = flavors[j + 1];
}
num_flavors--;
printf("Flavor removed successfully.\n");
return;
}
}
printf("Flavor not found.\n");
}
void print_flavors() {
printf("Flavors available:\n");
for (int i = 0; i < num_flavors; i++) {
printf("%s - %d\n", flavors[i].name, flavors[i].stock);
}
}
int main() {
	int choice, stock;
	char name[20];
	do {
printf("\n1. Add flavor\n");
printf("2. Remove flavor\n");
printf("3. View available flavors\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter flavor name: ");
scanf("%s", name);
printf("Enter stock: ");
scanf("%d", &stock);
add_flavor(name, stock);
break;
case 2:
printf("Enter flavor name: ");
scanf("%s", name);
remove_flavor(name);
break;
case 3:
print_flavors();
break;
case 4:
printf("Exiting...\n");
break;
default:
printf("Invalid choice.\n");
break;
}
} while (choice != 4);
return 0;
}
