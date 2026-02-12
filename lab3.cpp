#include <iostream>

/*
Задача: Ігровий персонаж із емоційним станом та логом подій

Сценарій:

У грі є один глобальний логер подій — всі персонажі пишуть у нього повідомлення. Тут використовується Singleton.

Кожен персонаж може мати різні стани емоцій: щасливий, сумний, злий — це State, і поведінка персонажа змінюється залежно від стану.

До персонажа можна додати додаткові можливості (наприклад, магічний щит або бонус до атаки) — це Decorator, який динамічно розширює його функціональність.
*/

class Logger {
private:
    Logger() {}
    static Logger* instance;
public:
    static Logger* getInstance() {
        if (!instance) instance = new Logger();
        return instance;
    }
    void log(const std::string& message) {
        std::cout << message << std::endl;
    }
};
Logger* Logger::instance = nullptr;


class State {
public:
    virtual void act() = 0;
    virtual ~State() {}
};

class Happy : public State {
public:
    void act() override { Logger::getInstance()->log("Character is happy!"); }
};

class Angry : public State {
public:
    void act() override { Logger::getInstance()->log("Character is angry!"); }
};


class Character {
public:
    virtual void performAction() = 0;
    virtual ~Character() {}
};

class BasicCharacter : public Character {
private:
    State* state;
public:
    BasicCharacter(State* s) : state(s) {}
    void setState(State* s) { state = s; }
    void performAction() override { state->act(); }
};

class MagicShield : public Character {
private:
    Character* character;
public:
    MagicShield(Character* c) : character(c) {}
    void performAction() override {
        character->performAction();
        Logger::getInstance()->log("...with a magical shield!");
    }
};

int main() {
    State* happy = new Happy();
    State* angry = new Angry();

    Character* hero = new BasicCharacter(happy);
    Character* heroWithShield = new MagicShield(hero);

    heroWithShield->performAction();
    
    dynamic_cast<BasicCharacter*>(hero)->setState(angry);
    heroWithShield->performAction();
}
