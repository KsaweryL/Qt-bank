#include "admin.h"

void Admin::Additional_options(Customer &client, string option, string input)
{
    if(option == "banning") client.Change("1", "ban_status");               //banning and unbanning
    if(option == "unbanning") client.Change("0", "ban_status");

    if(option == "change_the_name") client.Change(input, "name");
    if(option == "change_the_surname")  client.Change(input, "surname");

    if(option == "change_the_login") client.Change(input, "login");
    if(option == "change_the_password")  client.Change(input, "password");
}

