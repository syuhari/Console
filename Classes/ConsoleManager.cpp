//
//  ConsoleManager.cpp
//
//  Created by Akihiro Matsuura on 12/04/14.
//
//

#include "ConsoleManager.h"
#include <sys/socket.h>

USING_NS_CC;

// Console サーバの TCP ポート番号
#define TCP_PORT 6010

static ConsoleManager *m_instance = NULL;

ConsoleManager::ConsoleManager()
{
    
}

ConsoleManager::~ConsoleManager()
{
    
}

ConsoleManager* ConsoleManager::getInstance()
{
    if (!m_instance) {
        m_instance = new ConsoleManager();
    }
    return m_instance;
}

void ConsoleManager::startConsole()
{
#ifndef COCOS2D_DEBUG
    return;
#endif
    
    // 接続要求を待ち受ける
    Director::getInstance()->getConsole()->listenOnTCP(TCP_PORT);
    
    cocos2d::Console::Command event = { "event", "dispatch custom event. Args:[event name]", [](int fd, const std::string& args) {
        Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(args);
        const char msg[] = "dispatch custom event!\n";
        send(fd, msg, sizeof(msg),0);
    }};
    Director::getInstance()->getConsole()->addCommand(event);
    
    cocos2d::Console::Command del = { "remove", "remove a file. Args:[filename]", [](int fd, const std::string& args) {
        auto path = FileUtils::getInstance()->getWritablePath() + args;
        int ret = remove(path.c_str());
        if (ret==0) {
            const char msg[] = "remove file!\n";
            send(fd, msg, sizeof(msg),0);
        } else {
            const char msg[] = "can not remove file\n";
            send(fd, msg, sizeof(msg),0);
        }
    }};
    Director::getInstance()->getConsole()->addCommand(del);
    
    // サーチパス
    std::vector<std::string> searchPath;
    std::string writablePath = FileUtils::getInstance()->getWritablePath();
    searchPath.push_back(writablePath);
    FileUtils::getInstance()->setSearchPaths(searchPath);
}
