package com.wzy.j2eelabs.lab4.dao.Impl;

import com.wzy.j2eelabs.lab4.dao.UserDao;
import org.springframework.stereotype.Repository;

@Repository
public class UserDaoImpl implements UserDao {

    @Override
    public void selectUserName(String userName) {
        if (userName == "wzy"){
            System.out.println("true");
        }else{
            System.out.println("false");
        }

    }
}
