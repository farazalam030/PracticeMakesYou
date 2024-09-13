#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Product {
public:
  virtual double price() const = 0;
  virtual ~Product() = default;
};

// Concrete product classes
class Book : public Product {
public:
  Book(const string &title, double price) : m_Title(title), m_Price(price) {}

  double price() const override {
    cout << "Getting \"" << m_Title << "\" book price = " << m_Price << endl;
    return m_Price;
  }

private:
  std::string m_Title;
  double m_Price;
};

class Toy : public Product {
public:
  Toy(const string &name, double price) : m_Name(name), m_PriceTag(price) {}

  double price() const override {
    cout << "Getting \"" << m_Name << "\" toy price = " << m_PriceTag << endl;
    return m_PriceTag;
  }

private:
  std::string m_Name;
  double m_PriceTag;
};

// Box class that holds products and other boxes
class Box : public Product {
private:
  string m_Name;
  std::vector<Product *> products;

public:
  explicit Box(const string &name) : m_Name(name) {}

  void addProduct(Product &product) { products.push_back(&product); }

  double price() const override {
    cout << "Opening " << m_Name << endl;
    double totalPrice = 0;

    for (const auto &product : products) {
      totalPrice += product->price();
    }

    return totalPrice;
  }
};

int main() {
  // Create some products
  Book book1{"Robinson Crusoe", 4.99};
  Toy toy1{"Star Trooper", 39.99};
  Toy toy2{"Barbie Dreamhouse", 59.99};

  // Create some boxes and add products and other boxes to them
  Box smallBox("Small Box");

  smallBox.addProduct(book1);
  smallBox.addProduct(toy1);

  Box bigBox("Big Box");

  bigBox.addProduct(toy2);
  bigBox.addProduct(smallBox);

  // Calculate the total price of the top-level box
  cout << "Calculating total price. " << endl << bigBox.price() << endl;

  return 0;
}