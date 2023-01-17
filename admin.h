#ifndef ADMIN_H
#define ADMIN_H

#include "customer.h"


class Admin: public Customer            //inheritance used
{

public:

    void Additional_options(Customer &client, string option, string input);

};

#endif // ADMIN_H
