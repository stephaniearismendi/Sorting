#include "./include/selection.hpp"
#include "./include/radix.hpp"
#include "./include/shell.hpp"
#include "./include/heap.hpp"
#include "./include/quick.hpp"
#include "./include/ordenacion.hpp"
#include <unistd.h>

#define MAX_NUM 9999
#define MIN_NUM 1000

int main()
{
    using key = int;
    Sort<key> *selection;
    bool exit = false;
    while (exit == false)
    {
        std::cout << "                                                                                                                                            " << std::endl;
        std::cout << "  /$$$$$$  /$$$$$$ /$$$$$$$ /$$$$$$$$/$$$$$$/$$   /$$ /$$$$$$        /$$      /$$/$$$$$$$$/$$$$$$$$/$$   /$$ /$$$$$$ /$$$$$$$  /$$$$$$ " << std::endl;
        std::cout << " /$$__  $$/$$__  $| $$__  $|__  $$__|_  $$_| $$$ | $$/$$__  $$      | $$$    /$$| $$_____|__  $$__| $$  | $$/$$__  $| $$__  $$/$$__  $$" << std::endl;
        std::cout << "| $$  \\__| $$  \\ $| $$  \\ $$  | $$    | $$ | $$$$| $| $$  \\__/      | $$$$  /$$$| $$        | $$  | $$  | $| $$  \\ $| $$  \\ $| $$  \\__/" << std::endl;
        std::cout << "|  $$$$$$| $$  | $| $$$$$$$/  | $$    | $$ | $$ $$ $| $$ /$$$$      | $$ $$/$$ $| $$$$$     | $$  | $$$$$$$| $$  | $| $$  | $|  $$$$$$ " << std::endl;
        std::cout << " \\____  $| $$  | $| $$__  $$  | $$    | $$ | $$  $$$| $$|_  $$      | $$  $$$| $| $$__/     | $$  | $$__  $| $$  | $| $$  | $$\\____  $$" << std::endl;
        std::cout << " /$$  \\ $| $$  | $| $$  \\ $$  | $$    | $$ | $$\\  $$| $$  \\ $$      | $$\\  $ | $| $$        | $$  | $$  | $| $$  | $| $$  | $$/$$  \\ $$" << std::endl;
        std::cout << "|  $$$$$$|  $$$$$$| $$  | $$  | $$   /$$$$$| $$ \\  $|  $$$$$$/      | $$ \\/  | $| $$$$$$$$  | $$  | $$  | $|  $$$$$$| $$$$$$$|  $$$$$$/" << std::endl;
        std::cout << " \\______/ \\______/|__/  |__/  |__/  |______|__/  \\__/\\______/       |__/     |__|________/  |__/  |__/  |__/\\______/|_______/ \\______/ " << std::endl;
        std::cout << "                                                                                                                                            " << std::endl;
        std::cout << "Which sorting algorithm do you want to use?" << std::endl;
        std::cout << "1. RadixSort" << std::endl;
        std::cout << "2. SelectionSort" << std::endl;
        std::cout << "3. ShellSort" << std::endl;
        std::cout << "4. HeapSort" << std::endl;
        std::cout << "5. QuickSort" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        unsigned int choice = 0;
        std::cin >> choice;
        if (choice != 6)
        {
            std::vector<int> v;
            std::cout << "Enter the size of the vector: ";
            int size;
            std::cin >> size;
            std::cout << "Do you want to enter the vector manually? (y/n): ";
            char c;
            std::cin >> c;
            if (c == 'y')
            {
                for (int i = 0; i < size; i++)
                {
                    std::cout << "Enter the value of the " << i + 1 << " element: ";
                    int value;
                    std::cin >> value;
                    v.push_back(value);
                }
            }
            else
            {
                int random_number = 0;
                for (int i = 0; i < size; i++)
                {
                    random_number = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
                    v.push_back(random_number);
                }
            }
            switch (choice)
            {
            case 1:
                selection = new RadixSort<key>();
                system("clear");
                break;
            case 2:
                selection = new SelectionSort<key>();
                system("clear");
                break;
            case 3:
                selection = new ShellSort<key>();
                system("clear");
                break;
            case 4:
                selection = new HeapSort<key>();
                break;
            case 5:
                selection = new QuickSort<key>();
                break;
            default:
                std::cout << "Invalid choice, try again" << std::endl;
                return 0;
            }
            std::cout << "Vector before sorting: " << std::endl;
            selection->print(v);
            selection->sort(v);
            std::cout << std::endl;
            std::cout << "Vector after sorting: " << std::endl;
            selection->print(v);
            // sleep(4);
            // system("clear");
        }
        else
        {
            std::cout << "Exiting..." << std::endl;
            exit = true;
        }
    }
}
