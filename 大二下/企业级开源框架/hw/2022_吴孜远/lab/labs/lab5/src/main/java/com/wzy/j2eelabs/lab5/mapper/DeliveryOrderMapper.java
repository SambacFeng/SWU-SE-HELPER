package com.wzy.j2eelabs.lab5.mapper;

import com.wzy.j2eelabs.lab5.pojo.DeliveryOrder;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.springframework.stereotype.Repository;

import java.util.List;
@Repository
public interface DeliveryOrderMapper {
    void insertDelivery(DeliveryOrder deliveryOrder);
    // 用@Param的方式传递参数，将参数打包成map，key是param的参数，value是传递的实参
    // 执行delete语句，mysql会自动返回被操作的row数，我们这里可以用int接收，也可以void忽略
    int deleteDelivery(@Param("trackingId") String trackingId);
    int updateDelivery(DeliveryOrder deliveryOrder);
    List<DeliveryOrder> selectByTrackingId(@Param("trackingId") String trackingId);
    @Select("select * from delivery_order where courier_id=#{courierId}")
    List<DeliveryOrder> selectByCourierId(@Param("courierId") String courierId);

    @Select("select * from delivery_order")
    List<DeliveryOrder> selectAll();
}
