#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "flags.h"
#include "product.h"

#include "library/libstr.h"
#include "library/menu.h"

#define SINGLE_MARGIN 50

/*
 * Prep a ProductList for use
 */
void InitializeProductList(ProductList *pProductList)
{
	if(!pProductList) return;

	pProductList->pSandwiches = NULL;
	pProductList->pSides      = NULL;
	pProductList->pBeverages  = NULL;
	pProductList->pCoupons    = NULL;
}

/*
 * File I/O
 */
void LoadProducts(ProductList *pProductList, char *sFileName)
{
	FILE    *pF;
	Product *pTmp;

	if(!pProductList) return;

/*	pF = fopen(sFileName, "r");
	if(pF)
	{
		// XXXX
	}
	else
*/	{
		pTmp = AddProduct(pProductList, "Hamburger", SANDWICH);
		AddSubProduct(pTmp, "Single", 2.29);
		AddSubProduct(pTmp, "Double", 2.89);
		AddSubProduct(pTmp, "Triple", 3.49);

		pTmp = AddProduct(pProductList, "Cheeseburger", SANDWICH);
		AddSubProduct(pTmp, "Single", 2.69);
		AddSubProduct(pTmp, "Double", 3.09);
		AddSubProduct(pTmp, "Triple", 3.79);

		pTmp = AddProduct(pProductList, "Bacon Cheeseburger", SANDWICH);
		AddSubProduct(pTmp, "Single", 3.19);
		AddSubProduct(pTmp, "Double", 3.59);
		AddSubProduct(pTmp, "Triple", 4.29);

		pTmp = AddProduct(pProductList, "Gardenburger", SANDWICH);
		AddSubProduct(pTmp, "Single", 2.89);
		AddSubProduct(pTmp, "Double", 3.49);
		AddSubProduct(pTmp, "Triple", 4.09);

		pTmp = AddProduct(pProductList, "French Fries", SIDE);
		AddSubProduct(pTmp, "Small",  1.19);
		AddSubProduct(pTmp, "Medium", 1.49);
		AddSubProduct(pTmp, "Large",  1.79);

		pTmp = AddProduct(pProductList, "Sweet Potato Fries", SIDE);
		AddSubProduct(pTmp, "Small",  1.29);
		AddSubProduct(pTmp, "Medium", 1.59);
		AddSubProduct(pTmp, "Large",  1.89);

		pTmp = AddProduct(pProductList, "Onion Rings", SIDE);
		AddSubProduct(pTmp, "Small",  1.39);
		AddSubProduct(pTmp, "Medium", 1.79);
		AddSubProduct(pTmp, "Large",  2.19);

		pTmp = AddProduct(pProductList, "Tater Tots", SIDE);
		AddSubProduct(pTmp, "Small",  1.29);
		AddSubProduct(pTmp, "Medium", 1.59);
		AddSubProduct(pTmp, "Large",  1.89);

		pTmp = AddProduct(pProductList, "Soda", BEVERAGE);
		AddSubProduct(pTmp, "Small",  2.09);
		AddSubProduct(pTmp, "Medium", 2.49);
		AddSubProduct(pTmp, "Large",  2.89);

		pTmp = AddProduct(pProductList, "Vanilla Milkshake", BEVERAGE);
		AddSubProduct(pTmp, "Small",  3.19);
		AddSubProduct(pTmp, "Medium", 3.89);
		AddSubProduct(pTmp, "Large",  4.59);

		pTmp = AddProduct(pProductList, "Chocolate Milkshake", BEVERAGE);
		AddSubProduct(pTmp, "Small",  3.19);
		AddSubProduct(pTmp, "Medium", 3.89);
		AddSubProduct(pTmp, "Large",  4.59);

		pTmp = AddProduct(pProductList, "Coffee", BEVERAGE);
		AddSubProduct(pTmp, "Small",  1.09);
		AddSubProduct(pTmp, "Medium", 1.39);
		AddSubProduct(pTmp, "Large",  1.69);

//		pTmp = AddProduct(pProductList, "First Visit", COUPON);
//		AddSubProduct(pTmp, "First Visit Discount", 0.05);
	}
}

void SaveProducts(ProductList *pProductList, char *sFileName)
{
	if(!pProductList) return;

	// XXXX
}

/*
 * List tidying
 */
void SortProducts(ProductList *pProductList)
{
	if(!pProductList) return;

	// XXXX
}

/*
 * Basic menu printing functions
 */
void DrawMenu        (ProductList *pProductList, ProductType eType)
{
	Product        *pCurP;
	SubProduct *pCurV;

	if(!pProductList) return;

	switch(eType)
	{
	case SANDWICH:
		printf("%*s%-50s  %-7s\n", SINGLE_MARGIN, "", "SANDWICHES", "PRICE");
		pCurP = pProductList->pSandwiches;
		break;
	case SIDE:
		printf("%*s%-50s  %-7s\n", SINGLE_MARGIN, "", "SIDES", "PRICE");
		pCurP = pProductList->pSides;
		break;
	case BEVERAGE:
		printf("%*s%-50s  %-7s\n", SINGLE_MARGIN, "", "BEVERGES", "PRICE");
		pCurP = pProductList->pBeverages;
		break;
	case COUPON:
		printf("%*s%-50s  %-7s\n", SINGLE_MARGIN, "", "COUPONS", "VALUE");
		pCurP = pProductList->pCoupons;
		break;
	}
	printf("%*s%-50s  %-7s\n", SINGLE_MARGIN, "", "--------------------", "-------");
	for( ; pCurP; pCurP = pCurP->pNext)
	{
		printf("%*s%-50s\n", SINGLE_MARGIN, "", pCurP->sName);
		for(pCurV = pCurP->pSubProducts; pCurV; pCurV = pCurV->pNext)
		{
			printf("%*s    %-46s  $3.2f\n", SINGLE_MARGIN, "", pCurV->sName, pCurV->fPrice);
		}
	}
}

void DrawSandwichMenu(ProductList *pProductList)
{
	if(!pProductList) return;

	DrawMenu(pProductList, SANDWICH);
}

void DrawSideMenu    (ProductList *pProductList)
{
	if(!pProductList) return;

	DrawMenu(pProductList, SIDE);
}

void DrawBeverageMenu(ProductList *pProductList)
{
	if(!pProductList) return;

	DrawMenu(pProductList, BEVERAGE);
}

void DrawCouponMenu  (ProductList *pProductList)
{
	if(!pProductList) return;

	DrawMenu(pProductList, COUPON);
}

/*
 * Main functions for interracting with program
 */
void DrawFullMenu    (ProductList *pProductList)
{
	if(!pProductList) return;

	// XXXX
}

ProductType     QueryProductType   (void)
{
	Menu myMenu;

	InitializeMenu(&myMenu, "", "Choose a product category:", 50, 4, MENU_STYLE_NUMERIC);
	AddMenuItem(&myMenu, "Sandwich", SANDWICH);
	AddMenuItem(&myMenu, "Side",     SIDE);
	AddMenuItem(&myMenu, "Beverage", BEVERAGE);

	return QueryMenu(&myMenu);
}

Product        *QueryProductByType (ProductList *pProductList, ProductType eType)
{
    int iSelection, i;
    Product *pRoot, *pCur;
    Menu myMenu;
    char *sTitle;

	if(!pProductList) return;

    switch(eType)
    {
    case SANDWICH:
        pRoot = pProductList->pSandwiches;
        sTitle = "Sandwiches";
        break;
    case SIDE:
        pRoot = pProductList->pSides;
        sTitle = "Sides";
        break;
    case BEVERAGE:
        pRoot = pProductList->pBeverages;
        sTitle = "Beverages";
        break;
    case COUPON:
        pRoot = pProductList->pCoupons;
        sTitle = "Coupons";
        break;
    }

    InitializeMenu(&myMenu, sTitle, "Which would you like?", 50, 4, MENU_STYLE_NUMERIC);
    for(i = 0, pCur = pRoot; pCur; i++, pCur = pCur->pNext)
        AddMenuItem(&myMenu, pCur->sName, i);

    iSelection = QueryMenu(&myMenu);
    for(i = 0, pCur = pRoot; i < iSelection; i++, pCur = pCur->pNext)
        ;

    return pCur;
}

SubProduct *QuerySubProduct(Product *pProduct)
{
    int i;
    SubProduct *pCur;
    Menu myMenu;

	if(!pProduct) return NULL;

	InitializeMenu(&myMenu, pProduct->sName, "Which size would you like?", 50, 4, MENU_STYLE_NUMERIC);
	for(i = 0, pCur = pProduct->pSubProducts; pCur; i++, pCur = pCur->pNext)
        AddMenuItem(&myMenu, pCur->sName, i);

    i = QueryMenu(&myMenu);
    for(pCur = pProduct->pSubProducts; i > 0; i--, pCur = pCur->pNext)
        ;

    return pCur;
}

/*
 * Product counts
 */
int GetProductCount   (ProductList *pProductList)
{
	if(!pProductList) return 0;

	return GetSandwichCount(pProductList) + GetSideCount(pProductList) + GetBeverageCount(pProductList);
}

int GetProductTypeCount(ProductList *pProductList, ProductType eType)
{
	int iCount = 0;
	Product *pCur;

	if(!pProductList) return;

	switch(eType)
	{
	case SANDWICH:
		pCur = pProductList->pSandwiches;
		break;
	case SIDE:
		pCur = pProductList->pSides;
		break;
	case BEVERAGE:
		pCur = pProductList->pBeverages;
		break;
	case COUPON:
		pCur = pProductList->pCoupons;
		break;
	default:
		return 0;
	}

	for( ; pCur; pCur = pCur->pNext)
		iCount++;

	return iCount;
}

int GetSandwichCount  (ProductList *pProductList)
{
	return GetProductTypeCount(pProductList, SANDWICH);
}

int GetSideCount      (ProductList *pProductList)
{
	return GetProductTypeCount(pProductList, SIDE);
}

int GetBeverageCount  (ProductList *pProductList)
{
	return GetProductTypeCount(pProductList, BEVERAGE);
}

int GetCouponCount    (ProductList *pProductList)
{
	return GetProductTypeCount(pProductList, COUPON);
}

int GetSubProductCount(Product *pProduct)
{
    int iCount = 0;
    SubProduct *pCur;

    if(!pProduct) return 0;

    for(pCur = pProduct->pSubProducts; pCur; pCur = pCur->pNext)
        iCount++;

    return iCount;
}

/*
 * Data Management Private Utility Functions
 */
void FreeProduct(Product *pProduct)
{
	SubProduct *pRip;

	if(!pProduct) return;

	while(pProduct->pSubProducts)
	{
		pRip = pProduct->pSubProducts;
		pProduct->pSubProducts = pProduct->pSubProducts->pNext;
		free(pRip->sName);
		free(pRip);
	}
	free(pProduct);
}

/*
 * Add Data
 */
Product *AddProduct    (ProductList *pProductList, char *sName, ProductType eType)
{
	Product *pCur;

	if(!pProductList) return NULL;

	if(pCur = FindProduct(pProductList, sName))
	{
		if(pCur->eType != eType)
			ChangeProductType(pCur, eType);
		return pCur;
	}

	switch(eType)
	{
	case SANDWICH:
		if(!pProductList->pSandwiches)
		{
			pProductList->pSandwiches = malloc(sizeof(Product));
			pCur = pProductList->pSandwiches;
		}
		else
		{
			for(pCur = pProductList->pSandwiches; pCur->pNext; pCur = pCur->pNext)
				;
			pCur->pNext = malloc(sizeof(Product));
			pCur = pCur->pNext;
		}
		break;
	case SIDE:
		if(!pProductList->pSides)
		{
			pProductList->pSides = malloc(sizeof(Product));
			pCur = pProductList->pSides;
		}
		else
		{
			for(pCur = pProductList->pSides; pCur->pNext; pCur = pCur->pNext)
				;
			pCur->pNext = malloc(sizeof(Product));
			pCur = pCur->pNext;
		}
		break;
	case BEVERAGE:
		if(!pProductList->pBeverages)
		{
			pProductList->pBeverages = malloc(sizeof(Product));
			pCur = pProductList->pBeverages;
		}
		else
		{
			for(pCur = pProductList->pBeverages; pCur->pNext; pCur = pCur->pNext)
				;
			pCur->pNext = malloc(sizeof(Product));
			pCur = pCur->pNext;
		}
		break;
	case COUPON:
		if(!pProductList->pCoupons)
		{
			pProductList->pCoupons = malloc(sizeof(Product));
			pCur = pProductList->pCoupons;
		}
		else
		{
			for(pCur = pProductList->pCoupons; pCur->pNext; pCur = pCur->pNext)
				;
			pCur->pNext = malloc(sizeof(Product));
			pCur = pCur->pNext;
		}
		break;
	default:
		return NULL;
	}
	pCur->sName = malloc(strlen(sName) + 1);
	strcpy(pCur->sName, sName);
	pCur->eType        = eType;
	pCur->pSubProducts = NULL;
	pCur->pNext        = NULL;
	pCur->pParent      = pProductList;

	return pCur;
}

void     AddSubProduct(Product *pProduct, char *sName, float fPrice)
{
	SubProduct *pCur;

	if(!pProduct) return;

	if(pCur = FindSubProduct(pProduct, sName))
	{
		pCur->fPrice = fPrice;
		return;
	}

	if(!pProduct->pSubProducts)
	{
		pProduct->pSubProducts = malloc(sizeof(SubProduct));
		pCur = pProduct->pSubProducts;
	}
	else
	{
		for(pCur = pProduct->pSubProducts; pCur->pNext; pCur = pCur->pNext)
			;
		pCur->pNext = malloc(sizeof(SubProduct));
		pCur = pCur->pNext;
	}
	pCur->sName = malloc(strlen(sName) + 1);
	strcpy(pCur->sName, sName);
	pCur->fPrice  = fPrice;
	pCur->pNext   = NULL;
	pCur->pParent = pProduct;
}

/*
 * Modify Products
 */
Product *FindProduct      (ProductList *pProductList, char *sName)
{
	Product *pCur;

	if(!pProductList) return NULL;

	for(pCur = pProductList->pSandwiches; pCur; pCur = pCur->pNext)
	{
		if(strcmp(sName, pCur->sName) == 0)
			return pCur;
	}

	for(pCur = pProductList->pSides; pCur; pCur = pCur->pNext)
	{
		if(strcmp(sName, pCur->sName) == 0)
			return pCur;
	}

	for(pCur = pProductList->pBeverages; pCur; pCur = pCur->pNext)
	{
		if(strcmp(sName, pCur->sName) == 0)
			return pCur;
	}

	for(pCur = pProductList->pCoupons; pCur; pCur = pCur->pNext)
	{
		if(strcmp(sName, pCur->sName) == 0)
			return pCur;
	}

	return NULL;
}

void     RemoveProduct    (Product *pProduct)
{
	Product *pPre;

	if(!pProduct) return;

	switch(pProduct->eType)
	{
	case SANDWICH:
		if(pProduct->pParent->pSandwiches == pProduct)
		{
			pPre = pProduct->pParent->pSandwiches;
			pProduct->pParent->pSandwiches = pPre->pNext;
			FreeProduct(pPre);
			return;
		}
		pPre = pProduct->pParent->pSandwiches;
		break;
	case SIDE:
		if(pProduct->pParent->pSides == pProduct)
		{
			pPre = pProduct->pParent->pSides;
			pProduct->pParent->pSides = pPre->pNext;
			FreeProduct(pPre);
			return;
		}
		pPre = pProduct->pParent->pSides;
		break;
	case BEVERAGE:
		if(pProduct->pParent->pBeverages == pProduct)
		{
			pPre = pProduct->pParent->pBeverages;
			pProduct->pParent->pBeverages = pPre->pNext;
			FreeProduct(pPre);
			return;
		}
		pPre = pProduct->pParent->pBeverages;
		break;
	case COUPON:
		if(pProduct->pParent->pCoupons == pProduct)
		{
			pPre = pProduct->pParent->pCoupons;
			pProduct->pParent->pCoupons = pPre->pNext;
			FreeProduct(pPre);
			return;
		}
		pPre = pProduct->pParent->pCoupons;
		break;
	default:
		return;
	}
	for( ; pPre->pNext != pProduct; pPre = pPre->pNext)
		;
	pPre->pNext = pProduct->pNext;
	FreeProduct(pProduct);
}

void     ChangeProductName(Product *pProduct, char *sName)
{
	if(!pProduct) return;

	free(pProduct->sName);
	pProduct->sName = malloc(strlen(sName) + 1);
	strcpy(pProduct->sName, sName);
}

void     ChangeProductType(Product *pProduct, ProductType eType)
{
	Product    *pNewProduct;
	SubProduct *pCurVariant;

	if(!pProduct) return;

	if(pProduct->eType == eType) return;

	pNewProduct = AddProduct(pProduct->pParent, "AAAAAABBBBBBCCCCCCDDDDDDEEEEEE", eType);
	ChangeProductName(pNewProduct, pProduct->sName);
	for(pCurVariant = pProduct->pSubProducts; pCurVariant; pCurVariant = pCurVariant->pNext)
	{
		AddSubProduct(pNewProduct, pCurVariant->sName, pCurVariant->fPrice);
	}
	RemoveProduct(pProduct);
}

/*
 * Modify SubProduct
 */
SubProduct *FindSubProduct       (Product *pProduct, char *sName)
{
	SubProduct *pCur;

	if(!pProduct) return NULL;

	for(pCur = pProduct->pSubProducts; pCur; pCur = pCur->pNext)
	{
		if(strcmp(sName, pCur->sName) == 0)
			return pCur;
	}

	return NULL;
}

void        RemoveSubProduct     (SubProduct *pSubProduct)
{
	SubProduct *pPre;

	if(!pSubProduct) return;

	if(pSubProduct->pParent->pSubProducts == pSubProduct)
	{
		pSubProduct->pParent->pSubProducts = pSubProduct->pNext;
		free(pSubProduct->sName);
		free(pSubProduct);
	}
	else
	{
		for(pPre = pSubProduct->pParent->pSubProducts; pPre->pNext != pSubProduct; pPre = pPre->pNext)
			;
		pPre->pNext = pSubProduct->pNext;
		free(pSubProduct->sName);
		free(pSubProduct);
	}
}

void        ChangeSubProductName (SubProduct *pSubProduct, char *sName)
{
	if(!pSubProduct) return;

	free(pSubProduct->sName);
	pSubProduct->sName = malloc(strlen(sName) + 1);
	strcpy(pSubProduct->sName, sName);
}

void        ChangeSubProductPrice(SubProduct *pSubProduct, float fPrice)
{
	if(!pSubProduct) return;

	pSubProduct->fPrice = fPrice;
}
