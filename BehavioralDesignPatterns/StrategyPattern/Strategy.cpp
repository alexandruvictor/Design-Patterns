#include <iostream>
#include <memory>

// ===== Strategy Interface =====
class Strategy {
public:
	virtual ~Strategy() = default;
	virtual int execute(int a, int b) const = 0;
};

// ===== Concrete Strategies =====
class AddStrategy : public Strategy {
public:
	int execute(int a, int b) const override 
    {
		return a + b;
	}
};

class SubtractStrategy : public Strategy {
public:
	int execute(int a, int b) const override 
    {
		return a - b;
	}
};

class MultiplyStrategy : public Strategy {
public:
	int execute(int a, int b) const override 
    {
		return a * b;
	}
};

// ===== Context =====
class Context {
public:
	void setStrategy(std::shared_ptr<Strategy> s) 
    {
		strategy_ = s;
	}

	int executeStrategy(int a, int b) const 
    {
		if (!strategy_) {
			std::cerr << "No strategy set!\n";
			return 0;
		}
        
		return strategy_->execute(a, b);
	}

private:
	std::shared_ptr<Strategy> strategy_;
};

// ===== Example Usage =====
int main() {
	std::cout << "--- Strategy Pattern Demo ---\n" << std::endl;

	Context ctx;

	ctx.setStrategy(std::make_shared<AddStrategy>());
	std::cout << "Add 3 + 4 = " << ctx.executeStrategy(3, 4) << std::endl;

	ctx.setStrategy(std::make_shared<SubtractStrategy>());
	std::cout << "Subtract 10 - 6 = " << ctx.executeStrategy(10, 6) << std::endl;

	ctx.setStrategy(std::make_shared<MultiplyStrategy>());
	std::cout << "Multiply 7 * 8 = " << ctx.executeStrategy(7, 8) << std::endl;

	return 0;
}

