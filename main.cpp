#include <iostream>
#include <fstream>
#include <conio.h>
#include <unistd.h>
#include <iomanip>
#include <windows.h>
#include <string.h>
#define MAX 100

using namespace std;

//functions
void load();
void createAccount();
void menu();
void showCars();
void insertionSort();
void RentedCars();

//global variables
string customername;
string cnic;
string age;
string gender;
string password;
string cpassword;


class CustomerInfo{
    public:
    string data;
    CustomerInfo *next;
    
    //constructor
    CustomerInfo(string value){
        data = value;
        next = NULL;
    }
};


CustomerInfo *head = NULL;

//stack
class paymentStack{
	public:
		int data;
		paymentStack *next;
	paymentStack(int value){
		data = value;
		next = NULL;
	}
};
paymentStack *pts;

int peek(paymentStack* root){
    if (root == NULL)
        return 0;
    return root->data;
}
void push(paymentStack** root, int data){
    paymentStack* stackNode = new paymentStack(data);
    (stackNode)->next = *root;
    *root = stackNode;
}
 

//Insert function
void insertNode(CustomerInfo **head, string data){
    if (*head == NULL){
        *head = new CustomerInfo(data);
    }
    else{
        CustomerInfo *temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new CustomerInfo(data);
    }
}
class carData{
    private:
    public:
    string carmodel;
    string carnumber;
    char data;
};

// Queue Class
class QNode{
    public:
    string value;
    QNode *next;
}*front = NULL, *rear = NULL;

int remainAmount;
int advanceAmount;
int rentalfee;

// inhereted class from carDataclass
class rent : public carData {
    public:
    int days, rentalfee; // additional int vatiables defined

    void data(){
        int login();
        
		cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t---------------------------------";
        cout << "\n\t\t\t\t\t\t\t\t\t\t\tCREATE YOUR ACCOUNT \n";
        cout << "\t\t\t\t\t\t\t\t\t\t---------------------------------\n\n";
        cout << "\t\t\t\t\t\t\t\t\t\tEnter Your Name: ";
        cin >> customername;
        insertNode(&head, customername);
        cout << "\n\n\t\t\t\t\t\t\t\t\t\tEnter CNIC-Number: ";
        cin >> cnic;
        insertNode(&head, cnic);
        cout << "\n\n\t\t\t\t\t\t\t\t\t\tEnter your Age: ";
        cin >> age;
        insertNode(&head, age);
        cout << "\n\n\t\t\t\t\t\t\t\t\t\tEnter Gender: ";
        cin >> gender;
        insertNode(&head, gender);

        createAccount();
        system("CLS");
        cout << endl;
        login();

        do{	
            mainInfo:
            cout << "\t\t\t\t---------------------------------------------" << endl; 	
            cout << "\t\t\t\tPlease Select a Car" << endl; // giving user a choice to select among three different models
            showCars();
            cout << endl;
            cout << "\t\t\t\tChoose a Car from the above options: ";
            cin >> carmodel;
            cout << endl;
            if (carmodel == "A"){
                cout<<"\t\t\t\tThis car already Rented---"<<endl;
                sleep(3);
                goto mainInfo;
            }
            else if (carmodel == "B"){
            	
                system("CLS");

                cout << "You have choosen BMW model 2018AS" << endl;
                ifstream inB("B.txt"); // displaying details of model B
                char str[200];
                while (inB){
                    inB.getline(str, 200);
                    if (inB)
                        cout << str << endl;
                }
                sleep(2);
            }
            else if (carmodel == "F"){
                system("CLS");
                cout << "You have choosen Ford model 2018DS" << endl;
                ifstream inC("F.txt"); // displaying details of model C
                char str[200];
                while (inC){
                    inC.getline(str, 200);
                    if (inC)
                        cout << str << endl;
                }
                sleep(2);
            }
            else if (carmodel == "H"){
                cout<<"\t\t\t\tThis car already Rented---"<<endl;
                sleep(3);
                goto mainInfo;
            }

            else if (carmodel == "M"){
                system("CLS");
                cout << "You have choosen Mercedes model 2018OW" << endl;
                ifstream inC("M.txt"); // displaying details of model C
                char str[200];
                while (inC){
                    inC.getline(str, 200);
                    if (inC)
                        cout << str << endl;
                }
                sleep(2);
            }
            else if (carmodel == "S"){
                system("CLS");
                cout << "You have choosen Skoda model 2005Ps" << endl;
                ifstream inC("S.txt"); // displaying details of model C
                char str[200];
                while (inC){
                    inC.getline(str, 200);
                    if (inC)
                    cout << str << endl;
                }
                sleep(2);
            }
            else if (carmodel == "T"){
                cout<<"\t\t\t\tThis car already Rented---"<<endl;
                sleep(3);
                goto mainInfo;
            }
            else if (carmodel == "V"){
                system("CLS");
                cout << "You have choosen VolksWagen model 2016SA" << endl;
                ifstream inC("V.txt"); // displaying details of model C
                char str[200];
                while (inC){
                    inC.getline(str, 200);
                    if (inC)
                        cout << str << endl;
                }
                sleep(2);
            }
            else{
                cout << "Invaild Car Model. Please try again!" << endl;
            }
        }while (carmodel != "A" && carmodel != "B" && carmodel != "F" && carmodel != "H" && carmodel != "M" && carmodel != "S" && carmodel != "T" && carmodel != "V");
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Please provide following Information"<<endl;
        cout << "Number of days you wish to rent the car : ";
        cin >> days;
        cout << endl;
        
        int choice;
        string pin1, pin2;
        cout << "\n\n\t\t----------------------------" << endl;
        cout << "\t\t\tPayment Method:  " << endl;
        cout << "\t\t----------------------------" << endl;
        cout << "\t\t1: CASH\t\t\t2: CARD" << endl;
        cout << "\n\t\tEnter your Choice: ";
        cin >> choice;
        //system("CLS");
        
        if (choice == 1){
            cout << "\n\t\tEnter amount: ";
            cin >> advanceAmount; 
            push(&pts, advanceAmount);
	      }
        home1:
        if (choice == 2){
            cout << "\n\n\n\n\t\tEnter your PIN: ";
            cin >> pin1;
            cout << "\n\t\tVerify your PIN: ";
            cin >> pin2;
            if (pin1 == pin2){
                cout << "\n\t\tEnter your Amout: ";
                cin >> advanceAmount;
                push(&pts, advanceAmount);
            }
            else{
                cout << "\n\t\tPin Doesn't Match: " << endl;
                cout << "\t\tTry Again";
                sleep(2);
                system("CLS");
                goto home1;
            }
        }
        
        
    }
    void calculate()
    {
        sleep(1);
        system("CLS");
        cout << "Calculating rent. Please wait......" << endl;
        sleep(2);
        if (carmodel == "A" || carmodel == "a")
            rentalfee = days * 256;
        if (carmodel == "B" || carmodel == "b")
            rentalfee = days * 260;
        if (carmodel == "F" || carmodel == "f")
            rentalfee = days * 275;
        if (carmodel == "H" || carmodel == "h")
            rentalfee = days * 249;
        if (carmodel == "M" || carmodel == "m")
            rentalfee = days * 268;
        if (carmodel == "S" || carmodel == "s")
            rentalfee = days * 288;
        if (carmodel == "T" || carmodel == "t")
            rentalfee = days * 320;
        if (carmodel == "V" || carmodel == "v")
            rentalfee = days * 240;
        
        remainAmount = advanceAmount - rentalfee;
    }
    void showrent(){
        
		cout << "\n\t\t\t                       Car Rental - Customer Invoice                  " << endl;
        cout << "\t\t\t\t	____________________________________________" << endl;
        cout << "\t\t\t\t	| Invoice No. :"<< "------------------|" << setw(10) << "#Cnb81353"<< " |" << endl;
        cout << "\t\t\t\t	| Customer Name:"<< "-----------------|" << setw(10) << (head)->data << " |" << endl;
        cout << "\t\t\t\t	| CNIC Number:"<< "-------------------|" << setw(10) << (head)->next->data << " |" << endl;
        cout << "\t\t\t\t	| Age:"<< "---------------------------|" << setw(10) << (head)->next->next->data << " |" << endl;
        cout << "\t\t\t\t	| Gender:"<< "------------------------|" << setw(10) << (head)->next->next->next->data << " |" << endl;
        cout << "\t\t\t\t	| Car Model :"<< "--------------------|" << setw(10) << carmodel << " |" << endl;
        cout << "\t\t\t\t	| Number of days :"<< "---------------|" << setw(10) << days << " |" << endl;
        cout << "\t\t\t\t	| Your Rental Amount is :"<< "--------|" << setw(10) << rentalfee << " |" << endl;
        cout << "\t\t\t\t	| Remain: Money :"<< "----------------|" << setw(10) << remainAmount << " |" << endl;
        cout << "\t\t\t\t	| Advance :"<< "----------------------|" << setw(10) << peek(pts) << " |" << endl;
        cout << "\t\t\t\t	 ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t\t\t	| Total Rental Amount is :"<< "-------|" << setw(10) << rentalfee << " |" << endl;
        cout << "\t\t\t\t	 ________________________________________________________" << endl;
        cout << "\t\t\t\t	 # This is a computer generated invoce and it does not" << endl;
        cout << "\t\t\t\t	 require an authorised signture #" << endl;
        cout << " " << endl;
        cout << "\t\t\t\t	------------------------------------------------------------" << endl;
        cout << "\t\t\t\t	You are advised to pay up the amount before due date." << endl;
        cout << "\t\t\t\t	Otherwise penelty fee will be applied" << endl;
        cout << "\t\t\t\t	-------------------------------------------------------------" << endl;
        int f;
        system("PAUSE");
        
        
        ofstream fileOut;  // Create Object of Ofstream
        ifstream fin;
        fin.open("CustomerInfo.txt");
        fileOut.open ("CustomerInfo.txt",ios::app); // Append mode
		if(fin.is_open())
        fileOut<<"\n"<<customername<<"\t\t"<<carmodel<<"\t\t"<<cnic; 
        
        fin.close();
        fileOut.close(); // Closing the file
        

        system("CLS");

        ifstream inf("thanks.txt");
        char str[300];

        while (inf){
            inf.getline(str, 300);
            if (inf)
                cout << str << endl;
        }
        inf.close();
    }
};
void createAccount(){
    int ch;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tCreate Password: ";
    cin>>password;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tConfirm Password: ";
    cin>>cpassword;

    if (password == cpassword)
    {
        cout << "\n\t\t\t\tAccount Created Succesfully" << endl;
        sleep(2);
        system("CLS");
    }
    else
    {
        cout << "\n\t\t\t\tPassword Doest Not Match" << endl;
        cout << "\t\t\t\tTry Again" << endl;
        sleep(2);
        system("CLS");
        createAccount();
    }
}
// welcome class
class welcome{
    public:
    int welcom(){
        ifstream in("welcome.txt"); // displaying welcome ASCII image text on output screen fn1353
        if (!in){
            cout << "Cannot open input file.\n";
        }
        char str[1000];
        while (in){
            in.getline(str, 1000); // delim defaults to '\n' cp
            if (in)
                cout << str << endl;
        }
        in.close();
        sleep(1); // function which waits for (n) seconds
    }
};
void menu(){
	
    char choice;
    rent obj2;
    welcome objc;

    mainhome:
    cout << "\n\n\t\t\t\t\t\t\t\t\t__________________________________\n"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\tMENU" << endl;
    cout << "\t\t\t\t\t\t\t\t\t__________________________________" << endl;
    cout << "\t\t\t\t\t\t\t\tEnter S to List all cars\n"<< endl;
    cout << "\t\t\t\t\t\t\t\tEnter B to Book a CAR\n"<< endl;
    cout << "\t\t\t\t\t\t\t\tEnter R to Show Rented Cars\n"<< endl;
    cout << "\t\t\t\t\t\t\t\tEnter Q to Quit\n"<< endl;
    cout << "\t\t\t\t\t\t\t\tEnter your Choice: ";
    choice = toupper(getch());
    
	if (choice == 'S'){
        showCars();
        getch();
        system("cls");
        objc.welcom();
        goto mainhome;
    }
    else if (choice == 'B'){
        system("cls");
        objc.welcom();
        obj2.data();
        obj2.calculate();
        obj2.showrent();
    }
    else if (choice == 'R'){
        RentedCars();
        objc.welcom();
        goto mainhome;
    }
    else if (choice == 'Q')
        exit(1);
}
/*---------------------MAIN FUNCTION---------------------------------*/
int main(){
    system("color 57");
    
	welcome obj1;
    
    obj1.welcom(); // welcom function is called
    
	menu();

    return 0; // end of the program
}

//LOGIN
int login(){
    string pass = "";
    char ch;
    int choice;
    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t-------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t|\t    LOG IN\t\t|" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t--------------------------------" << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tEnter a Password You Created: ";
    ch = _getch();
    while (ch != 13){ // character 13 is enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (pass == cpassword){
        cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
        sleep(3);
        system("CLS");
        load();
        system("CLS");
    }
    else{
        cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";

        sleep(2);
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter 1: For try Again" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\tEnter 2: For Forgot Password" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\tEnter your choice: ";
        cin >> choice;
        if (choice == 1){
            system("CLS");
            login();
        }
        else{
            system("CLS");
            createAccount();
            login();
        }
    }
}
void next_position(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void load(){
    int r, c, q;
    next_position(90, 25);
    printf("Loading");
    for (r = 1; r <= 15; r++){
        for (q = 0; q <= 100000000; q++); // to display the character slowly
        cout << ".";
    }
    system("CLS");
}
void sortStrings(char arr[][MAX], int n){

    char temp[MAX];

    // Sorting strings using bubble sort
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (strcmp(arr[j], arr[j + 1]) > 0){
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}
void showCars(){
    system("CLS");
    welcome objc;
    objc.welcom();
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t-----------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t|\t    ALL CARS\t\t  |" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t-----------------------------------" << endl;

    cout << "\n\t\t\t\t\t____________________________________________________________________________________\n"
         << endl;
    cout << "\t\t\t\t\t  CAR NAME\t\tCAR MODEL\tCOLOR\t\tMax-Speed \tCAR PRICE" << endl;
    cout << "\t\t\t\t\t____________________________________________________________________________________" << endl;

    int price[10] = {256, 260, 275, 249, 268, 288, 320, 240};

    string model[10] = {"2016MD", "2018AS", "2018DS", "2017LA", "2018OW", "2005Ps", "2008PW", "2010QW"};

    string color[10] = {"Red", "black", "yellow", "Blue", "Red", "Brown", "Silver", "Black"};

    string maxs_peed[10] = {"100 Km/h ", "150 Km/h", "150 Km/h", "170 Km/h", "130 Km/h", "140 Km/h", "130 Km/h", "120 Km/h", "150 Km/h"};
    // SORT ONLY CAR NAMES
    char arr[][MAX] = {"Hyundai", "BMW\t", "Mercedes", "Audi\t", "Ford\t", "Skoda\t", "Volkswagun", "Toyota"};

    int n = sizeof(arr) / sizeof(arr[0]);

    sortStrings(arr, n);

    for (int i = 0; i < n; i++){
        cout << "\t\t\t\t\t" << i + 1 << " " << arr[i] << "\t\t" << model[i] << "\t\t" << color[i] << "\t\t" << maxs_peed[i] << "\t" << price[i] << "\n"
             << endl;
    }
}
void enQ(string newVal){
    QNode *newNode = new QNode();
    newNode->value = newVal;

    if (front == NULL){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}
void deQ(){

    QNode *newNode = new QNode();
    if (front == rear){
        front = rear = NULL;
    }
    else{
        newNode = front;
        front = front->next;
    }
}
void display(QNode *ptr){
    while (ptr != NULL){
        cout << "\n\t\t\t\t\t" << ptr->value << endl;
        ptr = ptr->next;
    }
}
void RentedCars(){

    system("CLS");
    welcome objc;
    objc.welcom();

    cout << "\n\n\n\t\t\t\t\t\t\t\t---------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\tALL RENTED CARS" << endl;
    cout << "\t\t\t\t\t\t\t\t---------------------------------------------\n"<< endl;
    cout << "\t\t\t\t\t__________________________________________________________________________________________________________________\n"<< endl;
    cout << "\t\t\t\t\tUSER ID\t\t"<< "Name\t\t"<< "Car Name\t"<< "Car Price\t"<< "Car Model\t"<< "Qty\t\t"<< "RentDays";
    cout << "\n\t\t\t\t\t__________________________________________________________________________________________________________________" << endl;
    
    //enqueue data
    enQ("cs201003\tABDUL MALIK\tAudi\t\t256.00\t\t2016MD\t\t2\t\t4\t\t");
    enQ("cs201125\tSANJAY KUMAR\tHyundai\t\t249.00\t\t2017LA\t\t3\t\t2\t\t");
    enQ("cs201029\tAYUSH KUMAR\tToyota\t\t320.00\t\t2008PW\t\t1\t\t5\t\t");
    
    //print data
	display(front);
	//dequeue data
    deQ();
    deQ();
    deQ();

    getch();
    system("CLS");
}
