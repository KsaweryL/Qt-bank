#ifndef ADMIN_H
#define ADMIN_H

#include "customer.h"


class Admin: public Customer            //inheritance used
{

public:

    Admin()
    {

    }

    void Banning(Customer client);

};

#endif // ADMIN_H
