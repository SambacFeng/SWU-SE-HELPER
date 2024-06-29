package com.wzy.j2eelabs.lab3.test;

import com.wzy.j2eelabs.lab3.mapper.DeliveryOrderMapper;
import com.wzy.j2eelabs.lab3.pojo.DeliveryOrder;
import com.wzy.j2eelabs.lab3.utils.SqlSessionUtil;
import org.apache.ibatis.session.SqlSession;

public class Main {
    public static void main(String[] args){
        SqlSession sqlSession = SqlSessionUtil.getSqlSession();
        DeliveryOrderMapper mapper = sqlSession.getMapper(DeliveryOrderMapper.class);
        DeliveryOrder first = new DeliveryOrder(20, "1", "swu", "13333333333");
        mapper.insertDelivery(first);
        System.out.println(first);
    }
}
