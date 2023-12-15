#include<iostream>
#include <list>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

//folder creator
bool folderExists(const char* folderPath="data/") {
    DWORD dwAttrib = GetFileAttributesA(folderPath);
    return (dwAttrib != INVALID_FILE_ATTRIBUTES && (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

void first(){
    if( folderExists() == 0){
            CreateDirectoryA("data/", NULL);
        }

}


#define FPath "data/data.text"
#define DPath "data/data2.text"
#define FiPath "data/data3.text"
//variables:
int choice;
int choice1;
int choice2;
int dis;
int you = 0;
string newadd;
string newdis;
list<string> finished;
list<string> description = {"a program that ask qustion and get answers withe counter for a score","chossing a number and letting the computer guss it givin him hint in too low or too high or the opposite","programe that creat a randome password normaly or using spsific condition the user choos like not using numbers", "save the taskes in file set it as complete and modifing in it ","giving the user a random leter from a word withe a hint so he can find the word","save modifi delet and serch in contacts","program that can get anformation from any website (use spisific lyberary)","an normal x o game withe pc or other player"};
list<string> projects = {"Quiz game (easy)","Gussing a number (easy)","password creator (easy)","To-Do list (medium)","Hangman (medium)","Contact mangment (Hard)","web scraber (Hard)","Tic-Tac-To (Hard)"};
list<string>::iterator ptr = projects.begin();
list<string>::iterator dtr = description.begin();
list<string>::iterator ftr = finished.begin();

//add to list :
void addlist(){
string Fline;
string flin;
    ifstream myfile(FPath);
    ifstream myfile2(DPath);
    ifstream myfile3(FiPath); 
        if (myfile.is_open() && myfile2.is_open() ){
        projects = {};
        description = {};
        finished = {};

        while (getline(myfile, Fline)){
            projects.push_back(Fline);
        }
        while (getline(myfile2, Fline)){
            description.push_back(Fline);
        }
        while (getline(myfile3, flin)){
            finished.push_back(flin);
        }
    }else {
        
        if (you == 0){
        cout << "welcome withe us \n";
        _getch();
        cout<<"Press any key to continuo ";
        }
    }
}
//functions:
int home(){
    
        cout<<"==========================  Welcome to the Project manager pro  ===================="<<endl;
        cout<<"1 --- Project Lists \n";
        cout<<"2 --- Edit Project Lists \n";
        cout<<"3 --- Search for a Project in the Lists \n";
        cout<<"4 --- paramater\n";
        cout<<" press any other key to Exits \n";
        cout<<"choose a suported command : ";
        cin>>choice;
    return choice;
}

void describe(int option){
    int i = 0;
    for (string item : projects){
        if (i == option){
            cout <<"================"<<item<<"=============="<<endl;
        }
        i++;
    }
    i = 0;
    for (string disc : description){
        if (i == option){
            cout <<"================\n"<<disc<<"\n=============="<<endl;
            cout << endl;
        }
        i++;
    }
    
}
void DelAll(){
    remove("data/data.text");
    remove("data/data2.text");
    remove("data/data3.text");
    RemoveDirectoryA("data/");
    cout << "Done !!\n";
}

void refresh(string file,string file2){
        ofstream myfile;
        myfile.open(file, ios::out);
        myfile.close();
        myfile.open(file, ios::out | ios::app);
        for (string proj : projects){
            myfile << proj + "\n";            
        }
        myfile.close();
        ofstream myfile2;
        myfile2.open(file2, ios::out);
        myfile2.close();
        myfile2.open(file2, ios::out | ios::app);
        for (string disc : description){
            myfile2 << disc + "\n";            
        }
        myfile2.close();
}
void addtofin(string file3,string fini){
        ofstream myfile3;
        myfile3.open(file3, ios::out | ios::app);
        myfile3 << fini + "\n";
        myfile3.close();

    
}

void delit(int cho){
    list<string>::iterator ptr = projects.begin();
    list<string>::iterator dtr = description.begin();
    for (int i =1; i != cho;i++){
        ++ptr;
        ++dtr;
    }
    projects.erase(ptr);
    description.erase(dtr);
    refresh(FPath,DPath);
    cout << "Done!\n";

}
void wait(){
    cout<<"Press any key to continuo ...\n";
    _getch();
}

int main(){
    first();
    addlist();
    home();
    you = 1;
    cout<<"\n";
    if (choice == 1){
        int i = 1;
        cout <<"=================================\n";
        for (string project: projects){
              cout <<i <<"--"<<project<<endl;
            i++;  
        }
        cout <<"=================================\n";
        cout <<"1 -- Get Description about projects\n2 -- Finished projects list\n-- or pres any key to return to home screen\n";
        cin >> choice1;
        if (choice1 == 1){
            cout << "choose a project pleas : ";
            cin >> dis;
            describe(dis-1);
            wait();
            main();
        }else if (choice1 == 2){
            cout << "\n=================== Finished projects ==================\n";
            if (finished.empty()){
                cout <<"\nno finished project's for now !!\n";
                wait();
            }else{
                int i = 1;
                for (string item : finished){
                    cout << i << "---"<<item<<endl;
                    i++;
                }
            }
            cout << "\n==========================================================================\n";
            wait();
            main();
        }
    }else if (choice == 2){
        cout<<"==========================  Welcome to the Edit menu pro  ===================="<<endl;
        cout<<"1 --- to set project as  complete \n";
        cout<<"2 --- add new Project to the List \n";
        cout<<"3 --- to delete Project from the List \n";
        cout<<"4 --- to Edit an existant Project\n";
        cout<<" press any key to Exits \n";
        cout<<"choose a suported command : ";
        cin>>choice2;
        if (choice2 == 1){
            int i = 1;
        cout <<"=====================================================\n";
        for (string project : projects){
            cout <<i <<"--"<<project<<endl;
            i++;
        }
        cout << "what did you finished : ";
        int del;
        cin >> del;
        list<string>::iterator ptr = projects.begin();
        list<string>::iterator ftr = finished.begin();
        list<string>::iterator dtr = description.begin();
        for (int i =0; i!= del-1 ;i++){
            ++ptr;
            ++dtr;
        }
        finished.push_back(*ptr);
        projects.erase(ptr);
        description.erase(dtr);
        refresh(FPath,DPath);
        ofstream myfile3;
        myfile3.open(FiPath, ios::out | ios::trunc);
        myfile3.close();
        for (string item :finished ){
            addtofin(FiPath,item);
        }
        cout <<"Done!\n";
        wait();
        }else if(choice2 == 2){
            cout <<"=====================================================\n";
            cout << "put the name of the project and the difeculte(between a9wass) please : ";
            std::cin >> std::ws;
            getline(cin,newadd);
            cout << "put the discription of the project please : ";
            std::cin >> std::ws;
            getline(cin,newdis);
            projects.push_back(newadd);
            description.push_back(newdis) ;
            refresh(FPath,DPath);
            cout << "Done!\n";
            wait();
        }else if (choice2 == 3){
            cout <<"\n=====================================================\n";
            int i = 1;
            for (string item : projects){
                cout << i<<"---"<<item<<endl;
                i++;
            }
            int choice3;
            cout << "=====================================================\n";
            cout << "What to delete : ";
            cin >> choice3;
            delit(choice3);
            main();
            wait();
        }else if(choice2 == 4){
            int i = 1;
        cout <<"=================================\n";
        auto ptr = projects.begin();
        auto dtr = description.begin();
        for (string project: projects){
              cout <<i <<"--"<<project<<endl;
            i++;  
        }
        cout << "======================================================\n";
        int index;
        cout << "chose one to edit : ";
        cin >> index;
        index = index -1;
        int t;
        cout << "Editing the name (1) Yes (0) No : ";
        cin >> t;
        if (t == 1){
        cout << "the project new name :  ";
        string EditName;
        std::cin >> std::ws;
        getline(cin,EditName);
        advance(ptr,index);
        if (ptr != projects.end()) {
            *ptr = EditName; // Update the value at the specified position
        } else {
            cout << "Invalid Project !" << endl;
            wait();
        }
        }
        cout << "Editing the description (1) Yes (0) No : ";
        cin >> t;
        if (t == 1){
        cout << "the project new description : ";
        string EditDis;
        std::cin >> std::ws;
        getline(cin,EditDis);
        advance(dtr,index);
        if (ptr != projects.end()) {
            *dtr = EditDis;
        } else {
            cout << "Invalid Project !" << endl;
            wait();
        }
        }
        cout << "Done!!\n";
        refresh(FPath,DPath);
        wait();
            main();
        }else{
            wait();
            main();
        }
        main();
    }else if (choice == 3){
        cout << "==========================Welcome to the search Menu ===========================\n";
        cout << "search by the name or difficultly (part of the name or difficulty search is supported ) : ";
        string ser;
        std::cin >> std::ws;
        getline(cin,ser);
        for (char& x : ser) {
        x = tolower(x);
        }
//the serching prosses is fucking funney
        int i =1;
        bool prop = false ;
        auto ptr = projects.begin();
        auto dtr = description.begin();
        for(string proj : projects){
            
            for (char& p : proj) {
            p = tolower(p);
            }
            
            if (proj.find(ser) !=string::npos) {
                std::cout << i <<"---"<<proj<< '\n';
                i++;
                prop = true;
                cout << "=========================================\n";
                cout << *dtr<<endl;
                cout << "==========================================\n";
                
            } 
            ++ptr;
            ++dtr;
        }
                if (prop == false){
                cout << "sorry nothing was found !!\n";
                }
                wait();
    
    }else if (choice == 4){
        int par;
        string sure ;
        cout <<"1 -- Delete All Data \n2 -- Connects to the Data base \n -- any key to back to home screen\n choose a supported command : ";
        cin >> par;
        if (par == 1 ){
            cout << "Are you sure All the data will be erased with no way to restoret !!\n press '1' to confirm \n any other key to cancel : ";
            cin >>  sure;
            if (sure == "1"){
                DelAll();
                addlist();
                cout << "restart the app so that stupid thing undrstand (-_-)\n";
                wait();
            }else{
                //return 0;
                
            }
             
            
        }else if(par == 2 ){
            cout << "it turned out to be a lot of work so i cancel it so waill back to home screen pleas \n";
            wait();
            main();
        }
    }
    main();
    return 0;
}
