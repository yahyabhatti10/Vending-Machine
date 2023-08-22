#include <iostream>
using namespace std;

class VendingMachine   
{
	private: 
		int laysQ;
		int laysP;
		int cokeQ;
		int cokeP;
		int oreoQ;
		int oreoP;
		int balance;
		int choiceShop;
		int choiceFood;
		int choiceQuantity;
		
		
	public:
		VendingMachine() 
		{
			laysQ = 10;
			cokeQ = 10;
			oreoQ = 10;
			laysP = 50;
			cokeP = 80;
			oreoP = 20;
		} 
		
		void setLaysQ(int l)
		{
			laysQ = l;
		} 
		void setCokeQ(int c)
		{
			cokeQ = c;
		} 
		void setOreoQ(int o)
		{
			oreoQ = o;
		} 
		
		void setLaysP(int l)
		{
			laysP = l;
		} 
		void setCokeP(int c)
		{
			cokeP = c;
		} 
		void setOreoP(int o)
		{
			oreoP = o;
		} 
		
		void stockDisplay() 
		{
			cout<<"                                ---WELCOME TO UMT FOOD FACTORY---"<<endl;
			cout<<"The Stock of Food Items we have in the Machine is as under : "<<endl;
			cout<<"1.Lays : "<<laysQ<<" Pieces"<<endl;
			cout<<"2.Coke : "<<cokeQ<<" Pieces"<<endl;
			cout<<"3.Oreo : "<<oreoQ<<" Pieces"<<endl;
		}  
		
		void setChoiceShop() 
		{
			cout<<"\nDo you want to Shop Food?"<<endl;
			cout<<"1.Yes"<<endl;
			cout<<"2.No"<<endl;
			cout<<"Enter the Desired Option : ";
			cin>>choiceShop;
		} 
		
		int	getChoiceShop() 
		{
			return choiceShop;
		} 
		
		void setBalance() 
		{
			
			cout<<"\n                                         -Cash Deposit-"<<endl;
			cout<<"Enter the Balance : Rs.";
			cin>>balance;
		} 
		
		int getBalance() 
		{
			return balance;
		} 
				
		void priceDisplay() 
		{
			cout<<"\n                                          -Price Chart-"<<endl;
			cout<<"1.Lays = Rs."<<laysP<<" (per piece)"<<endl;
			cout<<"2.Coke = Rs."<<cokeP<<" (per piece)"<<endl;
			cout<<"3.Oreo = Rs."<<oreoP<<" (per piece)"<<endl;
		} 
		
		void setChoiceFood() 
		{
			cout<<"\n                                          -Food Order-"<<endl;
			cout<<"Enter the Food Item you want to buy : ";
			cin>>choiceFood;
		} 
		
		int getChoiceFood() 
		{
			return choiceFood;
		} 
		
		void setChoiceQuantity() 
		{
			cout<<"Enter the Quantity of Item : ";
			cin>>choiceQuantity;
		} 
		
		int getChoiceQuantity() 
		{
			return choiceQuantity;
		} 
		int calculateBill() 
		{
			if(choiceFood==1) 
			{ 
				return laysP * choiceQuantity;
			} 
			else if(choiceFood==2) 
			{ 
				return cokeP * choiceQuantity;
			} 
			else 
			{ 
				return oreoP * choiceQuantity;
			} 
			
		} 
		
		void programRun()
		{
			int choiceShop, choiceFood, quantityFood,totalBill,newBalance;
			
			do	
			{
				stockDisplay();
				if(laysQ==0 && cokeQ==0 && oreoQ==0)
				{
					cout<<"\nSorry,we are out of stock."<<endl;
					break;
				}
				choiceException:
					setChoiceShop();
					choiceShop = getChoiceShop();
					
				if(choiceShop==2) 
				{
					cout<<"\n                   -Thank You for shopping from UMT FOOD FACTORY. Have a nice day-"<<endl;
					break;
				} 
				else if(choiceShop>2 || choiceShop<1)
				{
					cout<<"\nInvalid Input!!!\nPlease Enter the Correct Input to proceed."<<endl;
					goto choiceException;
				} 
				
				
  				setBalance(); 
				priceDisplay(); 
 				
				quantityException:	
					setChoiceFood(); 
					choiceFood = getChoiceFood(); 
					if(choiceFood>3 || choiceFood<1)
					{
						cout<<"\nInvalid Input!!!\nPlease Enter the Valid Food Item Number."<<endl;
						goto quantityException;
					}
						
					setChoiceQuantity(); 
					quantityFood = getChoiceQuantity(); 
					
					if(choiceFood==1)
					{
						if(laysQ>0&&quantityFood>laysQ)
						{
							cout<<"\nWe have a Limited Stock here. \nPlease Enter the quantity meansetting Stock of Food Items."<<endl;
							goto quantityException;
						} 
						else if(laysQ==0)
						{
							cout<<"\nSorry, Lays is out of stock. Please Select Something Else."<<endl;
							goto quantityException;
						} 
					} 
					else if(choiceFood==2)
					{
						if(cokeQ>0&&quantityFood>cokeQ)
						{
							cout<<"\nWe have a Limited Stock here. \nPlease Enter the quantity meansetting Stock of Food Items."<<endl;
							goto quantityException;
						} 
						else if(cokeQ==0)
						{
							cout<<"\nSorry, Coke is out of stock. Please Select Something Else."<<endl;
							goto quantityException;
						} 
					} 
					else if(choiceFood==3)
					{
						if(oreoQ>0&&quantityFood>oreoQ)
						{
							cout<<"\nWe have a Limited Stock here. \nPlease Enter the quantity meansetting Stock of Food Items."<<endl;
							goto quantityException;
						} 
						else if(oreoQ==0)
						{
							cout<<"\nSorry, Oreo is out of stock. Please Select Something Else."<<endl;
							goto quantityException;
						} 
					} 
					totalBill = calculateBill(); 
					
				balanceException:	
					if(totalBill<=balance)
					{
						
						if(choiceFood==1) 
						{ 
							cout<<"                                         -Food Delivery-"<<endl;
							cout<<"Item Selected.\nFood Item : Lays\nQuantity : "<<quantityFood<<endl; 
							cout<<"\nTotal Bill : "<<laysP<<" x "<<quantityFood<<" = Rs."<<totalBill<<endl; 
							laysQ = laysQ-quantityFood;
						} 
						else if(choiceFood==2)
						{ 
							cout<<"                                         -Food Delivery-"<<endl;
							cout<<"Item Selected.\nFood Item : Coke\nQuantity : "<<quantityFood<<endl;
							cout<<"\nTotal Bill : "<<cokeP<<" x "<<quantityFood<<" = Rs."<<totalBill<<endl; 
							cokeQ = cokeQ-quantityFood;
						} 
						else if(choiceFood==3) 
						{ 
							cout<<"                                         -Food Delivery-"<<endl;
							cout<<"Item Selected.\nFood Item : Oreo\nQuantity : "<<quantityFood<<endl;
							cout<<"\nTotal Bill : "<<oreoP<<" x "<<quantityFood<<" = Rs."<<totalBill<<endl; 
							oreoQ = oreoQ-quantityFood;
						} 
							
						balance = balance - totalBill;
						cout<<"Remaining Balance : Rs."<<balance<<endl;
						cout<<"\nThank You for Purchasing. Transaction Successfully Done.\nCollect your remaining amount and Recieve your order from the Product Delivery Door."<<endl;
						cout<<endl<<endl<<endl<<endl;
							
					} 
		
					else 
					{
						cout<<"                                         -Bill Payments-"<<endl;
						cout<<"\nYour Balance amount is lower than Total Bill."<<endl;
						cout<<"Total Bill : Rs."<<totalBill<<endl;
						cout<<"Balance : Rs."<<balance<<endl;
						cout<<"Due Amount : Rs."<<totalBill-balance<<endl;
					    cout<<"Enter the Due Amount to Proceed : Rs.";
					    cin>>newBalance;
					    balance = newBalance + balance;
					    goto balanceException;
					} 
	
			} 
				while(choiceShop==1);
	    } 
}; 

int main()
{
	VendingMachine v1; 
	v1.programRun(); 
	
	return 0;
} 
