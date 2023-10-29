// CODE WRITTEN DATE - 2021
// #include <bits/stdc++.h>
// It's Code Block include.
// !!! ADD THE REQUIRED LIBRARIES !!!
// For example #include <string> and other...

using namespace std;

class Product{
private:
    string name;
    int weight;
    int price;
    int createdate, spoileddate;
    int days;
    int cnt;
    string typeproducts;
public:
    Product() = default;

    Product(string name, int weight, int price, int createdate){
        this->name = name;
        set_weight(weight);
        set_price(price);
        set_createdate(createdate);
    }
    virtual string get_typeproducts() const{return this-> typeproducts;}
    virtual int get_spolieddate() const{return this-> spoileddate;}
    virtual string get_name() const{return this->name;}
    virtual int get_weight() const{return this->weight;}
    virtual int get_price() const{return this->price;}
    virtual int get_createdate() const{return this->createdate;}
    virtual int get_days() const{return this->days;}
    virtual int get_spoileddate() const{return this->spoileddate;}
    virtual int get_cnt() const{return this->cnt;}

    virtual void set_name(string name){this->name = name;}
    virtual void set_weight(int weight){this->weight = weight;}
    virtual void set_price(int price){this->price = price;}
    virtual void set_createdate(int createdate){this->createdate = createdate;}
    virtual void set_spoileddate(int spoileddate){this->spoileddate = spoileddate;}
    virtual void set_days(int days){this->days = days;}
    virtual void set_cnt(int cnt){this->cnt = cnt;}
    virtual void set_typeproducts(string typeproducts){this->typeproducts = typeproducts;}

    friend ostream& operator<<(ostream& out, const Product& obj) {
        out << "Name: " << obj.get_name() << ", Weight: " << obj.get_weight() <<", Price: " << obj.get_price() << ", Createdate: " << obj.get_createdate() << obj.get_typeproducts() << ", Typeproducts" << endl;
        return out;
    }
};

class Nonperishable_products: public Product{
public:
    Nonperishable_products() = default;

    Nonperishable_products(string name, int weight, int price, int createdate): Product(name, weight, price, createdate){
    }
};

class Perishable_products: public Product{
private:
    string spoileddate;
public:
    Perishable_products() = default;


    Perishable_products(string name, int price, int weight, int createdate, string spoileddate): Product(name, weight, price, createdate){

    }
    bool perishable(Product prodct)const{
        if(prodct.get_createdate() + prodct.get_days() > prodct.get_spoileddate()){
            return true;
        }
    }
};

class Shop{
private:
    vector<Product> products;
    bool openorclose;
    int time;
public:
    Shop() = default;

    vector<Product> get_products() {return this->products;}
    int get_time() {return this->time;}
    bool get_openorclose() {return this->openorclose;}

    void set_time(int time){this->time = time;}
    void set_openorclose(int openorclose){this->openorclose = openorclose;}

    void AddProduct() {
        string name1;
        int weight1, price1, cnt1;
        cout << "name product: ";
        cin >> name1;
        cout << "\nEnter Quantity: ";
        cin >> cnt1;
        cout << "\nEnter the weight of the item: ";
        cin >> weight1;
        cout << "\nEnter cost : ";
        cin >> price1;
        cout << "\nProduct added\n";

        Product current;
        current.set_name(name1);
        current.set_cnt(cnt1);
        current.set_price(price1);
        current.set_weight(weight1);
        products.push_back(current);
    }

    void BuyProduct(Shop &shop) {

        while(1 == 1) {

            shop.PrintProducts();
            cout << "Enter the name of the product you want to buy: ";
            string name; cin >> name;
            cout << "\nEnter the quantity you want to buy: ";
            int cnt; cin >> cnt;
            cout << "\n";
            for (int i = 0; i < products.size(); i++) {
                if (products[i].get_name() == name) {
                    if (products[i].get_cnt() < cnt) {
                        cout << "Sorry, the shop does not have enough " << name << "!\n";
                    } else {
                        products[i].set_cnt(products[i].get_cnt() - cnt);
                        cout << "Purchase successful! The total cost is " << products[i].get_price() * cnt << ".\n";
                    }
                }
            }
            string true_or_false;
            cout << "Do you want to go out(true or false)?";
            cin >> true_or_false;
            if(true_or_false == "true") {
                break;
            }
        }
    }

    void ChangeProduct(Shop &shop) {
        shop.PrintProducts();
        cout << "Enter the name of the product you want to change: ";
        string name2; cin >> name2;

        cout << "\nEnter a new price: ";
        int price2; cin >> price2;

        cout << "\nEnter new quantity: ";
        int cnt2; cin >> cnt2;

        cout << "\n";
        for (int i = 0; i < products.size(); i++) {

            if (products[i].get_name() == name2) {

                products[i].set_price(price2);
                products[i].set_cnt(cnt2);
                break;
            }
        }
        cout << "Product information has been changed!\n";
    }

    void ChangeProductCnt() {

        cout << "Enter the name of the product you want to change: ";
        string name2; cin >> name2;

        cout << "\nEnter new quantity: ";
        int cnt2; cin >> cnt2;

        cout << "\n";
        for (int i = 0; i < products.size(); i++) {

            if (products[i].get_name() == name2) {

                products[i].set_cnt(cnt2);
                break;
            }
        }
        cout << "Product Quantity Information Changed!\n";
    }

    void ClearShop() {

        cout << "All items removed!\n";

        for (int i = 0; i < products.size(); i++) {

            int cnt1; cnt1 = 0;
            products[i].set_cnt(cnt1);
        }
    }
    void PrintProducts() {

        cout << "List of products in stock:\n";
        for (int i = 0; i < products.size(); i++) {

            if (products[i].get_cnt() > 0) {

                Product cur = products[i];
                cout << "Name: " << cur.get_name() << ", Price: " << cur.get_price();
                cout << ", Weight: " << cur.get_weight() << ", Quantity: " << cur.get_cnt() << "\n";
            }
        }
        cout << "List of items out of stock:\n";
        for (int i = 0; i < products.size(); i++) {

            if (products[i].get_cnt() == 0) {

                Product cur = products[i];
                cout << "Name: " << cur.get_name() << ", Price: " << cur.get_price();
                cout << ", Weight: " << cur.get_weight() << "\n";
            }
        }
    }

    void OpenShop(){

        int timeshop; timeshop = 8;
        set_time(timeshop);
        if(timeshop == 8){
            set_openorclose(true);
        }
        else if(timeshop == 21){
            set_openorclose(false);
        }
    }

};

class Worker{
private:
    int sallary;
    int age;
    string nameW;
    int soldProducts;
    vector<Worker> workers;
public:
    vector<Worker> get_workers() const {return workers;}
    virtual string get_nameW() const{return this->nameW;}
    virtual int get_age() const{return this->age;}
    virtual int get_sallary() const{return this->sallary;}
    virtual int get_soldProducts() const{return this->soldProducts;}

    vector<Worker> set_workers() {return workers;}
    virtual void set_nameW(string nameW){this->nameW = nameW;}
    virtual void set_sallary(int sallary){this->sallary = sallary;}
    virtual void set_age(int age){this->age = age;}
    virtual void set_soldProducts(int soldProducts){this->soldProducts = soldProducts;}

    void AddWorker() {
        int age;
        string name;
        cout << "Enter the seller's name and age separated by a space: ";
        cin >> name >> age;
        Worker worker;
        worker.set_age(age);
        worker.set_nameW(nameW);
        worker.sallary = 0;
        worker.soldProducts = 0;
        workers.push_back(worker);
        cout << "Seller added!\n";
    }
};

class CashRegistr: public Shop{
private:
    bool openorclose;
    int time;
public:

};

class Client: public Shop{
private:
    int budget;
    vector<Client> names;
    string nameC;
    string namecs;

public:
    Client() = default;

    Client(string nameC, int budget) {
        set_nameC(nameC);
        set_budget(budget);
    }

    virtual string get_namecs() {return namecs;}
    virtual string get_nameC() const {return nameC;}
    virtual vector<Client> get_names() const {return names;}
    virtual Client get_nind(int i) const {return names[i];}
    virtual int get_budget() const {return budget;}

    virtual void set_nameC(string nameC) {nameC = nameC;}
    virtual void set_budget(int new_budget) {budget = new_budget;}
    virtual void set_namecs(string namecs) {namecs = namecs;}

    void Add_Client(Shop &shop){
        string namess;
        int budgetcs;
        cout << "Enter your name:\n";
        cin >> namess;
        cout << "Enter budget:\n";
        cin >> budgetcs;
        Client client;
        client.set_nameC(namess);
        set_namecs(namess);
        client.set_budget(budgetcs);
    }

    void remove_client(string name) {
        for (int i = 0; i < get_names().size(); i++) {
            if (get_names()[i].get_nameC() == name) {
                get_names().erase(get_names().begin() + i);
                return;
            }
        }
    }
};
int main() {
    // only if you need
    //setlocale(LC_ALL,"Russian");

    Shop shop;
    Client client;

    string s, cork;

    while(1 == 1){

        cout << "Who you are(Client, Owner)?\n";
        cin >> cork;

        if(cork == "Owner"){

            while (true) {

                cout << "Enter command for shop: Print, Change, Add, Exit, Clear, ChangeProductCnt:\n";
                cin >> s;
              
                if (s == "Print") {
                    shop.PrintProducts();
                }
                else if (s == "Change") {
                    shop.ChangeProduct(shop);
                }
                else if (s == "Clear") {
                    shop.ClearShop();
                }
                else if (s == "OpenOrClose") {
                    shop.OpenShop();
                }
                else if (s == "ChangeProductCnt") {
                    shop.ChangeProductCnt();
                }
                else if (s == "Add") {
                    shop.AddProduct();
                }
                else if (s == "Exit") {
                    break;
                }
                else {
                    cout << "I don't know such a command. Please enter correctly:\n";
                }
            }
        }
        else if(cork == "Client"){

                Client client;
                client.Add_Client(shop);
                shop.BuyProduct(shop);
        }
    }

    return 0;
}
