package com.wzy.j2eelabs.lab4.service.Impl;

import com.wzy.j2eelabs.lab4.dao.UserDao;
import com.wzy.j2eelabs.lab4.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserServiceImpl implements UserService {

    @Autowired
    UserDao userDao;
    @Override
    public void selectUserName(String userName) {
        userDao.selectUserName(userName);
    }
}
