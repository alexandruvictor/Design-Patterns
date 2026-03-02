#include <iostream>
#include <vector>
#include <memory>
#include <string>

// ===== Observer Interface =====
class Observer {
public:
	virtual ~Observer() = default;
	virtual void update(int state) = 0;
};

// ===== Subject (Observable) =====
class Subject {
public:
	virtual ~Subject() = default;

	void attach(std::shared_ptr<Observer> obs) 
    {
		observers_.push_back(obs);
	}

	void detach(std::shared_ptr<Observer> obs) 
    {
		observers_.erase(std::remove(observers_.begin(), observers_.end(), obs), observers_.end());
	}

	void notify() {
		for (auto &obs : observers_) 
        {
			if (obs) obs->update(state_);
		}
	}

	void setState(int s) 
    {
		state_ = s;
		notify();
	}

	int getState() const { return state_; }

private:
	std::vector<std::shared_ptr<Observer>> observers_;
	int state_ = 0;
};

// ===== Concrete Observers =====
class ConcreteObserverA : public Observer 
{
public:
	ConcreteObserverA(const std::string &name) : name_(name) {}

	void update(int state) override 
    {
		std::cout << "Observer " << name_ << " received state update: " << state << std::endl;
	}

private:
	std::string name_;
};

class ConcreteObserverB : public Observer {
public:
	ConcreteObserverB(const std::string &name) : name_(name) {}

	void update(int state) override 
    {
		std::cout << "Observer " << name_ << " handling new state: " << state << std::endl;
	}
    
private:
	std::string name_;
};

// ===== Example usage =====
int main() {
	std::cout << "--- Observer Pattern Demo ---\n" << std::endl;

	Subject subject;

	auto obs1 = std::make_shared<ConcreteObserverA>("ObserverA");
	auto obs2 = std::make_shared<ConcreteObserverB>("ObserverB");

	subject.attach(obs1);
	subject.attach(obs2);

	std::cout << "Setting state to 1" << std::endl;
	subject.setState(1);

	std::cout << "Detaching ObserverA and setting state to 2" << std::endl;
	subject.detach(obs1);
	subject.setState(2);

	return 0;
}

