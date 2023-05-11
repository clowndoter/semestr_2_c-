#include <iostream>
#include <string>

using namespace std;

class ShopItemOrder
{
public:
    ShopItemOrder(string name, double price, int quantity);

    double get_total_price();
    void print_order();

private:
    string name;
    double price;
    int quantity;
};


ShopItemOrder::ShopItemOrder(string name, double price, int quantity)
{
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}


double ShopItemOrder::get_total_price()
{
    return price * quantity;
}

void ShopItemOrder::print_order()
{
    cout << "Order Details:" << endl;
    cout << "Item Name: " << name << endl;
    cout << "Unit Price: $" << price << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total Price: $" << get_total_price() << endl;
    cout << "----------------------------" << endl;
}

int main()
{
    ShopItemOrder item("iPhone 14 Pro Max", 100000, 2);
    item.print_order();
    
    cout<<"Total price: $"<<item.get_total_price()<<endl;

    return 0;
}
