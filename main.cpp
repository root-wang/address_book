#include <iostream>
#include <string>
#include <fstream>

#define Max 1001
using namespace std;

struct data{
    string m_Name;
    string m_tele;
    int m_Num=0;
};

struct list{
    data p[Max];
    int num=0;
}list1;

void showMenu(){
    cout << "***********************\n";
    cout << "***** 1、添加联系人 *****\n";
    cout << "***** 2、显示联系人 *****\n";
    cout << "***** 3、删除联系人 *****\n";
    cout << "***** 4、查找联系人 *****\n";
    cout << "***** 5、修改联系人 *****\n";
    cout << "***** 6、清空联系人 *****\n";
    cout << "***** 0、退出通讯录 *****\n";
    cout << "***********************\n";
}

void addContacts(){
    string name;
    string tele;
    cin >> name;
    cin >> tele;
    list1.p[list1.num].m_Num=list1.num+1;
    list1.p[list1.num].m_Name=name;
    list1.p[list1.num].m_tele=tele;
    list1.num++;
    system("pause");
    system("cls");
}

void showContacts(){
    int i=0;
    while(i<list1.num) {
        cout << list1.p[i].m_Num << "、" << list1.p[i].m_Name << "-" << list1.p[i].m_tele;
        cout << endl;
        //ofstream out("F:\\code\\C++\\address_book:address.txt");
        //out << list1.p[i].m_Num << "、" << list1.p[i].m_Name << "-" << list1.p[i].m_tele;
        //out << endl;
        i++;
    }
    system("pause");
    system("cls");
}

void deleteContacts(){
    showContacts();
    int num;
    cin >> num;
    for(int i=num-1;i<list1.num;i++){
        list1.p[i].m_Name=list1.p[i+1].m_Name;
        list1.p[i].m_tele=list1.p[i+1].m_tele;
    }
    list1.num--;
    system("pause");
    system("cls");
}

void findContacts(){
    string name;
    string tele;
    int select;
    cout << "输入1来选择使用名字查询；输入2来选择使用号码查询 \n";
    cin >> select;
    if(1==select){
        cin >> name;
        for(int i=0;i<list1.num;i++){
            if(name==list1.p[i].m_Name){
                cout << list1.p[i].m_Num << "、" << list1.p[i].m_Name << "-" << list1.p[i].m_tele;
                cout << endl;
            }
        }
    }
    else{
        cin >> tele;
        for(int i=0;i<list1.num;i++){
            if(tele==list1.p[i].m_tele){
                cout << list1.p[i].m_Num << "、" << list1.p[i].m_Name << "-" << list1.p[i].m_tele;
                cout << endl;
            }
        }
    }
    system("pause");
    system("cls");
}

void changeContacts(){

}

void clearContacts(){
    int check;
    cout << "请输入1来确认清空\n";
    cin >> check;
    if(1==check){
        //for(int i=0;i<list1.num;i++){
        //    list1.p[i].m_tele.clear();
        //    list1.p[i].m_Name.clear();
        //    list1.p[i].m_Num=0;
        //}
        list1.num=0;
    }
    system("pause");
    system("cls");
}


int main() {
    char ch;
    while(true){
        showMenu();
        cin.get(ch);
        switch(ch){
            case '1':addContacts();break;
            case '2':showContacts();break;
            case '3':deleteContacts();break;
            case '4':findContacts();break;
            case '5':changeContacts();break;
            case '6':clearContacts();break;
            case '0':cout << "欢迎下次使用"<<endl; return 0;
            default:break;
        }
        cin.get(ch);
    }
}
