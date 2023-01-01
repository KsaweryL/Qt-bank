#include "admin.h"

void Admin::Banning(Customer client)
{
    client.ban_status = 1;
}
