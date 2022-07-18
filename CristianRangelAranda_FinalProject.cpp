//Program Name: Final Project CSCI 202
//Author: Cristian Rangel Aranda
//Last Modfied: May 11,2022
//Due Date: May 11,2022



//Libraries used
#include <bits/stdc++.h>
#include <iostream>
#include<map>
#include<string>
#include<iterator>
#include<vector>
#include<stdio.h>
#include<time.h>

using namespace std;

//linked list node
struct Node{
float data;
struct Node* next;
};

//Function to insert a node at the beginning
void push(struct Node** head_ref, float new_data)
{
  //allocate node
  struct Node* new_node= new Node;

  //inserts data into the node
  new_node->data = new_data;

  //link the old list to the new node
  new_node->next =(*head_ref);

  //move head to point to the new node
  (*head_ref)=new_node;
}

//Fuction to find the sum of the nodes
void Total(struct Node* head, float* sum)
{
  if(!head)
  {
    return;
  }

  else
  {
    //recursively traverse the remaining nodes
    Total(head-> next, sum);

    //will add all the values into a total
    *sum=*sum+head-> data;
    
  }

  
}

//Function to find the sum
float TotalUtil(struct Node* head)
{
  float sum=0;

  //Will find the sum
  Total(head, &sum);

  //returns the value of sum
  return sum;
}

void fun()
{
    for (int i=0; i<10; i++)
    {
    }
}




int main() 
{
    
  try{

    //Check time complexity 
    time_t start, end;
    
    time(&start);

      // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
  
    fun();
  
    //Maps Variables 
    int found=0;
    string Phonenum2;

  
    //Linked list Varialbles
    struct Node*head = NULL;
    int Option=0;
    int accountchoice;
    int choice=0;
    int x=1;
    int y=2;

    //Item varialbes
    string ProductName;
    float Price;
    char proceed;

    //Reciept Variables 
    float BeforeTax;
    float AfterTax;
    float Tax;

    //Vector used for items name
    vector<string> Items;
 
    map<string,string> Account;
  
    Account.insert(pair<string,string>("123456789","Welcome back value customer!"));

    
    
    //Welcome screen for the user
    cout<<"Welcome to the FarmsMarket Self-Checkout"<<endl;
    cout<<"Do you have a account with us?"<<endl;
    cout<<"Enter '1' for Yes or enter '2' for no."<<endl;

    cin>>accountchoice;
    cout<<endl;

  //User Validation
    while(accountchoice !=x && accountchoice!=y)
      {
        cout<<"Sorry your input is invalid. Please try again"<<endl;
        cin>>accountchoice;
      }
   
   
    
    //This portion the user will enter their phone number to check for their account
    if(accountchoice==1)
    {
    
      //Enter 123456789 as your phonenumber to pull up account.
      cout<<"Great you have an account with us"<<endl;
      cout<<"Please enter your phone number to retrive your account."<<endl;
    
      cin>>Phonenum2;
      cout<<endl;
      
      //Iterator
      map<string,string>::iterator search;
  
      search=Account.find(Phonenum2);
  
        if(search==Account.end())
        {
          cout<<"Sorry you don't have an account with us."<<endl;
          cout<<endl;
          
          found=0;
        }

        else
        {
        cout<<search->second<<endl;
        found=1;
        cout<<endl;
        }

    }

    
    else 
    {
      int choice=0;
      string phonenum;
      cout<<"Will you like to create one? If you will like to create one enter '1' or enter '2' to not create one."<<endl;
      cin>>choice;
      if(choice==1)
      {
        cout<<"Great! Lets create one. All I would need is your phone number."<<endl;

        
        cin>>phonenum;

      
        Account.insert(pair<string,string>(phonenum,"Thanks for signing up!"));

        map<string,string>::iterator search;
  
      search=Account.find(phonenum);
  
        if(search==Account.end())
        {
          cout<<"Wasn't able to create an account at this moment sorry."<<endl;
          found=0;
        }

        else
        {
        cout<<search->second<<endl;
        found=1;
        cout<<endl;
        }
   
    
      
      }
  
    
    }

    
    //This section will be let the user enter the items they want to purchase. 
      
    cout<<"Please select from one of the following options"<<endl;

    int a=1;
    int b=2;
    
    cout<<"1-Start Transaction"<<endl;
    cout<<"2-End transaction"<<endl;
    cin>>Option;
    cout<<endl;

    //Input validation
     while(Option !=a && Option!=2)
      {
        cout<<"Sorry your input is invalid. Please try again"<<endl;
        cin>>Option;
      }
    
    if(Option==2)
    {
    //Throw to end transaction
    throw (2);
    }

    
    
    else

    //Example of input of product
      cout<<"Enter the product name of the item and then enter the price of the product."<<endl;
      cout<<"Example:"<<endl;
      cout<<"Product: Water "<<endl;
      cout<<"Product Price: 1.25"<<endl;
    cout<<endl;
     
      
    
    
   
    //items count
    int count=0;
      
    cout<<"How many items will you be purchasing?"<<endl;
    cin>>count;
    
  //User validation
 while(count<1)
      {
        cout<<"Sorry your input is invalid. Please try again"<<endl;
        cin>>count;
      }
    cout<<endl;


 
  //Will loop based on the value of count so the user can enter the name and price of each item. 
    for(int i=0;i<count;i++)
      {
          cout<<"Product Name: ";

          //User enters the product name
          cin>>ProductName;
          //Product name will be entered to the linked list
          Items.push_back(ProductName);
          
          cout<<"Product Price: ";
          //Product price
          cin>>Price;
          //Price gets entered into a vector
          push(&head,Price);

          
          
        }


    //Reciept Print out

    //Calculations for taxes to be included
      BeforeTax=TotalUtil(head);
      Tax=BeforeTax*0.07;
      AfterTax=BeforeTax+Tax;

    cout<<endl;
    cout<<endl;
    cout<<"FarmersMarket"<<endl;//Store name
    
    cout<<endl;
    cout<<"May 11, 2022"<<endl;//Date
    cout<<endl;
    cout<<"(123) 456-7891"<<endl;//Store Phonenumber
    cout<<endl;
    cout<<"***************"<<endl;//Seperation
    cout<<"Items: "<<endl;//Header
    cout<<endl;
    for (int i=0;i<count;i++)
      {
        cout<<Items[i]<<endl;
        cout<<endl;
      }
    //Mkes sure that values are printed to 2 decimal places
     cout<<setprecision(2)<<fixed;

    //Breaks down the total 
    cout<<"Subtotal: $ "<<TotalUtil(head)<<endl;//Subtotal
    cout<<"Tax: $"<<Tax<<endl;//Taxes from the subtotal
    cout<<"Total: $"<<AfterTax<<endl;//Subtotal + Tax
    cout<<endl;
    cout<<"Thank you for shopping at the Farmers Market."<<endl;
    cout<<endl;
    cout<<"Come Again Soon "<<endl;
    cout<<endl;
    //recording end time
    time(&end);
    
     // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
    
    
    
  }
  //Ends transaction
  catch(...)
    {
    cout<<"Your transaction has ended. Thank you!"<<endl;
    }

}
 


