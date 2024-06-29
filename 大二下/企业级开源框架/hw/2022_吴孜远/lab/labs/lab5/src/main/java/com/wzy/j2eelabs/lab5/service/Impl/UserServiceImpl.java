package com.wzy.j2eelabs.lab5.service.Impl;

import com.wzy.j2eelabs.lab5.mapper.DeliveryOrderMapper;
import com.wzy.j2eelabs.lab5.mapper.UserMapper;
import com.wzy.j2eelabs.lab5.pojo.Courier;
import com.wzy.j2eelabs.lab5.pojo.DeliveryOrder;
import com.wzy.j2eelabs.lab5.service.UserService;
import org.apache.ibatis.session.SqlSessionFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
@Transactional
public class UserServiceImpl implements UserService {
    // 我们在spring中设置了sqlSessionFactoryBean,
    // 又设置了自动创建mapper接口的代理实现
    // 所以这里可以直接从ioc容器中自动装填mapper代理实现
    @Autowired
    private DeliveryOrderMapper deliveryOrderMapper;
    @Autowired
    private UserMapper userMapper;

    public boolean userMatch(String courierId, String password) {
        List<Courier> list = userMapper.userMatch(courierId, password);
        if (list == null || list.isEmpty()) {
            // 如果列表为空，没有找到用户或密码不匹配，返回false
            return false;
        } else {
            // 如果找到了用户，返回true
            return true;
        }
    }
    @Override
    public List<DeliveryOrder> selectAll() {
        return deliveryOrderMapper.selectAll();
    }

    @Override
    public List<DeliveryOrder> selectByTrackingId(String trackingId) {
        return deliveryOrderMapper.selectByTrackingId(trackingId);
    }

    @Override
    public List<DeliveryOrder> selectByCourierId(String courierId) {
        return deliveryOrderMapper.selectByCourierId(courierId);
    }

    @Override
    public void insertDelivery(DeliveryOrder deliveryOrder) {
        deliveryOrderMapper.insertDelivery(deliveryOrder);
    }

    @Override
    public int deleteDelivery(String trackingId) {
        return deliveryOrderMapper.deleteDelivery(trackingId);
    }

    @Override
    public int updateDelivery(DeliveryOrder deliveryOrder) {
        return deliveryOrderMapper.updateDelivery(deliveryOrder);
    }


}
