
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
            cout << "움직이지 않고 가만히 앉아있다" << endl;
        }
        else if (health >= 30 && health < 60)
        {
            cout << "설렁설렁 걸어다닌다" << endl;
        }
        else if (health >= 60 && health <= 100)
        {
            cout << "날아다니고 난리났다" << endl;
        }
    }

    void crying()
    {
        if (condition >= 0 && condition < 50)
        {
            cout << "잠잠하다...." << endl;
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

    mychicken.setbreed("토종닭");
    mychicken.setage(3);
    mychicken.setsound("꼬끼오~!!!!!");

    cout << "품종 : " << mychicken.getbreed() << endl;
    cout << "나이 : " << mychicken.getage() << endl;
    cout << endl << endl;

    mychicken.sethealth(60);
    mychicken.setcondition(70);
    mychicken.moving();
    mychicken.crying();

    cout << endl;
    system("pause");
    return 0;
}