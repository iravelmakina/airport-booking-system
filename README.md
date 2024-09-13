### Description:
- Implemented core functionality for the airflight booking system, including booking, unbooking, seat availability checking, and viewing information.

### Changes:
- `Ticket.cpp`: 
  - Implemented the `Ticket` class for representing individual bookings.

- `Airplane.cpp`: 
  - Added methods for booking, unbooking, checking seat availability and viewing information about bookings.
  - Implemented price retrieval based on seat row.
  - Added helpers for seat index/ID conversion.

- `Registry.cpp`: 
  - Added methods to store and retrieve airplane and ticket data.
  - Linked airplane objects with corresponding flights and managed ticket records for users.

- `CommandPerformer.cpp`: 
  - Added logic for booking, unbooking, and viewing tickets.
  - Integrated with `Registry` to manage ticket data and airplane objects.

- `CLI.cpp`: 
  - Implemented a command-line interface for interacting with the booking system.
  - Added commands for checking availability, booking tickets, returning tickets, and viewing booked tickets.

- `FileReader.cpp`: 
  - Implemented configuration file parsing to load flight data, including seat pricing and availability.

### How to Test:
1. Initialize the system by providing a valid configuration file (`Config.txt`).
2. Test the `check` command:
   - Enter a valid date and flight number.
   - Ensure the system returns available seats with corresponding prices.
3. Test the `book` command:
   - Enter valid flight details and seat information.
   - Ensure the seat is booked and returns a valid ticket ID.
4. Test the `return` command:
   - Enter a valid ticket ID.
   - Ensure the seat is unbooked and available again.
5. Test the `view id` command:
   - Enter a valid ticket ID.
   - Ensure the system displays correct ticket information (flight, seat, price).
6. Test the `view user` command:
   - Enter a valid username.
   - Ensure the system returns all booked tickets for that user.
7. Test the `view flight` command:
   - Enter valid flight details.
   - Ensure all booked seats are shown with user details.
   
  ### Program structure
  
<img width="1484" alt="Screenshot 2024-09-13 at 15 02 15" src="https://github.com/user-attachments/assets/20e0f7e6-1152-4392-aead-99a57a279ab5">
