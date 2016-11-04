/*/*
== #2  shopping ==

Author	: Zixian Ou
Date	: Nov 3rd 2016
Student Number: 125421164
Matrix Account: zou2
Seneca Email: zou2@myseneca.ca
Workshop: #7 at-home

*/
#include <stdio.h>

#define MAX_ITEMS 10
struct Item {
	int _sku;
	float _price;
   int _quantity;
};

void welcome(){
	printf("Welcome to the Shop\n");
	printf("===================\n");
}
void displayInventory(const struct Item items[],const int size);
void clear();
int validate(const int low, const int high);

void displayInventory(const struct Item items[],const int size);
int searchInventory(const struct Item items[],const int sku_item,const int size);
void addItem(struct Item items[], int *size);
void menu();
void checkPrice(const struct Item items[],const int size);



int main(){
	struct Item item[MAX_ITEMS]; //An array of Item representing the inventory
	//struct Item* Pitem;
	//Pitem = item;
	int size=0; //Number of items in the inventory. The inventory is initially empty.
	int user_enter;
	int blankspace;
	for(blankspace = 0; blankspace < 20; blankspace++){
		printf("\n");
	}
	welcome();
	do{
	menu();
	user_enter = validate(0,4);
	switch(user_enter){
		case 0://exit
			break;

		case 1://display
			displayInventory(item,size);
			break;

		case 2:
			addItem(item, &size);
			break;

		case 3:
			checkPrice(item, size);
			break;

		case 4:
			clear();
			break;

		}
	}while(user_enter != 0);
	printf("Goodbye!\n");
   return 0;
}


//Functions
void menu(){
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Clear Screen.\n");
	printf("0) Exit.\n");

}

int validate(const int low, const int high){
	int enterNum;
	int getvalid = 0;


	printf("Select: ");

	do{
		scanf("%d", &enterNum);
	if(enterNum < low || enterNum > high){
		printf("Invalid input, try again: ");
	}else{
		getvalid = 1;
	}
	}while(getvalid != 1);
	return enterNum;
}

void clear(){
	int i;
	for(i = 0; i<=40; i++){
	printf("\n");
	}
}

void displayInventory(const struct Item items[],const int size){
	int i;

	printf("\n\nInventory\n");
	printf("=========================================\n");
	printf("Sku         Price       Quantity\n");
	for(i = 0; i < size; i++){
		printf("%4d        %-5.2f       %-10d\n", items[i]._sku, items[i]._price, items[i]._quantity);
	}
	printf("=========================================\n");
}

int searchInventory(const struct Item items[],const int sku_item,const int size){
	int i;
	int found_item = 0;
	int found;

	for(i = 0; i < size ; i++){
		if(sku_item == items[i]._sku){
			found_item = 1;
			found = i;
		}
	}
	if(found_item != 1){
		found = -1;
	}
	return found;
}

void addItem(struct Item items[], int *size){
	int sku_item;
	int found;
	int addQuantity = 0;

	printf("Please input a SKU number: ");
	scanf("%d", &sku_item);
	found = searchInventory(items, sku_item, *size);
	if(found == -1){
		if(*size == MAX_ITEMS){
			printf("the inventory is full.\n");
			//full = 1;
		}else{
		items[*size]._sku = sku_item;
		printf("Quantity: ");
		scanf("%d", &items[*size]._quantity);
		printf("Price: ");
		scanf("%f", &items[*size]._price);
		*size += 1;
		printf("The item is successfully added to the inventory.\n");
		}

	}else{
		printf("Quantity: ");
		scanf("%d", &addQuantity);
		items[found]._quantity += addQuantity;
		printf("The item exists in the repository, quantity is updated.\n");
	}
}
void checkPrice(const struct Item items[],const int size){
	int sku_item;
	int found;
	printf("Please input the sku number of the item: ");
	scanf("%d", &sku_item);
	found = searchInventory(items, sku_item, size);
	if(found == -1){
		printf("Item does not exist in the shop! Please try again.\n");
	}else{
		printf("Item %d costs $%.2f\n", items[found]._sku, items[found]._price);
	}
}
/* output:




















Welcome to the Shop
===================
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 5
Invalid input, try again: 2
Please input a SKU number: 1234
Quantity: 2
Price: 45.63
The item is successfully added to the inventory.
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 2
Please input a SKU number: 9010
Quantity: 5
Price: 23.50
The item is successfully added to the inventory.
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 2
Please input a SKU number: 1234
Quantity: 5
The item exists in the repository, quantity is updated.
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 1


Inventory
=========================================
Sku         Price       Quantity
1234        45.63       7
9010        23.50       5
=========================================
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 0
Goodbye!
*/


