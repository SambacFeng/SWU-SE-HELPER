package com.wzy.j2eelabs.lab4.test;

import com.wzy.j2eelabs.lab4.controller.UserController;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;


public class UserTest {
    @Test
    public void test(){
        ApplicationContext ioc = new ClassPathXmlApplicationContext("spring-config.xml");
        UserController controller= ioc.getBean(UserController.class);
        controller.selectUserName("wzy");
    }
}
