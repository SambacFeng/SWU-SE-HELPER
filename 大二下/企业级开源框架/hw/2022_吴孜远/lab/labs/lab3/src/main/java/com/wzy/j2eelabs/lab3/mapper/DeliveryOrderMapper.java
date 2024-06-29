package com.wzy.j2eelabs.lab3.mapper;

import com.wzy.j2eelabs.lab3.pojo.DeliveryOrder;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface DeliveryOrderMapper {
    void insertDelivery(DeliveryOrder deliveryOrder);
    // 用@Param的方式传递参数，将参数打包成map，key是param的参数，value是传递的实参
    void deleteDelivery(@Param("trackingId") String trackingId);
    void updateDelivery(DeliveryOrder deliveryOrder);
    List<DeliveryOrder> selectByTrackingId(@Param("trackingId") String trackingId);
}
