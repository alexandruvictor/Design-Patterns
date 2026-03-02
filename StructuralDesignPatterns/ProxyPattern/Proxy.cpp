#include <iostream>
#include <memory>
#include <string>

// ===== Subject Interface =====
// Defines the interface for RealSubject and Proxy
class Image {
public:
	virtual ~Image() = default;
	virtual void display() = 0;
};

// ===== Real Subject =====
// Expensive to create (e.g., loading large image file)
class RealImage : public Image 
{
public:
	RealImage(const std::string& filename) : filename_(filename) 
    {
		loadFromDisk();
	}

	void display() override 
    {
		std::cout << "Displaying image: " << filename_ << std::endl;
	}

private:
	std::string filename_;

	void loadFromDisk() 
    {
		// Simulate expensive loading operation
		std::cout << "Loading image from disk: " << filename_ << std::endl;
	}
};

// ===== Proxy =====
// Controls access to RealImage and adds lazy loading/caching
class ProxyImage : public Image
 {
public:
	ProxyImage(const std::string& filename) : filename_(filename) {}

	void display() override 
    {
		// Lazy initialization: create RealImage only on first use
		if (!realImage_) {
			std::cout << "Proxy: creating RealImage on first display call" << std::endl;
			realImage_ = std::make_unique<RealImage>(filename_);
		} 
        else 
        {
			std::cout << "Proxy: reusing cached RealImage" << std::endl;
		}
        
		realImage_->display();
	}

private:
	std::string filename_;
	std::unique_ptr<RealImage> realImage_;
};

// ===== Example Usage =====
int main() {
	std::cout << "--- Proxy Pattern Demo ---\n" << std::endl;

	// Client works with Image interface only
	ProxyImage img("photo_large.jpg");

	std::cout << "First call to display():\n";
	img.display();  // Loads and displays

	std::cout << "\nSecond call to display():\n";
	img.display();  // Reuses loaded image

	std::cout << "\nUsing polymorphism via Image*:\n";
	Image* i = &img;
	i->display();

	return 0;
}

