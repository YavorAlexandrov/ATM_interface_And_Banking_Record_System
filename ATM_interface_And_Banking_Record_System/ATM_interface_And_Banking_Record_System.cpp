#include <iostream>
#include<string>
#include"Admin.h"
#include"Database.h"



int main()
{ 
     Database db;
     
     Name n("asd", "asdf ", " asfafa");
     Date d(2,11,2000);
     
     Admin a("a", "b", "c", n, d, "d", "e");
     
     db.addAdmin(a);
    
     db.addEmployee(0);

    
    
}

