
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
    contactClass(std::string fnm, std::string lnm, std::string scrt, int ide, std::string nnm, int phn){
        id = ide;
        fname = fnm;
        lname = lnm;
        secret = scrt;
        nname = nnm;
        phone = phn;
    }
};

int main()
{
    contactClass contactObj1("Alejo","Ram","NA",1,"alejiri",123456);
    cout << contactObj1.id << " " << contactObj1.fname << " " << contactObj1.phone << "\n";
}