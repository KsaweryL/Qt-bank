#ifndef ADMIN_H
#define ADMIN_H

#include "customer.h"


class Admin: public Customer            //inheritance used
{
private:
    //int nrUsers;						//the number of users
   // Customer* user;
public:

    Admin()
    {
       // nrUsers = 10;						//the number of users should be stated upon creation of the member of this class
       // user = new Customer[nrUsers];

        //user[0].password = password;		//the password and the login are the same for both admin and user nr 0
        //user[0].login = login;
    }

};

#endif // ADMIN_H
