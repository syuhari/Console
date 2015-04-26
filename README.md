# Console
Cocos2d-x console sample project

# What about Console  
http://www.cocos2d-x.org/wiki/User_Tutorial-Console_Tutorial

# Connect your game
1. start your game
2. enter bellow command  
$ telnet ipaddress port  
if you launch it on the ios simulator and port is 6010, command is the bellow   
$ telnet localhost 6010  
3. you can get usage if enter help command  
> help

# About ConsoleManager
1. start console function  
ConsoleManager::getInstance()->startConsole();  
2. added two custom command  
dispatch custom event command  
remove a file command  
please check help messages.
