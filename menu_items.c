#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ITEMS 100
#define MAX_ORDERS 50

struct Menuitem {
    int item_no;
    char name[30];
    int price;
};

struct Order {
    int item_no;
    int quantity;
    int total_price;
};

struct Menuitem menu[MAX_ITEMS] = {
    {1, "Margherita Pizza", 250},
    {2, "Farmhouse Pizza", 280},
    {3, "Pepperoni Pizza", 320},
    {4, "Cheese Burst Pizza", 350},
    {5, "Tandoori Paneer Pizza", 300},
    {6, "BBQ Chicken Pizza", 350},
    {7, "Veg Burger", 120},
    {8, "Chicken Burger", 150},
    {9, "Paneer Burger", 140},
    {10, "Double Patty Burger", 180},
    {11, "White Sauce Pasta", 200},
    {12, "Red Sauce Pasta", 180},
    {13, "Mac & Cheese", 220},
    {14, "Grilled Cheese Sandwich", 100},
    {15, "Club Sandwich", 120},
    {16, "French Fries", 90},
    {17, "Peri Peri Fries", 100},
    {18, "Chili Cheese Fries", 120},
    {19, "Chowmein Noodles", 150},
    {20, "Schezwan Noodles", 160},
    {21, "Hakka Noodles", 170},
    {22, "Paneer Manchurian", 200},
    {23, "Chicken Manchurian", 220},
    {24, "Spring Rolls", 130},
    {25, "Fried Rice", 150},
    {26, "Egg Fried Rice", 170},
    {27, "Chicken Fried Rice", 200},
    {28, "Paneer Butter Masala", 250},
    {29, "Kadhai Paneer", 260},
    {30, "Palak Paneer", 240},
    {31, "Chicken Curry", 280},
    {32, "Butter Chicken", 300},
    {33, "Mutton Rogan Josh", 350},
    {34, "Dal Makhani", 200},
    {35, "Rajma Chawal", 180},
    {36, "Chole Bhature", 160},
    {37, "Poori Sabzi", 140},
    {38, "Veg Thali", 250},
    {39, "Non-Veg Thali", 320},
    {40, "Butter Naan", 40},
    {41, "Garlic Naan", 50},
    {42, "Tandoori Roti", 30},
    {43, "Stuffed Paratha", 80},
    {44, "Aloo Paratha", 70},
    {45, "Paneer Paratha", 90},
    {46, "Dosa", 120},
    {47, "Masala Dosa", 140},
    {48, "Mysore Dosa", 160},
    {49, "Uttapam", 130},
    {50, "Idli Sambar", 100},
    {51, "Vada Sambar", 110},
    {52, "Pani Puri", 60},
    {53, "Sev Puri", 80},
    {54, "Dahi Puri", 90},
    {55, "Bhel Puri", 100},
    {56, "Pav Bhaji", 150},
    {57, "Misal Pav", 140},
    {58, "Soft Drink", 70},
    {59, "Cold Coffee", 100},
    {60, "Hot Tea", 50},
    {61, "Ginger Tea", 60},
    {62, "Masala Chai", 70},
    {63, "Green Tea", 80},
    {64, "Lassi", 90},
    {65, "Buttermilk", 80},
    {66, "Fresh Lime Soda", 90},
    {67, "Mango Shake", 110},
    {68, "Chocolate Shake", 120},
    {69, "Strawberry Shake", 130},
    {70, "Gulab Jamun", 80},
    {71, "Rasgulla", 90},
    {72, "Rasmalai", 110},
    {73, "Jalebi", 100},
    {74, "Kaju Katli", 150},
    {75, "Motichoor Ladoo", 130},
    {76, "Chocolate Ice Cream", 120},
    {77, "Vanilla Ice Cream", 110},
    {78, "Strawberry Ice Cream", 120},
    {79, "Butterscotch Ice Cream", 130},
    {80, "Fruit Salad", 140},
    {81, "Brownie", 160},
    {82, "Choco Lava Cake", 180},
    {83, "Sizzling Brownie", 200},
    {84, "Waffles", 150},
    {85, "Pancakes", 160},
    {86, "Churros", 170},
    {87, "Momos (Veg)", 140},
    {88, "Momos (Chicken)", 160},
    {89, "Cheese Momos", 180},
    {90, "Tandoori Momos", 200},
    {91, "Falooda", 140},
    {92, "Custard", 120},
    {93, "Fruit Cream", 130},
    {94, "Tiramisu", 220},
    {95, "Cheesecake", 250},
    {96, "Red Velvet Cake", 280},
    {97, "Chocolate Truffle Cake", 300},
    {98, "Pastry", 110},
    {99, "Muffins", 100},
    {100, "Donuts", 90}
};

struct Order orders[MAX_ORDERS];
int order_count = 0;

void displaymenu() {
    printf("===================================================\n");
    printf("                    FOOD MENU                      \n");
    printf("===================================================\n");
    printf("Item No | Food Item                | Price (in Rs)\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%-7d | %-25s | %d\n", menu[i].item_no, menu[i].name, menu[i].price);
    }
    printf("===================================================\n");
}

void placeOrder(){
    int item_no, quantity;
    char more;
    do {
        displaymenu();
        printf("Enter the item no to order: ");
        scanf("%d", &item_no);

        if (item_no < 1 || item_no > MAX_ITEMS) {
            printf("\nInvalid Item Number! Try Again.\n");
            continue;
        }

        printf("Enter Quantity: ");
        scanf("%d", &quantity);

        if (order_count >= MAX_ORDERS) {
            printf("\nOrder limit reached!\n");
            return;
        }

        orders[order_count].item_no = item_no;
        orders[order_count].quantity = quantity;
        orders[order_count].total_price = menu[item_no - 1].price * quantity; // Fix indexing
        order_count++;

        printf("\n%s x %d added to your order.\n", menu[item_no - 1].name, quantity);

        printf("\nDo you want to order more items? (y/n): ");
        scanf(" %c", &more);
    } while (more == 'y' || more == 'Y');
}

void generateBill() {
    if (order_count == 0) {
        printf("\nNo items ordered yet!\n");
        return;
    }
    int total = 0;
    printf("============================================\n");
    printf("                  BILL                      \n");
    printf("============================================\n");
    printf("Item No | Quantity | Total Price (Rs.)\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < order_count; i++) {
        printf("%-7d | %-8d | %d\n", orders[i].item_no, orders[i].quantity, orders[i].total_price);
        total += orders[i].total_price;
    }
    printf("--------------------------------------------\n");
    printf("Grand Total: Rs. %d\n", total);
    printf("============================================\n");
}

int main() {
    printf("============================================\n");
    printf("          Welcome to Food Corner            \n");
    printf("============================================\n");
    int choice;
    do {
        printf("\n1. View Menu\n2. Place Order\n3. Generate Bill\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: displaymenu(); break;
            case 2: placeOrder(); break;
            case 3: generateBill(); break;
            case 4: printf("\nThank you! Visit again.\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}