#include <iostream>
#include<string>
#include"Admin.h"
#include"Database.h"



int main()
{ 
    
        Database db;

        Name n("asd", "asdf ", " asfafa");
        Date d(2, 11, 2000);

        Admin a("a", "b", "c", n, d, "d", "e");

        //db.addAdmin(a);
        db.loadUsersFromFiles();
    

        //db.deleteEmployee(0);
      //db.printEmployees();
    
       // db.addEmployee(0);


  
        while (1) {
            int a;
            std::cin >> a;
            if (a == 1) {
                db.addEmployee(0);
            }
            else if (a == 2) {
                db.deleteEmployee(0);
            }
    }
    
}

