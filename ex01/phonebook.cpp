
# include <string>
# include <iostream>

class contactClass
{
    private:
        int id;
        std::string fname;
        std::string lname;
        std::string secret;
        std::string nname;
        int phone;
    public:
    contactClass (std::string fnm, std::string lnm, std::string scrt, int ide, std::string nnm, int phn){
        id = ide;
        fname = fnm;
        lname = lnm;
        secret = scrt;
        nname = nnm;
        phone = phn;
    }
    contactClass(){
        id = 0;
        phone = 0;
        fname = "";
        lname = "";
        secret = "";
        nname = "";
    }
    int getID() { return id; }
    std::string getFname() { return fname; }
    std::string getLname() { return lname; }
    void displayContact() { 
        std::cout << phone << " " << nname << " " << secret << "\n";}
};

int main()
{
    int count;
    std::string command;
    contactClass array[8];
    //int id;
    std::string fname;
    std::string lname;
    std::string secret;
    std::string nname;
    int phone;

    count = 0;
    while(true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT):";
        std::cin >> command;
        if (command == "ADD")
        {
            std::cout << "Enter first name";
            std::cin >> fname;
            std::cout << "Enter last name";
            std::cin >> lname;
            std::cout << "Enter darkest secret";
            std::cin >> secret;
            std::cout << "Enter nickname";
            std::cin >> nname;
            std::cout << "Enter phone";
            std::cin >> phone;
            array[count] = contactClass(fname, lname, secret, count, nname, phone);
            count++;
        }
        else
            break;
    }

    
    // I think I need a while loop that reads from command line and do something based on user input.
    
    contactClass contactObj1("Alejo","Ram","NA",1,"alejiri",123456);
    std::cout << contactObj1.getID() << " " << contactObj1.getFname() << " " << contactObj1.getLname() << "\n";
    contactObj1.displayContact();
}