#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Flight {
    public:
        bool reserveSeats[30];
        string source, destination, ticketClass, name, seatNo;
        int count, countB, countE;

        Flight() {}

        Flight(string src, string des) {
            for (int i = 0; i < 30; ++i)
                reserveSeats[i] = false;
            source = src;
            destination = des;
            count = 0;
            countB = 0;
            countE = 0;
        }

        void bookTicket(string src, string des, int i) {
            if (count < 30) {
                cout << "1. Book a ticket for Business Class\n2. Book a ticket for Economic Class" << endl;
                int cls;
                cin >> cls;

                if (cls == 1) {
                    ticketClass = "Business";
                    cout << "Passenger Name: ";
                    cin.ignore();
                    getline(cin, name);

                    while (countB < 15) {
                        reserveSeats[countB] = true;
                        seatNo = "ARS1705200" + to_string(i);
                        count++;
                        countB++;
                        break;
                    }
                }
                else if (cls == 2) {
                    ticketClass = "Economic";
                    cout << "Passenger Name: ";
                    cin.ignore();
                    getline(cin, name);

                    while (countE < 15) {
                        reserveSeats[countE] = true;
                        seatNo = "ARS1705200" + to_string(i);
                        count++;
                        countE++;
                        break;
                    }
                }

                cout << "Your ticket has been booked successfully for journey " << src << " to " << des
                     << " of " << ticketClass << " class.\nThank You for using Online Airline Reservation System." << endl;
            }
            else {
                cout << "Sorry, reservations are full. Cannot book your ticket now." << endl;
            }
        }

        int ticketPrice(string src, string des) {
            int price = 0;

            if (source == "Mumbai" && destination == "Chennai" && ticketClass == "Business")
                price += 4000;
            else if (source == "Mumbai" && destination == "Chennai" && ticketClass == "Economic")
                price += 3000;
            else if (source == "Mumbai" && destination == "Delhi" && ticketClass == "Economic")
                price += 4000;
            else if (source == "Mumbai" && destination == "Delhi" && ticketClass == "Business")
                price += 5000;
            else if (source == "Mumbai" && destination == "Goa" && ticketClass == "Business")
                price += 5500;
            else if (source == "Mumbai" && destination == "Goa" && ticketClass == "Economic")
                price += 4500;

            return price;
        }

        static void displayTicket(Flight f, int i) {
            cout << "\nYour Booking Details are as follow:\n"
                 << "_________________________________________________________________\n\n"
                 << "*****************************************************************\n"
                 << "...AIR INDIA...\n"
                 << "Flight: " << f.source << " ---> " << f.destination << "\n"
                 << "Name: " << f.name << "\n"
                 << "Seat Number: ARS1705200" << i << "\n"
                 << "Class: " << f.ticketClass << "\n"
                 << "Expense: " << f.ticketPrice(f.source, f.destination) << "\n"
                 << "HAPPY JOURNEY.......\n"
                 << "*****************************************************************\n"
                 << "_________________________________________________________________\n";
        }

        void checkTicketAvailability() {
            int choice;
            cout << "1. Check Business Class ticket availability\n"
                 << "2. Check Economic class ticket availability\n"
                 << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << (15 - countB) << " tickets available." << endl;
            }
            else if (choice == 2) {
                cout << (15 - countE) << " tickets available." << endl;
            }
        }

        void cancelTicket(string sitnum) {
            for (int i = 0; i < count; ++i) {
                if (sitnum == ("ARS1705200" + to_string(i))) {
                    reserveSeats[i] = false;
                    cout << "Your booking has been cancelled." << endl;
                    break;
                }
            }
        }
};

int main() {
    vector<Flight> MTC, MTD, MTG;
    int choice, ans;
    int i = 0, j = 5, k = 10;

    Flight flight1("Mumbai", "Chennai");
    Flight flight2("Mumbai", "Delhi");
    Flight flight3("Mumbai", "Goa");

    do {
        cout << "\n********************AIR INDIA********************\n"
             << "1. Book a Ticket\n"
             << "2. View Ticket Availability\n"
             << "3. Cancel Booking\n"
             << "4. Check all bookings of a flight\n"
             << "Please select one: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int sol;
                do {
                    cout << "Welcome to our online reservation System...\n"
                         << "Booking is going on for these flights:\n"
                         << "1. Mumbai to Chennai\n2. Mumbai to Delhi\n3. Mumbai to Goa\n"
                         << "Enter your choice: ";
                    int ch;
                    cin >> ch;

                    if (ch == 1) {
                        flight1.bookTicket(flight1.source, flight1.destination, i);
                        Flight::displayTicket(flight1, i);
                        MTC.push_back(flight1);
                        i++;
                    }
                    else if (ch == 2) {
                        flight2.bookTicket(flight2.source, flight2.destination, j);
                        Flight::displayTicket(flight2, j);
                        MTD.push_back(flight2);
                        j++;
                    }
                    else if (ch == 3) {
                        flight3.bookTicket(flight3.source, flight3.destination, k);
                        Flight::displayTicket(flight3, k);
                        MTG.push_back(flight3);
                        k++;
                    }
                    cout << "Do you want to book more tickets? Press 1 to book another one: ";
                    cin >> sol;
                } while (sol == 1);
                break;
            }

            case 2: {
                int cont, ch;
                do {
                    cout << "Check ticket availability for flights:\n"
                         << "1. Mumbai to Chennai\n2. Mumbai to Delhi\n3. Mumbai to Goa\n"
                         << "Enter your choice: ";
                    cin >> ch;

                    if (ch == 1)
                        flight1.checkTicketAvailability();
                    else if (ch == 2)
                        flight2.checkTicketAvailability();
                    else if (ch == 3)
                        flight3.checkTicketAvailability();

                    cout << "Press 1 to check available tickets for other flights: ";
                    cin >> cont;
                } while (cont == 1);
                break;
            }

            case 3: {
                int contd;
                do {
                    cout << "Cancel Booking for:\n"
                         << "1. Mumbai to Chennai\n2. Mumbai to Delhi\n3. Mumbai to Goa\n"
                         << "Please choose the flight for cancellation: ";
                    int choose;
                    cin >> choose;
                    string sitnum;

                    if (choose == 1) {
                        cout << "Enter Seat Number: ";
                        cin >> sitnum;
                        for (int f = 0; f < MTC.size(); ++f) {
                            if (sitnum == MTC[f].seatNo) {
                                MTC.erase(MTC.begin() + f);
                                break;
                            }
                        }
                        flight1.cancelTicket(sitnum);
                    }
                    else if (choose == 2) {
                        cout << "Enter Seat Number: ";
                        cin >> sitnum;
                        for (int f = 0; f < MTD.size(); ++f) {
                            if (sitnum == MTD[f].seatNo) {
                                MTD.erase(MTD.begin() + f);
                                break;
                            }
                        }
                        flight2.cancelTicket(sitnum);
                    }
                    else if (choose == 3) {
                        cout << "Enter Seat Number: ";
                        cin >> sitnum;
                        for (int f = 0; f < MTG.size(); ++f) {
                            if (sitnum == MTG[f].seatNo) {
                                MTG.erase(MTG.begin() + f);
                                break;
                            }
                        }
                        flight3.cancelTicket(sitnum);
                    }

                    cout << "Press 1 to continue the cancellation: ";
                    cin >> contd;
                } while (contd == 1);
                break;
            }

            case 4: {
                int ans1;
                do {
                    cout << "Check bookings of flight:\n"
                         << "1. Mumbai to Chennai\n2. Mumbai to Delhi\n3. Mumbai to Goa\n"
                         << "Your choice: ";
                    int ch;
                    cin >> ch;

                    if (ch == 1) {
                        for (Flight f : MTC) {
                            cout << "Departure: " << f.source << "\nDestination: " << f.destination
                                 << "\nClass: " << f.ticketClass << "\nPassenger Name: " << f.name
                                 << "\nSeat Number: " << f.seatNo << "\nTicket Price: "
                                 << f.ticketPrice(f.source, f.destination) << "\n_______________________\n";
                        }
                    }
                    else if (ch == 2) {
                        for (Flight f : MTD) {
                            cout << "Departure: " << f.source << "\nDestination: " << f.destination
                                 << "\nClass: " << f.ticketClass << "\nPassenger Name: " << f.name
                                 << "\nSeat Number: " << f.seatNo << "\nTicket Price: "
                                 << f.ticketPrice(f.source, f.destination) << "\n_______________________\n";
                        }
                    }
                    else if (ch == 3) {
                        for (Flight f : MTG) {
                            cout << "Departure: " << f.source << "\nDestination: " << f.destination
                                 << "\nClass: " << f.ticketClass << "\nPassenger Name: " << f.name
                                 << "\nSeat Number: " << f.seatNo << "\nTicket Price: "
                                 << f.ticketPrice(f.source, f.destination) << "\n_______________________\n";
                        }
                    }

                    cout << "Press 1 to check bookings of other flights: ";
                    cin >> ans1;
                } while (ans1 == 1);
                break;
            }

            default:
                break;
        }

        cout << "Press 1 to continue: ";
        cin >> ans;
    } while (ans == 1);

    return 0;
}
