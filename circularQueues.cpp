/**
 * @mainpage Documentation circular Queues
 * 
 * @section Introduction
 * This project from structur data
 * this project use structur data queues, implements circular arrays
 * 
 * @section Operations
 * - en queue for insert elements into queues
 * - de queue for delete elements from queues
 * - show data / display
 * 
 * @section How to use
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 4. Exit
 * 
 * @author yProfile
 * - Nama   : Tasya Maulida Putri
 * - NIM    : 20240140239
 * - Kelas  : E
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */

#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief This Class is for operation queues
 * 
 */
 

class Queues {
private:
    int FRONT; /// private variable front for indicate first element
    int REAR; /// private variable rear for indicate the last element
    int max = 5; /// private variable max for maximum capasity of element
    int queue_array[5]; /// private variable queue_array to store element

public:
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method for entering data into a queue
     * This method will prompt the user to input a number.
     * If the queue is not full, the number will be added to the queue.
     * If the queue is full, a "Queue overflow" message will be displayed.
     */
    void insert() {
        int num; /// Declare variable 'num' to store user input
        cout << "Enter a number: "; /// Prompt the user to enter a number
        cin >> num; /// Read input from the user and store it in 'num'
        cout << endl; /// Print a new line for better output formatting

        // Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        // Cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }
        else {
            // Jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max -1)
            REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }
    
    /**
     * @brief Remove an element from the queue.
     * This method will remove the front element of the queue.
     * If the queue is empty, a "Queue underflow" message will be displayed.
     */
    void remove() {
        // Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        // Cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }
        else {
            // jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max -1)
            FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    /**
     * @brief Display the elements of the queue
     * This method will show all current elements in the queue.
     * If the queue is empty, a "Queue is empty" message will be displayed.
     */
    void display() {
        int FRONT_position = FRONT; /// Create a local variable 'FRONT_position' to temporarily store the current FRONT index
        int REAR_position = REAR; /// Create a local variable 'REAR_position' to temporarily store the current REAR index

        // Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements is the queue are...\n";

        // Jika FRONT_position <= RAER_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            // jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max -1) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }

            FRONT_position = 0;

            // Iterasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
    }

};


/**
 * @brief Main function for running the circular queue program.
 * This function provides a menu to the user to perform queue operations.
 * Options include insert, delete, display, and exit.
 * 
 * @return int Returns 0 upon successful program termination.
 */
int main()
{
    Queues q;
    char ch;

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implementasi insert operation" << endl;
            cout << "2. Implementasi delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;  

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
               
        
    }
}