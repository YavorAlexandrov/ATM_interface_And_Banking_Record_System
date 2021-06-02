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
        bool b;
        Employee e("asd", "dacx", "36782", n, d, "567", "ansdk asd");
       
        e.createBankAcc("6543", 3241, db.clients, b);
        //db.addClient(0);
    
}

