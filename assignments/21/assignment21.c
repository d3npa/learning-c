#include <stdio.h>
#include <string.h>

struct employee {
	int id;
	char first_name[16];
	char last_name[16];
	char title[32];
	int ssn_last4;
};

void read_employee(struct employee *emp) {
	printf("Employee ID: ");
	scanf("%d\n", &emp->id);

	printf("First name: ");
	scanf("%s\n", &emp->first_name);

	printf("Last name: ");
	scanf("%s\n", &emp->last_name);

	// Title can contain spaces, so opt for fgets over scanf
	printf("Title: ");
	fgets(emp->title, 32, stdin);
	emp->title[strcspn(emp->title, "\n")] = 0; // Remove the \n from fgets

	printf("Last 4 digits of SSN: ");
	scanf("%d\n", &emp->ssn_last4);
}

void print_employee(struct employee *emp) {
	printf("============================================\n");
	printf("Employee information for %s %s:\n", &emp->first_name, &emp->last_name);
	printf("Employee ID: %06d\n", emp->id);
	printf("SSN (Last 4 Digits): %04d\n", emp->ssn_last4);
	printf("Title: %s\n\n", &emp->title);
}

void main() {
	struct {
		// This really ought to be an array, not a struct...
		struct employee emp1;
		struct employee emp2;
	} registry;

	read_employee(&registry.emp1);
	read_employee(&registry.emp2);

	print_employee(&registry.emp1);
	print_employee(&registry.emp2);
}
