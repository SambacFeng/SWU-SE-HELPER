package com.wzy.j2eelabs.lab4.controller;
import com.wzy.j2eelabs.lab4.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;

@Controller
public class UserController {
    @Autowired
    UserService userService;
    public void selectUserName(String userName){
        userService.selectUserName(userName);
    }
}
