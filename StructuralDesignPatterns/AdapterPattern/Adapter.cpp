#include <iostream>
#include <memory>
#include <string>

// Adapter Pattern - Object Adapter example
// Target: interface expected by the client
class Target 
{
public:
	virtual ~Target() = default;
	virtual void request() = 0; // client calls this
};

// Adaptee: existing class with incompatible interface
class Adaptee 
{
public:
	void specificRequest() 
    {
		std::cout << "Adaptee: specificRequest() called\n";
	}
};

// Adapter: makes Adaptee conform to Target interface (object adapter)
class Adapter : public Target 
{
public:
	Adapter(std::shared_ptr<Adaptee> adaptee) : adaptee_(adaptee) {}

	void request() override 
    {
		// Translate the Target::request call to Adaptee::specificRequest
		std::cout << "Adapter: Translating request() to specificRequest()...\n";
		adaptee_->specificRequest();
	}

private:
	std::shared_ptr<Adaptee> adaptee_;
};

// ===== Example usage =====
int main() {
	std::cout << "--- Adapter Pattern Demo ---\n";

	// Client expects a Target
	std::shared_ptr<Adaptee> oldComponent = std::make_shared<Adaptee>();

	// Adapter wraps the old component and presents the Target interface
	Adapter adapter(oldComponent);

	// Client uses the Target interface without knowing about Adaptee
	adapter.request();

	// You can also use polymorphism via Target*
	Target* t = &adapter;
	t->request();

	return 0;
}

