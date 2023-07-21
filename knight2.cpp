#include "knight2.h"

bool is_prime(int hp) {
    if (hp <= 1) return false;
    for (int i = 2; i <= sqrt(hp); i++) {
        if (hp % i == 0) return false;
    }
    return true;
}
bool pythagoras(int hp) {
    int a, b, c;
    int temp = hp;
    a = hp % 10;
    temp = hp / 10;
    b = temp % 10;
    c = temp / 10;
    if (a * a == b * b + c * c || b * b == a * a + c * c || b * b + a * a == c * c) {
        return true;
    }
    else {
        return false;
    }
}
/* * * BEGIN implementation of class BaseBag * * */
BaseBag::BaseBag(BaseKnight* knight, int a, int b){
    maxItem = 0;
    this->knight = knight;
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
    if (b > 0) {
        for (int i = 0; i < b; i++)
        {
            node* newNode = new node();
            newNode->item = new Antidote();
            newNode->next = NULL;
            if (bag == NULL)
            {
                bag = newNode;
            }
            else {
                newNode->next = bag;
                bag = newNode;
            }
        }
    }
}
BaseBag::~BaseBag(){
    delete knight;
    delete bag;
}
bool BaseBag::insertFirst(BaseItem* item) {
    if (maxItem <= 0)
    {
        return false;
    }
    else {
        node* newNode = new node();
        newNode->item = item;
        newNode->next = this->bag;
        this->bag = newNode;
        maxItem--;
        return true;
    }
}
BaseItem* BaseBag::get(ItemType itemType) {
    node* current = this->bag;
    node* prev = NULL;
    while (current != NULL) {
        if (current->item->itemType == itemType)
        {
            BaseItem* foundItem = current->item;
            if (prev == NULL)
            {
                this->bag = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            this->maxItem++;
            return foundItem;
        }
        prev = current;
        current = current->next;
    }
    return NULL;
}
string BaseBag::toString() const {
    string result;
    int count = 0;
    node* head = bag;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    result = "Bag[count=" + to_string(count) + ";";
    node* head2 = bag;
    while (head2 != NULL)
    {
        if (head2 != bag)
        {
            result += ",";
        }
        if (head2->item->itemType == ANTIDOTE)
        {
            result += "Antidote";
        }
        else if (head2->item->itemType == PHOENIXDOWNI) {
            result += "PhoenixI";
        }
        else if (head2->item->itemType == PHOENIXDOWNII) {
            result += "PhoenixII";
        }
        else if (head2->item->itemType == PHOENIXDOWNIII) {
            result += "PhoenixIII";
        }
        else if (head2->item->itemType == PHOENIXDOWNIV) {
            result += "PhoenixIV";
        }
        head2 = head2->next;
    }
    result += "]";
    return result;
}
bool PalaBag::insertFirst(BaseItem* item) {
    node* newNode = new node();
    newNode->item = item;
    newNode->next = bag;
    bag = newNode;
    maxItem--;
    return true;
}


/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}
BaseKnight::BaseKnight(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote) {
    this->id = id;
    this->maxhp = maxhp;
    this->hp = maxhp;
    this->gil = gil;
    this->level = level;
    this->antidote = antidote;
    this->phoenixdownI = phoenixdownI;
    this->knightType = NORMAL;
    this->bag = NULL;
}
BaseKnight::~BaseKnight() {

}
int BaseKnight::get_level() {
    return this->level;
}
void BaseKnight::set_level(int lv) {
    this->level = lv;
}
int BaseKnight::get_gil() {
    return this->gil;
}
void BaseKnight::set_gil(int gil) {
    this->gil = gil;
}
int BaseKnight::get_hp() {
    return this->hp;
}
void BaseKnight::set_hp(int hp) {
    this->hp = hp;
}
int BaseKnight::get_maxhp() {
    return this->maxhp;
}
int BaseKnight::get_antidote() {
    return this->antidote;
}
void BaseKnight::set_antidote(int antidote) {
    this->antidote = antidote;
}
int BaseKnight::get_phoenixdownI() {
    return this->phoenixdownI;
}
void BaseKnight::set_phoenixdownI(int phoenixdownI) {
    this->phoenixdownI = phoenixdownI;
}
int BaseKnight::get_phoenixdownII() {
    return this->phoenixdownII;
}
void BaseKnight::set_phoenixdownII(int phoenixdownII) {
    this->phoenixdownII = phoenixdownII;
}
int BaseKnight::get_phoenixdownIII() {
    return this->phoenixdownIII;
}
void BaseKnight::set_phoenixdownIII(int phoenixdownIII) {
    this->phoenixdownIII = phoenixdownIII;
}
int BaseKnight::get_phoenixdownIV() {
    return this->phoenixdownIV;
}
void BaseKnight::set_phoenixdownIV(int phoenixdownIV) {
    this->phoenixdownIV = phoenixdownIV;
}
BaseBag* BaseKnight::get_bag() {
    return this->bag;
}
KnightType BaseKnight::get_knigthType() {
    return this->knightType;
}
BaseKnight* BaseKnight::create(int id, int maxhp, int level, int phoenixdownI, int gil, int antidote) {
    BaseKnight* knight;
    if (is_prime(maxhp)) {
        knight = new BaseKnight(id, maxhp, level, phoenixdownI, gil, antidote);
        knight->knightType = PALADIN;
        knight->bag = new PalaBag(knight, phoenixdownI, antidote);
    }
    else if (maxhp == 888) {
        knight = new BaseKnight(id, maxhp, level, phoenixdownI, gil, antidote);
        knight->knightType = LANCELOT;
        knight->bag = new LanBag(knight, phoenixdownI, antidote);
    }
    else if (pythagoras(maxhp)) {
        knight = new BaseKnight(id, maxhp, level, phoenixdownI, gil, antidote);
        knight->knightType = DRAGON;
        knight->bag = new DraBag(knight, phoenixdownI, antidote);
    }
    else {
        knight = new BaseKnight(id, maxhp, level, phoenixdownI, gil, antidote);
        knight->knightType = NORMAL;
        knight->bag = new NorBag(knight, phoenixdownI, antidote);
    }
    return knight;
}


/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}
ArmyKnights::ArmyKnights(const string& file_armyknights) {
    ifstream input2(file_armyknights);
    if (input2.is_open())
    {
        input2 >> sum_Knight;
        knight = new BaseKnight * [sum_Knight];
        for (int id = 0; id < sum_Knight; id++)
        {
            int hp, level, phoenixdownI, gil, antidote;
            input2 >> hp >> level >> phoenixdownI >> gil >> antidote;
            knight[id] = BaseKnight::create(id + 1, hp, level, phoenixdownI, gil, antidote);
        }
    }
    input2.close();
};

ArmyKnights::~ArmyKnights() {
    for (int id = 0; id < sum_Knight; id++) {
        delete knight[id];
    }
    delete[] knight;
}

int ArmyKnights::count() const {
    return sum_Knight;
};
BaseKnight* ArmyKnights::lastKnight() const {
    if (sum_Knight > 0)
    {
        return knight[sum_Knight - 1];
    }
    else
    {
        return NULL;
    }
};
bool ArmyKnights::hasPaladinShield() const {
    return hasShield;
};
bool ArmyKnights::hasLancelotSpear() const {
    return hasSpear;
};
bool ArmyKnights::hasGuinevereHair() const {
    return hasHair;
};
bool ArmyKnights::hasExcaliburSword() const {
    return hasSword;
};

bool ArmyKnights::fight(BaseOpponent* opponent) {
    BaseItem* item;
  
    if (opponent->eventID == 1)
    {
        if (lastKnight()->get_level() >= opponent->levelO || lastKnight()->get_knigthType() == LANCELOT || lastKnight()->get_knigthType() == PALADIN) {
            lastKnight()->set_gil(lastKnight()->get_gil() + opponent->gil);
            if (lastKnight()->get_gil() > 999) {
                lastKnight()->set_gil(999);
            }          
            return true;
        }
        else {
            int dame = opponent->baseDamage * (opponent->levelO - lastKnight()->get_level());
            lastKnight()->set_hp(lastKnight()->get_hp() - dame);
            node* temp_bag = lastKnight()->get_bag()->bag;
            while (temp_bag != NULL)
            {
                if (temp_bag->item->itemType == PHOENIXDOWNI)
                {
                    item = new PhoenixDownI();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNII) {
                    item = new PhoenixDownII();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNIII) {
                    item = new PhoenixDownIII();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNIV) {
                    item = new PhoenixDownIV();
                    item->use(lastKnight());
                }
                temp_bag = temp_bag->next;
            }
            delete temp_bag;
            if (lastKnight()->get_hp() <= 0)
            {
                if (lastKnight()->get_gil() >= 100)
                {
                    lastKnight()->set_gil(lastKnight()->get_gil() - 100);
                    lastKnight()->set_hp(lastKnight()->get_maxhp() *1.0/ 2);
                    return true;
                }
                else {
                    return false;
                }
            }
            else return true;
        }
    }
    else if (opponent->eventID == 2)
    {
        if (lastKnight()->get_level() >= opponent->levelO || lastKnight()->get_knigthType() == LANCELOT || lastKnight()->get_knigthType() == PALADIN) {
            lastKnight()->set_gil(lastKnight()->get_gil() + opponent->gil);
            if (lastKnight()->get_gil() > 999) {
                lastKnight()->set_gil(999);
            }
            return true;
        }
        else {
            int dame = opponent->baseDamage * (opponent->levelO - lastKnight()->get_level());
            lastKnight()->set_hp(lastKnight()->get_hp() - dame);
            node* temp_bag = lastKnight()->get_bag()->bag;
            while (temp_bag != NULL)
            {
                if (temp_bag->item->itemType == PHOENIXDOWNI)
                {
                    item = new PhoenixDownI();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNII) {
                    item = new PhoenixDownII();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNIII) {
                    item = new PhoenixDownIII();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNIV) {
                    item = new PhoenixDownIV();
                    item->use(lastKnight());
                }
                temp_bag = temp_bag->next;
            }
            delete temp_bag;
            if (lastKnight()->get_hp() <= 0)
            {
                if (lastKnight()->get_gil() >= 100)
                {
                    lastKnight()->set_gil(lastKnight()->get_gil() - 100);
                    lastKnight()->set_hp(lastKnight()->get_maxhp() *1.0 / 2);
                    return true;
                }
                else {
                    return false;
                }
            }
            else return true;
        }
    }
    else if (opponent->eventID == 3)
    {
        if (lastKnight()->get_level() >= opponent->levelO || lastKnight()->get_knigthType() == LANCELOT || lastKnight()->get_knigthType() == PALADIN) {
            lastKnight()->set_gil(lastKnight()->get_gil() + opponent->gil);
            if (lastKnight()->get_gil() > 999) {
                lastKnight()->set_gil(999);
            }
            return true;
        }
        else {
            int dame = opponent->baseDamage * (opponent->levelO - lastKnight()->get_level());
            lastKnight()->set_hp(lastKnight()->get_hp() - dame);
            node* temp_bag = lastKnight()->get_bag()->bag;
            while (temp_bag != NULL)
            {
                if (temp_bag->item->itemType == PHOENIXDOWNI)
                {
                    item = new PhoenixDownI();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNII) {
                    item = new PhoenixDownII();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNIII) {
                    item = new PhoenixDownIII();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNIV) {
                    item = new PhoenixDownIV();
                    item->use(lastKnight());
                }
                temp_bag = temp_bag->next;
            }
            delete temp_bag;
            if (lastKnight()->get_hp() <= 0)
            {
                if (lastKnight()->get_gil() >= 100)
                {
                    lastKnight()->set_gil(lastKnight()->get_gil() - 100);
                    lastKnight()->set_hp(lastKnight()->get_maxhp() *1.0/ 2);
                    return true;
                }
                else {
                    return false;
                }
            }
            else return true;
        }
    }
    else if (opponent->eventID == 4)
    {
        if (lastKnight()->get_level() >= opponent->levelO || lastKnight()->get_knigthType() == LANCELOT || lastKnight()->get_knigthType() == PALADIN) {
            lastKnight()->set_gil(lastKnight()->get_gil() + opponent->gil);
            if (lastKnight()->get_gil() > 999) {
                lastKnight()->set_gil(999);
            }
            return true;
        }
        else {
            int dame = opponent->baseDamage * (opponent->levelO - lastKnight()->get_level());
            lastKnight()->set_hp(lastKnight()->get_hp() - dame);
            node* temp_bag = lastKnight()->get_bag()->bag;
            while (temp_bag != NULL)
            {
                if (temp_bag->item->itemType == PHOENIXDOWNI)
                {
                    item = new PhoenixDownI();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNII) {
                    item = new PhoenixDownII();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNIII) {
                    item = new PhoenixDownIII();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNIV) {
                    item = new PhoenixDownIV();
                    item->use(lastKnight());
                }
                temp_bag = temp_bag->next;
            }
            delete temp_bag;

            if (lastKnight()->get_hp() <= 0)
            {
                if (lastKnight()->get_gil() >= 100)
                {
                    lastKnight()->set_gil(lastKnight()->get_gil() - 100);
                    lastKnight()->set_hp(lastKnight()->get_maxhp() *1.0/ 2);
                    return true;
                }
                else {
                    return false;
                }
            }
            else return true;
        }
    }
    else if (opponent->eventID == 5)
    {
        if (lastKnight()->get_level() >= opponent->levelO || lastKnight()->get_knigthType() == LANCELOT || lastKnight()->get_knigthType() == PALADIN) {
            lastKnight()->set_gil(lastKnight()->get_gil() + opponent->gil);
            if (lastKnight()->get_gil() > 999) {
                lastKnight()->set_gil(999);
            }
            return true;
        }
        else {
            int dame = opponent->baseDamage * (opponent->levelO - lastKnight()->get_level());
            lastKnight()->set_hp(lastKnight()->get_hp() - dame);
            node* temp_bag = lastKnight()->get_bag()->bag;
            while (temp_bag != NULL)
            {
                if (temp_bag->item->itemType == PHOENIXDOWNI)
                {
                    item = new PhoenixDownI();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNII) {
                    item = new PhoenixDownII();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNIII) {
                    item = new PhoenixDownIII();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNIV) {
                    item = new PhoenixDownIV();
                    item->use(lastKnight());
                }
                temp_bag = temp_bag->next;
            }
            delete temp_bag;
  /*          item = new PhoenixDownI();
            item->use(lastKnight());
            item = new PhoenixDownII();
            item->use(lastKnight());
            item = new PhoenixDownIII();
            item->use(lastKnight());
            item = new PhoenixDownIV();
            item->use(lastKnight());*/
            if (lastKnight()->get_hp() <= 0)
            {
                if (lastKnight()->get_gil() >= 100)
                {
                    lastKnight()->set_gil(lastKnight()->get_gil() - 100);
                    lastKnight()->set_hp(lastKnight()->get_maxhp() *1.0/ 2);
                    return true;
                }
                else {
                    return false;
                }
            }
            else return true;
        }
    }
    else if (opponent->eventID == 6)
    {
        if (lastKnight()->get_level() >= opponent->levelO) {
            if (lastKnight()->get_level() <10)
            {
                lastKnight()->set_level(lastKnight()->get_level() + 1);
            }
            return true;
        }
        else {
            if (lastKnight()->get_knigthType() == DRAGON)
            {
                lastKnight()->posioned = false;
                return true;
            }
            else {
                lastKnight()->posioned = true;
                if (lastKnight()->posioned) {
                    item = new Antidote();
                    item->use(lastKnight());
                }
                node* temp_bag = lastKnight()->get_bag()->bag;
                while (temp_bag != NULL)
                {
                    if (temp_bag->item->itemType == PHOENIXDOWNI)
                    {
                        item = new PhoenixDownI();
                        item->use(lastKnight());
                    }
                    else if (temp_bag->item->itemType == PHOENIXDOWNII) {
                        item = new PhoenixDownII();
                        item->use(lastKnight());
                    }
                    else if (temp_bag->item->itemType == PHOENIXDOWNIII) {
                        item = new PhoenixDownIII();
                        item->use(lastKnight());
                    }
                    else if (temp_bag->item->itemType == PHOENIXDOWNIV) {
                        item = new PhoenixDownIV();
                        item->use(lastKnight());
                    }
                    temp_bag = temp_bag->next;
                }
                delete temp_bag;
                if (lastKnight()->get_hp() <= 0)
                {
                    if (lastKnight()->get_gil() >= 100)
                    {
                        lastKnight()->set_gil(lastKnight()->get_gil() - 100);
                        lastKnight()->set_hp(lastKnight()->get_maxhp() *1.0/ 2);
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else return true;
            }
        }
    }
    else if (opponent->eventID == 7)
    {
        if (lastKnight()->get_level() >= opponent->levelO) {
            lastKnight()->set_gil(lastKnight()->get_gil()*2);
            if (lastKnight()->get_gil() > 999)
            {
                int a = 1;
                lastKnight()->set_gil(999);
                int gil_residual = lastKnight()->get_gil() - 999;
                while (gil_residual >0 && a != (sum_Knight-1))
                {
                    knight[sum_Knight - a - 1]->set_gil(knight[sum_Knight - a -1]->get_gil()+gil_residual);
                    if (knight[sum_Knight -a - 1]->get_gil()>999)
                    {
                        knight[sum_Knight - a - 1]->set_gil(999);
                        gil_residual = knight[sum_Knight - a - 1]->get_gil() - 999;
                    }
                    else {
                        gil_residual = 0;
                    }
                    a++;
                }
            }
        }
        else {
            if(lastKnight()->get_knigthType() != PALADIN)
            lastKnight()->set_gil(lastKnight()->get_gil() *1.0/ 2);
        }
        return true;
    }
    else if (opponent->eventID == 8)
    {
        if (lastKnight()->get_knigthType() == PALADIN && lastKnight()->get_hp() < lastKnight()->get_maxhp() *1.0/ 3)
        {
            lastKnight()->set_hp(lastKnight()->get_hp() + 1.0 / 5 * lastKnight()->get_maxhp());
        }
        if (lastKnight()->get_gil() >= 50 && lastKnight()->get_hp() < lastKnight()->get_maxhp()*1.0/3 && lastKnight()->get_knigthType() != PALADIN) {
            lastKnight()->set_gil(lastKnight()->get_gil() - 50);
            lastKnight()->set_hp(lastKnight()->get_hp() + 1.0 / 5 * lastKnight()->get_maxhp());
        }
        return true;
    }
    else if (opponent->eventID == 9)
    {
        lastKnight()->set_hp(lastKnight()->get_maxhp());
        return true;
    }
    else if (opponent->eventID == 10 && !meetOmega)
    {
        meetOmega = true;
        if (lastKnight()->get_level() == 10 && lastKnight()->get_hp() == lastKnight()->get_maxhp()){
            lastKnight()->set_level(10);
            lastKnight()->set_gil(999);
            return true;
        }
        else {
            lastKnight()->set_hp(0);
            node* temp_bag = lastKnight()->get_bag()->bag;
            while (temp_bag != NULL)
            {
                if (temp_bag->item->itemType == PHOENIXDOWNI)
                {
                    item = new PhoenixDownI();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNII) {
                    item = new PhoenixDownII();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNIII) {
                    item = new PhoenixDownIII();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNIV) {
                    item = new PhoenixDownIV();
                    item->use(lastKnight());
                }
                temp_bag = temp_bag->next;
            }
            delete temp_bag;
            if (lastKnight()->get_hp() <= 0)
            {
                if (lastKnight()->get_gil() >= 100)
                {
                    lastKnight()->set_gil(lastKnight()->get_gil() - 100);
                    lastKnight()->set_hp(lastKnight()->get_maxhp() *1.0/ 2);
                    return true;
                }
                else {
                    meetOmega = false;
                    return false;
                }
            }
            else return true;
        }
    }
    else if (opponent->eventID == 11 && !meetHades)
    {
        meetHades = true;
        if (lastKnight()->get_level() == 10|| (lastKnight()->get_level()>=8 && lastKnight()->get_knigthType() == PALADIN)) {
            hasShield = true;
            return true;
        }
        else {
            lastKnight()->set_hp(0);
            node* temp_bag = lastKnight()->get_bag()->bag;
            while (temp_bag != NULL)
            {
                if (temp_bag->item->itemType == PHOENIXDOWNI)
                {
                    item = new PhoenixDownI();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNII) {
                    item = new PhoenixDownII();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNIII) {
                    item = new PhoenixDownIII();
                    item->use(lastKnight());
                }
                else if (temp_bag->item->itemType == PHOENIXDOWNIV) {
                    item = new PhoenixDownIV();
                    item->use(lastKnight());
                }
                temp_bag = temp_bag->next;
            }
            delete temp_bag;
            if (lastKnight()->get_hp() <= 0)
            {
                if (lastKnight()->get_gil() >= 100)
                {
                    lastKnight()->set_gil(lastKnight()->get_gil() - 100);
                    lastKnight()->set_hp(lastKnight()->get_maxhp() *1.0/ 2);
                    return true;
                }
                else {
                    meetHades = false;
                    return false;
                }
            }
            else return true;
        }
    }
    return false;
}
bool ArmyKnights::adventure(Events* events) {
    for (int i = 0; i < events->count() ; i++)
    {
        if (events->get(i) == 1)
        {
            if (fight(new Madbear(i))) {
                printInfo();
                continue;
            }
            else {
                sum_Knight--;
            }
            if (sum_Knight ==0) break;
            printInfo();
        }
        else if (events->get(i) == 2) {
            if (fight(new Bandit(i))) {
                printInfo();
                continue;
            }
            else sum_Knight--; 
            if (sum_Knight == 0) break;
            printInfo();
        }
        else if (events->get(i) == 3) {
            if (fight(new LordLupin(i))) {
                printInfo();
                continue;
            }
            else sum_Knight--;
            if (sum_Knight == 0) break;
            printInfo();
        }
        else if (events->get(i) == 4) {
            if (fight(new Elf(i))) {
                printInfo();
                continue;
            }
            else sum_Knight--;
            if (sum_Knight == 0) break;
            printInfo();
        }
        else if (events->get(i) == 5) {
            if (fight(new Troll(i))) {
                printInfo();
                continue;
            }
            else sum_Knight--;
            if (sum_Knight == 0) break;
            printInfo();
        }
        else if (events->get(i) == 6) {
            if (fight(new Tornbery(i))) {
                printInfo();
                continue;
            }
            else sum_Knight--;
            if (sum_Knight == 0) break;
            printInfo();
        }
        else if (events->get(i) == 7) {
            if (fight(new QueenOfCards(i))) {
                printInfo();
                continue;
            }
            else sum_Knight--;
            if (sum_Knight == 0) break;
            printInfo();
        }
        else if (events->get(i) == 8) {
            if (fight(new NinaDerings(i))) {
                printInfo();
                continue;
            }
            else sum_Knight--;
            if (sum_Knight == 0) break;
            printInfo();
        }
        else if (events->get(i) == 9) {
            if (fight(new DurianGarden(i))) {
                printInfo();
                continue;
            }
            else sum_Knight--;
            if (sum_Knight == 0) break;
            printInfo();
        }
        else if (events->get(i) == 10) {
            if (meetOmega)
            {
                printInfo();
                continue;
            }
            if (fight(new OmegaWeapon(i))) {
                printInfo();
                continue;
            }
            else sum_Knight--;
            if (sum_Knight == 0) break;
            printInfo();
        }
        else if (events->get(i) == 11) {\
            if (meetHades)
            {
                printInfo();
                continue;
            }
            if (fight(new Hades(i))) {
                printInfo();
                continue;
            }
            else sum_Knight--;
            if (sum_Knight == 0) break;
            printInfo();
        }
        else if (events->get(i) == 112) {
            lastKnight()->get_bag()->insertFirst(new PhoenixDownII());
            lastKnight()->set_phoenixdownII(lastKnight()->get_phoenixdownII() + 1);
            printInfo();
            continue;
        }
        else if (events->get(i) == 113) {
            lastKnight()->get_bag()->insertFirst(new PhoenixDownIII());
            lastKnight()->set_phoenixdownIII(lastKnight()->get_phoenixdownIII() + 1);
            printInfo();
            continue;
        }
        else if (events->get(i) == 114) {
            lastKnight()->get_bag()->insertFirst(new PhoenixDownIV());
            lastKnight()->set_phoenixdownIV(lastKnight()->get_phoenixdownIV() + 1);
            printInfo();
            continue;
        }
        else if (events->get(i) == 95) {
            this->hasShield = true;
            hasPaladinShield();
            printInfo();
            continue;
        }
        else if (events->get(i) == 96) {
            this->hasSpear = true;
            hasLancelotSpear();
            printInfo();
            continue;
        }
        else if (events->get(i) == 97) {
            this->hasHair = true;
            hasGuinevereHair();
            printInfo();
            continue;
        }
        else if (events->get(i) == 98) {
            if (!hasHair || !hasShield || !hasSpear)
            {
                hasSword = false;
                hasExcaliburSword();
            }
            else if(hasHair && hasShield && hasSpear) {
                hasSword = true;
                hasExcaliburSword();
            }
            printInfo();
            continue;
        }
        else if (events->get(i) == 99) {
            int HP_ultimecia = 5000;
            if (hasExcaliburSword())
            {
                printInfo();
                break;
            }
            else if (hasGuinevereHair() && hasPaladinShield() && hasLancelotSpear()) {
                while (HP_ultimecia > 0 && sum_Knight)
                {
                    if (lastKnight()->get_knigthType() == LANCELOT)
                    {
                        int damage = lastKnight()->get_hp() * lastKnight()->get_level() * 0.05;
                        HP_ultimecia -= damage;
                    }
                    if (lastKnight()->get_knigthType() == PALADIN)
                    {
                        int damage = lastKnight()->get_hp() * lastKnight()->get_level() * 0.06;
                        HP_ultimecia -= damage;
                    }
                    if (lastKnight()->get_knigthType() == DRAGON)
                    {
                        int damage = lastKnight()->get_hp() * lastKnight()->get_level() * 0.075;
                        HP_ultimecia -= damage;
                    }
                    if (lastKnight()->get_knigthType() == NORMAL)
                    {
                        sum_Knight--;
                        if (sum_Knight == 0) break;
                        continue;
                    }
                }
            }
            else {
                sum_Knight = 0;
            }
        }
 
    }
    if (sum_Knight > 0)
    {
        return true;
    }
    else {
        printInfo();
        return false;
    }
}
/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}
KnightAdventure::~KnightAdventure() {
    delete armyKnights;
    delete events;
}
void KnightAdventure::loadArmyKnights(const string& file_armyKnights) {
    this->armyKnights = new ArmyKnights(file_armyKnights);
}
void KnightAdventure::loadEvents(const string& file_events) {
    this->events = new Events(file_events);
}
void KnightAdventure::run() { 
    armyKnights->printResult(armyKnights->adventure(events));
}

/* * * END implementation of class KnightAdventure * * */

/***  Begin implementation of class BaseItem ***/
BaseItem::BaseItem() {
}
BaseItem::~BaseItem(){}
Antidote::Antidote() {
    this->itemType = ANTIDOTE;
}
Antidote::~Antidote() {};
bool Antidote::canUse(BaseKnight* knight) {
    if (knight->get_antidote() > 0 && knight->posioned == true) return true;
    else  return false;
}
void Antidote::use(BaseKnight* knight) {
    if (canUse(knight)) {
        knight->set_antidote(knight->get_antidote() - 1);
        knight->posioned = false;
        knight->get_bag()->get(ANTIDOTE);
    }
    else {
        int count = 0;
        while (knight->get_bag()->bag != NULL && count != 3) {
            if (knight->get_bag()->bag->item->itemType == PHOENIXDOWNI)
            {
                knight->set_phoenixdownI(knight->get_phoenixdownI() - 1);
            }
            if (knight->get_bag()->bag->item->itemType == PHOENIXDOWNII)
            {
                knight->set_phoenixdownII(knight->get_phoenixdownII() - 1);
            }
            if (knight->get_bag()->bag->item->itemType == PHOENIXDOWNIII)
            {
                knight->set_phoenixdownIII(knight->get_phoenixdownIII() - 1);
            }
            if (knight->get_bag()->bag->item->itemType == PHOENIXDOWNIV)
            {
                knight->set_phoenixdownIV(knight->get_phoenixdownIV() - 1);
            }
            knight->get_bag()->bag = knight->get_bag()->bag->next;
            count++;
        }
        if (knight->get_hp() >= 10)
            knight->set_hp(knight->get_hp() - 10);
        else
            knight->set_hp(0);
    }
}

PhoenixDownI::PhoenixDownI() {
    itemType = PHOENIXDOWNI;
}
PhoenixDownI::~PhoenixDownI() {};
bool PhoenixDownI::canUse(BaseKnight* knight) {
    if (knight->get_phoenixdownI() > 0 && knight->get_hp() <= 0) return true;
    else return false;
}
void PhoenixDownI::use(BaseKnight* knight) {
    if (canUse(knight)) {
        knight->set_phoenixdownI(knight->get_phoenixdownI() - 1);
        knight->set_hp(knight->get_maxhp());
        knight->get_bag()->get(PHOENIXDOWNI);
    }
}

PhoenixDownII::PhoenixDownII() {
    itemType = PHOENIXDOWNII;
}
PhoenixDownII::~PhoenixDownII() {};
bool PhoenixDownII::canUse(BaseKnight* knight) {
    if (knight->get_phoenixdownII() > 0 && knight->get_hp() < knight->get_maxhp() *1.0/ 4)
        return true;
    else return false;
}
void PhoenixDownII::use(BaseKnight* knight) {
    if (canUse(knight)) {
        knight->set_phoenixdownII(knight->get_phoenixdownII() - 1);
        knight->set_hp(knight->get_maxhp());
        knight->get_bag()->get(PHOENIXDOWNII);
    }
}

PhoenixDownIII::PhoenixDownIII() {
    itemType = PHOENIXDOWNIII;
}
PhoenixDownIII::~PhoenixDownIII() {};
bool PhoenixDownIII::canUse(BaseKnight* knight) {
    if (knight->get_phoenixdownIII() > 0 && knight->get_hp() < knight->get_maxhp() / 3) return true;
    else return false;
}
void PhoenixDownIII::use(BaseKnight* knight) {
    if (canUse(knight)) {
        if (knight->get_hp() <= 0)
        {
            knight->set_phoenixdownIII(knight->get_phoenixdownIII() - 1);
            knight->set_hp(knight->get_maxhp() / 3);
        }
        else {
            knight->set_hp(knight->get_hp() + knight->get_maxhp() / 4);
        }
        knight->get_bag()->get(PHOENIXDOWNIII);
    }
}

PhoenixDownIV::PhoenixDownIV() {
    itemType = PHOENIXDOWNIV;
}
PhoenixDownIV::~PhoenixDownIV() {};
bool PhoenixDownIV::canUse(BaseKnight* knight) {
    if (knight->get_phoenixdownIV() > 0 && knight->get_hp() < knight->get_maxhp()/2) return true;
    else return false;
}
void PhoenixDownIV::use(BaseKnight* knight) {
    if (canUse(knight))
    {
        if (knight->get_hp() <= 0) knight->set_hp(knight->get_maxhp() / 2);
        else knight->set_hp(knight->get_hp() + knight->get_maxhp() / 5);
        knight->get_bag()->get(PHOENIXDOWNIV);
    }
}
/*** End implementation of class BaseItem***/

/***  Begin implementation of class BaseOpponent ***/

int BaseOpponent::get_levelO(int i) {
    levelO = (i + eventID) % 10 + 1;
    return levelO;
}
Madbear::Madbear(int i) {
    eventID = 1;
    gil = 100;
    baseDamage = 10;
    levelO = get_levelO(i);
}
Bandit::Bandit(int i) {
    eventID = 2;
    gil = 150;
    baseDamage = 15;
    levelO = get_levelO(i);
}
LordLupin::LordLupin(int i) {
    eventID = 3;
    gil = 450;
    baseDamage = 45;
    levelO = get_levelO(i);
}
Elf::Elf(int i) {
    eventID = 4;
    gil = 750;
    baseDamage = 75;
    levelO = get_levelO(i);
}
Troll::Troll(int i) {
    eventID = 5;
    gil = 800;
    baseDamage = 95;
    levelO = get_levelO(i);
}
Tornbery::Tornbery(int i) {
    eventID = 6;
    levelO = get_levelO(i);
}
QueenOfCards::QueenOfCards(int i) {
    eventID = 7;
    levelO = get_levelO(i);
}
NinaDerings::NinaDerings(int i) {
    eventID = 8;
    levelO = get_levelO(i);
}
DurianGarden::DurianGarden(int i) {
    eventID = 9;
    levelO = get_levelO(i);
}
OmegaWeapon::OmegaWeapon(int i) {
    eventID = 10;
    levelO = get_levelO(i);
}
Hades::Hades(int i) {
    eventID = 11;
    levelO = get_levelO(i);
}
/*** End implementation of class BaseOpponent***/
/***  Begin implementation of class Events ***/
Events::Events(const string& file_events) {
    ifstream input1(file_events);
    if (input1.is_open()) {
        input1 >> this->sum_event;
        for (int i = 0; i < sum_event; i++)
        {
            input1 >> arr_event[i];
        }
        input1.close();
    }
}
Events::~Events() { delete[]arr_event; };

int Events::count() const {
    return sum_event;
};
int Events::get(int i) const {
    return arr_event[i];
};
/*** End implementation of class Events***/