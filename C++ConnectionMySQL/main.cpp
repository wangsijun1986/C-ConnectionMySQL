//
//  main.cpp
//  C++ConnectionMySQL
//
//  Created by 王思俊 on 15/12/19.
//  Copyright © 2015年 王思俊. All rights reserved.
//

#include <iostream>
#include <mysql.h>
#include "MySQLConnector.hpp"
#include <sstream>

int main(int argc, const char * argv[]) {
    DataConfiguration config;
    config.host = "localhost";
    config.username="root";
    config.password="";
    config.databases="test";
    config.port=3306;
    config.character_set="set names \'GBK\'";
    MySqlOperation mysqlOperation(config);
    
    MySQLQueryResult result = mysqlOperation.Query("select * from userinfo;");
    string str = result.GetDataAt(0, 1);
    const char* st = str.c_str();
    
    printf(st);
    
    printf("\r\n");
    str = "insert into userinfo(username) values ('lvdandan')";
    int res = mysqlOperation.Command(str);
    
    stringstream strs;
    strs<<res;
    string resChar;
    strs >> resChar;
    char c = (char)res;
    const char* ss =&c;
    printf(ss);
    printf("\r\n");
    res=0;
    
    res = mysqlOperation.SelectDatabase("test2");
    if(res){
        printf("成功");
        str = "insert into userinfo(username) values ('lvdandan')";
        res=0;
        res = mysqlOperation.Command(str);
        if(res){
             printf("添加成功");
        }
        else{
            printf("添加失败");
        }
        
    }
    else{
        printf("失败");
    }
    
    
    return 0;
}
