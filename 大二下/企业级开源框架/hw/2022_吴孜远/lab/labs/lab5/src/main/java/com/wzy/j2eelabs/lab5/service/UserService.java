package com.wzy.j2eelabs.lab5.service;

import com.wzy.j2eelabs.lab5.pojo.DeliveryOrder;

import java.util.List;

public interface UserService {
    boolean userMatch(String courierId, String password);
    List<DeliveryOrder> selectAll();
    List<DeliveryOrder> selectByTrackingId( String trackingId);
    List<DeliveryOrder> selectByCourierId(String courierId);
    void insertDelivery(DeliveryOrder deliveryOrder);
    int deleteDelivery(String trackingId);
    int updateDelivery(DeliveryOrder deliveryOrder);
}
