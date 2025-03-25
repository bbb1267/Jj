#include "BackupJob.h"
#include "SplitStorage.h"
#include "SingleStorage.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    try {
        std::cout << "Выберите метод: 1 - SplitStorage, 2 - SingleStorage: ";
        int choice;
        std::cin >> choice;

        std::unique_ptr<IStorage> storage;

        if (choice == 1) {
            storage = std::make_unique<SplitStorage>();
        }
        else {
            storage = std::make_unique<SingleStorage>();
        }

        BackupJob job(std::move(storage));

        job.AddObject(BackupObject("file1.txt"));
        job.AddObject(BackupObject("file2.txt"));

        job.CreateRestorePoint();
    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << "\n";
    }

    return 0;
}