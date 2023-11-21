ReservaByte:	main.o Date.o Time.o Patron.o PatronArray.o Reservation.o Restaurant.o RsvList.o Table.o Control.o View.o 
	g++ -o ReservaByte main.o Date.o Time.o Patron.o PatronArray.o Reservation.o RsvList.o Restaurant.o Table.o Control.o View.o

main.o:	main.cc defs.h
	g++ -c main.cc

Patron.o:	Patron.cc Patron.h
	g++ -c Patron.cc

PatronArray.o:	PatronArray.cc PatronArray.h
	g++ -c PatronArray.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Time.o:	Time.cc Time.h
	g++ -c Time.cc

RsvList.o:	RsvList.cc RsvList.h
	g++ -c RsvList.cc

Reservation.o:	Reservation.cc Reservation.h
	g++ -c Reservation.cc

Restaurant.o:	Restaurant.cc Restaurant.h
	g++ -c Restaurant.cc

Table.o:	Table.cc Table.h
	g++ -c Table.cc

Control.o:	Control.cc Control.h 
	g++ -c Control.cc

View.o:	View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o restaurant_reservation
