#include "admin.h"

void Admin::Banning(Customer client)
{
    client.Change("1", "ban_status");
}

