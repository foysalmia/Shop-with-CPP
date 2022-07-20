
# OOP Practise With C++

A shop management simple programme with c++



## Features

- Input how many products
- Input Every products data
- Products data => Name,Price,Quantity
- User can buy product from the list
- Calculate total income of the shop



## 🚀 About Me
I'm Foysal who is a curious programmer....


## Main function code sample

```javascript
#include <iostream>

using namespace std;

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
```


