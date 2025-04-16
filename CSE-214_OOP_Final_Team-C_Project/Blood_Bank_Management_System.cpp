#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Donor
{
    protected:
        string name;
        string city;
        string area;
        string gender;
        string bloodType;
        string contactNumber;
        string gmailAddress;
        string lastDonationDate;
        bool availableInEmergency;

    public:
        virtual void inputDonorInfo(){}
        virtual void displayDonorInfo(){}

        void setName(string n) {name = n;}
        void setCity(string c) {city = c;}
        void setArea(string a) {area = a;}
        void setGender(string g) {gender = g;}
        void setBloodType(string bt) {bloodType = bt;}
        void setContactNumber(string cn) {contactNumber = cn;}
        void setGmailAddress(string ga) {gmailAddress = ga;}
        void setLastDonationDate(string ldd) {lastDonationDate = ldd;}
        void setAvailableInEmergency(bool aie) {availableInEmergency = aie;}

        string getBloodType() {return bloodType;}
        bool getAvailableInEmergency() {return availableInEmergency;}
};


class BloodBank : public Donor
{
    private:
        vector <Donor*> donors;

    public:
        void inputDonorInfo()
        {
            string n, g, bt, cn, ga, c, a, ldd;
            bool aie;

            cout << endl;
            cout << "\n\t\t\t\t\t\t\t\t\t\t >> Donor Information  :" << endl;
            cout << "\n\t\t\t\t\t\t\t\t\t\t -----------------------" << endl;

            cout << "\n\t\t\t\t\t\t\t  -> Enter Donor Name: ";
            cin.ignore();
            getline(cin, n);
            setName(n);

            cout << "\n\t\t\t\t\t\t\t  -> Enter Gender (M/F): ";
            cin >> g;
            setGender(g);

            cout << "\n\t\t\t\t\t\t\t  >> Enter blood type to search (A/B/AB/O +/-): ";
            cin >> bt;
            setBloodType(bt);

            cout << "\n\t\t\t\t\t\t\t  -> Enter Contact Number: ";
            cin >> cn;
            setContactNumber(cn);

            cout << "\n\t\t\t\t\t\t\t  -> Enter City: ";
            cin >> c;
            setCity(c);

            cout << "\n\t\t\t\t\t\t\t  -> Enter Area: ";
            cin >> a;
            setArea(a);

            cout << "\n\t\t\t\t\t\t\t  -> Enter Last Date of Donating Blood (DD/MM/YYYY): ";
            cin >> ldd;
            setLastDonationDate(ldd);

            cout << "\n\t\t\t\t\t\t\t  -> Available in Emergency Situation?  [1 -> Yes | 0 -> No]: ";
            cin >> aie;
            setAvailableInEmergency(aie);
            if(aie == 1)
                cout << "\n\t\t\t\t\t\t\t  -> Thank you for being available in emergencies! ";

            cout << "\n\t\t\t\t\t\t\t  -> Your details have been successfully saved. Thank you!\n\n";

            donors.push_back(this);
        }

        void displayDonorInfo()
        {
            cout << endl;
            cout << "\n\t\t\t\t\t\t\t  -> Name: " << name << endl;
            cout << "\n\t\t\t\t\t\t\t  -> Gender: " << gender << endl;
            cout << "\n\t\t\t\t\t\t\t  -> Blood Type: "<< bloodType << endl;
            cout << "\n\t\t\t\t\t\t\t  -> Contact Number: " << contactNumber << endl;
            cout << "\n\t\t\t\t\t\t\t  -> Gmail Address: " << gmailAddress << endl;
            cout << "\n\t\t\t\t\t\t\t  -> City: " << city << endl;
            cout << "\n\t\t\t\t\t\t\t  -> Area: " << area << endl;
            cout << "\n\t\t\t\t\t\t\t  -> Last Donation Date: " << lastDonationDate << endl;
            cout << "\n\t\t\t\t\t\t\t  -> Available in Emergency: " << (availableInEmergency ? "Yes" : "No") << endl;
        }

        void displayAllDonors()
        {
            if(donors.empty()){
                cout << "\n\t\t\t\t\t\t\t  [No donors found!]" << endl;
                return;
            }

            for(Donor* donor : donors){
                donor -> displayDonorInfo();
                cout << endl;
            }
        }

        bool displayEmergencyDonors()
        {
            for(Donor* donor : donors)
            {
                if(donor -> getAvailableInEmergency()){
                    return true;
                }
            }
            return false;
        }

        bool searchDonorByBloodType(const string& bloodGroup)
        {
            for(Donor* donor : donors)
            {
                if(donor -> getBloodType() == bloodGroup){
                    return true;
                }
            }
            return false;
        }
};

class Blood_Bank_Management_System
{
    private:
        vector <BloodBank*> bloodBanks;

    public:
        void run()
        {
            int choice;

            do{
                cout << "\t\t\t\t\t\t\t\t\t\t =====================================";
                cout << "\n\t\t\t\t\t\t\t\t\t\t BLOOD BANK MANAGEMENT SYSTEM" << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t            MAIN MENU"<<endl;
                cout << "\t\t\t\t\t\t\t\t\t\t =====================================";
                cout << "\n\n\n";

                cout << "\n\t\t\t\t\t\t\t  1. Add Donor" << endl;
                cout << "\n\t\t\t\t\t\t\t  2. Display Donors" << endl;
                cout << "\n\t\t\t\t\t\t\t  3. Search Donors by Blood Type" << endl;
                cout << "\n\t\t\t\t\t\t\t  4. Emergency Situation" << endl;
                cout << "\n\t\t\t\t\t\t\t  5. Exit" << endl;
                cout << "\n\n\t\t\t\t\t\t\t  -> Enter your choice: ";
                cin >> choice;

                switch(choice)
                {
                    case 1: {
                        BloodBank* newBloodbank = new BloodBank();
                        newBloodbank -> inputDonorInfo();
                        bloodBanks.push_back(newBloodbank);
                        break;
                    }

                    case 2: {
                        if(!bloodBanks.empty())
                        {
                            cout << "\n\t\t\t\t\t\t\t\t\t\t >> Available Donors   :" << endl;
                            cout << "\n\t\t\t\t\t\t\t\t\t\t -----------------------" << endl;

                            int donorCount = 1;
                            for(BloodBank* bloodBank : bloodBanks)
                            {
                                if(donorCount > 1) cout << "\n\n";
                                cout << "\n\t\t\t\t\t\t\t Donor " << donorCount++ << ":" << endl;
                                bloodBank -> displayAllDonors();
                            }
                        }
                        else
                            cout << "\n\t\t\t\t\t\t\t  [No donors to display!]" << endl;
                        break;
                    }

                    case 3: {
                        cout << "\n\t\t\t\t\t\t\t  Enter blood group to search: ";
                        string bloodGroup;
                        cin >> bloodGroup;

                        int donorCount = 1;
                        if(!bloodBanks.empty())
                        {
                            cout << "\n\t\t\t\t\t\t\t\t\t\t >> Available Donors with Blood Group " << bloodGroup << endl;
                            cout << "\n\t\t\t\t\t\t\t\t\t\t -------------------------------------" << endl;

                            bool found = false;
                            for(BloodBank* bloodBank : bloodBanks)
                            {
                                if(donorCount > 1) cout << "\n\n";

                                if(bloodBank -> searchDonorByBloodType(bloodGroup))
                                {
                                    cout << "\n\t\t\t\t\t\t\t Donor " << donorCount++ << ":" << endl;
                                    bloodBank  -> displayDonorInfo();
                                    found = true;
                                }
                            }
                            if(!found)
                                cout << "\n\t\t\t\t\t\t\t  [No donor found with blood type: " << bloodGroup << "]" << endl;
                        }
                        else
                            cout << "\n\t\t\t\t\t\t\t  [No donors to search!]" << endl;
                        break;
                    }

                    case 4: {
                        int donorCount = 1;
                        if(!bloodBanks.empty())
                        {
                            cout << "\n\t\t\t\t\t\t\t\t\t\t >> Available Donors in Emergency   :" << endl;
                            cout << "\n\t\t\t\t\t\t\t\t\t\t ------------------------------------" << endl;

                            bool found = false;
                            for(BloodBank* bloodBank : bloodBanks)
                            {
                                if(donorCount > 1) cout << "\n\n";

                                if(bloodBank -> displayEmergencyDonors())
                                {
                                    cout << "\n\t\t\t\t\t\t\t Donor " << donorCount++ << ":" << endl;
                                    bloodBank  -> displayDonorInfo();
                                    found = true;
                                }
                            }
                            if(!found)
                                cout << "\n\t\t\t\t\t\t\t  [No donors available in emergency!]" << endl;
                        }
                        else
                            cout << "\n\t\t\t\t\t\t\t  [No donors to check!]" << endl;
                        break;
                    }
                    case 5:
                        cout << "\n\t\t\t\t\t\t\t\t\t ------------>> Exiting the program <<------------" << endl;
                        break;

                    default:
                        cout << "\n\t\t\t\t\t\t\t  [Invalid choice. Try again.]" << endl;
                        break;
                }
            } while(choice != 5);

            for(BloodBank* bloodBank : bloodBanks){
                delete bloodBank;
            }
        }
};

int main()
{
    Blood_Bank_Management_System system;
    system.run();

    return 0;
}
