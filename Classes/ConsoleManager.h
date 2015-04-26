//
//  ConsoleManager.h
//
//  Created by Akihiro Matsuura on 12/04/14.
//
//

#ifndef __Syuhari__ConsoleManager__
#define __Syuhari__ConsoleManager__

#include "cocos2d.h"

class ConsoleManager
{
public:
    ConsoleManager();
    ~ConsoleManager();
    static ConsoleManager *getInstance();
    void startConsole();
private:
};

#endif /* defined(__Syuhari__ConsoleManager__) */
