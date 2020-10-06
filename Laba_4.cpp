#include <iostream>

class Transporter {
protected:
    float CostTonnsPerKm;
    float MaxRouteLength;
    float CargoMass;
public:
    Transporter(): CostTonnsPerKm(0),
                   MaxRouteLength(0),
                   CargoMass(0) { }
    Transporter(float cost, float route, float mass): CostTonnsPerKm(cost),
                                                   MaxRouteLength(route),
                                                   CargoMass(mass) { }
    virtual ~Transporter() { }

    virtual float TotalCost() = 0;
    virtual void SetData() {
        std::cout << "Push the cost of cargo delivery (t/km): ";
        std::cin >> CostTonnsPerKm;
        std::cout << "Push the length of max route for this transport: ";
        std::cin >> MaxRouteLength;
        std::cout << "Push the max mass of cargo for one transport unit: ";
        std::cin >> CargoMass;
    }
    virtual void GetData() {
        std::cout << "Delivery cost (kg/km): " << CostTonnsPerKm;
        std::cout << "\nMax route length: " << MaxRouteLength;
        std::cout << "\nMass of cargo (tonns): " << CargoMass;
    }
};
class Aircraft: public Transporter {
    float BaseCost;
public:
    Aircraft():
        Transporter(), BaseCost(0) { }
    Aircraft(float cost, float route, float mass, float bc):
        Transporter(cost, route, mass), BaseCost(bc) { }
    ~Aircraft() { }

    float TotalCost() {
        float mass, dist;
        std::cout << "Total cost.\nThe value of mass of cargo, please: ";
        std::cin >> mass;
        std::cout << "The value of distance, please: ";
        std::cin >> dist;
        if (mass > CargoMass || dist > MaxRouteLength) {
            std::cout << "Impossible to deliver. Please, leave more humble data";
            return -1;
        }
        return mass * dist * CostTonnsPerKm + BaseCost;
    }

    void SetData() {
        std::cout << "Push the data about aircraft.\n";
        Transporter::SetData();
        std::cout << "Push the info about base cost of using: ";
        std::cin >> BaseCost;
    }
    void GetData() {
        std::cout << "\n\nAircraft's parameters.\n";
        Transporter::GetData();
        std::cout << "\nBase cost of using: " << BaseCost;
    }
};
class Train: public Transporter {
    float AddingCarriageCost;
public:
    Train(): Transporter(), AddingCarriageCost(0) { }
    Train(float cost, float route, float mass, float acc):
        Transporter(cost, route, mass), AddingCarriageCost(acc) { }
    ~Train() { }

    float TotalCost() {
        float mass, dist;
        std::cout << "The mass of your cargo: ";
        std::cin >> mass;
        std::cout << "The distance you need: ";
        std::cin >> dist;
        if (dist > MaxRouteLength) {
            std::cout << "It's too far away. Stay humble.";
            return -1;
        }
        if (mass > CargoMass) {
            float CarriageNumber = 1;
            while (mass > CargoMass * CarriageNumber)
                CarriageNumber++;
            if (CarriageNumber > 70) {
                std::cout << "\nIt's too many carriages for your cargo. Be humble.\n";
                return -1;
            }
            return mass * dist * CostTonnsPerKm + AddingCarriageCost * CarriageNumber;
        }
        return mass * dist * CostTonnsPerKm + AddingCarriageCost;
    }

    void SetData() {
        std::cout << "\nPush the data about train.\n";
        Transporter::SetData();
        std::cout << "Push the cost of using one carriage: ";
        std::cin >> AddingCarriageCost;
    }
    void GetData() {
        std::cout << "\n\nTrain's parameters.\n";
        Transporter::GetData();
        std::cout << "\nThe cost of adding one carriage: " << AddingCarriageCost;
    }
};
class Vehicle: public Transporter {
    float GasolineWaste;
public:
    Vehicle(): Transporter(), GasolineWaste(0) { }
    Vehicle(float cost, float route, float mass, float waste):
        Transporter(cost, route, mass), GasolineWaste(waste) { }
    ~Vehicle() { }

    float TotalCost() {
        float mass, dist;
        std::cout << "Push the distance: "; std::cin >> mass;
        std::cout << "Push the mass: "; std::cin >> dist;
        if (mass > CargoMass || dist > MaxRouteLength) {
            std::cout << "Oh, something went wrong. Incorrect data!";
            return -1;
         }
        return CostTonnsPerKm * mass * dist;
    }

    void SetData() {
        std::cout << "\nPush the data about vehicle\n";
        Transporter::SetData();
        std::cout << "The gasoline waste, please: ";
        std::cin >> GasolineWaste;
    }
    void GetData() {
        std::cout << "\n\nVehicle's parameters.\n";
        Transporter::GetData();
        std::cout << "\nThe gasoline waste (l/100 km): " << GasolineWaste;
    }
};

int main() {
    Transporter* ptrs[5];
    ptrs[0] = new Aircraft(15000, 29000, 120, 20000);
    ptrs[1] = new Train(2000, 3000, 64, 1500);
    ptrs[2] = new Aircraft;
    ptrs[3] = new Train;
    ptrs[4] = new Vehicle;
    int i;
    for (i = 2; i < 5; i++)
        ptrs[i]->SetData();
    for (i = 0; i < 5; i++)
        ptrs[i]->GetData();
    for (i = 0; i < 5; i++)
        delete ptrs[i];
    return 0;
}
