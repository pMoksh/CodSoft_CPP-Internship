//CODSOFT C++ Programming
//Moksh Pohoja
//Dr. Akhilesh Das Gupta Institute of Technology
//Task 5 Movie Ticket Booking System

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 5;    // Number of rows in the theater
const int NUM_COLS = 10;   // Number of seats per row

class Movie {
public:
    Movie(const string& title, int availableSeats)
        : title(title), availableSeats(availableSeats) {}

    const string& getTitle() const {
        return title;
    }

    int getAvailableSeats() const {
        return availableSeats;
    }

    void decreaseAvailableSeats(int numSeats) {
        availableSeats -= numSeats;
    }

private:
    string title;
    int availableSeats;
};

class BookingSystem {
public:
    BookingSystem(const vector<Movie>& initialMovies)
        : movies(initialMovies), selectedMovieIndex(-1), selectedNumSeats(-1) {
        initializeSeatingChart();
    }

    void displayMovieList() const {
        cout << "Movie Listings:\n";
        for (size_t i = 0; i < movies.size(); ++i) {
            cout << i + 1 << ". " << movies[i].getTitle() << " (" << movies[i].getAvailableSeats() << " seats available)\n";
        }
        cout << endl;
    }

    void selectMovie() {
        int movieIndex;
        cout << "Enter the index of the movie you want to watch: ";
        cin >> movieIndex;

        if (movieIndex > 0 && static_cast<size_t>(movieIndex) <= movies.size()) {
            selectedMovieIndex = movieIndex - 1;
            cout << "You selected: " << movies[selectedMovieIndex].getTitle() << endl;
        } else {
            cout << "Invalid movie selection.\n";
        }
    }

    void displaySeatingChart() const {
        cout << "  ";
        for (int i = 1; i <= NUM_COLS; i++) {
            cout << setw(2) << i;
        }
        cout << "\n";

        for (int row = 0; row < NUM_ROWS; row++) {
            cout << static_cast<char>('A' + row) << " ";
            for (int col = 0; col < NUM_COLS; col++) {
                cout << seatingChart[row][col] << " ";
            }
            cout << "\n";
        }
    }

    void selectSeats() {
        int numSeats;
        cout << "Enter the number of seats you want to book: ";
        cin >> numSeats;

        if (numSeats > 0 && numSeats <= movies[selectedMovieIndex].getAvailableSeats()) {
            cout << "Enter the seats you want to book (e.g., A1, B2): ";
            bookSeats(numSeats);
        } else {
            cout << "Invalid number of seats or not enough available seats.\n";
        }
    }

    void makeBooking() {
        if (selectedMovieIndex != -1 && selectedNumSeats != -1) {
            movies[selectedMovieIndex].decreaseAvailableSeats(selectedNumSeats);
            cout << "Booking successful! Enjoy the movie.\n";
            displayReceipt();
            resetSelections();
        } else {
            cout << "Invalid booking. Please select a movie and seats first.\n";
        }
    }

private:
    vector<Movie> movies;
    int selectedMovieIndex;
    int selectedNumSeats;
    vector<vector<char>> seatingChart;

    void initializeSeatingChart() {
        seatingChart = vector<vector<char>>(NUM_ROWS, vector<char>(NUM_COLS, '-'));
    }

    void bookSeats(int numSeats) {
        int bookedCount = 0;

        while (bookedCount < numSeats) {
            string seat;
            cin >> seat;

            if (seat.length() != 2) {
                cout << "Invalid seat format. Use a letter and a number (e.g., A1): ";
                continue;
            }

            int row = seat[0] - 'A';
            int col = seat[1] - '1';

            if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) {
                cout << "Invalid seat. Please select a valid seat: ";
                continue;
            }

            if (seatingChart[row][col] == 'X') {
                cout << "Seat " << seat << " is already booked. Please choose another seat: ";
                continue;
            }

            seatingChart[row][col] = 'X';
            bookedCount++;
        }

        selectedNumSeats = bookedCount;
    }

    void displayReceipt() const {
        const Movie& selectedMovie = movies[selectedMovieIndex];
        int totalCost = selectedNumSeats * 10; // Assuming each seat costs $10

        cout << "\nReceipt:\n";
        cout << "Movie: " << selectedMovie.getTitle() << "\n";
        cout << "Number of seats: " << selectedNumSeats << "\n";
        cout << "Total cost: $" << totalCost << "\n\n";
    }

    void resetSelections() {
        selectedMovieIndex = -1;
        selectedNumSeats = -1;
    }
};

int main() {
    vector<Movie> movieList = {
        Movie("Inception", 30),
        Movie("The Dark Knight", 25),
        Movie("The Shawshank Redemption", 20)
    };

    BookingSystem bookingSystem(movieList);

    int choice;

    do {
        cout << "Movie Ticket Booking System\n";
        cout << "1. View Movie Listings\n";
        cout << "2. Select Movie\n";
        cout << "3. Display Seating Chart\n";
        cout << "4. Select Seats\n";
        cout << "5. Make Booking\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookingSystem.displayMovieList();
                break;
            case 2:
                bookingSystem.selectMovie();
                break;
            case 3:
                bookingSystem.displaySeatingChart();
                break;
            case 4:
                bookingSystem.selectSeats();
                break;
            case 5:
                bookingSystem.makeBooking();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}
