#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
class BaseKnight;
class Events;
enum ItemType {
    ANTIDOTE = 0,
    PHOENIXDOWNI,
    PHOENIXDOWNII,
    PHOENIXDOWNIII,
    PHOENIXDOWNIV
};
class BaseItem {
public:
    BaseItem();
    ~BaseItem();
    ItemType itemType = ANTIDOTE;
    virtual bool canUse(BaseKnight * knight) = 0;
    virtual void use(BaseKnight * knight) = 0;
    
};
class Antidote :public BaseItem {
public:
    Antidote();
    ~Antidote();
    bool canUse(BaseKnight * knight);
    void use(BaseKnight * knight);
};
class PhoenixDownI :public BaseItem {
public:
    PhoenixDownI();
    ~PhoenixDownI();
    bool canUse(BaseKnight * knight);
    void use(BaseKnight * knight);
};
class PhoenixDownII :public BaseItem {
public:
    PhoenixDownII();
    ~PhoenixDownII();
    bool canUse(BaseKnight * knight);
    void use(BaseKnight * knight);
};
class PhoenixDownIII :public BaseItem {
public:
    PhoenixDownIII();
    ~PhoenixDownIII();
    bool canUse(BaseKnight * knight);
    void use(BaseKnight * knight);
};
class PhoenixDownIV :public BaseItem {
public:
    PhoenixDownIV();
    ~PhoenixDownIV();
    bool canUse(BaseKnight * knight);
    void use(BaseKnight * knight);
};
struct node
{
    BaseItem* item;
    node* next;
};
class BaseBag {
public:
    BaseKnight * knight;
    node* bag = NULL;
    int maxItem = 0;
    BaseBag(BaseKnight* knight, int a, int b);
    ~BaseBag();
    virtual bool insertFirst(BaseItem * item);
    virtual BaseItem * get(ItemType itemType);
    virtual string toString() const;
};
class PalaBag : public BaseBag {
public:
    PalaBag(BaseKnight* knight, int a, int b) :BaseBag(knight, a, b) {};
    ~PalaBag() {};
    bool insertFirst(BaseItem* item);
};
class DraBag : public BaseBag {
public:
    DraBag(BaseKnight* knight, int a, int b) : BaseBag(knight, a, b) {
        maxItem = 14 - a;
        if (a > 0)
        {
            for (int i = 0; i < a; i++)
            {
                node* newNode = new node();
                newNode->item = new PhoenixDownI();
                newNode->next = NULL;
                if (bag == NULL)
                {
                    bag = newNode;
                }
                else
                {
                    newNode->next = bag;
                    bag = newNode;
                }
            }
        }
    };
    ~DraBag() {};
};
class LanBag : public BaseBag {
public:
    LanBag(BaseKnight* knight, int a, int b) : BaseBag(knight, a, b) {
        maxItem = 16 - a - b;
    };
    ~LanBag() {};

};
class NorBag : public BaseBag {
public:
    NorBag(BaseKnight* knight, int a, int b) : BaseBag(knight, a, b) {
        maxItem = 19 - a - b;
    };
    ~NorBag() {};
};

class BaseOpponent {
public:
    int eventID = 0;
    int levelO = 0;
    int gil = 0;
    int baseDamage = 0;
public:
    BaseOpponent() {};
    ~BaseOpponent() {};
    int get_levelO(int i);
};
class Madbear : public BaseOpponent {
public:
    Madbear(int i);
    ~Madbear() {};
};
class Bandit : public BaseOpponent {
public:
    Bandit(int i);
    Bandit() {};
};
class LordLupin :public BaseOpponent {
public:
    LordLupin(int i);
    ~LordLupin() {};
};
class Elf : public BaseOpponent {
public:
    Elf(int i);
    ~Elf() {};
};
class Troll : public BaseOpponent {
public:
    Troll(int i);
    ~Troll() {};
};
class Tornbery : public BaseOpponent {
public:
    Tornbery(int i);
    ~Tornbery() {};
};
class QueenOfCards :public BaseOpponent {
public:
    QueenOfCards(int i);
    ~QueenOfCards() {};
};
class NinaDerings :public BaseOpponent {
public:
    NinaDerings(int i);
    ~NinaDerings() {};
};
class DurianGarden :public BaseOpponent {
public:
    DurianGarden(int i);
    ~DurianGarden() {};
};
class OmegaWeapon :public BaseOpponent {
public:
    OmegaWeapon(int i);
    ~OmegaWeapon() {};
};
class Hades :public BaseOpponent {
public:
    Hades(int i);
    ~Hades() {};
};
enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    int phoenixdownI;
    int phoenixdownII = 0;
    int phoenixdownIII = 0;
    int phoenixdownIV = 0;
    BaseBag* bag;
    KnightType knightType;
public:
    bool posioned = false;
    BaseKnight(int id, int maxhp, int gil,int level, int antidote, int phoenixdownI);
    ~BaseKnight();
    int get_level();
    void set_level(int lv);
    int get_gil();
    void set_gil(int gil);
    int get_hp();
    void set_hp(int hp);
    int get_maxhp();
    int get_antidote();
    void set_antidote(int antidote);
    int get_phoenixdownI();
    void set_phoenixdownI(int phoenixdownI);
    int get_phoenixdownII();
    void set_phoenixdownII(int phoenixdownI);
    int get_phoenixdownIII();
    void set_phoenixdownIII(int phoenixdownI);
    int get_phoenixdownIV();
    void set_phoenixdownIV(int phoenixdownI);
    BaseBag* get_bag();
    KnightType get_knigthType();
    static BaseKnight* create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
};

class ArmyKnights {
public:
    bool meetOmega = false;
    bool meetHades = false;
    bool hasShield = false;
    bool hasSpear = false;
    bool hasHair = false;
    bool hasSword = false;
    int sum_Knight = 0;
    BaseKnight** knight = nullptr;
    ArmyKnights(const string& file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent* opponent);
    bool adventure(Events* events);
    int count() const;
    BaseKnight* lastKnight() const ;
    bool hasPaladinShield() const ;
    bool hasLancelotSpear() const ;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;
    void printInfo() const;
    void printResult(bool win) const;
};
class Events {
public:
    static int id_event;
    int sum_event = 0;
    int* arr_event = new int[1000];
    Events(const string & file_events);
    ~Events();

    int count() const ;
    int get(int i) const;
};

class KnightAdventure {
private:
    ArmyKnights* armyKnights;
    Events* events;

public:
    KnightAdventure();
    ~KnightAdventure(); // TODO:

    void loadArmyKnights(const string&);
    void loadEvents(const string&);
    void run();
};

#endif // __KNIGHT2_H__