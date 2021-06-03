#include <iostream>
#include<string>
#include"Admin.h"
#include"Database.h"



int main()
{ 
    
        Database db;

        Name n("asd", "asdf ", " asfafa");
        Date d(2, 11, 2000);


    
        db.loadUsersFromFiles();
        db.loadClientBankAccs();
        db.loadClientCards();
        bool b;
        Employee e("asd", "dacx", "36782", n, d, "567", "ansdk asd");
        //e.deleteBankAcc(db.clients);
       e.createBankAcc("6543", 642.54, db.clients, b);
       //e.addNewCard("6543", "00MYBANK65432", db.clients, b);
       // e.deleteCard(db.clients);
       e.printClient("6543", db.clients);
        
       
    
}

