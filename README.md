# ReservaByte
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

## Overview
ReservaByte is a C++ program developed to manage restaurant reservations efficiently. The system utilizes dynamically allocated linked lists and arrays to optimize memory usage and improve the management of tables and customers. The code design emphasizes modularity and structure, promoting code maintainability and reusability.

## Screenshots

## Features
**Dynamic Memory Allocation:** Utilizes dynamically allocated linked lists and arrays for efficient memory usage.

**Table Management:** Effectively manages tables and customers, ensuring a seamless reservation experience.

**Error Handling:** Implements error handling to prevent double-booking of the same table during the same time.

## How to set up and run the application: 
Make sure you have a C++ compiler installed on your system.
1. Clone the repository and make sure you are in that directory:
```
https://github.com/Maiku3/ReservaByte.git

```
2. Compile the program with the make file
```
make
```
3. Run the application:
```
./ReservaByte
```

## Usage
First it preloads some reservations and patrons, which include cases that show all the types of error checks it does.
<img width="529" alt="Screenshot 2023-11-21 at 9 43 03 AM" src="https://github.com/Maiku3/ReservaByte/assets/95307563/9beb6d14-aaed-4b72-ad9f-7ddc30728955">

### The Menu
<img width="510" alt="Screenshot 2023-11-14 at 9 51 31 PM" src="https://github.com/Maiku3/Restaurant-Reservation/assets/95307563/2e3f595e-03f6-4cfa-b21c-52049b015ce1">

#### Option (1) Print reservation schedule
Type in 1 to print all the reservations. <br>
<img width="416" alt="Screenshot 2023-11-14 at 9 51 49 PM" src="https://github.com/Maiku3/Restaurant-Reservation/assets/95307563/11be7194-6bf7-4950-8daf-c0c48223020d">

#### Option (2) Print day schedule
Type in 2 to print all the reservations on that day. <br>
<img width="463" alt="Screenshot 2023-11-14 at 9 52 18 PM" src="https://github.com/Maiku3/ReservaByte/assets/95307563/23be0236-44bf-47de-a1b3-8461b0a5f3ce">

#### Option (3) Print patrons
Type in 3 to print all the patrons. <br>
<img width="448" alt="Screenshot 2023-11-14 at 9 52 57 PM" src="https://github.com/Maiku3/ReservaByte/assets/95307563/c2202628-db92-4906-8d29-f03f594809a7">

#### Option (4) Reserve a table
Type in 4 to reserve a table for a certain time. It will prompt you for the date and time information. <br>
<img width="390" alt="Screenshot 2023-11-21 at 10 19 15 AM" src="https://github.com/Maiku3/ReservaByte/assets/95307563/c1932ed0-a732-4e1c-bcae-c966051ec72b">

## Potential Improvements
- Consider adding a graphical user interface for a more user-friendly experience.

- Integrate a database to store reservation information persistently.

- Explore adding features like reservation reminders

- Add options to input name or phone number instead of ID, and if the patron does not exist it adds them
