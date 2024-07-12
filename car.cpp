#include <iostream>
#include <string>
#include <limits> // Для использования std::numeric_limits

class Car 
{
private:
    std::string name;
	unsigned int speed;

public:
    Car() : name(""), speed(0)
	{
        std::cout << "Car: Empty name" << std::endl;
    }

    Car(const std::string& str, unsigned int speed) : name(str), speed(speed)
	{
        std::cout << "Car: Parameterized constructor called" << std::endl;
    }

    Car(const Car& other) : name(other.name), speed(other.speed)
	{
        std::cout << "Car: Copy constructor called" << std::endl;
    }

    Car& operator=(const Car& other) 
	{
        std::cout << "Car: Copy assignment operator called" << std::endl;
        if (this == &other) 
		{
            return *this;
        }


        name = other.name;
		speed = other.speed;

        return *this;
    }

    virtual ~Car()  
    {
        
    }

    virtual void driveAll () = 0;


    void setName(const std::string& value) 
	{
        this->name = value;
    }

	void setSpeed(unsigned int value) 
	{
        // Проверяем, что значение не превышает максимальное значение для unsigned int
        if (value <= std::numeric_limits<unsigned int>::max())
        {
            speed = value;
            std::cout << "Car: Set speed to " << value << " km/h." << std::endl;
        }
        else
        {
            std::cout << "Car: Error: Speed value exceeds maximum allowed for unsigned int." << std::endl;
        }
    }

    const std::string& getName() const 
	{
        return name;
    }

	unsigned int getSpeed() const 
	{
        return speed;
    }

    virtual void drive() const { std::cout << "only car ";}
};

class Vehicle : public Car
{
protected:
    std::string make;
	std::string model;
    int year;

public:
    Vehicle(const std::string& name, unsigned int speed, 
			const std::string& make, const std::string& model, int year)
        : Car(name, speed), make(make), model(model), year(year)
    {
        std::cout << "Vehicle: Parameterized constructor called" << std::endl;
    }

    Vehicle(const Vehicle& other)
        : Car(other), make(other.make), model(other.model), year(other.year)
    {
        std::cout << "Vehicle: Copy constructor called" << std::endl;
    }

    Vehicle& operator=(const Vehicle& other) {
        std::cout << "Vehicle: copy assignment operator called" << std::endl;

        if (this != &other) {
            Car::operator=(other);
            this->make = other.make;
            this->model = other.model;
            this->year = other.year;
        }
        return *this;
    }

    virtual ~Vehicle() override
    {
        std::cout << "Vehicle: Destructor called" << std::endl;
    }

    void setMake(const std::string& make) 
    {
        this->make = make;
    }

	void setModel(const std::string& model) 
    {
        this->model = model;
    }

    void setYear(int year) 
    {
        this->year = year;
    }

    const std::string& getMake() const 
    {
        return make;
    }

	const std::string& getModel() const 
    {
        return model;
    }

    int getYear() const 
    {
        return year;
    }

    virtual void drive() const override
    {
        std::cout << "Vehicle: Driving " << make << "vehicle++++++++" << std::endl;
    }

    virtual void driveAll() {
        std::cout << "Vehicle drive all" << std::endl;
    }

    // Сделаем метод setSpeed виртуальным, чтобы можно было его переопределить в производных классах
    virtual void setSpeed(unsigned int speed)
    {
        if (speed <= std::numeric_limits<unsigned int>::max())
        {
            Car::setSpeed(speed);
        }
        else
        {
            std::cout << "Vehicle: Error: Speed value exceeds maximum allowed for unsigned int." << std::endl;
        }
    }
};

class SportsCar : public Vehicle
{
private:
    unsigned int maxSpeed;
    std::string driveType;

public:
    SportsCar(const std::string& name, unsigned int speed,
              const std::string& make, const std::string& model,
              int year, unsigned int maxSpeed, const std::string& driveType)
        : Vehicle(name, speed, make, model, year), maxSpeed(maxSpeed), driveType(driveType)
    {
        std::cout << "SportsCar: Parameterized constructor called" << std::endl;
    }

    SportsCar(const SportsCar& other)
        : Vehicle(other), maxSpeed(other.maxSpeed), driveType(other.driveType)
    {
        std::cout << "SportsCar: Copy constructor called" << std::endl;
    }

    SportsCar& operator=(const SportsCar& other) {
        std::cout << "SportsCar: copy assignment operator called" << std::endl;
        if (this != &other) {
            Vehicle::operator=(other);
            this->maxSpeed = other.maxSpeed;
            this->driveType = other.driveType;
        }
        return *this;
    }

    ~SportsCar() override
    {
        std::cout << "SportsCar: Destructor called" << std::endl;
    }

    void setMaxSpeed(unsigned int maxSpeed)
    {
        this->maxSpeed = maxSpeed;
    }

    unsigned int getMaxSpeed() const
    {
        return maxSpeed;
    }

    void setDriveType(const std::string& driveType)
    {
        this->driveType = driveType;
    }

    const std::string& getDriveType() const
    {
        return driveType;
    }

    virtual void drive() const override
    {
        std::cout << "SportsCar: Driving " << make << " " << model << " " << getName() << " "
                  << year << ". Max speed: " << maxSpeed << " km/h. Drive type: "
                  << driveType << ". SportCar" << std::endl;
    }

    void setSpeed(unsigned int speed) override
    {
        if (speed <= maxSpeed)
        {
            Vehicle::setSpeed(speed);
        }
        else
        {
            std::cout << "SportsCar: Error: Speed value exceeds maximum allowed for SportsCar." << std::endl;
        }
    }

    virtual void driveAll () 
    {
        std::cout << "empty" << std::endl;
    };
};

int main()
{
    // Пример использования класса Car
 //   std::cout << "=== Example using Car ===" << std::endl;
   // Car car("Toyota", 180);
    // car.drive();

   // std::cout << "Setting new speed for Car..." << std::endl;
    // car.setSpeed(200); // Установка новой скорости для Car
    // car.drive(); // Повторный вызов drive, чтобы увидеть изменение

    std::cout << std::endl;

    // Пример использования класса Vehicle
    std::cout << "=== Example using Vehicle ===" << std::endl;
    Vehicle vehicle("Ford", 150, "Ford", "Fusion", 2023);
    vehicle.drive();

    std::cout << "Setting new speed for Vehicle..." << std::endl;
    vehicle.setSpeed(160); // Установка новой скорости для Vehicle
    vehicle.drive(); // Повторный вызов drive, чтобы увидеть изменение

    std::cout << std::endl;

    // Пример использования класса SportsCar
    std::cout << "=== Example using SportsCar ===" << std::endl;
    SportsCar sportsCar("Ferrari", 280, "Ferrari", "458 Italia", 2022, 350, "Rear-wheel drive");
    sportsCar.drive();

    std::cout << "Setting new speed for SportsCar..." << std::endl;
    sportsCar.setSpeed(320); // Установка новой скорости, которая должна работать
    sportsCar.drive(); // Повторный вызов drive, чтобы увидеть изменение

    std::cout << "Trying to set speed above maximum for SportsCar..." << std::endl;
    sportsCar.setSpeed(4294967295); // Попытка установить скорость, которая превышает максимально допустимую для unsigned int
    sportsCar.setSpeed(429);
	sportsCar.setSpeed(-2);
std::cout << "continue ====================================" << std::endl;
  Car& car1 ;
  car1 = vehicle;
 //   car1 = car;

 Car& car2 = sportsCar;

 //   car1 = car2;
std::cout << "continue ====================================" << std::endl;
    car1.drive();
 //   std::cout << "=== Example using SportsCar ===" << car1.getModel() << std::endl
 car2.drive();
	
	

    return 0;
}
