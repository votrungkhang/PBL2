#include "DataAccess/FileBuuKienRepository.h"
#include "Business/BuuKienService.h"
#include "Presentation/ConsoleUI.h"

#include <iostream>
#include <stdexcept>

int main() {
    try {
        FileBuuKienRepository repository;
        BuuKienService service(repository);
        ConsoleUI app(service);
        const int exitCode = app.run();
        repository.save();
        return exitCode;
    } catch (const std::runtime_error& error) {
        std::cerr << "Loi du lieu: " << error.what() << '\n';
        return 1;
    }
}
