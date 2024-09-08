#include <iostream>
#include "Airplane.h"
#include "Ticket.h"

int main() {
    Ticket ticket(1, "JohnDoe", "2023-10-01", "FL123", "12A", 200, false);
    ticket.book();
    return 0;
}
