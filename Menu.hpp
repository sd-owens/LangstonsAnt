//
// Created by Steve Owens on 10/3/19.
//

#ifndef MENU_HPP
#define MENU_HPP

class Menu {
private:
    static int count;
    std::string title;
    std::string mainMenu;
    std::string subMenu1;
    std::vector<std::string> inputPrompts;
    std::string startPrompt;
    std::string replayPrompt;
public:
    Menu(std::string &title, std::string &mainMenu, std::string &subMenu1, std::vector<std::string> &inputPrompts, std::string &startPrompt, std::string &relayPrompt);
    std::vector<int> display(int choice = 0);
    int replay();
};


#endif //MENU_HPP
