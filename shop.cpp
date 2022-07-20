#include<bits/stdc++.h>

using namespace std;

class Shop
{
protected:
    int total_income;
public:
    string product_name[10];
    int product_price[10];
    int product_quantity[10];

    int getTotalIncome()
    {
        return this->total_income;
    };
    void setTotalIncome(int a)
    {
        this->total_income += a;
    };

    Shop(int n,string product[],int productPrice[],int productQuantity[])
    {
        this->total_income = 0;
        for(int i=0; i<n; i++)
        {
            this->product_name[i] = product[i];
            this->product_price[i] = productPrice[i];
            this->product_quantity[i] = productQuantity[i];
        }
    };

    void upadateQuantity(int opt,int quantity)
    {

        product_quantity[opt-1] -= quantity;
        cout<<product_name[opt-1]<<" bought "<<quantity<<" pc successfully"<<endl;


    }
};

Shop *createShop(int n)
{
    string name;
    int price,quantity;
    string productName[n];
    int productPrice[n],productQuantity[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Product "<<i+1<<" Name : ";
        cin>>name;
        cout<<"Product "<<i+1<<" Price : ";
        cin>>price;
        cout<<"Product "<<i+1<<" Quantity : ";
        cin>>quantity;

        productName[i] = name;
        productPrice[i] = price;
        productQuantity[i] = quantity;

    }

    Shop *shop = new Shop(n,productName,productPrice,productQuantity);
    return shop;
}

void printData(Shop *shop,int n)
{
    cout<<"\t\t\tBUY PRODUCT"<<endl;
    cout<<"\t\t\t-----------"<<endl;

    cout<<"Product index \t\t\t";
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<"\t\t";
    };
    cout<<"\nProduct Name \t\t\t";
    for(int i=0; i<n; i++)
    {
        cout<<shop->product_name[i]<<"\t\t";
    };
    cout<<"\nProduct Price \t\t\t";
    for(int i=0; i<n; i++)
    {
        cout<<shop->product_price[i]<<"\t\t";
    };
    cout<<"\nProduct Quantity \t\t";
    for(int i=0; i<n; i++)
    {
        cout<<shop->product_quantity[i]<<"\t\t";
    };
};

int priceCalculate(Shop *shop,int opt,int number)
{
    int result = shop->product_price[opt-1] * number;
    return result;
};

void buyProduct(Shop *shop,int n)
{
    int opt,quant;
    cout<<"\nWhich product do you want? from 1 to "<<n<<" : ";
    cin>>opt;
    cout<<"What is the Quantity that you want of "<<shop->product_name[opt-1]<<" : ";
    cin>>quant;

    if(quant <= shop->product_quantity[opt-1])
    {
        shop->upadateQuantity(opt,quant);
        int income = priceCalculate(shop,opt,quant);
        shop->setTotalIncome(income);
        cout<<"Your total income : "<<shop->getTotalIncome()<<endl;
    }
    else
    {
        cout<<"This Quantity of this product is not available"<<endl;
    }

};

int main()
{
    int n;
    cout<<"Number of Product : ";
    cin>>n;
    Shop *myShop = createShop(n);

    while(true)
    {
        printData(myShop,n);
        buyProduct(myShop,n);
    }
    return 0;
}
