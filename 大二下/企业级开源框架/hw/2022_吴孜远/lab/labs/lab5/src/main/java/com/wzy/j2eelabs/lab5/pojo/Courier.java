package com.wzy.j2eelabs.lab5.pojo;

public class Courier {
    private String courierId;
    private String password;

    public String getUsername() {return courierId;}

    public void setUsername(String courierId) {
        this.courierId = courierId;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
