#include "GAME/Game.h"

int main() {
    Game game;
    game.run();

    return 0;
}



// "Tema 3, imi pare rau ca te-am deranjat!"
// Multumesc!


 /*#include <iostream>
#include <vector>
#include <string>

template <typename T>
class ComputerComponents {
private:
    T processor;
    T graphicsCard;
    T ram;
    T powerSupply;

public:
    ComputerComponents(const T& processor, const T& graphicsCard, const T& ram, const T& powerSupply)
        : processor(processor), graphicsCard(graphicsCard), ram(ram), powerSupply(powerSupply) {}

    const T& getProcessor() const { return processor; }
    const T& getGraphicsCard() const { return graphicsCard; }
    const T& getRAM() const { return ram; }
    const T& getPowerSupply() const { return powerSupply; }
};

template <typename T>
class Computer {
protected:
    std::string user;
    ComputerComponents<T> components;

public:
    Computer(const std::string& username, const ComputerComponents<T>& components)
        : user(username), components(components) {}

    virtual void display() const = 0;

    void setUser(const std::string& username) {
        user = username;
    }

    virtual ~Computer() {}
};

template <typename T>
class AMDComputer : public Computer<T> {
public:
    AMDComputer(const std::string& username, const ComputerComponents<T>& components)
        : Computer<T>(username, components) {}

    void display() const override {
        std::cout << "AMD User: " << this->user
                  << ", Processor: " << this->components.getProcessor()
                  << ", Graphics Card: " << this->components.getGraphicsCard()
                  << ", RAM: " << this->components.getRAM()
                  << ", Power Supply: " << this->components.getPowerSupply() << std::endl;
    }
};

template <typename T>
class IntelComputer : public Computer<T> {
public:
    IntelComputer(const std::string& username, const ComputerComponents<T>& components)
        : Computer<T>(username, components) {}

    void display() const override {
        std::cout << "Intel - User: " << this->user
                  << ", Processor: " << this->components.getProcessor()
                  << ", Graphics Card: " << this->components.getGraphicsCard()
                  << ", RAM: " << this->components.getRAM()
                  << ", Power Supply: " << this->components.getPowerSupply() << std::endl;
    }
};

template <typename T>
class ComputerFactory {
public:
    virtual Computer<T>* createComputer(const std::string& username, int processorChoice, int graphicsChoice, int ramChoice, int powerChoice) = 0;
    virtual ~ComputerFactory() {}
};

template <typename T>
class AMDComputerFactory : public ComputerFactory<T> {
public:
    Computer<T>* createComputer(const std::string& username, int processorChoice, int graphicsChoice, int ramChoice, int powerChoice) override {
        std::string processor;
        std::string graphicsCard;
        std::string ram;
        std::string powerSupply;

        if (processorChoice == 1) {
            processor = "Ryzen 5";
        } else if (processorChoice == 2) {
            processor = "Ryzen 7";
        } else if (processorChoice == 3) {
            processor = "Ryzen 9";
        }

        if (graphicsChoice == 1) {
            graphicsCard = "RTX 4070";
        } else if (graphicsChoice == 2) {
            graphicsCard = "RTX 4080";
        } else if (graphicsChoice == 3) {
            graphicsCard = "RTX 4090";
        }

        if (ramChoice == 1) {
            ram = "16GB";
        } else if (ramChoice == 2) {
            ram = "32GB";
        } else if (ramChoice == 3) {
            ram = "64GB";
        }

        if (powerChoice == 1) {
            powerSupply = "750W";
        } else if (powerChoice == 2) {
            powerSupply = "850W";
        } else if (powerChoice == 3) {
            powerSupply = "1000W";
        }

        ComputerComponents<std::string> components(processor, graphicsCard, ram, powerSupply);
        AMDComputer<std::string>* amdComputer = new AMDComputer<std::string>(username, components);
        return amdComputer;
    }
};

template <typename T>
class IntelComputerFactory : public ComputerFactory<T> {
public:
    Computer<T>* createComputer(const std::string& username, int processorChoice, int graphicsChoice, int ramChoice, int powerChoice) override {
        std::string processor;
        std::string graphicsCard;
        std::string ram;
        std::string powerSupply;

        if (processorChoice == 1) {
            processor = "i5";
        } else if (processorChoice == 2) {
            processor = "i7";
        } else if (processorChoice == 3) {
            processor = "i9";
        }

        if (graphicsChoice == 1) {
            graphicsCard = "RTX 4070";
        } else if (graphicsChoice == 2) {
            graphicsCard = "RTX 4080";
        } else if (graphicsChoice == 3) {
            graphicsCard = "RTX 4090";
        }

        if (ramChoice == 1) {
            ram = "16GB";
        } else if (ramChoice == 2) {
            ram = "32GB";
        } else if (ramChoice == 3) {
            ram = "64GB";
        }

        if (powerChoice == 1) {
            powerSupply = "750W";
        } else if (powerChoice == 2) {
            powerSupply = "850W";
        } else if (powerChoice == 3) {
            powerSupply = "1000W";
        }

        ComputerComponents<std::string> components(processor, graphicsCard, ram, powerSupply);
        IntelComputer<std::string>* intelComputer = new IntelComputer<std::string>(username, components);
        return intelComputer;
    }
};

template <typename T>
void showComputers(const std::vector<Computer<T>*>& computers) {
    std::cout << "\nToate calculatoarele:\n";
    for (const auto& computer : computers) {
        computer->display();
    }
}

template <typename T>
void deleteComputers(std::vector<Computer<T>*>& computers) {
    for (auto& computer : computers) {
        delete computer;
    }
    computers.clear();
}

int main() {
    std::vector<Computer<std::string>*> computers;
    ComputerFactory<std::string>* computerFactory = nullptr;

    while (true) {
        std::cout << "\nSelectati optiunea:\n"
                  << "1. Creaza un calculator AMD\n"
                  << "2. Creaza un calculator Intel\n"
                  << "3. Arata toate calculatoarele\n"
                  << "4. Sterge un calculator\n"
                  << "5. Exit\n";

        int option;
        std::cin >> option;

        switch (option) {
            case 1: {
                std::string username;
                std::cout << "User AMD: ";
                std::cin >> username;

                int processorChoice, graphicsChoice, ramChoice, powerChoice;
                std::cout << "(1 pentru Ryzen 5, 2 pentru Ryzen 7, 3 pentru Ryzen 9): ";
                std::cin >> processorChoice;

                std::cout << "(1 pentru RTX 4070, 2 pentru RTX 4080, 3 pentru RTX 4090): ";
                std::cin >> graphicsChoice;

                std::cout << "(1 pentru 16GB, 2 pentru 32GB, 3 pentru 64GB): ";
                std::cin >> ramChoice;

                std::cout << "(1 pentru 750W, 2 pentru 850W, 3 pentru 1000W): ";
                std::cin >> powerChoice;

                computerFactory = new AMDComputerFactory<std::string>();
                computers.push_back(computerFactory->createComputer(username, processorChoice, graphicsChoice, ramChoice, powerChoice));
                delete computerFactory;
                break;
            }
            case 2: {
                std::string username;
                std::cout << "User Intel: ";
                std::cin >> username;

                int processorChoice, graphicsChoice, ramChoice, powerChoice;
                std::cout << "(1 pentru i5, 2 pentru i7, 3 pentru i9): ";
                std::cin >> processorChoice;

                std::cout << "(1 pentru RTX 4070, 2 pentru RTX 4080, 3 pentru RTX 4090): ";
                std::cin >> graphicsChoice;

                std::cout << "(1 pentru 16GB, 2 pentru 32GB, 3 pentru 64GB): ";
                std::cin >> ramChoice;

                std::cout << "(1 pentru 750W, 2 pentru 850W, 3 pentru 1000W): ";
                std::cin >> powerChoice;

                computerFactory = new IntelComputerFactory<std::string>();
                computers.push_back(computerFactory->createComputer(username, processorChoice, graphicsChoice, ramChoice, powerChoice));
                delete computerFactory;
                break;
            }
            case 3: {
                showComputers(computers);
                break;
            }
            case 4: {
                if (!computers.empty()) {
                    int deleteIndex;
                    std::cout << "Indexul de stergere: ";
                    std::cin >> deleteIndex;

                    if (deleteIndex >= 0 && deleteIndex < computers.size()) {
                        delete computers[deleteIndex];
                        computers.erase(computers.begin() + deleteIndex);
                        std::cout << "Calculatorul a fost sters!\n";
                    } else {
                        std::cout << "Index invalid!\n";
                    }
                } else {
                    std::cout << "Nu exista calculatoare de sters!\n";
                }
                break;
            }
            case 5: {
                deleteComputers(computers);
                return 0;
            }
            default:
                std::cout << "Optiune invalida!\n";
        }
    }
}
 */
