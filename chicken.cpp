
#include <string>
#include <iostream>
using namespace std;

class Chicken {

    string breed;
    short age;
    short health;
    string sound;
    short condition;

public:
    void setbreed(string st) { breed = st; }
    void setage(short a) { age = a; }
    void sethealth(short a) { health = a; }
    void setcondition(short a) { condition = a; }
    void setsound(string st) { sound = st; }

    string getbreed() { return breed; }
    short getage() { return age; }
    short gethealth() { return health; }
    short getcondition() { return condition; }
    string getsound() { return sound; }

    void moving()
    {
        if (health >= 0 && health <30)
        {
            cout << "�������� �ʰ� ������ �ɾ��ִ�" << endl;
        }
        else if (health >= 30 && health < 60)
        {
            cout << "�������� �ɾ�ٴѴ�" << endl;
        }
        else if (health >= 60 && health <= 100)
        {
            cout << "���ƴٴϰ� ��������" << endl;
        }
    }

    void crying()
    {
        if (condition >= 0 && condition < 50)
        {
            cout << "�����ϴ�...." << endl;
        }
        else if (condition >= 50 && condition <= 100)
        {
            cout << getsound() << endl;
        }
    }
};

int main()
{
    Chicken mychicken;

    mychicken.setbreed("������");
    mychicken.setage(3);
    mychicken.setsound("������~!!!!!");

    cout << "ǰ�� : " << mychicken.getbreed() << endl;
    cout << "���� : " << mychicken.getage() << endl;
    cout << endl << endl;

    mychicken.sethealth(60);
    mychicken.setcondition(70);
    mychicken.moving();
    mychicken.crying();

    cout << endl;
    system("pause");
    return 0;
}