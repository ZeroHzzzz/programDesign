#include <iomanip>
#include <iostream>
#include "../include/file_manager.h"
#include "../include/machine.h"
#include "../include/menu.h"
int main() {
    Menu menu;
    UserList list;
    File file("../data/data", ".txt");
    file.init(list);
    mp.init();
    bool flagMain = true;
    int userChoice = 0;
    menu.displayMainMenu();
    while (flagMain && std::cin >> userChoice && userChoice) {
        switch (userChoice) {
            case 1: {
                bool flagMain_ = true;
                menu.displayMaintainMenu();
                int typeNum = 0;
                // 维护学生信息
                while (flagMain_ && std::cin >> typeNum && typeNum) {
                    switch (typeNum) {
                        // 添加上机信息
                        case 1: {
                            std::cout << std::setw(20) << std::setfill('-')
                                      << std::endl;
                            file.add(list.addNode(std::cin));
                            break;
                        }
                        // 添加下机信息
                        case 2: {
                            std::cout << std::setw(20) << std::setfill('-')
                                      << std::endl;
                            std::cout << "请输入想添加信息的学生的学号：";
                            std::string num;
                            std::cin >> num;
                            list.changeNode_info(num);
                            file.change(list);
                            break;
                        }
                        case 3: {
                            if (!list.getSize()) {
                                std::cout << std::setw(20) << std::setfill('-')
                                          << std::endl;
                                std::cout << "当前链表为空" << std::endl;
                                break;
                            }
                            menu.displayChangeMenu();
                            int typeNum_ = 0;
                            bool flag = true;
                            while (flag && std::cin >> typeNum_ && typeNum_) {
                                switch (typeNum_) {
                                    case 1: {
                                        std::cout << std::setw(20)
                                                  << std::setfill('-')
                                                  << std::endl;
                                        std::cout << "请输入想修改学生的学号：";
                                        std::string num;
                                        std::cin >> num;
                                        list.changeNode(num, "num");
                                        file.change(list);
                                        flag = false;
                                        break;
                                    }
                                    case 2: {
                                        std::cout << std::setw(20)
                                                  << std::setfill('-')
                                                  << std::endl;
                                        std::cout << "请输入想修改用户的姓名：";
                                        std::string name;
                                        std::cin >> name;
                                        list.changeNode(name, "name");
                                        file.change(list);
                                        flag = false;
                                        break;
                                    }
                                    default: {
                                        std::cout << "输入有误，请重新输入\n>";
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 4: {
                            if (!list.getSize()) {
                                std::cout << std::setw(20) << std::setfill('-')
                                          << std::endl;
                                std::cout << "当前链表为空" << std::endl;
                                break;
                            }
                            menu.displayDeleteMenu();
                            int typeNum_;
                            bool flag = true;
                            while (flag && std::cin >> typeNum_ && typeNum_) {
                                switch (typeNum_) {
                                    case 1: {
                                        std::cout << std::setw(20)
                                                  << std::setfill('-')
                                                  << std::endl;
                                        std::cout << "请输入想删除用户的学号：";
                                        std::string num;
                                        std::cin >> num;
                                        list.delNode(num, "num");
                                        file.change(list);
                                        flag = false;
                                        break;
                                    }
                                    case 2: {
                                        std::cout << std::setw(20)
                                                  << std::setfill('-')
                                                  << std::endl;
                                        std::cout << "请输入想删除用户的姓名：";
                                        std::string name;
                                        std::cin >> name;
                                        list.delNode(name, "name");
                                        file.change(list);
                                        flag = false;
                                        break;
                                    }
                                    default: {
                                        std::cout << "输入有误，请重新输入\n>";
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                    }
                    if (typeNum)
                        menu.displayMaintainMenu();
                }
                break;
            }
            case 2: {
                // 查询学生信息
                if (!list.getSize()) {
                    std::cout << "当前链表为空" << std::endl;
                    break;
                }
                menu.displayFetchMenu();
                int typeNum_;
                bool flag = true;
                while (flag && std::cin >> typeNum_ && typeNum_) {
                    switch (typeNum_) {
                        case 1: {
                            std::cout << "请输入想查询用户的学号：";
                            std::string num;
                            std::cin >> num;
                            auto user = list.fetchNode(num, "num");
                            if (user) {
                                std::cout << *user;
                            } else {
                                std::cout << "该用户不存在" << std::endl;
                            }
                            flag = false;
                            break;
                        }
                        case 2: {
                            std::cout << "请输入想查询用户的姓名：";
                            std::string name;
                            std::cin >> name;
                            auto user = list.fetchNode(name, "name");
                            if (user) {
                                std::cout << *user;
                            } else {
                                std::cout << "该用户不存在" << std::endl;
                            }
                            flag = false;
                            break;
                        }
                        default: {
                            std::cout << "输入有误，请重新输入\n>";
                            break;
                        }
                    }
                }
                break;
            }
            case 3: {
                std::cout << std::setw(20) << std::setfill('-') << "-"
                          << std::endl;
                list.display();
                break;
            }
            case 4: {
                std::cout << std::setw(20) << std::setfill('-') << "-"
                          << std::endl;
                if (!list.getSize()) {
                    std::cout << "当前链表为空" << std::endl;
                    break;
                }
                list.sortNode();  // Ensure this function actually sorts the
                                  // nodes.
                file.change(list);
                break;
            }
            case 5: {
                std::cout << std::setw(20) << std::setfill('-') << "-"
                          << std::endl;
                mp.displayMap();
                break;
            }
            default:
                break;
        }
        if (userChoice)
            menu.displayMainMenu();
    }
    file.change(list);
    system("pause");
    return 0;
}
