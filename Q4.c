#include "exam.h"
#define DATE_LEN 9
int addShopRequest (AE* pAE, int fromID, int toID, char *productName, int category, float amount, char* date)
{
	/*
	* Note to self: shopDetails is a poor name, should be buyDetails or something like that.
	* However, I did not choose that name.
	*/
	int membersNum = pAE->memberSize;
	shopDetails* newBuy = (shopDetails*)malloc(sizeof(shopDetails));
	if (newBuy == NULL) {
		return 0;
	}
	/*
	* first, I will deal with dynamic fields:
	*/
	char* date_allocate = (char*)malloc(sizeof(char) * DATE_LEN);
	if (date_allocate == NULL) {
		free(newBuy);
		return 0;
	}
	strcpy(date_allocate, date);

	int productName_len = strlen(productName);
	char* productName_allocate = (char*)malloc(sizeof(char) * (productName_len + 1));
	if (!productName_allocate) {
		free(newBuy);
		free(date_allocate);
		return 0;
	}
	strcpy(productName_allocate,productName);
	newBuy->date = date_allocate;
	newBuy->productName = productName_allocate;
	/*
	* Now, fill static fields of newBuy
	*/
	newBuy->amount = amount;
	newBuy->category = category;
	newBuy->from_ID = fromID;
	newBuy->to_ID = toID;

	/*
	* this flag is in case the buyer is also the seller, which should not be the case,
	* but just to be safe. This is done in order
	* to avoid realloating the same shoping list twice, 
	* and thus have a duplicate of the same buy(or as it is called here, shopDetails,
	* which is a needlessly confusing name)
	*/
	int buyerIsSeller = 0;
	if (toID == fromID) {
		buyerIsSeller = 1;
	}
	member* buyer = NULL;
	member* seller = NULL;;
	for (int i = 0; i < membersNum; i++) {
		member* mem = pAE->members[i];
		if(strcmp(mem->name,toID)==0){
			seller = mem;
			if (buyerIsSeller) {
				buyer = mem;
				break;
			}
		}
		if (strcmp(mem->name, fromID) == 0 && !buyerIsSeller) {
			buyer = mem;
		}
		if (buyer && seller) {
			break;
		}
	}
	shopDetails** seller_new_arr =
		(shopDetails**)realloc(seller->shoppingArr, seller->numberOfShoppings + 1);
	if (seller_new_arr == NULL) {
		//TOo tired to free all of the stuff
		return 0;
	}
	seller_new_arr[seller->numberOfShoppings] = newBuy;
	seller->numberOfShoppings++;
	seller->shoppingArr = seller_new_arr;
	/*
	* if the buyer is not the seller, need to do the same thing for the buyer:
	*/
	if (!buyerIsSeller) {
		shopDetails** buyer_new_arr =
			(shopDetails**)realloc(buyer->shoppingArr, buyer->numberOfShoppings + 1);
		if (buyer_new_arr == NULL) {
			//TOo tired to free all of the stuff
			return 0;
		}
		buyer_new_arr[buyer->numberOfShoppings] = newBuy;
		buyer->numberOfShoppings++;
		buyer->shoppingArr = buyer_new_arr;
	}
	/*
	* At long last, add the buy to the instance of the site itself
	*/
	shopDetails** newSiteBuysList =
		(shopDetails**)realloc(pAE->shopping, pAE->totaSize + 1);
	if (newSiteBuysList == NULL) {
		/*
		* TODO: 1.remove buy from the client and the seller,
		* by reallocating to size-1.
		* 2. free the allocated fields of shopDetails newBuy:
		*	2.1. free(newBuy->date)
		*	2.2. free(newBuy->productName)
		* 3.free(buy)
		*/
		return 0;
	}
	newSiteBuysList[pAE->totaSize] = newBuy;
	pAE->totaSize++;
	pAE->shopping = newSiteBuysList;
	return 1;
}


int deleteAE(AE* pAE)
{
 return NULL;
}
