#include<iostream>
#include<cstring>

using namespace std;

//Shopping Cart using inheritance

class Product {
private:
    int id;
    string name;
    static int counter;
protected:
    double price;
    Product *products[100];
    int productNo;
public:
    Product() {
    }

    Product(string noun, double sum) {
        name = noun;
        price = sum;
        counter++;
        id = counter;
        productNo = 0;
    }

    void addFreeProduct(Product *a) {
        products[productNo++] = a;
    }

    string getName () {
        return name;
    }

    virtual double getTax() {
        return 0;
    }

    double getPrice() {
        return price;
    }

    int getID () {
        return id;
    }
};

int Product::counter = 0;

//override necessary methods
class Phones:public Product {
private:
    static double tax;
public:
    Phones(string a, double b):Product(a,b) {
    }

    static void setTax(double x) {
        tax = x;
    }

    double getTax() {
        return tax;
    }
};

double Phones::tax=0;

//override methods
class Foods:public Product {
private:
    static double tax;
public:
    Foods(string a, double b):Product(a,b) {
    }

    static void setTax(double x) {
        tax = x;
    }

    double getTax() {
        return tax;
    }
};

double Foods::tax=0;

class Cart {
    double totalPrice;
    Product *products[100];
    int itemNo;
public:
    Cart() {
        totalPrice = 0;
        itemNo = 0;
    }

    void addToCart(Product *x) {
        products[itemNo++] = x;
    }

    void showCartDetails() {
        for (int i =0; i < itemNo; i++) {
            cout << products[i]->getName() << "("<< products[i]->getID() << ")" << ": " << products[i]->getPrice() + (products[i]->getPrice() * products[i]->getTax() /100) << endl;
            cout << "___________________________" << endl;
        }
    }
};

int main() {
    Phones::setTax(15); // set  15% VAT on phones
    Foods::setTax(5);  // set 5% VAT on Foods
    Cart myCart;

    Foods mango("Rajshahir mango",500);
    Foods pithaPuli("Chitoi pitha",200);

    Foods hilsha("Ilish",1000);
    Product vrset("Virtual Reality Headset",10000);

    Phones samsungGalaxy("Samsung Galaxy S7",75000);
    Phones nokia("Nokia 1100",2000);

    samsungGalaxy.addFreeProduct(&vrset);
    samsungGalaxy.addFreeProduct(&hilsha);

    //addToCart add product to Cart
    myCart.addToCart(&samsungGalaxy);
    myCart.addToCart(&mango);
    myCart.addToCart(&pithaPuli);
    myCart.addToCart(&nokia);

//showCartDetails show products and their price
    myCart.showCartDetails();

    cout<<endl<<"**********After Tax Change*********"<<endl<<endl;

    Phones::setTax(10);
    Foods::setTax(7);

    myCart.showCartDetails();

    return 0;
}
