#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Base class
class ItemDetails {
protected:
    string itemName;
    int itemNumber;
    float itemPrice;

public:
    void setDetails(const string& name, int number, float price) {
        itemName = name;
        itemNumber = number;
        itemPrice = price;
    }

    virtual void getDetails() const {
        cout << "Item name: " << itemName << endl;
        cout << "Item number: " << itemNumber << endl;
        cout << "Item price: " << fixed << setprecision(0) << itemPrice << endl;
    }

    float getPrice() const {
        return itemPrice;
    }
};

// Derived class
class DiscountedItem : public ItemDetails {
    float discountPercent;
    float discountedPrice;

public:
    void setDiscount(float discount) {
        discountPercent = discount;
        discountedPrice = itemPrice * (1 - discountPercent / 100.0);
    }

    float getDiscountedPrice() const {
        return discountedPrice;
    }

    float getDiscountAmount() const {
        return itemPrice - discountedPrice;
    }

    void getDetails() const override {
        cout << "Item name: " << itemName << endl;
        cout << "Item number: " << itemNumber << endl;
        cout << "Item price: " << fixed << setprecision(0) << itemPrice << endl;
        cout << "Discount percent: " << fixed << setprecision(0) << discountPercent << "%" << endl;
        cout << "Discounted price: " << fixed << setprecision(1) << discountedPrice << endl;
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();  // Clear newline after reading n

    vector<DiscountedItem> items;

    for (int i = 0; i < n; ++i) {
        string name;
        int number;
        float price, discount;

        getline(cin, name);
        string numStr;
        getline(cin, numStr);
        number = stoi(numStr);
        string priceStr;
        getline(cin, priceStr);
        price = stof(priceStr);
        string discountStr;
        getline(cin, discountStr);
        discount = stof(discountStr);

        DiscountedItem item;
        item.setDetails(name, number, price);
        item.setDiscount(discount);

        items.push_back(item);
    }

    cout << "Item-wise bill:" << endl;

    float totalPrice = 0.0, totalDiscount = 0.0;

    for (const auto& item : items) {
        item.getDetails();
        totalPrice += item.getPrice();
        totalDiscount += item.getPrice() - item.getDiscountedPrice();
    }

    cout << "Total price: " << fixed << setprecision(0) << totalPrice << endl;
    cout << "Total discount: " << fixed << setprecision(1) << totalDiscount << endl;

    return 0;
}
