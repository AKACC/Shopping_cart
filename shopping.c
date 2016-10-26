#include<stdio.h>

struct Item {
	int sku_;
	//float price_;
	int quantity_;
};
struct Price
{
	float price_;
};

int getSkunum() {
	int skunum;
	scanf("%d",&skunum);
	return skunum;
}
int getQuantity() {
	int quantity;
	scanf("%d", &quantity);
	return quantity;
}

float getPrice() {
	float price;
	scanf("%f", &price);
	return price;
}

int option() {   //options for user
	int input;
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add to shop.\n");
	printf("3) Price check.\n");
	printf("0) Exit.\n");
	printf("Select:");
	scanf("%d", &input);

	while (input < 0 || input > 3) {
		printf("Invalid input, try again: Please select from the following options:\n");
		printf("1) Display the inventory.\n");
		printf("2) Add to shop.\n");
		printf("3) Price check.\n");
		printf("0) Exit.\n");
		printf("Select:");
		scanf("%d", &input);
	}
	return input;
}

struct Item item(){
	struct Item it;
	printf("Please input a SKU number:");
	it.sku_ = getSkunum();
	printf("Quantity:");
	it.quantity_ = getQuantity();
	return it;
}
struct Price price(){
	struct Price itp;
	printf("Price:");
	itp.price_ = getPrice();
	return itp;
}
/*printf("Price:");
it.price_ = getPrice();
*/
//check
/*void check() {

}*/
int main(void) {
	int input;
	//int size = 40;
	struct Item it[40];
	struct Price itp[40];

	int i=0; //size
	int num;
	int chanum = 40 ;  //store matched index from changing
	int checknonum;
	int checkdfnum;//store matched index from checking
	int checknum;
	printf("Welcome to the Shop\n");
	printf("===================\n");
	input = option();

	do {
		while (input == 1)//Display the inventory.
		{
			printf("\n");
			printf("\n");
			printf("Inventory\n");//Display the inventory.
			printf("=========================================\n");
			printf("Sku         Price       Quanity\n");
			for (num = 0; num < i; num++) {
				printf("%d        %.2f       %d         \n", it[num].sku_, itp[num].price_, it[num].quantity_);
			}
			printf("=========================================\n");
			//option();
			input = option();

			//return input;
		}
		while(input == 3){//Price Check
			checknonum = 0;
			checkdfnum = 40;
			printf("Please input the sku number of the item:\n");
			checknum = getSkunum();
			for(num = 0; num < i; num++){
				if(checknum == it[num].sku_){
					printf("Item %d costs $%.2f\n", it[num].sku_, itp[num].price_);
					checkdfnum = num;
				}
				if(checknonum == 0 && checkdfnum == 40){
					if(checknum != it[num].sku_){
					printf("Item does not exist in the shop! Please try again.\n");
					checknonum++;

					}
				}

			}

			input = option();
		}


		while (input == 2) {
			int ic = i;
			int cnum = 0; //check repeated data

			it[ic] = item();

			if (ic == 0)
			{
				itp[ic] = price();
				it[i] = it[ic];//Add to the inventory.
				itp[i] = itp[ic];
				printf("The item is successfully added to the inventory.\n");
				i++;
			}
			else {
				while (cnum < ic) {

					if (it[ic].sku_ == it[cnum].sku_)
					{
						it[cnum].quantity_ += it[ic].quantity_; //update
						printf("The item exists in the repository, quanity is updated.\n");
						chanum = cnum;
					}
					cnum++;
				}

				if (chanum == 40 ) {
					itp[ic] = price();
					it[i] = it[ic];//Add to the inventory.
					itp[i] = itp[ic];
					printf("The item is successfully added to the inventory.\n");
					i++;
				}
			}
			//option();
			input = option();
		}
	}
	while (input != 0);

	printf("Good bye!\n");//Exit.



	return 0;
}
